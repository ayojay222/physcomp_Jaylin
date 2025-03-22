// Pin Definitions
const int buttonPin = 2;   // Push button input
const int led1 = 5;        // LED 1
const int led2 = 6;        // LED 2
const int led3 = 7;        // LED 3
const int led4 = 8;        // LED 4

// Variables
int buttonState = 0;
int lastButtonState = 1;  // Assume HIGH at start (ESP32 internal pull-up)
int pattern = 0;          // Stores the current pattern
int debounceDelay = 50;   // Debounce delay
unsigned long lastDebounceTime = 0;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); // Enable pull-up resistor
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

  Serial.begin(115200);
}

void loop() {
  // Read button state with debounce
  int reading = digitalRead(buttonPin);
  if (reading == LOW && lastButtonState == HIGH && millis() - lastDebounceTime > debounceDelay) {
    pattern++;  // Increment pattern on button press
    if (pattern > 4) {
      pattern = 1;  // Reset to first pattern when exceeding 4
    }
    lastDebounceTime = millis();
  }
  lastButtonState = reading;

  // LED Patterns
  if (pattern == 1) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);
  } 
  else if (pattern == 2) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(led4, HIGH);
  } 
  else if (pattern == 3) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  } 
  else if (pattern == 4) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
  }

  // Debugging output
  Serial.print("Pattern: ");
  Serial.println(pattern);
}
