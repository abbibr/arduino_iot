#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

#define DHTPIN 5
#define DHTTYPE 22

DHT dht(DHTPIN, DHTTYPE);

int buzzer = 9;
int bluePin = 7;
int redPin = 6;
int gasDetector = A1;
float temperature, humidity;

void setup() {
  Serial.begin(9600);
  dht.begin();
  Wire.begin();
  lcd.init();
  lcd.backlight();

  pinMode(gasDetector, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  temperature = dht.readTemperature();
  humidity = dht.readHumidity();
  int value = analogRead(gasDetector);

  Serial.print("Temperature = ");
  Serial.print(temperature);
  Serial.print(" C,  ");

  lcd.setCursor(0, 0);
  lcd.print("Temperature = ");
  lcd.print(temperature);
  lcd.print(" C");

  Serial.print("Humidity = ");
  Serial.print(humidity);
  Serial.print(" %,  ");

  lcd.setCursor(0, 1);
  lcd.print("Humidity = ");
  lcd.print(humidity);
  lcd.print(" %");

  Serial.print("Gas detector = ");

  lcd.setCursor(0, 2);
  lcd.print("Gas detector = ");
  lcd.print(value);

  if(value > 150) {
    digitalWrite(redPin, HIGH);
    analogWrite(buzzer, 100);
    digitalWrite(bluePin, LOW);

    Serial.println("It is so dirty!!!");

    lcd.setCursor(0, 3);
    lcd.print("It is so dirty!!!");
  }
  else {
    digitalWrite(bluePin, HIGH);
    digitalWrite(redPin, LOW);
    digitalWrite(buzzer, LOW);

    Serial.println(value);

    lcd.setCursor(0, 3);
    lcd.print("Everything is okay)");
  }

  delay(500);
}
