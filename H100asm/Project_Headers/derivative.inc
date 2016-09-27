; Note: This file is recreated by the project wizard whenever the MCU is
;       changed and should not be edited by hand

; include derivative specific macros
            INCLUDE 'MC9S08MP16.inc'


; RAM/ROM definitions


; Watchdog feed macro
feed_watchdog: MACRO
            PSHA
            LDA #$55
            STA SRS
            COMA
            STA SRS
            PULA

          ENDM
