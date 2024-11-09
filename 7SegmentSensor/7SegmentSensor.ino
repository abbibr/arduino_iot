int DP = 5;
int E = 8;
int D = 7;
int C = 6;
int G = 12;
int F = 11;
int A = 10;
int B = 9;
int buzzer = 3;

void setup()
{
  pinMode(DP, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop()
{
  nine();
  delay(1000);
  
  eight();
  delay(1000);
  
  seven();
  delay(1000);
  
  six();
  delay(1000);
  
  five();
  delay(1000);
  
  four();
  delay(1000);
  
  three();
  delay(1000);
  
  two();
  delay(1000);
  
  one();
  delay(1000);
}

void nine() 
{
  digitalWrite(G, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  
  digitalWrite(E, LOW);
  digitalWrite(D, LOW);
  analogWrite(buzzer, 0);
}

void eight() 
{
  digitalWrite(G, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(D, HIGH);
  analogWrite(buzzer, 0);
}

void seven()
{
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  
  digitalWrite(F, LOW);
  digitalWrite(E, LOW);
  digitalWrite(D, LOW);
  digitalWrite(G, LOW);
  analogWrite(buzzer, 0);
}

void six()
{
  digitalWrite(G, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  
  digitalWrite(B, LOW);
  analogWrite(buzzer, 0);
}

void five()
{
  digitalWrite(A, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  
  digitalWrite(B, LOW);
  digitalWrite(E, LOW);
  analogWrite(buzzer, 0);
}

void four()
{
  digitalWrite(G, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  
  digitalWrite(A, LOW);
  digitalWrite(E, LOW);
  digitalWrite(D, LOW);
  analogWrite(buzzer, 0);
}

void three()
{
  digitalWrite(G, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(C, HIGH);
  
  digitalWrite(F, LOW);
  digitalWrite(E, LOW);
  analogWrite(buzzer, 0);
}

void two()
{
  digitalWrite(G, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  
  digitalWrite(F, LOW);
  digitalWrite(C, LOW);
  analogWrite(buzzer, 0);
}

void one()
{
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  
  digitalWrite(D, LOW);
  digitalWrite(G, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(A, LOW);

  analogWrite(buzzer, 150);
  delay(3000);
}