#include <SevSeg.h>

SevSeg sevseg; // make a object

// Number of digits on display (screen)
byte numDigits = 1;
// We don`t have any digit pins in single display
byte digitPins[] = {};
// Display segment pins: A - 10, B - 9, C - 6, D - 7, E - 8, F - 11, G - 12, DP - 5
byte segmentPins[] = {10, 9, 6, 7, 8, 11, 12, 5};
// Resistors are used or not
bool resistorUsed = true;
// Display type
byte hardwareConfig = COMMON_CATHODE;

String numberString;

void setup() {
  Serial.begin(9600);

  // start display
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorUsed);
  // Set brightness
  sevseg.setBrightness(90);

  Serial.println("Enter the number up to 9 which you want to see it in Segment Display: ");
  Serial.println();
}

void loop() {
  if(Serial.available()) {
    numberString = Serial.readString();
    numberString.trim();
    int numberInt = numberString.toInt();

    if(numberInt) {
      if(numberInt < 10) {
        Serial.print("Your number is: ");
        Serial.println(numberInt);

        // Set number to display
        sevseg.setNumber(numberInt);
      }
      else {
        Serial.println("Please, enter the positive number up to 9!");
      }
    }
    else {
      Serial.println("Please, enter integer type (number)!");
    }
  }

  // Refresh the display
  sevseg.refreshDisplay();
  delay(500);
}
