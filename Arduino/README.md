# Arduino

## Step 1 - Set Fuses

This method uses a USBasp hardware programmer and the AVRDUDE programming software.

* Download AVRDUDE - https://github.com/avrdudes/avrdude
* Extract AVRDUDE to C:\Temp or any other location
* Download the Windows batch script - setfuses.cmd
* Place setfuses.cmd in the same directory as AVRDUDE.exe
* Connect your USBasp programmer to the Novus T1200XE board
* Run setfuses.cmd

## Step 2 - Burn Bootloader

Coming soon!

## Step 3 - Upload Code

* Open the .ino file in Arduino.
* Select "Arduino Pro or Pro Mini" under "Arduino AVR Boards"
* Select your COM port
* Upload

Done!
