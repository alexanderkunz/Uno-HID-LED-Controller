# USB HID LED Controller for Arduino Uno

This Project aims to provide an USB HID device for use of specific tools of several japanese music games.
It supports the control of 16 LEDs over the standard HID driver.

**Requirements**
* Arduino Uno
* [HoodLoader2 (2.0.5)](https://github.com/NicoHood/HoodLoader2)
* [HID-Project (2.4.3)](https://github.com/NicoHood/HID)

To make it work, you have to compile and upload the sketch twice for the Uno and the 16u2 microcontroller.
The LEDs are mapped from pin 2 to pin 18.
