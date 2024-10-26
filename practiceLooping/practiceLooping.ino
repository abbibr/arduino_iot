// Simple Arduino Program using looping statements

/* 
  a.	Write a program to find the sum of first ‘n’ natural numbers
  b.	Write a program to print the sum of digits of a number using for loop
  c.	If a four-digit number is input through the keyboard, write a program to obtain the sum of the first and last digit of this number.
  d.	Write a program to find GCD (greatest common divisor or HCF) of two numbers
  e.	Write a program to find the LCM (least common multiple) of two numbers.
  f.	Write a program to find the factorial of a given number (without recursion)
  g.	Generate a Fibonacci series without recursion
  h.	Write a program to print the following patters
  i.	Write a program to find whether the given number is Armstrong or not
  j.	Write a program to find whether the given number is perfect or not
  k.	Write a program to find whether the given number is palindrome or not
  l.	Write a program to find whether the given number is prime or not
*/


void setup() {
  // Answer: a
  int sum = 0;
  int n = 10;
  int i = 0; 

  Serial.begin(9600);

  while(i<n) {
    sum = sum + i;
    i++;
  }

  Serial.print("The sum is: ");
  Serial.println(sum);


  // Answer: b
  int number = 12355;
  int sumNumbers = 0;
  int digit;

  Serial.print("The given number: ");
  Serial.println(number);

  for(;  number > 0; number = number / 10) {
    digit = number % 10;
    sumNumbers = sumNumbers + digit;
  }

  Serial.print("Sum of digits: ");
  Serial.println(sumNumbers);

  while(number>0) {
    digit = number % 10;
    sumNumbers += digit;
  }

  Serial.print("Sum of digits with while loop: ");
  Serial.println(sumNumbers);


  // Answer: c
  int numberC = 7867;
  int firstDigitC, lastDigitC, tempC;

  Serial.print("Number: ");
  Serial.println(numberC);

  lastDigitC = numberC % 10;

  tempC = numberC;
  while (tempC >= 10) {
    tempC = tempC / 10;
  }
  firstDigitC = tempC;

  int sumC = firstDigitC + lastDigitC;

  Serial.print("Sum of the first and last digits: ");
  Serial.println(sumC);


  // Answer: d
  int num1 = 287; 
  int num2 = 91;

  Serial.print("Number 1: ");
  Serial.println(num1);
  Serial.print("Number 2: ");
  Serial.println(num2);

  while (num2 != 0) {
    int remainder = num1 % num2;
    num1 = num2;
    num2 = remainder;
  }

  Serial.print("GCD is: ");
  Serial.println(num1);


  // Answer: e
  int xyz1 = 12;
  int xyz2 = 18;

  Serial.print("The first number is: ");
  Serial.println(xyz1);
  Serial.print("The second number is: ");
  Serial.println(xyz2);

  int multiple = xyz1 * xyz2;

  while(xyz2 != 0) {
    int remainder = xyz1 % xyz2;
    xyz1 = xyz2;
    xyz2 = remainder;
  }

  Serial.print("The LCM is: ");
  Serial.println(multiple/xyz1);


  // Answer: f
  int nF = 10;
  int factorial = 1;
  int iF = 1;

  while (iF <= nF) {
    factorial = factorial * iF;
    iF++;
  }

  Serial.print("Factorial of a given number is: ");
  Serial.println(factorial);


  // Answer: g
  int k = 10;
  int t1 = 0, t2=1, nextTerm;
  int iG = 1;

  Serial.print("Fibonacci Series: ");
  Serial.print(t1);

  while (iG<k) {
    Serial.print(", ");
    Serial.print(t2);

    nextTerm = t1 + t2;

    t1=t2;
    t2=nextTerm;
    iG++;
  }

  /* for(int i=1; i<k; i++) {
    Serial.print(", ");
    Serial.print(t2);

    nextTerm = t1 + t2;
    t1 = t2;
    t2 = nextTerm;
  } */


  // Answer: i
  int numberI = 153;
  int sumI = 0;
  
  while(numberI > 0) {
    int remainder = numberI % 10;
    numberI = numberI / 10;

    // while()

    for(int JK=1; JK<=numberI; JK++) {
      Serial.print("Test: ");
      Serial.println(JK);
    }

    Serial.print("Remainder: ");
    Serial.println(remainder);
  }

}

void loop() {
  // put your main code here, to run repeatedly:

}
