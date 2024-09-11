// Define motor control pins
#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5
#define ENA 9
#define ENB 10

// Define speed variables
int speedA = 0;
int speedB = 0;
int speedIncrement = 5; // Increment speed by 5
int maxSpeed = 255;

void setup() {
  // Set all motor control pins as output
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
}

void loop() {
  // Move forward and increase speed until max speed is reached
  moveForward();
  graduallyIncreaseSpeed();

  // Move backward and increase speed until max speed is reached
  moveBackward();
  graduallyIncreaseSpeed();

  // Turn left and increase speed until max speed is reached
  turnLeft();
  graduallyIncreaseSpeed();

  // Turn right and increase speed until max speed is reached
  turnRight();
  graduallyIncreaseSpeed();
}

// Function to gradually increase speed
void graduallyIncreaseSpeed() {
  for (int i = 0; i <= maxSpeed; i += speedIncrement) {
    analogWrite(ENA, i);
    analogWrite(ENB, i);
    delay(50); // Small delay to make the speed increase smooth
  }
  delay(1000); // Wait for a second before changing direction
}

// Function to move the car forward
void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

// Function to move the car backward
void moveBackward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

// Function to turn the car left
void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

// Function to turn the car right
void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
