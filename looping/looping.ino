// Looping Statements!

void setup() {
  Serial.begin(9600);

 /* 
    *
    **
    ***
    ****
    *****
 */

  for(int i=0; i<5; i++) {
    for(int j=0; j<=i; j++) {
      Serial.print("*");
    }

    Serial.println();
  }

  for(int m=5; m>0; m--) {
    for(int n=0; n<m; n++) {
      Serial.print("*");
    }

    Serial.println();
  }

  Serial.println();

  int n = 5;  // The maximum number of stars in the middle row
  int totalRows = 2 * n - 1;  // Total rows in the pattern

  // Use a single loop to print the pattern
  for (int i = 1; i <= totalRows; i++) {
    // Determine the number of stars to print for the current row
    int stars = (i <= n) ? i : (totalRows - i + 1);

    // Print the stars
    for (int j = 1; j <= stars; j++) {
      Serial.print("*");
    }
    Serial.println();  // Move to the next line
    delay(500);        // Small delay for readability in the output
  }


  int multiple = 1;

  while(multiple <= 10) {
    Serial.println(multiple * 2);
    multiple++;
  }


  int multy = 1;
  do {
    Serial.println(multy * 2);
    multy++;
    delay(500);
  } 
  while(multy>=10);

}

void loop() {
  /* static int xyz = 0;

  xyz++;
  Serial.println(xyz);
  delay(500); */

  static int xyz;

  while(xyz>5) {
    Serial.println("We are in the while loop now!");
    delay(500);
  }

  xyz++;
  Serial.println(xyz);
  delay(500);
}
