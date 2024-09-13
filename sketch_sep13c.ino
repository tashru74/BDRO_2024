#include <Servo.h>  // Include Servo library

// Motor control pins
int IN1 = 2;
int IN2 = 3;
int IN3 = 4;
int IN4 = 5;

// Sonar sensor pins
int trigPin = 8;
int echoPin = 9;

// Servo pin
int servoPin = 6;

// Define variables for distance measurement
long duration;
int distance;

// Create a servo object
Servo sonarServo;

void setup() {
  // Set motor pins as outputs
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Set sonar sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Attach servo to its pin
  sonarServo.attach(servoPin);
  
  // Initialize servo position (pointing forward)
  sonarServo.write(90);

  // Start Serial Monitor for debugging
  Serial.begin(9600);
}

void loop() {
  // Scan left and right with the sonar to check for obstacles
  int distanceLeft = scanDistance(0);   // Check distance to the left
  int distanceRight = scanDistance(180); // Check distance to the right
  
  // Check forward distance
  sonarServo.write(90); // Point forward
  delay(500);
  int distanceForward = getDistance();

  // Decision-making for movement
  if (distanceForward > 20) {
    // If no obstacle ahead, move forward
    moveForward();
  } else {
    // Stop if obstacle is detected
    stopRobot();

    // Decide direction based on sonar readings
    if (distanceLeft > distanceRight) {
      turnLeft();  // Turn left if more space on the left
    } else {
      turnRight();  // Turn right if more space on the right
    }
  }

  delay(200);
}

// Function to get distance from ultrasonic sensor
int getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echoPin and calculate distance
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;  // Speed of sound calculation

  return distance;
}

// Function to scan in a specific direction with the sonar
int scanDistance(int angle) {
  sonarServo.write(angle);
  delay(500);
  return getDistance();
}

// Function to move forward
void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

// Function to stop the robot
void stopRobot() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

// Function to turn left
void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(500);  // Turn for half a second
}

// Function to turn right
void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(500);  // Turn for half a second
}
