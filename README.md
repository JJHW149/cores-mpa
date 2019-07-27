Fork of the Teensy 2.0, 3.x, LC core libraries for Arduino, adding a new USB "joystick" type representing the MadCatz Midi Pro Adapter. More information: http://progsoc.org/~curious/rock_band/diy_midi_pro_adapter2.html

Note: before you can actually use this in Teensyduino / Arduino, you'll also need to amend boards.txt (which is outside of the cores folder) to add the new USBType, i.e. adding
```
teensy36.menu.usb.mpa=MPA
teensy36.menu.usb.mpa.build.usbtype=USB_MPA
teensy36.menu.usb.mpa.fake_serial=teensy_gateway
```
