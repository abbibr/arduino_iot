#include <Servo.h>

Servo myServo;  // create servo object to control a servo

int position = 0;  // variable to store the servo position
int potentiometer = A0;
int value;

void setup() {
  Serial.begin(9600);
  myServo.attach(9);  // variable to store the servo position (PWM pins)

  pinMode(potentiometer, INPUT);
}

void loop() {
  value = analogRead(potentiometer);
  value = map(value, 0, 1023, 0, 180);
  
  Serial.println(value);
  myServo.write(value);
  delay(15);

  /* for(position = 0; position <= 180; position++) {
    myServo.write(position);  // tell servo to go to position in variable "position"
    delay(15);
  }

  for(position = 180; position >= 180; position--) {
    myServo.write(position);
    delay(15);
  } */
}
