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
#include "SoftPWM.h"

byte pin_state[16];
const int fade_enable_pin = 18;
const int fade_speed = 4;

void setup() {

  // setup pins
  pinMode(fade_enable_pin, INPUT_PULLUP);

  // setup PWM
  SoftPWMBegin();

  // setup 16 pins as PWM
  for (int i = 0; i < 16; i++) {
    pin_state[i] = 0;
    if (i % 2)
      SoftPWMSet(i + 2, 128);
    else
      SoftPWMSet(i + 2, 255);
  }
  
  // setup serial
  Serial.begin(115200);
  Serial.setTimeout(500);
}

void loop() {

  // check if fade is enabled
  bool fade_enable = !digitalRead(fade_enable_pin);

  // update fade
  if (fade_enable)
    for (int i = 0; i < 16; i++)
      if (pin_state[i] > fade_speed)
        pin_state[i] -= fade_speed;
      else
        pin_state[i] = 0;
  
  // check serial
  if (Serial.available()) {
    // read two bytes
    uint8_t data[2];
    if (Serial.readBytes(data, 2) < 2)
      for (int n = 0; n < sizeof(data); n++)
        data[n] = 0;
  
    // write data to state
    for (int i = 0; i < 8; i++) {
      if (data[0] & (1 << i))
        pin_state[i + 0] = 255;
      else if (!fade_enable)
        pin_state[i + 0] = 0;
      if (data[1] & (1 << i))
        pin_state[i + 8] = 255;
      else if (!fade_enable)
        pin_state[i + 8] = 0;
    }
  }
  else if (fade_enable)
    delay(1);

  // set PWM state
  for (int i = 0; i < 16; i++) {
    SoftPWMSet(i + 2, pin_state[i]);
  }
}

#endif
