// usb_rbgtr.c
#include "usb_dev.h"
#include "usb_rbgtr.h"
#include "core_pins.h" // for yield()
#include "HardwareSerial.h"
#include <string.h> // for memcpy()

#ifdef USB_RBGTR // defined by usb_dev.h -> usb_desc.h

/*
uint8_t usb_rbgtr_data[6];

// Maximum number of transmit packets to queue so we don't starve other endpoints for memory
#define TX_PACKET_LIMIT 3

static uint8_t transmit_previous_timeout=0;

// When the PC isn't listening, how long do we wait before discarding data?
#define TX_TIMEOUT_MSEC 30

#if F_CPU == 96000000
  #define TX_TIMEOUT (TX_TIMEOUT_MSEC * 596)
#elif F_CPU == 48000000
  #define TX_TIMEOUT (TX_TIMEOUT_MSEC * 428)
#elif F_CPU == 24000000
  #define TX_TIMEOUT (TX_TIMEOUT_MSEC * 262)
#endif

int usb_rbgtr_send(void)
{
    uint32_t wait_count=0;
    usb_packet_t *tx_packet;

    while (1) {
        if (!usb_configuration) {
            return -1;
        }
        if (usb_tx_packet_count(RBGTR_ENDPOINT) < TX_PACKET_LIMIT) {           tx_packet = usb_malloc();           if (tx_packet) break;       }       if (++wait_count > TX_TIMEOUT || transmit_previous_timeout) {
                                                                        transmit_previous_timeout = 1;
                                                                        return -1;
        }
        yield();
    }

    transmit_previous_timeout = 0;
    memcpy(tx_packet->buf, usb_rbgtr_data, 6);
    tx_packet->len = 6;
    usb_tx(RBGTR_ENDPOINT, tx_packet);

    return 0;


}
*/

#if F_CPU >= 20000000
    
    uint8_t usb_rbgtr_data[ RBGTR_PACK_SIZE ] = { 0x00, 0x00, // button states
                                              0x08, // hat state
                                              0x80, 0x80, 0x80, 0x80,
                                              0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                              0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x02 };


    // Maximum number of transmit packets to queue so we don't starve other endpoints for memory
    #define TX_PACKET_LIMIT 3
    static uint8_t transmit_previous_timeout=0;

    // When the PC isn't listening, how long do we wait before discarding data?
    #define TX_TIMEOUT_MSEC 30

    #if F_CPU == 256000000
      #define TX_TIMEOUT (TX_TIMEOUT_MSEC * 1706)
    #elif F_CPU == 240000000
      #define TX_TIMEOUT (TX_TIMEOUT_MSEC * 1600)
    #elif F_CPU == 216000000
      #define TX_TIMEOUT (TX_TIMEOUT_MSEC * 1440)
    #elif F_CPU == 192000000
      #define TX_TIMEOUT (TX_TIMEOUT_MSEC * 1280)
    #elif F_CPU == 180000000
      #define TX_TIMEOUT (TX_TIMEOUT_MSEC * 1200)
    #elif F_CPU == 168000000
      #define TX_TIMEOUT (TX_TIMEOUT_MSEC * 1100)
    #elif F_CPU == 144000000
      #define TX_TIMEOUT (TX_TIMEOUT_MSEC * 932)
    #elif F_CPU == 120000000
      #define TX_TIMEOUT (TX_TIMEOUT_MSEC * 764)
    #elif F_CPU == 96000000
      #define TX_TIMEOUT (TX_TIMEOUT_MSEC * 596)
    #elif F_CPU == 72000000
      #define TX_TIMEOUT (TX_TIMEOUT_MSEC * 512)
    #elif F_CPU == 48000000
      #define TX_TIMEOUT (TX_TIMEOUT_MSEC * 428)
    #elif F_CPU == 24000000
      #define TX_TIMEOUT (TX_TIMEOUT_MSEC * 262)
    #endif

    void usb_rbgtr_set_hat( uint8_t hat_position ) {
      usb_rbgtr_data[ 2 ] = hat_position;
    }

    void usb_rbgtr_set_button( int button ) {
      if( button < 8 ) {
        usb_rbgtr_data[ 0 ] |= 1 << button;
      }
      else {
        usb_rbgtr_data[ 1 ] |= 1 << ( button - 8 );
      }
    }

    void usb_rbgtr_reset_packet( void ) {
      usb_rbgtr_data[ 0 ] = 0x00;
      usb_rbgtr_data[ 1 ] = 0x00;
      usb_rbgtr_data[ 2 ] = RBGTR_HAT_NEUTRAL;
    }

    int usb_rbgtr_send(void) {
      uint32_t wait_count=0;
      usb_packet_t *tx_packet;
      while (1) {
        if (!usb_configuration) {
          return -1;
        }
        if (usb_tx_packet_count(RBGTR_ENDPOINT) < TX_PACKET_LIMIT) {
          tx_packet = usb_malloc();
          if (tx_packet) break;
        }
        if (++wait_count > TX_TIMEOUT || transmit_previous_timeout) {
          transmit_previous_timeout = 1;
          return -2;
        }
      yield();
      }
      transmit_previous_timeout = 0;
      memcpy( tx_packet->buf, usb_rbgtr_data, RBGTR_PACK_SIZE);
      tx_packet->len = RBGTR_PACK_SIZE;
      usb_tx( RBGTR_ENDPOINT, tx_packet );
	    return 0;
    }

  #endif // F_CPU

#endif // USB_RBGTR