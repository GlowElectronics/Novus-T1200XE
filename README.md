# Novus T1200XE

This is a replacement power management board for the Toshiba T1200XE laptop. The goal was to implement similar features that the original power management board had. "Novus" is Latin for "New".

Many of the original power boards are failing due to damage caused by aging and leaking capacitors. These capacitors can leak electrolyte, which corrodes PCB traces and seeps into the board layers, causing irreparable damage. The cost of components can rise fast and in many instances, doesn't remedy the failure. A replacement was needed!

What's been implemented?

* Voltages: 12V, 5V, -9V, -22V & Separate 5V (VCC)
* Main battery: Management for the stock T1200XE battery. (or a rebuilt version of the T1200XE battery with the same chemistry)
* Logic: ATMEGA328. Manages power-on/off, voltage switching, communication between power management board and laptop motherboard.

Parts that must be re-used from your original Toshiba power board:

* Power switch (because it has reinforcement to give it some strength. the actual switch can be replaced)
* Power jack (this is an opportunity to change it if you dont have the original Toshiba power supply)
* Main battery header (you could probably source another)
* The 40-Pin socket (no idea if this part exists anymore) < The most important part!

## Signal Information

Through my research on this project, I’ve gathered information regarding the communication signals between the power management board and the laptop’s motherboard. While I’ve done my best to identify their functions based on testing, observation, and available documentation, some details may still be inaccurate. Unfortunately, I haven’t been able to locate any definitive or publicly available information confirming the exact purpose of these signals.

* RAMV - RAM voltage line. Used with the internal backup battery to keep the contents in RAM active while the main battery is replaced. Tied to 5V.
* BLV - Backlight voltage. Tied to 12V.
* P12V - The 12V rail.
* N9V - Negative 9 volt. Used for RS232 and the internal modem.
* LCDV - Negative 22 volt. Used for the LCD panel.
* CBLON - Output from PMB. Toggles 5V to the display inverter board.
* CPCNF - Input to PMB. Perhaps something to do with a co-processor.
* ACIN - Output from PMB. AC-DC adapter present signal.
* PCLR - Output from PMB. Power Clear / Reset.
* INTDSP - Input to PMB. LOW on boot. High when screen lid switch is pressed. Signal to turn off CBLON.
* CHG - Output from PMB. Main battery charging signal.
* LB - Output from PMB. Low battery signal.
* BEEP - Output from PMB.
* PSRD - Power supply read data / Power supply ready
* PSSD - Power supply send data / Power supply shutdown

## Building the PCB

There is one PCB and two BoM's to choose from- Basic and Pro. The basic version does not take any battery management into account. The Pro version includes Ni-MH battery management onboard.\
It is recommended to have the manufacturer populate the surface-mount components unless you have access to a hot-air rework station and are experienced with surface-mount soldering.\
The through-hole capacitors must be purchased separately and installed during assembly along with the 40-pin connector and other through-hole components.

## Technical Notes

Main battery circuit - Designed around the DS2715 (Ni-Cd & Ni-MH) and adjusted to function off a 12V power supply with the ability to charge six(6) cells in series, with a total of 7.2V. CANNOT be used for any type of retrofit lithium battery mods.\
RAM battery circuit - Eliminated. Tied to 5V.

## Development Environment

This PCB is designed in Eagle 6.5.\
All development boards have been manufactured by JLCPCB, and the gerber files have been exported according to their requirements. This shouldn't be an issue for other manufacturers like PCBWay.

## TODO

Technical notes update.\
Build videos.\
Learn KiCAD :)

## A Personal Note

I’ve spent a great deal of time researching, designing, and testing this device through multiple development stages. My goal has been to create a reliable and well-performing product that reflects my passion for electronics. However, as a dedicated hobbyist rather than a certified professional, I recognize that my designs may have limitations or areas that could be refined further. I encourage you to examine the build quality and performance for yourself, and to make any adjustments or improvements that suit your specific needs or expectations.

## Tips

I've also spent a decent amount developing this board. If it helps you and you want to show your appreciation, please check my Ko-Fi link for tips.

[![ko-fi](https://ko-fi.com/img/githubbutton_sm.svg)](https://ko-fi.com/T6T71UB3FH)

## Thanks and References
Thanks to the following for helping to piece this puzzle together:
* https://forum.vcfed.org/index.php?threads/toshiba-t1200xe-restoration-post.1242276/
* https://www.minuszerodegrees.net/manuals/Toshiba/Other/Toshiba%20T1200XE%20-%20Maintenance%20Manual.pdf