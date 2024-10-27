/*
  GND to GND on the Arduino.
  VCC to 5V on the Arduino.
  SDA to A4 on the Arduino (on most Arduino boards)
  SCL to A5 on the Arduino (on most Arduino boards)
*/


#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 20x4 display
LiquidCrystal_I2C lcd(0x27, 20, 4);  // Replace 0x27 with your LCD's I2C address if necessary

void setup() {
  lcd.begin(20, 4);  // Initialize the LCD with 20 columns and 4 rows
  lcd.backlight();    // Turn on the backlight
  lcd.setCursor(0, 0);  // Set cursor to first column, first row
  lcd.print("Hello, World!");  // Print text on the first row
}

void loop() {
  // You can add more code here if needed, or leave the loop empty for static text
}
