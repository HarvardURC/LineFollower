/* Assumes you've wired up your line follower according to the available wiring
 * diagram. Requires installation of QTRSensor Library as per
 * https://www.pololu.com/docs/0J19/2)
 *
 * Outputs to the Serial Monitor (go to Tools>Serial Monitor) what each
 * sensor on the QTR sensor array is reading. Lower values ~= darker, higher
 * values ~= lighter.
 */

#include <QTRSensors.h>                 // The sensor library

#define NUM_SENSORS             3       // Reflectance sensor has 3 individual sensors
#define NUM_SAMPLES_PER_SENSOR  4       // Averge 4 analog samples per sensor reading


// Object for three QTR-xA sensors on analog inputs 14, 15, and 16.
QTRSensorsAnalog qtra((unsigned char[]) {14, 15, 16},
                      NUM_SENSORS, NUM_SAMPLES_PER_SENSOR);

unsigned int sensorValues[NUM_SENSORS]; // For storing sensor readings

void setup() {
  // Serial debug start
  Serial.begin(9600);
}


void loop() {
  // Get sensor readings
  qtra.read(sensorValues);

  // Iterate over all sensors and print their reading followed by a tab
  for (unsigned char i = 0; i < NUM_SENSORS; i++) {
    Serial.print(sensorValues[i]);
    Serial.print("\t");
  }

  Serial.println();

  // Wait 250 ms per loop (don't flood serial monitor)
  delay(250);
}
