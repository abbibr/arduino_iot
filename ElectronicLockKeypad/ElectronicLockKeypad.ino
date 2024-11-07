#include <Keypad.h>
#include <LiquidCrystal_I2C.h> 
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 20, 4); 

// Length of password + 1 for null character
#define Password_Length 8
// Character to hold password input
char Data[Password_Length];
// Password 
char Master[Password_Length] = "580#96B";

// Pin connected to lock relay input (anypin we can use)
int lockOutput = 13;

// Counter for character entries
byte data_count = 0;

// Character to hold key input
char customKey;

const byte ROWS = 4;
const byte COLS = 4;
int ledPin = 12;
int buzzer = 11;

char arrayKeypad[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'},
};

// Connections to Arduino
byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

Keypad customKeypad = Keypad(makeKeymap(arrayKeypad), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzer, OUTPUT);

  // Set lockOutput as an OUTPUT pin
  pinMode(lockOutput, OUTPUT);

  lcd.init();
  lcd.backlight();
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("Enter password: ");

  // Look for keypress
  char valueKey = customKeypad.getKey();

  if(valueKey) {    
    // Enter keypress into array and increment counter
    Data[data_count] = valueKey;
    lcd.setCursor(data_count, 1);
    lcd.print(Data[data_count]);
    data_count++;
  }

  // See if we have reached the password length
  if(data_count == Password_Length - 1) {
    lcd.clear();

    // compare two password is same or not (Data array which we enter password through keypad, Master array is our correct password)
    if(!strcmp(Data, Master)) {
      // Password is correct
      lcd.print("Correct Password)");

      // Turn on relay for 5 seconds
      digitalWrite(lockOutput, HIGH);
      digitalWrite(ledPin, HIGH);
      delay(5000);
      digitalWrite(lockOutput, LOW);
      digitalWrite(ledPin, LOW);
    }
    else {
      // Password is incorrect
      lcd.print("Incorrect password!");

      digitalWrite(buzzer, HIGH);
      delay(1000);
      digitalWrite(buzzer, LOW);
    }

    // Clear data and LCD displaym 
    lcd.clear();
    clearData();
  }
}

void clearData() {
  // Go through array and clear data (iterating the loop when data_count is up to 0)

  while(data_count != 0) {
    Data[data_count--] = 0;
  }
}

