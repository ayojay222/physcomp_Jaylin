// LED pins
const int led1 = 2;
const int led2 = 4;
const int led3 = 5;
const int led4 = 18;

// Variables for controlling patterns
int pattern = 0;
int cycleCount = 0;
const int maxCycles = 12;  // Changes the patterns after the series iterations

void setup() {
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);
    pinMode(led4, OUTPUT);
}

void loop() {
    // Determine pattern based on cycle count
    if (cycleCount >= maxCycles) {
        cycleCount = 0;
        pattern = (pattern + 1) % 4; // Cycle through 4 patterns
    }

    // the LED patterns
    if (pattern == 0) {
        digitalWrite(led1, HIGH);
        digitalWrite(led2, LOW);
        digitalWrite(led3, HIGH);
        digitalWrite(led4, LOW);
    } else if (pattern == 1) {
        digitalWrite(led1, LOW);
        digitalWrite(led2, HIGH);
        digitalWrite(led3, LOW);
        digitalWrite(led4, HIGH);
    } else if (pattern == 2) {
        digitalWrite(led1, HIGH);
        digitalWrite(led2, HIGH);
        digitalWrite(led3, LOW);
        digitalWrite(led4, LOW);
    } else {
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
        digitalWrite(led3, HIGH);
        digitalWrite(led4, HIGH);
    }

    delay(500); // Wait for 500 milliseconds
    cycleCount++; // Increment cycle counter
}
