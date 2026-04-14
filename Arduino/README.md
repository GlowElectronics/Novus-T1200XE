# Arduino

## Step 1 - Set Fuses

This method uses a USBasp hardware programmer and the AVRDUDE programming software.

* Download setfuses_avrdude.zip
* Extract setfuses_avrdude.zip to C:\Temp or any other location
* Connect your USBasp programmer to your PC and install the libusbK driver through Zadig - https://zadig.akeo.ie/
* Disconnect the USBasp
* Connect the USBasp to the Novus T1200XE board with 6 jumper wires
* Reconnect the USBasp and run setfuses.cmd

## Step 2 - Burn Bootloader

* Disconnect the USBasp
* Reconnect the USBasp and open Arduino IDE
* Select "USBasp" under Tools | Programmer
* Open the Tools menu again and select "Burn Bootloader"
* Disconnect the USBasp

## Step 3 - Upload Code

* Insert a USB Type-C cable into the Novus T1200XE
* Open the .ino file in Arduino.
* Select "Arduino Pro or Pro Mini" under "Arduino AVR Boards"
* Select your COM port
* Upload

Done!

## Issues

If you encounter issues during the programming of the fuses (cannot set sck, etc.), please update the firmware on the USBasp to usbasp.2011-05-28.tar.gz from the official website - https://www.fischl.de/usbasp/

You can view this video on the update process - https://www.youtube.com/watch?v=MT_v0yea0Ik

It's recommended to disconnect and reconnect the USBasp between commands to avoid programming issues in Windows.