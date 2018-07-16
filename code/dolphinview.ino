/*
Example code for Benewake TFMini time-of-flight distance sensor. 
by Peter Jansen (December 11/2017)
 * Uno RX is digital pin 10 (connect to TX of TF Mini)
 * Uno TX is digital pin 11 (connect to RX of TF Mini)
*/

#include <SoftwareSerial.h>
#include <TFMini.h>

// Setup software serial port 
SoftwareSerial mySerial(10, 11);      // Uno RX (TFMINI TX), Uno TX (TFMINI RX)
TFMini tfmini;

void setup() {
  // Step 1: Initialize hardware serial port (serial debug port)
  Serial.begin(115200);
  // wait for serial port to connect. Needed for native USB port only
  while (!Serial);
     
  Serial.println ("Initializing...");

  // Step 2: Initialize the data rate for the SoftwareSerial port
  mySerial.begin(TFMINI_BAUDRATE);

  // Step 3: Initialize the TF Mini sensor
  tfmini.begin(&mySerial);    
}


void loop() {
  // Take one TF Mini distance measurement
  uint16_t dist = tfmini.getDistance();
  uint16_t strength = tfmini.getRecentSignalStrength();
  int scale = dist*1.3;   
  
  tone(3, 25, 30);

  delay(scale); 

}
