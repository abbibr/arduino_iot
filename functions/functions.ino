int pin1 = 7;
int pin2 = 10;
int pin3 = 13;

void setup() {
  Serial.begin(9600);

  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);

  Serial.println(sum(5, 7, 12));
}

void loop() {
  myBlinkFunction(pin1);
  myBlinkFunction(pin2);
  myBlinkFunction(pin3);

}


void myBlinkFunction(int pin) {
  digitalWrite(pin, HIGH);
  delay(1000);
  digitalWrite(pin, LOW);
  delay(1000);
}


int sum(int a, int b, int c) {
  return a + b + c;
}
