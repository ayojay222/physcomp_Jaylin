const int potPin = 34;  // GPIO2 → Potentiometer

void setup() {
  Serial.begin(115200);  
}

void loop() {
  int potVal = analogRead(potPin);                 // Range: 0–4095
  int angle = map(potVal, 0, 4095, 0, 180);        // servo angle

  // Send values to Processing
  //  potVal, angle (send dummy values to match 6-value format)
  Serial.print(0); // dummy light value
  Serial.print(",");
  Serial.print(potVal);
  Serial.print(",");
  Serial.print(0); //  R
  Serial.print(",");
  Serial.print(0); //  G
  Serial.print(",");
  Serial.print(0); //  B
  Serial.print(",");
  Serial.println(angle);

  delay(100);
}

