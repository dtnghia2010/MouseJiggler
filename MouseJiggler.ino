#include <Servo.h>

Servo myServo;
int servoPin = 9;
int angle = 0;

void setup() {
  Serial.begin(115200); // Start serial communication for debugging
  
  // Seed the random number generator with noise from analog pin 0
  randomSeed(analogRead(0));
  myServo.attach(servoPin);
}

void loop() {
  // Generate random numbers
  int delay1 = random(20, 200);       // Random number between 0 and 99
  int delay2 = random(10, 300);  // Random number between 50 and 149

  for(angle = 0; angle <= 180; angle += 1) {
    myServo.write(angle);
    delay(delay1);
  }
  for(angle = 180; angle >= 0; angle -= 1) {
    myServo.write(angle);
    delay(delay2);
  }
}
