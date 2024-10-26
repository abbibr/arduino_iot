// Simple Arduino Programs using decision statements

/* 
  a.	Write a program to find the largest among two numbers
  b.	Write a program to find the largest among three numbers
  c.	Write a program to find the roots of quadratic equation
  d.	Write a program to print whether a given number is even or odd
  e.	Write a program to compute grade of students using if else. The grades are assigned as follows:
  f.	Write a program to check whether the entered year is leap year or not (a year is leap if it is divisible by 4 and divisible by 100 or 400.)
*/

void setup() {
  // Answer: a
  int x = 5;
  int y = 5;

  Serial.begin(9600);

  if (x > y) {
    Serial.println("The largest number is: x");
  }
  else if (x == y) {
    Serial.println("Both numbers are equal!");
  }
  else {
    Serial.println("The largest number is: y");
  }


  // Answer: b
  int a=17;
  int b=10;
  int c=15;

  if(a>b && b>c) {
    Serial.println("The largest number is: a");
    Serial.println("The second largest number is: b");
    Serial.println("The smallest number is: c");
  }
  if(a>b && a>c && b<c) {
    Serial.println("The largest number is: a");
    Serial.println("The second largest number is: c");
    Serial.println("The smallest number is: b");
  }
  else if(a>b && a<c) {
    Serial.println("The largest number is: c");
    Serial.println("The second largest number is: a");
    Serial.println("The smallest number is: b");
  }
  else if(c>a && c>b && b>a) {
    Serial.println("The largest number is: c");
    Serial.println("The second largest number is: b");
    Serial.println("The smallest number is: a");
  }
  else if(b>a && b>c && a>c) {
    Serial.println("The largest number is: b");
    Serial.println("The second largest number is: a");
    Serial.println("The smallest number is: c");
  }
  else if(b>a && b>c && a<c) {
    Serial.println("The largest number is: b");
    Serial.println("The second largest number is: c");
    Serial.println("The smallest number is: a");
  }
  else {
    Serial.println("All numbers are equal!");
  }


  // Answer: c
  float aD=1;
  float bD=4;
  float cD=2;
  float D=pow(bD, 2) - (4*aD*cD);

  if (D>0) {
    float x1 = ((-bD - sqrt(D)) / (2*aD));
    float x2 = ((-bD + sqrt(D)) / (2*aD));

    Serial.println("There are 2 roots in the equation. They are: ");
    Serial.print("x1 is: ");
    Serial.println(x1);
    Serial.print("x2 is: ");
    Serial.println(x2);
  }
  if (D==0) {
    float x = ((-bD + sqrt(D)) / (2*aD));

    Serial.println("There is 1 root in the equation: ");
    Serial.print("x is: ");
    Serial.println(x);
  }
  else {
    Serial.println("There is not any root in the equation! Because D < 0");
  }


  // Answer: d
  int xyz=12;
  if(xyz % 2 == 0) {
    Serial.println("The given number is even");
  }
  else {
    Serial.println("The given number is odd");
  }


  // Answer: e
  int grade=95;

  if(grade>=90 && grade<=100) {
    Serial.println("Your grade is: A+");
  }
  else if(grade>=80 && grade<90) {
    Serial.println("Your grade is: A");
  }
  else if(grade>=70 && grade<80) {
    Serial.println("Your grade is: B+");
  }
  else if(grade>=60 && grade<70) {
    Serial.println("Your grade is: B");
  }
  else if(grade>=50 && grade<60) {
    Serial.println("Your grade is: C");
  }
  else {
    Serial.println("Your grade is: F");
  }


  // Answer: f
  int year=2220;

  if(year % 4 == 0 && (year % 100 == 0 || year % 400 == 0)) {
    Serial.println("This is leap year!");
  }
  else {
    Serial.println("It is not leap year!");
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
