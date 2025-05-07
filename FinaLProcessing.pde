import processing.serial.*;

Serial myPort;

int lightVal = 0;
int r = 0, g = 0, b = 0;
int servoAngle = 0;

void setup() {
  size(600, 600);
  printArray(Serial.list()); // Check for your Arduino port
  myPort = new Serial(this, Serial.list()[0], 9600); // Change index if needed
  myPort.bufferUntil('\n');
}

void draw() {
  background(r, g, b);

  // Mood label
  fill(255);
  textSize(20);
  textAlign(LEFT);
  text("Digital Mood Lamp", 20, 30);
  text("Light Level: " + lightVal, 20, 60);
  text("Servo Angle: " + servoAngle + "°", 20, 90);
  text("Mood Color: RGB(" + r + ", " + g + ", " + b + ")", 20, 120);

  // Draw a circle to represent the lamp
  fill(r, g, b);
  stroke(255);
  strokeWeight(2);
  ellipse(width/2, height/2, 250, 250);

  // Draw servo "arm"
  pushMatrix();
  translate(width / 2, height / 2);
  stroke(255);
  strokeWeight(6);
  float theta = radians(servoAngle - 90); // rotate visually
  line(0, 0, 100 * cos(theta), 100 * sin(theta));
  popMatrix();
}

void serialEvent(Serial myPort) {
  String input = myPort.readStringUntil('\n');
  if (input != null) {
    String[] values = trim(input).split(",");
    if (values.length == 5) {
      lightVal = int(values[0]);
      r = int(values[1]);
      g = int(values[2]);
      b = int(values[3]);
      servoAngle = int(values[4]);
    }
  }
}
