Fork of the Teensy 2.0, 3.x, LC core libraries for Arduino.

Note - you will also need to modify boards.txt (outside of the cores folder) to use the new USBType defined by this patch, add 

+teensy36.menu.usb.mpa=MPA
+teensy36.menu.usb.mpa.build.usbtype=USB_MPA
+teensy36.menu.usb.mpa.fake_serial=teensy_gateway

More information: http://progsoc.org/~curious/rock_band/diy_midi_pro_adapter2.html
