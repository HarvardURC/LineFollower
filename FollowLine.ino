#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_TSL2561_U.h>

Adafruit_TSL2561_Unified tsl = Adafruit_TSL2561_Unified(TSL2561_ADDR_FLOAT, 12345);
sensors_event_t on;
sensors_event_t off;
int LED_PIN = 20;
int THRESHOLD = 30;

int leftWheelB = 22;
int leftWheelA = 23;
int rightWheelB = 9;
int rightWheelA = 10;

void configureSensor(void)
{
  /* You can also manually set the gain or enable auto-gain support */
  // tsl.setGain(TSL2561_GAIN_1X);      /* No gain ... use in bright light to avoid sensor saturation */
  // tsl.setGain(TSL2561_GAIN_16X);     /* 16x gain ... use in low light to boost sensitivity */
  tsl.enableAutoRange(true);          /* Auto-gain ... switches automatically between 1x and 16x */
  
  /* Changing the integration time gives you better sensor resolution (402ms = 16-bit data) */
  tsl.setIntegrationTime(TSL2561_INTEGRATIONTIME_13MS);      /* fast but low resolution */
  // tsl.setIntegrationTime(TSL2561_INTEGRATIONTIME_101MS);  /* medium resolution and speed   */
  // tsl.setIntegrationTime(TSL2561_INTEGRATIONTIME_402MS);  /* 16-bit data but slowest conversions */
 
  /* Update these values depending on what you've set above! */  
  Serial.println("------------------------------------");
  Serial.print  ("Gain:         "); Serial.println("Auto");
  Serial.print  ("Timing:       "); Serial.println("13 ms");
  Serial.println("------------------------------------");
}

void setup() {
  // pin configuration
  Serial.begin(9600);
  pinMode(leftWheelB, OUTPUT);
  pinMode(leftWheelA, OUTPUT);
  pinMode(rightWheelB, OUTPUT);
  pinMode(rightWheelA, OUTPUT);
  configureSensor();
  pinMode(LED_PIN,OUTPUT);
 
  /* PID variables
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
  } else if (left < 0) {
    analogWrite(leftWheelB, -1*left);
    analogWrite(leftWheelA, 0);
  } else {
    analogWrite(leftWheelA, 0);
    analogWrite(leftWheelB, 0);
  }
  if(right > 0) {
    analogWrite(rightWheelB, right);
    analogWrite(rightWheelA, 0);
  } else if (right < 0) {
    analogWrite(rightWheelA, -1*right);
    analogWrite(rightWheelB, 0);
  } else {
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
  // acquire sensor readings
  digitalWrite(LED_PIN,HIGH);
  tsl.getEvent(&on);
  digitalWrite(LED_PIN,LOW);
  tsl.getEvent(&off);
  
  // Display the results (light is measured in lux)
  Serial.print(on.light-off.light);
  
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
  
  if(on.light-off.light > THRESHOLD) {
    Serial.println("left");
    setDriveSpeed(0,100);
  } else {
    Serial.println("right");
    setDriveSpeed(100,0);
  }
}
