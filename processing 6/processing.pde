import processing.serial.*;

Serial myPort;
int shapeSize = 50;
float bgBrightness = 100;
boolean shapeToggle = false;
color shapeColor = color(255, 0, 0);

void setup() {
    size(800, 600);
    myPort = new Serial(this, Serial.list()[0], 9600);
    myPort.bufferUntil('\n'); // Wait until end of line
}

void draw() {
    background(bgBrightness); // Control background brightness

    fill(shapeColor);
    
    if (shapeToggle) {
        ellipse(width / 2, height / 2, shapeSize, shapeSize); // Draw circle
    } else {
        rectMode(CENTER);
        rect(width / 2, height / 2, shapeSize, shapeSize); // Draw square
    }
}

void serialEvent(Serial p) {
    String data = p.readStringUntil('\n');
    if (data != null) {
        String[] values = split(trim(data), ",");
        if (values.length == 4) {
            int potValue = int(values[0]);
            int photoValue = int(values[1]);
            int buttonState = int(values[2]);
            int touchState = int(values[3]);

            // Map values to usable ranges
            shapeSize = int(map(potValue, 0, 1023, 20, 200));
            bgBrightness = map(photoValue, 0, 1023, 0, 255);

            if (buttonState == 0) {
                shapeToggle = !shapeToggle; // Toggle shape
            }

            if (touchState == 1) {
                shapeColor = color(random(255), random(255), random(255)); // Random color on touch
            }
        }
    }
}
