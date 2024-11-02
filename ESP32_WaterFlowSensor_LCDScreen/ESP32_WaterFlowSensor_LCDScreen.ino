/*
  YF‐ S201 Water Flow Sensor
  Water Flow Sensor output processed to read in litres/minute and litres/hour
*/

#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

volatile int flow_frequency; // Measures flow sensor pulses
float l_min;                 // Calculated liters/minute
float l_hour;                // Calculated liters/hour
float totalLiters = 0;       // Total liters spent
const unsigned char flowsensor = 2; // Sensor Input (e.g., GPIO 2 on ESP32)
unsigned long currentTime;
unsigned long cloopTime;

void IRAM_ATTR flow() // Interrupt function
{
   flow_frequency++;
}

void setup()
{
  pinMode(flowsensor, INPUT);
  digitalWrite(flowsensor, HIGH); // Optional Internal Pull-Up
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(flowsensor), flow, RISING); // Setup Interrupt for ESP32
  currentTime = millis();
  cloopTime = currentTime;

  Wire.begin(21, 22);
  Wire.setClock(100000);
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Welcome to AquaCare)");
  lcd.clear();
}

void loop()
{
   currentTime = millis();
   // Every second, calculate and print liters/minute and liters/hour
   if (currentTime >= (cloopTime + 1000))
   {
      cloopTime = currentTime; // Updates cloopTime
      
      // Calculate flow rate in L/min
      l_min = (flow_frequency / 7.5); 
      
      // Convert flow rate to L/h
      l_hour = l_min * 60; // 1 minute = 60 seconds, so multiply L/min by 60 to get L/h
      
      // Accumulate total water spent in liters
      totalLiters += (l_min / 60); // Convert from L/min to liters per second and add to total

      // Reset the pulse count
      flow_frequency = 0;

      // Print the results
      Serial.print("Flow rate: ");
      Serial.print(l_hour, 2); // Print liters/hour with 2 decimal places
      Serial.print(" L/h\t");
      Serial.print("Total liters spent: ");
      Serial.println(totalLiters, 2); // Print total liters spent with 2 decimal places
   }
}
