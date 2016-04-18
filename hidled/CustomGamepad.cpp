/*

CustomGamepad for HID LED Control.
Used SingleReport Gamepad of the HID-Project as template.


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

#if !defined(__AVR_ATmega328P__)
#include "CustomGamepad.h"

static const uint8_t _hidReportDescriptorGamepad[] PROGMEM = {
	/* Gamepad with 32 buttons and 6 axis*/
	0x05, 0x01,							/* USAGE_PAGE (Generic Desktop) */
	0x09, 0x05,							/* USAGE (Game Pad) */
	0xa1, 0x01,							/* COLLECTION (Application) */
	
	/* 8 Buttons */
    0x85, 0x04,				 	   /*   REPORT_ID */ //REPORT 4
	0x05, 0x09,							/*   USAGE_PAGE (Button) */
	0x19, 0x01,							/*   USAGE_MINIMUM (Button 1) */
	0x29, 0x08,							/*   USAGE_MAXIMUM (Button 8) */
	0x15, 0x00,							/*   LOGICAL_MINIMUM (0) */
	0x25, 0x01,							/*   LOGICAL_MAXIMUM (1) */
	0x95, 0x08,							/*   REPORT_COUNT (8) */
	0x75, 0x01,							/*   REPORT_SIZE (1) */
	0x81, 0x02,							/*   INPUT (Data,Var,Abs) */
	
	/*Lights config*/
    0x85, 0x05,				 /*   REPORT_ID set to 5*/ 
    0x15, 0x00,                    /*     LOGICAL_MINIMUM (0) */ 
    0x25, 0x01,                    /*     LOGICAL_MAXIMUM (1) */ 
	
    /*Led 1 */ 
    0x05, 0x0a,                    /*     USAGE_PAGE (Ordinals) */ 
    0x09, 0x01,                    /*     USAGE (Instance 1) */ 
    0xa1, 0x02,                    /*     COLLECTION (Logical) */ 
    0x05, 0x08,                    /*       USAGE_PAGE (LEDs) */ 
    0x09, 0x4b,                    /*       USAGE (Generic Indicator 1) */ 
    0x75, 0x01,                    /*       REPORT_SIZE (1) */ 
    0x95, 0x01,                    /*       REPORT_COUNT (1) */ 
    0x91, 0x02,                    /*       OUTPUT (Data,Var,Abs) */ 
    0xc0,                          /*     END_COLLECTION */ 
    /*Led 2 */ 
    0x05, 0x0a,                    /*     USAGE_PAGE (Ordinals) */ 
    0x09, 0x02,                    /*     USAGE (Instance 2) */ 
    0xa1, 0x02,                    /*     COLLECTION (Logical) */ 
    0x05, 0x08,                    /*       USAGE_PAGE (LEDs) */ 
    0x09, 0x4b,                    /*       USAGE (Generic Indicator 1) */ 
    0x75, 0x01,                    /*       REPORT_SIZE (1) */ 
    0x95, 0x01,                    /*       REPORT_COUNT (1) */ 
    0x91, 0x02,                    /*       OUTPUT (Data,Var,Abs) */ 
    0xc0,                          /*     END_COLLECTION */ 
    /*Led 3 */ 
    0x05, 0x0a,                    /*     USAGE_PAGE (Ordinals) */ 
    0x09, 0x03,                    /*     USAGE (Instance 3) */ 
    0xa1, 0x02,                    /*     COLLECTION (Logical) */ 
    0x05, 0x08,                    /*       USAGE_PAGE (LEDs) */ 
    0x09, 0x4b,                    /*       USAGE (Generic Indicator 1) */ 
    0x75, 0x01,                    /*       REPORT_SIZE (1) */ 
    0x95, 0x01,                    /*       REPORT_COUNT (1) */ 
    0x91, 0x02,                    /*       OUTPUT (Data,Var,Abs) */ 
    0xc0,                          /*     END_COLLECTION */ 
    /*Led 4 */ 
    0x05, 0x0a,                    /*     USAGE_PAGE (Ordinals) */ 
    0x09, 0x04,                    /*     USAGE (Instance 4) */ 
    0xa1, 0x02,                    /*     COLLECTION (Logical) */ 
    0x05, 0x08,                    /*       USAGE_PAGE (LEDs) */ 
    0x09, 0x4b,                    /*       USAGE (Generic Indicator 1) */ 
    0x75, 0x01,                    /*       REPORT_SIZE (1) */ 
    0x95, 0x01,                    /*       REPORT_COUNT (1) */ 
    0x91, 0x02,                    /*       OUTPUT (Data,Var,Abs) */ 
    0xc0,                          /*     END_COLLECTION */ 
    /*Led 5 */ 
    0x05, 0x0a,                    /*     USAGE_PAGE (Ordinals) */ 
    0x09, 0x05,                    /*     USAGE (Instance 5) */ 
    0xa1, 0x02,                    /*     COLLECTION (Logical) */ 
    0x05, 0x08,                    /*       USAGE_PAGE (LEDs) */ 
    0x09, 0x4b,                    /*       USAGE (Generic Indicator 1) */ 
    0x75, 0x01,                    /*       REPORT_SIZE (1) */ 
    0x95, 0x01,                    /*       REPORT_COUNT (1) */ 
    0x91, 0x02,                    /*       OUTPUT (Data,Var,Abs) */ 
    0xc0,                          /*     END_COLLECTION */ 
    /*Led 6 */ 
    0x05, 0x0a,                    /*     USAGE_PAGE (Ordinals) */ 
    0x09, 0x06,                    /*     USAGE (Instance 6) */ 
    0xa1, 0x02,                    /*     COLLECTION (Logical) */ 
    0x05, 0x08,                    /*       USAGE_PAGE (LEDs) */ 
    0x09, 0x4b,                    /*       USAGE (Generic Indicator 1) */ 
    0x75, 0x01,                    /*       REPORT_SIZE (1) */ 
    0x95, 0x01,                    /*       REPORT_COUNT (1) */ 
    0x91, 0x02,                    /*       OUTPUT (Data,Var,Abs) */ 
    0xc0,                          /*     END_COLLECTION */ 
    /*Led 7 */ 
    0x05, 0x0a,                    /*     USAGE_PAGE (Ordinals) */ 
    0x09, 0x07,                    /*     USAGE (Instance 7) */ 
    0xa1, 0x02,                    /*     COLLECTION (Logical) */ 
    0x05, 0x08,                    /*       USAGE_PAGE (LEDs) */ 
    0x09, 0x4b,                    /*       USAGE (Generic Indicator 1) */ 
    0x75, 0x01,                    /*       REPORT_SIZE (1) */ 
    0x95, 0x01,                    /*       REPORT_COUNT (1) */ 
    0x91, 0x02,                    /*       OUTPUT (Data,Var,Abs) */ 
    0xc0,                          /*     END_COLLECTION */ 
    /*Led 8 */ 
    0x05, 0x0a,                    /*     USAGE_PAGE (Ordinals) */ 
    0x09, 0x08,                    /*     USAGE (Instance 8) */ 
    0xa1, 0x02,                    /*     COLLECTION (Logical) */ 
    0x05, 0x08,                    /*       USAGE_PAGE (LEDs) */ 
    0x09, 0x4b,                    /*       USAGE (Generic Indicator 1) */ 
    0x75, 0x01,                    /*       REPORT_SIZE (1) */ 
    0x95, 0x01,                    /*       REPORT_COUNT (1) */ 
    0x91, 0x02,                    /*       OUTPUT (Data,Var,Abs) */ 
    0xc0,                          /*     END_COLLECTION */ 
    /*Led 9 */ 
    0x05, 0x0a,                    /*     USAGE_PAGE (Ordinals) */ 
    0x09, 0x09,                    /*     USAGE (Instance 9) */ 
    0xa1, 0x02,                    /*     COLLECTION (Logical) */ 
    0x05, 0x08,                    /*       USAGE_PAGE (LEDs) */ 
    0x09, 0x4b,                    /*       USAGE (Generic Indicator 1) */ 
    0x75, 0x01,                    /*       REPORT_SIZE (1) */ 
    0x95, 0x01,                    /*       REPORT_COUNT (1) */ 
    0x91, 0x02,                    /*       OUTPUT (Data,Var,Abs) */ 
    0xc0,                          /*     END_COLLECTION */ 
    /*Led 10 */ 
    0x05, 0x0a,                    /*     USAGE_PAGE (Ordinals) */ 
    0x09, 0x0a,                    /*     USAGE (Instance 10) */ 
    0xa1, 0x02,                    /*     COLLECTION (Logical) */ 
    0x05, 0x08,                    /*       USAGE_PAGE (LEDs) */ 
    0x09, 0x4b,                    /*       USAGE (Generic Indicator 1) */ 
    0x75, 0x01,                    /*       REPORT_SIZE (1) */ 
    0x95, 0x01,                    /*       REPORT_COUNT (1) */ 
    0x91, 0x02,                    /*       OUTPUT (Data,Var,Abs) */ 
    0xc0,                          /*     END_COLLECTION */ 
    /*Led 11 */ 
    0x05, 0x0a,                    /*     USAGE_PAGE (Ordinals) */ 
    0x09, 0x0b,                    /*     USAGE (Instance 11) */ 
    0xa1, 0x02,                    /*     COLLECTION (Logical) */ 
    0x05, 0x08,                    /*       USAGE_PAGE (LEDs) */ 
    0x09, 0x4b,                    /*       USAGE (Generic Indicator 1) */ 
    0x75, 0x01,                    /*       REPORT_SIZE (1) */ 
    0x95, 0x01,                    /*       REPORT_COUNT (1) */ 
    0x91, 0x02,                    /*       OUTPUT (Data,Var,Abs) */ 
    0xc0,                          /*     END_COLLECTION */ 
    /*Led 12 */ 
    0x05, 0x0a,                    /*     USAGE_PAGE (Ordinals) */ 
    0x09, 0x0c,                    /*     USAGE (Instance 12) */ 
    0xa1, 0x02,                    /*     COLLECTION (Logical) */ 
    0x05, 0x08,                    /*       USAGE_PAGE (LEDs) */ 
    0x09, 0x4b,                    /*       USAGE (Generic Indicator 1) */ 
    0x75, 0x01,                    /*       REPORT_SIZE (1) */ 
    0x95, 0x01,                    /*       REPORT_COUNT (1) */ 
    0x91, 0x02,                    /*       OUTPUT (Data,Var,Abs) */ 
    0xc0,                          /*     END_COLLECTION */ 
    /*Led 13 */ 
    0x05, 0x0a,                    /*     USAGE_PAGE (Ordinals) */ 
    0x09, 0x0d,                    /*     USAGE (Instance 13) */ 
    0xa1, 0x02,                    /*     COLLECTION (Logical) */ 
    0x05, 0x08,                    /*       USAGE_PAGE (LEDs) */ 
    0x09, 0x4b,                    /*       USAGE (Generic Indicator 1) */ 
    0x75, 0x01,                    /*       REPORT_SIZE (1) */ 
    0x95, 0x01,                    /*       REPORT_COUNT (1) */ 
    0x91, 0x02,                    /*       OUTPUT (Data,Var,Abs) */ 
    0xc0,                          /*     END_COLLECTION */ 
    /*Led 14 */ 
    0x05, 0x0a,                    /*     USAGE_PAGE (Ordinals) */ 
    0x09, 0x0e,                    /*     USAGE (Instance 14) */ 
    0xa1, 0x02,                    /*     COLLECTION (Logical) */ 
    0x05, 0x08,                    /*       USAGE_PAGE (LEDs) */ 
    0x09, 0x4b,                    /*       USAGE (Generic Indicator 1) */ 
    0x75, 0x01,                    /*       REPORT_SIZE (1) */ 
    0x95, 0x01,                    /*       REPORT_COUNT (1) */ 
    0x91, 0x02,                    /*       OUTPUT (Data,Var,Abs) */ 
    0xc0,                          /*     END_COLLECTION */ 
    /*Led 15 */ 
    0x05, 0x0a,                    /*     USAGE_PAGE (Ordinals) */ 
    0x09, 0x0f,                    /*     USAGE (Instance 15) */ 
    0xa1, 0x02,                    /*     COLLECTION (Logical) */ 
    0x05, 0x08,                    /*       USAGE_PAGE (LEDs) */ 
    0x09, 0x4b,                    /*       USAGE (Generic Indicator 1) */ 
    0x75, 0x01,                    /*       REPORT_SIZE (1) */ 
    0x95, 0x01,                    /*       REPORT_COUNT (1) */ 
    0x91, 0x02,                    /*       OUTPUT (Data,Var,Abs) */ 
    0xc0,                          /*     END_COLLECTION */ 
    /*Led 16 */ 
    0x05, 0x0a,                    /*     USAGE_PAGE (Ordinals) */ 
    0x09, 0x10,                    /*     USAGE (Instance 16) */ 
    0xa1, 0x02,                    /*     COLLECTION (Logical) */ 
    0x05, 0x08,                    /*       USAGE_PAGE (LEDs) */ 
    0x09, 0x4b,                    /*       USAGE (Generic Indicator 1) */ 
    0x75, 0x01,                    /*       REPORT_SIZE (1) */ 
    0x95, 0x01,                    /*       REPORT_COUNT (1) */ 
    0x91, 0x02,                    /*       OUTPUT (Data,Var,Abs) */ 
    0xc0,                          /*     END_COLLECTION */
	
	0xc0								/* END_COLLECTION */
};

CustomGamepad_::CustomGamepad_(void) : PluggableUSBModule(1, 1, epType), protocol(HID_REPORT_PROTOCOL), idle(1)
{
	epType[0] = EP_TYPE_INTERRUPT_IN;
	PluggableUSB().plug(this);
}

int CustomGamepad_::getInterface(uint8_t* interfaceCount)
{
	*interfaceCount += 1; // uses 1
	HIDDescriptor hidInterface = {
		D_INTERFACE(pluggedInterface, 1, USB_DEVICE_CLASS_HUMAN_INTERFACE, HID_SUBCLASS_NONE, HID_PROTOCOL_NONE),
		D_HIDREPORT(sizeof(_hidReportDescriptorGamepad)),
		D_ENDPOINT(USB_ENDPOINT_IN(pluggedEndpoint), USB_ENDPOINT_TYPE_INTERRUPT, USB_EP_SIZE, 0x01)
	};
	return USB_SendControl(0, &hidInterface, sizeof(hidInterface));
}

int CustomGamepad_::getDescriptor(USBSetup& setup)
{
	// Check if this is a HID Class Descriptor request
	if (setup.bmRequestType != REQUEST_DEVICETOHOST_STANDARD_INTERFACE) { return 0; }
	if (setup.wValueH != HID_REPORT_DESCRIPTOR_TYPE) { return 0; }

	// In a HID Class Descriptor wIndex cointains the interface number
	if (setup.wIndex != pluggedInterface) { return 0; }

	// Reset the protocol on reenumeration. Normally the host should not assume the state of the protocol
	// due to the USB specs, but Windows and Linux just assumes its in report mode.
	protocol = HID_REPORT_PROTOCOL;

	return USB_SendControl(TRANSFER_PGM, _hidReportDescriptorGamepad, sizeof(_hidReportDescriptorGamepad));
}

bool CustomGamepad_::setup(USBSetup& setup)
{
	if (pluggedInterface != setup.wIndex) {
		return false;
	}

	uint8_t request = setup.bRequest;
	uint8_t requestType = setup.bmRequestType;

	if (requestType == REQUEST_DEVICETOHOST_CLASS_INTERFACE)
	{
		if (request == HID_GET_REPORT) {
			// TODO: HID_GetReport();
			return true;
		}
		if (request == HID_GET_PROTOCOL) {
			// TODO: Send8(protocol);
			return true;
		}
		if (request == HID_GET_IDLE) {
			// TODO: Send8(idle);
		}
	}

	if (requestType == REQUEST_HOSTTODEVICE_CLASS_INTERFACE)
	{
		if (request == HID_SET_PROTOCOL) {
			protocol = setup.wValueL;
			return true;
		}
		if (request == HID_SET_IDLE) {
			idle = setup.wValueL;
			return true;
		}
		if (request == HID_SET_REPORT)
		{
			uint8_t reportID = setup.wValueL;
			uint16_t length = setup.wLength;
			uint8_t data[length];
			
			// read LED data
			// first byte may contains the reportID on a multreport
			if (setup.wLength == 3) {
				uint8_t data[3];
				if (USB_RecvControl(data, sizeof(data)) == sizeof(data)) {
					led_data = (uint16_t)(data[2] << 8) + data[1];
				}
				return true;
			}
		}
	}

	return false;
}

bool CustomGamepad_::SendReport(void* data, int length){
	return USB_Send(pluggedEndpoint | TRANSFER_RELEASE, data, length) > 0;
}

void CustomGamepad_::begin(void){
	end();
}

void CustomGamepad_::end(void){
	memset(&_report, 0x00, sizeof(_report));
	SendReport(&_report, sizeof(_report));
}

bool CustomGamepad_::write(void){ 
	return SendReport(&_report, sizeof(_report)); 
}

CustomGamepad_ CustomGamepad;


#endif