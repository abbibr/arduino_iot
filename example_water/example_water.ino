#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
volatile int flowPulseCount = 0;
float calibrationFactor = 4.5; // This will depend on your flow sensor
float flowRate = 0;
float totalLiters = 0;
unsigned long previousMillis = 0;
const unsigned long interval = 1000; // 1-second interval

int pumpPin = 8; // Pin to control the pump

// Initialize the I2C LCD (0x27 is the I2C address, 16 columns, and 2 rows)
LiquidCrystal_I2C lcd(0x27, 16, 2); 

void setup() 
{
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP); // Flow sensor pin
  pinMode(pumpPin, OUTPUT); // Pump control pin
  attachInterrupt(digitalPinToInterrupt(2), pulseCounter, RISING); // Interrupt for flow sensor pulses
  digitalWrite(pumpPin, LOW); // Ensure pump is off initially
  lcd.begin(16, 2);        // Initialize the 16x2 LCD
  lcd.backlight();         // Turn on the backlight
}

void loop() 
{
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    // Calculate flow rate in L/h
    flowRate = ((flowPulseCount / calibrationFactor) / 7.5) * 60; // Convert pulses to L/h
    
    // Calculate total liters pumped (correctly converting from L/h to liters per second)
    totalLiters += (flowRate / 3600); // Convert flow rate from L/h to liters per second

    // Serial monitor for debugging
    Serial.print("Flow rate: ");
    Serial.print(flowRate);
    Serial.print(" L/h\t");
    Serial.print("Total liters: ");
    Serial.println(totalLiters);

    // Update the LCD without clearing
    lcd.setCursor(0, 0);     // First row, first column
    lcd.print("Rate: ");  
    lcd.print(flowRate);     
    lcd.print(" L/h  ");     // Update flow rate in L/h
    
    lcd.setCursor(0, 1);     // Second row, first column
    lcd.print("Total L: ");
    lcd.print(totalLiters);  // Update total liters pumped

    // Control the pump based on total water pumped (e.g., stop after 5 liters)
    if (totalLiters >= 5) {
      stopPump();
    } else {
      startPump();
    }

    flowPulseCount = 0; // Reset pulse count for the next second
  }
}

// Interrupt Service Routine (ISR) for counting flow sensor pulses
void pulseCounter() {
  flowPulseCount++;
}

void startPump() {
  digitalWrite(pumpPin, HIGH); // Turn the pump on
}

void stopPump() {
  digitalWrite(pumpPin, LOW); // Turn the pump off
}
