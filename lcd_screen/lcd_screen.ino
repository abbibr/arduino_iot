/*
  GND to GND on the Arduino.
  VCC to 5V on the Arduino.
  SDA to A4 on the Arduino (on most Arduino boards)
  SCL to A5 on the Arduino (on most Arduino boards)
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.begin(16, 2);
  lcd.backlight();  // Turn on the backlight if your LCD has it
  lcd.setCursor(0, 0);  // Set cursor to first column, first row
  lcd.print("Hello, World!");  // Print text on the first row

}

void loop() {
  // put your main code here, to run repeatedly:

}
