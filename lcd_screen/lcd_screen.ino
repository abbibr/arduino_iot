#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Replace 0x27 with your detected I2C address if different

void setup() {
  lcd.begin(16, 2);
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Testing LCD");
}

void loop() {
  // Empty loop
}
