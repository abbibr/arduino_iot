int bluePin = 13;
int button = 7;
int ledState = LOW;         // Variable to track LED state
int buttonState = 0;        // Variable to store the current button state
int lastButtonState = 0;    // Variable to store the last button state

void setup() {
  Serial.begin(9600);
  pinMode(button, INPUT);  // Set button with internal pull-up
  pinMode(bluePin, OUTPUT);
  digitalWrite(bluePin, ledState);  // Ensure LED starts off
}

void loop() {
  buttonState = digitalRead(button);
  Serial.println(buttonState);

  // Check if the button is pressed and only toggle when button is first pressed
  if (buttonState == HIGH && lastButtonState == LOW) {
    ledState = !ledState;                 // Toggle LED state
    digitalWrite(bluePin, ledState);      // Set LED to new state
    delay(50);                            // Debounce delay
  }

  lastButtonState = buttonState;          // Save the current state for next loop
}
