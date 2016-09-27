;*******************************************************************
;* This stationery serves as the framework for a user application. *
;* For a more comprehensive program that demonstrates the more     *
;* advanced functionality of this processor, please see the        *
;* demonstration applications, located in the examples             *
;* subdirectory of the "Freescale CodeWarrior for HC08" program    *
;* directory.                                                      *
;*******************************************************************

; export symbols
            XDEF asm_main

            ; Include derivative-specific definitions
            INCLUDE 'derivative.inc'

; variable/data section
MY_ZEROPAGE: SECTION  SHORT
; Insert here your data definition. For demonstration, temp_byte is used.
temp_byte:  DS.B   1

; code section
MyCode:     SECTION
; this assembly routine is called the C/C++ application
asm_main:
            MOV    #1,temp_byte     ; just some demonstration code
            NOP                     ; Insert here your own code

            RTS                     ; return to caller
