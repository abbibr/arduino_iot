/* global variables */
int firstVariable = 1; // integer
bool booleanType = true; // boolean
float floatNumber = 8.5; // float
char stringData = 'A'; // character

void setup() {
  // local variable
  int something = 15;

  firstVariable++;
  Serial.begin(9600);
  Serial.println(firstVariable);
  float firstVariable = 8.5;
  Serial.println(firstVariable);
}

void loop() {
  ++firstVariable;
  delay(1000);
  Serial.println(firstVariable);
}
