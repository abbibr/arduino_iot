/*
  YF‐ S201 Water Flow Sensor
  Water Flow Sensor output processed to read in litres/minute and litres/hour
*/

#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);  // LCD with I2C address 0x27, 20 columns, and 4 rows

volatile int flow_frequency = 0;     // Measures flow sensor pulses
float l_min = 0;                     // Calculated liters/minute
float l_hour = 0;                    // Calculated liters/hour
float totalLiters = 0;               // Total liters spent
const unsigned char flowsensor = 2;  // Sensor Input (e.g., GPIO 2 on ESP32)
unsigned long currentTime;
unsigned long cloopTime;

void IRAM_ATTR flow() 
{ 
   flow_frequency++;  // Interrupt function to count pulses
}

void setup() {
  pinMode(flowsensor, INPUT_PULLUP); // Setup the flow sensor pin with an internal pull-up
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(flowsensor), flow, RISING); // Setup interrupt on flow sensor

  Wire.begin(21, 22);  // Initialize I2C for ESP32 on pins 21 (SDA) and 22 (SCL)
  lcd.init();          // Initialize the LCD
  lcd.backlight();     // Turn on the LCD backlight

  lcd.setCursor(0, 0);
  lcd.print("Welcome to AquaCare"); // Initial welcome message

  currentTime = millis();
  cloopTime = currentTime;
}

void loop() {
  currentTime = millis();

  // Every second, calculate and display liters/minute and liters/hour
  if (currentTime - cloopTime >= 1000) {
    cloopTime = currentTime; // Update cloopTime

    // Calculate flow rate in L/min and L/h
    l_min = (flow_frequency / 7.5);  // Convert pulses to L/min
    l_hour = l_min * 60;             // Convert L/min to L/h
    totalLiters += (l_min / 60);     // Add to total liters in L/min converted to liters per second

    // Reset pulse count
    flow_frequency = 0;

    // Print the flow rate and total liters to Serial Monitor
    Serial.print("Flow rate: ");
    Serial.print(l_hour, 2); // Print liters/hour with 2 decimal places
    Serial.print(" L/h, ");
    Serial.print("Total liters spent: ");
    Serial.println(totalLiters, 2); // Print total liters with 2 decimal places

    lcd.setCursor(0, 2);
    lcd.print("Flow Rate: ");
    lcd.print(l_hour, 2);
    lcd.print(" L/h");

    lcd.setCursor(0, 3);
    lcd.print("Total Liters: ");
    lcd.print(totalLiters, 2);
    lcd.print(" L");
  }
}
