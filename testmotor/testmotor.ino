// Motor Driver Pin Definitions
#define BUTTON_PIN 13  // Pin where the button is connected
#define EN_A 11  // PWM speed control for motor 1
#define motor1Pin1 6   // Control pin for right motor
#define motor1Pin2 7   // Control pin for right motor
#define motor2Pin1 8   // Control pin for left motor
#define motor2Pin2 9   // Control pin for left motor
#define EN_B 10  // PWM speed control for motor 2

// Motor speed (adjustable between 0-255)
int motorSpeedLeft = 145;  
int motorSpeedRight = 150;


void setup() {
    // Set motor control pins as outputs
    pinMode(EN_A, OUTPUT);
    pinMode(motor1Pin1, OUTPUT);
    pinMode(motor1Pin2, OUTPUT);
    pinMode(motor2Pin1, OUTPUT);
    pinMode(motor2Pin2, OUTPUT);
    pinMode(EN_B, OUTPUT);

    pinMode(BUTTON_PIN, INPUT_PULLUP); // Use internal pull-up resistor

    Serial.begin(9600);
    Serial.println("Motor System Initialized");
}

void loop() {
    // Perform movement actions
    delay(2000);
    moveForward(1500);
    delay(500);
    turnLeft(730);
    delay(500);
    moveForward(1500);
    delay(500);
    turnLeft(730);
    delay(500);
    moveForward(1500);
    delay(500);
    turnRight(700);
    stopMotors();
    delay(1000);
}

// ==================== Motor Control Functions ====================

void moveForward(int duration) {
    Serial.println("Moving Forward...");
    analogWrite(EN_A, motorSpeedLeft);
    analogWrite(EN_B, motorSpeedRight);
    digitalWrite(motor1Pin1, HIGH);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, HIGH);
    digitalWrite(motor2Pin2, LOW);
    delay(duration);
    stopMotors();
}

void turnLeft(int duration) {
    Serial.println("Turning Left...");
    analogWrite(EN_A, motorSpeedLeft);
    analogWrite(EN_B, motorSpeedRight);
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, HIGH);
    digitalWrite(motor2Pin1, HIGH);
    digitalWrite(motor2Pin2, LOW);
    delay(duration);
    stopMotors();
}

void turnRight(int duration) {
    Serial.println("Turning Right...");
    analogWrite(EN_A, motorSpeedLeft);
    analogWrite(EN_B, motorSpeedRight);
    digitalWrite(motor1Pin1, HIGH);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, HIGH);
    delay(duration);
    stopMotors();
}

void stopMotors() {
    Serial.println("Stopping Motors...");
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, LOW);
}
