#include <Servo.h>

Servo servo1; // Servo connected to pin 6
Servo servo2; // Servo connected to pin 7
Servo servo3; // Servo connected to pin 4
Servo servo4; // Servo connected to pin 5
Servo servo5; // New Servo connected to pin 8

void setup() {
  servo1.attach(3); // Attach the first servo to pin 6
  servo2.attach(2); // Attach the second servo to pin 7
  servo3.attach(6); // Attach the third servo to pin 4
  servo4.attach(5); // Attach the fourth servo to pin 5
  servo5.attach(4); // Attach the new fifth servo to pin 8
}

void loop() {
  bothopen();
  delay(1000);
  lookright();
  delay(1000);
  lookleft();
  delay(1000);
  rightblink();
  delay(1000);
  leftblink();
  delay(1000);
  bothclose();
  delay(1000);
  // for (int pos1 = 180, pos2 = 90, pos5 = 90; pos1 >= 80 && pos2 <= 180 && pos5 <= 160; pos1--, pos2++, pos5++) {
  //   servo1.write(pos1); // Set first servo to current position
  //   servo2.write(pos2); // Set second servo to current position
  //   servo3.write(pos1); // Set third servo to current position
  //   servo4.write(pos2); // Set fourth servo to current position
  //   servo5.write(pos5); // Set fifth servo to current position (90 to 160 degrees)
  //   delay(50); // Small delay for smooth movement
  // }

  // // Move all servos back to their starting positions
  // for (int pos1 = 80, pos2 = 180, pos5 = 160; pos1 <= 180 && pos2 >= 90 && pos5 >= 90; pos1++, pos2--, pos5--) {
  //   servo1.write(pos1); // Set first servo to current position
  //   servo2.write(pos2); // Set second servo to current position
  //   servo3.write(pos1); // Set third servo to current position
  //   servo4.write(pos2); // Set fourth servo to current position
  //   servo5.write(pos5); // Set fifth servo to current position (160 back to 90 degrees)
  //   delay(5); // Small delay for smooth movement
  // }

  // // Optionally, you can add a delay before starting the loop again
  // delay(1000); // Wait for 1 second before repeating
}
void rightblink(){
  for (int pos1 = 180, pos2 = 90; pos1 >= 80 && pos2 <= 180; pos1--, pos2++) {
    servo1.write(pos1); // Set first servo to current position
    servo4.write(pos2); // Set fourth servo to current position
    delay(5); // Small delay for smooth movement
  }
}

void leftblink(){
   for (int pos1 = 180, pos2 = 90; pos1 >= 80 && pos2 <= 180; pos1--, pos2++) {
  servo3.write(pos1); // Set third servo to current position
  servo2.write(pos2); // Set fourth servo to current position
  delay(5); // Small delay for smooth movement
  }
  
  
}
void bothopen(){
  for (int pos1 = 180, pos2 = 90; pos1 >= 80 && pos2 <= 180; pos1--, pos2++) {
    servo1.write(pos1); // Set first servo to current position
    servo2.write(pos2); // Set second servo to current position
    servo3.write(pos1); // Set third servo to current position
    servo4.write(pos2); // Set fourth servo to current position
    delay(5); // Small delay for smooth movement
  }

}
void bothclose(){

 for (int pos1 = 80, pos2 = 180; pos1 <= 180 && pos2 >= 90; pos1++, pos2--) {
    servo1.write(pos1); // Set first servo to current position
    servo2.write(pos2); // Set second servo to current position
    servo3.write(pos1); // Set third servo to current position
    servo4.write(pos2); // Set fourth servo to current position
    delay(5); // Small delay for smooth movement
  }
}  
void lookright(){
  for (int pos5 = 90 ;pos5 <= 160 ;pos5++) {
    servo5.write(pos5);
    delay(15);// Set first servo to current position
  }
}

void lookleft(){
  for (int pos5 = 160; pos5 >= 90; pos5--) {
    servo5.write(pos5); // Set first servo to current position
  }
}
