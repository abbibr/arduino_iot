#include <WiFi.h>
#include <HTTPClient.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

volatile int flowPulseCount = 0;
float calibrationFactor = 4.5;
float flowRate = 0;
float totalLiters = 0;
unsigned long previousMillis = 0;
const unsigned long interval = 5000; // store data in every 5 seconds

int pumpPin = 12; // Using a compatible ESP32 pin for pump control
const char* ssid = "killer";
const char* password = "12345678";
const char* serverUrl = "https://b677-37-110-210-29.ngrok-free.app/api/store-water-data";

LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup() {
  Serial.begin(9600);
  Wire.begin(21, 22);  // Set ESP32 I2C pins
  Wire.setClock(100000);

  pinMode(2, INPUT_PULLUP);
  pinMode(pumpPin, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(2), pulseCounter, RISING);
  digitalWrite(pumpPin, LOW);
  lcd.init();    
  lcd.backlight(); 

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    flowRate = ((flowPulseCount / calibrationFactor) / 7.5) * 60;
    totalLiters += (flowRate / 3600);

    // Display on LCD
    lcd.setCursor(0, 0);
    lcd.print("Flow Rate: ");
    lcd.print(flowRate);
    lcd.print(" L/h  ");

    lcd.setCursor(0, 1);
    lcd.print("Total Litres: ");
    lcd.print(totalLiters);

    // Send data to backend
    sendToBackend(flowRate, totalLiters);

    flowPulseCount = 0; // Reset pulse count
  }
}

// Interrupt Service Routine (ISR) for counting flow sensor pulses
void pulseCounter() {
  flowPulseCount++;
}

// Function to send data to Laravel backend
void sendToBackend(float flowRate, float totalLiters) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(serverUrl);
    http.addHeader("Content-Type", "application/json");

    String jsonData = "{\"flowRate\":" + String(flowRate) + ",\"totalLiters\":" + String(totalLiters) + "}";
    int httpResponseCode = http.POST(jsonData);

    if (httpResponseCode > 0) {
      String response = http.getString();
      Serial.println("Data sent successfully");
      Serial.println(response);
    } else {
      Serial.print("Error sending data: ");
      Serial.println(httpResponseCode);
    }

    http.end();
  } else {
    Serial.println("WiFi Disconnected");
  }
}
