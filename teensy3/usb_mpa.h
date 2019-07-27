/*
 * code is derived from PJRC.com's usb_joystick.h
 * this is mostly renamed variables, but I also reformatted
 * it to make it easier for me to read.
 *
 * as a trivial modification of someone else's work, no
 * distinctive intellectual property inheres  -- curious.jp@gmail.com
 *
 * mpas are similar to joysticks, but -
 *		no autosending
 *		they have a lot of fixed bytes in their reports
 */

#ifndef USBmpa_h_
#define USBmpa_h_

#include "usb_desc.h"

#if defined(MPA_INTERFACE)

    #define MPA_HAT_NEUTRAL 0x08
    #define MPA_HAT_UP 0x00
    #define MPA_HAT_DOWN 0x04
    #define MPA_HAT_LEFT 0x06
    #define MPA_HAT_RIGHT 0x02
	
	#include <inttypes.h>
	
	// C language implementation
#ifdef __cplusplus
extern "C" {
#endif

	void usb_mpa_set_hat( uint8_t hat_position );
	void usb_mpa_set_button( int button );
	void usb_mpa_reset_packet( void );
	int  usb_mpa_send( void );
	extern uint8_t usb_mpa_data[ MPA_PACK_SIZE ];

#ifdef __cplusplus
}
#endif

#endif // MPA_INTERFACE
#endif // USBmpa_h_

