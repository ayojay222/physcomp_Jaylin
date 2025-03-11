#define BUTTON_PIN  18  // Button input pin
#define LED1        2   // LED pins
#define LED2        4
#define LED3        5
#define LED4        6

int buttonState = 0;  // Variable to store button state
int lastButtonState = 1;  // Track previous button state
int pattern = 0;  // Variable to track LED pattern

void setup() {
    pinMode(BUTTON_PIN, INPUT_PULLUP);  //put internal pull-up resistor
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(LED3, OUTPUT);
    pinMode(LED4, OUTPUT);

void loop() {
    buttonState = digitalRead(BUTTON_PIN);

    // Detect button press (active LOW, avoids bouncing)
    if (buttonState == 0 && lastButtonState == 1) {
        pattern++;  // Increment pattern counter
        if (pattern > 3) pattern = 0;  // Rollover if past last pattern
        delay(200);  // Debounce delay
    }
    lastButtonState = buttonState;  // Update button state

    // Display the LED pattern based on counter
    if (pattern == 0) {
        digitalWrite(LED1, HIGH);
        digitalWrite(LED2, LOW);
        digitalWrite(LED3, LOW);
        digitalWrite(LED4, LOW);
    } 
    else if (pattern == 1) {
        digitalWrite(LED1, LOW);
        digitalWrite(LED2, HIGH);
        digitalWrite(LED3, LOW);
        digitalWrite(LED4, HIGH);
    } 
    else if (pattern == 2) {
        digitalWrite(LED1, HIGH);
        digitalWrite(LED2, HIGH);
        digitalWrite(LED3, LOW);
        digitalWrite(LED4, LOW);
    } 
    else if (pattern == 3) {
        digitalWrite(LED1, LOW);
        digitalWrite(LED2, LOW);
        digitalWrite(LED3, HIGH);
        digitalWrite(LED4, HIGH);
    }
}
