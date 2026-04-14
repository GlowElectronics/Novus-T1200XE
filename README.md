# Novus T1200XE PMB

This is a replacement power management board for the Toshiba T1200XE laptop. The goal was to implement similar features that the original power management board had.

Why?
Many of the original power boards are failing due to damage caused by aging and leaking capacitors. These capacitors can leak electrolyte, which corrodes PCB traces and seeps into the board layers, causing irreparable damage. The cost of components can rise fast and in many instances, doesn't remedy the failure.

What's been implemented?

* Voltages: 12V, 5V, -9V, -22V & Separate 5V (VCC)
* Main battery: Management for the stock T1200XE battery. (Pro version)
* Logic: ATMEGA328. Manages power-on/off, voltage switching, communication between power management board and laptop motherboard.

Parts that must be re-used from your original Toshiba power board:

* Power switch (because it has reinforcement to give it some strength. the actual switch can be replaced)
* Power jack (this is an opportunity to change it if you dont have the original Toshiba power supply)
* Main battery header (you could probably source another)
* The 40-Pin socket < The most important part! (I have no idea if this part exists anymore)

## Building the PCB

There is one PCB and two BoM's to choose from- Lite and Pro. The Lite version does not take any battery management into account. The Pro version includes Ni-MH battery management onboard.\
It is recommended to have the manufacturer populate the surface-mount components unless you have access to a hot-air rework station and are experienced with surface-mount soldering.\

## Technical Notes

Main battery circuit - Designed around the DS2715 (Ni-Cd & Ni-MH) and adjusted to function off a 12V power supply with the ability to charge six(6) cells in series, with a total of 7.2V. CANNOT be used for any type of retrofit lithium battery mods.\
RAM battery circuit - Eliminated. Tied to 5V. (see Known Issues)

## Development Environment

This PCB is designed in Eagle 6.5.\
All development boards have been manufactured by JLCPCB, and the gerber files have been exported according to their requirements.\
I'm working on the PCBWay files and project page.

## Known Issues

As the RAM battery circuit has been eliminated, the Hard RAM feature (Persistent RAM disk) is not available when using this board. I can possibly add it in a future release.

## A Personal Note

I’ve spent a great deal of time researching, designing, and testing this device through multiple development stages. My goal has been to create a reliable and well-performing product that reflects my passion for electronics. However, as a dedicated hobbyist rather than a certified professional, I recognize that my designs may have limitations or areas that could be refined further. I encourage you to examine the build quality and performance for yourself, and to make any adjustments or improvements that suit your specific needs or expectations.