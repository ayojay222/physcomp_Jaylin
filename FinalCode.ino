#include <Servo.h>

const int sensorPin = A0;    // Light sensor pin
const int servoPin = 9;      // Micro servo control pin

Servo myServo;

void setup() {
  Serial.begin(9600);
  myServo.attach(servoPin);
}

void loop() {
  int lightVal = analogRead(sensorPin); // 0 to 1023

  // Convert light to servo angle (0° = dark, 180° = bright)
  int angle = map(lightVal, 0, 1023, 0, 180);
  myServo.write(angle);

  // Convert to RGB values for Processing visualization
  int red = map(lightVal, 0, 1023, 255, 100);   // Dark = warm
  int green = map(lightVal, 0, 1023, 50, 255);  // Brighter = calmer
  int blue = map(lightVal, 0, 1023, 100, 255);  // Mix of tones

  // Send data to Processing: light, R, G, B, angle
  Serial.print(lightVal);
  Serial.print(",");
  Serial.print(red);
  Serial.print(",");
  Serial.print(green);
  Serial.print(",");
  Serial.print(blue);
  Serial.print(",");
  Serial.println(angle);

  delay(100); // Slight pause for stability
}
