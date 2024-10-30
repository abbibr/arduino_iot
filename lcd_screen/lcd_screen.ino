#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4); // Replace 0x27 with the detected address

void setup() {
  Wire.begin(21, 22);  // Set ESP32 I2C pins
  Wire.setClock(100000);
  lcd.init();    
  lcd.backlight(); 
  lcd.setCursor(0, 0); 
  lcd.print("Hello, CEO!");
  lcd.setCursor(0, 1); 
  lcd.print("Welcome to th abbibr");
  lcd.setCursor(0, 2); 
  lcd.print("Happy to see you");
  lcd.setCursor(3, 3); 
  lcd.print("Byeee!)");
}

void loop() {
  // No code needed here
}
