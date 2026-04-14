## Signal Information

Through my research on this project, I’ve gathered information regarding the communication signals between the power management board and the laptop’s motherboard. While I’ve done my best to identify their functions based on testing, observation, and available documentation, some details may still be inaccurate. Unfortunately, I haven’t been able to locate any definitive or publicly available information confirming the exact purpose of these signals.

* RAMV - RAM voltage line. Used with the internal backup battery to keep the contents in RAM active while the main battery is replaced. Tied to 5V.
* BLV - Backlight voltage. Tied to 12V.
* P12V - The 12V rail.
* N9V - Negative 9 volt. Used for RS232 and the internal modem.
* LCDV - Negative 22 volt. Used for the LCD panel.
* CBLON - Output from PMB. Toggles 5V to the display inverter board.
* CPCNF - Input to PMB. Perhaps something to do with a co-processor or automatic downclocking of the CPU when the laptop is idling.
* ACIN - Output from PMB. AC-DC adapter present signal.
* PCLR - Output from PMB. Power Clear / Reset.
* INTDSP - Input to PMB. LOW on boot. High when screen lid switch is pressed. Signal to turn off CBLON.
* CHG - Output from PMB. Main battery charging signal.
* LB - Output from PMB. Low battery signal.
* BEEP - Output from PMB.
* PSRD - Power supply read data / Power supply ready
* PSSD - Power supply send data / Power supply shutdown

## PCB Gerbers

As of March 1st 2026, the Lite version of this design is available to the public.

The Pro version is still in development and will come in time.