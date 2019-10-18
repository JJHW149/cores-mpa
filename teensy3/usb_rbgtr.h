// usb_rbgtr.h
#ifndef USB_RBGTR_H
#define USB_RBGTR_H

#if defined(USB_RBGTR)

#include "usb_desc.h"

#if defined(RBGTR_INTERFACE)

    #define RBGTR_HAT_NEUTRAL 0x08
    #define RBGTR_HAT_UP 0x00
    #define RBGTR_HAT_DOWN 0x04
    #define RBGTR_HAT_LEFT 0x06
    #define RBGTR_HAT_RIGHT 0x02
	
	#include <inttypes.h>
	
	// C language implementation
#ifdef __cplusplus
extern "C" {
#endif

	void usb_rbgtr_set_hat( uint8_t hat_position );
	void usb_rbgtr_set_button( int button );
	void usb_rbgtr_reset_packet( void );
	int  usb_rbgtr_send( void );
	extern uint8_t usb_rbgtr_data[ RBGTR_PACK_SIZE ];

#ifdef __cplusplus
}
#endif



/*#include <inttypes.h>

// C language implementation
#ifdef __cplusplus
extern "C" {
#endif
int usb_rbgtr_send(void);
// we have packets that are 6 bytes long
extern uint8_t usb_rbgtr_data[6];
#ifdef __cplusplus
}
#endif

// C++ interface
#ifdef __cplusplus
class usb_rbgtr_class
{
private:
    static uint8_t auto_send;

public:
    void button(uint8_t button, bool val) {
        if (--button >= 16) return;
        if (val) usb_rbgtr_data[button >= 8 ? 5 : 4] |= (1 << (button >= 8 ? (button - 8) : button));
        else usb_rbgtr_data[button >= 8 ? 5 : 4] &= ~(1 << (button >= 8 ? (button - 8) : button));
        if(auto_send) usb_rbgtr_send();
    }

    void axis(uint8_t axis, int8_t val) {
        if(axis >= 4) return;
        if(val > 0) usb_rbgtr_data[axis] = 127;
        else if(val < 0) usb_rbgtr_data[axis] = -127;
        else usb_rbgtr_data[axis] = 0;
        if(auto_send) usb_rbgtr_send();
    }

    void X(unsigned int val) {
		if (val > 1023) val = 1023;
		usb_rbgtr_data[1] = (usb_rbgtr_data[1] & 0xFFFFC00F) | (val << 4);
		if (auto_send) usb_rbgtr_send();
	}

	void Y(unsigned int val) {
		if (val > 1023) val = 1023;
		usb_rbgtr_data[1] = (usb_rbgtr_data[1] & 0xFF003FFF) | (val << 14);
		if (auto_send) usb_rbgtr_send();
	}

    void Z(unsigned int val) {
		if (val > 1023) val = 1023;
		usb_rbgtr_data[1] = (usb_rbgtr_data[1] & 0x00FFFFFF) | (val << 24);
		usb_rbgtr_data[2] = (usb_rbgtr_data[2] & 0xFFFFFFFC) | (val >> 8);
		if (auto_send) usb_rbgtr_send();
	}

    inline void hat(int dir) {
            uint32_t val = 0;
            if (dir < 0) val = 15;
            else if (dir < 23) val = 0;
            else if (dir < 68) val = 1;
            else if (dir < 113) val = 2;
            else if (dir < 158) val = 3;
            else if (dir < 203) val = 4;
            else if (dir < 245) val = 5;
            else if (dir < 293) val = 6;
            else if (dir < 338) val = 7;
	usb_rbgtr_data[1] = (usb_rbgtr_data[1] & 0xFFFFFFF0) | val;
            if (auto_send) usb_rbgtr_send();
    }

    void setAutoSend(bool send) {
        auto_send = send;
    }

    void send() {
        usb_rbgtr_send();
    }
};
extern usb_rbgtr_class RBGTR;

#endif // __cplusplus  */
#endif // USB_RBGTR
#endif // USB_RBGTR_H
#endif
