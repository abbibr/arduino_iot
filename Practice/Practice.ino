// Input and Output statements

/* 
   a.	Write a Program to calculate and display the volume of a CUBE having its height (h=10cm), width (w=12cm) and depth (8cm)
   b.	Prepare a program to find the area and perimeter of rectangle
   c.	Prepare a program to swap the values of two given variables with a third variable
   d.	Prepare a program to swap the values of two given variables without a third variable
   e.	Write a program to find the largest of three numbers using ternary operators.
*/


// Answer: a
int height = 10;
int width = 12;
int depth = 8;
int volume;

void setup() {
  // Answer: a
  volume = height * depth * width;

  Serial.begin(9600);
  Serial.print("The volume of cube: ");
  Serial.println(volume);

  // Answer: b
  int a = 5;
  int b = 7;
  int perimeter = 2*(a+b);
  int area = a*b;
  
  Serial.print("The perimeter of rectangle: ");
  Serial.println(perimeter);
  Serial.print("The area of rectangle: ");
  Serial.println(area);

  // Answer: c
  int x = 5; // x=7
  int y = 7; // y=5

  int change = x;
  x=y;
  y=change;

  Serial.print("Y is: ");
  Serial.println(y);
  Serial.print("X is: ");
  Serial.println(x);

  // Answer: d
  int m = 20;
  int n = 10;
  m = m + n;
  n = m - n;
  m = m - n;

  Serial.print("M is: ");
  Serial.println(m);
  Serial.print("N is: ");
  Serial.println(n);

  // Answer: e
  int first = 12;
  int second = 15;
  int third = 10;

  Serial.print(first > second ? "First is the largest" : (second > third ? "Second is the largest" : "Third is the largest"));

}

void loop() {
  // put your main code here, to run repeatedly:

}
