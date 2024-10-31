/* 
  Mini Project for tutorials! 
  by Ibrohim Abbosov)
*/

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHTPIN 5  // Pin connected to DHT22 data pin
#define DHTTYPE 22  // Define the DHT sensor type
DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal_I2C lcd(0x27, 20, 4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

#define echoPin 10
#define trigPin 8

int buzzer = 7;
int ledPin = 3;
float distance, duration, temperature, humidity;
float speedOfSound;   // Speed of sound based on current temperature and humidity

void setup()
{
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();

  dht.begin();  // Initialize DHT sensor

  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(ledPin, OUTPUT);
}


void loop()
{
  // Read temperature and humidity from DHT22
  temperature = dht.readTemperature();
  humidity = dht.readHumidity();

  // Calculate speed of sound based on temperature and humidity
  speedOfSound = 331.3 + (0.606 * temperature) + (0.0124 * humidity); // in m/s

  // Trigger the ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the duration of the echo pulse
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance with corrected speed of sound
  distance = (duration / 2) * (speedOfSound / 10000);   // Convert to cm

  Serial.print("Distance = ");

  lcd.clear();

  if(distance > 400 || distance < 0) {
    Serial.println("Out of range!");
    lcd.setCursor(0, 1);
    lcd.print("Out of range!");

    digitalWrite(buzzer, LOW);  // Ensure the buzzer is off if out of range
    digitalWrite(ledPin, LOW);
  }
  else {
    Serial.print(distance);
    Serial.print(" cm, ");

    Serial.print(" Temperature = ");
    Serial.print(temperature);
    Serial.print(" C, ");

    Serial.print(" Humidity = ");
    Serial.print(humidity);
    Serial.println(" %");

    lcd.setCursor(0, 0);
    lcd.print("Testing experiment!");

    lcd.setCursor(0, 1);
    lcd.print("Distance = ");
    lcd.print(distance);
    lcd.print(" cm");

    lcd.setCursor(0, 2);
    lcd.print("Temperatur = ");
    lcd.print(temperature);
    lcd.print(" C");

    lcd.setCursor(0, 3);
    lcd.print("Humidity = ");
    lcd.print(humidity);
    lcd.print(" %");

    // Control the buzzer based on distance
    if (distance < 40) {
      digitalWrite(buzzer, HIGH);
      digitalWrite(ledPin, HIGH);
    } else {
      digitalWrite(buzzer, LOW);
      digitalWrite(ledPin, LOW);
    }
  }

  delay(500);
}
