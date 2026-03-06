# Novus T1200XE Basic

Prototype A of this design is now available!

The zip archive contains the gerber files for the basic version and the xlsx files store the parameters for the components.

The BoM and CPL files are formatted for JLCPCB. I'm working on separate files for PCBWay, but they may accept them as is.

The following is required for the PCB manufacturer-

* novus_t1200xe_pm_dual_0.8.1_pa.zip
* novus_t1200xe_0.8_pa_basic_bom_smd.xlsx (SMD Only)
* novus_t1200xe_0.8_pa_basic_cpl_smd_upd.xlsx (SMD Only)

* Optional - replace novus_t1200xe_0.8_pa_basic_bom_smd.xlsx with novus_t1200xe_0.8.1_pa_basic_bom_all.xlsx (SMD & TH)
* Optional - replace novus_t1200xe_0.8_pa_basic_cpl_smd_upd.xlsx with novus_t1200xe_0.8.1_pa_basic_cpl_all.xlsx (SMD & TH)

## PCB Manufacturing

Select the "Untented Via's" option when placing your PCB order. This is because some via's are placed within pads and should not be filled with resin/epoxy.

If you're using a PCB manufacturer like JLCPCB, select the option to confirm the placement of the components before they continue with production. I'm mentioning this as JLC's 3D viewer for the populated board is not rendering properly, but if you select the simple view, you'll see that components are in the right locations. It's just a free sanity check that I'm recommending.

## Update - 2 March '26

novus_t1200xe_0.8_pa_basic_cpl_smd_upd.xlsx was updated for component orientation, however JLCPCB's viewer still does weird things with the components. Ensure that you select the option to confirm component placement.

I'm concerned about the final orientation of some components, particularly D10 and D12. The cathode (line) should face the 40-Pin connector on these two diodes.

## Update #1 - 6 March '26

v0.8.1 Changes - Silkscreen orientation markings for D10 and D12 diodes & one ground via moved.

I'm working on the PCBWay project page for this design.

## Update #2 - 6 March '26

I have added the through hole components to the BoM and CPL files. You might pay extra for the placement as they are almost certainly hand-soldered.

These parts are included - C1, C60, C61, C74, C75, C76, J1, S2