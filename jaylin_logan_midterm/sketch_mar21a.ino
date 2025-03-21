// Pins
const int potPin = 1;      // Potentiometer input
const int buttonPin = 2;   // Button input
const int led1 = 9;        // LED 1 (PWM controlled)
const int led2 = 10;       // LED 2 (PWM controlled)
const int buzzer = 3;      // Piezo buzzer

// Variables
int brightness = 0;
int buttonState = 0;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); // Enable internal pull-up resistor
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(buzzer, OUTPUT);

  Serial.begin(115200);
}

void loop() {
  // Read potentiometer and map to PWM range (0-255)
  brightness = analogRead(potPin);
  brightness = map(brightness, 0, 1023, 0, 255);

  // Read button state
  buttonState = digitalRead(buttonPin);

  // If button is pressed, turn on both LEDs and play buzzer
  if (buttonState == LOW) {  
    analogWrite(led1, brightness);
    analogWrite(led2, brightness);
    tone(buzzer, 1000);  // Play a 1000Hz tone
  } else {  
    analogWrite(led1, 0); // Turn off LEDs
    analogWrite(led2, 0);
    noTone(buzzer);  // Stop buzzer
  }

  //  output
  Serial.print("Brightness: ");
  Serial.print(brightness);
  Serial.print("\t Button Pressed: ");
  Serial.println(buttonState == LOW ? "YES" : "NO");
}
