/*

RISD CTC/DM-2001
Programming Sound: Performance Systems
Prof. Shawn Greenlee

Teensy LC starter code

  For Teensy LC basic serial communition to Pure Data
  Code adapted from Alexandros Drymonits, Yann Seznec, and PJRC: public domain

*/

#include <Wire.h>
//Click here to get the library: http://librarymanager/All#SparkFun_VCNL4040
#include "SparkFun_VCNL4040_Arduino_Library.h"
VCNL4040 proximitySensor;

// analog values array size, must be constant
const int num_of_analog_pins = 4; // total numer of analog pins
int analog_values[num_of_analog_pins];
int analog_pins[] = {
  17,16,15,14// list each analog pin to use
};

// digital_values array size, must be constant
const int num_of_digital_pins = 3; // total numer of digital pins
int digital_values[num_of_digital_pins];
int digital_pins [] = {
  9, 10, 11 // list each digital pin to use
};


void setup() {

 // analogReadResolution(12); // Teensy is 12bit ADC, you can set to 12 but this will introduce some noise, also you can set lower like 7bit for MIDI range
  analogReadAveraging(32); // Teensy can do averaging of samples in hardware, set to 4, 8, 16, 32

  //  pinMode(0, INPUT_PULLUP);  // set pin modes individually
  //  pinMode(15, INPUT_PULLUP);
  //  pinMode(16, INPUT_PULLUP);
  //  pinMode(17, INPUT_PULLUP);
  //  pinMode(23, INPUT_PULLUP);
  //  pinMode(5, INPUT_PULLUP);
  //  pinMode(6, INPUT_PULLUP);
  //  pinMode(7, INPUT_PULLUP);
  //  pinMode(8, INPUT_PULLUP);
    pinMode(9, INPUT_PULLUP);
    pinMode(10, INPUT_PULLUP);
    pinMode(11, INPUT_PULLUP);
  //  pinMode(12, INPUT_PULLUP);
  //  pinMode(13, INPUT_PULLUP);

  Serial.begin(9600);

  Wire.begin(); //Join i2c bus

  proximitySensor.begin(); //Initialize the sensor

  //Turn on everything
  proximitySensor.powerOnProximity();
  proximitySensor.powerOnAmbient();
  proximitySensor.enableWhiteChannel();
}

void loop() {
  for (int i = 0; i < num_of_analog_pins; i++) analog_values[i] = analogRead(analog_pins[i]);
  for (int i = 0; i < num_of_digital_pins; i++) digital_values[i] = !digitalRead(digital_pins[i]);


  Serial.print("analog_values: ");
  for (int i = 0; i < (num_of_analog_pins); i++) {
    Serial.print(analog_values[i]);
    Serial.print(" ");
  }
  Serial.println(" ");


  Serial.print("digital_values: ");
  for (int i = 0; i < (num_of_digital_pins); i++) {
    Serial.print(digital_values[i]);
    Serial.print(" ");
  }
  Serial.println(" ");

    unsigned int proxValue = proximitySensor.getProximity();
  Serial.print("proximity: ");
  Serial.print(proxValue);
  Serial.print(" ");
  Serial.println(" ");
  
  unsigned int ambientValue = proximitySensor.getAmbient(); 
  Serial.print("ambientlight: ");
  Serial.print(ambientValue);
  Serial.print(" ");
  Serial.println(" ");

  unsigned int whiteValue = proximitySensor.getWhite(); 
  Serial.print("whitelight: ");
  Serial.print(whiteValue);
  Serial.print(" ");
  Serial.println(" ");

  delay(10);
}
