#!/bin/bash

if [ "${PATH%%arduino}" == "$PATH" ]; then
    export PATH="/opt/arduino-1.8.6/hardware/tools/avr/bin:$PATH"
fi

export AVRDUDE_CONF="-C/opt/arduino-1.8.6/hardware/tools/avr/etc/avrdude.conf"
#export ISPTOOL=usbasp
#export ISPPORT=/dev/usbasp
#export ISPSPEED=-b19200

export SPEED=38400
export PORT=/dev/ttyUSB0

avrdude $AVRDUDE_CONF -v -c arduino -P $PORT -b $SPEED -p ATmega328P -e -U flash:w:light.ino.hex
