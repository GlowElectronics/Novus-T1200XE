# Novus T1200XE Basic

Prototype A of this design is now available!

The zip archive contains the gerber files for the basic version and the xlsx files store the parameters for the components.

The following is required for the PCB manufacturer-

* novus_t1200xe_pm_dual_0.8.1_pa.zip
* novus_t1200xe_0.8_pa_basic_bom_smd.xlsx
* novus_t1200xe_0.8_pa_basic_cpl_smd_upd.xlsx

An extra file - novus_t1200xe_0.8_pa_basic_bom_th.xlsx is included for the through hole components that must be populated on the board.

## Important

If you're using a PCB manufacturer like JLCPCB, please select the option to confirm the placement of the components before they continue with production. I'm mentioning this as JLC's 3D viewer for the populated board is not rendering properly, but if you select the simple view, you'll see that components are in the right locations. It's just a free sanity check that I'm recommending.

Select the "Untented Via's" option when placing your PCB order. This is because some via's are placed within pads and should not be filled with resin.

## Update 2 March '26

novus_t1200xe_0.8_pa_basic_cpl_smd_upd.xlsx was updated for component orientation, however JLCPCB's viewer still does weird things with the components. Ensure that you select the option to confirm component placement.

I'm concerned about the final orientation of some components, particularly D10 and D12. The cathode (line) should face the 40-Pin connector on these two diodes.

## Update 6 March '26

v0.8.1 Changes - Silkscreen orientation markings for D10 and D12 diodes & one ground via moved.

I'm working on the PCBWay project page for this design.