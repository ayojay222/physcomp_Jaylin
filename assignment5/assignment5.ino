import processing.serial.*;

Serial myPort;  // Create a Serial object
float sensorValue;  // Holds incoming sensor data
float circleSize, rectWidth, bgColor; 

void setup() {
  size(800, 600);  // Display window width & height
  myPort = new Serial(this, "COM3", 9600);  //  port name setup
}

void draw() {
  background(bgColor);  

  // Map sensor values to control different elements
  circleSize = map(sensorValue, 0, 1023, 50, 300);  
  rectWidth = map(sensorValue, 0, 1023, 50, 400);
  bgColor = map(sensorValue, 0, 1023, 0, 255);
  
  // Draw shapes
  fill(255, 0, 0);
  ellipse(width/2, height/3, circleSize, circleSize);

  fill(0, 255, 0);
  rect(width/4, height/2, rectWidth, 50);

  stroke(0, 0, 255);
  strokeWeight(4);
  line(100, height-50, width-100, height-50);
}

void serialEvent(Serial myPort) {
  String inData = myPort.readStringUntil('\n');
  if (inData != null) {
    sensorValue = float(trim(inData)); // Convert to float
    sensorValue = constrain(sensorValue, 0, 1023); // Ensure valid range
  }
}
