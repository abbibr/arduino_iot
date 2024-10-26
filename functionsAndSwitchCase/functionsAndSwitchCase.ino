void setup() {
  Serial.begin(9600);

  int x = 45;

  /* switch case */

  switch(x) {
    case 1 ... 10: 
      Serial.println("Your case is 1!");
      break;
    case 11 ... 20: 
      Serial.println("Your case is 2!");
      break;
    case 21 ... 30: 
      Serial.println("Your case is 3!");
      break;
    case 31 ... 40: 
      Serial.println("Your case is 4!");
      break;
    case 41 ... 50: 
      Serial.println("Your case is 5!");
      break;
    default: 
      Serial.println("This is default one!");
      break;
  }


  /* arrays */

  int abc[3] = {0, 1, 2};
  Serial.println(abc[0]);
  int i = 0;
  int sum = 0;

  Serial.print("The numbers in the array are: ");

  while (i < 3) {
    int value = abc[i];
    Serial.print(value);

    sum = sum + value;

    if (i != 2) {
      Serial.print(", ");
    }

    i++;
  }
  
  Serial.println();
  Serial.print("The sum of matrix is: ");
  Serial.println(sum);


  /* strings */
  
  char smth[] = "Abc";
  Serial.println(smth);

  char wow[5] = {'a', 'b', 'c', 'd', '\0'};
  Serial.println(wow); // result: abcd

}

void loop() {
  // put your main code here, to run repeatedly:

}
