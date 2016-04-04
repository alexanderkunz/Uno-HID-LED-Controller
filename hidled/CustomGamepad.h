/*
Copyright (c) 2014-2015 NicoHood
See the readme for credit to other people.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

// Include guard
#pragma once

#include <Arduino.h>
#include "PluggableUSB.h"
#include "HID.h"
#include "HID-Settings.h"

typedef union {
	uint8_t buttons;
	struct{
		uint8_t button1 : 1;
		uint8_t button2 : 1;
		uint8_t button3 : 1;
		uint8_t button4 : 1;
		uint8_t button5 : 1;
		uint8_t button6 : 1;
		uint8_t button7 : 1;
		uint8_t button8 : 1;
	};
} HID_CustomGamepadReport_Data_t;

class CustomGamepad_ : public PluggableUSBModule
{
public:

	uint16_t led_data;
	
    CustomGamepad_(void);
	
	void begin(void);
	void end(void);
	void write(void);
	void press(uint8_t b);
	void release(uint8_t b);
	void releaseAll(void);

protected:
    // Implementation of the PUSBListNode
    int getInterface(uint8_t* interfaceCount);
    int getDescriptor(USBSetup& setup);
    bool setup(USBSetup& setup);
    
    uint8_t epType[1];
    uint8_t protocol;
    uint8_t idle;
	
	HID_CustomGamepadReport_Data_t _report;
    
    virtual void SendReport(void* data, int length);
};
extern CustomGamepad_ CustomGamepad;

