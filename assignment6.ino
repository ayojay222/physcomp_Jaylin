const int potPin = A0;      // Potentiometer pin
const int photoPin = A1;    // Photocell pin
const int buttonPin = 2;    // Button pin
const int touchPin = 3;     // Touch sensor pin

void setup() {
    Serial.begin(9600);
    pinMode(buttonPin, INPUT_PULLUP);
    pinMode(touchPin, INPUT);
}

void loop() {
    int potValue = analogRead(potPin);
    int photoValue = analogRead(photoPin);
    int buttonState = digitalRead(buttonPin);
    int touchState = digitalRead(touchPin);

    Serial.print(potValue);
    Serial.print(",");
    Serial.print(photoValue);
    Serial.print(",");
    Serial.print(buttonState);
    Serial.print(",");
    Serial.println(touchState);

    delay(100); // Adjust refresh rate
}
