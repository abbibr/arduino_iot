int buzzer = 7;
int valueMotion = 9;
int ledPin = 4;

void setup() {
  Serial.begin(9600);

  pinMode(buzzer, OUTPUT);
  pinMode(valueMotion, INPUT);
  pinMode(ledPin, OUTPUT);

}

void loop() {
  int readMotion = digitalRead(valueMotion);
 
  if(readMotion == HIGH) {
    Serial.println("Motion detected!");
    digitalWrite(buzzer, HIGH);
    digitalWrite(ledPin, HIGH);

    delay(500);
  }
  else {
    Serial.println("Motion ended)");
    digitalWrite(buzzer, LOW);
    digitalWrite(ledPin, LOW);

    delay(500);
  }

}
