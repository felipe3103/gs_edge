// C++ code
//
#include <Servo.h>

int i = 0;

int j = 0;

int cm = 0;

int inches = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

Servo servo_12;

void setup()
{
  servo_12.attach(12, 500, 2500);
}

void loop()
{
  if (0.01723 * readUltrasonicDistance(7, 7) < 70) {
    servo_12.write(90);
  } else {
    servo_12.write(0);
  }
  delay(10); // Delay a little bit to improve simulation performance
}