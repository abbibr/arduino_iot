/* 
  VCC -> 5v
  Trig -> Trigger Pin (input)
  Echo -> Echo pin (output)
  GND -> GND (ground)
*/


#define triggerPin 10
#define echoPin 13
int buzzer = 7;

float duration, distance;

void setup() {
  Serial.begin(9600);

  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT); 
  pinMode(buzzer, OUTPUT);
}

void loop() {

  // Write a pulse to the HC-SR04 Trigger Pin of UltraSonic Sensor
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  // Measure the response from Echo Pin
  duration = pulseIn(echoPin, HIGH);

  // Determine distance from duration
  // Used 343 metres per second as speed of sound
  distance = (duration / 2) * 0.0343;

  // Send result to Serial Monitor
  Serial.print("Distance = ");

  if(distance > 200) {
    digitalWrite(buzzer, HIGH);
    delay(500);
  }
  else {
    digitalWrite(buzzer, LOW);
    delay(500);
  }

  if(distance > 400 || distance < 2) {
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance);
    Serial.println(" sm");
    delay(500);
  }

  delay(500);

}

