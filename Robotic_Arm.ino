#include <Servo.h>
const int NUM_SERVOS = 4;
Servo myServos[NUM_SERVOS];
const int potPins[NUM_SERVOS]   = {A0, A1, A2, A3};  // Analog input pins
const int servoPins[NUM_SERVOS] = {9, 5, 11, 6};   // PWM digital output pins
void setup() {
  // Attach each servo object to its respective pin
  for (int i = 0; i < NUM_SERVOS; i++) {
    myServos[i].attach(servoPins[i]);
  }
}
void loop() {
  for (int i = 0; i < NUM_SERVOS; i++) {
    // 1. Read raw voltage from current potentiometer (0 to 1023)
    int potValue = analogRead(potPins[i]);
    // 2. Map it to degrees (0 to 180)
    int angle = map(potValue, 0, 1023, 0, 180);
    // 3. Write the calculated angle to the corresponding servo
    myServos[i].write(angle);
  }
  // Small delay to keep the system stable and allow mechanical movement
  delay(15); 
}
