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
int buzzer = 3;
int second = 0;
int minute = 0;
int hour = 0;

void setup() {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);

  // start display
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorUsed);
  // Set brightness
  sevseg.setBrightness(90);
}

void loop() {
  for(int i = 0; i < 10; i++) {
    second++;
    analogWrite(buzzer, 0);

    if(second % 60 == 0) {
      minute++;
      analogWrite(buzzer, 150);
    }
    if(minute % 60 == 0 && minute > 0) {
      hour++;
      minute = 0;
    }

    sevseg.setNumber(i);
    delay(1000);
    sevseg.refreshDisplay();
  }

  Serial.print("Time has just moved 10 seconds!  ");
  Serial.print("Totat seconds: ");
  Serial.print(second);

  Serial.print(".   Total minutes: ");
  Serial.println(minute);

  if(hour > 0) {
    Serial.print("   Total hours: ");
    Serial.println(hour);
  }
}
