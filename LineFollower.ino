/* Assumes you've wired up your line follower according to the available wiring
 * diagram. Requires installation of QTRSensor Library as per
 * https://www.pololu.com/docs/0J19/2)
 *
 * Skeleton code for your line follower!
 */
#include <QTRSensors.h>                 // The sensor library

#define NUM_SENSORS             3       // Reflectance sensor has 3 individual sensors
#define NUM_SAMPLES_PER_SENSOR  4       // Averge 4 analog samples per sensor reading

int leftWheelB = 22;
int leftWheelA = 23;
int rightWheelB = 9;
int rightWheelA = 10;

int onboardLED = 13;

// Object for three QTR-xA sensors on analog inputs 14, 15, and 16.
QTRSensorsAnalog qtra((unsigned char[]) {14, 15, 16},
                      NUM_SENSORS, NUM_SAMPLES_PER_SENSOR);

unsigned int sensorValues[NUM_SENSORS]; // For storing sensor readings

void setup() {
  // Pin configuration
  pinMode(leftWheelB, OUTPUT);
  pinMode(leftWheelA, OUTPUT);
  pinMode(rightWheelB, OUTPUT);
  pinMode(rightWheelA, OUTPUT);
  pinMode(onboardLED, OUTPUT);
  // Show when robot is on
  digitalWrite(onboardLED, HIGH);
  // Serial debug start
  Serial.begin(9600);

  // TODO: ADVANCED
  // If you want to improve your line follower further, you can use PID control.
  // Ask a HURC member about this topic once you get your line follower working!
  /* PID variables:
  // PID gains
  kp = 0;
  ki = 0;
  kd = 0;

  // error accumulators
  cumulative_error = 0;
  prev_error = 0;
  */
}

void setDriveSpeed(int left, int right) {
  if(left > 0) {
    analogWrite(leftWheelA, left);
    analogWrite(leftWheelB, 0);
  }
  else if (left < 0) {
    analogWrite(leftWheelB, -1*left);
    analogWrite(leftWheelA, 0);
  }
  else {
    analogWrite(leftWheelA, 0);
    analogWrite(leftWheelB, 0);
  }
  if(right > 0) {
    analogWrite(rightWheelB, right);
    analogWrite(rightWheelA, 0);
  }
  else if (right < 0) {
    analogWrite(rightWheelA, -1*right);
    analogWrite(rightWheelB, 0);
  }
  else {
    analogWrite(rightWheelA, 0);
    analogWrite(rightWheelB, 0);
  }
}

void turnRight() {
  setDriveSpeed(100,0);
}

void turnLeft() {
  setDriveSpeed(0,-100);
}

void loop() {
  // Acquire sensor readings
  qtra.read(sensorValues);

   // Iterate over all sensors and print their reading followed by a tab
  for (unsigned char i = 0; i < NUM_SENSORS; i++) {
    Serial.print(sensorValues[i]);
    Serial.print("\t");
  }
  Serial.println();

  /* TODO: Your code here!
   * Right now the robot doesn't take any of the sensor readings into account,
   * it just constantly turns right. Your job is to incorporate your sensor
   * readings into a decision about how to drive the motors!
   */

  turnRight();

  delay(10);


  // TODO: ADVANCED
  // If you want to improve your line follower further, you can use PID control.
  // Ask a HURC member about this topic once you get your line follower working!
  /* PID control loop
  // definition of error changes depending on sensors used
  error = (on.light - off.light) - THRESHOLD; // polarity might be change depending on system orientation

  // update error integration
  cumulative_error += error;

  // calculate error derivative
  error_derivative = error - prev_error;

  control = kp * error + ki * cumulative_error + kd * error_derivative;
  drive = control; // need some conversion of control to drive signal (need real values to determine this)
  setDriveSpeed(20, drive); // only need to control right wheel's speed if you keep the other constant

  // update error buffer
  prev_error = error;
  */

}
