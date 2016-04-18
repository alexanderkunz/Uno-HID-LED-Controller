// USB HID LED Controller
// For Arduino Uno (HoodLoader2, 2.0.5)
// Must have HID-Project 2.4.3 installed
// Compile and upload twice for 16u2 and Uno


// CODE FOR 16u2
/////////////////////////////////////////////
#if !defined(__AVR_ATmega328P__)
#include "HID-Project.h"
#include "CustomGamepad.h"

void setup() {
  
  // setup gamepad
  CustomGamepad.begin();

  // setup serial
  Serial1.begin(115200);
  delay(500);
}

void loop() {
  
  // send report
  if (!CustomGamepad.write())
    CustomGamepad.led_data = 0;
  
  // Number of microseconds between HID reports
  // 2000 = 500hz
  delayMicroseconds(2000);

  // send serial data
  Serial1.write((uint8_t*)(&CustomGamepad.led_data), 2);
  Serial1.flush();
}

#endif


// CODE FOR UNO
/////////////////////////////////////////////
#if defined(__AVR_ATmega328P__)

void setup() {

  // setup 16 pins as output
  for (int i = 2; i < 18; i++) {
    pinMode(i, OUTPUT);
    if (i % 2)
      digitalWrite(i, LOW);
    else
      digitalWrite(i, HIGH);
  }
  
  // setup serial
  Serial.begin(115200);
  Serial.setTimeout(500);
  delay(500);
}

void loop() {
  
  // read two bytes
  uint8_t data[2];
  if (Serial.readBytes(data, 2) < 2)
    for (int n = 0; n < sizeof(data); n++)
      data[n] = 0;

  // output all bits
  for (int i = 0; i < 8; i++) {
    if (data[1] & (1 << i))
      digitalWrite(2 + i, HIGH);
    else
      digitalWrite(2 + i, LOW);
    if (data[0] & (1 << i))
      digitalWrite(10 + i, HIGH);
    else
      digitalWrite(10 + i, LOW);
  }
}

#endif
