# Arduino

## Step 1 - Set Fuses

This method uses a USBasp hardware programmer and the AVRDUDE programming software.

* Download AVRDUDE - https://github.com/avrdudes/avrdude
* Extract AVRDUDE to C:\Temp or any other location
* Download the Windows batch script - setfuses.cmd
* Place setfuses.cmd in the same directory as AVRDUDE.exe
* Connect your USBasp programmer to the Novus T1200XE board with 6 male-to-female jumper wires
* Run setfuses.cmd

## Step 2 - Burn Bootloader

* While the USBasp is still connected, open Arduino IDE
* Select "USBasp" under Tools | Programmer
* Open the Tools menu again and select "Burn Bootloader"

## Step 3 - Upload Code

* Insert a USB Type-C cable into the Novus T1200XE
* Open the .ino file in Arduino.
* Select "Arduino Pro or Pro Mini" under "Arduino AVR Boards"
* Select your COM port
* Upload

Done!
