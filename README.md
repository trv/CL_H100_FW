# CL_H100_FW
Reverse engineering H100 firmware 1.2.8 to try to fix the fan rattle.

Device firmware is included in the [Corsair Link installer](http://www.corsair.com/en-us/support/downloads)

Development environment is the [Freescale CodeWarrior Evaluation IDE](http://www.freescale.com/tools/software-and-tools/software-development-tools/codewarrior-development-tools/codewarrior-development-studios/codewarrior-for-microcontrollers/codewarrior-for-mcus-eclipse-ide-coldfire-56800-e-dsc-kinetis-freescale-56xx-rs08-s08-s12z-v10.6:CW-MCU10?tab=Buy_Parametric_Tab&fromSearch=false)

1. Use C:/Freescale/CW MCU10 v10.4/MCU/prog/decoder.exe to disassemble the .s19 file.  See [Decoder User Guide](http://www.freescale.com/files/soft_dev_tools/doc/user_guide/DECODERUG.pdf) for details.  
    `decoder.exe -Proc=HC08:HCS08 CorsairLinkHydroFW_1.2.8.s19`
2. Assemble the resulting assembly listing and compare for differences.  Generally, these will be caused by data being treated as assembly instructions and re-assembled using a more compact encoding.  Also, convert the interrupt vector table from decoded assembly instructions back to addresses.


