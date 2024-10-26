int readPin = A0;
float calcPin;

void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);

}

void loop() {
  calcPin = ((5.0/1023.0) * analogRead(readPin));

  Serial.print(calcPin);
  Serial.println("V");

}
