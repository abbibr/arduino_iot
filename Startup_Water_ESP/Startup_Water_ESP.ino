#include <WiFi.h>
#include <HTTPClient.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

volatile int flow_frequency = 0;     // Counts flow sensor pulses
float l_min = 0;                     // Calculated liters/minute
float l_hour = 0;                    // Calculated liters/hour
float totalLiters = 0;               // Total liters spent
const unsigned char flowsensor = 2;  // Sensor pin
unsigned long lastMeasureTime = 0;
unsigned long lastSendTime = 0;
const int measureInterval = 1000;    // Measurement interval (1 second)
const int sendInterval = 5000;       // Data send interval (5 seconds)

const char* ssid = "Xiaomi 13 Lite";
const char* password = "salom12345";
const char* serverUrl = "https://768b-195-158-4-4.ngrok-free.app/api/store-water-data";  // Replace with your actual URL

LiquidCrystal_I2C lcd(0x27, 20, 4);  // LCD settings

// Interrupt service routine for counting flow sensor pulses
void IRAM_ATTR flow() { 
    flow_frequency++;
}

void setup() {
    pinMode(flowsensor, INPUT_PULLUP);  // Setup the flow sensor pin with an internal pull-up
    Serial.begin(9600);
    attachInterrupt(digitalPinToInterrupt(flowsensor), flow, RISING); // Attach interrupt

    Wire.begin(21, 22);  // Initialize I2C for ESP32 on SDA=21, SCL=22
    lcd.init();          
    lcd.backlight();    

    // Display welcome message on the first line permanently
    lcd.setCursor(0, 0);
    lcd.print("Welcome to AquaCare");

    // Connect to Wi-Fi
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi...");
    }
    Serial.println("Connected to WiFi");

    lastMeasureTime = millis();
    lastSendTime = millis();
}

void loop() {
    unsigned long currentTime = millis();

    // Measure flow rate and update display every second
    if (currentTime - lastMeasureTime >= measureInterval) {
        lastMeasureTime = currentTime; 
        l_min = (flow_frequency / 7.5);   // Convert pulses to L/min
        l_hour = l_min * 60;              // Convert L/min to L/h
        totalLiters += (l_min / 60);      // Total liters spent

        flow_frequency = 0; // Reset flow frequency count

        // Display on Serial Monitor for debugging
        Serial.print("Flow rate: ");
        Serial.print(l_hour, 2); 
        Serial.print(" L/h, ");
        Serial.print("Total liters spent: ");
        Serial.println(totalLiters, 2); 

        // Update only the necessary lines on the LCD
        lcd.setCursor(0, 2);
        lcd.print("Flow Rate: ");
        lcd.print(l_hour, 2);
        lcd.print(" L/h   ");  // Extra spaces to clear any previous characters

        lcd.setCursor(0, 3);
        lcd.print("Total Liters: ");
        lcd.print(totalLiters, 2);
        lcd.print(" L   ");    // Extra spaces to clear any previous characters
    }

    // Every 5 seconds, send data to backend
    if (currentTime - lastSendTime >= sendInterval) {
        sendToBackend(l_hour, totalLiters);
        lastSendTime = currentTime;
    }
}

// Function to send data to Laravel backend
void sendToBackend(float flowRate, float totalLiters) {
    if (WiFi.status() == WL_CONNECTED) {
        HTTPClient http;
        http.begin(serverUrl);
        http.addHeader("Content-Type", "application/json");

        // Construct JSON payload
        String jsonData = "{\"flowRate\":" + String(flowRate, 2) + ",\"totalLiters\":" + String(totalLiters, 2) + "}";
        int httpResponseCode = http.POST(jsonData);

        if (httpResponseCode > 0) {
            String response = http.getString();
            Serial.println("Data sent successfully");
            Serial.println("Response: " + response);
        } else {
            Serial.print("Error sending data: ");
            Serial.println(httpResponseCode);
        }

        http.end();
    } else {
        Serial.println("WiFi Disconnected");
    }
}
