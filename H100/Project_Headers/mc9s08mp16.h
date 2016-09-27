/* Based on CPU DB MC9S08MP16_48, version 3.00.021 (RegistersPrg V2.32) */
/*
** ###################################################################
**     Filename  : mc9s08mp16.h
**     Processor : MC9S08MP16VLF
**     FileFormat: V2.32
**     DataSheet : MC9S08MP16 Rev. 1 09/2009
**     Compiler  : CodeWarrior compiler
**     Date/Time : 5.10.2010, 13:54
**     Abstract  :
**         This header implements the mapping of I/O devices.
**
**     Copyright : 1997 - 2010 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
**
**     CPU Registers Revisions:
**               - none
**
**     File-Format-Revisions:
**      - 17.3.2009, V2.27 :
**               - Merged bit-group is not generated, if the name matches with another bit name in the register
**      - 6.4.2009, V2.28 :
**               - Fixed generation of merged bits for bit-groups with a digit at the end, if group-name is defined in CPUDB
**      - 3.8.2009, V2.29 :
**               - If there is just one bits group matching register name, single bits are not generated
**      - 10.9.2009, V2.30 :
**               - Fixed generation of registers arrays.
**      - 15.10.2009, V2.31 :
**               - HCS08 family: Bits and bit-groups are published for 16-bit registers: 8-bit overlay registers are required.
**      - 18.05.2010, V2.32 :
**               - MISRA compliance: U/UL suffixes added to all numbers (_MASK,_BITNUM and addresses)
**
**     Not all general-purpose I/O pins are available on all packages or on all mask sets of a specific
**     derivative device. To avoid extra current drain from floating input pins, the user’s reset
**     initialization routine in the application program must either enable on-chip pull-up devices
**     or change the direction of unconnected pins to outputs so the pins do not float.
** ###################################################################
*/

#ifndef _MC9S08MP16_H
#define _MC9S08MP16_H

/*lint -save  -e950 -esym(960,18.4) -e46 -esym(961,19.7) Disable MISRA rule (1.1,18.4,6.4,19.7) checking. */
/* Types definition */
typedef unsigned char byte;
typedef unsigned int word;
typedef unsigned long dword;
typedef unsigned long dlong[2];

/* Watchdog reset macro */
#ifndef __RESET_WATCHDOG
#ifdef _lint
  #define __RESET_WATCHDOG()  /* empty */
#else
  #define __RESET_WATCHDOG() (void)(SRS = 0x55U, SRS = 0xAAU)
#endif
#endif /* __RESET_WATCHDOG */

#define REG_BASE 0x0000                /* Base address for the I/O register block */


#pragma MESSAGE DISABLE C1106 /* WARNING C1106: Non-standard bitfield type */

/**************** interrupt vector numbers ****************/
#define VectorNumber_VReserved31        31U
#define VectorNumber_Vkeyboard3         30U
#define VectorNumber_Vkeyboard2         29U
#define VectorNumber_Vkeyboard1         28U
#define VectorNumber_Vhscmp3            27U
#define VectorNumber_Vhscmp2            26U
#define VectorNumber_Vhscmp1            25U
#define VectorNumber_Vrtc               24U
#define VectorNumber_Viic               23U
#define VectorNumber_Vscitx             22U
#define VectorNumber_Vscirx             21U
#define VectorNumber_Vscierr            20U
#define VectorNumber_Vspi               19U
#define VectorNumber_Vadc               18U
#define VectorNumber_Vpdb2              17U
#define VectorNumber_Vpdb1              16U
#define VectorNumber_Vmtim              15U
#define VectorNumber_Vftm2ovf           14U
#define VectorNumber_Vftm2ch5           13U
#define VectorNumber_Vftm2ch4           12U
#define VectorNumber_Vftm2ch3           11U
#define VectorNumber_Vftm2ch2           10U
#define VectorNumber_Vftm2ch1           9U
#define VectorNumber_Vftm2ch0           8U
#define VectorNumber_Vftm1ovf           7U
#define VectorNumber_Vftm1ch1           6U
#define VectorNumber_Vftm1ch0           5U
#define VectorNumber_Vftm2fault         4U
#define VectorNumber_Vftm1fault         3U
#define VectorNumber_Vlvw               2U
#define VectorNumber_Vswi               1U
#define VectorNumber_Vreset             0U

/**************** interrupt vector table ****************/
#define VReserved31                     0xFFC0U
#define Vkeyboard3                      0xFFC2U
#define Vkeyboard2                      0xFFC4U
#define Vkeyboard1                      0xFFC6U
#define Vhscmp3                         0xFFC8U
#define Vhscmp2                         0xFFCAU
#define Vhscmp1                         0xFFCCU
#define Vrtc                            0xFFCEU
#define Viic                            0xFFD0U
#define Vscitx                          0xFFD2U
#define Vscirx                          0xFFD4U
#define Vscierr                         0xFFD6U
#define Vspi                            0xFFD8U
#define Vadc                            0xFFDAU
#define Vpdb2                           0xFFDCU
#define Vpdb1                           0xFFDEU
#define Vmtim                           0xFFE0U
#define Vftm2ovf                        0xFFE2U
#define Vftm2ch5                        0xFFE4U
#define Vftm2ch4                        0xFFE6U
#define Vftm2ch3                        0xFFE8U
#define Vftm2ch2                        0xFFEAU
#define Vftm2ch1                        0xFFECU
#define Vftm2ch0                        0xFFEEU
#define Vftm1ovf                        0xFFF0U
#define Vftm1ch1                        0xFFF2U
#define Vftm1ch0                        0xFFF4U
#define Vftm2fault                      0xFFF6U
#define Vftm1fault                      0xFFF8U
#define Vlvw                            0xFFFAU
#define Vswi                            0xFFFCU
#define Vreset                          0xFFFEU

/**************** registers I/O map ****************/

/*** PTAD - Port A Data Register; 0x00000000 ***/
typedef union {
  byte Byte;
  struct {
    byte PTAD0       :1;                                       /* Port A Data Register Bit 0 */
    byte PTAD1       :1;                                       /* Port A Data Register Bit 1 */
    byte PTAD2       :1;                                       /* Port A Data Register Bit 2 */
    byte PTAD3       :1;                                       /* Port A Data Register Bit 3 */
    byte PTAD4       :1;                                       /* Port A Data Register Bit 4 */
    byte PTAD5       :1;                                       /* Port A Data Register Bit 5 */
    byte PTAD6       :1;                                       /* Port A Data Register Bit 6 */
    byte PTAD7       :1;                                       /* Port A Data Register Bit 7 */
  } Bits;
} PTADSTR;
extern volatile PTADSTR _PTAD @0x00000000;
#define PTAD                            _PTAD.Byte
#define PTAD_PTAD0                      _PTAD.Bits.PTAD0
#define PTAD_PTAD1                      _PTAD.Bits.PTAD1
#define PTAD_PTAD2                      _PTAD.Bits.PTAD2
#define PTAD_PTAD3                      _PTAD.Bits.PTAD3
#define PTAD_PTAD4                      _PTAD.Bits.PTAD4
#define PTAD_PTAD5                      _PTAD.Bits.PTAD5
#define PTAD_PTAD6                      _PTAD.Bits.PTAD6
#define PTAD_PTAD7                      _PTAD.Bits.PTAD7

#define PTAD_PTAD0_MASK                 1U
#define PTAD_PTAD1_MASK                 2U
#define PTAD_PTAD2_MASK                 4U
#define PTAD_PTAD3_MASK                 8U
#define PTAD_PTAD4_MASK                 16U
#define PTAD_PTAD5_MASK                 32U
#define PTAD_PTAD6_MASK                 64U
#define PTAD_PTAD7_MASK                 128U


/*** PTADD - Port A Data Direction Register; 0x00000001 ***/
typedef union {
  byte Byte;
  struct {
    byte PTADD0      :1;                                       /* Data Direction for Port A Bit 0 */
    byte PTADD1      :1;                                       /* Data Direction for Port A Bit 1 */
    byte PTADD2      :1;                                       /* Data Direction for Port A Bit 2 */
    byte PTADD3      :1;                                       /* Data Direction for Port A Bit 3 */
    byte PTADD4      :1;                                       /* Data Direction for Port A Bit 4 */
    byte PTADD5      :1;                                       /* Data Direction for Port A Bit 5 */
    byte PTADD6      :1;                                       /* Data Direction for Port A Bit 6 */
    byte PTADD7      :1;                                       /* Data Direction for Port A Bit 7 */
  } Bits;
} PTADDSTR;
extern volatile PTADDSTR _PTADD @0x00000001;
#define PTADD                           _PTADD.Byte
#define PTADD_PTADD0                    _PTADD.Bits.PTADD0
#define PTADD_PTADD1                    _PTADD.Bits.PTADD1
#define PTADD_PTADD2                    _PTADD.Bits.PTADD2
#define PTADD_PTADD3                    _PTADD.Bits.PTADD3
#define PTADD_PTADD4                    _PTADD.Bits.PTADD4
#define PTADD_PTADD5                    _PTADD.Bits.PTADD5
#define PTADD_PTADD6                    _PTADD.Bits.PTADD6
#define PTADD_PTADD7                    _PTADD.Bits.PTADD7

#define PTADD_PTADD0_MASK               1U
#define PTADD_PTADD1_MASK               2U
#define PTADD_PTADD2_MASK               4U
#define PTADD_PTADD3_MASK               8U
#define PTADD_PTADD4_MASK               16U
#define PTADD_PTADD5_MASK               32U
#define PTADD_PTADD6_MASK               64U
#define PTADD_PTADD7_MASK               128U


/*** PTBD - Port B Data Register; 0x00000002 ***/
typedef union {
  byte Byte;
  struct {
    byte PTBD0       :1;                                       /* Port B Data Register Bit 0 */
    byte PTBD1       :1;                                       /* Port B Data Register Bit 1 */
    byte PTBD2       :1;                                       /* Port B Data Register Bit 2 */
    byte PTBD3       :1;                                       /* Port B Data Register Bit 3 */
    byte PTBD4       :1;                                       /* Port B Data Register Bit 4 */
    byte PTBD5       :1;                                       /* Port B Data Register Bit 5 */
    byte PTBD6       :1;                                       /* Port B Data Register Bit 6 */
    byte PTBD7       :1;                                       /* Port B Data Register Bit 7 */
  } Bits;
} PTBDSTR;
extern volatile PTBDSTR _PTBD @0x00000002;
#define PTBD                            _PTBD.Byte
#define PTBD_PTBD0                      _PTBD.Bits.PTBD0
#define PTBD_PTBD1                      _PTBD.Bits.PTBD1
#define PTBD_PTBD2                      _PTBD.Bits.PTBD2
#define PTBD_PTBD3                      _PTBD.Bits.PTBD3
#define PTBD_PTBD4                      _PTBD.Bits.PTBD4
#define PTBD_PTBD5                      _PTBD.Bits.PTBD5
#define PTBD_PTBD6                      _PTBD.Bits.PTBD6
#define PTBD_PTBD7                      _PTBD.Bits.PTBD7

#define PTBD_PTBD0_MASK                 1U
#define PTBD_PTBD1_MASK                 2U
#define PTBD_PTBD2_MASK                 4U
#define PTBD_PTBD3_MASK                 8U
#define PTBD_PTBD4_MASK                 16U
#define PTBD_PTBD5_MASK                 32U
#define PTBD_PTBD6_MASK                 64U
#define PTBD_PTBD7_MASK                 128U


/*** PTBDD - Port B Data Direction Register; 0x00000003 ***/
typedef union {
  byte Byte;
  struct {
    byte PTBDD0      :1;                                       /* Data Direction for Port B Bit 0 */
    byte PTBDD1      :1;                                       /* Data Direction for Port B Bit 1 */
    byte PTBDD2      :1;                                       /* Data Direction for Port B Bit 2 */
    byte PTBDD3      :1;                                       /* Data Direction for Port B Bit 3 */
    byte PTBDD4      :1;                                       /* Data Direction for Port B Bit 4 */
    byte PTBDD5      :1;                                       /* Data Direction for Port B Bit 5 */
    byte PTBDD6      :1;                                       /* Data Direction for Port B Bit 6 */
    byte PTBDD7      :1;                                       /* Data Direction for Port B Bit 7 */
  } Bits;
} PTBDDSTR;
extern volatile PTBDDSTR _PTBDD @0x00000003;
#define PTBDD                           _PTBDD.Byte
#define PTBDD_PTBDD0                    _PTBDD.Bits.PTBDD0
#define PTBDD_PTBDD1                    _PTBDD.Bits.PTBDD1
#define PTBDD_PTBDD2                    _PTBDD.Bits.PTBDD2
#define PTBDD_PTBDD3                    _PTBDD.Bits.PTBDD3
#define PTBDD_PTBDD4                    _PTBDD.Bits.PTBDD4
#define PTBDD_PTBDD5                    _PTBDD.Bits.PTBDD5
#define PTBDD_PTBDD6                    _PTBDD.Bits.PTBDD6
#define PTBDD_PTBDD7                    _PTBDD.Bits.PTBDD7

#define PTBDD_PTBDD0_MASK               1U
#define PTBDD_PTBDD1_MASK               2U
#define PTBDD_PTBDD2_MASK               4U
#define PTBDD_PTBDD3_MASK               8U
#define PTBDD_PTBDD4_MASK               16U
#define PTBDD_PTBDD5_MASK               32U
#define PTBDD_PTBDD6_MASK               64U
#define PTBDD_PTBDD7_MASK               128U


/*** PTCD - Port C Data Register; 0x00000004 ***/
typedef union {
  byte Byte;
  struct {
    byte PTCD0       :1;                                       /* Port C Data Register Bit 0 */
    byte PTCD1       :1;                                       /* Port C Data Register Bit 1 */
    byte PTCD2       :1;                                       /* Port C Data Register Bit 2 */
    byte PTCD3       :1;                                       /* Port C Data Register Bit 3 */
    byte PTCD4       :1;                                       /* Port C Data Register Bit 4 */
    byte PTCD5       :1;                                       /* Port C Data Register Bit 5 */
    byte PTCD6       :1;                                       /* Port C Data Register Bit 6 */
    byte PTCD7       :1;                                       /* Port C Data Register Bit 7 */
  } Bits;
} PTCDSTR;
extern volatile PTCDSTR _PTCD @0x00000004;
#define PTCD                            _PTCD.Byte
#define PTCD_PTCD0                      _PTCD.Bits.PTCD0
#define PTCD_PTCD1                      _PTCD.Bits.PTCD1
#define PTCD_PTCD2                      _PTCD.Bits.PTCD2
#define PTCD_PTCD3                      _PTCD.Bits.PTCD3
#define PTCD_PTCD4                      _PTCD.Bits.PTCD4
#define PTCD_PTCD5                      _PTCD.Bits.PTCD5
#define PTCD_PTCD6                      _PTCD.Bits.PTCD6
#define PTCD_PTCD7                      _PTCD.Bits.PTCD7

#define PTCD_PTCD0_MASK                 1U
#define PTCD_PTCD1_MASK                 2U
#define PTCD_PTCD2_MASK                 4U
#define PTCD_PTCD3_MASK                 8U
#define PTCD_PTCD4_MASK                 16U
#define PTCD_PTCD5_MASK                 32U
#define PTCD_PTCD6_MASK                 64U
#define PTCD_PTCD7_MASK                 128U


/*** PTCDD - Port C Data Direction Register; 0x00000005 ***/
typedef union {
  byte Byte;
  struct {
    byte PTCDD0      :1;                                       /* Data Direction for Port C Bit 0 */
    byte PTCDD1      :1;                                       /* Data Direction for Port C Bit 1 */
    byte PTCDD2      :1;                                       /* Data Direction for Port C Bit 2 */
    byte PTCDD3      :1;                                       /* Data Direction for Port C Bit 3 */
    byte PTCDD4      :1;                                       /* Data Direction for Port C Bit 4 */
    byte PTCDD5      :1;                                       /* Data Direction for Port C Bit 5 */
    byte PTCDD6      :1;                                       /* Data Direction for Port C Bit 6 */
    byte PTCDD7      :1;                                       /* Data Direction for Port C Bit 7 */
  } Bits;
} PTCDDSTR;
extern volatile PTCDDSTR _PTCDD @0x00000005;
#define PTCDD                           _PTCDD.Byte
#define PTCDD_PTCDD0                    _PTCDD.Bits.PTCDD0
#define PTCDD_PTCDD1                    _PTCDD.Bits.PTCDD1
#define PTCDD_PTCDD2                    _PTCDD.Bits.PTCDD2
#define PTCDD_PTCDD3                    _PTCDD.Bits.PTCDD3
#define PTCDD_PTCDD4                    _PTCDD.Bits.PTCDD4
#define PTCDD_PTCDD5                    _PTCDD.Bits.PTCDD5
#define PTCDD_PTCDD6                    _PTCDD.Bits.PTCDD6
#define PTCDD_PTCDD7                    _PTCDD.Bits.PTCDD7

#define PTCDD_PTCDD0_MASK               1U
#define PTCDD_PTCDD1_MASK               2U
#define PTCDD_PTCDD2_MASK               4U
#define PTCDD_PTCDD3_MASK               8U
#define PTCDD_PTCDD4_MASK               16U
#define PTCDD_PTCDD5_MASK               32U
#define PTCDD_PTCDD6_MASK               64U
#define PTCDD_PTCDD7_MASK               128U


/*** PTDD - Port D Data Register; 0x00000006 ***/
typedef union {
  byte Byte;
  struct {
    byte PTDD0       :1;                                       /* Port D Data Register Bit 0 */
    byte PTDD1       :1;                                       /* Port D Data Register Bit 1 */
    byte PTDD2       :1;                                       /* Port D Data Register Bit 2 */
    byte PTDD3       :1;                                       /* Port D Data Register Bit 3 */
    byte PTDD4       :1;                                       /* Port D Data Register Bit 4 */
    byte PTDD5       :1;                                       /* Port D Data Register Bit 5 */
    byte PTDD6       :1;                                       /* Port D Data Register Bit 6 */
    byte PTDD7       :1;                                       /* Port D Data Register Bit 7 */
  } Bits;
} PTDDSTR;
extern volatile PTDDSTR _PTDD @0x00000006;
#define PTDD                            _PTDD.Byte
#define PTDD_PTDD0                      _PTDD.Bits.PTDD0
#define PTDD_PTDD1                      _PTDD.Bits.PTDD1
#define PTDD_PTDD2                      _PTDD.Bits.PTDD2
#define PTDD_PTDD3                      _PTDD.Bits.PTDD3
#define PTDD_PTDD4                      _PTDD.Bits.PTDD4
#define PTDD_PTDD5                      _PTDD.Bits.PTDD5
#define PTDD_PTDD6                      _PTDD.Bits.PTDD6
#define PTDD_PTDD7                      _PTDD.Bits.PTDD7

#define PTDD_PTDD0_MASK                 1U
#define PTDD_PTDD1_MASK                 2U
#define PTDD_PTDD2_MASK                 4U
#define PTDD_PTDD3_MASK                 8U
#define PTDD_PTDD4_MASK                 16U
#define PTDD_PTDD5_MASK                 32U
#define PTDD_PTDD6_MASK                 64U
#define PTDD_PTDD7_MASK                 128U


/*** PTDDD - Port D Data Direction Register; 0x00000007 ***/
typedef union {
  byte Byte;
  struct {
    byte PTDDD0      :1;                                       /* Data Direction for Port D Bit 0 */
    byte PTDDD1      :1;                                       /* Data Direction for Port D Bit 1 */
    byte PTDDD2      :1;                                       /* Data Direction for Port D Bit 2 */
    byte PTDDD3      :1;                                       /* Data Direction for Port D Bit 3 */
    byte PTDDD4      :1;                                       /* Data Direction for Port D Bit 4 */
    byte PTDDD5      :1;                                       /* Data Direction for Port D Bit 5 */
    byte PTDDD6      :1;                                       /* Data Direction for Port D Bit 6 */
    byte PTDDD7      :1;                                       /* Data Direction for Port D Bit 7 */
  } Bits;
} PTDDDSTR;
extern volatile PTDDDSTR _PTDDD @0x00000007;
#define PTDDD                           _PTDDD.Byte
#define PTDDD_PTDDD0                    _PTDDD.Bits.PTDDD0
#define PTDDD_PTDDD1                    _PTDDD.Bits.PTDDD1
#define PTDDD_PTDDD2                    _PTDDD.Bits.PTDDD2
#define PTDDD_PTDDD3                    _PTDDD.Bits.PTDDD3
#define PTDDD_PTDDD4                    _PTDDD.Bits.PTDDD4
#define PTDDD_PTDDD5                    _PTDDD.Bits.PTDDD5
#define PTDDD_PTDDD6                    _PTDDD.Bits.PTDDD6
#define PTDDD_PTDDD7                    _PTDDD.Bits.PTDDD7

#define PTDDD_PTDDD0_MASK               1U
#define PTDDD_PTDDD1_MASK               2U
#define PTDDD_PTDDD2_MASK               4U
#define PTDDD_PTDDD3_MASK               8U
#define PTDDD_PTDDD4_MASK               16U
#define PTDDD_PTDDD5_MASK               32U
#define PTDDD_PTDDD6_MASK               64U
#define PTDDD_PTDDD7_MASK               128U


/*** PTED - Port E Data Register; 0x00000008 ***/
typedef union {
  byte Byte;
  struct {
    byte PTED0       :1;                                       /* Port E Data Register Bit 0 */
    byte PTED1       :1;                                       /* Port E Data Register Bit 1 */
    byte PTED2       :1;                                       /* Port E Data Register Bit 2 */
    byte PTED3       :1;                                       /* Port E Data Register Bit 3 */
    byte PTED4       :1;                                       /* Port E Data Register Bit 4 */
    byte PTED5       :1;                                       /* Port E Data Register Bit 5 */
    byte PTED6       :1;                                       /* Port E Data Register Bit 6 */
    byte             :1; 
  } Bits;
  struct {
    byte grpPTED :7;
    byte         :1;
  } MergedBits;
} PTEDSTR;
extern volatile PTEDSTR _PTED @0x00000008;
#define PTED                            _PTED.Byte
#define PTED_PTED0                      _PTED.Bits.PTED0
#define PTED_PTED1                      _PTED.Bits.PTED1
#define PTED_PTED2                      _PTED.Bits.PTED2
#define PTED_PTED3                      _PTED.Bits.PTED3
#define PTED_PTED4                      _PTED.Bits.PTED4
#define PTED_PTED5                      _PTED.Bits.PTED5
#define PTED_PTED6                      _PTED.Bits.PTED6
#define PTED_PTED                       _PTED.MergedBits.grpPTED

#define PTED_PTED0_MASK                 1U
#define PTED_PTED1_MASK                 2U
#define PTED_PTED2_MASK                 4U
#define PTED_PTED3_MASK                 8U
#define PTED_PTED4_MASK                 16U
#define PTED_PTED5_MASK                 32U
#define PTED_PTED6_MASK                 64U
#define PTED_PTED_MASK                  127U
#define PTED_PTED_BITNUM                0U


/*** PTEDD - Port E Data Direction Register; 0x00000009 ***/
typedef union {
  byte Byte;
  struct {
    byte PTEDD0      :1;                                       /* Data Direction for Port E Bit 0 */
    byte PTEDD1      :1;                                       /* Data Direction for Port E Bit 1 */
    byte PTEDD2      :1;                                       /* Data Direction for Port E Bit 2 */
    byte PTEDD3      :1;                                       /* Data Direction for Port E Bit 3 */
    byte PTEDD4      :1;                                       /* Data Direction for Port E Bit 4 */
    byte PTEDD5      :1;                                       /* Data Direction for Port E Bit 5 */
    byte PTEDD6      :1;                                       /* Data Direction for Port E Bit 6 */
    byte             :1; 
  } Bits;
  struct {
    byte grpPTEDD :7;
    byte         :1;
  } MergedBits;
} PTEDDSTR;
extern volatile PTEDDSTR _PTEDD @0x00000009;
#define PTEDD                           _PTEDD.Byte
#define PTEDD_PTEDD0                    _PTEDD.Bits.PTEDD0
#define PTEDD_PTEDD1                    _PTEDD.Bits.PTEDD1
#define PTEDD_PTEDD2                    _PTEDD.Bits.PTEDD2
#define PTEDD_PTEDD3                    _PTEDD.Bits.PTEDD3
#define PTEDD_PTEDD4                    _PTEDD.Bits.PTEDD4
#define PTEDD_PTEDD5                    _PTEDD.Bits.PTEDD5
#define PTEDD_PTEDD6                    _PTEDD.Bits.PTEDD6
#define PTEDD_PTEDD                     _PTEDD.MergedBits.grpPTEDD

#define PTEDD_PTEDD0_MASK               1U
#define PTEDD_PTEDD1_MASK               2U
#define PTEDD_PTEDD2_MASK               4U
#define PTEDD_PTEDD3_MASK               8U
#define PTEDD_PTEDD4_MASK               16U
#define PTEDD_PTEDD5_MASK               32U
#define PTEDD_PTEDD6_MASK               64U
#define PTEDD_PTEDD_MASK                127U
#define PTEDD_PTEDD_BITNUM              0U


/*** PTFD - Port F Data Register; 0x0000000A ***/
typedef union {
  byte Byte;
  struct {
    byte PTFD0       :1;                                       /* Port F Data Register Bit 0 */
    byte PTFD1       :1;                                       /* Port F Data Register Bit 1 */
    byte PTFD2       :1;                                       /* Port F Data Register Bit 2 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTFD :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTFDSTR;
extern volatile PTFDSTR _PTFD @0x0000000A;
#define PTFD                            _PTFD.Byte
#define PTFD_PTFD0                      _PTFD.Bits.PTFD0
#define PTFD_PTFD1                      _PTFD.Bits.PTFD1
#define PTFD_PTFD2                      _PTFD.Bits.PTFD2
#define PTFD_PTFD                       _PTFD.MergedBits.grpPTFD

#define PTFD_PTFD0_MASK                 1U
#define PTFD_PTFD1_MASK                 2U
#define PTFD_PTFD2_MASK                 4U
#define PTFD_PTFD_MASK                  7U
#define PTFD_PTFD_BITNUM                0U


/*** PTFDD - Port F Data Direction Register; 0x0000000B ***/
typedef union {
  byte Byte;
  struct {
    byte PTFDD0      :1;                                       /* Data Direction for Port F Bit 0 */
    byte PTFDD1      :1;                                       /* Data Direction for Port F Bit 1 */
    byte PTFDD2      :1;                                       /* Data Direction for Port F Bit 2 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTFDD :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTFDDSTR;
extern volatile PTFDDSTR _PTFDD @0x0000000B;
#define PTFDD                           _PTFDD.Byte
#define PTFDD_PTFDD0                    _PTFDD.Bits.PTFDD0
#define PTFDD_PTFDD1                    _PTFDD.Bits.PTFDD1
#define PTFDD_PTFDD2                    _PTFDD.Bits.PTFDD2
#define PTFDD_PTFDD                     _PTFDD.MergedBits.grpPTFDD

#define PTFDD_PTFDD0_MASK               1U
#define PTFDD_PTFDD1_MASK               2U
#define PTFDD_PTFDD2_MASK               4U
#define PTFDD_PTFDD_MASK                7U
#define PTFDD_PTFDD_BITNUM              0U


/*** KBI1SC - KBI1 Status and Control Register; 0x0000000C ***/
typedef union {
  byte Byte;
  struct {
    byte KBIMOD      :1;                                       /* Keyboard Detection Mode */
    byte KBIE        :1;                                       /* Keyboard Interrupt Enable */
    byte KBACK       :1;                                       /* Keyboard Interrupt Acknowledge */
    byte KBF         :1;                                       /* Keyboard Interrupt Flag */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} KBI1SCSTR;
extern volatile KBI1SCSTR _KBI1SC @0x0000000C;
#define KBI1SC                          _KBI1SC.Byte
#define KBI1SC_KBIMOD                   _KBI1SC.Bits.KBIMOD
#define KBI1SC_KBIE                     _KBI1SC.Bits.KBIE
#define KBI1SC_KBACK                    _KBI1SC.Bits.KBACK
#define KBI1SC_KBF                      _KBI1SC.Bits.KBF

#define KBI1SC_KBIMOD_MASK              1U
#define KBI1SC_KBIE_MASK                2U
#define KBI1SC_KBACK_MASK               4U
#define KBI1SC_KBF_MASK                 8U


/*** KBI1PE - KBI1 Pin Enable Register; 0x0000000D ***/
typedef union {
  byte Byte;
  struct {
    byte KBIPE0      :1;                                       /* Keyboard Pin Enable for KBI Port Bit 0 */
    byte KBIPE1      :1;                                       /* Keyboard Pin Enable for KBI Port Bit 1 */
    byte KBIPE2      :1;                                       /* Keyboard Pin Enable for KBI Port Bit 2 */
    byte KBIPE3      :1;                                       /* Keyboard Pin Enable for KBI Port Bit 3 */
    byte KBIPE4      :1;                                       /* Keyboard Pin Enable for KBI Port Bit 4 */
    byte KBIPE5      :1;                                       /* Keyboard Pin Enable for KBI Port Bit 5 */
    byte KBIPE6      :1;                                       /* Keyboard Pin Enable for KBI Port Bit 6 */
    byte KBIPE7      :1;                                       /* Keyboard Pin Enable for KBI Port Bit 7 */
  } Bits;
} KBI1PESTR;
extern volatile KBI1PESTR _KBI1PE @0x0000000D;
#define KBI1PE                          _KBI1PE.Byte
#define KBI1PE_KBIPE0                   _KBI1PE.Bits.KBIPE0
#define KBI1PE_KBIPE1                   _KBI1PE.Bits.KBIPE1
#define KBI1PE_KBIPE2                   _KBI1PE.Bits.KBIPE2
#define KBI1PE_KBIPE3                   _KBI1PE.Bits.KBIPE3
#define KBI1PE_KBIPE4                   _KBI1PE.Bits.KBIPE4
#define KBI1PE_KBIPE5                   _KBI1PE.Bits.KBIPE5
#define KBI1PE_KBIPE6                   _KBI1PE.Bits.KBIPE6
#define KBI1PE_KBIPE7                   _KBI1PE.Bits.KBIPE7

#define KBI1PE_KBIPE0_MASK              1U
#define KBI1PE_KBIPE1_MASK              2U
#define KBI1PE_KBIPE2_MASK              4U
#define KBI1PE_KBIPE3_MASK              8U
#define KBI1PE_KBIPE4_MASK              16U
#define KBI1PE_KBIPE5_MASK              32U
#define KBI1PE_KBIPE6_MASK              64U
#define KBI1PE_KBIPE7_MASK              128U


/*** KBI1ES - KBI1 Edge Select Register; 0x0000000E ***/
typedef union {
  byte Byte;
  struct {
    byte KBEDG0      :1;                                       /* Keyboard Edge Select Bit 0 */
    byte KBEDG1      :1;                                       /* Keyboard Edge Select Bit 1 */
    byte KBEDG2      :1;                                       /* Keyboard Edge Select Bit 2 */
    byte KBEDG3      :1;                                       /* Keyboard Edge Select Bit 3 */
    byte KBEDG4      :1;                                       /* Keyboard Edge Select Bit 4 */
    byte KBEDG5      :1;                                       /* Keyboard Edge Select Bit 5 */
    byte KBEDG6      :1;                                       /* Keyboard Edge Select Bit 6 */
    byte KBEDG7      :1;                                       /* Keyboard Edge Select Bit 7 */
  } Bits;
} KBI1ESSTR;
extern volatile KBI1ESSTR _KBI1ES @0x0000000E;
#define KBI1ES                          _KBI1ES.Byte
#define KBI1ES_KBEDG0                   _KBI1ES.Bits.KBEDG0
#define KBI1ES_KBEDG1                   _KBI1ES.Bits.KBEDG1
#define KBI1ES_KBEDG2                   _KBI1ES.Bits.KBEDG2
#define KBI1ES_KBEDG3                   _KBI1ES.Bits.KBEDG3
#define KBI1ES_KBEDG4                   _KBI1ES.Bits.KBEDG4
#define KBI1ES_KBEDG5                   _KBI1ES.Bits.KBEDG5
#define KBI1ES_KBEDG6                   _KBI1ES.Bits.KBEDG6
#define KBI1ES_KBEDG7                   _KBI1ES.Bits.KBEDG7

#define KBI1ES_KBEDG0_MASK              1U
#define KBI1ES_KBEDG1_MASK              2U
#define KBI1ES_KBEDG2_MASK              4U
#define KBI1ES_KBEDG3_MASK              8U
#define KBI1ES_KBEDG4_MASK              16U
#define KBI1ES_KBEDG5_MASK              32U
#define KBI1ES_KBEDG6_MASK              64U
#define KBI1ES_KBEDG7_MASK              128U


/*** ADCSC1 - Status and Control Register 1; 0x00000010 ***/
typedef union {
  byte Byte;
  struct {
    byte ADCH0       :1;                                       /* Input Channel Select Bit 0 */
    byte ADCH1       :1;                                       /* Input Channel Select Bit 1 */
    byte ADCH2       :1;                                       /* Input Channel Select Bit 2 */
    byte ADCH3       :1;                                       /* Input Channel Select Bit 3 */
    byte ADCH4       :1;                                       /* Input Channel Select Bit 4 */
    byte ADCO        :1;                                       /* Continuous Conversion Enable - ADCO is used to enable continuous conversions */
    byte AIEN        :1;                                       /* Interrupt Enable - AIEN is used to enable conversion complete interrupts. When COCO becomes set while AIEN is high, an interrupt is asserted */
    byte COCO        :1;                                       /* Conversion Complete Flag */
  } Bits;
  struct {
    byte grpADCH :5;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} ADCSC1STR;
extern volatile ADCSC1STR _ADCSC1 @0x00000010;
#define ADCSC1                          _ADCSC1.Byte
#define ADCSC1_ADCH0                    _ADCSC1.Bits.ADCH0
#define ADCSC1_ADCH1                    _ADCSC1.Bits.ADCH1
#define ADCSC1_ADCH2                    _ADCSC1.Bits.ADCH2
#define ADCSC1_ADCH3                    _ADCSC1.Bits.ADCH3
#define ADCSC1_ADCH4                    _ADCSC1.Bits.ADCH4
#define ADCSC1_ADCO                     _ADCSC1.Bits.ADCO
#define ADCSC1_AIEN                     _ADCSC1.Bits.AIEN
#define ADCSC1_COCO                     _ADCSC1.Bits.COCO
#define ADCSC1_ADCH                     _ADCSC1.MergedBits.grpADCH

#define ADCSC1_ADCH0_MASK               1U
#define ADCSC1_ADCH1_MASK               2U
#define ADCSC1_ADCH2_MASK               4U
#define ADCSC1_ADCH3_MASK               8U
#define ADCSC1_ADCH4_MASK               16U
#define ADCSC1_ADCO_MASK                32U
#define ADCSC1_AIEN_MASK                64U
#define ADCSC1_COCO_MASK                128U
#define ADCSC1_ADCH_MASK                31U
#define ADCSC1_ADCH_BITNUM              0U


/*** ADCSC2 - Status and Control Register 2; 0x00000011 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte ACFGT       :1;                                       /* Compare Function Greater Than Enable */
    byte ACFE        :1;                                       /* Compare Function Enable - ACFE is used to enable the compare function */
    byte ADTRG       :1;                                       /* Conversion Trigger Select-ADTRG is used to select the type of trigger to be used for initiating a conversion */
    byte ADACT       :1;                                       /* Conversion Active - ADACT indicates that a conversion is in progress. ADACT is set when a conversion is initiated and cleared when a conversion is completed or aborted */
  } Bits;
} ADCSC2STR;
extern volatile ADCSC2STR _ADCSC2 @0x00000011;
#define ADCSC2                          _ADCSC2.Byte
#define ADCSC2_ACFGT                    _ADCSC2.Bits.ACFGT
#define ADCSC2_ACFE                     _ADCSC2.Bits.ACFE
#define ADCSC2_ADTRG                    _ADCSC2.Bits.ADTRG
#define ADCSC2_ADACT                    _ADCSC2.Bits.ADACT

#define ADCSC2_ACFGT_MASK               16U
#define ADCSC2_ACFE_MASK                32U
#define ADCSC2_ADTRG_MASK               64U
#define ADCSC2_ADACT_MASK               128U


/*** ADCR - Data Result Register; 0x00000012 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ADCRH - Data Result High Register; 0x00000012 ***/
    union {
      byte Byte;
      struct {
        byte ADR8        :1;                                       /* ADC Result Data Bit 8 */
        byte ADR9        :1;                                       /* ADC Result Data Bit 9 */
        byte ADR10       :1;                                       /* ADC Result Data Bit 10 */
        byte ADR11       :1;                                       /* ADC Result Data Bit 11 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
      struct {
        byte grpADR_8 :4;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } ADCRHSTR;
    #define ADCRH                       _ADCR.Overlap_STR.ADCRHSTR.Byte
    #define ADCRH_ADR8                  _ADCR.Overlap_STR.ADCRHSTR.Bits.ADR8
    #define ADCRH_ADR9                  _ADCR.Overlap_STR.ADCRHSTR.Bits.ADR9
    #define ADCRH_ADR10                 _ADCR.Overlap_STR.ADCRHSTR.Bits.ADR10
    #define ADCRH_ADR11                 _ADCR.Overlap_STR.ADCRHSTR.Bits.ADR11
    #define ADCRH_ADR_8                 _ADCR.Overlap_STR.ADCRHSTR.MergedBits.grpADR_8
    #define ADCRH_ADR                   ADCRH_ADR_8
    
    #define ADCRH_ADR8_MASK             1U
    #define ADCRH_ADR9_MASK             2U
    #define ADCRH_ADR10_MASK            4U
    #define ADCRH_ADR11_MASK            8U
    #define ADCRH_ADR_8_MASK            15U
    #define ADCRH_ADR_8_BITNUM          0U
    

    /*** ADCRL - Data Result Low Register; 0x00000013 ***/
    union {
      byte Byte;
      struct {
        byte ADR0        :1;                                       /* ADC Result Data Bit 0 */
        byte ADR1        :1;                                       /* ADC Result Data Bit 1 */
        byte ADR2        :1;                                       /* ADC Result Data Bit 2 */
        byte ADR3        :1;                                       /* ADC Result Data Bit 3 */
        byte ADR4        :1;                                       /* ADC Result Data Bit 4 */
        byte ADR5        :1;                                       /* ADC Result Data Bit 5 */
        byte ADR6        :1;                                       /* ADC Result Data Bit 6 */
        byte ADR7        :1;                                       /* ADC Result Data Bit 7 */
      } Bits;
    } ADCRLSTR;
    #define ADCRL                       _ADCR.Overlap_STR.ADCRLSTR.Byte
    #define ADCRL_ADR0                  _ADCR.Overlap_STR.ADCRLSTR.Bits.ADR0
    #define ADCRL_ADR1                  _ADCR.Overlap_STR.ADCRLSTR.Bits.ADR1
    #define ADCRL_ADR2                  _ADCR.Overlap_STR.ADCRLSTR.Bits.ADR2
    #define ADCRL_ADR3                  _ADCR.Overlap_STR.ADCRLSTR.Bits.ADR3
    #define ADCRL_ADR4                  _ADCR.Overlap_STR.ADCRLSTR.Bits.ADR4
    #define ADCRL_ADR5                  _ADCR.Overlap_STR.ADCRLSTR.Bits.ADR5
    #define ADCRL_ADR6                  _ADCR.Overlap_STR.ADCRLSTR.Bits.ADR6
    #define ADCRL_ADR7                  _ADCR.Overlap_STR.ADCRLSTR.Bits.ADR7
    
    #define ADCRL_ADR0_MASK             1U
    #define ADCRL_ADR1_MASK             2U
    #define ADCRL_ADR2_MASK             4U
    #define ADCRL_ADR3_MASK             8U
    #define ADCRL_ADR4_MASK             16U
    #define ADCRL_ADR5_MASK             32U
    #define ADCRL_ADR6_MASK             64U
    #define ADCRL_ADR7_MASK             128U
    
  } Overlap_STR;

} ADCRSTR;
extern volatile ADCRSTR _ADCR @0x00000012;
#define ADCR                            _ADCR.Word


/*** ADCCV - Compare Value Register; 0x00000014 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ADCCVH - Compare Value High Register; 0x00000014 ***/
    union {
      byte Byte;
      struct {
        byte ADCV8       :1;                                       /* Compare Function Value 8 */
        byte ADCV9       :1;                                       /* Compare Function Value 9 */
        byte ADCV10      :1;                                       /* Compare Function Value 10 */
        byte ADCV11      :1;                                       /* Compare Function Value 11 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
      struct {
        byte grpADCV_8 :4;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } ADCCVHSTR;
    #define ADCCVH                      _ADCCV.Overlap_STR.ADCCVHSTR.Byte
    #define ADCCVH_ADCV8                _ADCCV.Overlap_STR.ADCCVHSTR.Bits.ADCV8
    #define ADCCVH_ADCV9                _ADCCV.Overlap_STR.ADCCVHSTR.Bits.ADCV9
    #define ADCCVH_ADCV10               _ADCCV.Overlap_STR.ADCCVHSTR.Bits.ADCV10
    #define ADCCVH_ADCV11               _ADCCV.Overlap_STR.ADCCVHSTR.Bits.ADCV11
    #define ADCCVH_ADCV_8               _ADCCV.Overlap_STR.ADCCVHSTR.MergedBits.grpADCV_8
    #define ADCCVH_ADCV                 ADCCVH_ADCV_8
    
    #define ADCCVH_ADCV8_MASK           1U
    #define ADCCVH_ADCV9_MASK           2U
    #define ADCCVH_ADCV10_MASK          4U
    #define ADCCVH_ADCV11_MASK          8U
    #define ADCCVH_ADCV_8_MASK          15U
    #define ADCCVH_ADCV_8_BITNUM        0U
    

    /*** ADCCVL - Compare Value Low Register; 0x00000015 ***/
    union {
      byte Byte;
      struct {
        byte ADCV0       :1;                                       /* Compare Function Value 0 */
        byte ADCV1       :1;                                       /* Compare Function Value 1 */
        byte ADCV2       :1;                                       /* Compare Function Value 2 */
        byte ADCV3       :1;                                       /* Compare Function Value 3 */
        byte ADCV4       :1;                                       /* Compare Function Value 4 */
        byte ADCV5       :1;                                       /* Compare Function Value 5 */
        byte ADCV6       :1;                                       /* Compare Function Value 6 */
        byte ADCV7       :1;                                       /* Compare Function Value 7 */
      } Bits;
    } ADCCVLSTR;
    #define ADCCVL                      _ADCCV.Overlap_STR.ADCCVLSTR.Byte
    #define ADCCVL_ADCV0                _ADCCV.Overlap_STR.ADCCVLSTR.Bits.ADCV0
    #define ADCCVL_ADCV1                _ADCCV.Overlap_STR.ADCCVLSTR.Bits.ADCV1
    #define ADCCVL_ADCV2                _ADCCV.Overlap_STR.ADCCVLSTR.Bits.ADCV2
    #define ADCCVL_ADCV3                _ADCCV.Overlap_STR.ADCCVLSTR.Bits.ADCV3
    #define ADCCVL_ADCV4                _ADCCV.Overlap_STR.ADCCVLSTR.Bits.ADCV4
    #define ADCCVL_ADCV5                _ADCCV.Overlap_STR.ADCCVLSTR.Bits.ADCV5
    #define ADCCVL_ADCV6                _ADCCV.Overlap_STR.ADCCVLSTR.Bits.ADCV6
    #define ADCCVL_ADCV7                _ADCCV.Overlap_STR.ADCCVLSTR.Bits.ADCV7
    
    #define ADCCVL_ADCV0_MASK           1U
    #define ADCCVL_ADCV1_MASK           2U
    #define ADCCVL_ADCV2_MASK           4U
    #define ADCCVL_ADCV3_MASK           8U
    #define ADCCVL_ADCV4_MASK           16U
    #define ADCCVL_ADCV5_MASK           32U
    #define ADCCVL_ADCV6_MASK           64U
    #define ADCCVL_ADCV7_MASK           128U
    
  } Overlap_STR;

} ADCCVSTR;
extern volatile ADCCVSTR _ADCCV @0x00000014;
#define ADCCV                           _ADCCV.Word


/*** ADCCFG - Configuration Register; 0x00000016 ***/
typedef union {
  byte Byte;
  struct {
    byte ADICLK0     :1;                                       /* Input Clock Select Bit 0 */
    byte ADICLK1     :1;                                       /* Input Clock Select Bit 1 */
    byte MODE0       :1;                                       /* Conversion Mode Selection Bit 0 */
    byte MODE1       :1;                                       /* Conversion Mode Selection Bit 1 */
    byte ADLSMP      :1;                                       /* Long Sample Time Configuration */
    byte ADIV0       :1;                                       /* Clock Divide Select Bit 0 */
    byte ADIV1       :1;                                       /* Clock Divide Select Bit 1 */
    byte ADLPC       :1;                                       /* Low Power Configuration */
  } Bits;
  struct {
    byte grpADICLK :2;
    byte grpMODE :2;
    byte         :1;
    byte grpADIV :2;
    byte         :1;
  } MergedBits;
} ADCCFGSTR;
extern volatile ADCCFGSTR _ADCCFG @0x00000016;
#define ADCCFG                          _ADCCFG.Byte
#define ADCCFG_ADICLK0                  _ADCCFG.Bits.ADICLK0
#define ADCCFG_ADICLK1                  _ADCCFG.Bits.ADICLK1
#define ADCCFG_MODE0                    _ADCCFG.Bits.MODE0
#define ADCCFG_MODE1                    _ADCCFG.Bits.MODE1
#define ADCCFG_ADLSMP                   _ADCCFG.Bits.ADLSMP
#define ADCCFG_ADIV0                    _ADCCFG.Bits.ADIV0
#define ADCCFG_ADIV1                    _ADCCFG.Bits.ADIV1
#define ADCCFG_ADLPC                    _ADCCFG.Bits.ADLPC
#define ADCCFG_ADICLK                   _ADCCFG.MergedBits.grpADICLK
#define ADCCFG_MODE                     _ADCCFG.MergedBits.grpMODE
#define ADCCFG_ADIV                     _ADCCFG.MergedBits.grpADIV

#define ADCCFG_ADICLK0_MASK             1U
#define ADCCFG_ADICLK1_MASK             2U
#define ADCCFG_MODE0_MASK               4U
#define ADCCFG_MODE1_MASK               8U
#define ADCCFG_ADLSMP_MASK              16U
#define ADCCFG_ADIV0_MASK               32U
#define ADCCFG_ADIV1_MASK               64U
#define ADCCFG_ADLPC_MASK               128U
#define ADCCFG_ADICLK_MASK              3U
#define ADCCFG_ADICLK_BITNUM            0U
#define ADCCFG_MODE_MASK                12U
#define ADCCFG_MODE_BITNUM              2U
#define ADCCFG_ADIV_MASK                96U
#define ADCCFG_ADIV_BITNUM              5U


/*** APCTL1 - Pin Control 1 Register; 0x00000017 ***/
typedef union {
  byte Byte;
  struct {
    byte ADPC0       :1;                                       /* ADC Pin Control 0 - ADPC0 is used to control the pin associated with channel AD0 */
    byte ADPC1       :1;                                       /* ADC Pin Control 1 - ADPC1 is used to control the pin associated with channel AD1 */
    byte ADPC2       :1;                                       /* ADC Pin Control 2 - ADPC2 is used to control the pin associated with channel AD2 */
    byte ADPC3       :1;                                       /* ADC Pin Control 3 - ADPC3 is used to control the pin associated with channel AD3 */
    byte ADPC4       :1;                                       /* ADC Pin Control 4 - ADPC4 is used to control the pin associated with channel AD4 */
    byte ADPC5       :1;                                       /* ADC Pin Control 5 - ADPC5 is used to control the pin associated with channel AD5 */
    byte ADPC6       :1;                                       /* ADC Pin Control 6 - ADPC6 is used to control the pin associated with channel AD6 */
    byte ADPC7       :1;                                       /* ADC Pin Control 7 - ADPC7 is used to control the pin associated with channel AD7 */
  } Bits;
} APCTL1STR;
extern volatile APCTL1STR _APCTL1 @0x00000017;
#define APCTL1                          _APCTL1.Byte
#define APCTL1_ADPC0                    _APCTL1.Bits.ADPC0
#define APCTL1_ADPC1                    _APCTL1.Bits.ADPC1
#define APCTL1_ADPC2                    _APCTL1.Bits.ADPC2
#define APCTL1_ADPC3                    _APCTL1.Bits.ADPC3
#define APCTL1_ADPC4                    _APCTL1.Bits.ADPC4
#define APCTL1_ADPC5                    _APCTL1.Bits.ADPC5
#define APCTL1_ADPC6                    _APCTL1.Bits.ADPC6
#define APCTL1_ADPC7                    _APCTL1.Bits.ADPC7

#define APCTL1_ADPC0_MASK               1U
#define APCTL1_ADPC1_MASK               2U
#define APCTL1_ADPC2_MASK               4U
#define APCTL1_ADPC3_MASK               8U
#define APCTL1_ADPC4_MASK               16U
#define APCTL1_ADPC5_MASK               32U
#define APCTL1_ADPC6_MASK               64U
#define APCTL1_ADPC7_MASK               128U


/*** APCTL2 - Pin Control 2 Register; 0x00000018 ***/
typedef union {
  byte Byte;
  struct {
    byte ADPC8       :1;                                       /* ADC Pin Control 8 - ADPC8 is used to control the pin associated with channel AD8 */
    byte ADPC9       :1;                                       /* ADC Pin Control 9 - ADPC9 is used to control the pin associated with channel AD9 */
    byte ADPC10      :1;                                       /* ADC Pin Control 10 - ADPC10 is used to control the pin associated with channel AD10 */
    byte ADPC11      :1;                                       /* ADC Pin Control 11 - ADPC11 is used to control the pin associated with channel AD11 */
    byte ADPC12      :1;                                       /* ADC Pin Control 12 - ADPC12 is used to control the pin associated with channel AD12 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpADPC_8 :5;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} APCTL2STR;
extern volatile APCTL2STR _APCTL2 @0x00000018;
#define APCTL2                          _APCTL2.Byte
#define APCTL2_ADPC8                    _APCTL2.Bits.ADPC8
#define APCTL2_ADPC9                    _APCTL2.Bits.ADPC9
#define APCTL2_ADPC10                   _APCTL2.Bits.ADPC10
#define APCTL2_ADPC11                   _APCTL2.Bits.ADPC11
#define APCTL2_ADPC12                   _APCTL2.Bits.ADPC12
#define APCTL2_ADPC_8                   _APCTL2.MergedBits.grpADPC_8
#define APCTL2_ADPC                     APCTL2_ADPC_8

#define APCTL2_ADPC8_MASK               1U
#define APCTL2_ADPC9_MASK               2U
#define APCTL2_ADPC10_MASK              4U
#define APCTL2_ADPC11_MASK              8U
#define APCTL2_ADPC12_MASK              16U
#define APCTL2_ADPC_8_MASK              31U
#define APCTL2_ADPC_8_BITNUM            0U


/*** DAC1CTRL - DAC Control Register; 0x00000019 ***/
typedef union {
  byte Byte;
  struct {
    byte VOSEL0      :1;                                       /* DAC output voltage select, bit 0 */
    byte VOSEL1      :1;                                       /* DAC output voltage select, bit 1 */
    byte VOSEL2      :1;                                       /* DAC output voltage select, bit 2 */
    byte VOSEL3      :1;                                       /* DAC output voltage select, bit 3 */
    byte VOSEL4      :1;                                       /* DAC output voltage select, bit 4 */
    byte             :1; 
    byte             :1; 
    byte DACEN       :1;                                       /* DAC enable. When the module is disabled, the DAC is powered down to conserve power */
  } Bits;
  struct {
    byte grpVOSEL :5;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} DAC1CTRLSTR;
extern volatile DAC1CTRLSTR _DAC1CTRL @0x00000019;
#define DAC1CTRL                        _DAC1CTRL.Byte
#define DAC1CTRL_VOSEL0                 _DAC1CTRL.Bits.VOSEL0
#define DAC1CTRL_VOSEL1                 _DAC1CTRL.Bits.VOSEL1
#define DAC1CTRL_VOSEL2                 _DAC1CTRL.Bits.VOSEL2
#define DAC1CTRL_VOSEL3                 _DAC1CTRL.Bits.VOSEL3
#define DAC1CTRL_VOSEL4                 _DAC1CTRL.Bits.VOSEL4
#define DAC1CTRL_DACEN                  _DAC1CTRL.Bits.DACEN
#define DAC1CTRL_VOSEL                  _DAC1CTRL.MergedBits.grpVOSEL

#define DAC1CTRL_VOSEL0_MASK            1U
#define DAC1CTRL_VOSEL1_MASK            2U
#define DAC1CTRL_VOSEL2_MASK            4U
#define DAC1CTRL_VOSEL3_MASK            8U
#define DAC1CTRL_VOSEL4_MASK            16U
#define DAC1CTRL_DACEN_MASK             128U
#define DAC1CTRL_VOSEL_MASK             31U
#define DAC1CTRL_VOSEL_BITNUM           0U


/*** DAC2CTRL - DAC Control Register; 0x0000001A ***/
typedef union {
  byte Byte;
  struct {
    byte VOSEL0      :1;                                       /* DAC output voltage select, bit 0 */
    byte VOSEL1      :1;                                       /* DAC output voltage select, bit 1 */
    byte VOSEL2      :1;                                       /* DAC output voltage select, bit 2 */
    byte VOSEL3      :1;                                       /* DAC output voltage select, bit 3 */
    byte VOSEL4      :1;                                       /* DAC output voltage select, bit 4 */
    byte             :1; 
    byte             :1; 
    byte DACEN       :1;                                       /* DAC enable. When the module is disabled, the DAC is powered down to conserve power */
  } Bits;
  struct {
    byte grpVOSEL :5;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} DAC2CTRLSTR;
extern volatile DAC2CTRLSTR _DAC2CTRL @0x0000001A;
#define DAC2CTRL                        _DAC2CTRL.Byte
#define DAC2CTRL_VOSEL0                 _DAC2CTRL.Bits.VOSEL0
#define DAC2CTRL_VOSEL1                 _DAC2CTRL.Bits.VOSEL1
#define DAC2CTRL_VOSEL2                 _DAC2CTRL.Bits.VOSEL2
#define DAC2CTRL_VOSEL3                 _DAC2CTRL.Bits.VOSEL3
#define DAC2CTRL_VOSEL4                 _DAC2CTRL.Bits.VOSEL4
#define DAC2CTRL_DACEN                  _DAC2CTRL.Bits.DACEN
#define DAC2CTRL_VOSEL                  _DAC2CTRL.MergedBits.grpVOSEL

#define DAC2CTRL_VOSEL0_MASK            1U
#define DAC2CTRL_VOSEL1_MASK            2U
#define DAC2CTRL_VOSEL2_MASK            4U
#define DAC2CTRL_VOSEL3_MASK            8U
#define DAC2CTRL_VOSEL4_MASK            16U
#define DAC2CTRL_DACEN_MASK             128U
#define DAC2CTRL_VOSEL_MASK             31U
#define DAC2CTRL_VOSEL_BITNUM           0U


/*** DAC3CTRL - DAC Control Register; 0x0000001B ***/
typedef union {
  byte Byte;
  struct {
    byte VOSEL0      :1;                                       /* DAC output voltage select, bit 0 */
    byte VOSEL1      :1;                                       /* DAC output voltage select, bit 1 */
    byte VOSEL2      :1;                                       /* DAC output voltage select, bit 2 */
    byte VOSEL3      :1;                                       /* DAC output voltage select, bit 3 */
    byte VOSEL4      :1;                                       /* DAC output voltage select, bit 4 */
    byte             :1; 
    byte             :1; 
    byte DACEN       :1;                                       /* DAC enable. When the module is disabled, the DAC is powered down to conserve power */
  } Bits;
  struct {
    byte grpVOSEL :5;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} DAC3CTRLSTR;
extern volatile DAC3CTRLSTR _DAC3CTRL @0x0000001B;
#define DAC3CTRL                        _DAC3CTRL.Byte
#define DAC3CTRL_VOSEL0                 _DAC3CTRL.Bits.VOSEL0
#define DAC3CTRL_VOSEL1                 _DAC3CTRL.Bits.VOSEL1
#define DAC3CTRL_VOSEL2                 _DAC3CTRL.Bits.VOSEL2
#define DAC3CTRL_VOSEL3                 _DAC3CTRL.Bits.VOSEL3
#define DAC3CTRL_VOSEL4                 _DAC3CTRL.Bits.VOSEL4
#define DAC3CTRL_DACEN                  _DAC3CTRL.Bits.DACEN
#define DAC3CTRL_VOSEL                  _DAC3CTRL.MergedBits.grpVOSEL

#define DAC3CTRL_VOSEL0_MASK            1U
#define DAC3CTRL_VOSEL1_MASK            2U
#define DAC3CTRL_VOSEL2_MASK            4U
#define DAC3CTRL_VOSEL3_MASK            8U
#define DAC3CTRL_VOSEL4_MASK            16U
#define DAC3CTRL_DACEN_MASK             128U
#define DAC3CTRL_VOSEL_MASK             31U
#define DAC3CTRL_VOSEL_BITNUM           0U


/*** KBI2SC - KBI2 Status and Control Register; 0x0000001C ***/
typedef union {
  byte Byte;
  struct {
    byte KBIMOD      :1;                                       /* Keyboard Detection Mode */
    byte KBIE        :1;                                       /* Keyboard Interrupt Enable */
    byte KBACK       :1;                                       /* Keyboard Interrupt Acknowledge */
    byte KBF         :1;                                       /* Keyboard Interrupt Flag */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} KBI2SCSTR;
extern volatile KBI2SCSTR _KBI2SC @0x0000001C;
#define KBI2SC                          _KBI2SC.Byte
#define KBI2SC_KBIMOD                   _KBI2SC.Bits.KBIMOD
#define KBI2SC_KBIE                     _KBI2SC.Bits.KBIE
#define KBI2SC_KBACK                    _KBI2SC.Bits.KBACK
#define KBI2SC_KBF                      _KBI2SC.Bits.KBF

#define KBI2SC_KBIMOD_MASK              1U
#define KBI2SC_KBIE_MASK                2U
#define KBI2SC_KBACK_MASK               4U
#define KBI2SC_KBF_MASK                 8U


/*** KBI2PE - KBI2 Pin Enable Register; 0x0000001D ***/
typedef union {
  byte Byte;
  struct {
    byte KBIPE0      :1;                                       /* Keyboard Pin Enable for KBI Port Bit 0 */
    byte KBIPE1      :1;                                       /* Keyboard Pin Enable for KBI Port Bit 1 */
    byte KBIPE2      :1;                                       /* Keyboard Pin Enable for KBI Port Bit 2 */
    byte KBIPE3      :1;                                       /* Keyboard Pin Enable for KBI Port Bit 3 */
    byte KBIPE4      :1;                                       /* Keyboard Pin Enable for KBI Port Bit 4 */
    byte KBIPE5      :1;                                       /* Keyboard Pin Enable for KBI Port Bit 5 */
    byte KBIPE6      :1;                                       /* Keyboard Pin Enable for KBI Port Bit 6 */
    byte KBIPE7      :1;                                       /* Keyboard Pin Enable for KBI Port Bit 7 */
  } Bits;
} KBI2PESTR;
extern volatile KBI2PESTR _KBI2PE @0x0000001D;
#define KBI2PE                          _KBI2PE.Byte
#define KBI2PE_KBIPE0                   _KBI2PE.Bits.KBIPE0
#define KBI2PE_KBIPE1                   _KBI2PE.Bits.KBIPE1
#define KBI2PE_KBIPE2                   _KBI2PE.Bits.KBIPE2
#define KBI2PE_KBIPE3                   _KBI2PE.Bits.KBIPE3
#define KBI2PE_KBIPE4                   _KBI2PE.Bits.KBIPE4
#define KBI2PE_KBIPE5                   _KBI2PE.Bits.KBIPE5
#define KBI2PE_KBIPE6                   _KBI2PE.Bits.KBIPE6
#define KBI2PE_KBIPE7                   _KBI2PE.Bits.KBIPE7

#define KBI2PE_KBIPE0_MASK              1U
#define KBI2PE_KBIPE1_MASK              2U
#define KBI2PE_KBIPE2_MASK              4U
#define KBI2PE_KBIPE3_MASK              8U
#define KBI2PE_KBIPE4_MASK              16U
#define KBI2PE_KBIPE5_MASK              32U
#define KBI2PE_KBIPE6_MASK              64U
#define KBI2PE_KBIPE7_MASK              128U


/*** KBI2ES - KBI2 Edge Select Register; 0x0000001E ***/
typedef union {
  byte Byte;
  struct {
    byte KBEDG0      :1;                                       /* Keyboard Edge Select Bit 0 */
    byte KBEDG1      :1;                                       /* Keyboard Edge Select Bit 1 */
    byte KBEDG2      :1;                                       /* Keyboard Edge Select Bit 2 */
    byte KBEDG3      :1;                                       /* Keyboard Edge Select Bit 3 */
    byte KBEDG4      :1;                                       /* Keyboard Edge Select Bit 4 */
    byte KBEDG5      :1;                                       /* Keyboard Edge Select Bit 5 */
    byte KBEDG6      :1;                                       /* Keyboard Edge Select Bit 6 */
    byte KBEDG7      :1;                                       /* Keyboard Edge Select Bit 7 */
  } Bits;
} KBI2ESSTR;
extern volatile KBI2ESSTR _KBI2ES @0x0000001E;
#define KBI2ES                          _KBI2ES.Byte
#define KBI2ES_KBEDG0                   _KBI2ES.Bits.KBEDG0
#define KBI2ES_KBEDG1                   _KBI2ES.Bits.KBEDG1
#define KBI2ES_KBEDG2                   _KBI2ES.Bits.KBEDG2
#define KBI2ES_KBEDG3                   _KBI2ES.Bits.KBEDG3
#define KBI2ES_KBEDG4                   _KBI2ES.Bits.KBEDG4
#define KBI2ES_KBEDG5                   _KBI2ES.Bits.KBEDG5
#define KBI2ES_KBEDG6                   _KBI2ES.Bits.KBEDG6
#define KBI2ES_KBEDG7                   _KBI2ES.Bits.KBEDG7

#define KBI2ES_KBEDG0_MASK              1U
#define KBI2ES_KBEDG1_MASK              2U
#define KBI2ES_KBEDG2_MASK              4U
#define KBI2ES_KBEDG3_MASK              8U
#define KBI2ES_KBEDG4_MASK              16U
#define KBI2ES_KBEDG5_MASK              32U
#define KBI2ES_KBEDG6_MASK              64U
#define KBI2ES_KBEDG7_MASK              128U


/*** IICA1 - IIC Address Register; 0x00000020 ***/
typedef union {
  byte Byte;
  union { /* Several registers at the same address */
    /*** IICA1 - IIC Address Register; Several registers at the same address ***/
    union {
      struct {
        byte             :1; 
        byte AD1         :1;                                       /* Slave Address Bit 1 */
        byte AD2         :1;                                       /* Slave Address Bit 2 */
        byte AD3         :1;                                       /* Slave Address Bit 3 */
        byte AD4         :1;                                       /* Slave Address Bit 4 */
        byte AD5         :1;                                       /* Slave Address Bit 5 */
        byte AD6         :1;                                       /* Slave Address Bit 6 */
        byte AD7         :1;                                       /* Slave Address Bit 7 */
      } Bits;
      struct {
        byte     :1;
        byte grpAD_1 :7;
      } MergedBits;
    } IICA1STR;
    #define IICA1                       _IICA1.Byte
    #define IICA1_AD1                   _IICA1.SameAddr_STR.IICA1STR.Bits.AD1
    #define IICA1_AD2                   _IICA1.SameAddr_STR.IICA1STR.Bits.AD2
    #define IICA1_AD3                   _IICA1.SameAddr_STR.IICA1STR.Bits.AD3
    #define IICA1_AD4                   _IICA1.SameAddr_STR.IICA1STR.Bits.AD4
    #define IICA1_AD5                   _IICA1.SameAddr_STR.IICA1STR.Bits.AD5
    #define IICA1_AD6                   _IICA1.SameAddr_STR.IICA1STR.Bits.AD6
    #define IICA1_AD7                   _IICA1.SameAddr_STR.IICA1STR.Bits.AD7
    #define IICA1_AD_1                  _IICA1.SameAddr_STR.IICA1STR.MergedBits.grpAD_1
    #define IICA1_AD                    IICA1_AD_1
    
    #define IICA1_AD1_MASK              2U
    #define IICA1_AD2_MASK              4U
    #define IICA1_AD3_MASK              8U
    #define IICA1_AD4_MASK              16U
    #define IICA1_AD5_MASK              32U
    #define IICA1_AD6_MASK              64U
    #define IICA1_AD7_MASK              128U
    #define IICA1_AD_1_MASK             254U
    #define IICA1_AD_1_BITNUM           1U
    
    /*** IICA - IIC Address Register; Several registers at the same address ***/
    union {
      struct {
        byte             :1; 
        byte AD1         :1;                                       /* Slave Address Bit 1 */
        byte AD2         :1;                                       /* Slave Address Bit 2 */
        byte AD3         :1;                                       /* Slave Address Bit 3 */
        byte AD4         :1;                                       /* Slave Address Bit 4 */
        byte AD5         :1;                                       /* Slave Address Bit 5 */
        byte AD6         :1;                                       /* Slave Address Bit 6 */
        byte AD7         :1;                                       /* Slave Address Bit 7 */
      } Bits;
      struct {
        byte     :1;
        byte grpAD_1 :7;
      } MergedBits;
    } IICASTR;
    #define IICA                        _IICA1.Byte
    #define IICA_AD1                    _IICA1.SameAddr_STR.IICASTR.Bits.AD1
    #define IICA_AD2                    _IICA1.SameAddr_STR.IICASTR.Bits.AD2
    #define IICA_AD3                    _IICA1.SameAddr_STR.IICASTR.Bits.AD3
    #define IICA_AD4                    _IICA1.SameAddr_STR.IICASTR.Bits.AD4
    #define IICA_AD5                    _IICA1.SameAddr_STR.IICASTR.Bits.AD5
    #define IICA_AD6                    _IICA1.SameAddr_STR.IICASTR.Bits.AD6
    #define IICA_AD7                    _IICA1.SameAddr_STR.IICASTR.Bits.AD7
    #define IICA_AD_1                   _IICA1.SameAddr_STR.IICASTR.MergedBits.grpAD_1
    #define IICA_AD                     IICA_AD_1
    
    #define IICA_AD1_MASK               2U
    #define IICA_AD2_MASK               4U
    #define IICA_AD3_MASK               8U
    #define IICA_AD4_MASK               16U
    #define IICA_AD5_MASK               32U
    #define IICA_AD6_MASK               64U
    #define IICA_AD7_MASK               128U
    #define IICA_AD_1_MASK              254U
    #define IICA_AD_1_BITNUM            1U
    
  } SameAddr_STR; /*Several registers at the same address */

} IICA1STR;
extern volatile IICA1STR _IICA1 @0x00000020;


/*** IICF - IIC Frequency Divider Register; 0x00000021 ***/
typedef union {
  byte Byte;
  struct {
    byte ICR0        :1;                                       /* IIC Clock Rate Bit 0 */
    byte ICR1        :1;                                       /* IIC Clock Rate Bit 1 */
    byte ICR2        :1;                                       /* IIC Clock Rate Bit 2 */
    byte ICR3        :1;                                       /* IIC Clock Rate Bit 3 */
    byte ICR4        :1;                                       /* IIC Clock Rate Bit 4 */
    byte ICR5        :1;                                       /* IIC Clock Rate Bit 5 */
    byte MULT0       :1;                                       /* Multiplier Factor Bit 0 */
    byte MULT1       :1;                                       /* Multiplier Factor Bit 1 */
  } Bits;
  struct {
    byte grpICR  :6;
    byte grpMULT :2;
  } MergedBits;
} IICFSTR;
extern volatile IICFSTR _IICF @0x00000021;
#define IICF                            _IICF.Byte
#define IICF_ICR0                       _IICF.Bits.ICR0
#define IICF_ICR1                       _IICF.Bits.ICR1
#define IICF_ICR2                       _IICF.Bits.ICR2
#define IICF_ICR3                       _IICF.Bits.ICR3
#define IICF_ICR4                       _IICF.Bits.ICR4
#define IICF_ICR5                       _IICF.Bits.ICR5
#define IICF_MULT0                      _IICF.Bits.MULT0
#define IICF_MULT1                      _IICF.Bits.MULT1
#define IICF_ICR                        _IICF.MergedBits.grpICR
#define IICF_MULT                       _IICF.MergedBits.grpMULT

#define IICF_ICR0_MASK                  1U
#define IICF_ICR1_MASK                  2U
#define IICF_ICR2_MASK                  4U
#define IICF_ICR3_MASK                  8U
#define IICF_ICR4_MASK                  16U
#define IICF_ICR5_MASK                  32U
#define IICF_MULT0_MASK                 64U
#define IICF_MULT1_MASK                 128U
#define IICF_ICR_MASK                   63U
#define IICF_ICR_BITNUM                 0U
#define IICF_MULT_MASK                  192U
#define IICF_MULT_BITNUM                6U


/*** IICC1 - IIC Control Register 1; 0x00000022 ***/
typedef union {
  byte Byte;
  union { /* Several registers at the same address */
    /*** IICC1 - IIC Control Register 1; Several registers at the same address ***/
    union {
      struct {
        byte             :1; 
        byte             :1; 
        byte RSTA        :1;                                       /* Repeat START */
        byte TXAK        :1;                                       /* Transmit Acknowledge Enable */
        byte TX          :1;                                       /* Transmit Mode Select */
        byte MST         :1;                                       /* Master Mode Select */
        byte IICIE       :1;                                       /* IIC Interrupt Enable */
        byte IICEN       :1;                                       /* IIC Enable */
      } Bits;
    } IICC1STR;
    #define IICC1                       _IICC1.Byte
    #define IICC1_RSTA                  _IICC1.SameAddr_STR.IICC1STR.Bits.RSTA
    #define IICC1_TXAK                  _IICC1.SameAddr_STR.IICC1STR.Bits.TXAK
    #define IICC1_TX                    _IICC1.SameAddr_STR.IICC1STR.Bits.TX
    #define IICC1_MST                   _IICC1.SameAddr_STR.IICC1STR.Bits.MST
    #define IICC1_IICIE                 _IICC1.SameAddr_STR.IICC1STR.Bits.IICIE
    #define IICC1_IICEN                 _IICC1.SameAddr_STR.IICC1STR.Bits.IICEN
    
    #define IICC1_RSTA_MASK             4U
    #define IICC1_TXAK_MASK             8U
    #define IICC1_TX_MASK               16U
    #define IICC1_MST_MASK              32U
    #define IICC1_IICIE_MASK            64U
    #define IICC1_IICEN_MASK            128U
    
    /*** IICC - IIC Control Register; Several registers at the same address ***/
    union {
      struct {
        byte             :1; 
        byte             :1; 
        byte RSTA        :1;                                       /* Repeat START */
        byte TXAK        :1;                                       /* Transmit Acknowledge Enable */
        byte TX          :1;                                       /* Transmit Mode Select */
        byte MST         :1;                                       /* Master Mode Select */
        byte IICIE       :1;                                       /* IIC Interrupt Enable */
        byte IICEN       :1;                                       /* IIC Enable */
      } Bits;
    } IICCSTR;
    #define IICC                        _IICC1.Byte
    #define IICC_RSTA                   _IICC1.SameAddr_STR.IICCSTR.Bits.RSTA
    #define IICC_TXAK                   _IICC1.SameAddr_STR.IICCSTR.Bits.TXAK
    #define IICC_TX                     _IICC1.SameAddr_STR.IICCSTR.Bits.TX
    #define IICC_MST                    _IICC1.SameAddr_STR.IICCSTR.Bits.MST
    #define IICC_IICIE                  _IICC1.SameAddr_STR.IICCSTR.Bits.IICIE
    #define IICC_IICEN                  _IICC1.SameAddr_STR.IICCSTR.Bits.IICEN
    
    #define IICC_RSTA_MASK              4U
    #define IICC_TXAK_MASK              8U
    #define IICC_TX_MASK                16U
    #define IICC_MST_MASK               32U
    #define IICC_IICIE_MASK             64U
    #define IICC_IICEN_MASK             128U
    
  } SameAddr_STR; /*Several registers at the same address */

} IICC1STR;
extern volatile IICC1STR _IICC1 @0x00000022;


/*** IICS - IIC Status Register; 0x00000023 ***/
typedef union {
  byte Byte;
  struct {
    byte RXAK        :1;                                       /* Receive Acknowledge */
    byte IICIF       :1;                                       /* IIC Interrupt Flag */
    byte SRW         :1;                                       /* Slave Read/Write */
    byte             :1; 
    byte ARBL        :1;                                       /* Arbitration Lost */
    byte BUSY        :1;                                       /* Bus Busy */
    byte IAAS        :1;                                       /* Addressed as a Slave */
    byte TCF         :1;                                       /* Transfer Complete Flag */
  } Bits;
} IICSSTR;
extern volatile IICSSTR _IICS @0x00000023;
#define IICS                            _IICS.Byte
#define IICS_RXAK                       _IICS.Bits.RXAK
#define IICS_IICIF                      _IICS.Bits.IICIF
#define IICS_SRW                        _IICS.Bits.SRW
#define IICS_ARBL                       _IICS.Bits.ARBL
#define IICS_BUSY                       _IICS.Bits.BUSY
#define IICS_IAAS                       _IICS.Bits.IAAS
#define IICS_TCF                        _IICS.Bits.TCF

#define IICS_RXAK_MASK                  1U
#define IICS_IICIF_MASK                 2U
#define IICS_SRW_MASK                   4U
#define IICS_ARBL_MASK                  16U
#define IICS_BUSY_MASK                  32U
#define IICS_IAAS_MASK                  64U
#define IICS_TCF_MASK                   128U


/*** IICD - IIC Data I/O Register; 0x00000024 ***/
typedef union {
  byte Byte;
  struct {
    byte DATA0       :1;                                       /* IIC Data Bit 0 */
    byte DATA1       :1;                                       /* IIC Data Bit 1 */
    byte DATA2       :1;                                       /* IIC Data Bit 2 */
    byte DATA3       :1;                                       /* IIC Data Bit 3 */
    byte DATA4       :1;                                       /* IIC Data Bit 4 */
    byte DATA5       :1;                                       /* IIC Data Bit 5 */
    byte DATA6       :1;                                       /* IIC Data Bit 6 */
    byte DATA7       :1;                                       /* IIC Data Bit 7 */
  } Bits;
} IICDSTR;
extern volatile IICDSTR _IICD @0x00000024;
#define IICD                            _IICD.Byte
#define IICD_DATA0                      _IICD.Bits.DATA0
#define IICD_DATA1                      _IICD.Bits.DATA1
#define IICD_DATA2                      _IICD.Bits.DATA2
#define IICD_DATA3                      _IICD.Bits.DATA3
#define IICD_DATA4                      _IICD.Bits.DATA4
#define IICD_DATA5                      _IICD.Bits.DATA5
#define IICD_DATA6                      _IICD.Bits.DATA6
#define IICD_DATA7                      _IICD.Bits.DATA7

#define IICD_DATA0_MASK                 1U
#define IICD_DATA1_MASK                 2U
#define IICD_DATA2_MASK                 4U
#define IICD_DATA3_MASK                 8U
#define IICD_DATA4_MASK                 16U
#define IICD_DATA5_MASK                 32U
#define IICD_DATA6_MASK                 64U
#define IICD_DATA7_MASK                 128U


/*** IICC2 - IIC Control Register 2; 0x00000025 ***/
typedef union {
  byte Byte;
  struct {
    byte AD8         :1;                                       /* Slave Address Bit 8 */
    byte AD9         :1;                                       /* Slave Address Bit 9 */
    byte AD10        :1;                                       /* Slave Address Bit 10 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte ADEXT       :1;                                       /* Address Extension */
    byte GCAEN       :1;                                       /* General Call Address Enable */
  } Bits;
  struct {
    byte grpAD_8 :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} IICC2STR;
extern volatile IICC2STR _IICC2 @0x00000025;
#define IICC2                           _IICC2.Byte
#define IICC2_AD8                       _IICC2.Bits.AD8
#define IICC2_AD9                       _IICC2.Bits.AD9
#define IICC2_AD10                      _IICC2.Bits.AD10
#define IICC2_ADEXT                     _IICC2.Bits.ADEXT
#define IICC2_GCAEN                     _IICC2.Bits.GCAEN
#define IICC2_AD_8                      _IICC2.MergedBits.grpAD_8
#define IICC2_AD                        IICC2_AD_8

#define IICC2_AD8_MASK                  1U
#define IICC2_AD9_MASK                  2U
#define IICC2_AD10_MASK                 4U
#define IICC2_ADEXT_MASK                64U
#define IICC2_GCAEN_MASK                128U
#define IICC2_AD_8_MASK                 7U
#define IICC2_AD_8_BITNUM               0U


/*** IICSMB - SMBus Control and Status Register; 0x00000026 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte SHTF        :1;                                       /* SCL High Timeout Flag */
    byte SLTF        :1;                                       /* SCL Low Timeout Flag */
    byte TCKSEL      :1;                                       /* Time Out Counter Clock Select */
    byte SIICAEN     :1;                                       /* Second IIC Address Enable */
    byte ALERTEN     :1;                                       /* SMBus Alert Response Address Enable */
    byte FACK        :1;                                       /* Fast NACK/ACK enable */
  } Bits;
} IICSMBSTR;
extern volatile IICSMBSTR _IICSMB @0x00000026;
#define IICSMB                          _IICSMB.Byte
#define IICSMB_SHTF                     _IICSMB.Bits.SHTF
#define IICSMB_SLTF                     _IICSMB.Bits.SLTF
#define IICSMB_TCKSEL                   _IICSMB.Bits.TCKSEL
#define IICSMB_SIICAEN                  _IICSMB.Bits.SIICAEN
#define IICSMB_ALERTEN                  _IICSMB.Bits.ALERTEN
#define IICSMB_FACK                     _IICSMB.Bits.FACK

#define IICSMB_SHTF_MASK                4U
#define IICSMB_SLTF_MASK                8U
#define IICSMB_TCKSEL_MASK              16U
#define IICSMB_SIICAEN_MASK             32U
#define IICSMB_ALERTEN_MASK             64U
#define IICSMB_FACK_MASK                128U


/*** IICA2 - IIC Address Register 2; 0x00000027 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte SAD1        :1;                                       /* SMBus Address Bit 1 */
    byte SAD2        :1;                                       /* SMBus Address Bit 2 */
    byte SAD3        :1;                                       /* SMBus Address Bit 3 */
    byte SAD4        :1;                                       /* SMBus Address Bit 4 */
    byte SAD5        :1;                                       /* SMBus Address Bit 5 */
    byte SAD6        :1;                                       /* SMBus Address Bit 6 */
    byte SAD7        :1;                                       /* SMBus Address Bit 7 */
  } Bits;
  struct {
    byte         :1;
    byte grpSAD_1 :7;
  } MergedBits;
} IICA2STR;
extern volatile IICA2STR _IICA2 @0x00000027;
#define IICA2                           _IICA2.Byte
#define IICA2_SAD1                      _IICA2.Bits.SAD1
#define IICA2_SAD2                      _IICA2.Bits.SAD2
#define IICA2_SAD3                      _IICA2.Bits.SAD3
#define IICA2_SAD4                      _IICA2.Bits.SAD4
#define IICA2_SAD5                      _IICA2.Bits.SAD5
#define IICA2_SAD6                      _IICA2.Bits.SAD6
#define IICA2_SAD7                      _IICA2.Bits.SAD7
#define IICA2_SAD_1                     _IICA2.MergedBits.grpSAD_1
#define IICA2_SAD                       IICA2_SAD_1

#define IICA2_SAD1_MASK                 2U
#define IICA2_SAD2_MASK                 4U
#define IICA2_SAD3_MASK                 8U
#define IICA2_SAD4_MASK                 16U
#define IICA2_SAD5_MASK                 32U
#define IICA2_SAD6_MASK                 64U
#define IICA2_SAD7_MASK                 128U
#define IICA2_SAD_1_MASK                254U
#define IICA2_SAD_1_BITNUM              1U


/*** IICSLT - IIC SCL Low Time Out register; 0x00000028 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** IICSLTH - IIC SCL Low Time Out register - High byte; 0x00000028 ***/
    union {
      byte Byte;
      struct {
        byte SSLT8       :1;                                       /* SCL Low Time Out Bit 8 */
        byte SSLT9       :1;                                       /* SCL Low Time Out Bit 9 */
        byte SSLT10      :1;                                       /* SCL Low Time Out Bit 10 */
        byte SSLT11      :1;                                       /* SCL Low Time Out Bit 11 */
        byte SSLT12      :1;                                       /* SCL Low Time Out Bit 12 */
        byte SSLT13      :1;                                       /* SCL Low Time Out Bit 13 */
        byte SSLT14      :1;                                       /* SCL Low Time Out Bit 14 */
        byte SSLT15      :1;                                       /* SCL Low Time Out Bit 15 */
      } Bits;
    } IICSLTHSTR;
    #define IICSLTH                     _IICSLT.Overlap_STR.IICSLTHSTR.Byte
    #define IICSLTH_SSLT8               _IICSLT.Overlap_STR.IICSLTHSTR.Bits.SSLT8
    #define IICSLTH_SSLT9               _IICSLT.Overlap_STR.IICSLTHSTR.Bits.SSLT9
    #define IICSLTH_SSLT10              _IICSLT.Overlap_STR.IICSLTHSTR.Bits.SSLT10
    #define IICSLTH_SSLT11              _IICSLT.Overlap_STR.IICSLTHSTR.Bits.SSLT11
    #define IICSLTH_SSLT12              _IICSLT.Overlap_STR.IICSLTHSTR.Bits.SSLT12
    #define IICSLTH_SSLT13              _IICSLT.Overlap_STR.IICSLTHSTR.Bits.SSLT13
    #define IICSLTH_SSLT14              _IICSLT.Overlap_STR.IICSLTHSTR.Bits.SSLT14
    #define IICSLTH_SSLT15              _IICSLT.Overlap_STR.IICSLTHSTR.Bits.SSLT15
    
    #define IICSLTH_SSLT8_MASK          1U
    #define IICSLTH_SSLT9_MASK          2U
    #define IICSLTH_SSLT10_MASK         4U
    #define IICSLTH_SSLT11_MASK         8U
    #define IICSLTH_SSLT12_MASK         16U
    #define IICSLTH_SSLT13_MASK         32U
    #define IICSLTH_SSLT14_MASK         64U
    #define IICSLTH_SSLT15_MASK         128U
    

    /*** IICSLTL - IIC SCL Low Time Out register - Low byte; 0x00000029 ***/
    union {
      byte Byte;
      struct {
        byte SSLT0       :1;                                       /* SCL Low Time Out Bits, bit 0 */
        byte SSLT1       :1;                                       /* SCL Low Time Out Bits, bit 1 */
        byte SSLT2       :1;                                       /* SCL Low Time Out Bits, bit 2 */
        byte SSLT3       :1;                                       /* SCL Low Time Out Bits, bit 3 */
        byte SSLT4       :1;                                       /* SCL Low Time Out Bits, bit 4 */
        byte SSLT5       :1;                                       /* SCL Low Time Out Bits, bit 5 */
        byte SSLT6       :1;                                       /* SCL Low Time Out Bits, bit 6 */
        byte SSLT7       :1;                                       /* SCL Low Time Out Bits, bit 7 */
      } Bits;
    } IICSLTLSTR;
    #define IICSLTL                     _IICSLT.Overlap_STR.IICSLTLSTR.Byte
    #define IICSLTL_SSLT0               _IICSLT.Overlap_STR.IICSLTLSTR.Bits.SSLT0
    #define IICSLTL_SSLT1               _IICSLT.Overlap_STR.IICSLTLSTR.Bits.SSLT1
    #define IICSLTL_SSLT2               _IICSLT.Overlap_STR.IICSLTLSTR.Bits.SSLT2
    #define IICSLTL_SSLT3               _IICSLT.Overlap_STR.IICSLTLSTR.Bits.SSLT3
    #define IICSLTL_SSLT4               _IICSLT.Overlap_STR.IICSLTLSTR.Bits.SSLT4
    #define IICSLTL_SSLT5               _IICSLT.Overlap_STR.IICSLTLSTR.Bits.SSLT5
    #define IICSLTL_SSLT6               _IICSLT.Overlap_STR.IICSLTLSTR.Bits.SSLT6
    #define IICSLTL_SSLT7               _IICSLT.Overlap_STR.IICSLTLSTR.Bits.SSLT7
    
    #define IICSLTL_SSLT0_MASK          1U
    #define IICSLTL_SSLT1_MASK          2U
    #define IICSLTL_SSLT2_MASK          4U
    #define IICSLTL_SSLT3_MASK          8U
    #define IICSLTL_SSLT4_MASK          16U
    #define IICSLTL_SSLT5_MASK          32U
    #define IICSLTL_SSLT6_MASK          64U
    #define IICSLTL_SSLT7_MASK          128U
    
  } Overlap_STR;

} IICSLTSTR;
extern volatile IICSLTSTR _IICSLT @0x00000028;
#define IICSLT                          _IICSLT.Word


/*** IICFLT - IIC Filter register; 0x0000002A ***/
typedef union {
  byte Byte;
  struct {
    byte FLT0        :1;                                       /* Filter value bit 0 */
    byte FLT1        :1;                                       /* Filter value bit 1 */
    byte FLT2        :1;                                       /* Filter value bit 2 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpFLT  :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} IICFLTSTR;
extern volatile IICFLTSTR _IICFLT @0x0000002A;
#define IICFLT                          _IICFLT.Byte
#define IICFLT_FLT0                     _IICFLT.Bits.FLT0
#define IICFLT_FLT1                     _IICFLT.Bits.FLT1
#define IICFLT_FLT2                     _IICFLT.Bits.FLT2
#define IICFLT_FLT                      _IICFLT.MergedBits.grpFLT

#define IICFLT_FLT0_MASK                1U
#define IICFLT_FLT1_MASK                2U
#define IICFLT_FLT2_MASK                4U
#define IICFLT_FLT_MASK                 7U
#define IICFLT_FLT_BITNUM               0U


/*** KBI3SC - KBI3 Status and Control Register; 0x0000002C ***/
typedef union {
  byte Byte;
  struct {
    byte KBIMOD      :1;                                       /* Keyboard Detection Mode */
    byte KBIE        :1;                                       /* Keyboard Interrupt Enable */
    byte KBACK       :1;                                       /* Keyboard Interrupt Acknowledge */
    byte KBF         :1;                                       /* Keyboard Interrupt Flag */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} KBI3SCSTR;
extern volatile KBI3SCSTR _KBI3SC @0x0000002C;
#define KBI3SC                          _KBI3SC.Byte
#define KBI3SC_KBIMOD                   _KBI3SC.Bits.KBIMOD
#define KBI3SC_KBIE                     _KBI3SC.Bits.KBIE
#define KBI3SC_KBACK                    _KBI3SC.Bits.KBACK
#define KBI3SC_KBF                      _KBI3SC.Bits.KBF

#define KBI3SC_KBIMOD_MASK              1U
#define KBI3SC_KBIE_MASK                2U
#define KBI3SC_KBACK_MASK               4U
#define KBI3SC_KBF_MASK                 8U


/*** KBI3PE - KBI3 Pin Enable Register; 0x0000002D ***/
typedef union {
  byte Byte;
  struct {
    byte KBIPE0      :1;                                       /* Keyboard Pin Enable for KBI Port Bit 0 */
    byte KBIPE1      :1;                                       /* Keyboard Pin Enable for KBI Port Bit 1 */
    byte KBIPE2      :1;                                       /* Keyboard Pin Enable for KBI Port Bit 2 */
    byte KBIPE3      :1;                                       /* Keyboard Pin Enable for KBI Port Bit 3 */
    byte KBIPE4      :1;                                       /* Keyboard Pin Enable for KBI Port Bit 4 */
    byte KBIPE5      :1;                                       /* Keyboard Pin Enable for KBI Port Bit 5 */
    byte KBIPE6      :1;                                       /* Keyboard Pin Enable for KBI Port Bit 6 */
    byte KBIPE7      :1;                                       /* Keyboard Pin Enable for KBI Port Bit 7 */
  } Bits;
} KBI3PESTR;
extern volatile KBI3PESTR _KBI3PE @0x0000002D;
#define KBI3PE                          _KBI3PE.Byte
#define KBI3PE_KBIPE0                   _KBI3PE.Bits.KBIPE0
#define KBI3PE_KBIPE1                   _KBI3PE.Bits.KBIPE1
#define KBI3PE_KBIPE2                   _KBI3PE.Bits.KBIPE2
#define KBI3PE_KBIPE3                   _KBI3PE.Bits.KBIPE3
#define KBI3PE_KBIPE4                   _KBI3PE.Bits.KBIPE4
#define KBI3PE_KBIPE5                   _KBI3PE.Bits.KBIPE5
#define KBI3PE_KBIPE6                   _KBI3PE.Bits.KBIPE6
#define KBI3PE_KBIPE7                   _KBI3PE.Bits.KBIPE7

#define KBI3PE_KBIPE0_MASK              1U
#define KBI3PE_KBIPE1_MASK              2U
#define KBI3PE_KBIPE2_MASK              4U
#define KBI3PE_KBIPE3_MASK              8U
#define KBI3PE_KBIPE4_MASK              16U
#define KBI3PE_KBIPE5_MASK              32U
#define KBI3PE_KBIPE6_MASK              64U
#define KBI3PE_KBIPE7_MASK              128U


/*** KBI3ES - KBI3 Edge Select Register; 0x0000002E ***/
typedef union {
  byte Byte;
  struct {
    byte KBEDG0      :1;                                       /* Keyboard Edge Select Bit 0 */
    byte KBEDG1      :1;                                       /* Keyboard Edge Select Bit 1 */
    byte KBEDG2      :1;                                       /* Keyboard Edge Select Bit 2 */
    byte KBEDG3      :1;                                       /* Keyboard Edge Select Bit 3 */
    byte KBEDG4      :1;                                       /* Keyboard Edge Select Bit 4 */
    byte KBEDG5      :1;                                       /* Keyboard Edge Select Bit 5 */
    byte KBEDG6      :1;                                       /* Keyboard Edge Select Bit 6 */
    byte KBEDG7      :1;                                       /* Keyboard Edge Select Bit 7 */
  } Bits;
} KBI3ESSTR;
extern volatile KBI3ESSTR _KBI3ES @0x0000002E;
#define KBI3ES                          _KBI3ES.Byte
#define KBI3ES_KBEDG0                   _KBI3ES.Bits.KBEDG0
#define KBI3ES_KBEDG1                   _KBI3ES.Bits.KBEDG1
#define KBI3ES_KBEDG2                   _KBI3ES.Bits.KBEDG2
#define KBI3ES_KBEDG3                   _KBI3ES.Bits.KBEDG3
#define KBI3ES_KBEDG4                   _KBI3ES.Bits.KBEDG4
#define KBI3ES_KBEDG5                   _KBI3ES.Bits.KBEDG5
#define KBI3ES_KBEDG6                   _KBI3ES.Bits.KBEDG6
#define KBI3ES_KBEDG7                   _KBI3ES.Bits.KBEDG7

#define KBI3ES_KBEDG0_MASK              1U
#define KBI3ES_KBEDG1_MASK              2U
#define KBI3ES_KBEDG2_MASK              4U
#define KBI3ES_KBEDG3_MASK              8U
#define KBI3ES_KBEDG4_MASK              16U
#define KBI3ES_KBEDG5_MASK              32U
#define KBI3ES_KBEDG6_MASK              64U
#define KBI3ES_KBEDG7_MASK              128U


/*** FTM1SC - FTM1 Status and Control Register; 0x00000030 ***/
typedef union {
  byte Byte;
  struct {
    byte PS0         :1;                                       /* Prescale Divisor Select Bit 0 */
    byte PS1         :1;                                       /* Prescale Divisor Select Bit 1 */
    byte PS2         :1;                                       /* Prescale Divisor Select Bit 2 */
    byte CLKSA       :1;                                       /* Clock Source Select A */
    byte CLKSB       :1;                                       /* Clock Source Select B */
    byte CPWMS       :1;                                       /* Center-Aligned PWM Select */
    byte TOIE        :1;                                       /* Timer Overflow Interrupt Enable */
    byte TOF         :1;                                       /* Timer Overflow Flag */
  } Bits;
  struct {
    byte grpPS   :3;
    byte grpCLKSx :2;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} FTM1SCSTR;
extern volatile FTM1SCSTR _FTM1SC @0x00000030;
#define FTM1SC                          _FTM1SC.Byte
#define FTM1SC_PS0                      _FTM1SC.Bits.PS0
#define FTM1SC_PS1                      _FTM1SC.Bits.PS1
#define FTM1SC_PS2                      _FTM1SC.Bits.PS2
#define FTM1SC_CLKSA                    _FTM1SC.Bits.CLKSA
#define FTM1SC_CLKSB                    _FTM1SC.Bits.CLKSB
#define FTM1SC_CPWMS                    _FTM1SC.Bits.CPWMS
#define FTM1SC_TOIE                     _FTM1SC.Bits.TOIE
#define FTM1SC_TOF                      _FTM1SC.Bits.TOF
#define FTM1SC_PS                       _FTM1SC.MergedBits.grpPS
#define FTM1SC_CLKSx                    _FTM1SC.MergedBits.grpCLKSx

#define FTM1SC_PS0_MASK                 1U
#define FTM1SC_PS1_MASK                 2U
#define FTM1SC_PS2_MASK                 4U
#define FTM1SC_CLKSA_MASK               8U
#define FTM1SC_CLKSB_MASK               16U
#define FTM1SC_CPWMS_MASK               32U
#define FTM1SC_TOIE_MASK                64U
#define FTM1SC_TOF_MASK                 128U
#define FTM1SC_PS_MASK                  7U
#define FTM1SC_PS_BITNUM                0U
#define FTM1SC_CLKSx_MASK               24U
#define FTM1SC_CLKSx_BITNUM             3U


/*** FTM1CNT - FTM1 Timer Counter Register; 0x00000031 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** FTM1CNTH - FTM1 Timer Counter Register High; 0x00000031 ***/
    union {
      byte Byte;
    } FTM1CNTHSTR;
    #define FTM1CNTH                    _FTM1CNT.Overlap_STR.FTM1CNTHSTR.Byte
    

    /*** FTM1CNTL - FTM1 Timer Counter Register Low; 0x00000032 ***/
    union {
      byte Byte;
    } FTM1CNTLSTR;
    #define FTM1CNTL                    _FTM1CNT.Overlap_STR.FTM1CNTLSTR.Byte
    
  } Overlap_STR;

} FTM1CNTSTR;
extern volatile FTM1CNTSTR _FTM1CNT @0x00000031;
#define FTM1CNT                         _FTM1CNT.Word


/*** FTM1MOD - FTM1 Timer Counter Modulo Register; 0x00000033 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** FTM1MODH - FTM1 Timer Counter Modulo Register High; 0x00000033 ***/
    union {
      byte Byte;
    } FTM1MODHSTR;
    #define FTM1MODH                    _FTM1MOD.Overlap_STR.FTM1MODHSTR.Byte
    

    /*** FTM1MODL - FTM1 Timer Counter Modulo Register Low; 0x00000034 ***/
    union {
      byte Byte;
    } FTM1MODLSTR;
    #define FTM1MODL                    _FTM1MOD.Overlap_STR.FTM1MODLSTR.Byte
    
  } Overlap_STR;

} FTM1MODSTR;
extern volatile FTM1MODSTR _FTM1MOD @0x00000033;
#define FTM1MOD                         _FTM1MOD.Word


/*** FTM1C0SC - FTM1 Timer Channel 0 Status and Control Register; 0x00000035 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELS0A       :1;                                       /* Edge/Level Select Bit A */
    byte ELS0B       :1;                                       /* Edge/Level Select Bit B */
    byte MS0A        :1;                                       /* Mode Select A for FTM1 Channel 0 */
    byte MS0B        :1;                                       /* Mode Select B for FTM1 Channel 0 */
    byte CH0IE       :1;                                       /* Channel 0 Interrupt Enable */
    byte CH0F        :1;                                       /* Channel 0 Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELS0x :2;
    byte grpMS0x :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} FTM1C0SCSTR;
extern volatile FTM1C0SCSTR _FTM1C0SC @0x00000035;
#define FTM1C0SC                        _FTM1C0SC.Byte
#define FTM1C0SC_ELS0A                  _FTM1C0SC.Bits.ELS0A
#define FTM1C0SC_ELS0B                  _FTM1C0SC.Bits.ELS0B
#define FTM1C0SC_MS0A                   _FTM1C0SC.Bits.MS0A
#define FTM1C0SC_MS0B                   _FTM1C0SC.Bits.MS0B
#define FTM1C0SC_CH0IE                  _FTM1C0SC.Bits.CH0IE
#define FTM1C0SC_CH0F                   _FTM1C0SC.Bits.CH0F
#define FTM1C0SC_ELS0x                  _FTM1C0SC.MergedBits.grpELS0x
#define FTM1C0SC_MS0x                   _FTM1C0SC.MergedBits.grpMS0x

#define FTM1C0SC_ELS0A_MASK             4U
#define FTM1C0SC_ELS0B_MASK             8U
#define FTM1C0SC_MS0A_MASK              16U
#define FTM1C0SC_MS0B_MASK              32U
#define FTM1C0SC_CH0IE_MASK             64U
#define FTM1C0SC_CH0F_MASK              128U
#define FTM1C0SC_ELS0x_MASK             12U
#define FTM1C0SC_ELS0x_BITNUM           2U
#define FTM1C0SC_MS0x_MASK              48U
#define FTM1C0SC_MS0x_BITNUM            4U


/*** FTM1C0V - FTM1 Timer Channel 0 Value Register; 0x00000036 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** FTM1C0VH - FTM1 Timer Channel 0 Value Register High; 0x00000036 ***/
    union {
      byte Byte;
    } FTM1C0VHSTR;
    #define FTM1C0VH                    _FTM1C0V.Overlap_STR.FTM1C0VHSTR.Byte
    

    /*** FTM1C0VL - FTM1 Timer Channel 0 Value Register Low; 0x00000037 ***/
    union {
      byte Byte;
    } FTM1C0VLSTR;
    #define FTM1C0VL                    _FTM1C0V.Overlap_STR.FTM1C0VLSTR.Byte
    
  } Overlap_STR;

} FTM1C0VSTR;
extern volatile FTM1C0VSTR _FTM1C0V @0x00000036;
#define FTM1C0V                         _FTM1C0V.Word


/*** FTM1C1SC - FTM1 Timer Channel 1 Status and Control Register; 0x00000038 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELS1A       :1;                                       /* Edge/Level Select Bit A */
    byte ELS1B       :1;                                       /* Edge/Level Select Bit B */
    byte MS1A        :1;                                       /* Mode Select A for FTM1 Channel 1 */
    byte MS1B        :1;                                       /* Mode Select B for FTM1 Channel 1 */
    byte CH1IE       :1;                                       /* Channel 1 Interrupt Enable */
    byte CH1F        :1;                                       /* Channel 1 Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELS1x :2;
    byte grpMS1x :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} FTM1C1SCSTR;
extern volatile FTM1C1SCSTR _FTM1C1SC @0x00000038;
#define FTM1C1SC                        _FTM1C1SC.Byte
#define FTM1C1SC_ELS1A                  _FTM1C1SC.Bits.ELS1A
#define FTM1C1SC_ELS1B                  _FTM1C1SC.Bits.ELS1B
#define FTM1C1SC_MS1A                   _FTM1C1SC.Bits.MS1A
#define FTM1C1SC_MS1B                   _FTM1C1SC.Bits.MS1B
#define FTM1C1SC_CH1IE                  _FTM1C1SC.Bits.CH1IE
#define FTM1C1SC_CH1F                   _FTM1C1SC.Bits.CH1F
#define FTM1C1SC_ELS1x                  _FTM1C1SC.MergedBits.grpELS1x
#define FTM1C1SC_MS1x                   _FTM1C1SC.MergedBits.grpMS1x

#define FTM1C1SC_ELS1A_MASK             4U
#define FTM1C1SC_ELS1B_MASK             8U
#define FTM1C1SC_MS1A_MASK              16U
#define FTM1C1SC_MS1B_MASK              32U
#define FTM1C1SC_CH1IE_MASK             64U
#define FTM1C1SC_CH1F_MASK              128U
#define FTM1C1SC_ELS1x_MASK             12U
#define FTM1C1SC_ELS1x_BITNUM           2U
#define FTM1C1SC_MS1x_MASK              48U
#define FTM1C1SC_MS1x_BITNUM            4U


/*** FTM1C1V - FTM1 Timer Channel 1 Value Register; 0x00000039 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** FTM1C1VH - FTM1 Timer Channel 1 Value Register High; 0x00000039 ***/
    union {
      byte Byte;
    } FTM1C1VHSTR;
    #define FTM1C1VH                    _FTM1C1V.Overlap_STR.FTM1C1VHSTR.Byte
    

    /*** FTM1C1VL - FTM1 Timer Channel 1 Value Register Low; 0x0000003A ***/
    union {
      byte Byte;
    } FTM1C1VLSTR;
    #define FTM1C1VL                    _FTM1C1V.Overlap_STR.FTM1C1VLSTR.Byte
    
  } Overlap_STR;

} FTM1C1VSTR;
extern volatile FTM1C1VSTR _FTM1C1V @0x00000039;
#define FTM1C1V                         _FTM1C1V.Word


/*** ICSC1 - ICS Control Register 1; 0x0000003C ***/
typedef union {
  byte Byte;
  struct {
    byte IREFSTEN    :1;                                       /* Internal Reference Stop Enable */
    byte IRCLKEN     :1;                                       /* Internal Reference Clock Enable */
    byte IREFS       :1;                                       /* Internal Reference Select */
    byte RDIV0       :1;                                       /* Reference Divider, bit 0 */
    byte RDIV1       :1;                                       /* Reference Divider, bit 1 */
    byte RDIV2       :1;                                       /* Reference Divider, bit 2 */
    byte CLKS0       :1;                                       /* Clock Source Select, bit 0 */
    byte CLKS1       :1;                                       /* Clock Source Select, bit 1 */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpRDIV :3;
    byte grpCLKS :2;
  } MergedBits;
} ICSC1STR;
extern volatile ICSC1STR _ICSC1 @0x0000003C;
#define ICSC1                           _ICSC1.Byte
#define ICSC1_IREFSTEN                  _ICSC1.Bits.IREFSTEN
#define ICSC1_IRCLKEN                   _ICSC1.Bits.IRCLKEN
#define ICSC1_IREFS                     _ICSC1.Bits.IREFS
#define ICSC1_RDIV0                     _ICSC1.Bits.RDIV0
#define ICSC1_RDIV1                     _ICSC1.Bits.RDIV1
#define ICSC1_RDIV2                     _ICSC1.Bits.RDIV2
#define ICSC1_CLKS0                     _ICSC1.Bits.CLKS0
#define ICSC1_CLKS1                     _ICSC1.Bits.CLKS1
#define ICSC1_RDIV                      _ICSC1.MergedBits.grpRDIV
#define ICSC1_CLKS                      _ICSC1.MergedBits.grpCLKS

#define ICSC1_IREFSTEN_MASK             1U
#define ICSC1_IRCLKEN_MASK              2U
#define ICSC1_IREFS_MASK                4U
#define ICSC1_RDIV0_MASK                8U
#define ICSC1_RDIV1_MASK                16U
#define ICSC1_RDIV2_MASK                32U
#define ICSC1_CLKS0_MASK                64U
#define ICSC1_CLKS1_MASK                128U
#define ICSC1_RDIV_MASK                 56U
#define ICSC1_RDIV_BITNUM               3U
#define ICSC1_CLKS_MASK                 192U
#define ICSC1_CLKS_BITNUM               6U


/*** ICSC2 - ICS Control Register 2; 0x0000003D ***/
typedef union {
  byte Byte;
  struct {
    byte EREFSTEN    :1;                                       /* External Reference Stop Enable */
    byte ERCLKEN     :1;                                       /* External Reference Enable */
    byte EREFS       :1;                                       /* External Reference Select */
    byte LP          :1;                                       /* Low Power Select */
    byte HGO         :1;                                       /* High Gain Oscillator Select */
    byte RANGE       :1;                                       /* Frequency Range Select */
    byte BDIV0       :1;                                       /* Bus Frequency Divider, bit 0 */
    byte BDIV1       :1;                                       /* Bus Frequency Divider, bit 1 */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpBDIV :2;
  } MergedBits;
} ICSC2STR;
extern volatile ICSC2STR _ICSC2 @0x0000003D;
#define ICSC2                           _ICSC2.Byte
#define ICSC2_EREFSTEN                  _ICSC2.Bits.EREFSTEN
#define ICSC2_ERCLKEN                   _ICSC2.Bits.ERCLKEN
#define ICSC2_EREFS                     _ICSC2.Bits.EREFS
#define ICSC2_LP                        _ICSC2.Bits.LP
#define ICSC2_HGO                       _ICSC2.Bits.HGO
#define ICSC2_RANGE                     _ICSC2.Bits.RANGE
#define ICSC2_BDIV0                     _ICSC2.Bits.BDIV0
#define ICSC2_BDIV1                     _ICSC2.Bits.BDIV1
#define ICSC2_BDIV                      _ICSC2.MergedBits.grpBDIV

#define ICSC2_EREFSTEN_MASK             1U
#define ICSC2_ERCLKEN_MASK              2U
#define ICSC2_EREFS_MASK                4U
#define ICSC2_LP_MASK                   8U
#define ICSC2_HGO_MASK                  16U
#define ICSC2_RANGE_MASK                32U
#define ICSC2_BDIV0_MASK                64U
#define ICSC2_BDIV1_MASK                128U
#define ICSC2_BDIV_MASK                 192U
#define ICSC2_BDIV_BITNUM               6U


/*** ICSTRM - ICS Trim Register; 0x0000003E ***/
typedef union {
  byte Byte;
  struct {
    byte TRIM0       :1;                                       /* ICS Trim Setting, bit 0 */
    byte TRIM1       :1;                                       /* ICS Trim Setting, bit 1 */
    byte TRIM2       :1;                                       /* ICS Trim Setting, bit 2 */
    byte TRIM3       :1;                                       /* ICS Trim Setting, bit 3 */
    byte TRIM4       :1;                                       /* ICS Trim Setting, bit 4 */
    byte TRIM5       :1;                                       /* ICS Trim Setting, bit 5 */
    byte TRIM6       :1;                                       /* ICS Trim Setting, bit 6 */
    byte TRIM7       :1;                                       /* ICS Trim Setting, bit 7 */
  } Bits;
} ICSTRMSTR;
extern volatile ICSTRMSTR _ICSTRM @0x0000003E;
#define ICSTRM                          _ICSTRM.Byte
#define ICSTRM_TRIM0                    _ICSTRM.Bits.TRIM0
#define ICSTRM_TRIM1                    _ICSTRM.Bits.TRIM1
#define ICSTRM_TRIM2                    _ICSTRM.Bits.TRIM2
#define ICSTRM_TRIM3                    _ICSTRM.Bits.TRIM3
#define ICSTRM_TRIM4                    _ICSTRM.Bits.TRIM4
#define ICSTRM_TRIM5                    _ICSTRM.Bits.TRIM5
#define ICSTRM_TRIM6                    _ICSTRM.Bits.TRIM6
#define ICSTRM_TRIM7                    _ICSTRM.Bits.TRIM7

#define ICSTRM_TRIM0_MASK               1U
#define ICSTRM_TRIM1_MASK               2U
#define ICSTRM_TRIM2_MASK               4U
#define ICSTRM_TRIM3_MASK               8U
#define ICSTRM_TRIM4_MASK               16U
#define ICSTRM_TRIM5_MASK               32U
#define ICSTRM_TRIM6_MASK               64U
#define ICSTRM_TRIM7_MASK               128U


/*** ICSSC - ICS Status and Control Register; 0x0000003F ***/
typedef union {
  byte Byte;
  struct {
    byte FTRIM       :1;                                       /* ICS Fine Trim */
    byte OSCINIT     :1;                                       /* OSC Initialization */
    byte CLKST0      :1;                                       /* Clock Mode Status, bit 0 */
    byte CLKST1      :1;                                       /* Clock Mode Status, bit 1 */
    byte IREFST      :1;                                       /* Internal Reference Status */
    byte DMX32       :1;                                       /* DCO Maximum frequency with 32.768 kHz reference */
    byte DRST_DRS0   :1;                                       /* DCO Range Status/Range Select, bit 0 */
    byte DRST_DRS1   :1;                                       /* DCO Range Status/Range Select, bit 1 */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpCLKST :2;
    byte         :1;
    byte grpDMX_32 :1;
    byte grpDRST_DRS :2;
  } MergedBits;
} ICSSCSTR;
extern volatile ICSSCSTR _ICSSC @0x0000003F;
#define ICSSC                           _ICSSC.Byte
#define ICSSC_FTRIM                     _ICSSC.Bits.FTRIM
#define ICSSC_OSCINIT                   _ICSSC.Bits.OSCINIT
#define ICSSC_CLKST0                    _ICSSC.Bits.CLKST0
#define ICSSC_CLKST1                    _ICSSC.Bits.CLKST1
#define ICSSC_IREFST                    _ICSSC.Bits.IREFST
#define ICSSC_DMX32                     _ICSSC.Bits.DMX32
#define ICSSC_DRST_DRS0                 _ICSSC.Bits.DRST_DRS0
#define ICSSC_DRST_DRS1                 _ICSSC.Bits.DRST_DRS1
#define ICSSC_CLKST                     _ICSSC.MergedBits.grpCLKST
#define ICSSC_DRST_DRS                  _ICSSC.MergedBits.grpDRST_DRS

#define ICSSC_FTRIM_MASK                1U
#define ICSSC_OSCINIT_MASK              2U
#define ICSSC_CLKST0_MASK               4U
#define ICSSC_CLKST1_MASK               8U
#define ICSSC_IREFST_MASK               16U
#define ICSSC_DMX32_MASK                32U
#define ICSSC_DRST_DRS0_MASK            64U
#define ICSSC_DRST_DRS1_MASK            128U
#define ICSSC_CLKST_MASK                12U
#define ICSSC_CLKST_BITNUM              2U
#define ICSSC_DRST_DRS_MASK             192U
#define ICSSC_DRST_DRS_BITNUM           6U


/*** FTM1CNTIN - FTM1 Counter Initial Value Registers; 0x00000040 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** FTM1CNTINH - FTM1 Counter Initial Value Registers High; 0x00000040 ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* FTM1 Counter Initial Value Bit 8 */
        byte BIT9        :1;                                       /* FTM1 Counter Initial Value Bit 9 */
        byte BIT10       :1;                                       /* FTM1 Counter Initial Value Bit 10 */
        byte BIT11       :1;                                       /* FTM1 Counter Initial Value Bit 11 */
        byte BIT12       :1;                                       /* FTM1 Counter Initial Value Bit 12 */
        byte BIT13       :1;                                       /* FTM1 Counter Initial Value Bit 13 */
        byte BIT14       :1;                                       /* FTM1 Counter Initial Value Bit 14 */
        byte BIT15       :1;                                       /* FTM1 Counter Initial Value Bit 15 */
      } Bits;
    } FTM1CNTINHSTR;
    #define FTM1CNTINH                  _FTM1CNTIN.Overlap_STR.FTM1CNTINHSTR.Byte
    #define FTM1CNTINH_BIT8             _FTM1CNTIN.Overlap_STR.FTM1CNTINHSTR.Bits.BIT8
    #define FTM1CNTINH_BIT9             _FTM1CNTIN.Overlap_STR.FTM1CNTINHSTR.Bits.BIT9
    #define FTM1CNTINH_BIT10            _FTM1CNTIN.Overlap_STR.FTM1CNTINHSTR.Bits.BIT10
    #define FTM1CNTINH_BIT11            _FTM1CNTIN.Overlap_STR.FTM1CNTINHSTR.Bits.BIT11
    #define FTM1CNTINH_BIT12            _FTM1CNTIN.Overlap_STR.FTM1CNTINHSTR.Bits.BIT12
    #define FTM1CNTINH_BIT13            _FTM1CNTIN.Overlap_STR.FTM1CNTINHSTR.Bits.BIT13
    #define FTM1CNTINH_BIT14            _FTM1CNTIN.Overlap_STR.FTM1CNTINHSTR.Bits.BIT14
    #define FTM1CNTINH_BIT15            _FTM1CNTIN.Overlap_STR.FTM1CNTINHSTR.Bits.BIT15
    
    #define FTM1CNTINH_BIT8_MASK        1U
    #define FTM1CNTINH_BIT9_MASK        2U
    #define FTM1CNTINH_BIT10_MASK       4U
    #define FTM1CNTINH_BIT11_MASK       8U
    #define FTM1CNTINH_BIT12_MASK       16U
    #define FTM1CNTINH_BIT13_MASK       32U
    #define FTM1CNTINH_BIT14_MASK       64U
    #define FTM1CNTINH_BIT15_MASK       128U
    

    /*** FTM1CNTINL - FTM1 Counter Initial Value Registers Low; 0x00000041 ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* FTM1 Counter Initial Value Bit 0 */
        byte BIT1        :1;                                       /* FTM1 Counter Initial Value Bit 1 */
        byte BIT2        :1;                                       /* FTM1 Counter Initial Value Bit 2 */
        byte BIT3        :1;                                       /* FTM1 Counter Initial Value Bit 3 */
        byte BIT4        :1;                                       /* FTM1 Counter Initial Value Bit 4 */
        byte BIT5        :1;                                       /* FTM1 Counter Initial Value Bit 5 */
        byte BIT6        :1;                                       /* FTM1 Counter Initial Value Bit 6 */
        byte BIT7        :1;                                       /* FTM1 Counter Initial Value Bit 7 */
      } Bits;
    } FTM1CNTINLSTR;
    #define FTM1CNTINL                  _FTM1CNTIN.Overlap_STR.FTM1CNTINLSTR.Byte
    #define FTM1CNTINL_BIT0             _FTM1CNTIN.Overlap_STR.FTM1CNTINLSTR.Bits.BIT0
    #define FTM1CNTINL_BIT1             _FTM1CNTIN.Overlap_STR.FTM1CNTINLSTR.Bits.BIT1
    #define FTM1CNTINL_BIT2             _FTM1CNTIN.Overlap_STR.FTM1CNTINLSTR.Bits.BIT2
    #define FTM1CNTINL_BIT3             _FTM1CNTIN.Overlap_STR.FTM1CNTINLSTR.Bits.BIT3
    #define FTM1CNTINL_BIT4             _FTM1CNTIN.Overlap_STR.FTM1CNTINLSTR.Bits.BIT4
    #define FTM1CNTINL_BIT5             _FTM1CNTIN.Overlap_STR.FTM1CNTINLSTR.Bits.BIT5
    #define FTM1CNTINL_BIT6             _FTM1CNTIN.Overlap_STR.FTM1CNTINLSTR.Bits.BIT6
    #define FTM1CNTINL_BIT7             _FTM1CNTIN.Overlap_STR.FTM1CNTINLSTR.Bits.BIT7
    
    #define FTM1CNTINL_BIT0_MASK        1U
    #define FTM1CNTINL_BIT1_MASK        2U
    #define FTM1CNTINL_BIT2_MASK        4U
    #define FTM1CNTINL_BIT3_MASK        8U
    #define FTM1CNTINL_BIT4_MASK        16U
    #define FTM1CNTINL_BIT5_MASK        32U
    #define FTM1CNTINL_BIT6_MASK        64U
    #define FTM1CNTINL_BIT7_MASK        128U
    
  } Overlap_STR;

} FTM1CNTINSTR;
extern volatile FTM1CNTINSTR _FTM1CNTIN @0x00000040;
#define FTM1CNTIN                       _FTM1CNTIN.Word


/*** FTM1STATUS - FTM1 Capture and Compare Status Register; 0x00000042 ***/
typedef union {
  byte Byte;
  struct {
    byte CH0F        :1;                                       /* Channel 0 Flag */
    byte CH1F        :1;                                       /* Channel 1 Flag */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} FTM1STATUSSTR;
extern volatile FTM1STATUSSTR _FTM1STATUS @0x00000042;
#define FTM1STATUS                      _FTM1STATUS.Byte
#define FTM1STATUS_CH0F                 _FTM1STATUS.Bits.CH0F
#define FTM1STATUS_CH1F                 _FTM1STATUS.Bits.CH1F

#define FTM1STATUS_CH0F_MASK            1U
#define FTM1STATUS_CH1F_MASK            2U


/*** FTM1MODE - FTM1 Features Mode Selection Register; 0x00000043 ***/
typedef union {
  byte Byte;
  struct {
    byte FTMEN       :1;                                       /* FTM1 Enable */
    byte INIT        :1;                                       /* Initialize the Channels Output */
    byte WPDIS       :1;                                       /* Write Protected Disable */
    byte PWMSYNC     :1;                                       /* PWM synchronization mode */
    byte CAPTTEST    :1;                                       /* Capture test mode enable */
    byte FAULTM0     :1;                                       /* Fault Control Mode Bits, bit 0 */
    byte FAULTM1     :1;                                       /* Fault Control Mode Bits, bit 1 */
    byte FAULTIE     :1;                                       /* Fault Interrupt Enable */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpFAULTM :2;
    byte         :1;
  } MergedBits;
} FTM1MODESTR;
extern volatile FTM1MODESTR _FTM1MODE @0x00000043;
#define FTM1MODE                        _FTM1MODE.Byte
#define FTM1MODE_FTMEN                  _FTM1MODE.Bits.FTMEN
#define FTM1MODE_INIT                   _FTM1MODE.Bits.INIT
#define FTM1MODE_WPDIS                  _FTM1MODE.Bits.WPDIS
#define FTM1MODE_PWMSYNC                _FTM1MODE.Bits.PWMSYNC
#define FTM1MODE_CAPTTEST               _FTM1MODE.Bits.CAPTTEST
#define FTM1MODE_FAULTM0                _FTM1MODE.Bits.FAULTM0
#define FTM1MODE_FAULTM1                _FTM1MODE.Bits.FAULTM1
#define FTM1MODE_FAULTIE                _FTM1MODE.Bits.FAULTIE
#define FTM1MODE_FAULTM                 _FTM1MODE.MergedBits.grpFAULTM

#define FTM1MODE_FTMEN_MASK             1U
#define FTM1MODE_INIT_MASK              2U
#define FTM1MODE_WPDIS_MASK             4U
#define FTM1MODE_PWMSYNC_MASK           8U
#define FTM1MODE_CAPTTEST_MASK          16U
#define FTM1MODE_FAULTM0_MASK           32U
#define FTM1MODE_FAULTM1_MASK           64U
#define FTM1MODE_FAULTIE_MASK           128U
#define FTM1MODE_FAULTM_MASK            96U
#define FTM1MODE_FAULTM_BITNUM          5U


/*** FTM1SYNC - FTM1 Synchronization Register; 0x00000044 ***/
typedef union {
  byte Byte;
  struct {
    byte CNTMIN      :1;                                       /* FTM1 Counter is Minimum */
    byte CNTMAX      :1;                                       /* FTM1 Counter is Maximum */
    byte REINIT      :1;                                       /* Reinitialization of FTM1 Counter by Synchronization */
    byte SYNCHOM     :1;                                       /* Output Mask by Synchronization */
    byte TRIG0       :1;                                       /* External Trigger Bit 0 for Synchronization */
    byte TRIG1       :1;                                       /* External Trigger Bit 1 for Synchronization */
    byte TRIG2       :1;                                       /* External Trigger Bit 2 for Synchronization */
    byte SWSYNC      :1;                                       /* Software Trigger for Synchronization */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpTRIG :3;
    byte         :1;
  } MergedBits;
} FTM1SYNCSTR;
extern volatile FTM1SYNCSTR _FTM1SYNC @0x00000044;
#define FTM1SYNC                        _FTM1SYNC.Byte
#define FTM1SYNC_CNTMIN                 _FTM1SYNC.Bits.CNTMIN
#define FTM1SYNC_CNTMAX                 _FTM1SYNC.Bits.CNTMAX
#define FTM1SYNC_REINIT                 _FTM1SYNC.Bits.REINIT
#define FTM1SYNC_SYNCHOM                _FTM1SYNC.Bits.SYNCHOM
#define FTM1SYNC_TRIG0                  _FTM1SYNC.Bits.TRIG0
#define FTM1SYNC_TRIG1                  _FTM1SYNC.Bits.TRIG1
#define FTM1SYNC_TRIG2                  _FTM1SYNC.Bits.TRIG2
#define FTM1SYNC_SWSYNC                 _FTM1SYNC.Bits.SWSYNC
#define FTM1SYNC_TRIG                   _FTM1SYNC.MergedBits.grpTRIG

#define FTM1SYNC_CNTMIN_MASK            1U
#define FTM1SYNC_CNTMAX_MASK            2U
#define FTM1SYNC_REINIT_MASK            4U
#define FTM1SYNC_SYNCHOM_MASK           8U
#define FTM1SYNC_TRIG0_MASK             16U
#define FTM1SYNC_TRIG1_MASK             32U
#define FTM1SYNC_TRIG2_MASK             64U
#define FTM1SYNC_SWSYNC_MASK            128U
#define FTM1SYNC_TRIG_MASK              112U
#define FTM1SYNC_TRIG_BITNUM            4U


/*** FTM1OUTINIT - FTM1 Initial State for Channels Output Register; 0x00000045 ***/
typedef union {
  byte Byte;
  struct {
    byte CH0OI       :1;                                       /* Initial State for Channel 0 Output */
    byte CH1OI       :1;                                       /* Initial State for Channel 1 Output */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} FTM1OUTINITSTR;
extern volatile FTM1OUTINITSTR _FTM1OUTINIT @0x00000045;
#define FTM1OUTINIT                     _FTM1OUTINIT.Byte
#define FTM1OUTINIT_CH0OI               _FTM1OUTINIT.Bits.CH0OI
#define FTM1OUTINIT_CH1OI               _FTM1OUTINIT.Bits.CH1OI

#define FTM1OUTINIT_CH0OI_MASK          1U
#define FTM1OUTINIT_CH1OI_MASK          2U


/*** FTM1OUTMASK - FTM1 Output Mask Register; 0x00000046 ***/
typedef union {
  byte Byte;
  struct {
    byte CH0OM       :1;                                       /* Channel 0 Output Mask */
    byte CH1OM       :1;                                       /* Channel 1 Output Mask */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} FTM1OUTMASKSTR;
extern volatile FTM1OUTMASKSTR _FTM1OUTMASK @0x00000046;
#define FTM1OUTMASK                     _FTM1OUTMASK.Byte
#define FTM1OUTMASK_CH0OM               _FTM1OUTMASK.Bits.CH0OM
#define FTM1OUTMASK_CH1OM               _FTM1OUTMASK.Bits.CH1OM

#define FTM1OUTMASK_CH0OM_MASK          1U
#define FTM1OUTMASK_CH1OM_MASK          2U


/*** FTM1COMBINE0 - FTM1 Function For Linked Channel 0 Register; 0x00000047 ***/
typedef union {
  byte Byte;
  struct {
    byte COMBINE     :1;                                       /* Enables the Combine of the Channels 0 and 1 */
    byte COMP        :1;                                       /* Complementary of Channel 0 */
    byte             :1; 
    byte             :1; 
    byte DTEN        :1;                                       /* Deadtime Enable */
    byte SYNCEN      :1;                                       /* Synchronization Enable */
    byte FAULTEN     :1;                                       /* Fault Control Enable */
    byte             :1; 
  } Bits;
} FTM1COMBINE0STR;
extern volatile FTM1COMBINE0STR _FTM1COMBINE0 @0x00000047;
#define FTM1COMBINE0                    _FTM1COMBINE0.Byte
#define FTM1COMBINE0_COMBINE            _FTM1COMBINE0.Bits.COMBINE
#define FTM1COMBINE0_COMP               _FTM1COMBINE0.Bits.COMP
#define FTM1COMBINE0_DTEN               _FTM1COMBINE0.Bits.DTEN
#define FTM1COMBINE0_SYNCEN             _FTM1COMBINE0.Bits.SYNCEN
#define FTM1COMBINE0_FAULTEN            _FTM1COMBINE0.Bits.FAULTEN

#define FTM1COMBINE0_COMBINE_MASK       1U
#define FTM1COMBINE0_COMP_MASK          2U
#define FTM1COMBINE0_DTEN_MASK          16U
#define FTM1COMBINE0_SYNCEN_MASK        32U
#define FTM1COMBINE0_FAULTEN_MASK       64U


/*** FTM1DEADTIME - FTM1 Deadtime Insertion Control Register; 0x0000004B ***/
typedef union {
  byte Byte;
  struct {
    byte DTVAL0      :1;                                       /* Deadtime Value Bits, bit 0 */
    byte DTVAL1      :1;                                       /* Deadtime Value Bits, bit 1 */
    byte DTVAL2      :1;                                       /* Deadtime Value Bits, bit 2 */
    byte DTVAL3      :1;                                       /* Deadtime Value Bits, bit 3 */
    byte DTVAL4      :1;                                       /* Deadtime Value Bits, bit 4 */
    byte DTVAL5      :1;                                       /* Deadtime Value Bits, bit 5 */
    byte DTPS0       :1;                                       /* Deadtime Prescaler Value Bits, bit 0 */
    byte DTPS1       :1;                                       /* Deadtime Prescaler Value Bits, bit 1 */
  } Bits;
  struct {
    byte grpDTVAL :6;
    byte grpDTPS :2;
  } MergedBits;
} FTM1DEADTIMESTR;
extern volatile FTM1DEADTIMESTR _FTM1DEADTIME @0x0000004B;
#define FTM1DEADTIME                    _FTM1DEADTIME.Byte
#define FTM1DEADTIME_DTVAL0             _FTM1DEADTIME.Bits.DTVAL0
#define FTM1DEADTIME_DTVAL1             _FTM1DEADTIME.Bits.DTVAL1
#define FTM1DEADTIME_DTVAL2             _FTM1DEADTIME.Bits.DTVAL2
#define FTM1DEADTIME_DTVAL3             _FTM1DEADTIME.Bits.DTVAL3
#define FTM1DEADTIME_DTVAL4             _FTM1DEADTIME.Bits.DTVAL4
#define FTM1DEADTIME_DTVAL5             _FTM1DEADTIME.Bits.DTVAL5
#define FTM1DEADTIME_DTPS0              _FTM1DEADTIME.Bits.DTPS0
#define FTM1DEADTIME_DTPS1              _FTM1DEADTIME.Bits.DTPS1
#define FTM1DEADTIME_DTVAL              _FTM1DEADTIME.MergedBits.grpDTVAL
#define FTM1DEADTIME_DTPS               _FTM1DEADTIME.MergedBits.grpDTPS

#define FTM1DEADTIME_DTVAL0_MASK        1U
#define FTM1DEADTIME_DTVAL1_MASK        2U
#define FTM1DEADTIME_DTVAL2_MASK        4U
#define FTM1DEADTIME_DTVAL3_MASK        8U
#define FTM1DEADTIME_DTVAL4_MASK        16U
#define FTM1DEADTIME_DTVAL5_MASK        32U
#define FTM1DEADTIME_DTPS0_MASK         64U
#define FTM1DEADTIME_DTPS1_MASK         128U
#define FTM1DEADTIME_DTVAL_MASK         63U
#define FTM1DEADTIME_DTVAL_BITNUM       0U
#define FTM1DEADTIME_DTPS_MASK          192U
#define FTM1DEADTIME_DTPS_BITNUM        6U


/*** FTM1EXTTRIG - FTM1 ExternalTrigger Register; 0x0000004C ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte INITTRIGEN  :1;                                       /* Enables the Generation of a Trigger Signal */
    byte             :1; 
  } Bits;
} FTM1EXTTRIGSTR;
extern volatile FTM1EXTTRIGSTR _FTM1EXTTRIG @0x0000004C;
#define FTM1EXTTRIG                     _FTM1EXTTRIG.Byte
#define FTM1EXTTRIG_INITTRIGEN          _FTM1EXTTRIG.Bits.INITTRIGEN

#define FTM1EXTTRIG_INITTRIGEN_MASK     64U


/*** FTM1POL - FTM1 Channels Polarity Register; 0x0000004D ***/
typedef union {
  byte Byte;
  struct {
    byte POL0        :1;                                       /* Channel 0 Polarity */
    byte POL1        :1;                                       /* Channel 1 Polarity */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPOL  :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} FTM1POLSTR;
extern volatile FTM1POLSTR _FTM1POL @0x0000004D;
#define FTM1POL                         _FTM1POL.Byte
#define FTM1POL_POL0                    _FTM1POL.Bits.POL0
#define FTM1POL_POL1                    _FTM1POL.Bits.POL1
#define FTM1POL_POL                     _FTM1POL.MergedBits.grpPOL

#define FTM1POL_POL0_MASK               1U
#define FTM1POL_POL1_MASK               2U
#define FTM1POL_POL_MASK                3U
#define FTM1POL_POL_BITNUM              0U


/*** FTM1FMS - FTM1 Fault Mode Status Register; 0x0000004E ***/
typedef union {
  byte Byte;
  struct {
    byte FAULTF0     :1;                                       /* Fault detection flag 0 */
    byte FAULTF1     :1;                                       /* Fault detection flag 1 */
    byte FAULTF2     :1;                                       /* Fault detection flag 2 */
    byte FAULTF3     :1;                                       /* Fault detection flag 3 */
    byte             :1; 
    byte FAULTIN     :1;                                       /* Fault Input */
    byte WPEN        :1;                                       /* Write Protected Enable */
    byte FAULTF      :1;                                       /* Fault Detection Flag */
  } Bits;
  struct {
    byte         :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} FTM1FMSSTR;
extern volatile FTM1FMSSTR _FTM1FMS @0x0000004E;
#define FTM1FMS                         _FTM1FMS.Byte
#define FTM1FMS_FAULTF0                 _FTM1FMS.Bits.FAULTF0
#define FTM1FMS_FAULTF1                 _FTM1FMS.Bits.FAULTF1
#define FTM1FMS_FAULTF2                 _FTM1FMS.Bits.FAULTF2
#define FTM1FMS_FAULTF3                 _FTM1FMS.Bits.FAULTF3
#define FTM1FMS_FAULTIN                 _FTM1FMS.Bits.FAULTIN
#define FTM1FMS_WPEN                    _FTM1FMS.Bits.WPEN
#define FTM1FMS_FAULTF                  _FTM1FMS.Bits.FAULTF

#define FTM1FMS_FAULTF0_MASK            1U
#define FTM1FMS_FAULTF1_MASK            2U
#define FTM1FMS_FAULTF2_MASK            4U
#define FTM1FMS_FAULTF3_MASK            8U
#define FTM1FMS_FAULTIN_MASK            32U
#define FTM1FMS_WPEN_MASK               64U
#define FTM1FMS_FAULTF_MASK             128U


/*** FTM1FILTER0 - FTM1 Input Capture Filter Control Register 0; 0x0000004F ***/
typedef union {
  byte Byte;
  struct {
    byte CH0FVAL0    :1;                                       /* Channel 0 Input Filter Bits, bit 0 */
    byte CH0FVAL1    :1;                                       /* Channel 0 Input Filter Bits, bit 1 */
    byte CH0FVAL2    :1;                                       /* Channel 0 Input Filter Bits, bit 2 */
    byte CH0FVAL3    :1;                                       /* Channel 0 Input Filter Bits, bit 3 */
    byte CH1FVAL0    :1;                                       /* Channel 1 Input Filter Bits, bit 0 */
    byte CH1FVAL1    :1;                                       /* Channel 1 Input Filter Bits, bit 1 */
    byte CH1FVAL2    :1;                                       /* Channel 1 Input Filter Bits, bit 2 */
    byte CH1FVAL3    :1;                                       /* Channel 1 Input Filter Bits, bit 3 */
  } Bits;
  struct {
    byte grpCH0FVAL :4;
    byte grpCH1FVAL :4;
  } MergedBits;
} FTM1FILTER0STR;
extern volatile FTM1FILTER0STR _FTM1FILTER0 @0x0000004F;
#define FTM1FILTER0                     _FTM1FILTER0.Byte
#define FTM1FILTER0_CH0FVAL0            _FTM1FILTER0.Bits.CH0FVAL0
#define FTM1FILTER0_CH0FVAL1            _FTM1FILTER0.Bits.CH0FVAL1
#define FTM1FILTER0_CH0FVAL2            _FTM1FILTER0.Bits.CH0FVAL2
#define FTM1FILTER0_CH0FVAL3            _FTM1FILTER0.Bits.CH0FVAL3
#define FTM1FILTER0_CH1FVAL0            _FTM1FILTER0.Bits.CH1FVAL0
#define FTM1FILTER0_CH1FVAL1            _FTM1FILTER0.Bits.CH1FVAL1
#define FTM1FILTER0_CH1FVAL2            _FTM1FILTER0.Bits.CH1FVAL2
#define FTM1FILTER0_CH1FVAL3            _FTM1FILTER0.Bits.CH1FVAL3
#define FTM1FILTER0_CH0FVAL             _FTM1FILTER0.MergedBits.grpCH0FVAL
#define FTM1FILTER0_CH1FVAL             _FTM1FILTER0.MergedBits.grpCH1FVAL

#define FTM1FILTER0_CH0FVAL0_MASK       1U
#define FTM1FILTER0_CH0FVAL1_MASK       2U
#define FTM1FILTER0_CH0FVAL2_MASK       4U
#define FTM1FILTER0_CH0FVAL3_MASK       8U
#define FTM1FILTER0_CH1FVAL0_MASK       16U
#define FTM1FILTER0_CH1FVAL1_MASK       32U
#define FTM1FILTER0_CH1FVAL2_MASK       64U
#define FTM1FILTER0_CH1FVAL3_MASK       128U
#define FTM1FILTER0_CH0FVAL_MASK        15U
#define FTM1FILTER0_CH0FVAL_BITNUM      0U
#define FTM1FILTER0_CH1FVAL_MASK        240U
#define FTM1FILTER0_CH1FVAL_BITNUM      4U


/*** FTM1FLTFILTER - FTM1 Fault Input Filter Control Register; 0x00000051 ***/
typedef union {
  byte Byte;
  struct {
    byte FFVAL0      :1;                                       /* Fault Input Filter Bits, bit 0 */
    byte FFVAL1      :1;                                       /* Fault Input Filter Bits, bit 1 */
    byte FFVAL2      :1;                                       /* Fault Input Filter Bits, bit 2 */
    byte FFVAL3      :1;                                       /* Fault Input Filter Bits, bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpFFVAL :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} FTM1FLTFILTERSTR;
extern volatile FTM1FLTFILTERSTR _FTM1FLTFILTER @0x00000051;
#define FTM1FLTFILTER                   _FTM1FLTFILTER.Byte
#define FTM1FLTFILTER_FFVAL0            _FTM1FLTFILTER.Bits.FFVAL0
#define FTM1FLTFILTER_FFVAL1            _FTM1FLTFILTER.Bits.FFVAL1
#define FTM1FLTFILTER_FFVAL2            _FTM1FLTFILTER.Bits.FFVAL2
#define FTM1FLTFILTER_FFVAL3            _FTM1FLTFILTER.Bits.FFVAL3
#define FTM1FLTFILTER_FFVAL             _FTM1FLTFILTER.MergedBits.grpFFVAL

#define FTM1FLTFILTER_FFVAL0_MASK       1U
#define FTM1FLTFILTER_FFVAL1_MASK       2U
#define FTM1FLTFILTER_FFVAL2_MASK       4U
#define FTM1FLTFILTER_FFVAL3_MASK       8U
#define FTM1FLTFILTER_FFVAL_MASK        15U
#define FTM1FLTFILTER_FFVAL_BITNUM      0U


/*** FTM1FLTCTRL - FTM1 Fault Control Register; 0x00000052 ***/
typedef union {
  byte Byte;
  struct {
    byte FAULT0EN    :1;                                       /* Fault input 0 enable */
    byte FAULT1EN    :1;                                       /* Fault input 1 enable */
    byte FAULT2EN    :1;                                       /* Fault input 2 enable */
    byte FAULT3EN    :1;                                       /* Fault input 3 enable */
    byte FFLTR0EN    :1;                                       /* Fault input 0 filter enable */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} FTM1FLTCTRLSTR;
extern volatile FTM1FLTCTRLSTR _FTM1FLTCTRL @0x00000052;
#define FTM1FLTCTRL                     _FTM1FLTCTRL.Byte
#define FTM1FLTCTRL_FAULT0EN            _FTM1FLTCTRL.Bits.FAULT0EN
#define FTM1FLTCTRL_FAULT1EN            _FTM1FLTCTRL.Bits.FAULT1EN
#define FTM1FLTCTRL_FAULT2EN            _FTM1FLTCTRL.Bits.FAULT2EN
#define FTM1FLTCTRL_FAULT3EN            _FTM1FLTCTRL.Bits.FAULT3EN
#define FTM1FLTCTRL_FFLTR0EN            _FTM1FLTCTRL.Bits.FFLTR0EN

#define FTM1FLTCTRL_FAULT0EN_MASK       1U
#define FTM1FLTCTRL_FAULT1EN_MASK       2U
#define FTM1FLTCTRL_FAULT2EN_MASK       4U
#define FTM1FLTCTRL_FAULT3EN_MASK       8U
#define FTM1FLTCTRL_FFLTR0EN_MASK       16U


/*** MTIMSC - MTIM Clock Configuration Register; 0x00000054 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte TSTP        :1;                                       /* MTIM Counter Stop */
    byte TRST        :1;                                       /* MTIM Counter Reset */
    byte TOIE        :1;                                       /* MTIM Overflow Interrupt Enable */
    byte TOF         :1;                                       /* MTIM Overflow Flag */
  } Bits;
} MTIMSCSTR;
extern volatile MTIMSCSTR _MTIMSC @0x00000054;
#define MTIMSC                          _MTIMSC.Byte
#define MTIMSC_TSTP                     _MTIMSC.Bits.TSTP
#define MTIMSC_TRST                     _MTIMSC.Bits.TRST
#define MTIMSC_TOIE                     _MTIMSC.Bits.TOIE
#define MTIMSC_TOF                      _MTIMSC.Bits.TOF

#define MTIMSC_TSTP_MASK                16U
#define MTIMSC_TRST_MASK                32U
#define MTIMSC_TOIE_MASK                64U
#define MTIMSC_TOF_MASK                 128U


/*** MTIMCLK - MTIM Clock Configuration Register; 0x00000055 ***/
typedef union {
  byte Byte;
  struct {
    byte PS0         :1;                                       /* Clock source Prescaler Bit 0 */
    byte PS1         :1;                                       /* Clock source Prescaler Bit 1 */
    byte PS2         :1;                                       /* Clock source Prescaler Bit 2 */
    byte PS3         :1;                                       /* Clock source Prescaler Bit 3 */
    byte CLKS0       :1;                                       /* Clock source Select Bit 0 */
    byte CLKS1       :1;                                       /* Clock source Select Bit 1 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPS   :4;
    byte grpCLKS :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} MTIMCLKSTR;
extern volatile MTIMCLKSTR _MTIMCLK @0x00000055;
#define MTIMCLK                         _MTIMCLK.Byte
#define MTIMCLK_PS0                     _MTIMCLK.Bits.PS0
#define MTIMCLK_PS1                     _MTIMCLK.Bits.PS1
#define MTIMCLK_PS2                     _MTIMCLK.Bits.PS2
#define MTIMCLK_PS3                     _MTIMCLK.Bits.PS3
#define MTIMCLK_CLKS0                   _MTIMCLK.Bits.CLKS0
#define MTIMCLK_CLKS1                   _MTIMCLK.Bits.CLKS1
#define MTIMCLK_PS                      _MTIMCLK.MergedBits.grpPS
#define MTIMCLK_CLKS                    _MTIMCLK.MergedBits.grpCLKS

#define MTIMCLK_PS0_MASK                1U
#define MTIMCLK_PS1_MASK                2U
#define MTIMCLK_PS2_MASK                4U
#define MTIMCLK_PS3_MASK                8U
#define MTIMCLK_CLKS0_MASK              16U
#define MTIMCLK_CLKS1_MASK              32U
#define MTIMCLK_PS_MASK                 15U
#define MTIMCLK_PS_BITNUM               0U
#define MTIMCLK_CLKS_MASK               48U
#define MTIMCLK_CLKS_BITNUM             4U


/*** MTIMCNT - MTIM Counter Register; 0x00000056 ***/
typedef union {
  byte Byte;
} MTIMCNTSTR;
extern volatile MTIMCNTSTR _MTIMCNT @0x00000056;
#define MTIMCNT                         _MTIMCNT.Byte


/*** MTIMMOD - MTIM Modulo Register; 0x00000057 ***/
typedef union {
  byte Byte;
} MTIMMODSTR;
extern volatile MTIMMODSTR _MTIMMOD @0x00000057;
#define MTIMMOD                         _MTIMMOD.Byte


/*** SPIC1 - SPI Control Register 1; 0x00000058 ***/
typedef union {
  byte Byte;
  struct {
    byte LSBFE       :1;                                       /* LSB First (Shifter Direction) */
    byte SSOE        :1;                                       /* Slave Select Output Enable */
    byte CPHA        :1;                                       /* Clock Phase */
    byte CPOL        :1;                                       /* Clock Polarity */
    byte MSTR        :1;                                       /* Master/Slave Mode Select */
    byte SPTIE       :1;                                       /* SPI Transmit Interrupt Enable */
    byte SPE         :1;                                       /* SPI System Enable */
    byte SPIE        :1;                                       /* SPI Interrupt Enable (for SPRF and MODF) */
  } Bits;
} SPIC1STR;
extern volatile SPIC1STR _SPIC1 @0x00000058;
#define SPIC1                           _SPIC1.Byte
#define SPIC1_LSBFE                     _SPIC1.Bits.LSBFE
#define SPIC1_SSOE                      _SPIC1.Bits.SSOE
#define SPIC1_CPHA                      _SPIC1.Bits.CPHA
#define SPIC1_CPOL                      _SPIC1.Bits.CPOL
#define SPIC1_MSTR                      _SPIC1.Bits.MSTR
#define SPIC1_SPTIE                     _SPIC1.Bits.SPTIE
#define SPIC1_SPE                       _SPIC1.Bits.SPE
#define SPIC1_SPIE                      _SPIC1.Bits.SPIE

#define SPIC1_LSBFE_MASK                1U
#define SPIC1_SSOE_MASK                 2U
#define SPIC1_CPHA_MASK                 4U
#define SPIC1_CPOL_MASK                 8U
#define SPIC1_MSTR_MASK                 16U
#define SPIC1_SPTIE_MASK                32U
#define SPIC1_SPE_MASK                  64U
#define SPIC1_SPIE_MASK                 128U


/*** SPIC2 - SPI Control Register 2; 0x00000059 ***/
typedef union {
  byte Byte;
  struct {
    byte SPC0        :1;                                       /* SPI Pin Control 0 */
    byte SPISWAI     :1;                                       /* SPI Stop in Wait Mode */
    byte             :1; 
    byte BIDIROE     :1;                                       /* Bidirectional Mode Output Enable */
    byte MODFEN      :1;                                       /* Master Mode-Fault Function Enable */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} SPIC2STR;
extern volatile SPIC2STR _SPIC2 @0x00000059;
#define SPIC2                           _SPIC2.Byte
#define SPIC2_SPC0                      _SPIC2.Bits.SPC0
#define SPIC2_SPISWAI                   _SPIC2.Bits.SPISWAI
#define SPIC2_BIDIROE                   _SPIC2.Bits.BIDIROE
#define SPIC2_MODFEN                    _SPIC2.Bits.MODFEN

#define SPIC2_SPC0_MASK                 1U
#define SPIC2_SPISWAI_MASK              2U
#define SPIC2_BIDIROE_MASK              8U
#define SPIC2_MODFEN_MASK               16U


/*** SPIBR - SPI Baud Rate Register; 0x0000005A ***/
typedef union {
  byte Byte;
  struct {
    byte SPR0        :1;                                       /* SPI Baud Rate Divisor Bit 0 */
    byte SPR1        :1;                                       /* SPI Baud Rate Divisor Bit 1 */
    byte SPR2        :1;                                       /* SPI Baud Rate Divisor Bit 2 */
    byte SPR3        :1;                                       /* SPI Baud Rate Divisor Bit 3 */
    byte SPPR0       :1;                                       /* SPI Baud Rate Prescale Divisor Bit 0 */
    byte SPPR1       :1;                                       /* SPI Baud Rate Prescale Divisor Bit 1 */
    byte SPPR2       :1;                                       /* SPI Baud Rate Prescale Divisor Bit 2 */
    byte             :1; 
  } Bits;
  struct {
    byte grpSPR  :4;
    byte grpSPPR :3;
    byte         :1;
  } MergedBits;
} SPIBRSTR;
extern volatile SPIBRSTR _SPIBR @0x0000005A;
#define SPIBR                           _SPIBR.Byte
#define SPIBR_SPR0                      _SPIBR.Bits.SPR0
#define SPIBR_SPR1                      _SPIBR.Bits.SPR1
#define SPIBR_SPR2                      _SPIBR.Bits.SPR2
#define SPIBR_SPR3                      _SPIBR.Bits.SPR3
#define SPIBR_SPPR0                     _SPIBR.Bits.SPPR0
#define SPIBR_SPPR1                     _SPIBR.Bits.SPPR1
#define SPIBR_SPPR2                     _SPIBR.Bits.SPPR2
#define SPIBR_SPR                       _SPIBR.MergedBits.grpSPR
#define SPIBR_SPPR                      _SPIBR.MergedBits.grpSPPR

#define SPIBR_SPR0_MASK                 1U
#define SPIBR_SPR1_MASK                 2U
#define SPIBR_SPR2_MASK                 4U
#define SPIBR_SPR3_MASK                 8U
#define SPIBR_SPPR0_MASK                16U
#define SPIBR_SPPR1_MASK                32U
#define SPIBR_SPPR2_MASK                64U
#define SPIBR_SPR_MASK                  15U
#define SPIBR_SPR_BITNUM                0U
#define SPIBR_SPPR_MASK                 112U
#define SPIBR_SPPR_BITNUM               4U


/*** SPIS - SPI Status Register; 0x0000005B ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte MODF        :1;                                       /* Master Mode Fault Flag */
    byte SPTEF       :1;                                       /* SPI Transmit Buffer Empty Flag */
    byte             :1; 
    byte SPRF        :1;                                       /* SPI Read Buffer Full Flag */
  } Bits;
} SPISSTR;
extern volatile SPISSTR _SPIS @0x0000005B;
#define SPIS                            _SPIS.Byte
#define SPIS_MODF                       _SPIS.Bits.MODF
#define SPIS_SPTEF                      _SPIS.Bits.SPTEF
#define SPIS_SPRF                       _SPIS.Bits.SPRF

#define SPIS_MODF_MASK                  16U
#define SPIS_SPTEF_MASK                 32U
#define SPIS_SPRF_MASK                  128U


/*** SPID - SPI Data Register; 0x0000005D ***/
typedef union {
  byte Byte;
} SPIDSTR;
extern volatile SPIDSTR _SPID @0x0000005D;
#define SPID                            _SPID.Byte


/*** IPCSC - IPC Status and Control Register; 0x0000005E ***/
typedef union {
  byte Byte;
  struct {
    byte IPM0        :1;                                       /* Interrupt Priority Mask, bit 0 */
    byte IPM1        :1;                                       /* Interrupt Priority Mask, bit 1 */
    byte             :1; 
    byte PULIPM      :1;                                       /* Pull IPM from IPMPS */
    byte PSF         :1;                                       /* Pseudo Stack Full */
    byte PSE         :1;                                       /* Pseudo Stack Empty */
    byte             :1; 
    byte IPCE        :1;                                       /* Interrupt Priority Controller Enable */
  } Bits;
  struct {
    byte grpIPM  :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} IPCSCSTR;
extern volatile IPCSCSTR _IPCSC @0x0000005E;
#define IPCSC                           _IPCSC.Byte
#define IPCSC_IPM0                      _IPCSC.Bits.IPM0
#define IPCSC_IPM1                      _IPCSC.Bits.IPM1
#define IPCSC_PULIPM                    _IPCSC.Bits.PULIPM
#define IPCSC_PSF                       _IPCSC.Bits.PSF
#define IPCSC_PSE                       _IPCSC.Bits.PSE
#define IPCSC_IPCE                      _IPCSC.Bits.IPCE
#define IPCSC_IPM                       _IPCSC.MergedBits.grpIPM

#define IPCSC_IPM0_MASK                 1U
#define IPCSC_IPM1_MASK                 2U
#define IPCSC_PULIPM_MASK               8U
#define IPCSC_PSF_MASK                  16U
#define IPCSC_PSE_MASK                  32U
#define IPCSC_IPCE_MASK                 128U
#define IPCSC_IPM_MASK                  3U
#define IPCSC_IPM_BITNUM                0U


/*** IPMPS - Interrupt Priority Mask Pseudo Stack Register; 0x0000005F ***/
typedef union {
  byte Byte;
  struct {
    byte IPM00       :1;                                       /* Interrupt Priority Mask pseudo stack position 0, bit 0 */
    byte IPM01       :1;                                       /* Interrupt Priority Mask pseudo stack position 0, bit 1 */
    byte IPM10       :1;                                       /* Interrupt Priority Mask pseudo stack position 1, bit 0 */
    byte IPM11       :1;                                       /* Interrupt Priority Mask pseudo stack position 1, bit 1 */
    byte IPM20       :1;                                       /* Interrupt Priority Mask pseudo stack position 2, bit 0 */
    byte IPM21       :1;                                       /* Interrupt Priority Mask pseudo stack position 2, bit 1 */
    byte IPM30       :1;                                       /* Interrupt Priority Mask pseudo stack position 3, bit 0 */
    byte IPM31       :1;                                       /* Interrupt Priority Mask pseudo stack position 3, bit 1 */
  } Bits;
  struct {
    byte grpIPM0 :2;
    byte grpIPM1 :2;
    byte grpIPM2 :2;
    byte grpIPM3 :2;
  } MergedBits;
} IPMPSSTR;
extern volatile IPMPSSTR _IPMPS @0x0000005F;
#define IPMPS                           _IPMPS.Byte
#define IPMPS_IPM00                     _IPMPS.Bits.IPM00
#define IPMPS_IPM01                     _IPMPS.Bits.IPM01
#define IPMPS_IPM10                     _IPMPS.Bits.IPM10
#define IPMPS_IPM11                     _IPMPS.Bits.IPM11
#define IPMPS_IPM20                     _IPMPS.Bits.IPM20
#define IPMPS_IPM21                     _IPMPS.Bits.IPM21
#define IPMPS_IPM30                     _IPMPS.Bits.IPM30
#define IPMPS_IPM31                     _IPMPS.Bits.IPM31
#define IPMPS_IPM0                      _IPMPS.MergedBits.grpIPM0
#define IPMPS_IPM1                      _IPMPS.MergedBits.grpIPM1
#define IPMPS_IPM2                      _IPMPS.MergedBits.grpIPM2
#define IPMPS_IPM3                      _IPMPS.MergedBits.grpIPM3

#define IPMPS_IPM00_MASK                1U
#define IPMPS_IPM01_MASK                2U
#define IPMPS_IPM10_MASK                4U
#define IPMPS_IPM11_MASK                8U
#define IPMPS_IPM20_MASK                16U
#define IPMPS_IPM21_MASK                32U
#define IPMPS_IPM30_MASK                64U
#define IPMPS_IPM31_MASK                128U
#define IPMPS_IPM0_MASK                 3U
#define IPMPS_IPM0_BITNUM               0U
#define IPMPS_IPM1_MASK                 12U
#define IPMPS_IPM1_BITNUM               2U
#define IPMPS_IPM2_MASK                 48U
#define IPMPS_IPM2_BITNUM               4U
#define IPMPS_IPM3_MASK                 192U
#define IPMPS_IPM3_BITNUM               6U


/*** ILRS0 - Interrupt Level Setting Register; 0x00000060 ***/
typedef union {
  byte Byte;
  struct {
    byte ILR00       :1;                                       /* Interrupt Level Register for Source 0, bit 0 */
    byte ILR01       :1;                                       /* Interrupt Level Register for Source 0, bit 1 */
    byte ILR10       :1;                                       /* Interrupt Level Register for Source 1, bit 0 */
    byte ILR11       :1;                                       /* Interrupt Level Register for Source 1, bit 1 */
    byte ILR20       :1;                                       /* Interrupt Level Register for Source 2, bit 0 */
    byte ILR21       :1;                                       /* Interrupt Level Register for Source 2, bit 1 */
    byte ILR30       :1;                                       /* Interrupt Level Register for Source 3, bit 0 */
    byte ILR31       :1;                                       /* Interrupt Level Register for Source 3, bit 1 */
  } Bits;
  struct {
    byte grpILR0 :2;
    byte grpILR1 :2;
    byte grpILR2 :2;
    byte grpILR3 :2;
  } MergedBits;
} ILRS0STR;
extern volatile ILRS0STR _ILRS0 @0x00000060;
#define ILRS0                           _ILRS0.Byte
#define ILRS0_ILR00                     _ILRS0.Bits.ILR00
#define ILRS0_ILR01                     _ILRS0.Bits.ILR01
#define ILRS0_ILR10                     _ILRS0.Bits.ILR10
#define ILRS0_ILR11                     _ILRS0.Bits.ILR11
#define ILRS0_ILR20                     _ILRS0.Bits.ILR20
#define ILRS0_ILR21                     _ILRS0.Bits.ILR21
#define ILRS0_ILR30                     _ILRS0.Bits.ILR30
#define ILRS0_ILR31                     _ILRS0.Bits.ILR31
/* ILRS_ARR: Access 8 ILRSx registers in an array */
#define ILRS_ARR                        ((volatile byte * __far) &ILRS0)
#define ILRS0_ILR0                      _ILRS0.MergedBits.grpILR0
#define ILRS0_ILR1                      _ILRS0.MergedBits.grpILR1
#define ILRS0_ILR2                      _ILRS0.MergedBits.grpILR2
#define ILRS0_ILR3                      _ILRS0.MergedBits.grpILR3

#define ILRS0_ILR00_MASK                1U
#define ILRS0_ILR01_MASK                2U
#define ILRS0_ILR10_MASK                4U
#define ILRS0_ILR11_MASK                8U
#define ILRS0_ILR20_MASK                16U
#define ILRS0_ILR21_MASK                32U
#define ILRS0_ILR30_MASK                64U
#define ILRS0_ILR31_MASK                128U
#define ILRS0_ILR0_MASK                 3U
#define ILRS0_ILR0_BITNUM               0U
#define ILRS0_ILR1_MASK                 12U
#define ILRS0_ILR1_BITNUM               2U
#define ILRS0_ILR2_MASK                 48U
#define ILRS0_ILR2_BITNUM               4U
#define ILRS0_ILR3_MASK                 192U
#define ILRS0_ILR3_BITNUM               6U


/*** ILRS1 - Interrupt Level Setting Register; 0x00000061 ***/
typedef union {
  byte Byte;
  struct {
    byte ILR40       :1;                                       /* Interrupt Level Register for Source 4, bit 0 */
    byte ILR41       :1;                                       /* Interrupt Level Register for Source 4, bit 1 */
    byte ILR50       :1;                                       /* Interrupt Level Register for Source 5, bit 0 */
    byte ILR51       :1;                                       /* Interrupt Level Register for Source 5, bit 1 */
    byte ILR60       :1;                                       /* Interrupt Level Register for Source 6, bit 0 */
    byte ILR61       :1;                                       /* Interrupt Level Register for Source 6, bit 1 */
    byte ILR70       :1;                                       /* Interrupt Level Register for Source 7, bit 0 */
    byte ILR71       :1;                                       /* Interrupt Level Register for Source 7, bit 1 */
  } Bits;
  struct {
    byte grpILR4 :2;
    byte grpILR5 :2;
    byte grpILR6 :2;
    byte grpILR7 :2;
  } MergedBits;
} ILRS1STR;
extern volatile ILRS1STR _ILRS1 @0x00000061;
#define ILRS1                           _ILRS1.Byte
#define ILRS1_ILR40                     _ILRS1.Bits.ILR40
#define ILRS1_ILR41                     _ILRS1.Bits.ILR41
#define ILRS1_ILR50                     _ILRS1.Bits.ILR50
#define ILRS1_ILR51                     _ILRS1.Bits.ILR51
#define ILRS1_ILR60                     _ILRS1.Bits.ILR60
#define ILRS1_ILR61                     _ILRS1.Bits.ILR61
#define ILRS1_ILR70                     _ILRS1.Bits.ILR70
#define ILRS1_ILR71                     _ILRS1.Bits.ILR71
#define ILRS1_ILR4                      _ILRS1.MergedBits.grpILR4
#define ILRS1_ILR5                      _ILRS1.MergedBits.grpILR5
#define ILRS1_ILR6                      _ILRS1.MergedBits.grpILR6
#define ILRS1_ILR7                      _ILRS1.MergedBits.grpILR7

#define ILRS1_ILR40_MASK                1U
#define ILRS1_ILR41_MASK                2U
#define ILRS1_ILR50_MASK                4U
#define ILRS1_ILR51_MASK                8U
#define ILRS1_ILR60_MASK                16U
#define ILRS1_ILR61_MASK                32U
#define ILRS1_ILR70_MASK                64U
#define ILRS1_ILR71_MASK                128U
#define ILRS1_ILR4_MASK                 3U
#define ILRS1_ILR4_BITNUM               0U
#define ILRS1_ILR5_MASK                 12U
#define ILRS1_ILR5_BITNUM               2U
#define ILRS1_ILR6_MASK                 48U
#define ILRS1_ILR6_BITNUM               4U
#define ILRS1_ILR7_MASK                 192U
#define ILRS1_ILR7_BITNUM               6U


/*** ILRS2 - Interrupt Level Setting Register; 0x00000062 ***/
typedef union {
  byte Byte;
  struct {
    byte ILR80       :1;                                       /* Interrupt Level Register for Source 8, bit 0 */
    byte ILR81       :1;                                       /* Interrupt Level Register for Source 8, bit 1 */
    byte ILR90       :1;                                       /* Interrupt Level Register for Source 9, bit 0 */
    byte ILR91       :1;                                       /* Interrupt Level Register for Source 9, bit 1 */
    byte ILR100      :1;                                       /* Interrupt Level Register for Source 10, bit 0 */
    byte ILR101      :1;                                       /* Interrupt Level Register for Source 10, bit 1 */
    byte ILR110      :1;                                       /* Interrupt Level Register for Source 11, bit 0 */
    byte ILR111      :1;                                       /* Interrupt Level Register for Source 11, bit 1 */
  } Bits;
  struct {
    byte grpILR8 :2;
    byte grpILR9 :2;
    byte grpILR10 :2;
    byte grpILR11 :2;
  } MergedBits;
} ILRS2STR;
extern volatile ILRS2STR _ILRS2 @0x00000062;
#define ILRS2                           _ILRS2.Byte
#define ILRS2_ILR80                     _ILRS2.Bits.ILR80
#define ILRS2_ILR81                     _ILRS2.Bits.ILR81
#define ILRS2_ILR90                     _ILRS2.Bits.ILR90
#define ILRS2_ILR91                     _ILRS2.Bits.ILR91
#define ILRS2_ILR100                    _ILRS2.Bits.ILR100
#define ILRS2_ILR101                    _ILRS2.Bits.ILR101
#define ILRS2_ILR110                    _ILRS2.Bits.ILR110
#define ILRS2_ILR111                    _ILRS2.Bits.ILR111
#define ILRS2_ILR8                      _ILRS2.MergedBits.grpILR8
#define ILRS2_ILR9                      _ILRS2.MergedBits.grpILR9
#define ILRS2_ILR10                     _ILRS2.MergedBits.grpILR10
#define ILRS2_ILR11                     _ILRS2.MergedBits.grpILR11

#define ILRS2_ILR80_MASK                1U
#define ILRS2_ILR81_MASK                2U
#define ILRS2_ILR90_MASK                4U
#define ILRS2_ILR91_MASK                8U
#define ILRS2_ILR100_MASK               16U
#define ILRS2_ILR101_MASK               32U
#define ILRS2_ILR110_MASK               64U
#define ILRS2_ILR111_MASK               128U
#define ILRS2_ILR8_MASK                 3U
#define ILRS2_ILR8_BITNUM               0U
#define ILRS2_ILR9_MASK                 12U
#define ILRS2_ILR9_BITNUM               2U
#define ILRS2_ILR10_MASK                48U
#define ILRS2_ILR10_BITNUM              4U
#define ILRS2_ILR11_MASK                192U
#define ILRS2_ILR11_BITNUM              6U


/*** ILRS3 - Interrupt Level Setting Register; 0x00000063 ***/
typedef union {
  byte Byte;
  struct {
    byte ILR120      :1;                                       /* Interrupt Level Register for Source 12, bit 0 */
    byte ILR121      :1;                                       /* Interrupt Level Register for Source 12, bit 1 */
    byte ILR130      :1;                                       /* Interrupt Level Register for Source 13, bit 0 */
    byte ILR131      :1;                                       /* Interrupt Level Register for Source 13, bit 1 */
    byte ILR140      :1;                                       /* Interrupt Level Register for Source 14, bit 0 */
    byte ILR141      :1;                                       /* Interrupt Level Register for Source 14, bit 1 */
    byte ILR150      :1;                                       /* Interrupt Level Register for Source 15, bit 0 */
    byte ILR151      :1;                                       /* Interrupt Level Register for Source 15, bit 1 */
  } Bits;
  struct {
    byte grpILR12 :2;
    byte grpILR13 :2;
    byte grpILR14 :2;
    byte grpILR15 :2;
  } MergedBits;
} ILRS3STR;
extern volatile ILRS3STR _ILRS3 @0x00000063;
#define ILRS3                           _ILRS3.Byte
#define ILRS3_ILR120                    _ILRS3.Bits.ILR120
#define ILRS3_ILR121                    _ILRS3.Bits.ILR121
#define ILRS3_ILR130                    _ILRS3.Bits.ILR130
#define ILRS3_ILR131                    _ILRS3.Bits.ILR131
#define ILRS3_ILR140                    _ILRS3.Bits.ILR140
#define ILRS3_ILR141                    _ILRS3.Bits.ILR141
#define ILRS3_ILR150                    _ILRS3.Bits.ILR150
#define ILRS3_ILR151                    _ILRS3.Bits.ILR151
#define ILRS3_ILR12                     _ILRS3.MergedBits.grpILR12
#define ILRS3_ILR13                     _ILRS3.MergedBits.grpILR13
#define ILRS3_ILR14                     _ILRS3.MergedBits.grpILR14
#define ILRS3_ILR15                     _ILRS3.MergedBits.grpILR15

#define ILRS3_ILR120_MASK               1U
#define ILRS3_ILR121_MASK               2U
#define ILRS3_ILR130_MASK               4U
#define ILRS3_ILR131_MASK               8U
#define ILRS3_ILR140_MASK               16U
#define ILRS3_ILR141_MASK               32U
#define ILRS3_ILR150_MASK               64U
#define ILRS3_ILR151_MASK               128U
#define ILRS3_ILR12_MASK                3U
#define ILRS3_ILR12_BITNUM              0U
#define ILRS3_ILR13_MASK                12U
#define ILRS3_ILR13_BITNUM              2U
#define ILRS3_ILR14_MASK                48U
#define ILRS3_ILR14_BITNUM              4U
#define ILRS3_ILR15_MASK                192U
#define ILRS3_ILR15_BITNUM              6U


/*** ILRS4 - Interrupt Level Setting Register; 0x00000064 ***/
typedef union {
  byte Byte;
  struct {
    byte ILR160      :1;                                       /* Interrupt Level Register for Source 16, bit 0 */
    byte ILR161      :1;                                       /* Interrupt Level Register for Source 16, bit 1 */
    byte ILR170      :1;                                       /* Interrupt Level Register for Source 17, bit 0 */
    byte ILR171      :1;                                       /* Interrupt Level Register for Source 17, bit 1 */
    byte ILR180      :1;                                       /* Interrupt Level Register for Source 18, bit 0 */
    byte ILR181      :1;                                       /* Interrupt Level Register for Source 18, bit 1 */
    byte ILR190      :1;                                       /* Interrupt Level Register for Source 19, bit 0 */
    byte ILR191      :1;                                       /* Interrupt Level Register for Source 19, bit 1 */
  } Bits;
  struct {
    byte grpILR16 :2;
    byte grpILR17 :2;
    byte grpILR18 :2;
    byte grpILR19 :2;
  } MergedBits;
} ILRS4STR;
extern volatile ILRS4STR _ILRS4 @0x00000064;
#define ILRS4                           _ILRS4.Byte
#define ILRS4_ILR160                    _ILRS4.Bits.ILR160
#define ILRS4_ILR161                    _ILRS4.Bits.ILR161
#define ILRS4_ILR170                    _ILRS4.Bits.ILR170
#define ILRS4_ILR171                    _ILRS4.Bits.ILR171
#define ILRS4_ILR180                    _ILRS4.Bits.ILR180
#define ILRS4_ILR181                    _ILRS4.Bits.ILR181
#define ILRS4_ILR190                    _ILRS4.Bits.ILR190
#define ILRS4_ILR191                    _ILRS4.Bits.ILR191
#define ILRS4_ILR16                     _ILRS4.MergedBits.grpILR16
#define ILRS4_ILR17                     _ILRS4.MergedBits.grpILR17
#define ILRS4_ILR18                     _ILRS4.MergedBits.grpILR18
#define ILRS4_ILR19                     _ILRS4.MergedBits.grpILR19

#define ILRS4_ILR160_MASK               1U
#define ILRS4_ILR161_MASK               2U
#define ILRS4_ILR170_MASK               4U
#define ILRS4_ILR171_MASK               8U
#define ILRS4_ILR180_MASK               16U
#define ILRS4_ILR181_MASK               32U
#define ILRS4_ILR190_MASK               64U
#define ILRS4_ILR191_MASK               128U
#define ILRS4_ILR16_MASK                3U
#define ILRS4_ILR16_BITNUM              0U
#define ILRS4_ILR17_MASK                12U
#define ILRS4_ILR17_BITNUM              2U
#define ILRS4_ILR18_MASK                48U
#define ILRS4_ILR18_BITNUM              4U
#define ILRS4_ILR19_MASK                192U
#define ILRS4_ILR19_BITNUM              6U


/*** ILRS5 - Interrupt Level Setting Register; 0x00000065 ***/
typedef union {
  byte Byte;
  struct {
    byte ILR200      :1;                                       /* Interrupt Level Register for Source 20, bit 0 */
    byte ILR201      :1;                                       /* Interrupt Level Register for Source 20, bit 1 */
    byte ILR210      :1;                                       /* Interrupt Level Register for Source 21, bit 0 */
    byte ILR211      :1;                                       /* Interrupt Level Register for Source 21, bit 1 */
    byte ILR220      :1;                                       /* Interrupt Level Register for Source 22, bit 0 */
    byte ILR221      :1;                                       /* Interrupt Level Register for Source 22, bit 1 */
    byte ILR230      :1;                                       /* Interrupt Level Register for Source 23, bit 0 */
    byte ILR231      :1;                                       /* Interrupt Level Register for Source 23, bit 1 */
  } Bits;
  struct {
    byte grpILR20 :2;
    byte grpILR21 :2;
    byte grpILR22 :2;
    byte grpILR23 :2;
  } MergedBits;
} ILRS5STR;
extern volatile ILRS5STR _ILRS5 @0x00000065;
#define ILRS5                           _ILRS5.Byte
#define ILRS5_ILR200                    _ILRS5.Bits.ILR200
#define ILRS5_ILR201                    _ILRS5.Bits.ILR201
#define ILRS5_ILR210                    _ILRS5.Bits.ILR210
#define ILRS5_ILR211                    _ILRS5.Bits.ILR211
#define ILRS5_ILR220                    _ILRS5.Bits.ILR220
#define ILRS5_ILR221                    _ILRS5.Bits.ILR221
#define ILRS5_ILR230                    _ILRS5.Bits.ILR230
#define ILRS5_ILR231                    _ILRS5.Bits.ILR231
#define ILRS5_ILR20                     _ILRS5.MergedBits.grpILR20
#define ILRS5_ILR21                     _ILRS5.MergedBits.grpILR21
#define ILRS5_ILR22                     _ILRS5.MergedBits.grpILR22
#define ILRS5_ILR23                     _ILRS5.MergedBits.grpILR23

#define ILRS5_ILR200_MASK               1U
#define ILRS5_ILR201_MASK               2U
#define ILRS5_ILR210_MASK               4U
#define ILRS5_ILR211_MASK               8U
#define ILRS5_ILR220_MASK               16U
#define ILRS5_ILR221_MASK               32U
#define ILRS5_ILR230_MASK               64U
#define ILRS5_ILR231_MASK               128U
#define ILRS5_ILR20_MASK                3U
#define ILRS5_ILR20_BITNUM              0U
#define ILRS5_ILR21_MASK                12U
#define ILRS5_ILR21_BITNUM              2U
#define ILRS5_ILR22_MASK                48U
#define ILRS5_ILR22_BITNUM              4U
#define ILRS5_ILR23_MASK                192U
#define ILRS5_ILR23_BITNUM              6U


/*** ILRS6 - Interrupt Level Setting Register; 0x00000066 ***/
typedef union {
  byte Byte;
  struct {
    byte ILR240      :1;                                       /* Interrupt Level Register for Source 24, bit 0 */
    byte ILR241      :1;                                       /* Interrupt Level Register for Source 24, bit 1 */
    byte ILR250      :1;                                       /* Interrupt Level Register for Source 25, bit 0 */
    byte ILR251      :1;                                       /* Interrupt Level Register for Source 25, bit 1 */
    byte ILR260      :1;                                       /* Interrupt Level Register for Source 26, bit 0 */
    byte ILR261      :1;                                       /* Interrupt Level Register for Source 26, bit 1 */
    byte ILR270      :1;                                       /* Interrupt Level Register for Source 27, bit 0 */
    byte ILR271      :1;                                       /* Interrupt Level Register for Source 27, bit 1 */
  } Bits;
  struct {
    byte grpILR24 :2;
    byte grpILR25 :2;
    byte grpILR26 :2;
    byte grpILR27 :2;
  } MergedBits;
} ILRS6STR;
extern volatile ILRS6STR _ILRS6 @0x00000066;
#define ILRS6                           _ILRS6.Byte
#define ILRS6_ILR240                    _ILRS6.Bits.ILR240
#define ILRS6_ILR241                    _ILRS6.Bits.ILR241
#define ILRS6_ILR250                    _ILRS6.Bits.ILR250
#define ILRS6_ILR251                    _ILRS6.Bits.ILR251
#define ILRS6_ILR260                    _ILRS6.Bits.ILR260
#define ILRS6_ILR261                    _ILRS6.Bits.ILR261
#define ILRS6_ILR270                    _ILRS6.Bits.ILR270
#define ILRS6_ILR271                    _ILRS6.Bits.ILR271
#define ILRS6_ILR24                     _ILRS6.MergedBits.grpILR24
#define ILRS6_ILR25                     _ILRS6.MergedBits.grpILR25
#define ILRS6_ILR26                     _ILRS6.MergedBits.grpILR26
#define ILRS6_ILR27                     _ILRS6.MergedBits.grpILR27

#define ILRS6_ILR240_MASK               1U
#define ILRS6_ILR241_MASK               2U
#define ILRS6_ILR250_MASK               4U
#define ILRS6_ILR251_MASK               8U
#define ILRS6_ILR260_MASK               16U
#define ILRS6_ILR261_MASK               32U
#define ILRS6_ILR270_MASK               64U
#define ILRS6_ILR271_MASK               128U
#define ILRS6_ILR24_MASK                3U
#define ILRS6_ILR24_BITNUM              0U
#define ILRS6_ILR25_MASK                12U
#define ILRS6_ILR25_BITNUM              2U
#define ILRS6_ILR26_MASK                48U
#define ILRS6_ILR26_BITNUM              4U
#define ILRS6_ILR27_MASK                192U
#define ILRS6_ILR27_BITNUM              6U


/*** ILRS7 - Interrupt Level Setting Register; 0x00000067 ***/
typedef union {
  byte Byte;
  struct {
    byte ILR280      :1;                                       /* Interrupt Level Register for Source 28, bit 0 */
    byte ILR281      :1;                                       /* Interrupt Level Register for Source 28, bit 1 */
    byte ILR290      :1;                                       /* Interrupt Level Register for Source 29, bit 0 */
    byte ILR291      :1;                                       /* Interrupt Level Register for Source 29, bit 1 */
    byte ILR300      :1;                                       /* Interrupt Level Register for Source 30, bit 0 */
    byte ILR301      :1;                                       /* Interrupt Level Register for Source 30, bit 1 */
    byte ILR310      :1;                                       /* Interrupt Level Register for Source 31, bit 0 */
    byte ILR311      :1;                                       /* Interrupt Level Register for Source 31, bit 1 */
  } Bits;
  struct {
    byte grpILR28 :2;
    byte grpILR29 :2;
    byte grpILR30 :2;
    byte grpILR31 :2;
  } MergedBits;
} ILRS7STR;
extern volatile ILRS7STR _ILRS7 @0x00000067;
#define ILRS7                           _ILRS7.Byte
#define ILRS7_ILR280                    _ILRS7.Bits.ILR280
#define ILRS7_ILR281                    _ILRS7.Bits.ILR281
#define ILRS7_ILR290                    _ILRS7.Bits.ILR290
#define ILRS7_ILR291                    _ILRS7.Bits.ILR291
#define ILRS7_ILR300                    _ILRS7.Bits.ILR300
#define ILRS7_ILR301                    _ILRS7.Bits.ILR301
#define ILRS7_ILR310                    _ILRS7.Bits.ILR310
#define ILRS7_ILR311                    _ILRS7.Bits.ILR311
#define ILRS7_ILR28                     _ILRS7.MergedBits.grpILR28
#define ILRS7_ILR29                     _ILRS7.MergedBits.grpILR29
#define ILRS7_ILR30                     _ILRS7.MergedBits.grpILR30
#define ILRS7_ILR31                     _ILRS7.MergedBits.grpILR31

#define ILRS7_ILR280_MASK               1U
#define ILRS7_ILR281_MASK               2U
#define ILRS7_ILR290_MASK               4U
#define ILRS7_ILR291_MASK               8U
#define ILRS7_ILR300_MASK               16U
#define ILRS7_ILR301_MASK               32U
#define ILRS7_ILR310_MASK               64U
#define ILRS7_ILR311_MASK               128U
#define ILRS7_ILR28_MASK                3U
#define ILRS7_ILR28_BITNUM              0U
#define ILRS7_ILR29_MASK                12U
#define ILRS7_ILR29_BITNUM              2U
#define ILRS7_ILR30_MASK                48U
#define ILRS7_ILR30_BITNUM              4U
#define ILRS7_ILR31_MASK                192U
#define ILRS7_ILR31_BITNUM              6U


/*** SCIBD - SCI Baud Rate Register; 0x00000068 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** SCIBDH - SCI Baud Rate Register High; 0x00000068 ***/
    union {
      byte Byte;
      struct {
        byte SBR8        :1;                                       /* Baud Rate Modulo Divisor Bit 8 */
        byte SBR9        :1;                                       /* Baud Rate Modulo Divisor Bit 9 */
        byte SBR10       :1;                                       /* Baud Rate Modulo Divisor Bit 10 */
        byte SBR11       :1;                                       /* Baud Rate Modulo Divisor Bit 11 */
        byte SBR12       :1;                                       /* Baud Rate Modulo Divisor Bit 12 */
        byte             :1; 
        byte RXEDGIE     :1;                                       /* RxD Input Active Edge Interrupt Enable (for RXEDGIF) */
        byte LBKDIE      :1;                                       /* LIN Break Detect Interrupt Enable (for LBKDIF) */
      } Bits;
      struct {
        byte grpSBR_8 :5;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } SCIBDHSTR;
    #define SCIBDH                      _SCIBD.Overlap_STR.SCIBDHSTR.Byte
    #define SCIBDH_SBR8                 _SCIBD.Overlap_STR.SCIBDHSTR.Bits.SBR8
    #define SCIBDH_SBR9                 _SCIBD.Overlap_STR.SCIBDHSTR.Bits.SBR9
    #define SCIBDH_SBR10                _SCIBD.Overlap_STR.SCIBDHSTR.Bits.SBR10
    #define SCIBDH_SBR11                _SCIBD.Overlap_STR.SCIBDHSTR.Bits.SBR11
    #define SCIBDH_SBR12                _SCIBD.Overlap_STR.SCIBDHSTR.Bits.SBR12
    #define SCIBDH_RXEDGIE              _SCIBD.Overlap_STR.SCIBDHSTR.Bits.RXEDGIE
    #define SCIBDH_LBKDIE               _SCIBD.Overlap_STR.SCIBDHSTR.Bits.LBKDIE
    #define SCIBDH_SBR_8                _SCIBD.Overlap_STR.SCIBDHSTR.MergedBits.grpSBR_8
    #define SCIBDH_SBR                  SCIBDH_SBR_8
    
    #define SCIBDH_SBR8_MASK            1U
    #define SCIBDH_SBR9_MASK            2U
    #define SCIBDH_SBR10_MASK           4U
    #define SCIBDH_SBR11_MASK           8U
    #define SCIBDH_SBR12_MASK           16U
    #define SCIBDH_RXEDGIE_MASK         64U
    #define SCIBDH_LBKDIE_MASK          128U
    #define SCIBDH_SBR_8_MASK           31U
    #define SCIBDH_SBR_8_BITNUM         0U
    

    /*** SCIBDL - SCI Baud Rate Register Low; 0x00000069 ***/
    union {
      byte Byte;
      struct {
        byte SBR0        :1;                                       /* Baud Rate Modulo Divisor Bit 0 */
        byte SBR1        :1;                                       /* Baud Rate Modulo Divisor Bit 1 */
        byte SBR2        :1;                                       /* Baud Rate Modulo Divisor Bit 2 */
        byte SBR3        :1;                                       /* Baud Rate Modulo Divisor Bit 3 */
        byte SBR4        :1;                                       /* Baud Rate Modulo Divisor Bit 4 */
        byte SBR5        :1;                                       /* Baud Rate Modulo Divisor Bit 5 */
        byte SBR6        :1;                                       /* Baud Rate Modulo Divisor Bit 6 */
        byte SBR7        :1;                                       /* Baud Rate Modulo Divisor Bit 7 */
      } Bits;
    } SCIBDLSTR;
    #define SCIBDL                      _SCIBD.Overlap_STR.SCIBDLSTR.Byte
    #define SCIBDL_SBR0                 _SCIBD.Overlap_STR.SCIBDLSTR.Bits.SBR0
    #define SCIBDL_SBR1                 _SCIBD.Overlap_STR.SCIBDLSTR.Bits.SBR1
    #define SCIBDL_SBR2                 _SCIBD.Overlap_STR.SCIBDLSTR.Bits.SBR2
    #define SCIBDL_SBR3                 _SCIBD.Overlap_STR.SCIBDLSTR.Bits.SBR3
    #define SCIBDL_SBR4                 _SCIBD.Overlap_STR.SCIBDLSTR.Bits.SBR4
    #define SCIBDL_SBR5                 _SCIBD.Overlap_STR.SCIBDLSTR.Bits.SBR5
    #define SCIBDL_SBR6                 _SCIBD.Overlap_STR.SCIBDLSTR.Bits.SBR6
    #define SCIBDL_SBR7                 _SCIBD.Overlap_STR.SCIBDLSTR.Bits.SBR7
    
    #define SCIBDL_SBR0_MASK            1U
    #define SCIBDL_SBR1_MASK            2U
    #define SCIBDL_SBR2_MASK            4U
    #define SCIBDL_SBR3_MASK            8U
    #define SCIBDL_SBR4_MASK            16U
    #define SCIBDL_SBR5_MASK            32U
    #define SCIBDL_SBR6_MASK            64U
    #define SCIBDL_SBR7_MASK            128U
    
  } Overlap_STR;

} SCIBDSTR;
extern volatile SCIBDSTR _SCIBD @0x00000068;
#define SCIBD                           _SCIBD.Word


/*** SCIC1 - SCI Control Register 1; 0x0000006A ***/
typedef union {
  byte Byte;
  struct {
    byte PT          :1;                                       /* Parity Type */
    byte PE          :1;                                       /* Parity Enable */
    byte ILT         :1;                                       /* Idle Line Type Select */
    byte WAKE        :1;                                       /* Receiver Wakeup Method Select */
    byte M           :1;                                       /* 9-Bit or 8-Bit Mode Select */
    byte RSRC        :1;                                       /* Receiver Source Select */
    byte SCISWAI     :1;                                       /* SCI Stops in Wait Mode */
    byte LOOPS       :1;                                       /* Loop Mode Select */
  } Bits;
} SCIC1STR;
extern volatile SCIC1STR _SCIC1 @0x0000006A;
#define SCIC1                           _SCIC1.Byte
#define SCIC1_PT                        _SCIC1.Bits.PT
#define SCIC1_PE                        _SCIC1.Bits.PE
#define SCIC1_ILT                       _SCIC1.Bits.ILT
#define SCIC1_WAKE                      _SCIC1.Bits.WAKE
#define SCIC1_M                         _SCIC1.Bits.M
#define SCIC1_RSRC                      _SCIC1.Bits.RSRC
#define SCIC1_SCISWAI                   _SCIC1.Bits.SCISWAI
#define SCIC1_LOOPS                     _SCIC1.Bits.LOOPS

#define SCIC1_PT_MASK                   1U
#define SCIC1_PE_MASK                   2U
#define SCIC1_ILT_MASK                  4U
#define SCIC1_WAKE_MASK                 8U
#define SCIC1_M_MASK                    16U
#define SCIC1_RSRC_MASK                 32U
#define SCIC1_SCISWAI_MASK              64U
#define SCIC1_LOOPS_MASK                128U


/*** SCIC2 - SCI Control Register 2; 0x0000006B ***/
typedef union {
  byte Byte;
  struct {
    byte SBK         :1;                                       /* Send Break */
    byte RWU         :1;                                       /* Receiver Wakeup Control */
    byte RE          :1;                                       /* Receiver Enable */
    byte TE          :1;                                       /* Transmitter Enable */
    byte ILIE        :1;                                       /* Idle Line Interrupt Enable (for IDLE) */
    byte RIE         :1;                                       /* Receiver Interrupt Enable (for RDRF) */
    byte TCIE        :1;                                       /* Transmission Complete Interrupt Enable (for TC) */
    byte TIE         :1;                                       /* Transmit Interrupt Enable (for TDRE) */
  } Bits;
} SCIC2STR;
extern volatile SCIC2STR _SCIC2 @0x0000006B;
#define SCIC2                           _SCIC2.Byte
#define SCIC2_SBK                       _SCIC2.Bits.SBK
#define SCIC2_RWU                       _SCIC2.Bits.RWU
#define SCIC2_RE                        _SCIC2.Bits.RE
#define SCIC2_TE                        _SCIC2.Bits.TE
#define SCIC2_ILIE                      _SCIC2.Bits.ILIE
#define SCIC2_RIE                       _SCIC2.Bits.RIE
#define SCIC2_TCIE                      _SCIC2.Bits.TCIE
#define SCIC2_TIE                       _SCIC2.Bits.TIE

#define SCIC2_SBK_MASK                  1U
#define SCIC2_RWU_MASK                  2U
#define SCIC2_RE_MASK                   4U
#define SCIC2_TE_MASK                   8U
#define SCIC2_ILIE_MASK                 16U
#define SCIC2_RIE_MASK                  32U
#define SCIC2_TCIE_MASK                 64U
#define SCIC2_TIE_MASK                  128U


/*** SCIS1 - SCI Status Register 1; 0x0000006C ***/
typedef union {
  byte Byte;
  struct {
    byte PF          :1;                                       /* Parity Error Flag */
    byte FE          :1;                                       /* Framing Error Flag */
    byte NF          :1;                                       /* Noise Flag */
    byte OR          :1;                                       /* Receiver Overrun Flag */
    byte IDLE        :1;                                       /* Idle Line Flag */
    byte RDRF        :1;                                       /* Receive Data Register Full Flag */
    byte TC          :1;                                       /* Transmission Complete Flag */
    byte TDRE        :1;                                       /* Transmit Data Register Empty Flag */
  } Bits;
} SCIS1STR;
extern volatile SCIS1STR _SCIS1 @0x0000006C;
#define SCIS1                           _SCIS1.Byte
#define SCIS1_PF                        _SCIS1.Bits.PF
#define SCIS1_FE                        _SCIS1.Bits.FE
#define SCIS1_NF                        _SCIS1.Bits.NF
#define SCIS1_OR                        _SCIS1.Bits.OR
#define SCIS1_IDLE                      _SCIS1.Bits.IDLE
#define SCIS1_RDRF                      _SCIS1.Bits.RDRF
#define SCIS1_TC                        _SCIS1.Bits.TC
#define SCIS1_TDRE                      _SCIS1.Bits.TDRE

#define SCIS1_PF_MASK                   1U
#define SCIS1_FE_MASK                   2U
#define SCIS1_NF_MASK                   4U
#define SCIS1_OR_MASK                   8U
#define SCIS1_IDLE_MASK                 16U
#define SCIS1_RDRF_MASK                 32U
#define SCIS1_TC_MASK                   64U
#define SCIS1_TDRE_MASK                 128U


/*** SCIS2 - SCI Status Register 2; 0x0000006D ***/
typedef union {
  byte Byte;
  struct {
    byte RAF         :1;                                       /* Receiver Active Flag */
    byte LBKDE       :1;                                       /* LIN Break Detection Enable */
    byte BRK13       :1;                                       /* Break Character Generation Length */
    byte RWUID       :1;                                       /* Receive Wake Up Idle Detect */
    byte RXINV       :1;                                       /* Receive Data Inversion */
    byte             :1; 
    byte RXEDGIF     :1;                                       /* RxD Pin Active Edge Interrupt Flag */
    byte LBKDIF      :1;                                       /* LIN Break Detect Interrupt Flag */
  } Bits;
} SCIS2STR;
extern volatile SCIS2STR _SCIS2 @0x0000006D;
#define SCIS2                           _SCIS2.Byte
#define SCIS2_RAF                       _SCIS2.Bits.RAF
#define SCIS2_LBKDE                     _SCIS2.Bits.LBKDE
#define SCIS2_BRK13                     _SCIS2.Bits.BRK13
#define SCIS2_RWUID                     _SCIS2.Bits.RWUID
#define SCIS2_RXINV                     _SCIS2.Bits.RXINV
#define SCIS2_RXEDGIF                   _SCIS2.Bits.RXEDGIF
#define SCIS2_LBKDIF                    _SCIS2.Bits.LBKDIF

#define SCIS2_RAF_MASK                  1U
#define SCIS2_LBKDE_MASK                2U
#define SCIS2_BRK13_MASK                4U
#define SCIS2_RWUID_MASK                8U
#define SCIS2_RXINV_MASK                16U
#define SCIS2_RXEDGIF_MASK              64U
#define SCIS2_LBKDIF_MASK               128U


/*** SCIC3 - SCI Control Register 3; 0x0000006E ***/
typedef union {
  byte Byte;
  struct {
    byte PEIE        :1;                                       /* Parity Error Interrupt Enable */
    byte FEIE        :1;                                       /* Framing Error Interrupt Enable */
    byte NEIE        :1;                                       /* Noise Error Interrupt Enable */
    byte ORIE        :1;                                       /* Overrun Interrupt Enable */
    byte TXINV       :1;                                       /* Transmit Data Inversion */
    byte TXDIR       :1;                                       /* TxD Pin Direction in Single-Wire Mode */
    byte T8          :1;                                       /* Ninth Data Bit for Transmitter */
    byte R8          :1;                                       /* Ninth Data Bit for Receiver */
  } Bits;
} SCIC3STR;
extern volatile SCIC3STR _SCIC3 @0x0000006E;
#define SCIC3                           _SCIC3.Byte
#define SCIC3_PEIE                      _SCIC3.Bits.PEIE
#define SCIC3_FEIE                      _SCIC3.Bits.FEIE
#define SCIC3_NEIE                      _SCIC3.Bits.NEIE
#define SCIC3_ORIE                      _SCIC3.Bits.ORIE
#define SCIC3_TXINV                     _SCIC3.Bits.TXINV
#define SCIC3_TXDIR                     _SCIC3.Bits.TXDIR
#define SCIC3_T8                        _SCIC3.Bits.T8
#define SCIC3_R8                        _SCIC3.Bits.R8

#define SCIC3_PEIE_MASK                 1U
#define SCIC3_FEIE_MASK                 2U
#define SCIC3_NEIE_MASK                 4U
#define SCIC3_ORIE_MASK                 8U
#define SCIC3_TXINV_MASK                16U
#define SCIC3_TXDIR_MASK                32U
#define SCIC3_T8_MASK                   64U
#define SCIC3_R8_MASK                   128U


/*** SCID - SCI Data Register; 0x0000006F ***/
typedef union {
  byte Byte;
  struct {
    byte R0_T0       :1;                                       /* Receive/Transmit Data Bit 0 */
    byte R1_T1       :1;                                       /* Receive/Transmit Data Bit 1 */
    byte R2_T2       :1;                                       /* Receive/Transmit Data Bit 2 */
    byte R3_T3       :1;                                       /* Receive/Transmit Data Bit 3 */
    byte R4_T4       :1;                                       /* Receive/Transmit Data Bit 4 */
    byte R5_T5       :1;                                       /* Receive/Transmit Data Bit 5 */
    byte R6_T6       :1;                                       /* Receive/Transmit Data Bit 6 */
    byte R7_T7       :1;                                       /* Receive/Transmit Data Bit 7 */
  } Bits;
} SCIDSTR;
extern volatile SCIDSTR _SCID @0x0000006F;
#define SCID                            _SCID.Byte
#define SCID_R0_T0                      _SCID.Bits.R0_T0
#define SCID_R1_T1                      _SCID.Bits.R1_T1
#define SCID_R2_T2                      _SCID.Bits.R2_T2
#define SCID_R3_T3                      _SCID.Bits.R3_T3
#define SCID_R4_T4                      _SCID.Bits.R4_T4
#define SCID_R5_T5                      _SCID.Bits.R5_T5
#define SCID_R6_T6                      _SCID.Bits.R6_T6
#define SCID_R7_T7                      _SCID.Bits.R7_T7

#define SCID_R0_T0_MASK                 1U
#define SCID_R1_T1_MASK                 2U
#define SCID_R2_T2_MASK                 4U
#define SCID_R3_T3_MASK                 8U
#define SCID_R4_T4_MASK                 16U
#define SCID_R5_T5_MASK                 32U
#define SCID_R6_T6_MASK                 64U
#define SCID_R7_T7_MASK                 128U


/*** PDB1CTRL1 - PDB1 Control 1 Register; 0x00000070 ***/
typedef union {
  byte Byte;
  struct {
    byte LDOK        :1;                                       /* Load OK */
    byte ENA         :1;                                       /* Trigger A Enable */
    byte AOS0        :1;                                       /* Trigger A Output Select, bit 0 */
    byte AOS1        :1;                                       /* Trigger A Output Select, bit 1 */
    byte ENB         :1;                                       /* Trigger B Enable */
    byte BOS0        :1;                                       /* Trigger B Output Select, bit 0 */
    byte BOS1        :1;                                       /* Trigger B Output Select, bit 1 */
    byte LDMOD       :1;                                       /* Load mode select */
  } Bits;
  struct {
    byte         :1;
    byte grpENx  :1;
    byte grpAOS  :2;
    byte         :1;
    byte grpBOS  :2;
    byte         :1;
  } MergedBits;
} PDB1CTRL1STR;
extern volatile PDB1CTRL1STR _PDB1CTRL1 @0x00000070;
#define PDB1CTRL1                       _PDB1CTRL1.Byte
#define PDB1CTRL1_LDOK                  _PDB1CTRL1.Bits.LDOK
#define PDB1CTRL1_ENA                   _PDB1CTRL1.Bits.ENA
#define PDB1CTRL1_AOS0                  _PDB1CTRL1.Bits.AOS0
#define PDB1CTRL1_AOS1                  _PDB1CTRL1.Bits.AOS1
#define PDB1CTRL1_ENB                   _PDB1CTRL1.Bits.ENB
#define PDB1CTRL1_BOS0                  _PDB1CTRL1.Bits.BOS0
#define PDB1CTRL1_BOS1                  _PDB1CTRL1.Bits.BOS1
#define PDB1CTRL1_LDMOD                 _PDB1CTRL1.Bits.LDMOD
#define PDB1CTRL1_AOS                   _PDB1CTRL1.MergedBits.grpAOS
#define PDB1CTRL1_BOS                   _PDB1CTRL1.MergedBits.grpBOS

#define PDB1CTRL1_LDOK_MASK             1U
#define PDB1CTRL1_ENA_MASK              2U
#define PDB1CTRL1_AOS0_MASK             4U
#define PDB1CTRL1_AOS1_MASK             8U
#define PDB1CTRL1_ENB_MASK              16U
#define PDB1CTRL1_BOS0_MASK             32U
#define PDB1CTRL1_BOS1_MASK             64U
#define PDB1CTRL1_LDMOD_MASK            128U
#define PDB1CTRL1_AOS_MASK              12U
#define PDB1CTRL1_AOS_BITNUM            2U
#define PDB1CTRL1_BOS_MASK              96U
#define PDB1CTRL1_BOS_BITNUM            5U


/*** PDB1CTRL2 - PDB1 Control 2 Register; 0x00000071 ***/
typedef union {
  byte Byte;
  struct {
    byte SWTRIG      :1;                                       /* Software Trigger */
    byte CONT        :1;                                       /* Continuous Mode Enable */
    byte TRIGSEL0    :1;                                       /* Input Trigger, bit 0 */
    byte TRIGSEL1    :1;                                       /* Input Trigger, bit 1 */
    byte TRIGSEL2    :1;                                       /* Input Trigger, bit 2 */
    byte PRESCALER0  :1;                                       /* Clock Prescaler, bit 0 */
    byte PRESCALER1  :1;                                       /* Clock Prescaler, bit 1 */
    byte PRESCALER2  :1;                                       /* Clock Prescaler, bit 2 */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpTRIGSEL :3;
    byte grpPRESCALER :3;
  } MergedBits;
} PDB1CTRL2STR;
extern volatile PDB1CTRL2STR _PDB1CTRL2 @0x00000071;
#define PDB1CTRL2                       _PDB1CTRL2.Byte
#define PDB1CTRL2_SWTRIG                _PDB1CTRL2.Bits.SWTRIG
#define PDB1CTRL2_CONT                  _PDB1CTRL2.Bits.CONT
#define PDB1CTRL2_TRIGSEL0              _PDB1CTRL2.Bits.TRIGSEL0
#define PDB1CTRL2_TRIGSEL1              _PDB1CTRL2.Bits.TRIGSEL1
#define PDB1CTRL2_TRIGSEL2              _PDB1CTRL2.Bits.TRIGSEL2
#define PDB1CTRL2_PRESCALER0            _PDB1CTRL2.Bits.PRESCALER0
#define PDB1CTRL2_PRESCALER1            _PDB1CTRL2.Bits.PRESCALER1
#define PDB1CTRL2_PRESCALER2            _PDB1CTRL2.Bits.PRESCALER2
#define PDB1CTRL2_TRIGSEL               _PDB1CTRL2.MergedBits.grpTRIGSEL
#define PDB1CTRL2_PRESCALER             _PDB1CTRL2.MergedBits.grpPRESCALER

#define PDB1CTRL2_SWTRIG_MASK           1U
#define PDB1CTRL2_CONT_MASK             2U
#define PDB1CTRL2_TRIGSEL0_MASK         4U
#define PDB1CTRL2_TRIGSEL1_MASK         8U
#define PDB1CTRL2_TRIGSEL2_MASK         16U
#define PDB1CTRL2_PRESCALER0_MASK       32U
#define PDB1CTRL2_PRESCALER1_MASK       64U
#define PDB1CTRL2_PRESCALER2_MASK       128U
#define PDB1CTRL2_TRIGSEL_MASK          28U
#define PDB1CTRL2_TRIGSEL_BITNUM        2U
#define PDB1CTRL2_PRESCALER_MASK        224U
#define PDB1CTRL2_PRESCALER_BITNUM      5U


/*** PDB1DLYA - PDB1 Delay A Register; 0x00000072 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PDB1DLYAH - PDB1 Delay A High Register; 0x00000072 ***/
    union {
      byte Byte;
      struct {
        byte DELAYA8     :1;                                       /* Delay A, bit 8 */
        byte DELAYA9     :1;                                       /* Delay A, bit 9 */
        byte DELAYA10    :1;                                       /* Delay A, bit 10 */
        byte DELAYA11    :1;                                       /* Delay A, bit 11 */
        byte DELAYA12    :1;                                       /* Delay A, bit 12 */
        byte DELAYA13    :1;                                       /* Delay A, bit 13 */
        byte DELAYA14    :1;                                       /* Delay A, bit 14 */
        byte DELAYA15    :1;                                       /* Delay A, bit 15 */
      } Bits;
    } PDB1DLYAHSTR;
    #define PDB1DLYAH                   _PDB1DLYA.Overlap_STR.PDB1DLYAHSTR.Byte
    #define PDB1DLYAH_DELAYA8           _PDB1DLYA.Overlap_STR.PDB1DLYAHSTR.Bits.DELAYA8
    #define PDB1DLYAH_DELAYA9           _PDB1DLYA.Overlap_STR.PDB1DLYAHSTR.Bits.DELAYA9
    #define PDB1DLYAH_DELAYA10          _PDB1DLYA.Overlap_STR.PDB1DLYAHSTR.Bits.DELAYA10
    #define PDB1DLYAH_DELAYA11          _PDB1DLYA.Overlap_STR.PDB1DLYAHSTR.Bits.DELAYA11
    #define PDB1DLYAH_DELAYA12          _PDB1DLYA.Overlap_STR.PDB1DLYAHSTR.Bits.DELAYA12
    #define PDB1DLYAH_DELAYA13          _PDB1DLYA.Overlap_STR.PDB1DLYAHSTR.Bits.DELAYA13
    #define PDB1DLYAH_DELAYA14          _PDB1DLYA.Overlap_STR.PDB1DLYAHSTR.Bits.DELAYA14
    #define PDB1DLYAH_DELAYA15          _PDB1DLYA.Overlap_STR.PDB1DLYAHSTR.Bits.DELAYA15
    
    #define PDB1DLYAH_DELAYA8_MASK      1U
    #define PDB1DLYAH_DELAYA9_MASK      2U
    #define PDB1DLYAH_DELAYA10_MASK     4U
    #define PDB1DLYAH_DELAYA11_MASK     8U
    #define PDB1DLYAH_DELAYA12_MASK     16U
    #define PDB1DLYAH_DELAYA13_MASK     32U
    #define PDB1DLYAH_DELAYA14_MASK     64U
    #define PDB1DLYAH_DELAYA15_MASK     128U
    

    /*** PDB1DLYAL - PDB1 Delay A Low Register; 0x00000073 ***/
    union {
      byte Byte;
      struct {
        byte DELAYA0     :1;                                       /* Delay A, bit 0 */
        byte DELAYA1     :1;                                       /* Delay A, bit 1 */
        byte DELAYA2     :1;                                       /* Delay A, bit 2 */
        byte DELAYA3     :1;                                       /* Delay A, bit 3 */
        byte DELAYA4     :1;                                       /* Delay A, bit 4 */
        byte DELAYA5     :1;                                       /* Delay A, bit 5 */
        byte DELAYA6     :1;                                       /* Delay A, bit 6 */
        byte DELAYA7     :1;                                       /* Delay A, bit 7 */
      } Bits;
    } PDB1DLYALSTR;
    #define PDB1DLYAL                   _PDB1DLYA.Overlap_STR.PDB1DLYALSTR.Byte
    #define PDB1DLYAL_DELAYA0           _PDB1DLYA.Overlap_STR.PDB1DLYALSTR.Bits.DELAYA0
    #define PDB1DLYAL_DELAYA1           _PDB1DLYA.Overlap_STR.PDB1DLYALSTR.Bits.DELAYA1
    #define PDB1DLYAL_DELAYA2           _PDB1DLYA.Overlap_STR.PDB1DLYALSTR.Bits.DELAYA2
    #define PDB1DLYAL_DELAYA3           _PDB1DLYA.Overlap_STR.PDB1DLYALSTR.Bits.DELAYA3
    #define PDB1DLYAL_DELAYA4           _PDB1DLYA.Overlap_STR.PDB1DLYALSTR.Bits.DELAYA4
    #define PDB1DLYAL_DELAYA5           _PDB1DLYA.Overlap_STR.PDB1DLYALSTR.Bits.DELAYA5
    #define PDB1DLYAL_DELAYA6           _PDB1DLYA.Overlap_STR.PDB1DLYALSTR.Bits.DELAYA6
    #define PDB1DLYAL_DELAYA7           _PDB1DLYA.Overlap_STR.PDB1DLYALSTR.Bits.DELAYA7
    
    #define PDB1DLYAL_DELAYA0_MASK      1U
    #define PDB1DLYAL_DELAYA1_MASK      2U
    #define PDB1DLYAL_DELAYA2_MASK      4U
    #define PDB1DLYAL_DELAYA3_MASK      8U
    #define PDB1DLYAL_DELAYA4_MASK      16U
    #define PDB1DLYAL_DELAYA5_MASK      32U
    #define PDB1DLYAL_DELAYA6_MASK      64U
    #define PDB1DLYAL_DELAYA7_MASK      128U
    
  } Overlap_STR;

} PDB1DLYASTR;
extern volatile PDB1DLYASTR _PDB1DLYA @0x00000072;
#define PDB1DLYA                        _PDB1DLYA.Word


/*** PDB1DLYB - PDB1 Delay B Register; 0x00000074 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PDB1DLYBH - PDB1 Delay B High Register; 0x00000074 ***/
    union {
      byte Byte;
      struct {
        byte DELAYB8     :1;                                       /* Delay B, bit 8 */
        byte DELAYB9     :1;                                       /* Delay B, bit 9 */
        byte DELAYB10    :1;                                       /* Delay B, bit 10 */
        byte DELAYB11    :1;                                       /* Delay B, bit 11 */
        byte DELAYB12    :1;                                       /* Delay B, bit 12 */
        byte DELAYB13    :1;                                       /* Delay B, bit 13 */
        byte DELAYB14    :1;                                       /* Delay B, bit 14 */
        byte DELAYB15    :1;                                       /* Delay B, bit 15 */
      } Bits;
    } PDB1DLYBHSTR;
    #define PDB1DLYBH                   _PDB1DLYB.Overlap_STR.PDB1DLYBHSTR.Byte
    #define PDB1DLYBH_DELAYB8           _PDB1DLYB.Overlap_STR.PDB1DLYBHSTR.Bits.DELAYB8
    #define PDB1DLYBH_DELAYB9           _PDB1DLYB.Overlap_STR.PDB1DLYBHSTR.Bits.DELAYB9
    #define PDB1DLYBH_DELAYB10          _PDB1DLYB.Overlap_STR.PDB1DLYBHSTR.Bits.DELAYB10
    #define PDB1DLYBH_DELAYB11          _PDB1DLYB.Overlap_STR.PDB1DLYBHSTR.Bits.DELAYB11
    #define PDB1DLYBH_DELAYB12          _PDB1DLYB.Overlap_STR.PDB1DLYBHSTR.Bits.DELAYB12
    #define PDB1DLYBH_DELAYB13          _PDB1DLYB.Overlap_STR.PDB1DLYBHSTR.Bits.DELAYB13
    #define PDB1DLYBH_DELAYB14          _PDB1DLYB.Overlap_STR.PDB1DLYBHSTR.Bits.DELAYB14
    #define PDB1DLYBH_DELAYB15          _PDB1DLYB.Overlap_STR.PDB1DLYBHSTR.Bits.DELAYB15
    
    #define PDB1DLYBH_DELAYB8_MASK      1U
    #define PDB1DLYBH_DELAYB9_MASK      2U
    #define PDB1DLYBH_DELAYB10_MASK     4U
    #define PDB1DLYBH_DELAYB11_MASK     8U
    #define PDB1DLYBH_DELAYB12_MASK     16U
    #define PDB1DLYBH_DELAYB13_MASK     32U
    #define PDB1DLYBH_DELAYB14_MASK     64U
    #define PDB1DLYBH_DELAYB15_MASK     128U
    

    /*** PDB1DLYBL - PDB1 Delay B Low Register; 0x00000075 ***/
    union {
      byte Byte;
      struct {
        byte DELAYB0     :1;                                       /* Delay B, bit 0 */
        byte DELAYB1     :1;                                       /* Delay B, bit 1 */
        byte DELAYB2     :1;                                       /* Delay B, bit 2 */
        byte DELAYB3     :1;                                       /* Delay B, bit 3 */
        byte DELAYB4     :1;                                       /* Delay B, bit 4 */
        byte DELAYB5     :1;                                       /* Delay B, bit 5 */
        byte DELAYB6     :1;                                       /* Delay B, bit 6 */
        byte DELAYB7     :1;                                       /* Delay B, bit 7 */
      } Bits;
    } PDB1DLYBLSTR;
    #define PDB1DLYBL                   _PDB1DLYB.Overlap_STR.PDB1DLYBLSTR.Byte
    #define PDB1DLYBL_DELAYB0           _PDB1DLYB.Overlap_STR.PDB1DLYBLSTR.Bits.DELAYB0
    #define PDB1DLYBL_DELAYB1           _PDB1DLYB.Overlap_STR.PDB1DLYBLSTR.Bits.DELAYB1
    #define PDB1DLYBL_DELAYB2           _PDB1DLYB.Overlap_STR.PDB1DLYBLSTR.Bits.DELAYB2
    #define PDB1DLYBL_DELAYB3           _PDB1DLYB.Overlap_STR.PDB1DLYBLSTR.Bits.DELAYB3
    #define PDB1DLYBL_DELAYB4           _PDB1DLYB.Overlap_STR.PDB1DLYBLSTR.Bits.DELAYB4
    #define PDB1DLYBL_DELAYB5           _PDB1DLYB.Overlap_STR.PDB1DLYBLSTR.Bits.DELAYB5
    #define PDB1DLYBL_DELAYB6           _PDB1DLYB.Overlap_STR.PDB1DLYBLSTR.Bits.DELAYB6
    #define PDB1DLYBL_DELAYB7           _PDB1DLYB.Overlap_STR.PDB1DLYBLSTR.Bits.DELAYB7
    
    #define PDB1DLYBL_DELAYB0_MASK      1U
    #define PDB1DLYBL_DELAYB1_MASK      2U
    #define PDB1DLYBL_DELAYB2_MASK      4U
    #define PDB1DLYBL_DELAYB3_MASK      8U
    #define PDB1DLYBL_DELAYB4_MASK      16U
    #define PDB1DLYBL_DELAYB5_MASK      32U
    #define PDB1DLYBL_DELAYB6_MASK      64U
    #define PDB1DLYBL_DELAYB7_MASK      128U
    
  } Overlap_STR;

} PDB1DLYBSTR;
extern volatile PDB1DLYBSTR _PDB1DLYB @0x00000074;
#define PDB1DLYB                        _PDB1DLYB.Word


/*** PDB1MOD - PDB1 Counter Modulus Register; 0x00000076 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PDB1MODH - PDB1 Counter Modulus High Register; 0x00000076 ***/
    union {
      byte Byte;
      struct {
        byte MOD8        :1;                                       /* Counter Modulus, bit 8 */
        byte MOD9        :1;                                       /* Counter Modulus, bit 9 */
        byte MOD10       :1;                                       /* Counter Modulus, bit 10 */
        byte MOD11       :1;                                       /* Counter Modulus, bit 11 */
        byte MOD12       :1;                                       /* Counter Modulus, bit 12 */
        byte MOD13       :1;                                       /* Counter Modulus, bit 13 */
        byte MOD14       :1;                                       /* Counter Modulus, bit 14 */
        byte MOD15       :1;                                       /* Counter Modulus, bit 15 */
      } Bits;
    } PDB1MODHSTR;
    #define PDB1MODH                    _PDB1MOD.Overlap_STR.PDB1MODHSTR.Byte
    #define PDB1MODH_MOD8               _PDB1MOD.Overlap_STR.PDB1MODHSTR.Bits.MOD8
    #define PDB1MODH_MOD9               _PDB1MOD.Overlap_STR.PDB1MODHSTR.Bits.MOD9
    #define PDB1MODH_MOD10              _PDB1MOD.Overlap_STR.PDB1MODHSTR.Bits.MOD10
    #define PDB1MODH_MOD11              _PDB1MOD.Overlap_STR.PDB1MODHSTR.Bits.MOD11
    #define PDB1MODH_MOD12              _PDB1MOD.Overlap_STR.PDB1MODHSTR.Bits.MOD12
    #define PDB1MODH_MOD13              _PDB1MOD.Overlap_STR.PDB1MODHSTR.Bits.MOD13
    #define PDB1MODH_MOD14              _PDB1MOD.Overlap_STR.PDB1MODHSTR.Bits.MOD14
    #define PDB1MODH_MOD15              _PDB1MOD.Overlap_STR.PDB1MODHSTR.Bits.MOD15
    
    #define PDB1MODH_MOD8_MASK          1U
    #define PDB1MODH_MOD9_MASK          2U
    #define PDB1MODH_MOD10_MASK         4U
    #define PDB1MODH_MOD11_MASK         8U
    #define PDB1MODH_MOD12_MASK         16U
    #define PDB1MODH_MOD13_MASK         32U
    #define PDB1MODH_MOD14_MASK         64U
    #define PDB1MODH_MOD15_MASK         128U
    

    /*** PDB1MODL - PDB1 Counter Modulus Low Register; 0x00000077 ***/
    union {
      byte Byte;
      struct {
        byte MOD0        :1;                                       /* Counter Modulus, bit 0 */
        byte MOD1        :1;                                       /* Counter Modulus, bit 1 */
        byte MOD2        :1;                                       /* Counter Modulus, bit 2 */
        byte MOD3        :1;                                       /* Counter Modulus, bit 3 */
        byte MOD4        :1;                                       /* Counter Modulus, bit 4 */
        byte MOD5        :1;                                       /* Counter Modulus, bit 5 */
        byte MOD6        :1;                                       /* Counter Modulus, bit 6 */
        byte MOD7        :1;                                       /* Counter Modulus, bit 7 */
      } Bits;
    } PDB1MODLSTR;
    #define PDB1MODL                    _PDB1MOD.Overlap_STR.PDB1MODLSTR.Byte
    #define PDB1MODL_MOD0               _PDB1MOD.Overlap_STR.PDB1MODLSTR.Bits.MOD0
    #define PDB1MODL_MOD1               _PDB1MOD.Overlap_STR.PDB1MODLSTR.Bits.MOD1
    #define PDB1MODL_MOD2               _PDB1MOD.Overlap_STR.PDB1MODLSTR.Bits.MOD2
    #define PDB1MODL_MOD3               _PDB1MOD.Overlap_STR.PDB1MODLSTR.Bits.MOD3
    #define PDB1MODL_MOD4               _PDB1MOD.Overlap_STR.PDB1MODLSTR.Bits.MOD4
    #define PDB1MODL_MOD5               _PDB1MOD.Overlap_STR.PDB1MODLSTR.Bits.MOD5
    #define PDB1MODL_MOD6               _PDB1MOD.Overlap_STR.PDB1MODLSTR.Bits.MOD6
    #define PDB1MODL_MOD7               _PDB1MOD.Overlap_STR.PDB1MODLSTR.Bits.MOD7
    
    #define PDB1MODL_MOD0_MASK          1U
    #define PDB1MODL_MOD1_MASK          2U
    #define PDB1MODL_MOD2_MASK          4U
    #define PDB1MODL_MOD3_MASK          8U
    #define PDB1MODL_MOD4_MASK          16U
    #define PDB1MODL_MOD5_MASK          32U
    #define PDB1MODL_MOD6_MASK          64U
    #define PDB1MODL_MOD7_MASK          128U
    
  } Overlap_STR;

} PDB1MODSTR;
extern volatile PDB1MODSTR _PDB1MOD @0x00000076;
#define PDB1MOD                         _PDB1MOD.Word


/*** PDB1CNT - PDB1 Counter Value Register; 0x00000078 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PDB1CNTH - PDB1 Counter Value High Register; 0x00000078 ***/
    union {
      byte Byte;
      struct {
        byte COUNT8      :1;                                       /* Counter Value, bit 8 */
        byte COUNT9      :1;                                       /* Counter Value, bit 9 */
        byte COUNT10     :1;                                       /* Counter Value, bit 10 */
        byte COUNT11     :1;                                       /* Counter Value, bit 11 */
        byte COUNT12     :1;                                       /* Counter Value, bit 12 */
        byte COUNT13     :1;                                       /* Counter Value, bit 13 */
        byte COUNT14     :1;                                       /* Counter Value, bit 14 */
        byte COUNT15     :1;                                       /* Counter Value, bit 15 */
      } Bits;
    } PDB1CNTHSTR;
    #define PDB1CNTH                    _PDB1CNT.Overlap_STR.PDB1CNTHSTR.Byte
    #define PDB1CNTH_COUNT8             _PDB1CNT.Overlap_STR.PDB1CNTHSTR.Bits.COUNT8
    #define PDB1CNTH_COUNT9             _PDB1CNT.Overlap_STR.PDB1CNTHSTR.Bits.COUNT9
    #define PDB1CNTH_COUNT10            _PDB1CNT.Overlap_STR.PDB1CNTHSTR.Bits.COUNT10
    #define PDB1CNTH_COUNT11            _PDB1CNT.Overlap_STR.PDB1CNTHSTR.Bits.COUNT11
    #define PDB1CNTH_COUNT12            _PDB1CNT.Overlap_STR.PDB1CNTHSTR.Bits.COUNT12
    #define PDB1CNTH_COUNT13            _PDB1CNT.Overlap_STR.PDB1CNTHSTR.Bits.COUNT13
    #define PDB1CNTH_COUNT14            _PDB1CNT.Overlap_STR.PDB1CNTHSTR.Bits.COUNT14
    #define PDB1CNTH_COUNT15            _PDB1CNT.Overlap_STR.PDB1CNTHSTR.Bits.COUNT15
    
    #define PDB1CNTH_COUNT8_MASK        1U
    #define PDB1CNTH_COUNT9_MASK        2U
    #define PDB1CNTH_COUNT10_MASK       4U
    #define PDB1CNTH_COUNT11_MASK       8U
    #define PDB1CNTH_COUNT12_MASK       16U
    #define PDB1CNTH_COUNT13_MASK       32U
    #define PDB1CNTH_COUNT14_MASK       64U
    #define PDB1CNTH_COUNT15_MASK       128U
    

    /*** PDB1CNTL - PDB1 Counter Value Low Register; 0x00000079 ***/
    union {
      byte Byte;
      struct {
        byte COUNT0      :1;                                       /* Counter Value, bit 0 */
        byte COUNT1      :1;                                       /* Counter Value, bit 1 */
        byte COUNT2      :1;                                       /* Counter Value, bit 2 */
        byte COUNT3      :1;                                       /* Counter Value, bit 3 */
        byte COUNT4      :1;                                       /* Counter Value, bit 4 */
        byte COUNT5      :1;                                       /* Counter Value, bit 5 */
        byte COUNT6      :1;                                       /* Counter Value, bit 6 */
        byte COUNT7      :1;                                       /* Counter Value, bit 7 */
      } Bits;
    } PDB1CNTLSTR;
    #define PDB1CNTL                    _PDB1CNT.Overlap_STR.PDB1CNTLSTR.Byte
    #define PDB1CNTL_COUNT0             _PDB1CNT.Overlap_STR.PDB1CNTLSTR.Bits.COUNT0
    #define PDB1CNTL_COUNT1             _PDB1CNT.Overlap_STR.PDB1CNTLSTR.Bits.COUNT1
    #define PDB1CNTL_COUNT2             _PDB1CNT.Overlap_STR.PDB1CNTLSTR.Bits.COUNT2
    #define PDB1CNTL_COUNT3             _PDB1CNT.Overlap_STR.PDB1CNTLSTR.Bits.COUNT3
    #define PDB1CNTL_COUNT4             _PDB1CNT.Overlap_STR.PDB1CNTLSTR.Bits.COUNT4
    #define PDB1CNTL_COUNT5             _PDB1CNT.Overlap_STR.PDB1CNTLSTR.Bits.COUNT5
    #define PDB1CNTL_COUNT6             _PDB1CNT.Overlap_STR.PDB1CNTLSTR.Bits.COUNT6
    #define PDB1CNTL_COUNT7             _PDB1CNT.Overlap_STR.PDB1CNTLSTR.Bits.COUNT7
    
    #define PDB1CNTL_COUNT0_MASK        1U
    #define PDB1CNTL_COUNT1_MASK        2U
    #define PDB1CNTL_COUNT2_MASK        4U
    #define PDB1CNTL_COUNT3_MASK        8U
    #define PDB1CNTL_COUNT4_MASK        16U
    #define PDB1CNTL_COUNT5_MASK        32U
    #define PDB1CNTL_COUNT6_MASK        64U
    #define PDB1CNTL_COUNT7_MASK        128U
    
  } Overlap_STR;

} PDB1CNTSTR;
extern volatile PDB1CNTSTR _PDB1CNT @0x00000078;
#define PDB1CNT                         _PDB1CNT.Word


/*** PDB1SCR - PDB1 Status Register; 0x0000007A ***/
typedef union {
  byte Byte;
  struct {
    byte DAIE        :1;                                       /* Delay A successful compare interrupt request enable */
    byte DAF         :1;                                       /* Delay A flag */
    byte DBIE        :1;                                       /* Delay B successful compare interrupt request enable */
    byte DBF         :1;                                       /* Delay B flag */
    byte COIE        :1;                                       /* Counter overflow interrupt request enable */
    byte COF         :1;                                       /* Counter overflow flag */
    byte PDBEN       :1;                                       /* PDB module enable */
    byte PADEN       :1;                                       /* Pulse output PAD enable */
  } Bits;
} PDB1SCRSTR;
extern volatile PDB1SCRSTR _PDB1SCR @0x0000007A;
#define PDB1SCR                         _PDB1SCR.Byte
#define PDB1SCR_DAIE                    _PDB1SCR.Bits.DAIE
#define PDB1SCR_DAF                     _PDB1SCR.Bits.DAF
#define PDB1SCR_DBIE                    _PDB1SCR.Bits.DBIE
#define PDB1SCR_DBF                     _PDB1SCR.Bits.DBF
#define PDB1SCR_COIE                    _PDB1SCR.Bits.COIE
#define PDB1SCR_COF                     _PDB1SCR.Bits.COF
#define PDB1SCR_PDBEN                   _PDB1SCR.Bits.PDBEN
#define PDB1SCR_PADEN                   _PDB1SCR.Bits.PADEN

#define PDB1SCR_DAIE_MASK               1U
#define PDB1SCR_DAF_MASK                2U
#define PDB1SCR_DBIE_MASK               4U
#define PDB1SCR_DBF_MASK                8U
#define PDB1SCR_COIE_MASK               16U
#define PDB1SCR_COF_MASK                32U
#define PDB1SCR_PDBEN_MASK              64U
#define PDB1SCR_PADEN_MASK              128U


/*** CRCH - CRC High Register; 0x0000007C ***/
typedef union {
  byte Byte;
  struct {
    byte BIT8        :1;                                       /* High byte of CRC register ,bit 8 */
    byte BIT9        :1;                                       /* High byte of CRC register ,bit 9 */
    byte BIT10       :1;                                       /* High byte of CRC register ,bit 10 */
    byte BIT11       :1;                                       /* High byte of CRC register ,bit 11 */
    byte BIT12       :1;                                       /* High byte of CRC register ,bit 12 */
    byte BIT13       :1;                                       /* High byte of CRC register ,bit 13 */
    byte BIT14       :1;                                       /* High byte of CRC register ,bit 14 */
    byte BIT15       :1;                                       /* High byte of CRC register ,bit 15 */
  } Bits;
} CRCHSTR;
extern volatile CRCHSTR _CRCH @0x0000007C;
#define CRCH                            _CRCH.Byte
#define CRCH_BIT8                       _CRCH.Bits.BIT8
#define CRCH_BIT9                       _CRCH.Bits.BIT9
#define CRCH_BIT10                      _CRCH.Bits.BIT10
#define CRCH_BIT11                      _CRCH.Bits.BIT11
#define CRCH_BIT12                      _CRCH.Bits.BIT12
#define CRCH_BIT13                      _CRCH.Bits.BIT13
#define CRCH_BIT14                      _CRCH.Bits.BIT14
#define CRCH_BIT15                      _CRCH.Bits.BIT15

#define CRCH_BIT8_MASK                  1U
#define CRCH_BIT9_MASK                  2U
#define CRCH_BIT10_MASK                 4U
#define CRCH_BIT11_MASK                 8U
#define CRCH_BIT12_MASK                 16U
#define CRCH_BIT13_MASK                 32U
#define CRCH_BIT14_MASK                 64U
#define CRCH_BIT15_MASK                 128U


/*** CRCL - CRC Low Register; 0x0000007D ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Low byte of CRC register, bit 0 */
    byte BIT1        :1;                                       /* Low byte of CRC register, bit 1 */
    byte BIT2        :1;                                       /* Low byte of CRC register, bit 2 */
    byte BIT3        :1;                                       /* Low byte of CRC register, bit 3 */
    byte BIT4        :1;                                       /* Low byte of CRC register, bit 4 */
    byte BIT5        :1;                                       /* Low byte of CRC register, bit 5 */
    byte BIT6        :1;                                       /* Low byte of CRC register, bit 6 */
    byte BIT7        :1;                                       /* Low byte of CRC register, bit 7 */
  } Bits;
} CRCLSTR;
extern volatile CRCLSTR _CRCL @0x0000007D;
#define CRCL                            _CRCL.Byte
#define CRCL_BIT0                       _CRCL.Bits.BIT0
#define CRCL_BIT1                       _CRCL.Bits.BIT1
#define CRCL_BIT2                       _CRCL.Bits.BIT2
#define CRCL_BIT3                       _CRCL.Bits.BIT3
#define CRCL_BIT4                       _CRCL.Bits.BIT4
#define CRCL_BIT5                       _CRCL.Bits.BIT5
#define CRCL_BIT6                       _CRCL.Bits.BIT6
#define CRCL_BIT7                       _CRCL.Bits.BIT7

#define CRCL_BIT0_MASK                  1U
#define CRCL_BIT1_MASK                  2U
#define CRCL_BIT2_MASK                  4U
#define CRCL_BIT3_MASK                  8U
#define CRCL_BIT4_MASK                  16U
#define CRCL_BIT5_MASK                  32U
#define CRCL_BIT6_MASK                  64U
#define CRCL_BIT7_MASK                  128U


/*** TRANSPOSE - CRC Transpose Register; 0x0000007E ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* CRC transpose register, bit 0 */
    byte BIT1        :1;                                       /* CRC transpose register, bit 1 */
    byte BIT2        :1;                                       /* CRC transpose register, bit 2 */
    byte BIT3        :1;                                       /* CRC transpose register, bit 3 */
    byte BIT4        :1;                                       /* CRC transpose register, bit 4 */
    byte BIT5        :1;                                       /* CRC transpose register, bit 5 */
    byte BIT6        :1;                                       /* CRC transpose register, bit 6 */
    byte BIT7        :1;                                       /* CRC transpose register, bit 7 */
  } Bits;
} TRANSPOSESTR;
extern volatile TRANSPOSESTR _TRANSPOSE @0x0000007E;
#define TRANSPOSE                       _TRANSPOSE.Byte
#define TRANSPOSE_BIT0                  _TRANSPOSE.Bits.BIT0
#define TRANSPOSE_BIT1                  _TRANSPOSE.Bits.BIT1
#define TRANSPOSE_BIT2                  _TRANSPOSE.Bits.BIT2
#define TRANSPOSE_BIT3                  _TRANSPOSE.Bits.BIT3
#define TRANSPOSE_BIT4                  _TRANSPOSE.Bits.BIT4
#define TRANSPOSE_BIT5                  _TRANSPOSE.Bits.BIT5
#define TRANSPOSE_BIT6                  _TRANSPOSE.Bits.BIT6
#define TRANSPOSE_BIT7                  _TRANSPOSE.Bits.BIT7

#define TRANSPOSE_BIT0_MASK             1U
#define TRANSPOSE_BIT1_MASK             2U
#define TRANSPOSE_BIT2_MASK             4U
#define TRANSPOSE_BIT3_MASK             8U
#define TRANSPOSE_BIT4_MASK             16U
#define TRANSPOSE_BIT5_MASK             32U
#define TRANSPOSE_BIT6_MASK             64U
#define TRANSPOSE_BIT7_MASK             128U


/*** PDB2CTRL1 - PDB2 Control 1 Register; 0x00000080 ***/
typedef union {
  byte Byte;
  struct {
    byte LDOK        :1;                                       /* Load OK */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte LDMOD       :1;                                       /* Load mode select */
  } Bits;
} PDB2CTRL1STR;
extern volatile PDB2CTRL1STR _PDB2CTRL1 @0x00000080;
#define PDB2CTRL1                       _PDB2CTRL1.Byte
#define PDB2CTRL1_LDOK                  _PDB2CTRL1.Bits.LDOK
#define PDB2CTRL1_LDMOD                 _PDB2CTRL1.Bits.LDMOD

#define PDB2CTRL1_LDOK_MASK             1U
#define PDB2CTRL1_LDMOD_MASK            128U


/*** PDB2CTRL2 - PDB2 Control 2 Register; 0x00000081 ***/
typedef union {
  byte Byte;
  struct {
    byte SWTRIG      :1;                                       /* Software Trigger */
    byte CONT        :1;                                       /* Continuous Mode Enable */
    byte TRIGSEL0    :1;                                       /* Input Trigger, bit 0 */
    byte TRIGSEL1    :1;                                       /* Input Trigger, bit 1 */
    byte TRIGSEL2    :1;                                       /* Input Trigger, bit 2 */
    byte PRESCALER0  :1;                                       /* Clock Prescaler, bit 0 */
    byte PRESCALER1  :1;                                       /* Clock Prescaler, bit 1 */
    byte PRESCALER2  :1;                                       /* Clock Prescaler, bit 2 */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpTRIGSEL :3;
    byte grpPRESCALER :3;
  } MergedBits;
} PDB2CTRL2STR;
extern volatile PDB2CTRL2STR _PDB2CTRL2 @0x00000081;
#define PDB2CTRL2                       _PDB2CTRL2.Byte
#define PDB2CTRL2_SWTRIG                _PDB2CTRL2.Bits.SWTRIG
#define PDB2CTRL2_CONT                  _PDB2CTRL2.Bits.CONT
#define PDB2CTRL2_TRIGSEL0              _PDB2CTRL2.Bits.TRIGSEL0
#define PDB2CTRL2_TRIGSEL1              _PDB2CTRL2.Bits.TRIGSEL1
#define PDB2CTRL2_TRIGSEL2              _PDB2CTRL2.Bits.TRIGSEL2
#define PDB2CTRL2_PRESCALER0            _PDB2CTRL2.Bits.PRESCALER0
#define PDB2CTRL2_PRESCALER1            _PDB2CTRL2.Bits.PRESCALER1
#define PDB2CTRL2_PRESCALER2            _PDB2CTRL2.Bits.PRESCALER2
#define PDB2CTRL2_TRIGSEL               _PDB2CTRL2.MergedBits.grpTRIGSEL
#define PDB2CTRL2_PRESCALER             _PDB2CTRL2.MergedBits.grpPRESCALER

#define PDB2CTRL2_SWTRIG_MASK           1U
#define PDB2CTRL2_CONT_MASK             2U
#define PDB2CTRL2_TRIGSEL0_MASK         4U
#define PDB2CTRL2_TRIGSEL1_MASK         8U
#define PDB2CTRL2_TRIGSEL2_MASK         16U
#define PDB2CTRL2_PRESCALER0_MASK       32U
#define PDB2CTRL2_PRESCALER1_MASK       64U
#define PDB2CTRL2_PRESCALER2_MASK       128U
#define PDB2CTRL2_TRIGSEL_MASK          28U
#define PDB2CTRL2_TRIGSEL_BITNUM        2U
#define PDB2CTRL2_PRESCALER_MASK        224U
#define PDB2CTRL2_PRESCALER_BITNUM      5U


/*** PDB2DLYA - PDB2 Delay A Register; 0x00000082 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PDB2DLYAH - PDB2 Delay A High Register; 0x00000082 ***/
    union {
      byte Byte;
      struct {
        byte DELAYA8     :1;                                       /* Delay A, bit 8 */
        byte DELAYA9     :1;                                       /* Delay A, bit 9 */
        byte DELAYA10    :1;                                       /* Delay A, bit 10 */
        byte DELAYA11    :1;                                       /* Delay A, bit 11 */
        byte DELAYA12    :1;                                       /* Delay A, bit 12 */
        byte DELAYA13    :1;                                       /* Delay A, bit 13 */
        byte DELAYA14    :1;                                       /* Delay A, bit 14 */
        byte DELAYA15    :1;                                       /* Delay A, bit 15 */
      } Bits;
    } PDB2DLYAHSTR;
    #define PDB2DLYAH                   _PDB2DLYA.Overlap_STR.PDB2DLYAHSTR.Byte
    #define PDB2DLYAH_DELAYA8           _PDB2DLYA.Overlap_STR.PDB2DLYAHSTR.Bits.DELAYA8
    #define PDB2DLYAH_DELAYA9           _PDB2DLYA.Overlap_STR.PDB2DLYAHSTR.Bits.DELAYA9
    #define PDB2DLYAH_DELAYA10          _PDB2DLYA.Overlap_STR.PDB2DLYAHSTR.Bits.DELAYA10
    #define PDB2DLYAH_DELAYA11          _PDB2DLYA.Overlap_STR.PDB2DLYAHSTR.Bits.DELAYA11
    #define PDB2DLYAH_DELAYA12          _PDB2DLYA.Overlap_STR.PDB2DLYAHSTR.Bits.DELAYA12
    #define PDB2DLYAH_DELAYA13          _PDB2DLYA.Overlap_STR.PDB2DLYAHSTR.Bits.DELAYA13
    #define PDB2DLYAH_DELAYA14          _PDB2DLYA.Overlap_STR.PDB2DLYAHSTR.Bits.DELAYA14
    #define PDB2DLYAH_DELAYA15          _PDB2DLYA.Overlap_STR.PDB2DLYAHSTR.Bits.DELAYA15
    
    #define PDB2DLYAH_DELAYA8_MASK      1U
    #define PDB2DLYAH_DELAYA9_MASK      2U
    #define PDB2DLYAH_DELAYA10_MASK     4U
    #define PDB2DLYAH_DELAYA11_MASK     8U
    #define PDB2DLYAH_DELAYA12_MASK     16U
    #define PDB2DLYAH_DELAYA13_MASK     32U
    #define PDB2DLYAH_DELAYA14_MASK     64U
    #define PDB2DLYAH_DELAYA15_MASK     128U
    

    /*** PDB2DLYAL - PDB2 Delay A Low Register; 0x00000083 ***/
    union {
      byte Byte;
      struct {
        byte DELAYA0     :1;                                       /* Delay A, bit 0 */
        byte DELAYA1     :1;                                       /* Delay A, bit 1 */
        byte DELAYA2     :1;                                       /* Delay A, bit 2 */
        byte DELAYA3     :1;                                       /* Delay A, bit 3 */
        byte DELAYA4     :1;                                       /* Delay A, bit 4 */
        byte DELAYA5     :1;                                       /* Delay A, bit 5 */
        byte DELAYA6     :1;                                       /* Delay A, bit 6 */
        byte DELAYA7     :1;                                       /* Delay A, bit 7 */
      } Bits;
    } PDB2DLYALSTR;
    #define PDB2DLYAL                   _PDB2DLYA.Overlap_STR.PDB2DLYALSTR.Byte
    #define PDB2DLYAL_DELAYA0           _PDB2DLYA.Overlap_STR.PDB2DLYALSTR.Bits.DELAYA0
    #define PDB2DLYAL_DELAYA1           _PDB2DLYA.Overlap_STR.PDB2DLYALSTR.Bits.DELAYA1
    #define PDB2DLYAL_DELAYA2           _PDB2DLYA.Overlap_STR.PDB2DLYALSTR.Bits.DELAYA2
    #define PDB2DLYAL_DELAYA3           _PDB2DLYA.Overlap_STR.PDB2DLYALSTR.Bits.DELAYA3
    #define PDB2DLYAL_DELAYA4           _PDB2DLYA.Overlap_STR.PDB2DLYALSTR.Bits.DELAYA4
    #define PDB2DLYAL_DELAYA5           _PDB2DLYA.Overlap_STR.PDB2DLYALSTR.Bits.DELAYA5
    #define PDB2DLYAL_DELAYA6           _PDB2DLYA.Overlap_STR.PDB2DLYALSTR.Bits.DELAYA6
    #define PDB2DLYAL_DELAYA7           _PDB2DLYA.Overlap_STR.PDB2DLYALSTR.Bits.DELAYA7
    
    #define PDB2DLYAL_DELAYA0_MASK      1U
    #define PDB2DLYAL_DELAYA1_MASK      2U
    #define PDB2DLYAL_DELAYA2_MASK      4U
    #define PDB2DLYAL_DELAYA3_MASK      8U
    #define PDB2DLYAL_DELAYA4_MASK      16U
    #define PDB2DLYAL_DELAYA5_MASK      32U
    #define PDB2DLYAL_DELAYA6_MASK      64U
    #define PDB2DLYAL_DELAYA7_MASK      128U
    
  } Overlap_STR;

} PDB2DLYASTR;
extern volatile PDB2DLYASTR _PDB2DLYA @0x00000082;
#define PDB2DLYA                        _PDB2DLYA.Word


/*** PDB2DLYB - PDB2 Delay B Register; 0x00000084 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PDB2DLYBH - PDB2 Delay B High Register; 0x00000084 ***/
    union {
      byte Byte;
      struct {
        byte DELAYB8     :1;                                       /* Delay B, bit 8 */
        byte DELAYB9     :1;                                       /* Delay B, bit 9 */
        byte DELAYB10    :1;                                       /* Delay B, bit 10 */
        byte DELAYB11    :1;                                       /* Delay B, bit 11 */
        byte DELAYB12    :1;                                       /* Delay B, bit 12 */
        byte DELAYB13    :1;                                       /* Delay B, bit 13 */
        byte DELAYB14    :1;                                       /* Delay B, bit 14 */
        byte DELAYB15    :1;                                       /* Delay B, bit 15 */
      } Bits;
    } PDB2DLYBHSTR;
    #define PDB2DLYBH                   _PDB2DLYB.Overlap_STR.PDB2DLYBHSTR.Byte
    #define PDB2DLYBH_DELAYB8           _PDB2DLYB.Overlap_STR.PDB2DLYBHSTR.Bits.DELAYB8
    #define PDB2DLYBH_DELAYB9           _PDB2DLYB.Overlap_STR.PDB2DLYBHSTR.Bits.DELAYB9
    #define PDB2DLYBH_DELAYB10          _PDB2DLYB.Overlap_STR.PDB2DLYBHSTR.Bits.DELAYB10
    #define PDB2DLYBH_DELAYB11          _PDB2DLYB.Overlap_STR.PDB2DLYBHSTR.Bits.DELAYB11
    #define PDB2DLYBH_DELAYB12          _PDB2DLYB.Overlap_STR.PDB2DLYBHSTR.Bits.DELAYB12
    #define PDB2DLYBH_DELAYB13          _PDB2DLYB.Overlap_STR.PDB2DLYBHSTR.Bits.DELAYB13
    #define PDB2DLYBH_DELAYB14          _PDB2DLYB.Overlap_STR.PDB2DLYBHSTR.Bits.DELAYB14
    #define PDB2DLYBH_DELAYB15          _PDB2DLYB.Overlap_STR.PDB2DLYBHSTR.Bits.DELAYB15
    
    #define PDB2DLYBH_DELAYB8_MASK      1U
    #define PDB2DLYBH_DELAYB9_MASK      2U
    #define PDB2DLYBH_DELAYB10_MASK     4U
    #define PDB2DLYBH_DELAYB11_MASK     8U
    #define PDB2DLYBH_DELAYB12_MASK     16U
    #define PDB2DLYBH_DELAYB13_MASK     32U
    #define PDB2DLYBH_DELAYB14_MASK     64U
    #define PDB2DLYBH_DELAYB15_MASK     128U
    

    /*** PDB2DLYBL - PDB2 Delay B Low Register; 0x00000085 ***/
    union {
      byte Byte;
      struct {
        byte DELAYB0     :1;                                       /* Delay B, bit 0 */
        byte DELAYB1     :1;                                       /* Delay B, bit 1 */
        byte DELAYB2     :1;                                       /* Delay B, bit 2 */
        byte DELAYB3     :1;                                       /* Delay B, bit 3 */
        byte DELAYB4     :1;                                       /* Delay B, bit 4 */
        byte DELAYB5     :1;                                       /* Delay B, bit 5 */
        byte DELAYB6     :1;                                       /* Delay B, bit 6 */
        byte DELAYB7     :1;                                       /* Delay B, bit 7 */
      } Bits;
    } PDB2DLYBLSTR;
    #define PDB2DLYBL                   _PDB2DLYB.Overlap_STR.PDB2DLYBLSTR.Byte
    #define PDB2DLYBL_DELAYB0           _PDB2DLYB.Overlap_STR.PDB2DLYBLSTR.Bits.DELAYB0
    #define PDB2DLYBL_DELAYB1           _PDB2DLYB.Overlap_STR.PDB2DLYBLSTR.Bits.DELAYB1
    #define PDB2DLYBL_DELAYB2           _PDB2DLYB.Overlap_STR.PDB2DLYBLSTR.Bits.DELAYB2
    #define PDB2DLYBL_DELAYB3           _PDB2DLYB.Overlap_STR.PDB2DLYBLSTR.Bits.DELAYB3
    #define PDB2DLYBL_DELAYB4           _PDB2DLYB.Overlap_STR.PDB2DLYBLSTR.Bits.DELAYB4
    #define PDB2DLYBL_DELAYB5           _PDB2DLYB.Overlap_STR.PDB2DLYBLSTR.Bits.DELAYB5
    #define PDB2DLYBL_DELAYB6           _PDB2DLYB.Overlap_STR.PDB2DLYBLSTR.Bits.DELAYB6
    #define PDB2DLYBL_DELAYB7           _PDB2DLYB.Overlap_STR.PDB2DLYBLSTR.Bits.DELAYB7
    
    #define PDB2DLYBL_DELAYB0_MASK      1U
    #define PDB2DLYBL_DELAYB1_MASK      2U
    #define PDB2DLYBL_DELAYB2_MASK      4U
    #define PDB2DLYBL_DELAYB3_MASK      8U
    #define PDB2DLYBL_DELAYB4_MASK      16U
    #define PDB2DLYBL_DELAYB5_MASK      32U
    #define PDB2DLYBL_DELAYB6_MASK      64U
    #define PDB2DLYBL_DELAYB7_MASK      128U
    
  } Overlap_STR;

} PDB2DLYBSTR;
extern volatile PDB2DLYBSTR _PDB2DLYB @0x00000084;
#define PDB2DLYB                        _PDB2DLYB.Word


/*** PDB2MOD - PDB2 Counter Modulus Register; 0x00000086 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PDB2MODH - PDB2 Counter Modulus High Register; 0x00000086 ***/
    union {
      byte Byte;
      struct {
        byte MOD8        :1;                                       /* Counter Modulus, bit 8 */
        byte MOD9        :1;                                       /* Counter Modulus, bit 9 */
        byte MOD10       :1;                                       /* Counter Modulus, bit 10 */
        byte MOD11       :1;                                       /* Counter Modulus, bit 11 */
        byte MOD12       :1;                                       /* Counter Modulus, bit 12 */
        byte MOD13       :1;                                       /* Counter Modulus, bit 13 */
        byte MOD14       :1;                                       /* Counter Modulus, bit 14 */
        byte MOD15       :1;                                       /* Counter Modulus, bit 15 */
      } Bits;
    } PDB2MODHSTR;
    #define PDB2MODH                    _PDB2MOD.Overlap_STR.PDB2MODHSTR.Byte
    #define PDB2MODH_MOD8               _PDB2MOD.Overlap_STR.PDB2MODHSTR.Bits.MOD8
    #define PDB2MODH_MOD9               _PDB2MOD.Overlap_STR.PDB2MODHSTR.Bits.MOD9
    #define PDB2MODH_MOD10              _PDB2MOD.Overlap_STR.PDB2MODHSTR.Bits.MOD10
    #define PDB2MODH_MOD11              _PDB2MOD.Overlap_STR.PDB2MODHSTR.Bits.MOD11
    #define PDB2MODH_MOD12              _PDB2MOD.Overlap_STR.PDB2MODHSTR.Bits.MOD12
    #define PDB2MODH_MOD13              _PDB2MOD.Overlap_STR.PDB2MODHSTR.Bits.MOD13
    #define PDB2MODH_MOD14              _PDB2MOD.Overlap_STR.PDB2MODHSTR.Bits.MOD14
    #define PDB2MODH_MOD15              _PDB2MOD.Overlap_STR.PDB2MODHSTR.Bits.MOD15
    
    #define PDB2MODH_MOD8_MASK          1U
    #define PDB2MODH_MOD9_MASK          2U
    #define PDB2MODH_MOD10_MASK         4U
    #define PDB2MODH_MOD11_MASK         8U
    #define PDB2MODH_MOD12_MASK         16U
    #define PDB2MODH_MOD13_MASK         32U
    #define PDB2MODH_MOD14_MASK         64U
    #define PDB2MODH_MOD15_MASK         128U
    

    /*** PDB2MODL - PDB2 Counter Modulus Low Register; 0x00000087 ***/
    union {
      byte Byte;
      struct {
        byte MOD0        :1;                                       /* Counter Modulus, bit 0 */
        byte MOD1        :1;                                       /* Counter Modulus, bit 1 */
        byte MOD2        :1;                                       /* Counter Modulus, bit 2 */
        byte MOD3        :1;                                       /* Counter Modulus, bit 3 */
        byte MOD4        :1;                                       /* Counter Modulus, bit 4 */
        byte MOD5        :1;                                       /* Counter Modulus, bit 5 */
        byte MOD6        :1;                                       /* Counter Modulus, bit 6 */
        byte MOD7        :1;                                       /* Counter Modulus, bit 7 */
      } Bits;
    } PDB2MODLSTR;
    #define PDB2MODL                    _PDB2MOD.Overlap_STR.PDB2MODLSTR.Byte
    #define PDB2MODL_MOD0               _PDB2MOD.Overlap_STR.PDB2MODLSTR.Bits.MOD0
    #define PDB2MODL_MOD1               _PDB2MOD.Overlap_STR.PDB2MODLSTR.Bits.MOD1
    #define PDB2MODL_MOD2               _PDB2MOD.Overlap_STR.PDB2MODLSTR.Bits.MOD2
    #define PDB2MODL_MOD3               _PDB2MOD.Overlap_STR.PDB2MODLSTR.Bits.MOD3
    #define PDB2MODL_MOD4               _PDB2MOD.Overlap_STR.PDB2MODLSTR.Bits.MOD4
    #define PDB2MODL_MOD5               _PDB2MOD.Overlap_STR.PDB2MODLSTR.Bits.MOD5
    #define PDB2MODL_MOD6               _PDB2MOD.Overlap_STR.PDB2MODLSTR.Bits.MOD6
    #define PDB2MODL_MOD7               _PDB2MOD.Overlap_STR.PDB2MODLSTR.Bits.MOD7
    
    #define PDB2MODL_MOD0_MASK          1U
    #define PDB2MODL_MOD1_MASK          2U
    #define PDB2MODL_MOD2_MASK          4U
    #define PDB2MODL_MOD3_MASK          8U
    #define PDB2MODL_MOD4_MASK          16U
    #define PDB2MODL_MOD5_MASK          32U
    #define PDB2MODL_MOD6_MASK          64U
    #define PDB2MODL_MOD7_MASK          128U
    
  } Overlap_STR;

} PDB2MODSTR;
extern volatile PDB2MODSTR _PDB2MOD @0x00000086;
#define PDB2MOD                         _PDB2MOD.Word


/*** PDB2CNT - PDB2 Counter Value Register; 0x00000088 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PDB2CNTH - PDB2 Counter Value High Register; 0x00000088 ***/
    union {
      byte Byte;
      struct {
        byte COUNT8      :1;                                       /* Counter Value, bit 8 */
        byte COUNT9      :1;                                       /* Counter Value, bit 9 */
        byte COUNT10     :1;                                       /* Counter Value, bit 10 */
        byte COUNT11     :1;                                       /* Counter Value, bit 11 */
        byte COUNT12     :1;                                       /* Counter Value, bit 12 */
        byte COUNT13     :1;                                       /* Counter Value, bit 13 */
        byte COUNT14     :1;                                       /* Counter Value, bit 14 */
        byte COUNT15     :1;                                       /* Counter Value, bit 15 */
      } Bits;
    } PDB2CNTHSTR;
    #define PDB2CNTH                    _PDB2CNT.Overlap_STR.PDB2CNTHSTR.Byte
    #define PDB2CNTH_COUNT8             _PDB2CNT.Overlap_STR.PDB2CNTHSTR.Bits.COUNT8
    #define PDB2CNTH_COUNT9             _PDB2CNT.Overlap_STR.PDB2CNTHSTR.Bits.COUNT9
    #define PDB2CNTH_COUNT10            _PDB2CNT.Overlap_STR.PDB2CNTHSTR.Bits.COUNT10
    #define PDB2CNTH_COUNT11            _PDB2CNT.Overlap_STR.PDB2CNTHSTR.Bits.COUNT11
    #define PDB2CNTH_COUNT12            _PDB2CNT.Overlap_STR.PDB2CNTHSTR.Bits.COUNT12
    #define PDB2CNTH_COUNT13            _PDB2CNT.Overlap_STR.PDB2CNTHSTR.Bits.COUNT13
    #define PDB2CNTH_COUNT14            _PDB2CNT.Overlap_STR.PDB2CNTHSTR.Bits.COUNT14
    #define PDB2CNTH_COUNT15            _PDB2CNT.Overlap_STR.PDB2CNTHSTR.Bits.COUNT15
    
    #define PDB2CNTH_COUNT8_MASK        1U
    #define PDB2CNTH_COUNT9_MASK        2U
    #define PDB2CNTH_COUNT10_MASK       4U
    #define PDB2CNTH_COUNT11_MASK       8U
    #define PDB2CNTH_COUNT12_MASK       16U
    #define PDB2CNTH_COUNT13_MASK       32U
    #define PDB2CNTH_COUNT14_MASK       64U
    #define PDB2CNTH_COUNT15_MASK       128U
    

    /*** PDB2CNTL - PDB2 Counter Value Low Register; 0x00000089 ***/
    union {
      byte Byte;
      struct {
        byte COUNT0      :1;                                       /* Counter Value, bit 0 */
        byte COUNT1      :1;                                       /* Counter Value, bit 1 */
        byte COUNT2      :1;                                       /* Counter Value, bit 2 */
        byte COUNT3      :1;                                       /* Counter Value, bit 3 */
        byte COUNT4      :1;                                       /* Counter Value, bit 4 */
        byte COUNT5      :1;                                       /* Counter Value, bit 5 */
        byte COUNT6      :1;                                       /* Counter Value, bit 6 */
        byte COUNT7      :1;                                       /* Counter Value, bit 7 */
      } Bits;
    } PDB2CNTLSTR;
    #define PDB2CNTL                    _PDB2CNT.Overlap_STR.PDB2CNTLSTR.Byte
    #define PDB2CNTL_COUNT0             _PDB2CNT.Overlap_STR.PDB2CNTLSTR.Bits.COUNT0
    #define PDB2CNTL_COUNT1             _PDB2CNT.Overlap_STR.PDB2CNTLSTR.Bits.COUNT1
    #define PDB2CNTL_COUNT2             _PDB2CNT.Overlap_STR.PDB2CNTLSTR.Bits.COUNT2
    #define PDB2CNTL_COUNT3             _PDB2CNT.Overlap_STR.PDB2CNTLSTR.Bits.COUNT3
    #define PDB2CNTL_COUNT4             _PDB2CNT.Overlap_STR.PDB2CNTLSTR.Bits.COUNT4
    #define PDB2CNTL_COUNT5             _PDB2CNT.Overlap_STR.PDB2CNTLSTR.Bits.COUNT5
    #define PDB2CNTL_COUNT6             _PDB2CNT.Overlap_STR.PDB2CNTLSTR.Bits.COUNT6
    #define PDB2CNTL_COUNT7             _PDB2CNT.Overlap_STR.PDB2CNTLSTR.Bits.COUNT7
    
    #define PDB2CNTL_COUNT0_MASK        1U
    #define PDB2CNTL_COUNT1_MASK        2U
    #define PDB2CNTL_COUNT2_MASK        4U
    #define PDB2CNTL_COUNT3_MASK        8U
    #define PDB2CNTL_COUNT4_MASK        16U
    #define PDB2CNTL_COUNT5_MASK        32U
    #define PDB2CNTL_COUNT6_MASK        64U
    #define PDB2CNTL_COUNT7_MASK        128U
    
  } Overlap_STR;

} PDB2CNTSTR;
extern volatile PDB2CNTSTR _PDB2CNT @0x00000088;
#define PDB2CNT                         _PDB2CNT.Word


/*** PDB2SCR - PDB2 Status Register; 0x0000008A ***/
typedef union {
  byte Byte;
  struct {
    byte DAIE        :1;                                       /* Delay A successful compare interrupt request enable */
    byte DAF         :1;                                       /* Delay A flag */
    byte DBIE        :1;                                       /* Delay B successful compare interrupt request enable */
    byte DBF         :1;                                       /* Delay B flag */
    byte COIE        :1;                                       /* Counter overflow interrupt request enable */
    byte COF         :1;                                       /* Counter overflow flag */
    byte PDBEN       :1;                                       /* PDB module enable */
    byte PADEN       :1;                                       /* Pulse output PAD enable */
  } Bits;
} PDB2SCRSTR;
extern volatile PDB2SCRSTR _PDB2SCR @0x0000008A;
#define PDB2SCR                         _PDB2SCR.Byte
#define PDB2SCR_DAIE                    _PDB2SCR.Bits.DAIE
#define PDB2SCR_DAF                     _PDB2SCR.Bits.DAF
#define PDB2SCR_DBIE                    _PDB2SCR.Bits.DBIE
#define PDB2SCR_DBF                     _PDB2SCR.Bits.DBF
#define PDB2SCR_COIE                    _PDB2SCR.Bits.COIE
#define PDB2SCR_COF                     _PDB2SCR.Bits.COF
#define PDB2SCR_PDBEN                   _PDB2SCR.Bits.PDBEN
#define PDB2SCR_PADEN                   _PDB2SCR.Bits.PADEN

#define PDB2SCR_DAIE_MASK               1U
#define PDB2SCR_DAF_MASK                2U
#define PDB2SCR_DBIE_MASK               4U
#define PDB2SCR_DBF_MASK                8U
#define PDB2SCR_COIE_MASK               16U
#define PDB2SCR_COF_MASK                32U
#define PDB2SCR_PDBEN_MASK              64U
#define PDB2SCR_PADEN_MASK              128U


/*** RTCSC - RTC Status and Control Register; 0x0000008C ***/
typedef union {
  byte Byte;
  struct {
    byte RTCPS0      :1;                                       /* Real-Time Clock Prescaler Select, bit 0 */
    byte RTCPS1      :1;                                       /* Real-Time Clock Prescaler Select, bit 1 */
    byte RTCPS2      :1;                                       /* Real-Time Clock Prescaler Select, bit 2 */
    byte RTCPS3      :1;                                       /* Real-Time Clock Prescaler Select, bit 3 */
    byte RTIE        :1;                                       /* Real-Time Interrupt Enable */
    byte RTCLKS0     :1;                                       /* Real-Time Clock Source Select, bit 0 */
    byte RTCLKS1     :1;                                       /* Real-Time Clock Source Select, bit 1 */
    byte RTIF        :1;                                       /* Real-Time Interrupt Flag */
  } Bits;
  struct {
    byte grpRTCPS :4;
    byte         :1;
    byte grpRTCLKS :2;
    byte         :1;
  } MergedBits;
} RTCSCSTR;
extern volatile RTCSCSTR _RTCSC @0x0000008C;
#define RTCSC                           _RTCSC.Byte
#define RTCSC_RTCPS0                    _RTCSC.Bits.RTCPS0
#define RTCSC_RTCPS1                    _RTCSC.Bits.RTCPS1
#define RTCSC_RTCPS2                    _RTCSC.Bits.RTCPS2
#define RTCSC_RTCPS3                    _RTCSC.Bits.RTCPS3
#define RTCSC_RTIE                      _RTCSC.Bits.RTIE
#define RTCSC_RTCLKS0                   _RTCSC.Bits.RTCLKS0
#define RTCSC_RTCLKS1                   _RTCSC.Bits.RTCLKS1
#define RTCSC_RTIF                      _RTCSC.Bits.RTIF
#define RTCSC_RTCPS                     _RTCSC.MergedBits.grpRTCPS
#define RTCSC_RTCLKS                    _RTCSC.MergedBits.grpRTCLKS

#define RTCSC_RTCPS0_MASK               1U
#define RTCSC_RTCPS1_MASK               2U
#define RTCSC_RTCPS2_MASK               4U
#define RTCSC_RTCPS3_MASK               8U
#define RTCSC_RTIE_MASK                 16U
#define RTCSC_RTCLKS0_MASK              32U
#define RTCSC_RTCLKS1_MASK              64U
#define RTCSC_RTIF_MASK                 128U
#define RTCSC_RTCPS_MASK                15U
#define RTCSC_RTCPS_BITNUM              0U
#define RTCSC_RTCLKS_MASK               96U
#define RTCSC_RTCLKS_BITNUM             5U


/*** RTCCNT - RTC Counter Register; 0x0000008D ***/
typedef union {
  byte Byte;
} RTCCNTSTR;
extern volatile RTCCNTSTR _RTCCNT @0x0000008D;
#define RTCCNT                          _RTCCNT.Byte


/*** RTCMOD - RTC Modulo Register; 0x0000008E ***/
typedef union {
  byte Byte;
} RTCMODSTR;
extern volatile RTCMODSTR _RTCMOD @0x0000008E;
#define RTCMOD                          _RTCMOD.Byte


/*** SRS - System Reset Status Register; 0x00001800 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte LVD         :1;                                       /* Low Voltage Detect */
    byte             :1; 
    byte ILAD        :1;                                       /* Illegal Address */
    byte ILOP        :1;                                       /* Illegal Opcode */
    byte COP         :1;                                       /* Computer Operating Properly (COP) Watchdog */
    byte PIN         :1;                                       /* External Reset Pin */
    byte POR         :1;                                       /* Power-On Reset */
  } Bits;
} SRSSTR;
extern volatile SRSSTR _SRS @0x00001800;
#define SRS                             _SRS.Byte
#define SRS_LVD                         _SRS.Bits.LVD
#define SRS_ILAD                        _SRS.Bits.ILAD
#define SRS_ILOP                        _SRS.Bits.ILOP
#define SRS_COP                         _SRS.Bits.COP
#define SRS_PIN                         _SRS.Bits.PIN
#define SRS_POR                         _SRS.Bits.POR

#define SRS_LVD_MASK                    2U
#define SRS_ILAD_MASK                   8U
#define SRS_ILOP_MASK                   16U
#define SRS_COP_MASK                    32U
#define SRS_PIN_MASK                    64U
#define SRS_POR_MASK                    128U


/*** SBDFR - System Background Debug Force Reset Register; 0x00001801 ***/
typedef union {
  byte Byte;
  struct {
    byte BDFR        :1;                                       /* Background Debug Force Reset */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} SBDFRSTR;
extern volatile SBDFRSTR _SBDFR @0x00001801;
#define SBDFR                           _SBDFR.Byte
#define SBDFR_BDFR                      _SBDFR.Bits.BDFR

#define SBDFR_BDFR_MASK                 1U


/*** SOPT1 - System Options Register 1; 0x00001802 ***/
typedef union {
  byte Byte;
  struct {
    byte RSTPE       :1;                                       /* RESET Pin Enable */
    byte BKGDPE      :1;                                       /* Background Debug Mode Pin Enable */
    byte ACIC1       :1;                                       /* Analog Comparator to Input Capture Enable */
    byte ACIC2       :1;                                       /* Analog Comparator to Input Capture Enable */
    byte SPIFE       :1;                                       /* SPI Ports Filter Enable */
    byte STOPE       :1;                                       /* Stop Mode Enable */
    byte COPT0       :1;                                       /* COP Watchdog Timeout, bit 0 */
    byte COPT1       :1;                                       /* COP Watchdog Timeout, bit 1 */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpACIC_1 :2;
    byte         :1;
    byte         :1;
    byte grpCOPT :2;
  } MergedBits;
} SOPT1STR;
extern volatile SOPT1STR _SOPT1 @0x00001802;
#define SOPT1                           _SOPT1.Byte
#define SOPT1_RSTPE                     _SOPT1.Bits.RSTPE
#define SOPT1_BKGDPE                    _SOPT1.Bits.BKGDPE
#define SOPT1_ACIC1                     _SOPT1.Bits.ACIC1
#define SOPT1_ACIC2                     _SOPT1.Bits.ACIC2
#define SOPT1_SPIFE                     _SOPT1.Bits.SPIFE
#define SOPT1_STOPE                     _SOPT1.Bits.STOPE
#define SOPT1_COPT0                     _SOPT1.Bits.COPT0
#define SOPT1_COPT1                     _SOPT1.Bits.COPT1
#define SOPT1_ACIC_1                    _SOPT1.MergedBits.grpACIC_1
#define SOPT1_COPT                      _SOPT1.MergedBits.grpCOPT
#define SOPT1_ACIC                      SOPT1_ACIC_1

#define SOPT1_RSTPE_MASK                1U
#define SOPT1_BKGDPE_MASK               2U
#define SOPT1_ACIC1_MASK                4U
#define SOPT1_ACIC2_MASK                8U
#define SOPT1_SPIFE_MASK                16U
#define SOPT1_STOPE_MASK                32U
#define SOPT1_COPT0_MASK                64U
#define SOPT1_COPT1_MASK                128U
#define SOPT1_ACIC_1_MASK               12U
#define SOPT1_ACIC_1_BITNUM             2U
#define SOPT1_COPT_MASK                 192U
#define SOPT1_COPT_BITNUM               6U


/*** SOPT2 - System Options Register 2; 0x00001803 ***/
typedef union {
  byte Byte;
  struct {
    byte CMP2OPS     :1;                                       /* CMP2OUT Pin Select */
    byte CMP3OPS     :1;                                       /* CMP3OUT Pin Select */
    byte TCLKPS      :1;                                       /* TCLK Pin Select */
    byte IICPS0      :1;                                       /* IIC Pin Select, bit 0 */
    byte IICPS1      :1;                                       /* IIC Pin Select, bit 1 */
    byte FTM2T2S     :1;                                       /* Flextimer 2 Trigger 2 Input Select */
    byte COPW        :1;                                       /* COP Window */
    byte COPCLKS     :1;                                       /* COP Watchdog Clock Select */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpIICPS :2;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} SOPT2STR;
extern volatile SOPT2STR _SOPT2 @0x00001803;
#define SOPT2                           _SOPT2.Byte
#define SOPT2_CMP2OPS                   _SOPT2.Bits.CMP2OPS
#define SOPT2_CMP3OPS                   _SOPT2.Bits.CMP3OPS
#define SOPT2_TCLKPS                    _SOPT2.Bits.TCLKPS
#define SOPT2_IICPS0                    _SOPT2.Bits.IICPS0
#define SOPT2_IICPS1                    _SOPT2.Bits.IICPS1
#define SOPT2_FTM2T2S                   _SOPT2.Bits.FTM2T2S
#define SOPT2_COPW                      _SOPT2.Bits.COPW
#define SOPT2_COPCLKS                   _SOPT2.Bits.COPCLKS
#define SOPT2_IICPS                     _SOPT2.MergedBits.grpIICPS

#define SOPT2_CMP2OPS_MASK              1U
#define SOPT2_CMP3OPS_MASK              2U
#define SOPT2_TCLKPS_MASK               4U
#define SOPT2_IICPS0_MASK               8U
#define SOPT2_IICPS1_MASK               16U
#define SOPT2_FTM2T2S_MASK              32U
#define SOPT2_COPW_MASK                 64U
#define SOPT2_COPCLKS_MASK              128U
#define SOPT2_IICPS_MASK                24U
#define SOPT2_IICPS_BITNUM              3U


/*** SDID - System Device Identification Register; 0x00001806 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** SDIDH - System Device Identification Register High; 0x00001806 ***/
    union {
      byte Byte;
      struct {
        byte ID8         :1;                                       /* Part Identification Number, bit 8 */
        byte ID9         :1;                                       /* Part Identification Number, bit 9 */
        byte ID10        :1;                                       /* Part Identification Number, bit 10 */
        byte ID11        :1;                                       /* Part Identification Number, bit 11 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
      struct {
        byte grpID_8 :4;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } SDIDHSTR;
    #define SDIDH                       _SDID.Overlap_STR.SDIDHSTR.Byte
    #define SDIDH_ID8                   _SDID.Overlap_STR.SDIDHSTR.Bits.ID8
    #define SDIDH_ID9                   _SDID.Overlap_STR.SDIDHSTR.Bits.ID9
    #define SDIDH_ID10                  _SDID.Overlap_STR.SDIDHSTR.Bits.ID10
    #define SDIDH_ID11                  _SDID.Overlap_STR.SDIDHSTR.Bits.ID11
    #define SDIDH_ID_8                  _SDID.Overlap_STR.SDIDHSTR.MergedBits.grpID_8
    #define SDIDH_ID                    SDIDH_ID_8
    
    #define SDIDH_ID8_MASK              1U
    #define SDIDH_ID9_MASK              2U
    #define SDIDH_ID10_MASK             4U
    #define SDIDH_ID11_MASK             8U
    #define SDIDH_ID_8_MASK             15U
    #define SDIDH_ID_8_BITNUM           0U
    

    /*** SDIDL - System Device Identification Register Low; 0x00001807 ***/
    union {
      byte Byte;
      struct {
        byte ID0         :1;                                       /* Part Identification Number, bit 0 */
        byte ID1         :1;                                       /* Part Identification Number, bit 1 */
        byte ID2         :1;                                       /* Part Identification Number, bit 2 */
        byte ID3         :1;                                       /* Part Identification Number, bit 3 */
        byte ID4         :1;                                       /* Part Identification Number, bit 4 */
        byte ID5         :1;                                       /* Part Identification Number, bit 5 */
        byte ID6         :1;                                       /* Part Identification Number, bit 6 */
        byte ID7         :1;                                       /* Part Identification Number, bit 7 */
      } Bits;
    } SDIDLSTR;
    #define SDIDL                       _SDID.Overlap_STR.SDIDLSTR.Byte
    #define SDIDL_ID0                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID0
    #define SDIDL_ID1                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID1
    #define SDIDL_ID2                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID2
    #define SDIDL_ID3                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID3
    #define SDIDL_ID4                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID4
    #define SDIDL_ID5                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID5
    #define SDIDL_ID6                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID6
    #define SDIDL_ID7                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID7
    
    #define SDIDL_ID0_MASK              1U
    #define SDIDL_ID1_MASK              2U
    #define SDIDL_ID2_MASK              4U
    #define SDIDL_ID3_MASK              8U
    #define SDIDL_ID4_MASK              16U
    #define SDIDL_ID5_MASK              32U
    #define SDIDL_ID6_MASK              64U
    #define SDIDL_ID7_MASK              128U
    
  } Overlap_STR;

} SDIDSTR;
extern volatile SDIDSTR _SDID @0x00001806;
#define SDID                            _SDID.Word


/*** SPMSC1 - System Power Management Status and Control 1 Register; 0x00001809 ***/
typedef union {
  byte Byte;
  struct {
    byte BGBE        :1;                                       /* Bandgap Buffer Enable */
    byte             :1; 
    byte LVDE        :1;                                       /* Low-Voltage Detect Enable */
    byte LVDSE       :1;                                       /* Low-Voltage Detect Stop Enable */
    byte LVDRE       :1;                                       /* Low-Voltage Detect Reset Enable */
    byte LVWIE       :1;                                       /* Low-Voltage Warning Interrupt Enable */
    byte LVWACK      :1;                                       /* Low-Voltage Warning Acknowledge */
    byte LVWF        :1;                                       /* Low-Voltage Warning status */
  } Bits;
} SPMSC1STR;
extern volatile SPMSC1STR _SPMSC1 @0x00001809;
#define SPMSC1                          _SPMSC1.Byte
#define SPMSC1_BGBE                     _SPMSC1.Bits.BGBE
#define SPMSC1_LVDE                     _SPMSC1.Bits.LVDE
#define SPMSC1_LVDSE                    _SPMSC1.Bits.LVDSE
#define SPMSC1_LVDRE                    _SPMSC1.Bits.LVDRE
#define SPMSC1_LVWIE                    _SPMSC1.Bits.LVWIE
#define SPMSC1_LVWACK                   _SPMSC1.Bits.LVWACK
#define SPMSC1_LVWF                     _SPMSC1.Bits.LVWF

#define SPMSC1_BGBE_MASK                1U
#define SPMSC1_LVDE_MASK                4U
#define SPMSC1_LVDSE_MASK               8U
#define SPMSC1_LVDRE_MASK               16U
#define SPMSC1_LVWIE_MASK               32U
#define SPMSC1_LVWACK_MASK              64U
#define SPMSC1_LVWF_MASK                128U


/*** SPMSC2 - System Power Management Status and Control 2 Register; 0x0000180A ***/
typedef union {
  byte Byte;
  struct {
    byte PPDC        :1;                                       /* Partial Power Down Control */
    byte             :1; 
    byte PPDACK      :1;                                       /* Partial Power Down Acknowledge */
    byte PPDF        :1;                                       /* Partial Power Down Flag */
    byte LVWV        :1;                                       /* Low-Voltage Warning Voltage Select */
    byte LVDV        :1;                                       /* Low-Voltage Detect Voltage Select */
    byte             :1; 
    byte             :1; 
  } Bits;
} SPMSC2STR;
extern volatile SPMSC2STR _SPMSC2 @0x0000180A;
#define SPMSC2                          _SPMSC2.Byte
#define SPMSC2_PPDC                     _SPMSC2.Bits.PPDC
#define SPMSC2_PPDACK                   _SPMSC2.Bits.PPDACK
#define SPMSC2_PPDF                     _SPMSC2.Bits.PPDF
#define SPMSC2_LVWV                     _SPMSC2.Bits.LVWV
#define SPMSC2_LVDV                     _SPMSC2.Bits.LVDV

#define SPMSC2_PPDC_MASK                1U
#define SPMSC2_PPDACK_MASK              4U
#define SPMSC2_PPDF_MASK                8U
#define SPMSC2_LVWV_MASK                16U
#define SPMSC2_LVDV_MASK                32U


/*** SOPT3 - System Options Register 3; 0x0000180B ***/
typedef union {
  byte Byte;
  struct {
    byte SYNCFTM     :1;                                       /* Synchronize FTM */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} SOPT3STR;
extern volatile SOPT3STR _SOPT3 @0x0000180B;
#define SOPT3                           _SOPT3.Byte
#define SOPT3_SYNCFTM                   _SOPT3.Bits.SYNCFTM

#define SOPT3_SYNCFTM_MASK              1U


/*** SCGC1 - System Clock Gating Control 1 Register; 0x0000180E ***/
typedef union {
  byte Byte;
  struct {
    byte CMPDAC1     :1;                                       /* HSCMP1 and DAC1 Clock Gate Control */
    byte CMPDAC2     :1;                                       /* HSCMP2 and DAC2 Clock Gate Control */
    byte CMPDAC3     :1;                                       /* HSCMP3 and DAC3 Clock Gate Control */
    byte PDB         :1;                                       /* PDB1 and PDB2 Clock Gate Control */
    byte RTC         :1;                                       /* RTC Clock Gate Control */
    byte MTIM        :1;                                       /* MTIM Clock Gate Control */
    byte FTM1        :1;                                       /* FTM1 Clock Gate Control */
    byte FTM2        :1;                                       /* FTM2 Clock Gate Control */
  } Bits;
  struct {
    byte grpCMPDAC_1 :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpFTM_1 :2;
  } MergedBits;
} SCGC1STR;
extern volatile SCGC1STR _SCGC1 @0x0000180E;
#define SCGC1                           _SCGC1.Byte
#define SCGC1_CMPDAC1                   _SCGC1.Bits.CMPDAC1
#define SCGC1_CMPDAC2                   _SCGC1.Bits.CMPDAC2
#define SCGC1_CMPDAC3                   _SCGC1.Bits.CMPDAC3
#define SCGC1_PDB                       _SCGC1.Bits.PDB
#define SCGC1_RTC                       _SCGC1.Bits.RTC
#define SCGC1_MTIM                      _SCGC1.Bits.MTIM
#define SCGC1_FTM1                      _SCGC1.Bits.FTM1
#define SCGC1_FTM2                      _SCGC1.Bits.FTM2
#define SCGC1_CMPDAC_1                  _SCGC1.MergedBits.grpCMPDAC_1
#define SCGC1_FTM_1                     _SCGC1.MergedBits.grpFTM_1
#define SCGC1_CMPDAC                    SCGC1_CMPDAC_1
#define SCGC1_FTM                       SCGC1_FTM_1

#define SCGC1_CMPDAC1_MASK              1U
#define SCGC1_CMPDAC2_MASK              2U
#define SCGC1_CMPDAC3_MASK              4U
#define SCGC1_PDB_MASK                  8U
#define SCGC1_RTC_MASK                  16U
#define SCGC1_MTIM_MASK                 32U
#define SCGC1_FTM1_MASK                 64U
#define SCGC1_FTM2_MASK                 128U
#define SCGC1_CMPDAC_1_MASK             7U
#define SCGC1_CMPDAC_1_BITNUM           0U
#define SCGC1_FTM_1_MASK                192U
#define SCGC1_FTM_1_BITNUM              6U


/*** SCGC2 - System Clock Gating Control 2 Register; 0x0000180F ***/
typedef union {
  byte Byte;
  struct {
    byte PGA         :1;                                       /* PGA Clock Gate Control */
    byte IIC         :1;                                       /* IIC Clock Gate Control */
    byte SPI         :1;                                       /* SPI Clock Gate Control */
    byte SCI         :1;                                       /* SCI Clock Gate Control */
    byte ADC         :1;                                       /* ADC Clock Gate Control */
    byte KBI         :1;                                       /* KBI1, KBI2, and KBI3 Clock Gate Control */
    byte FLS         :1;                                       /* Flash Clock Gate Control */
    byte DBG         :1;                                       /* DBG Clock Gate Control */
  } Bits;
} SCGC2STR;
extern volatile SCGC2STR _SCGC2 @0x0000180F;
#define SCGC2                           _SCGC2.Byte
#define SCGC2_PGA                       _SCGC2.Bits.PGA
#define SCGC2_IIC                       _SCGC2.Bits.IIC
#define SCGC2_SPI                       _SCGC2.Bits.SPI
#define SCGC2_SCI                       _SCGC2.Bits.SCI
#define SCGC2_ADC                       _SCGC2.Bits.ADC
#define SCGC2_KBI                       _SCGC2.Bits.KBI
#define SCGC2_FLS                       _SCGC2.Bits.FLS
#define SCGC2_DBG                       _SCGC2.Bits.DBG

#define SCGC2_PGA_MASK                  1U
#define SCGC2_IIC_MASK                  2U
#define SCGC2_SPI_MASK                  4U
#define SCGC2_SCI_MASK                  8U
#define SCGC2_ADC_MASK                  16U
#define SCGC2_KBI_MASK                  32U
#define SCGC2_FLS_MASK                  64U
#define SCGC2_DBG_MASK                  128U


/*** DBGCA - Debug Comparator A Register; 0x00001810 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** DBGCAH - Debug Comparator A High Register; 0x00001810 ***/
    union {
      byte Byte;
      struct {
        byte Bit8        :1;                                       /* Comparator A High Compare Bit 8 */
        byte Bit9        :1;                                       /* Comparator A High Compare Bit 9 */
        byte Bit10       :1;                                       /* Comparator A High Compare Bit 10 */
        byte Bit11       :1;                                       /* Comparator A High Compare Bit 11 */
        byte Bit12       :1;                                       /* Comparator A High Compare Bit 12 */
        byte Bit13       :1;                                       /* Comparator A High Compare Bit 13 */
        byte Bit14       :1;                                       /* Comparator A High Compare Bit 14 */
        byte Bit15       :1;                                       /* Comparator A High Compare Bit 15 */
      } Bits;
    } DBGCAHSTR;
    #define DBGCAH                      _DBGCA.Overlap_STR.DBGCAHSTR.Byte
    #define DBGCAH_Bit8                 _DBGCA.Overlap_STR.DBGCAHSTR.Bits.Bit8
    #define DBGCAH_Bit9                 _DBGCA.Overlap_STR.DBGCAHSTR.Bits.Bit9
    #define DBGCAH_Bit10                _DBGCA.Overlap_STR.DBGCAHSTR.Bits.Bit10
    #define DBGCAH_Bit11                _DBGCA.Overlap_STR.DBGCAHSTR.Bits.Bit11
    #define DBGCAH_Bit12                _DBGCA.Overlap_STR.DBGCAHSTR.Bits.Bit12
    #define DBGCAH_Bit13                _DBGCA.Overlap_STR.DBGCAHSTR.Bits.Bit13
    #define DBGCAH_Bit14                _DBGCA.Overlap_STR.DBGCAHSTR.Bits.Bit14
    #define DBGCAH_Bit15                _DBGCA.Overlap_STR.DBGCAHSTR.Bits.Bit15
    
    #define DBGCAH_Bit8_MASK            1U
    #define DBGCAH_Bit9_MASK            2U
    #define DBGCAH_Bit10_MASK           4U
    #define DBGCAH_Bit11_MASK           8U
    #define DBGCAH_Bit12_MASK           16U
    #define DBGCAH_Bit13_MASK           32U
    #define DBGCAH_Bit14_MASK           64U
    #define DBGCAH_Bit15_MASK           128U
    

    /*** DBGCAL - Debug Comparator A Low Register; 0x00001811 ***/
    union {
      byte Byte;
      struct {
        byte Bit0        :1;                                       /* Comparator A Low Compare Bit 0 */
        byte Bit1        :1;                                       /* Comparator A Low Compare Bit 1 */
        byte Bit2        :1;                                       /* Comparator A Low Compare Bit 2 */
        byte Bit3        :1;                                       /* Comparator A Low Compare Bit 3 */
        byte Bit4        :1;                                       /* Comparator A Low Compare Bit 4 */
        byte Bit5        :1;                                       /* Comparator A Low Compare Bit 5 */
        byte Bit6        :1;                                       /* Comparator A Low Compare Bit 6 */
        byte Bit7        :1;                                       /* Comparator A Low Compare Bit 7 */
      } Bits;
    } DBGCALSTR;
    #define DBGCAL                      _DBGCA.Overlap_STR.DBGCALSTR.Byte
    #define DBGCAL_Bit0                 _DBGCA.Overlap_STR.DBGCALSTR.Bits.Bit0
    #define DBGCAL_Bit1                 _DBGCA.Overlap_STR.DBGCALSTR.Bits.Bit1
    #define DBGCAL_Bit2                 _DBGCA.Overlap_STR.DBGCALSTR.Bits.Bit2
    #define DBGCAL_Bit3                 _DBGCA.Overlap_STR.DBGCALSTR.Bits.Bit3
    #define DBGCAL_Bit4                 _DBGCA.Overlap_STR.DBGCALSTR.Bits.Bit4
    #define DBGCAL_Bit5                 _DBGCA.Overlap_STR.DBGCALSTR.Bits.Bit5
    #define DBGCAL_Bit6                 _DBGCA.Overlap_STR.DBGCALSTR.Bits.Bit6
    #define DBGCAL_Bit7                 _DBGCA.Overlap_STR.DBGCALSTR.Bits.Bit7
    
    #define DBGCAL_Bit0_MASK            1U
    #define DBGCAL_Bit1_MASK            2U
    #define DBGCAL_Bit2_MASK            4U
    #define DBGCAL_Bit3_MASK            8U
    #define DBGCAL_Bit4_MASK            16U
    #define DBGCAL_Bit5_MASK            32U
    #define DBGCAL_Bit6_MASK            64U
    #define DBGCAL_Bit7_MASK            128U
    
  } Overlap_STR;

} DBGCASTR;
extern volatile DBGCASTR _DBGCA @0x00001810;
#define DBGCA                           _DBGCA.Word


/*** DBGCB - Debug Comparator B Register; 0x00001812 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** DBGCBH - Debug Comparator B High Register; 0x00001812 ***/
    union {
      byte Byte;
      struct {
        byte Bit8        :1;                                       /* Comparator B High Compare Bit 8 */
        byte Bit9        :1;                                       /* Comparator B High Compare Bit 9 */
        byte Bit10       :1;                                       /* Comparator B High Compare Bit 10 */
        byte Bit11       :1;                                       /* Comparator B High Compare Bit 11 */
        byte Bit12       :1;                                       /* Comparator B High Compare Bit 12 */
        byte Bit13       :1;                                       /* Comparator B High Compare Bit 13 */
        byte Bit14       :1;                                       /* Comparator B High Compare Bit 14 */
        byte Bit15       :1;                                       /* Comparator B High Compare Bit 15 */
      } Bits;
    } DBGCBHSTR;
    #define DBGCBH                      _DBGCB.Overlap_STR.DBGCBHSTR.Byte
    #define DBGCBH_Bit8                 _DBGCB.Overlap_STR.DBGCBHSTR.Bits.Bit8
    #define DBGCBH_Bit9                 _DBGCB.Overlap_STR.DBGCBHSTR.Bits.Bit9
    #define DBGCBH_Bit10                _DBGCB.Overlap_STR.DBGCBHSTR.Bits.Bit10
    #define DBGCBH_Bit11                _DBGCB.Overlap_STR.DBGCBHSTR.Bits.Bit11
    #define DBGCBH_Bit12                _DBGCB.Overlap_STR.DBGCBHSTR.Bits.Bit12
    #define DBGCBH_Bit13                _DBGCB.Overlap_STR.DBGCBHSTR.Bits.Bit13
    #define DBGCBH_Bit14                _DBGCB.Overlap_STR.DBGCBHSTR.Bits.Bit14
    #define DBGCBH_Bit15                _DBGCB.Overlap_STR.DBGCBHSTR.Bits.Bit15
    
    #define DBGCBH_Bit8_MASK            1U
    #define DBGCBH_Bit9_MASK            2U
    #define DBGCBH_Bit10_MASK           4U
    #define DBGCBH_Bit11_MASK           8U
    #define DBGCBH_Bit12_MASK           16U
    #define DBGCBH_Bit13_MASK           32U
    #define DBGCBH_Bit14_MASK           64U
    #define DBGCBH_Bit15_MASK           128U
    

    /*** DBGCBL - Debug Comparator B Low Register; 0x00001813 ***/
    union {
      byte Byte;
      struct {
        byte Bit0        :1;                                       /* Comparator B Low Compare Bit 0 */
        byte Bit1        :1;                                       /* Comparator B Low Compare Bit 1 */
        byte Bit2        :1;                                       /* Comparator B Low Compare Bit 2 */
        byte Bit3        :1;                                       /* Comparator B Low Compare Bit 3 */
        byte Bit4        :1;                                       /* Comparator B Low Compare Bit 4 */
        byte Bit5        :1;                                       /* Comparator B Low Compare Bit 5 */
        byte Bit6        :1;                                       /* Comparator B Low Compare Bit 6 */
        byte Bit7        :1;                                       /* Comparator B Low Compare Bit 7 */
      } Bits;
    } DBGCBLSTR;
    #define DBGCBL                      _DBGCB.Overlap_STR.DBGCBLSTR.Byte
    #define DBGCBL_Bit0                 _DBGCB.Overlap_STR.DBGCBLSTR.Bits.Bit0
    #define DBGCBL_Bit1                 _DBGCB.Overlap_STR.DBGCBLSTR.Bits.Bit1
    #define DBGCBL_Bit2                 _DBGCB.Overlap_STR.DBGCBLSTR.Bits.Bit2
    #define DBGCBL_Bit3                 _DBGCB.Overlap_STR.DBGCBLSTR.Bits.Bit3
    #define DBGCBL_Bit4                 _DBGCB.Overlap_STR.DBGCBLSTR.Bits.Bit4
    #define DBGCBL_Bit5                 _DBGCB.Overlap_STR.DBGCBLSTR.Bits.Bit5
    #define DBGCBL_Bit6                 _DBGCB.Overlap_STR.DBGCBLSTR.Bits.Bit6
    #define DBGCBL_Bit7                 _DBGCB.Overlap_STR.DBGCBLSTR.Bits.Bit7
    
    #define DBGCBL_Bit0_MASK            1U
    #define DBGCBL_Bit1_MASK            2U
    #define DBGCBL_Bit2_MASK            4U
    #define DBGCBL_Bit3_MASK            8U
    #define DBGCBL_Bit4_MASK            16U
    #define DBGCBL_Bit5_MASK            32U
    #define DBGCBL_Bit6_MASK            64U
    #define DBGCBL_Bit7_MASK            128U
    
  } Overlap_STR;

} DBGCBSTR;
extern volatile DBGCBSTR _DBGCB @0x00001812;
#define DBGCB                           _DBGCB.Word


/*** DBGCC - Debug Comparator C Register; 0x00001814 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** DBGCCH - Debug Comparator C High Register; 0x00001814 ***/
    union {
      byte Byte;
      struct {
        byte Bit8        :1;                                       /* Comparator C High Compare Bit 8 */
        byte Bit9        :1;                                       /* Comparator C High Compare Bit 9 */
        byte Bit10       :1;                                       /* Comparator C High Compare Bit 10 */
        byte Bit11       :1;                                       /* Comparator C High Compare Bit 11 */
        byte Bit12       :1;                                       /* Comparator C High Compare Bit 12 */
        byte Bit13       :1;                                       /* Comparator C High Compare Bit 13 */
        byte Bit14       :1;                                       /* Comparator C High Compare Bit 14 */
        byte Bit15       :1;                                       /* Comparator C High Compare Bit 15 */
      } Bits;
    } DBGCCHSTR;
    #define DBGCCH                      _DBGCC.Overlap_STR.DBGCCHSTR.Byte
    #define DBGCCH_Bit8                 _DBGCC.Overlap_STR.DBGCCHSTR.Bits.Bit8
    #define DBGCCH_Bit9                 _DBGCC.Overlap_STR.DBGCCHSTR.Bits.Bit9
    #define DBGCCH_Bit10                _DBGCC.Overlap_STR.DBGCCHSTR.Bits.Bit10
    #define DBGCCH_Bit11                _DBGCC.Overlap_STR.DBGCCHSTR.Bits.Bit11
    #define DBGCCH_Bit12                _DBGCC.Overlap_STR.DBGCCHSTR.Bits.Bit12
    #define DBGCCH_Bit13                _DBGCC.Overlap_STR.DBGCCHSTR.Bits.Bit13
    #define DBGCCH_Bit14                _DBGCC.Overlap_STR.DBGCCHSTR.Bits.Bit14
    #define DBGCCH_Bit15                _DBGCC.Overlap_STR.DBGCCHSTR.Bits.Bit15
    
    #define DBGCCH_Bit8_MASK            1U
    #define DBGCCH_Bit9_MASK            2U
    #define DBGCCH_Bit10_MASK           4U
    #define DBGCCH_Bit11_MASK           8U
    #define DBGCCH_Bit12_MASK           16U
    #define DBGCCH_Bit13_MASK           32U
    #define DBGCCH_Bit14_MASK           64U
    #define DBGCCH_Bit15_MASK           128U
    

    /*** DBGCCL - Debug Comparator C Low Register; 0x00001815 ***/
    union {
      byte Byte;
      struct {
        byte Bit0        :1;                                       /* Comparator C Low Compare Bit 0 */
        byte Bit1        :1;                                       /* Comparator C Low Compare Bit 1 */
        byte Bit2        :1;                                       /* Comparator C Low Compare Bit 2 */
        byte Bit3        :1;                                       /* Comparator C Low Compare Bit 3 */
        byte Bit4        :1;                                       /* Comparator C Low Compare Bit 4 */
        byte Bit5        :1;                                       /* Comparator C Low Compare Bit 5 */
        byte Bit6        :1;                                       /* Comparator C Low Compare Bit 6 */
        byte Bit7        :1;                                       /* Comparator C Low Compare Bit 7 */
      } Bits;
    } DBGCCLSTR;
    #define DBGCCL                      _DBGCC.Overlap_STR.DBGCCLSTR.Byte
    #define DBGCCL_Bit0                 _DBGCC.Overlap_STR.DBGCCLSTR.Bits.Bit0
    #define DBGCCL_Bit1                 _DBGCC.Overlap_STR.DBGCCLSTR.Bits.Bit1
    #define DBGCCL_Bit2                 _DBGCC.Overlap_STR.DBGCCLSTR.Bits.Bit2
    #define DBGCCL_Bit3                 _DBGCC.Overlap_STR.DBGCCLSTR.Bits.Bit3
    #define DBGCCL_Bit4                 _DBGCC.Overlap_STR.DBGCCLSTR.Bits.Bit4
    #define DBGCCL_Bit5                 _DBGCC.Overlap_STR.DBGCCLSTR.Bits.Bit5
    #define DBGCCL_Bit6                 _DBGCC.Overlap_STR.DBGCCLSTR.Bits.Bit6
    #define DBGCCL_Bit7                 _DBGCC.Overlap_STR.DBGCCLSTR.Bits.Bit7
    
    #define DBGCCL_Bit0_MASK            1U
    #define DBGCCL_Bit1_MASK            2U
    #define DBGCCL_Bit2_MASK            4U
    #define DBGCCL_Bit3_MASK            8U
    #define DBGCCL_Bit4_MASK            16U
    #define DBGCCL_Bit5_MASK            32U
    #define DBGCCL_Bit6_MASK            64U
    #define DBGCCL_Bit7_MASK            128U
    
  } Overlap_STR;

} DBGCCSTR;
extern volatile DBGCCSTR _DBGCC @0x00001814;
#define DBGCC                           _DBGCC.Word


/*** DBGF - Debug FIFO Register; 0x00001816 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** DBGFH - Debug FIFO High Register; 0x00001816 ***/
    union {
      byte Byte;
      struct {
        byte Bit8        :1;                                       /* FIFO High Data Bit 8 */
        byte Bit9        :1;                                       /* FIFO High Data Bit 9 */
        byte Bit10       :1;                                       /* FIFO High Data Bit 10 */
        byte Bit11       :1;                                       /* FIFO High Data Bit 11 */
        byte Bit12       :1;                                       /* FIFO High Data Bit 12 */
        byte Bit13       :1;                                       /* FIFO High Data Bit 13 */
        byte Bit14       :1;                                       /* FIFO High Data Bit 14 */
        byte Bit15       :1;                                       /* FIFO High Data Bit 15 */
      } Bits;
    } DBGFHSTR;
    #define DBGFH                       _DBGF.Overlap_STR.DBGFHSTR.Byte
    #define DBGFH_Bit8                  _DBGF.Overlap_STR.DBGFHSTR.Bits.Bit8
    #define DBGFH_Bit9                  _DBGF.Overlap_STR.DBGFHSTR.Bits.Bit9
    #define DBGFH_Bit10                 _DBGF.Overlap_STR.DBGFHSTR.Bits.Bit10
    #define DBGFH_Bit11                 _DBGF.Overlap_STR.DBGFHSTR.Bits.Bit11
    #define DBGFH_Bit12                 _DBGF.Overlap_STR.DBGFHSTR.Bits.Bit12
    #define DBGFH_Bit13                 _DBGF.Overlap_STR.DBGFHSTR.Bits.Bit13
    #define DBGFH_Bit14                 _DBGF.Overlap_STR.DBGFHSTR.Bits.Bit14
    #define DBGFH_Bit15                 _DBGF.Overlap_STR.DBGFHSTR.Bits.Bit15
    
    #define DBGFH_Bit8_MASK             1U
    #define DBGFH_Bit9_MASK             2U
    #define DBGFH_Bit10_MASK            4U
    #define DBGFH_Bit11_MASK            8U
    #define DBGFH_Bit12_MASK            16U
    #define DBGFH_Bit13_MASK            32U
    #define DBGFH_Bit14_MASK            64U
    #define DBGFH_Bit15_MASK            128U
    

    /*** DBGFL - Debug FIFO Low Register; 0x00001817 ***/
    union {
      byte Byte;
      struct {
        byte Bit0        :1;                                       /* FIFO Low Data Bit 0 */
        byte Bit1        :1;                                       /* FIFO Low Data Bit 1 */
        byte Bit2        :1;                                       /* FIFO Low Data Bit 2 */
        byte Bit3        :1;                                       /* FIFO Low Data Bit 3 */
        byte Bit4        :1;                                       /* FIFO Low Data Bit 4 */
        byte Bit5        :1;                                       /* FIFO Low Data Bit 5 */
        byte Bit6        :1;                                       /* FIFO Low Data Bit 6 */
        byte Bit7        :1;                                       /* FIFO Low Data Bit 7 */
      } Bits;
    } DBGFLSTR;
    #define DBGFL                       _DBGF.Overlap_STR.DBGFLSTR.Byte
    #define DBGFL_Bit0                  _DBGF.Overlap_STR.DBGFLSTR.Bits.Bit0
    #define DBGFL_Bit1                  _DBGF.Overlap_STR.DBGFLSTR.Bits.Bit1
    #define DBGFL_Bit2                  _DBGF.Overlap_STR.DBGFLSTR.Bits.Bit2
    #define DBGFL_Bit3                  _DBGF.Overlap_STR.DBGFLSTR.Bits.Bit3
    #define DBGFL_Bit4                  _DBGF.Overlap_STR.DBGFLSTR.Bits.Bit4
    #define DBGFL_Bit5                  _DBGF.Overlap_STR.DBGFLSTR.Bits.Bit5
    #define DBGFL_Bit6                  _DBGF.Overlap_STR.DBGFLSTR.Bits.Bit6
    #define DBGFL_Bit7                  _DBGF.Overlap_STR.DBGFLSTR.Bits.Bit7
    
    #define DBGFL_Bit0_MASK             1U
    #define DBGFL_Bit1_MASK             2U
    #define DBGFL_Bit2_MASK             4U
    #define DBGFL_Bit3_MASK             8U
    #define DBGFL_Bit4_MASK             16U
    #define DBGFL_Bit5_MASK             32U
    #define DBGFL_Bit6_MASK             64U
    #define DBGFL_Bit7_MASK             128U
    
  } Overlap_STR;

} DBGFSTR;
extern volatile DBGFSTR _DBGF @0x00001816;
#define DBGF                            _DBGF.Word


/*** DBGCAX - Debug Comparator A Extension Register; 0x00001818 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte RWA         :1;                                       /* Read/Write Comparator A Value Bit */
    byte RWAEN       :1;                                       /* Read/Write Comparator A Enable Bit */
  } Bits;
} DBGCAXSTR;
extern volatile DBGCAXSTR _DBGCAX @0x00001818;
#define DBGCAX                          _DBGCAX.Byte
#define DBGCAX_RWA                      _DBGCAX.Bits.RWA
#define DBGCAX_RWAEN                    _DBGCAX.Bits.RWAEN

#define DBGCAX_RWA_MASK                 64U
#define DBGCAX_RWAEN_MASK               128U


/*** DBGCBX - Debug Comparator B Extension Register; 0x00001819 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte RWB         :1;                                       /* Read/Write Comparator B Value Bit */
    byte RWBEN       :1;                                       /* Read/Write Comparator B Enable Bit */
  } Bits;
} DBGCBXSTR;
extern volatile DBGCBXSTR _DBGCBX @0x00001819;
#define DBGCBX                          _DBGCBX.Byte
#define DBGCBX_RWB                      _DBGCBX.Bits.RWB
#define DBGCBX_RWBEN                    _DBGCBX.Bits.RWBEN

#define DBGCBX_RWB_MASK                 64U
#define DBGCBX_RWBEN_MASK               128U


/*** DBGCCX - Debug Comparator C Extension Register; 0x0000181A ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte RWC         :1;                                       /* Read/Write Comparator C Value Bit */
    byte RWCEN       :1;                                       /* Read/Write Comparator C Enable Bit */
  } Bits;
} DBGCCXSTR;
extern volatile DBGCCXSTR _DBGCCX @0x0000181A;
#define DBGCCX                          _DBGCCX.Byte
#define DBGCCX_RWC                      _DBGCCX.Bits.RWC
#define DBGCCX_RWCEN                    _DBGCCX.Bits.RWCEN

#define DBGCCX_RWC_MASK                 64U
#define DBGCCX_RWCEN_MASK               128U


/*** DBGC - Debug Control Register; 0x0000181C ***/
typedef union {
  byte Byte;
  struct {
    byte LOOP1       :1;                                       /* Select LOOP1 Capture Mode */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte BRKEN       :1;                                       /* Break Enable Bit */
    byte TAG         :1;                                       /* Tag or Force Bit */
    byte ARM         :1;                                       /* Arm Bit */
    byte DBGEN       :1;                                       /* DBG Module Enable Bit */
  } Bits;
} DBGCSTR;
extern volatile DBGCSTR _DBGC @0x0000181C;
#define DBGC                            _DBGC.Byte
#define DBGC_LOOP1                      _DBGC.Bits.LOOP1
#define DBGC_BRKEN                      _DBGC.Bits.BRKEN
#define DBGC_TAG                        _DBGC.Bits.TAG
#define DBGC_ARM                        _DBGC.Bits.ARM
#define DBGC_DBGEN                      _DBGC.Bits.DBGEN

#define DBGC_LOOP1_MASK                 1U
#define DBGC_BRKEN_MASK                 16U
#define DBGC_TAG_MASK                   32U
#define DBGC_ARM_MASK                   64U
#define DBGC_DBGEN_MASK                 128U


/*** DBGT - Debug Trigger Register; 0x0000181D ***/
typedef union {
  byte Byte;
  struct {
    byte TRG0        :1;                                       /* Trigger Mode Bit 0 */
    byte TRG1        :1;                                       /* Trigger Mode Bit 1 */
    byte TRG2        :1;                                       /* Trigger Mode Bit 2 */
    byte TRG3        :1;                                       /* Trigger Mode Bit 3 */
    byte             :1; 
    byte             :1; 
    byte BEGIN       :1;                                       /* Begin/End Trigger Bit */
    byte TRGSEL      :1;                                       /* Trigger Selection Bit */
  } Bits;
  struct {
    byte grpTRG  :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} DBGTSTR;
extern volatile DBGTSTR _DBGT @0x0000181D;
#define DBGT                            _DBGT.Byte
#define DBGT_TRG0                       _DBGT.Bits.TRG0
#define DBGT_TRG1                       _DBGT.Bits.TRG1
#define DBGT_TRG2                       _DBGT.Bits.TRG2
#define DBGT_TRG3                       _DBGT.Bits.TRG3
#define DBGT_BEGIN                      _DBGT.Bits.BEGIN
#define DBGT_TRGSEL                     _DBGT.Bits.TRGSEL
#define DBGT_TRG                        _DBGT.MergedBits.grpTRG

#define DBGT_TRG0_MASK                  1U
#define DBGT_TRG1_MASK                  2U
#define DBGT_TRG2_MASK                  4U
#define DBGT_TRG3_MASK                  8U
#define DBGT_BEGIN_MASK                 64U
#define DBGT_TRGSEL_MASK                128U
#define DBGT_TRG_MASK                   15U
#define DBGT_TRG_BITNUM                 0U


/*** DBGS - Debug Status Register; 0x0000181E ***/
typedef union {
  byte Byte;
  struct {
    byte ARMF        :1;                                       /* Arm Flag Bit */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte CF          :1;                                       /* Trigger C Match Bit */
    byte BF          :1;                                       /* Trigger B Match Bit */
    byte AF          :1;                                       /* Trigger A Match Bit */
  } Bits;
} DBGSSTR;
extern volatile DBGSSTR _DBGS @0x0000181E;
#define DBGS                            _DBGS.Byte
#define DBGS_ARMF                       _DBGS.Bits.ARMF
#define DBGS_CF                         _DBGS.Bits.CF
#define DBGS_BF                         _DBGS.Bits.BF
#define DBGS_AF                         _DBGS.Bits.AF

#define DBGS_ARMF_MASK                  1U
#define DBGS_CF_MASK                    32U
#define DBGS_BF_MASK                    64U
#define DBGS_AF_MASK                    128U


/*** DBGCNT - Debug Count Status Register; 0x0000181F ***/
typedef union {
  byte Byte;
  struct {
    byte CNT0        :1;                                       /* FIFO Valid Count Bits, bit 0 */
    byte CNT1        :1;                                       /* FIFO Valid Count Bits, bit 1 */
    byte CNT2        :1;                                       /* FIFO Valid Count Bits, bit 2 */
    byte CNT3        :1;                                       /* FIFO Valid Count Bits, bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpCNT  :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} DBGCNTSTR;
extern volatile DBGCNTSTR _DBGCNT @0x0000181F;
#define DBGCNT                          _DBGCNT.Byte
#define DBGCNT_CNT0                     _DBGCNT.Bits.CNT0
#define DBGCNT_CNT1                     _DBGCNT.Bits.CNT1
#define DBGCNT_CNT2                     _DBGCNT.Bits.CNT2
#define DBGCNT_CNT3                     _DBGCNT.Bits.CNT3
#define DBGCNT_CNT                      _DBGCNT.MergedBits.grpCNT

#define DBGCNT_CNT0_MASK                1U
#define DBGCNT_CNT1_MASK                2U
#define DBGCNT_CNT2_MASK                4U
#define DBGCNT_CNT3_MASK                8U
#define DBGCNT_CNT_MASK                 15U
#define DBGCNT_CNT_BITNUM               0U


/*** FCDIV - FLASH Clock Divider Register; 0x00001820 ***/
typedef union {
  byte Byte;
  struct {
    byte DIV0        :1;                                       /* Divisor for FLASH Clock Divider, bit 0 */
    byte DIV1        :1;                                       /* Divisor for FLASH Clock Divider, bit 1 */
    byte DIV2        :1;                                       /* Divisor for FLASH Clock Divider, bit 2 */
    byte DIV3        :1;                                       /* Divisor for FLASH Clock Divider, bit 3 */
    byte DIV4        :1;                                       /* Divisor for FLASH Clock Divider, bit 4 */
    byte DIV5        :1;                                       /* Divisor for FLASH Clock Divider, bit 5 */
    byte PRDIV8      :1;                                       /* Prescale (Divide) FLASH Clock by 8 */
    byte DIVLD       :1;                                       /* Divisor Loaded Status Flag */
  } Bits;
  struct {
    byte grpDIV  :6;
    byte grpPRDIV_8 :1;
    byte         :1;
  } MergedBits;
} FCDIVSTR;
extern volatile FCDIVSTR _FCDIV @0x00001820;
#define FCDIV                           _FCDIV.Byte
#define FCDIV_DIV0                      _FCDIV.Bits.DIV0
#define FCDIV_DIV1                      _FCDIV.Bits.DIV1
#define FCDIV_DIV2                      _FCDIV.Bits.DIV2
#define FCDIV_DIV3                      _FCDIV.Bits.DIV3
#define FCDIV_DIV4                      _FCDIV.Bits.DIV4
#define FCDIV_DIV5                      _FCDIV.Bits.DIV5
#define FCDIV_PRDIV8                    _FCDIV.Bits.PRDIV8
#define FCDIV_DIVLD                     _FCDIV.Bits.DIVLD
#define FCDIV_DIV                       _FCDIV.MergedBits.grpDIV

#define FCDIV_DIV0_MASK                 1U
#define FCDIV_DIV1_MASK                 2U
#define FCDIV_DIV2_MASK                 4U
#define FCDIV_DIV3_MASK                 8U
#define FCDIV_DIV4_MASK                 16U
#define FCDIV_DIV5_MASK                 32U
#define FCDIV_PRDIV8_MASK               64U
#define FCDIV_DIVLD_MASK                128U
#define FCDIV_DIV_MASK                  63U
#define FCDIV_DIV_BITNUM                0U


/*** FOPT - FLASH Options Register; 0x00001821 ***/
typedef union {
  byte Byte;
  struct {
    byte SEC00       :1;                                       /* Security State Code, bit 0 */
    byte SEC01       :1;                                       /* Security State Code, bit 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte FNORED      :1;                                       /* Vector Redirection Disable */
    byte KEYEN       :1;                                       /* Backdoor Key Mechanism Enable */
  } Bits;
  struct {
    byte grpSEC0 :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} FOPTSTR;
extern volatile FOPTSTR _FOPT @0x00001821;
#define FOPT                            _FOPT.Byte
#define FOPT_SEC00                      _FOPT.Bits.SEC00
#define FOPT_SEC01                      _FOPT.Bits.SEC01
#define FOPT_FNORED                     _FOPT.Bits.FNORED
#define FOPT_KEYEN                      _FOPT.Bits.KEYEN
#define FOPT_SEC0                       _FOPT.MergedBits.grpSEC0

#define FOPT_SEC00_MASK                 1U
#define FOPT_SEC01_MASK                 2U
#define FOPT_FNORED_MASK                64U
#define FOPT_KEYEN_MASK                 128U
#define FOPT_SEC0_MASK                  3U
#define FOPT_SEC0_BITNUM                0U


/*** FCNFG - FLASH Configuration Register; 0x00001823 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte KEYACC      :1;                                       /* Enable Writing of Access Key */
    byte             :1; 
    byte             :1; 
  } Bits;
} FCNFGSTR;
extern volatile FCNFGSTR _FCNFG @0x00001823;
#define FCNFG                           _FCNFG.Byte
#define FCNFG_KEYACC                    _FCNFG.Bits.KEYACC

#define FCNFG_KEYACC_MASK               32U


/*** FPROT - FLASH Protection Register; 0x00001824 ***/
typedef union {
  byte Byte;
  struct {
    byte FPDIS       :1;                                       /* FLASH Protection Disable */
    byte FPS1        :1;                                       /* FLASH Protect Select Bit 1 */
    byte FPS2        :1;                                       /* FLASH Protect Select Bit 2 */
    byte FPS3        :1;                                       /* FLASH Protect Select Bit 3 */
    byte FPS4        :1;                                       /* FLASH Protect Select Bit 4 */
    byte FPS5        :1;                                       /* FLASH Protect Select Bit 5 */
    byte FPS6        :1;                                       /* FLASH Protect Select Bit 6 */
    byte FPS7        :1;                                       /* FLASH Protect Select Bit 7 */
  } Bits;
  struct {
    byte         :1;
    byte grpFPS_1 :7;
  } MergedBits;
} FPROTSTR;
extern volatile FPROTSTR _FPROT @0x00001824;
#define FPROT                           _FPROT.Byte
#define FPROT_FPDIS                     _FPROT.Bits.FPDIS
#define FPROT_FPS1                      _FPROT.Bits.FPS1
#define FPROT_FPS2                      _FPROT.Bits.FPS2
#define FPROT_FPS3                      _FPROT.Bits.FPS3
#define FPROT_FPS4                      _FPROT.Bits.FPS4
#define FPROT_FPS5                      _FPROT.Bits.FPS5
#define FPROT_FPS6                      _FPROT.Bits.FPS6
#define FPROT_FPS7                      _FPROT.Bits.FPS7
#define FPROT_FPS_1                     _FPROT.MergedBits.grpFPS_1
#define FPROT_FPS                       FPROT_FPS_1

#define FPROT_FPDIS_MASK                1U
#define FPROT_FPS1_MASK                 2U
#define FPROT_FPS2_MASK                 4U
#define FPROT_FPS3_MASK                 8U
#define FPROT_FPS4_MASK                 16U
#define FPROT_FPS5_MASK                 32U
#define FPROT_FPS6_MASK                 64U
#define FPROT_FPS7_MASK                 128U
#define FPROT_FPS_1_MASK                254U
#define FPROT_FPS_1_BITNUM              1U


/*** FSTAT - Flash Status Register; 0x00001825 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte FBLANK      :1;                                       /* FLASH Flag Indicating the Erase Verify Operation Status */
    byte             :1; 
    byte FACCERR     :1;                                       /* FLASH Access Error Flag */
    byte FPVIOL      :1;                                       /* FLASH Protection Violation Flag */
    byte FCCF        :1;                                       /* FLASH Command Complete Interrupt Flag */
    byte FCBEF       :1;                                       /* FLASH Command Buffer Empty Flag */
  } Bits;
} FSTATSTR;
extern volatile FSTATSTR _FSTAT @0x00001825;
#define FSTAT                           _FSTAT.Byte
#define FSTAT_FBLANK                    _FSTAT.Bits.FBLANK
#define FSTAT_FACCERR                   _FSTAT.Bits.FACCERR
#define FSTAT_FPVIOL                    _FSTAT.Bits.FPVIOL
#define FSTAT_FCCF                      _FSTAT.Bits.FCCF
#define FSTAT_FCBEF                     _FSTAT.Bits.FCBEF

#define FSTAT_FBLANK_MASK               4U
#define FSTAT_FACCERR_MASK              16U
#define FSTAT_FPVIOL_MASK               32U
#define FSTAT_FCCF_MASK                 64U
#define FSTAT_FCBEF_MASK                128U


/*** FCMD - FLASH Command Register; 0x00001826 ***/
typedef union {
  byte Byte;
  struct {
    byte FCMD0       :1;                                       /* FLASH Command Bit 0 */
    byte FCMD1       :1;                                       /* FLASH Command Bit 1 */
    byte FCMD2       :1;                                       /* FLASH Command Bit 2 */
    byte FCMD3       :1;                                       /* FLASH Command Bit 3 */
    byte FCMD4       :1;                                       /* FLASH Command Bit 4 */
    byte FCMD5       :1;                                       /* FLASH Command Bit 5 */
    byte FCMD6       :1;                                       /* FLASH Command Bit 6 */
    byte FCMD7       :1;                                       /* FLASH Command Bit 7 */
  } Bits;
} FCMDSTR;
extern volatile FCMDSTR _FCMD @0x00001826;
#define FCMD                            _FCMD.Byte
#define FCMD_FCMD0                      _FCMD.Bits.FCMD0
#define FCMD_FCMD1                      _FCMD.Bits.FCMD1
#define FCMD_FCMD2                      _FCMD.Bits.FCMD2
#define FCMD_FCMD3                      _FCMD.Bits.FCMD3
#define FCMD_FCMD4                      _FCMD.Bits.FCMD4
#define FCMD_FCMD5                      _FCMD.Bits.FCMD5
#define FCMD_FCMD6                      _FCMD.Bits.FCMD6
#define FCMD_FCMD7                      _FCMD.Bits.FCMD7

#define FCMD_FCMD0_MASK                 1U
#define FCMD_FCMD1_MASK                 2U
#define FCMD_FCMD2_MASK                 4U
#define FCMD_FCMD3_MASK                 8U
#define FCMD_FCMD4_MASK                 16U
#define FCMD_FCMD5_MASK                 32U
#define FCMD_FCMD6_MASK                 64U
#define FCMD_FCMD7_MASK                 128U


/*** PTAPE - Port A Pull Enable Register; 0x00001840 ***/
typedef union {
  byte Byte;
  struct {
    byte PTAPE0      :1;                                       /* Internal Pull Enable for Port A Bit 0 */
    byte PTAPE1      :1;                                       /* Internal Pull Enable for Port A Bit 1 */
    byte PTAPE2      :1;                                       /* Internal Pull Enable for Port A Bit 2 */
    byte PTAPE3      :1;                                       /* Internal Pull Enable for Port A Bit 3 */
    byte PTAPE4      :1;                                       /* Internal Pull Enable for Port A Bit 4 */
    byte PTAPE5      :1;                                       /* Internal Pull Enable for Port A Bit 5 */
    byte PTAPE6      :1;                                       /* Internal Pull Enable for Port A Bit 6 */
    byte PTAPE7      :1;                                       /* Internal Pull Enable for Port A Bit 7 */
  } Bits;
} PTAPESTR;
extern volatile PTAPESTR _PTAPE @0x00001840;
#define PTAPE                           _PTAPE.Byte
#define PTAPE_PTAPE0                    _PTAPE.Bits.PTAPE0
#define PTAPE_PTAPE1                    _PTAPE.Bits.PTAPE1
#define PTAPE_PTAPE2                    _PTAPE.Bits.PTAPE2
#define PTAPE_PTAPE3                    _PTAPE.Bits.PTAPE3
#define PTAPE_PTAPE4                    _PTAPE.Bits.PTAPE4
#define PTAPE_PTAPE5                    _PTAPE.Bits.PTAPE5
#define PTAPE_PTAPE6                    _PTAPE.Bits.PTAPE6
#define PTAPE_PTAPE7                    _PTAPE.Bits.PTAPE7

#define PTAPE_PTAPE0_MASK               1U
#define PTAPE_PTAPE1_MASK               2U
#define PTAPE_PTAPE2_MASK               4U
#define PTAPE_PTAPE3_MASK               8U
#define PTAPE_PTAPE4_MASK               16U
#define PTAPE_PTAPE5_MASK               32U
#define PTAPE_PTAPE6_MASK               64U
#define PTAPE_PTAPE7_MASK               128U


/*** PTASE - Port A Slew Rate Enable Register; 0x00001841 ***/
typedef union {
  byte Byte;
  struct {
    byte PTASE0      :1;                                       /* Output Slew Rate Enable for Port A Bit 0 */
    byte PTASE1      :1;                                       /* Output Slew Rate Enable for Port A Bit 1 */
    byte PTASE2      :1;                                       /* Output Slew Rate Enable for Port A Bit 2 */
    byte PTASE3      :1;                                       /* Output Slew Rate Enable for Port A Bit 3 */
    byte PTASE4      :1;                                       /* Output Slew Rate Enable for Port A Bit 4 */
    byte PTASE5      :1;                                       /* Output Slew Rate Enable for Port A Bit 5 */
    byte PTASE6      :1;                                       /* Output Slew Rate Enable for Port A Bit 6 */
    byte PTASE7      :1;                                       /* Output Slew Rate Enable for Port A Bit 7 */
  } Bits;
} PTASESTR;
extern volatile PTASESTR _PTASE @0x00001841;
#define PTASE                           _PTASE.Byte
#define PTASE_PTASE0                    _PTASE.Bits.PTASE0
#define PTASE_PTASE1                    _PTASE.Bits.PTASE1
#define PTASE_PTASE2                    _PTASE.Bits.PTASE2
#define PTASE_PTASE3                    _PTASE.Bits.PTASE3
#define PTASE_PTASE4                    _PTASE.Bits.PTASE4
#define PTASE_PTASE5                    _PTASE.Bits.PTASE5
#define PTASE_PTASE6                    _PTASE.Bits.PTASE6
#define PTASE_PTASE7                    _PTASE.Bits.PTASE7

#define PTASE_PTASE0_MASK               1U
#define PTASE_PTASE1_MASK               2U
#define PTASE_PTASE2_MASK               4U
#define PTASE_PTASE3_MASK               8U
#define PTASE_PTASE4_MASK               16U
#define PTASE_PTASE5_MASK               32U
#define PTASE_PTASE6_MASK               64U
#define PTASE_PTASE7_MASK               128U


/*** PTADS - Port A Drive Strength Selection Register; 0x00001842 ***/
typedef union {
  byte Byte;
  struct {
    byte PTADS0      :1;                                       /* Output Drive Strength Selection for Port A Bit 0 */
    byte PTADS1      :1;                                       /* Output Drive Strength Selection for Port A Bit 1 */
    byte PTADS2      :1;                                       /* Output Drive Strength Selection for Port A Bit 2 */
    byte PTADS3      :1;                                       /* Output Drive Strength Selection for Port A Bit 3 */
    byte PTADS4      :1;                                       /* Output Drive Strength Selection for Port A Bit 4 */
    byte PTADS5      :1;                                       /* Output Drive Strength Selection for Port A Bit 5 */
    byte PTADS6      :1;                                       /* Output Drive Strength Selection for Port A Bit 6 */
    byte PTADS7      :1;                                       /* Output Drive Strength Selection for Port A Bit 7 */
  } Bits;
} PTADSSTR;
extern volatile PTADSSTR _PTADS @0x00001842;
#define PTADS                           _PTADS.Byte
#define PTADS_PTADS0                    _PTADS.Bits.PTADS0
#define PTADS_PTADS1                    _PTADS.Bits.PTADS1
#define PTADS_PTADS2                    _PTADS.Bits.PTADS2
#define PTADS_PTADS3                    _PTADS.Bits.PTADS3
#define PTADS_PTADS4                    _PTADS.Bits.PTADS4
#define PTADS_PTADS5                    _PTADS.Bits.PTADS5
#define PTADS_PTADS6                    _PTADS.Bits.PTADS6
#define PTADS_PTADS7                    _PTADS.Bits.PTADS7

#define PTADS_PTADS0_MASK               1U
#define PTADS_PTADS1_MASK               2U
#define PTADS_PTADS2_MASK               4U
#define PTADS_PTADS3_MASK               8U
#define PTADS_PTADS4_MASK               16U
#define PTADS_PTADS5_MASK               32U
#define PTADS_PTADS6_MASK               64U
#define PTADS_PTADS7_MASK               128U


/*** PTBPE - Port B Pull Enable Register; 0x00001844 ***/
typedef union {
  byte Byte;
  struct {
    byte PTBPE0      :1;                                       /* Internal Pull Enable for Port B Bit 0 */
    byte PTBPE1      :1;                                       /* Internal Pull Enable for Port B Bit 1 */
    byte PTBPE2      :1;                                       /* Internal Pull Enable for Port B Bit 2 */
    byte PTBPE3      :1;                                       /* Internal Pull Enable for Port B Bit 3 */
    byte PTBPE4      :1;                                       /* Internal Pull Enable for Port B Bit 4 */
    byte PTBPE5      :1;                                       /* Internal Pull Enable for Port B Bit 5 */
    byte PTBPE6      :1;                                       /* Internal Pull Enable for Port B Bit 6 */
    byte PTBPE7      :1;                                       /* Internal Pull Enable for Port B Bit 7 */
  } Bits;
} PTBPESTR;
extern volatile PTBPESTR _PTBPE @0x00001844;
#define PTBPE                           _PTBPE.Byte
#define PTBPE_PTBPE0                    _PTBPE.Bits.PTBPE0
#define PTBPE_PTBPE1                    _PTBPE.Bits.PTBPE1
#define PTBPE_PTBPE2                    _PTBPE.Bits.PTBPE2
#define PTBPE_PTBPE3                    _PTBPE.Bits.PTBPE3
#define PTBPE_PTBPE4                    _PTBPE.Bits.PTBPE4
#define PTBPE_PTBPE5                    _PTBPE.Bits.PTBPE5
#define PTBPE_PTBPE6                    _PTBPE.Bits.PTBPE6
#define PTBPE_PTBPE7                    _PTBPE.Bits.PTBPE7

#define PTBPE_PTBPE0_MASK               1U
#define PTBPE_PTBPE1_MASK               2U
#define PTBPE_PTBPE2_MASK               4U
#define PTBPE_PTBPE3_MASK               8U
#define PTBPE_PTBPE4_MASK               16U
#define PTBPE_PTBPE5_MASK               32U
#define PTBPE_PTBPE6_MASK               64U
#define PTBPE_PTBPE7_MASK               128U


/*** PTBSE - Port B Slew Rate Enable Register; 0x00001845 ***/
typedef union {
  byte Byte;
  struct {
    byte PTBSE0      :1;                                       /* Output Slew Rate Enable for Port B Bit 0 */
    byte PTBSE1      :1;                                       /* Output Slew Rate Enable for Port B Bit 1 */
    byte PTBSE2      :1;                                       /* Output Slew Rate Enable for Port B Bit 2 */
    byte PTBSE3      :1;                                       /* Output Slew Rate Enable for Port B Bit 3 */
    byte PTBSE4      :1;                                       /* Output Slew Rate Enable for Port B Bit 4 */
    byte PTBSE5      :1;                                       /* Output Slew Rate Enable for Port B Bit 5 */
    byte PTBSE6      :1;                                       /* Output Slew Rate Enable for Port B Bit 6 */
    byte PTBSE7      :1;                                       /* Output Slew Rate Enable for Port B Bit 7 */
  } Bits;
} PTBSESTR;
extern volatile PTBSESTR _PTBSE @0x00001845;
#define PTBSE                           _PTBSE.Byte
#define PTBSE_PTBSE0                    _PTBSE.Bits.PTBSE0
#define PTBSE_PTBSE1                    _PTBSE.Bits.PTBSE1
#define PTBSE_PTBSE2                    _PTBSE.Bits.PTBSE2
#define PTBSE_PTBSE3                    _PTBSE.Bits.PTBSE3
#define PTBSE_PTBSE4                    _PTBSE.Bits.PTBSE4
#define PTBSE_PTBSE5                    _PTBSE.Bits.PTBSE5
#define PTBSE_PTBSE6                    _PTBSE.Bits.PTBSE6
#define PTBSE_PTBSE7                    _PTBSE.Bits.PTBSE7

#define PTBSE_PTBSE0_MASK               1U
#define PTBSE_PTBSE1_MASK               2U
#define PTBSE_PTBSE2_MASK               4U
#define PTBSE_PTBSE3_MASK               8U
#define PTBSE_PTBSE4_MASK               16U
#define PTBSE_PTBSE5_MASK               32U
#define PTBSE_PTBSE6_MASK               64U
#define PTBSE_PTBSE7_MASK               128U


/*** PTBDS - Port B Drive Strength Selection Register; 0x00001846 ***/
typedef union {
  byte Byte;
  struct {
    byte PTBDS0      :1;                                       /* Output Drive Strength Selection for Port B Bit 0 */
    byte PTBDS1      :1;                                       /* Output Drive Strength Selection for Port B Bit 1 */
    byte PTBDS2      :1;                                       /* Output Drive Strength Selection for Port B Bit 2 */
    byte PTBDS3      :1;                                       /* Output Drive Strength Selection for Port B Bit 3 */
    byte PTBDS4      :1;                                       /* Output Drive Strength Selection for Port B Bit 4 */
    byte PTBDS5      :1;                                       /* Output Drive Strength Selection for Port B Bit 5 */
    byte PTBDS6      :1;                                       /* Output Drive Strength Selection for Port B Bit 6 */
    byte PTBDS7      :1;                                       /* Output Drive Strength Selection for Port B Bit 7 */
  } Bits;
} PTBDSSTR;
extern volatile PTBDSSTR _PTBDS @0x00001846;
#define PTBDS                           _PTBDS.Byte
#define PTBDS_PTBDS0                    _PTBDS.Bits.PTBDS0
#define PTBDS_PTBDS1                    _PTBDS.Bits.PTBDS1
#define PTBDS_PTBDS2                    _PTBDS.Bits.PTBDS2
#define PTBDS_PTBDS3                    _PTBDS.Bits.PTBDS3
#define PTBDS_PTBDS4                    _PTBDS.Bits.PTBDS4
#define PTBDS_PTBDS5                    _PTBDS.Bits.PTBDS5
#define PTBDS_PTBDS6                    _PTBDS.Bits.PTBDS6
#define PTBDS_PTBDS7                    _PTBDS.Bits.PTBDS7

#define PTBDS_PTBDS0_MASK               1U
#define PTBDS_PTBDS1_MASK               2U
#define PTBDS_PTBDS2_MASK               4U
#define PTBDS_PTBDS3_MASK               8U
#define PTBDS_PTBDS4_MASK               16U
#define PTBDS_PTBDS5_MASK               32U
#define PTBDS_PTBDS6_MASK               64U
#define PTBDS_PTBDS7_MASK               128U


/*** PTCPE - Port C Pull Enable Register; 0x00001848 ***/
typedef union {
  byte Byte;
  struct {
    byte PTCPE0      :1;                                       /* Internal Pull Enable for Port C Bit 0 */
    byte PTCPE1      :1;                                       /* Internal Pull Enable for Port C Bit 1 */
    byte PTCPE2      :1;                                       /* Internal Pull Enable for Port C Bit 2 */
    byte PTCPE3      :1;                                       /* Internal Pull Enable for Port C Bit 3 */
    byte PTCPE4      :1;                                       /* Internal Pull Enable for Port C Bit 4 */
    byte PTCPE5      :1;                                       /* Internal Pull Enable for Port C Bit 5 */
    byte PTCPE6      :1;                                       /* Internal Pull Enable for Port C Bit 6 */
    byte PTCPE7      :1;                                       /* Internal Pull Enable for Port C Bit 7 */
  } Bits;
} PTCPESTR;
extern volatile PTCPESTR _PTCPE @0x00001848;
#define PTCPE                           _PTCPE.Byte
#define PTCPE_PTCPE0                    _PTCPE.Bits.PTCPE0
#define PTCPE_PTCPE1                    _PTCPE.Bits.PTCPE1
#define PTCPE_PTCPE2                    _PTCPE.Bits.PTCPE2
#define PTCPE_PTCPE3                    _PTCPE.Bits.PTCPE3
#define PTCPE_PTCPE4                    _PTCPE.Bits.PTCPE4
#define PTCPE_PTCPE5                    _PTCPE.Bits.PTCPE5
#define PTCPE_PTCPE6                    _PTCPE.Bits.PTCPE6
#define PTCPE_PTCPE7                    _PTCPE.Bits.PTCPE7

#define PTCPE_PTCPE0_MASK               1U
#define PTCPE_PTCPE1_MASK               2U
#define PTCPE_PTCPE2_MASK               4U
#define PTCPE_PTCPE3_MASK               8U
#define PTCPE_PTCPE4_MASK               16U
#define PTCPE_PTCPE5_MASK               32U
#define PTCPE_PTCPE6_MASK               64U
#define PTCPE_PTCPE7_MASK               128U


/*** PTCSE - Port C Slew Rate Enable Register; 0x00001849 ***/
typedef union {
  byte Byte;
  struct {
    byte PTCSE0      :1;                                       /* Output Slew Rate Enable for Port C Bit 0 */
    byte PTCSE1      :1;                                       /* Output Slew Rate Enable for Port C Bit 1 */
    byte PTCSE2      :1;                                       /* Output Slew Rate Enable for Port C Bit 2 */
    byte PTCSE3      :1;                                       /* Output Slew Rate Enable for Port C Bit 3 */
    byte PTCSE4      :1;                                       /* Output Slew Rate Enable for Port C Bit 4 */
    byte PTCSE5      :1;                                       /* Output Slew Rate Enable for Port C Bit 5 */
    byte PTCSE6      :1;                                       /* Output Slew Rate Enable for Port C Bit 6 */
    byte PTCSE7      :1;                                       /* Output Slew Rate Enable for Port C Bit 7 */
  } Bits;
} PTCSESTR;
extern volatile PTCSESTR _PTCSE @0x00001849;
#define PTCSE                           _PTCSE.Byte
#define PTCSE_PTCSE0                    _PTCSE.Bits.PTCSE0
#define PTCSE_PTCSE1                    _PTCSE.Bits.PTCSE1
#define PTCSE_PTCSE2                    _PTCSE.Bits.PTCSE2
#define PTCSE_PTCSE3                    _PTCSE.Bits.PTCSE3
#define PTCSE_PTCSE4                    _PTCSE.Bits.PTCSE4
#define PTCSE_PTCSE5                    _PTCSE.Bits.PTCSE5
#define PTCSE_PTCSE6                    _PTCSE.Bits.PTCSE6
#define PTCSE_PTCSE7                    _PTCSE.Bits.PTCSE7

#define PTCSE_PTCSE0_MASK               1U
#define PTCSE_PTCSE1_MASK               2U
#define PTCSE_PTCSE2_MASK               4U
#define PTCSE_PTCSE3_MASK               8U
#define PTCSE_PTCSE4_MASK               16U
#define PTCSE_PTCSE5_MASK               32U
#define PTCSE_PTCSE6_MASK               64U
#define PTCSE_PTCSE7_MASK               128U


/*** PTCDS - Port C Drive Strength Selection Register; 0x0000184A ***/
typedef union {
  byte Byte;
  struct {
    byte PTCDS0      :1;                                       /* Output Drive Strength Selection for Port C Bit 0 */
    byte PTCDS1      :1;                                       /* Output Drive Strength Selection for Port C Bit 1 */
    byte PTCDS2      :1;                                       /* Output Drive Strength Selection for Port C Bit 2 */
    byte PTCDS3      :1;                                       /* Output Drive Strength Selection for Port C Bit 3 */
    byte PTCDS4      :1;                                       /* Output Drive Strength Selection for Port C Bit 4 */
    byte PTCDS5      :1;                                       /* Output Drive Strength Selection for Port C Bit 5 */
    byte PTCDS6      :1;                                       /* Output Drive Strength Selection for Port C Bit 6 */
    byte PTCDS7      :1;                                       /* Output Drive Strength Selection for Port C Bit 7 */
  } Bits;
} PTCDSSTR;
extern volatile PTCDSSTR _PTCDS @0x0000184A;
#define PTCDS                           _PTCDS.Byte
#define PTCDS_PTCDS0                    _PTCDS.Bits.PTCDS0
#define PTCDS_PTCDS1                    _PTCDS.Bits.PTCDS1
#define PTCDS_PTCDS2                    _PTCDS.Bits.PTCDS2
#define PTCDS_PTCDS3                    _PTCDS.Bits.PTCDS3
#define PTCDS_PTCDS4                    _PTCDS.Bits.PTCDS4
#define PTCDS_PTCDS5                    _PTCDS.Bits.PTCDS5
#define PTCDS_PTCDS6                    _PTCDS.Bits.PTCDS6
#define PTCDS_PTCDS7                    _PTCDS.Bits.PTCDS7

#define PTCDS_PTCDS0_MASK               1U
#define PTCDS_PTCDS1_MASK               2U
#define PTCDS_PTCDS2_MASK               4U
#define PTCDS_PTCDS3_MASK               8U
#define PTCDS_PTCDS4_MASK               16U
#define PTCDS_PTCDS5_MASK               32U
#define PTCDS_PTCDS6_MASK               64U
#define PTCDS_PTCDS7_MASK               128U


/*** PTDPE - Port D Pull Enable Register; 0x0000184C ***/
typedef union {
  byte Byte;
  struct {
    byte PTDPE0      :1;                                       /* Internal Pull Enable for Port D Bit 0 */
    byte PTDPE1      :1;                                       /* Internal Pull Enable for Port D Bit 1 */
    byte PTDPE2      :1;                                       /* Internal Pull Enable for Port D Bit 2 */
    byte PTDPE3      :1;                                       /* Internal Pull Enable for Port D Bit 3 */
    byte PTDPE4      :1;                                       /* Internal Pull Enable for Port D Bit 4 */
    byte PTDPE5      :1;                                       /* Internal Pull Enable for Port D Bit 5 */
    byte PTDPE6      :1;                                       /* Internal Pull Enable for Port D Bit 6 */
    byte PTDPE7      :1;                                       /* Internal Pull Enable for Port D Bit 7 */
  } Bits;
} PTDPESTR;
extern volatile PTDPESTR _PTDPE @0x0000184C;
#define PTDPE                           _PTDPE.Byte
#define PTDPE_PTDPE0                    _PTDPE.Bits.PTDPE0
#define PTDPE_PTDPE1                    _PTDPE.Bits.PTDPE1
#define PTDPE_PTDPE2                    _PTDPE.Bits.PTDPE2
#define PTDPE_PTDPE3                    _PTDPE.Bits.PTDPE3
#define PTDPE_PTDPE4                    _PTDPE.Bits.PTDPE4
#define PTDPE_PTDPE5                    _PTDPE.Bits.PTDPE5
#define PTDPE_PTDPE6                    _PTDPE.Bits.PTDPE6
#define PTDPE_PTDPE7                    _PTDPE.Bits.PTDPE7

#define PTDPE_PTDPE0_MASK               1U
#define PTDPE_PTDPE1_MASK               2U
#define PTDPE_PTDPE2_MASK               4U
#define PTDPE_PTDPE3_MASK               8U
#define PTDPE_PTDPE4_MASK               16U
#define PTDPE_PTDPE5_MASK               32U
#define PTDPE_PTDPE6_MASK               64U
#define PTDPE_PTDPE7_MASK               128U


/*** PTDSE - Port D Slew Rate Enable Register; 0x0000184D ***/
typedef union {
  byte Byte;
  struct {
    byte PTDSE0      :1;                                       /* Output Slew Rate Enable for Port D Bit 0 */
    byte PTDSE1      :1;                                       /* Output Slew Rate Enable for Port D Bit 1 */
    byte PTDSE2      :1;                                       /* Output Slew Rate Enable for Port D Bit 2 */
    byte PTDSE3      :1;                                       /* Output Slew Rate Enable for Port D Bit 3 */
    byte PTDSE4      :1;                                       /* Output Slew Rate Enable for Port D Bit 4 */
    byte PTDSE5      :1;                                       /* Output Slew Rate Enable for Port D Bit 5 */
    byte PTDSE6      :1;                                       /* Output Slew Rate Enable for Port D Bit 6 */
    byte PTDSE7      :1;                                       /* Output Slew Rate Enable for Port D Bit 7 */
  } Bits;
} PTDSESTR;
extern volatile PTDSESTR _PTDSE @0x0000184D;
#define PTDSE                           _PTDSE.Byte
#define PTDSE_PTDSE0                    _PTDSE.Bits.PTDSE0
#define PTDSE_PTDSE1                    _PTDSE.Bits.PTDSE1
#define PTDSE_PTDSE2                    _PTDSE.Bits.PTDSE2
#define PTDSE_PTDSE3                    _PTDSE.Bits.PTDSE3
#define PTDSE_PTDSE4                    _PTDSE.Bits.PTDSE4
#define PTDSE_PTDSE5                    _PTDSE.Bits.PTDSE5
#define PTDSE_PTDSE6                    _PTDSE.Bits.PTDSE6
#define PTDSE_PTDSE7                    _PTDSE.Bits.PTDSE7

#define PTDSE_PTDSE0_MASK               1U
#define PTDSE_PTDSE1_MASK               2U
#define PTDSE_PTDSE2_MASK               4U
#define PTDSE_PTDSE3_MASK               8U
#define PTDSE_PTDSE4_MASK               16U
#define PTDSE_PTDSE5_MASK               32U
#define PTDSE_PTDSE6_MASK               64U
#define PTDSE_PTDSE7_MASK               128U


/*** PTDDS - Port D Drive Strength Selection Register; 0x0000184E ***/
typedef union {
  byte Byte;
  struct {
    byte PTDDS0      :1;                                       /* Output Drive Strength Selection for Port D Bit 0 */
    byte PTDDS1      :1;                                       /* Output Drive Strength Selection for Port D Bit 1 */
    byte PTDDS2      :1;                                       /* Output Drive Strength Selection for Port D Bit 2 */
    byte PTDDS3      :1;                                       /* Output Drive Strength Selection for Port D Bit 3 */
    byte PTDDS4      :1;                                       /* Output Drive Strength Selection for Port D Bit 4 */
    byte PTDDS5      :1;                                       /* Output Drive Strength Selection for Port D Bit 5 */
    byte PTDDS6      :1;                                       /* Output Drive Strength Selection for Port D Bit 6 */
    byte PTDDS7      :1;                                       /* Output Drive Strength Selection for Port D Bit 7 */
  } Bits;
} PTDDSSTR;
extern volatile PTDDSSTR _PTDDS @0x0000184E;
#define PTDDS                           _PTDDS.Byte
#define PTDDS_PTDDS0                    _PTDDS.Bits.PTDDS0
#define PTDDS_PTDDS1                    _PTDDS.Bits.PTDDS1
#define PTDDS_PTDDS2                    _PTDDS.Bits.PTDDS2
#define PTDDS_PTDDS3                    _PTDDS.Bits.PTDDS3
#define PTDDS_PTDDS4                    _PTDDS.Bits.PTDDS4
#define PTDDS_PTDDS5                    _PTDDS.Bits.PTDDS5
#define PTDDS_PTDDS6                    _PTDDS.Bits.PTDDS6
#define PTDDS_PTDDS7                    _PTDDS.Bits.PTDDS7

#define PTDDS_PTDDS0_MASK               1U
#define PTDDS_PTDDS1_MASK               2U
#define PTDDS_PTDDS2_MASK               4U
#define PTDDS_PTDDS3_MASK               8U
#define PTDDS_PTDDS4_MASK               16U
#define PTDDS_PTDDS5_MASK               32U
#define PTDDS_PTDDS6_MASK               64U
#define PTDDS_PTDDS7_MASK               128U


/*** PTEPE - Port E Pull Enable Register; 0x00001850 ***/
typedef union {
  byte Byte;
  struct {
    byte PTEPE0      :1;                                       /* Internal Pull Enable for Port E Bit 0 */
    byte PTEPE1      :1;                                       /* Internal Pull Enable for Port E Bit 1 */
    byte PTEPE2      :1;                                       /* Internal Pull Enable for Port E Bit 2 */
    byte PTEPE3      :1;                                       /* Internal Pull Enable for Port E Bit 3 */
    byte PTEPE4      :1;                                       /* Internal Pull Enable for Port E Bit 4 */
    byte PTEPE5      :1;                                       /* Internal Pull Enable for Port E Bit 5 */
    byte PTEPE6      :1;                                       /* Internal Pull Enable for Port E Bit 6 */
    byte             :1; 
  } Bits;
  struct {
    byte grpPTEPE :7;
    byte         :1;
  } MergedBits;
} PTEPESTR;
extern volatile PTEPESTR _PTEPE @0x00001850;
#define PTEPE                           _PTEPE.Byte
#define PTEPE_PTEPE0                    _PTEPE.Bits.PTEPE0
#define PTEPE_PTEPE1                    _PTEPE.Bits.PTEPE1
#define PTEPE_PTEPE2                    _PTEPE.Bits.PTEPE2
#define PTEPE_PTEPE3                    _PTEPE.Bits.PTEPE3
#define PTEPE_PTEPE4                    _PTEPE.Bits.PTEPE4
#define PTEPE_PTEPE5                    _PTEPE.Bits.PTEPE5
#define PTEPE_PTEPE6                    _PTEPE.Bits.PTEPE6
#define PTEPE_PTEPE                     _PTEPE.MergedBits.grpPTEPE

#define PTEPE_PTEPE0_MASK               1U
#define PTEPE_PTEPE1_MASK               2U
#define PTEPE_PTEPE2_MASK               4U
#define PTEPE_PTEPE3_MASK               8U
#define PTEPE_PTEPE4_MASK               16U
#define PTEPE_PTEPE5_MASK               32U
#define PTEPE_PTEPE6_MASK               64U
#define PTEPE_PTEPE_MASK                127U
#define PTEPE_PTEPE_BITNUM              0U


/*** PTESE - Port E Slew Rate Enable Register; 0x00001851 ***/
typedef union {
  byte Byte;
  struct {
    byte PTESE0      :1;                                       /* Output Slew Rate Enable for Port E Bit 0 */
    byte PTESE1      :1;                                       /* Output Slew Rate Enable for Port E Bit 1 */
    byte PTESE2      :1;                                       /* Output Slew Rate Enable for Port E Bit 2 */
    byte PTESE3      :1;                                       /* Output Slew Rate Enable for Port E Bit 3 */
    byte PTESE4      :1;                                       /* Output Slew Rate Enable for Port E Bit 4 */
    byte PTESE5      :1;                                       /* Output Slew Rate Enable for Port E Bit 5 */
    byte PTESE6      :1;                                       /* Output Slew Rate Enable for Port E Bit 6 */
    byte             :1; 
  } Bits;
  struct {
    byte grpPTESE :7;
    byte         :1;
  } MergedBits;
} PTESESTR;
extern volatile PTESESTR _PTESE @0x00001851;
#define PTESE                           _PTESE.Byte
#define PTESE_PTESE0                    _PTESE.Bits.PTESE0
#define PTESE_PTESE1                    _PTESE.Bits.PTESE1
#define PTESE_PTESE2                    _PTESE.Bits.PTESE2
#define PTESE_PTESE3                    _PTESE.Bits.PTESE3
#define PTESE_PTESE4                    _PTESE.Bits.PTESE4
#define PTESE_PTESE5                    _PTESE.Bits.PTESE5
#define PTESE_PTESE6                    _PTESE.Bits.PTESE6
#define PTESE_PTESE                     _PTESE.MergedBits.grpPTESE

#define PTESE_PTESE0_MASK               1U
#define PTESE_PTESE1_MASK               2U
#define PTESE_PTESE2_MASK               4U
#define PTESE_PTESE3_MASK               8U
#define PTESE_PTESE4_MASK               16U
#define PTESE_PTESE5_MASK               32U
#define PTESE_PTESE6_MASK               64U
#define PTESE_PTESE_MASK                127U
#define PTESE_PTESE_BITNUM              0U


/*** PTEDS - Port E Drive Strength Selection Register; 0x00001852 ***/
typedef union {
  byte Byte;
  struct {
    byte PTEDS0      :1;                                       /* Output Drive Strength Selection for Port E Bit 0 */
    byte PTEDS1      :1;                                       /* Output Drive Strength Selection for Port E Bit 1 */
    byte PTEDS2      :1;                                       /* Output Drive Strength Selection for Port E Bit 2 */
    byte PTEDS3      :1;                                       /* Output Drive Strength Selection for Port E Bit 3 */
    byte PTEDS4      :1;                                       /* Output Drive Strength Selection for Port E Bit 4 */
    byte PTEDS5      :1;                                       /* Output Drive Strength Selection for Port E Bit 5 */
    byte PTEDS6      :1;                                       /* Output Drive Strength Selection for Port E Bit 6 */
    byte             :1; 
  } Bits;
  struct {
    byte grpPTEDS :7;
    byte         :1;
  } MergedBits;
} PTEDSSTR;
extern volatile PTEDSSTR _PTEDS @0x00001852;
#define PTEDS                           _PTEDS.Byte
#define PTEDS_PTEDS0                    _PTEDS.Bits.PTEDS0
#define PTEDS_PTEDS1                    _PTEDS.Bits.PTEDS1
#define PTEDS_PTEDS2                    _PTEDS.Bits.PTEDS2
#define PTEDS_PTEDS3                    _PTEDS.Bits.PTEDS3
#define PTEDS_PTEDS4                    _PTEDS.Bits.PTEDS4
#define PTEDS_PTEDS5                    _PTEDS.Bits.PTEDS5
#define PTEDS_PTEDS6                    _PTEDS.Bits.PTEDS6
#define PTEDS_PTEDS                     _PTEDS.MergedBits.grpPTEDS

#define PTEDS_PTEDS0_MASK               1U
#define PTEDS_PTEDS1_MASK               2U
#define PTEDS_PTEDS2_MASK               4U
#define PTEDS_PTEDS3_MASK               8U
#define PTEDS_PTEDS4_MASK               16U
#define PTEDS_PTEDS5_MASK               32U
#define PTEDS_PTEDS6_MASK               64U
#define PTEDS_PTEDS_MASK                127U
#define PTEDS_PTEDS_BITNUM              0U


/*** PTFPE - Port F Pull Enable Register; 0x00001854 ***/
typedef union {
  byte Byte;
  struct {
    byte PTFPE0      :1;                                       /* Internal Pull Enable for Port F Bit 0 */
    byte PTFPE1      :1;                                       /* Internal Pull Enable for Port F Bit 1 */
    byte PTFPE2      :1;                                       /* Internal Pull Enable for Port F Bit 2 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTFPE :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTFPESTR;
extern volatile PTFPESTR _PTFPE @0x00001854;
#define PTFPE                           _PTFPE.Byte
#define PTFPE_PTFPE0                    _PTFPE.Bits.PTFPE0
#define PTFPE_PTFPE1                    _PTFPE.Bits.PTFPE1
#define PTFPE_PTFPE2                    _PTFPE.Bits.PTFPE2
#define PTFPE_PTFPE                     _PTFPE.MergedBits.grpPTFPE

#define PTFPE_PTFPE0_MASK               1U
#define PTFPE_PTFPE1_MASK               2U
#define PTFPE_PTFPE2_MASK               4U
#define PTFPE_PTFPE_MASK                7U
#define PTFPE_PTFPE_BITNUM              0U


/*** PTFSE - Port F Slew Rate Enable Register; 0x00001855 ***/
typedef union {
  byte Byte;
  struct {
    byte PTFSE0      :1;                                       /* Output Slew Rate Enable for Port F Bit 0 */
    byte PTFSE1      :1;                                       /* Output Slew Rate Enable for Port F Bit 1 */
    byte PTFSE2      :1;                                       /* Output Slew Rate Enable for Port F Bit 2 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTFSE :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTFSESTR;
extern volatile PTFSESTR _PTFSE @0x00001855;
#define PTFSE                           _PTFSE.Byte
#define PTFSE_PTFSE0                    _PTFSE.Bits.PTFSE0
#define PTFSE_PTFSE1                    _PTFSE.Bits.PTFSE1
#define PTFSE_PTFSE2                    _PTFSE.Bits.PTFSE2
#define PTFSE_PTFSE                     _PTFSE.MergedBits.grpPTFSE

#define PTFSE_PTFSE0_MASK               1U
#define PTFSE_PTFSE1_MASK               2U
#define PTFSE_PTFSE2_MASK               4U
#define PTFSE_PTFSE_MASK                7U
#define PTFSE_PTFSE_BITNUM              0U


/*** PTFDS - Port F Drive Strength Selection Register; 0x00001856 ***/
typedef union {
  byte Byte;
  struct {
    byte PTFDS0      :1;                                       /* Output Drive Strength Selection for Port F Bit 0 */
    byte PTFDS1      :1;                                       /* Output Drive Strength Selection for Port F Bit 1 */
    byte PTFDS2      :1;                                       /* Output Drive Strength Selection for Port F Bit 2 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTFDS :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTFDSSTR;
extern volatile PTFDSSTR _PTFDS @0x00001856;
#define PTFDS                           _PTFDS.Byte
#define PTFDS_PTFDS0                    _PTFDS.Bits.PTFDS0
#define PTFDS_PTFDS1                    _PTFDS.Bits.PTFDS1
#define PTFDS_PTFDS2                    _PTFDS.Bits.PTFDS2
#define PTFDS_PTFDS                     _PTFDS.MergedBits.grpPTFDS

#define PTFDS_PTFDS0_MASK               1U
#define PTFDS_PTFDS1_MASK               2U
#define PTFDS_PTFDS2_MASK               4U
#define PTFDS_PTFDS_MASK                7U
#define PTFDS_PTFDS_BITNUM              0U


/*** HSCMP1CR0 - HSCMP1 Control Register 0; 0x00001860 ***/
typedef union {
  byte Byte;
  struct {
    byte MMC0        :1;                                       /* Minus Input Mux Control, bit 0 */
    byte MMC1        :1;                                       /* Minus Input Mux Control, bit 1 */
    byte PMC0        :1;                                       /* Positive Input Mux Control, bit 0 */
    byte PMC1        :1;                                       /* Positive Input Mux Control, bit 1 */
    byte FILTER_CNT0 :1;                                       /* Filter Sample Count, bit 0 */
    byte FILTER_CNT1 :1;                                       /* Filter Sample Count, bit 1 */
    byte FILTER_CNT2 :1;                                       /* Filter Sample Count, bit 2 */
    byte             :1; 
  } Bits;
  struct {
    byte grpMMC  :2;
    byte grpPMC  :2;
    byte grpFILTER_CNT :3;
    byte         :1;
  } MergedBits;
} HSCMP1CR0STR;
extern volatile HSCMP1CR0STR _HSCMP1CR0 @0x00001860;
#define HSCMP1CR0                       _HSCMP1CR0.Byte
#define HSCMP1CR0_MMC0                  _HSCMP1CR0.Bits.MMC0
#define HSCMP1CR0_MMC1                  _HSCMP1CR0.Bits.MMC1
#define HSCMP1CR0_PMC0                  _HSCMP1CR0.Bits.PMC0
#define HSCMP1CR0_PMC1                  _HSCMP1CR0.Bits.PMC1
#define HSCMP1CR0_FILTER_CNT0           _HSCMP1CR0.Bits.FILTER_CNT0
#define HSCMP1CR0_FILTER_CNT1           _HSCMP1CR0.Bits.FILTER_CNT1
#define HSCMP1CR0_FILTER_CNT2           _HSCMP1CR0.Bits.FILTER_CNT2
/* HSCMP1CR_ARR: Access 2 HSCMP1CRx registers in an array */
#define HSCMP1CR_ARR                    ((volatile byte * __far) &HSCMP1CR0)
#define HSCMP1CR0_MMC                   _HSCMP1CR0.MergedBits.grpMMC
#define HSCMP1CR0_PMC                   _HSCMP1CR0.MergedBits.grpPMC
#define HSCMP1CR0_FILTER_CNT            _HSCMP1CR0.MergedBits.grpFILTER_CNT

#define HSCMP1CR0_MMC0_MASK             1U
#define HSCMP1CR0_MMC1_MASK             2U
#define HSCMP1CR0_PMC0_MASK             4U
#define HSCMP1CR0_PMC1_MASK             8U
#define HSCMP1CR0_FILTER_CNT0_MASK      16U
#define HSCMP1CR0_FILTER_CNT1_MASK      32U
#define HSCMP1CR0_FILTER_CNT2_MASK      64U
#define HSCMP1CR0_MMC_MASK              3U
#define HSCMP1CR0_MMC_BITNUM            0U
#define HSCMP1CR0_PMC_MASK              12U
#define HSCMP1CR0_PMC_BITNUM            2U
#define HSCMP1CR0_FILTER_CNT_MASK       112U
#define HSCMP1CR0_FILTER_CNT_BITNUM     4U


/*** HSCMP1CR1 - HSCMP1 Control Register 1; 0x00001861 ***/
typedef union {
  byte Byte;
  struct {
    byte EN          :1;                                       /* Comparator Module Enable */
    byte OPE         :1;                                       /* Comparator Output Pin Enable */
    byte COS         :1;                                       /* Comparator Output Select */
    byte INV         :1;                                       /* Comparator INVERT */
    byte PMODE       :1;                                       /* Power Mode Select */
    byte             :1; 
    byte WE          :1;                                       /* Windowing Enable */
    byte SE          :1;                                       /* Sample Enable */
  } Bits;
} HSCMP1CR1STR;
extern volatile HSCMP1CR1STR _HSCMP1CR1 @0x00001861;
#define HSCMP1CR1                       _HSCMP1CR1.Byte
#define HSCMP1CR1_EN                    _HSCMP1CR1.Bits.EN
#define HSCMP1CR1_OPE                   _HSCMP1CR1.Bits.OPE
#define HSCMP1CR1_COS                   _HSCMP1CR1.Bits.COS
#define HSCMP1CR1_INV                   _HSCMP1CR1.Bits.INV
#define HSCMP1CR1_PMODE                 _HSCMP1CR1.Bits.PMODE
#define HSCMP1CR1_WE                    _HSCMP1CR1.Bits.WE
#define HSCMP1CR1_SE                    _HSCMP1CR1.Bits.SE

#define HSCMP1CR1_EN_MASK               1U
#define HSCMP1CR1_OPE_MASK              2U
#define HSCMP1CR1_COS_MASK              4U
#define HSCMP1CR1_INV_MASK              8U
#define HSCMP1CR1_PMODE_MASK            16U
#define HSCMP1CR1_WE_MASK               64U
#define HSCMP1CR1_SE_MASK               128U


/*** HSCMP1FPR - HSCMP1 Filter Period Register; 0x00001862 ***/
typedef union {
  byte Byte;
  struct {
    byte FILT_PER0   :1;                                       /* Filter Period, bit 0 */
    byte FILT_PER1   :1;                                       /* Filter Period, bit 1 */
    byte FILT_PER2   :1;                                       /* Filter Period, bit 2 */
    byte FILT_PER3   :1;                                       /* Filter Period, bit 3 */
    byte FILT_PER4   :1;                                       /* Filter Period, bit 4 */
    byte FILT_PER5   :1;                                       /* Filter Period, bit 5 */
    byte FILT_PER6   :1;                                       /* Filter Period, bit 6 */
    byte FILT_PER7   :1;                                       /* Filter Period, bit 7 */
  } Bits;
} HSCMP1FPRSTR;
extern volatile HSCMP1FPRSTR _HSCMP1FPR @0x00001862;
#define HSCMP1FPR                       _HSCMP1FPR.Byte
#define HSCMP1FPR_FILT_PER0             _HSCMP1FPR.Bits.FILT_PER0
#define HSCMP1FPR_FILT_PER1             _HSCMP1FPR.Bits.FILT_PER1
#define HSCMP1FPR_FILT_PER2             _HSCMP1FPR.Bits.FILT_PER2
#define HSCMP1FPR_FILT_PER3             _HSCMP1FPR.Bits.FILT_PER3
#define HSCMP1FPR_FILT_PER4             _HSCMP1FPR.Bits.FILT_PER4
#define HSCMP1FPR_FILT_PER5             _HSCMP1FPR.Bits.FILT_PER5
#define HSCMP1FPR_FILT_PER6             _HSCMP1FPR.Bits.FILT_PER6
#define HSCMP1FPR_FILT_PER7             _HSCMP1FPR.Bits.FILT_PER7

#define HSCMP1FPR_FILT_PER0_MASK        1U
#define HSCMP1FPR_FILT_PER1_MASK        2U
#define HSCMP1FPR_FILT_PER2_MASK        4U
#define HSCMP1FPR_FILT_PER3_MASK        8U
#define HSCMP1FPR_FILT_PER4_MASK        16U
#define HSCMP1FPR_FILT_PER5_MASK        32U
#define HSCMP1FPR_FILT_PER6_MASK        64U
#define HSCMP1FPR_FILT_PER7_MASK        128U


/*** HSCMP1SCR - HSCMP1 Status & Control Register; 0x00001863 ***/
typedef union {
  byte Byte;
  struct {
    byte COUT        :1;                                       /* Analog Comparator Output */
    byte CFF         :1;                                       /* Analog Comparator Flag Falling */
    byte CFR         :1;                                       /* Analog Comparator Flag Rising */
    byte IEF         :1;                                       /* Comparator Interrupt Enable Falling */
    byte IER         :1;                                       /* Comparator Interrupt Enable Rising */
    byte SMLEB       :1;                                       /* Stop Mode Edge / Level Interrupt Control */
    byte             :1; 
    byte             :1; 
  } Bits;
} HSCMP1SCRSTR;
extern volatile HSCMP1SCRSTR _HSCMP1SCR @0x00001863;
#define HSCMP1SCR                       _HSCMP1SCR.Byte
#define HSCMP1SCR_COUT                  _HSCMP1SCR.Bits.COUT
#define HSCMP1SCR_CFF                   _HSCMP1SCR.Bits.CFF
#define HSCMP1SCR_CFR                   _HSCMP1SCR.Bits.CFR
#define HSCMP1SCR_IEF                   _HSCMP1SCR.Bits.IEF
#define HSCMP1SCR_IER                   _HSCMP1SCR.Bits.IER
#define HSCMP1SCR_SMLEB                 _HSCMP1SCR.Bits.SMLEB

#define HSCMP1SCR_COUT_MASK             1U
#define HSCMP1SCR_CFF_MASK              2U
#define HSCMP1SCR_CFR_MASK              4U
#define HSCMP1SCR_IEF_MASK              8U
#define HSCMP1SCR_IER_MASK              16U
#define HSCMP1SCR_SMLEB_MASK            32U


/*** HSCMP1PCR - Pin Control Register; 0x00001864 ***/
typedef union {
  byte Byte;
  struct {
    byte INMPE1      :1;                                       /* Minus Input Pin 1 Enable */
    byte INMPE2      :1;                                       /* Minus Input Pin 2 Enable */
    byte INMPE3      :1;                                       /* Minus Input Pin 3 Enable */
    byte INMPE4      :1;                                       /* Minus Input Pin 4 Enable */
    byte INPPE1      :1;                                       /* Positive Input Pin 1 Enable */
    byte INPPE2      :1;                                       /* Positive Input Pin 2 Enable */
    byte INPPE3      :1;                                       /* Positive Input Pin 3 Enable */
    byte INPPE4      :1;                                       /* Positive Input Pin 4 Enable */
  } Bits;
  struct {
    byte grpINMPE_1 :4;
    byte grpINPPE_1 :4;
  } MergedBits;
} HSCMP1PCRSTR;
extern volatile HSCMP1PCRSTR _HSCMP1PCR @0x00001864;
#define HSCMP1PCR                       _HSCMP1PCR.Byte
#define HSCMP1PCR_INMPE1                _HSCMP1PCR.Bits.INMPE1
#define HSCMP1PCR_INMPE2                _HSCMP1PCR.Bits.INMPE2
#define HSCMP1PCR_INMPE3                _HSCMP1PCR.Bits.INMPE3
#define HSCMP1PCR_INMPE4                _HSCMP1PCR.Bits.INMPE4
#define HSCMP1PCR_INPPE1                _HSCMP1PCR.Bits.INPPE1
#define HSCMP1PCR_INPPE2                _HSCMP1PCR.Bits.INPPE2
#define HSCMP1PCR_INPPE3                _HSCMP1PCR.Bits.INPPE3
#define HSCMP1PCR_INPPE4                _HSCMP1PCR.Bits.INPPE4
#define HSCMP1PCR_INMPE_1               _HSCMP1PCR.MergedBits.grpINMPE_1
#define HSCMP1PCR_INPPE_1               _HSCMP1PCR.MergedBits.grpINPPE_1
#define HSCMP1PCR_INMPE                 HSCMP1PCR_INMPE_1
#define HSCMP1PCR_INPPE                 HSCMP1PCR_INPPE_1

#define HSCMP1PCR_INMPE1_MASK           1U
#define HSCMP1PCR_INMPE2_MASK           2U
#define HSCMP1PCR_INMPE3_MASK           4U
#define HSCMP1PCR_INMPE4_MASK           8U
#define HSCMP1PCR_INPPE1_MASK           16U
#define HSCMP1PCR_INPPE2_MASK           32U
#define HSCMP1PCR_INPPE3_MASK           64U
#define HSCMP1PCR_INPPE4_MASK           128U
#define HSCMP1PCR_INMPE_1_MASK          15U
#define HSCMP1PCR_INMPE_1_BITNUM        0U
#define HSCMP1PCR_INPPE_1_MASK          240U
#define HSCMP1PCR_INPPE_1_BITNUM        4U


/*** HSCMP2CR0 - HSCMP2 Control Register 0; 0x00001868 ***/
typedef union {
  byte Byte;
  struct {
    byte MMC0        :1;                                       /* Minus Input Mux Control, bit 0 */
    byte MMC1        :1;                                       /* Minus Input Mux Control, bit 1 */
    byte PMC0        :1;                                       /* Positive Input Mux Control, bit 0 */
    byte PMC1        :1;                                       /* Positive Input Mux Control, bit 1 */
    byte FILTER_CNT0 :1;                                       /* Filter Sample Count, bit 0 */
    byte FILTER_CNT1 :1;                                       /* Filter Sample Count, bit 1 */
    byte FILTER_CNT2 :1;                                       /* Filter Sample Count, bit 2 */
    byte             :1; 
  } Bits;
  struct {
    byte grpMMC  :2;
    byte grpPMC  :2;
    byte grpFILTER_CNT :3;
    byte         :1;
  } MergedBits;
} HSCMP2CR0STR;
extern volatile HSCMP2CR0STR _HSCMP2CR0 @0x00001868;
#define HSCMP2CR0                       _HSCMP2CR0.Byte
#define HSCMP2CR0_MMC0                  _HSCMP2CR0.Bits.MMC0
#define HSCMP2CR0_MMC1                  _HSCMP2CR0.Bits.MMC1
#define HSCMP2CR0_PMC0                  _HSCMP2CR0.Bits.PMC0
#define HSCMP2CR0_PMC1                  _HSCMP2CR0.Bits.PMC1
#define HSCMP2CR0_FILTER_CNT0           _HSCMP2CR0.Bits.FILTER_CNT0
#define HSCMP2CR0_FILTER_CNT1           _HSCMP2CR0.Bits.FILTER_CNT1
#define HSCMP2CR0_FILTER_CNT2           _HSCMP2CR0.Bits.FILTER_CNT2
/* HSCMP2CR_ARR: Access 2 HSCMP2CRx registers in an array */
#define HSCMP2CR_ARR                    ((volatile byte * __far) &HSCMP2CR0)
#define HSCMP2CR0_MMC                   _HSCMP2CR0.MergedBits.grpMMC
#define HSCMP2CR0_PMC                   _HSCMP2CR0.MergedBits.grpPMC
#define HSCMP2CR0_FILTER_CNT            _HSCMP2CR0.MergedBits.grpFILTER_CNT

#define HSCMP2CR0_MMC0_MASK             1U
#define HSCMP2CR0_MMC1_MASK             2U
#define HSCMP2CR0_PMC0_MASK             4U
#define HSCMP2CR0_PMC1_MASK             8U
#define HSCMP2CR0_FILTER_CNT0_MASK      16U
#define HSCMP2CR0_FILTER_CNT1_MASK      32U
#define HSCMP2CR0_FILTER_CNT2_MASK      64U
#define HSCMP2CR0_MMC_MASK              3U
#define HSCMP2CR0_MMC_BITNUM            0U
#define HSCMP2CR0_PMC_MASK              12U
#define HSCMP2CR0_PMC_BITNUM            2U
#define HSCMP2CR0_FILTER_CNT_MASK       112U
#define HSCMP2CR0_FILTER_CNT_BITNUM     4U


/*** HSCMP2CR1 - HSCMP2 Control Register 1; 0x00001869 ***/
typedef union {
  byte Byte;
  struct {
    byte EN          :1;                                       /* Comparator Module Enable */
    byte OPE         :1;                                       /* Comparator Output Pin Enable */
    byte COS         :1;                                       /* Comparator Output Select */
    byte INV         :1;                                       /* Comparator INVERT */
    byte PMODE       :1;                                       /* Power Mode Select */
    byte             :1; 
    byte WE          :1;                                       /* Windowing Enable */
    byte SE          :1;                                       /* Sample Enable */
  } Bits;
} HSCMP2CR1STR;
extern volatile HSCMP2CR1STR _HSCMP2CR1 @0x00001869;
#define HSCMP2CR1                       _HSCMP2CR1.Byte
#define HSCMP2CR1_EN                    _HSCMP2CR1.Bits.EN
#define HSCMP2CR1_OPE                   _HSCMP2CR1.Bits.OPE
#define HSCMP2CR1_COS                   _HSCMP2CR1.Bits.COS
#define HSCMP2CR1_INV                   _HSCMP2CR1.Bits.INV
#define HSCMP2CR1_PMODE                 _HSCMP2CR1.Bits.PMODE
#define HSCMP2CR1_WE                    _HSCMP2CR1.Bits.WE
#define HSCMP2CR1_SE                    _HSCMP2CR1.Bits.SE

#define HSCMP2CR1_EN_MASK               1U
#define HSCMP2CR1_OPE_MASK              2U
#define HSCMP2CR1_COS_MASK              4U
#define HSCMP2CR1_INV_MASK              8U
#define HSCMP2CR1_PMODE_MASK            16U
#define HSCMP2CR1_WE_MASK               64U
#define HSCMP2CR1_SE_MASK               128U


/*** HSCMP2FPR - HSCMP2 Filter Period Register; 0x0000186A ***/
typedef union {
  byte Byte;
  struct {
    byte FILT_PER0   :1;                                       /* Filter Period, bit 0 */
    byte FILT_PER1   :1;                                       /* Filter Period, bit 1 */
    byte FILT_PER2   :1;                                       /* Filter Period, bit 2 */
    byte FILT_PER3   :1;                                       /* Filter Period, bit 3 */
    byte FILT_PER4   :1;                                       /* Filter Period, bit 4 */
    byte FILT_PER5   :1;                                       /* Filter Period, bit 5 */
    byte FILT_PER6   :1;                                       /* Filter Period, bit 6 */
    byte FILT_PER7   :1;                                       /* Filter Period, bit 7 */
  } Bits;
} HSCMP2FPRSTR;
extern volatile HSCMP2FPRSTR _HSCMP2FPR @0x0000186A;
#define HSCMP2FPR                       _HSCMP2FPR.Byte
#define HSCMP2FPR_FILT_PER0             _HSCMP2FPR.Bits.FILT_PER0
#define HSCMP2FPR_FILT_PER1             _HSCMP2FPR.Bits.FILT_PER1
#define HSCMP2FPR_FILT_PER2             _HSCMP2FPR.Bits.FILT_PER2
#define HSCMP2FPR_FILT_PER3             _HSCMP2FPR.Bits.FILT_PER3
#define HSCMP2FPR_FILT_PER4             _HSCMP2FPR.Bits.FILT_PER4
#define HSCMP2FPR_FILT_PER5             _HSCMP2FPR.Bits.FILT_PER5
#define HSCMP2FPR_FILT_PER6             _HSCMP2FPR.Bits.FILT_PER6
#define HSCMP2FPR_FILT_PER7             _HSCMP2FPR.Bits.FILT_PER7

#define HSCMP2FPR_FILT_PER0_MASK        1U
#define HSCMP2FPR_FILT_PER1_MASK        2U
#define HSCMP2FPR_FILT_PER2_MASK        4U
#define HSCMP2FPR_FILT_PER3_MASK        8U
#define HSCMP2FPR_FILT_PER4_MASK        16U
#define HSCMP2FPR_FILT_PER5_MASK        32U
#define HSCMP2FPR_FILT_PER6_MASK        64U
#define HSCMP2FPR_FILT_PER7_MASK        128U


/*** HSCMP2SCR - HSCMP2 Status & Control Register; 0x0000186B ***/
typedef union {
  byte Byte;
  struct {
    byte COUT        :1;                                       /* Analog Comparator Output */
    byte CFF         :1;                                       /* Analog Comparator Flag Falling */
    byte CFR         :1;                                       /* Analog Comparator Flag Rising */
    byte IEF         :1;                                       /* Comparator Interrupt Enable Falling */
    byte IER         :1;                                       /* Comparator Interrupt Enable Rising */
    byte SMLEB       :1;                                       /* Stop Mode Edge / Level Interrupt Control */
    byte             :1; 
    byte             :1; 
  } Bits;
} HSCMP2SCRSTR;
extern volatile HSCMP2SCRSTR _HSCMP2SCR @0x0000186B;
#define HSCMP2SCR                       _HSCMP2SCR.Byte
#define HSCMP2SCR_COUT                  _HSCMP2SCR.Bits.COUT
#define HSCMP2SCR_CFF                   _HSCMP2SCR.Bits.CFF
#define HSCMP2SCR_CFR                   _HSCMP2SCR.Bits.CFR
#define HSCMP2SCR_IEF                   _HSCMP2SCR.Bits.IEF
#define HSCMP2SCR_IER                   _HSCMP2SCR.Bits.IER
#define HSCMP2SCR_SMLEB                 _HSCMP2SCR.Bits.SMLEB

#define HSCMP2SCR_COUT_MASK             1U
#define HSCMP2SCR_CFF_MASK              2U
#define HSCMP2SCR_CFR_MASK              4U
#define HSCMP2SCR_IEF_MASK              8U
#define HSCMP2SCR_IER_MASK              16U
#define HSCMP2SCR_SMLEB_MASK            32U


/*** HSCMP2PCR - Pin Control Register; 0x0000186C ***/
typedef union {
  byte Byte;
  struct {
    byte INMPE1      :1;                                       /* Minus Input Pin 1 Enable */
    byte INMPE2      :1;                                       /* Minus Input Pin 2 Enable */
    byte INMPE3      :1;                                       /* Minus Input Pin 3 Enable */
    byte INMPE4      :1;                                       /* Minus Input Pin 4 Enable */
    byte INPPE1      :1;                                       /* Positive Input Pin 1 Enable */
    byte INPPE2      :1;                                       /* Positive Input Pin 2 Enable */
    byte INPPE3      :1;                                       /* Positive Input Pin 3 Enable */
    byte INPPE4      :1;                                       /* Positive Input Pin 4 Enable */
  } Bits;
  struct {
    byte grpINMPE_1 :4;
    byte grpINPPE_1 :4;
  } MergedBits;
} HSCMP2PCRSTR;
extern volatile HSCMP2PCRSTR _HSCMP2PCR @0x0000186C;
#define HSCMP2PCR                       _HSCMP2PCR.Byte
#define HSCMP2PCR_INMPE1                _HSCMP2PCR.Bits.INMPE1
#define HSCMP2PCR_INMPE2                _HSCMP2PCR.Bits.INMPE2
#define HSCMP2PCR_INMPE3                _HSCMP2PCR.Bits.INMPE3
#define HSCMP2PCR_INMPE4                _HSCMP2PCR.Bits.INMPE4
#define HSCMP2PCR_INPPE1                _HSCMP2PCR.Bits.INPPE1
#define HSCMP2PCR_INPPE2                _HSCMP2PCR.Bits.INPPE2
#define HSCMP2PCR_INPPE3                _HSCMP2PCR.Bits.INPPE3
#define HSCMP2PCR_INPPE4                _HSCMP2PCR.Bits.INPPE4
#define HSCMP2PCR_INMPE_1               _HSCMP2PCR.MergedBits.grpINMPE_1
#define HSCMP2PCR_INPPE_1               _HSCMP2PCR.MergedBits.grpINPPE_1
#define HSCMP2PCR_INMPE                 HSCMP2PCR_INMPE_1
#define HSCMP2PCR_INPPE                 HSCMP2PCR_INPPE_1

#define HSCMP2PCR_INMPE1_MASK           1U
#define HSCMP2PCR_INMPE2_MASK           2U
#define HSCMP2PCR_INMPE3_MASK           4U
#define HSCMP2PCR_INMPE4_MASK           8U
#define HSCMP2PCR_INPPE1_MASK           16U
#define HSCMP2PCR_INPPE2_MASK           32U
#define HSCMP2PCR_INPPE3_MASK           64U
#define HSCMP2PCR_INPPE4_MASK           128U
#define HSCMP2PCR_INMPE_1_MASK          15U
#define HSCMP2PCR_INMPE_1_BITNUM        0U
#define HSCMP2PCR_INPPE_1_MASK          240U
#define HSCMP2PCR_INPPE_1_BITNUM        4U


/*** HSCMP3CR0 - HSCMP3 Control Register 0; 0x00001870 ***/
typedef union {
  byte Byte;
  struct {
    byte MMC0        :1;                                       /* Minus Input Mux Control, bit 0 */
    byte MMC1        :1;                                       /* Minus Input Mux Control, bit 1 */
    byte PMC0        :1;                                       /* Positive Input Mux Control, bit 0 */
    byte PMC1        :1;                                       /* Positive Input Mux Control, bit 1 */
    byte FILTER_CNT0 :1;                                       /* Filter Sample Count, bit 0 */
    byte FILTER_CNT1 :1;                                       /* Filter Sample Count, bit 1 */
    byte FILTER_CNT2 :1;                                       /* Filter Sample Count, bit 2 */
    byte             :1; 
  } Bits;
  struct {
    byte grpMMC  :2;
    byte grpPMC  :2;
    byte grpFILTER_CNT :3;
    byte         :1;
  } MergedBits;
} HSCMP3CR0STR;
extern volatile HSCMP3CR0STR _HSCMP3CR0 @0x00001870;
#define HSCMP3CR0                       _HSCMP3CR0.Byte
#define HSCMP3CR0_MMC0                  _HSCMP3CR0.Bits.MMC0
#define HSCMP3CR0_MMC1                  _HSCMP3CR0.Bits.MMC1
#define HSCMP3CR0_PMC0                  _HSCMP3CR0.Bits.PMC0
#define HSCMP3CR0_PMC1                  _HSCMP3CR0.Bits.PMC1
#define HSCMP3CR0_FILTER_CNT0           _HSCMP3CR0.Bits.FILTER_CNT0
#define HSCMP3CR0_FILTER_CNT1           _HSCMP3CR0.Bits.FILTER_CNT1
#define HSCMP3CR0_FILTER_CNT2           _HSCMP3CR0.Bits.FILTER_CNT2
/* HSCMP3CR_ARR: Access 2 HSCMP3CRx registers in an array */
#define HSCMP3CR_ARR                    ((volatile byte * __far) &HSCMP3CR0)
#define HSCMP3CR0_MMC                   _HSCMP3CR0.MergedBits.grpMMC
#define HSCMP3CR0_PMC                   _HSCMP3CR0.MergedBits.grpPMC
#define HSCMP3CR0_FILTER_CNT            _HSCMP3CR0.MergedBits.grpFILTER_CNT

#define HSCMP3CR0_MMC0_MASK             1U
#define HSCMP3CR0_MMC1_MASK             2U
#define HSCMP3CR0_PMC0_MASK             4U
#define HSCMP3CR0_PMC1_MASK             8U
#define HSCMP3CR0_FILTER_CNT0_MASK      16U
#define HSCMP3CR0_FILTER_CNT1_MASK      32U
#define HSCMP3CR0_FILTER_CNT2_MASK      64U
#define HSCMP3CR0_MMC_MASK              3U
#define HSCMP3CR0_MMC_BITNUM            0U
#define HSCMP3CR0_PMC_MASK              12U
#define HSCMP3CR0_PMC_BITNUM            2U
#define HSCMP3CR0_FILTER_CNT_MASK       112U
#define HSCMP3CR0_FILTER_CNT_BITNUM     4U


/*** HSCMP3CR1 - HSCMP3 Control Register 1; 0x00001871 ***/
typedef union {
  byte Byte;
  struct {
    byte EN          :1;                                       /* Comparator Module Enable */
    byte OPE         :1;                                       /* Comparator Output Pin Enable */
    byte COS         :1;                                       /* Comparator Output Select */
    byte INV         :1;                                       /* Comparator INVERT */
    byte PMODE       :1;                                       /* Power Mode Select */
    byte             :1; 
    byte WE          :1;                                       /* Windowing Enable */
    byte SE          :1;                                       /* Sample Enable */
  } Bits;
} HSCMP3CR1STR;
extern volatile HSCMP3CR1STR _HSCMP3CR1 @0x00001871;
#define HSCMP3CR1                       _HSCMP3CR1.Byte
#define HSCMP3CR1_EN                    _HSCMP3CR1.Bits.EN
#define HSCMP3CR1_OPE                   _HSCMP3CR1.Bits.OPE
#define HSCMP3CR1_COS                   _HSCMP3CR1.Bits.COS
#define HSCMP3CR1_INV                   _HSCMP3CR1.Bits.INV
#define HSCMP3CR1_PMODE                 _HSCMP3CR1.Bits.PMODE
#define HSCMP3CR1_WE                    _HSCMP3CR1.Bits.WE
#define HSCMP3CR1_SE                    _HSCMP3CR1.Bits.SE

#define HSCMP3CR1_EN_MASK               1U
#define HSCMP3CR1_OPE_MASK              2U
#define HSCMP3CR1_COS_MASK              4U
#define HSCMP3CR1_INV_MASK              8U
#define HSCMP3CR1_PMODE_MASK            16U
#define HSCMP3CR1_WE_MASK               64U
#define HSCMP3CR1_SE_MASK               128U


/*** HSCMP3FPR - HSCMP3 Filter Period Register; 0x00001872 ***/
typedef union {
  byte Byte;
  struct {
    byte FILT_PER0   :1;                                       /* Filter Period, bit 0 */
    byte FILT_PER1   :1;                                       /* Filter Period, bit 1 */
    byte FILT_PER2   :1;                                       /* Filter Period, bit 2 */
    byte FILT_PER3   :1;                                       /* Filter Period, bit 3 */
    byte FILT_PER4   :1;                                       /* Filter Period, bit 4 */
    byte FILT_PER5   :1;                                       /* Filter Period, bit 5 */
    byte FILT_PER6   :1;                                       /* Filter Period, bit 6 */
    byte FILT_PER7   :1;                                       /* Filter Period, bit 7 */
  } Bits;
} HSCMP3FPRSTR;
extern volatile HSCMP3FPRSTR _HSCMP3FPR @0x00001872;
#define HSCMP3FPR                       _HSCMP3FPR.Byte
#define HSCMP3FPR_FILT_PER0             _HSCMP3FPR.Bits.FILT_PER0
#define HSCMP3FPR_FILT_PER1             _HSCMP3FPR.Bits.FILT_PER1
#define HSCMP3FPR_FILT_PER2             _HSCMP3FPR.Bits.FILT_PER2
#define HSCMP3FPR_FILT_PER3             _HSCMP3FPR.Bits.FILT_PER3
#define HSCMP3FPR_FILT_PER4             _HSCMP3FPR.Bits.FILT_PER4
#define HSCMP3FPR_FILT_PER5             _HSCMP3FPR.Bits.FILT_PER5
#define HSCMP3FPR_FILT_PER6             _HSCMP3FPR.Bits.FILT_PER6
#define HSCMP3FPR_FILT_PER7             _HSCMP3FPR.Bits.FILT_PER7

#define HSCMP3FPR_FILT_PER0_MASK        1U
#define HSCMP3FPR_FILT_PER1_MASK        2U
#define HSCMP3FPR_FILT_PER2_MASK        4U
#define HSCMP3FPR_FILT_PER3_MASK        8U
#define HSCMP3FPR_FILT_PER4_MASK        16U
#define HSCMP3FPR_FILT_PER5_MASK        32U
#define HSCMP3FPR_FILT_PER6_MASK        64U
#define HSCMP3FPR_FILT_PER7_MASK        128U


/*** HSCMP3SCR - HSCMP3 Status & Control Register; 0x00001873 ***/
typedef union {
  byte Byte;
  struct {
    byte COUT        :1;                                       /* Analog Comparator Output */
    byte CFF         :1;                                       /* Analog Comparator Flag Falling */
    byte CFR         :1;                                       /* Analog Comparator Flag Rising */
    byte IEF         :1;                                       /* Comparator Interrupt Enable Falling */
    byte IER         :1;                                       /* Comparator Interrupt Enable Rising */
    byte SMLEB       :1;                                       /* Stop Mode Edge / Level Interrupt Control */
    byte             :1; 
    byte             :1; 
  } Bits;
} HSCMP3SCRSTR;
extern volatile HSCMP3SCRSTR _HSCMP3SCR @0x00001873;
#define HSCMP3SCR                       _HSCMP3SCR.Byte
#define HSCMP3SCR_COUT                  _HSCMP3SCR.Bits.COUT
#define HSCMP3SCR_CFF                   _HSCMP3SCR.Bits.CFF
#define HSCMP3SCR_CFR                   _HSCMP3SCR.Bits.CFR
#define HSCMP3SCR_IEF                   _HSCMP3SCR.Bits.IEF
#define HSCMP3SCR_IER                   _HSCMP3SCR.Bits.IER
#define HSCMP3SCR_SMLEB                 _HSCMP3SCR.Bits.SMLEB

#define HSCMP3SCR_COUT_MASK             1U
#define HSCMP3SCR_CFF_MASK              2U
#define HSCMP3SCR_CFR_MASK              4U
#define HSCMP3SCR_IEF_MASK              8U
#define HSCMP3SCR_IER_MASK              16U
#define HSCMP3SCR_SMLEB_MASK            32U


/*** HSCMP3PCR - Pin Control Register; 0x00001874 ***/
typedef union {
  byte Byte;
  struct {
    byte INMPE1      :1;                                       /* Minus Input Pin 1 Enable */
    byte INMPE2      :1;                                       /* Minus Input Pin 2 Enable */
    byte INMPE3      :1;                                       /* Minus Input Pin 3 Enable */
    byte INMPE4      :1;                                       /* Minus Input Pin 4 Enable */
    byte INPPE1      :1;                                       /* Positive Input Pin 1 Enable */
    byte INPPE2      :1;                                       /* Positive Input Pin 2 Enable */
    byte INPPE3      :1;                                       /* Positive Input Pin 3 Enable */
    byte INPPE4      :1;                                       /* Positive Input Pin 4 Enable */
  } Bits;
  struct {
    byte grpINMPE_1 :4;
    byte grpINPPE_1 :4;
  } MergedBits;
} HSCMP3PCRSTR;
extern volatile HSCMP3PCRSTR _HSCMP3PCR @0x00001874;
#define HSCMP3PCR                       _HSCMP3PCR.Byte
#define HSCMP3PCR_INMPE1                _HSCMP3PCR.Bits.INMPE1
#define HSCMP3PCR_INMPE2                _HSCMP3PCR.Bits.INMPE2
#define HSCMP3PCR_INMPE3                _HSCMP3PCR.Bits.INMPE3
#define HSCMP3PCR_INMPE4                _HSCMP3PCR.Bits.INMPE4
#define HSCMP3PCR_INPPE1                _HSCMP3PCR.Bits.INPPE1
#define HSCMP3PCR_INPPE2                _HSCMP3PCR.Bits.INPPE2
#define HSCMP3PCR_INPPE3                _HSCMP3PCR.Bits.INPPE3
#define HSCMP3PCR_INPPE4                _HSCMP3PCR.Bits.INPPE4
#define HSCMP3PCR_INMPE_1               _HSCMP3PCR.MergedBits.grpINMPE_1
#define HSCMP3PCR_INPPE_1               _HSCMP3PCR.MergedBits.grpINPPE_1
#define HSCMP3PCR_INMPE                 HSCMP3PCR_INMPE_1
#define HSCMP3PCR_INPPE                 HSCMP3PCR_INPPE_1

#define HSCMP3PCR_INMPE1_MASK           1U
#define HSCMP3PCR_INMPE2_MASK           2U
#define HSCMP3PCR_INMPE3_MASK           4U
#define HSCMP3PCR_INMPE4_MASK           8U
#define HSCMP3PCR_INPPE1_MASK           16U
#define HSCMP3PCR_INPPE2_MASK           32U
#define HSCMP3PCR_INPPE3_MASK           64U
#define HSCMP3PCR_INPPE4_MASK           128U
#define HSCMP3PCR_INMPE_1_MASK          15U
#define HSCMP3PCR_INMPE_1_BITNUM        0U
#define HSCMP3PCR_INPPE_1_MASK          240U
#define HSCMP3PCR_INPPE_1_BITNUM        4U


/*** PGACNTL0 - PGA Control Register 0; 0x00001878 ***/
typedef union {
  byte Byte;
  struct {
    byte EN          :1;                                       /* Module Enable */
    byte LP          :1;                                       /* Power Mode */
    byte GAINSEL0    :1;                                       /* Gain Select, bit 0 */
    byte GAINSEL1    :1;                                       /* Gain Select, bit 1 */
    byte GAINSEL2    :1;                                       /* Gain Select, bit 2 */
    byte GAINSEL3    :1;                                       /* Gain Select, bit 3 */
    byte GAINSEL4    :1;                                       /* Gain Select, bit 4 */
    byte TM          :1;                                       /* Trigger Mode */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpGAINSEL :5;
    byte         :1;
  } MergedBits;
} PGACNTL0STR;
extern volatile PGACNTL0STR _PGACNTL0 @0x00001878;
#define PGACNTL0                        _PGACNTL0.Byte
#define PGACNTL0_EN                     _PGACNTL0.Bits.EN
#define PGACNTL0_LP                     _PGACNTL0.Bits.LP
#define PGACNTL0_GAINSEL0               _PGACNTL0.Bits.GAINSEL0
#define PGACNTL0_GAINSEL1               _PGACNTL0.Bits.GAINSEL1
#define PGACNTL0_GAINSEL2               _PGACNTL0.Bits.GAINSEL2
#define PGACNTL0_GAINSEL3               _PGACNTL0.Bits.GAINSEL3
#define PGACNTL0_GAINSEL4               _PGACNTL0.Bits.GAINSEL4
#define PGACNTL0_TM                     _PGACNTL0.Bits.TM
/* PGACNTL_ARR: Access 3 PGACNTLx registers in an array */
#define PGACNTL_ARR                     ((volatile byte * __far) &PGACNTL0)
#define PGACNTL0_GAINSEL                _PGACNTL0.MergedBits.grpGAINSEL

#define PGACNTL0_EN_MASK                1U
#define PGACNTL0_LP_MASK                2U
#define PGACNTL0_GAINSEL0_MASK          4U
#define PGACNTL0_GAINSEL1_MASK          8U
#define PGACNTL0_GAINSEL2_MASK          16U
#define PGACNTL0_GAINSEL3_MASK          32U
#define PGACNTL0_GAINSEL4_MASK          64U
#define PGACNTL0_TM_MASK                128U
#define PGACNTL0_GAINSEL_MASK           124U
#define PGACNTL0_GAINSEL_BITNUM         2U


/*** PGACNTL1 - PGA Control Register 1; 0x00001879 ***/
typedef union {
  byte Byte;
  struct {
    byte CPD0        :1;                                       /* Charge Pump Divisor, bit 0 */
    byte CPD1        :1;                                       /* Charge Pump Divisor, bit 1 */
    byte CPD2        :1;                                       /* Charge Pump Divisor, bit 2 */
    byte CALMODE0    :1;                                       /* Calibration Mode, bit 0 */
    byte CALMODE1    :1;                                       /* Calibration Mode, bit 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpCPD  :3;
    byte grpCALMODE :2;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PGACNTL1STR;
extern volatile PGACNTL1STR _PGACNTL1 @0x00001879;
#define PGACNTL1                        _PGACNTL1.Byte
#define PGACNTL1_CPD0                   _PGACNTL1.Bits.CPD0
#define PGACNTL1_CPD1                   _PGACNTL1.Bits.CPD1
#define PGACNTL1_CPD2                   _PGACNTL1.Bits.CPD2
#define PGACNTL1_CALMODE0               _PGACNTL1.Bits.CALMODE0
#define PGACNTL1_CALMODE1               _PGACNTL1.Bits.CALMODE1
#define PGACNTL1_CPD                    _PGACNTL1.MergedBits.grpCPD
#define PGACNTL1_CALMODE                _PGACNTL1.MergedBits.grpCALMODE

#define PGACNTL1_CPD0_MASK              1U
#define PGACNTL1_CPD1_MASK              2U
#define PGACNTL1_CPD2_MASK              4U
#define PGACNTL1_CALMODE0_MASK          8U
#define PGACNTL1_CALMODE1_MASK          16U
#define PGACNTL1_CPD_MASK               7U
#define PGACNTL1_CPD_BITNUM             0U
#define PGACNTL1_CALMODE_MASK           24U
#define PGACNTL1_CALMODE_BITNUM         3U


/*** PGACNTL2 - PGA Control Register 2; 0x0000187A ***/
typedef union {
  byte Byte;
  struct {
    byte ADIV0       :1;                                       /* Clock Divide Select, bit 0 */
    byte ADIV1       :1;                                       /* Clock Divide Select, bit 1 */
    byte NUM_CLK_GS0 :1;                                       /* Number of clk_gs pulses per conversion, bit 0 */
    byte NUM_CLK_GS1 :1;                                       /* Number of clk_gs pulses per conversion, bit 1 */
    byte NUM_CLK_GS2 :1;                                       /* Number of clk_gs pulses per conversion, bit 2 */
    byte SWTRIG      :1;                                       /* Software Trigger */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpADIV :2;
    byte grpNUM_CLK_GS :3;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PGACNTL2STR;
extern volatile PGACNTL2STR _PGACNTL2 @0x0000187A;
#define PGACNTL2                        _PGACNTL2.Byte
#define PGACNTL2_ADIV0                  _PGACNTL2.Bits.ADIV0
#define PGACNTL2_ADIV1                  _PGACNTL2.Bits.ADIV1
#define PGACNTL2_NUM_CLK_GS0            _PGACNTL2.Bits.NUM_CLK_GS0
#define PGACNTL2_NUM_CLK_GS1            _PGACNTL2.Bits.NUM_CLK_GS1
#define PGACNTL2_NUM_CLK_GS2            _PGACNTL2.Bits.NUM_CLK_GS2
#define PGACNTL2_SWTRIG                 _PGACNTL2.Bits.SWTRIG
#define PGACNTL2_ADIV                   _PGACNTL2.MergedBits.grpADIV
#define PGACNTL2_NUM_CLK_GS             _PGACNTL2.MergedBits.grpNUM_CLK_GS

#define PGACNTL2_ADIV0_MASK             1U
#define PGACNTL2_ADIV1_MASK             2U
#define PGACNTL2_NUM_CLK_GS0_MASK       4U
#define PGACNTL2_NUM_CLK_GS1_MASK       8U
#define PGACNTL2_NUM_CLK_GS2_MASK       16U
#define PGACNTL2_SWTRIG_MASK            32U
#define PGACNTL2_ADIV_MASK              3U
#define PGACNTL2_ADIV_BITNUM            0U
#define PGACNTL2_NUM_CLK_GS_MASK        28U
#define PGACNTL2_NUM_CLK_GS_BITNUM      2U


/*** PGASTS - PGA Status Register; 0x0000187B ***/
typedef union {
  byte Byte;
  struct {
    byte STCOMP      :1;                                       /* Startup Complete */
    byte RUNNING     :1;                                       /* PGA RUN Sequence Underway */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} PGASTSSTR;
extern volatile PGASTSSTR _PGASTS @0x0000187B;
#define PGASTS                          _PGASTS.Byte
#define PGASTS_STCOMP                   _PGASTS.Bits.STCOMP
#define PGASTS_RUNNING                  _PGASTS.Bits.RUNNING

#define PGASTS_STCOMP_MASK              1U
#define PGASTS_RUNNING_MASK             2U


/*** FTM2SC - FTM2 Status and Control Register; 0x00001880 ***/
typedef union {
  byte Byte;
  struct {
    byte PS0         :1;                                       /* Prescale Divisor Select Bit 0 */
    byte PS1         :1;                                       /* Prescale Divisor Select Bit 1 */
    byte PS2         :1;                                       /* Prescale Divisor Select Bit 2 */
    byte CLKSA       :1;                                       /* Clock Source Select A */
    byte CLKSB       :1;                                       /* Clock Source Select B */
    byte CPWMS       :1;                                       /* Center-Aligned PWM Select */
    byte TOIE        :1;                                       /* Timer Overflow Interrupt Enable */
    byte TOF         :1;                                       /* Timer Overflow Flag */
  } Bits;
  struct {
    byte grpPS   :3;
    byte grpCLKSx :2;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} FTM2SCSTR;
extern volatile FTM2SCSTR _FTM2SC @0x00001880;
#define FTM2SC                          _FTM2SC.Byte
#define FTM2SC_PS0                      _FTM2SC.Bits.PS0
#define FTM2SC_PS1                      _FTM2SC.Bits.PS1
#define FTM2SC_PS2                      _FTM2SC.Bits.PS2
#define FTM2SC_CLKSA                    _FTM2SC.Bits.CLKSA
#define FTM2SC_CLKSB                    _FTM2SC.Bits.CLKSB
#define FTM2SC_CPWMS                    _FTM2SC.Bits.CPWMS
#define FTM2SC_TOIE                     _FTM2SC.Bits.TOIE
#define FTM2SC_TOF                      _FTM2SC.Bits.TOF
#define FTM2SC_PS                       _FTM2SC.MergedBits.grpPS
#define FTM2SC_CLKSx                    _FTM2SC.MergedBits.grpCLKSx

#define FTM2SC_PS0_MASK                 1U
#define FTM2SC_PS1_MASK                 2U
#define FTM2SC_PS2_MASK                 4U
#define FTM2SC_CLKSA_MASK               8U
#define FTM2SC_CLKSB_MASK               16U
#define FTM2SC_CPWMS_MASK               32U
#define FTM2SC_TOIE_MASK                64U
#define FTM2SC_TOF_MASK                 128U
#define FTM2SC_PS_MASK                  7U
#define FTM2SC_PS_BITNUM                0U
#define FTM2SC_CLKSx_MASK               24U
#define FTM2SC_CLKSx_BITNUM             3U


/*** FTM2CNT - FTM2 Timer Counter Register; 0x00001881 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** FTM2CNTH - FTM2 Timer Counter Register High; 0x00001881 ***/
    union {
      byte Byte;
    } FTM2CNTHSTR;
    #define FTM2CNTH                    _FTM2CNT.Overlap_STR.FTM2CNTHSTR.Byte
    

    /*** FTM2CNTL - FTM2 Timer Counter Register Low; 0x00001882 ***/
    union {
      byte Byte;
    } FTM2CNTLSTR;
    #define FTM2CNTL                    _FTM2CNT.Overlap_STR.FTM2CNTLSTR.Byte
    
  } Overlap_STR;

} FTM2CNTSTR;
extern volatile FTM2CNTSTR _FTM2CNT @0x00001881;
#define FTM2CNT                         _FTM2CNT.Word


/*** FTM2MOD - FTM2 Timer Counter Modulo Register; 0x00001883 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** FTM2MODH - FTM2 Timer Counter Modulo Register High; 0x00001883 ***/
    union {
      byte Byte;
    } FTM2MODHSTR;
    #define FTM2MODH                    _FTM2MOD.Overlap_STR.FTM2MODHSTR.Byte
    

    /*** FTM2MODL - FTM2 Timer Counter Modulo Register Low; 0x00001884 ***/
    union {
      byte Byte;
    } FTM2MODLSTR;
    #define FTM2MODL                    _FTM2MOD.Overlap_STR.FTM2MODLSTR.Byte
    
  } Overlap_STR;

} FTM2MODSTR;
extern volatile FTM2MODSTR _FTM2MOD @0x00001883;
#define FTM2MOD                         _FTM2MOD.Word


/*** FTM2C0SC - FTM2 Timer Channel 0 Status and Control Register; 0x00001885 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELS0A       :1;                                       /* Edge/Level Select Bit A */
    byte ELS0B       :1;                                       /* Edge/Level Select Bit B */
    byte MS0A        :1;                                       /* Mode Select A for FTM2 Channel 0 */
    byte MS0B        :1;                                       /* Mode Select B for FTM2 Channel 0 */
    byte CH0IE       :1;                                       /* Channel 0 Interrupt Enable */
    byte CH0F        :1;                                       /* Channel 0 Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELS0x :2;
    byte grpMS0x :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} FTM2C0SCSTR;
extern volatile FTM2C0SCSTR _FTM2C0SC @0x00001885;
#define FTM2C0SC                        _FTM2C0SC.Byte
#define FTM2C0SC_ELS0A                  _FTM2C0SC.Bits.ELS0A
#define FTM2C0SC_ELS0B                  _FTM2C0SC.Bits.ELS0B
#define FTM2C0SC_MS0A                   _FTM2C0SC.Bits.MS0A
#define FTM2C0SC_MS0B                   _FTM2C0SC.Bits.MS0B
#define FTM2C0SC_CH0IE                  _FTM2C0SC.Bits.CH0IE
#define FTM2C0SC_CH0F                   _FTM2C0SC.Bits.CH0F
#define FTM2C0SC_ELS0x                  _FTM2C0SC.MergedBits.grpELS0x
#define FTM2C0SC_MS0x                   _FTM2C0SC.MergedBits.grpMS0x

#define FTM2C0SC_ELS0A_MASK             4U
#define FTM2C0SC_ELS0B_MASK             8U
#define FTM2C0SC_MS0A_MASK              16U
#define FTM2C0SC_MS0B_MASK              32U
#define FTM2C0SC_CH0IE_MASK             64U
#define FTM2C0SC_CH0F_MASK              128U
#define FTM2C0SC_ELS0x_MASK             12U
#define FTM2C0SC_ELS0x_BITNUM           2U
#define FTM2C0SC_MS0x_MASK              48U
#define FTM2C0SC_MS0x_BITNUM            4U


/*** FTM2C0V - FTM2 Timer Channel 0 Value Register; 0x00001886 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** FTM2C0VH - FTM2 Timer Channel 0 Value Register High; 0x00001886 ***/
    union {
      byte Byte;
    } FTM2C0VHSTR;
    #define FTM2C0VH                    _FTM2C0V.Overlap_STR.FTM2C0VHSTR.Byte
    

    /*** FTM2C0VL - FTM2 Timer Channel 0 Value Register Low; 0x00001887 ***/
    union {
      byte Byte;
    } FTM2C0VLSTR;
    #define FTM2C0VL                    _FTM2C0V.Overlap_STR.FTM2C0VLSTR.Byte
    
  } Overlap_STR;

} FTM2C0VSTR;
extern volatile FTM2C0VSTR _FTM2C0V @0x00001886;
#define FTM2C0V                         _FTM2C0V.Word


/*** FTM2C1SC - FTM2 Timer Channel 1 Status and Control Register; 0x00001888 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELS1A       :1;                                       /* Edge/Level Select Bit A */
    byte ELS1B       :1;                                       /* Edge/Level Select Bit B */
    byte MS1A        :1;                                       /* Mode Select A for FTM2 Channel 1 */
    byte MS1B        :1;                                       /* Mode Select B for FTM2 Channel 1 */
    byte CH1IE       :1;                                       /* Channel 1 Interrupt Enable */
    byte CH1F        :1;                                       /* Channel 1 Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELS1x :2;
    byte grpMS1x :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} FTM2C1SCSTR;
extern volatile FTM2C1SCSTR _FTM2C1SC @0x00001888;
#define FTM2C1SC                        _FTM2C1SC.Byte
#define FTM2C1SC_ELS1A                  _FTM2C1SC.Bits.ELS1A
#define FTM2C1SC_ELS1B                  _FTM2C1SC.Bits.ELS1B
#define FTM2C1SC_MS1A                   _FTM2C1SC.Bits.MS1A
#define FTM2C1SC_MS1B                   _FTM2C1SC.Bits.MS1B
#define FTM2C1SC_CH1IE                  _FTM2C1SC.Bits.CH1IE
#define FTM2C1SC_CH1F                   _FTM2C1SC.Bits.CH1F
#define FTM2C1SC_ELS1x                  _FTM2C1SC.MergedBits.grpELS1x
#define FTM2C1SC_MS1x                   _FTM2C1SC.MergedBits.grpMS1x

#define FTM2C1SC_ELS1A_MASK             4U
#define FTM2C1SC_ELS1B_MASK             8U
#define FTM2C1SC_MS1A_MASK              16U
#define FTM2C1SC_MS1B_MASK              32U
#define FTM2C1SC_CH1IE_MASK             64U
#define FTM2C1SC_CH1F_MASK              128U
#define FTM2C1SC_ELS1x_MASK             12U
#define FTM2C1SC_ELS1x_BITNUM           2U
#define FTM2C1SC_MS1x_MASK              48U
#define FTM2C1SC_MS1x_BITNUM            4U


/*** FTM2C1V - FTM2 Timer Channel 1 Value Register; 0x00001889 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** FTM2C1VH - FTM2 Timer Channel 1 Value Register High; 0x00001889 ***/
    union {
      byte Byte;
    } FTM2C1VHSTR;
    #define FTM2C1VH                    _FTM2C1V.Overlap_STR.FTM2C1VHSTR.Byte
    

    /*** FTM2C1VL - FTM2 Timer Channel 1 Value Register Low; 0x0000188A ***/
    union {
      byte Byte;
    } FTM2C1VLSTR;
    #define FTM2C1VL                    _FTM2C1V.Overlap_STR.FTM2C1VLSTR.Byte
    
  } Overlap_STR;

} FTM2C1VSTR;
extern volatile FTM2C1VSTR _FTM2C1V @0x00001889;
#define FTM2C1V                         _FTM2C1V.Word


/*** FTM2C2SC - FTM2 Timer Channel 2 Status and Control Register; 0x0000188B ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELS2A       :1;                                       /* Edge/Level Select Bit A */
    byte ELS2B       :1;                                       /* Edge/Level Select Bit B */
    byte MS2A        :1;                                       /* Mode Select A for FTM2 Channel 2 */
    byte MS2B        :1;                                       /* Mode Select B for FTM2 Channel 2 */
    byte CH2IE       :1;                                       /* Channel 2 Interrupt Enable */
    byte CH2F        :1;                                       /* Channel 2 Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELS2x :2;
    byte grpMS2x :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} FTM2C2SCSTR;
extern volatile FTM2C2SCSTR _FTM2C2SC @0x0000188B;
#define FTM2C2SC                        _FTM2C2SC.Byte
#define FTM2C2SC_ELS2A                  _FTM2C2SC.Bits.ELS2A
#define FTM2C2SC_ELS2B                  _FTM2C2SC.Bits.ELS2B
#define FTM2C2SC_MS2A                   _FTM2C2SC.Bits.MS2A
#define FTM2C2SC_MS2B                   _FTM2C2SC.Bits.MS2B
#define FTM2C2SC_CH2IE                  _FTM2C2SC.Bits.CH2IE
#define FTM2C2SC_CH2F                   _FTM2C2SC.Bits.CH2F
#define FTM2C2SC_ELS2x                  _FTM2C2SC.MergedBits.grpELS2x
#define FTM2C2SC_MS2x                   _FTM2C2SC.MergedBits.grpMS2x

#define FTM2C2SC_ELS2A_MASK             4U
#define FTM2C2SC_ELS2B_MASK             8U
#define FTM2C2SC_MS2A_MASK              16U
#define FTM2C2SC_MS2B_MASK              32U
#define FTM2C2SC_CH2IE_MASK             64U
#define FTM2C2SC_CH2F_MASK              128U
#define FTM2C2SC_ELS2x_MASK             12U
#define FTM2C2SC_ELS2x_BITNUM           2U
#define FTM2C2SC_MS2x_MASK              48U
#define FTM2C2SC_MS2x_BITNUM            4U


/*** FTM2C2V - FTM2 Timer Channel 2 Value Register; 0x0000188C ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** FTM2C2VH - FTM2 Timer Channel 2 Value Register High; 0x0000188C ***/
    union {
      byte Byte;
    } FTM2C2VHSTR;
    #define FTM2C2VH                    _FTM2C2V.Overlap_STR.FTM2C2VHSTR.Byte
    

    /*** FTM2C2VL - FTM2 Timer Channel 2 Value Register Low; 0x0000188D ***/
    union {
      byte Byte;
    } FTM2C2VLSTR;
    #define FTM2C2VL                    _FTM2C2V.Overlap_STR.FTM2C2VLSTR.Byte
    
  } Overlap_STR;

} FTM2C2VSTR;
extern volatile FTM2C2VSTR _FTM2C2V @0x0000188C;
#define FTM2C2V                         _FTM2C2V.Word


/*** FTM2C3SC - FTM2 Timer Channel 3 Status and Control Register; 0x0000188E ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELS3A       :1;                                       /* Edge/Level Select Bit A */
    byte ELS3B       :1;                                       /* Edge/Level Select Bit B */
    byte MS3A        :1;                                       /* Mode Select A for FTM2 Channel 3 */
    byte MS3B        :1;                                       /* Mode Select B for FTM2 Channel 3 */
    byte CH3IE       :1;                                       /* Channel 3 Interrupt Enable */
    byte CH3F        :1;                                       /* Channel 3 Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELS3x :2;
    byte grpMS3x :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} FTM2C3SCSTR;
extern volatile FTM2C3SCSTR _FTM2C3SC @0x0000188E;
#define FTM2C3SC                        _FTM2C3SC.Byte
#define FTM2C3SC_ELS3A                  _FTM2C3SC.Bits.ELS3A
#define FTM2C3SC_ELS3B                  _FTM2C3SC.Bits.ELS3B
#define FTM2C3SC_MS3A                   _FTM2C3SC.Bits.MS3A
#define FTM2C3SC_MS3B                   _FTM2C3SC.Bits.MS3B
#define FTM2C3SC_CH3IE                  _FTM2C3SC.Bits.CH3IE
#define FTM2C3SC_CH3F                   _FTM2C3SC.Bits.CH3F
#define FTM2C3SC_ELS3x                  _FTM2C3SC.MergedBits.grpELS3x
#define FTM2C3SC_MS3x                   _FTM2C3SC.MergedBits.grpMS3x

#define FTM2C3SC_ELS3A_MASK             4U
#define FTM2C3SC_ELS3B_MASK             8U
#define FTM2C3SC_MS3A_MASK              16U
#define FTM2C3SC_MS3B_MASK              32U
#define FTM2C3SC_CH3IE_MASK             64U
#define FTM2C3SC_CH3F_MASK              128U
#define FTM2C3SC_ELS3x_MASK             12U
#define FTM2C3SC_ELS3x_BITNUM           2U
#define FTM2C3SC_MS3x_MASK              48U
#define FTM2C3SC_MS3x_BITNUM            4U


/*** FTM2C3V - FTM2 Timer Channel 3 Value Register; 0x0000188F ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** FTM2C3VH - FTM2 Timer Channel 3 Value Register High; 0x0000188F ***/
    union {
      byte Byte;
    } FTM2C3VHSTR;
    #define FTM2C3VH                    _FTM2C3V.Overlap_STR.FTM2C3VHSTR.Byte
    

    /*** FTM2C3VL - FTM2 Timer Channel 3 Value Register Low; 0x00001890 ***/
    union {
      byte Byte;
    } FTM2C3VLSTR;
    #define FTM2C3VL                    _FTM2C3V.Overlap_STR.FTM2C3VLSTR.Byte
    
  } Overlap_STR;

} FTM2C3VSTR;
extern volatile FTM2C3VSTR _FTM2C3V @0x0000188F;
#define FTM2C3V                         _FTM2C3V.Word


/*** FTM2C4SC - FTM2 Timer Channel 4 Status and Control Register; 0x00001891 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELS4A       :1;                                       /* Edge/Level Select Bit A */
    byte ELS4B       :1;                                       /* Edge/Level Select Bit B */
    byte MS4A        :1;                                       /* Mode Select A for FTM2 Channel 4 */
    byte MS4B        :1;                                       /* Mode Select B for FTM2 Channel 4 */
    byte CH4IE       :1;                                       /* Channel 4 Interrupt Enable */
    byte CH4F        :1;                                       /* Channel 4 Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELS4x :2;
    byte grpMS4x :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} FTM2C4SCSTR;
extern volatile FTM2C4SCSTR _FTM2C4SC @0x00001891;
#define FTM2C4SC                        _FTM2C4SC.Byte
#define FTM2C4SC_ELS4A                  _FTM2C4SC.Bits.ELS4A
#define FTM2C4SC_ELS4B                  _FTM2C4SC.Bits.ELS4B
#define FTM2C4SC_MS4A                   _FTM2C4SC.Bits.MS4A
#define FTM2C4SC_MS4B                   _FTM2C4SC.Bits.MS4B
#define FTM2C4SC_CH4IE                  _FTM2C4SC.Bits.CH4IE
#define FTM2C4SC_CH4F                   _FTM2C4SC.Bits.CH4F
#define FTM2C4SC_ELS4x                  _FTM2C4SC.MergedBits.grpELS4x
#define FTM2C4SC_MS4x                   _FTM2C4SC.MergedBits.grpMS4x

#define FTM2C4SC_ELS4A_MASK             4U
#define FTM2C4SC_ELS4B_MASK             8U
#define FTM2C4SC_MS4A_MASK              16U
#define FTM2C4SC_MS4B_MASK              32U
#define FTM2C4SC_CH4IE_MASK             64U
#define FTM2C4SC_CH4F_MASK              128U
#define FTM2C4SC_ELS4x_MASK             12U
#define FTM2C4SC_ELS4x_BITNUM           2U
#define FTM2C4SC_MS4x_MASK              48U
#define FTM2C4SC_MS4x_BITNUM            4U


/*** FTM2C4V - FTM2 Timer Channel 4 Value Register; 0x00001892 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** FTM2C4VH - FTM2 Timer Channel 4 Value Register High; 0x00001892 ***/
    union {
      byte Byte;
    } FTM2C4VHSTR;
    #define FTM2C4VH                    _FTM2C4V.Overlap_STR.FTM2C4VHSTR.Byte
    

    /*** FTM2C4VL - FTM2 Timer Channel 4 Value Register Low; 0x00001893 ***/
    union {
      byte Byte;
    } FTM2C4VLSTR;
    #define FTM2C4VL                    _FTM2C4V.Overlap_STR.FTM2C4VLSTR.Byte
    
  } Overlap_STR;

} FTM2C4VSTR;
extern volatile FTM2C4VSTR _FTM2C4V @0x00001892;
#define FTM2C4V                         _FTM2C4V.Word


/*** FTM2C5SC - FTM2 Timer Channel 5 Status and Control Register; 0x00001894 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELS5A       :1;                                       /* Edge/Level Select Bit A */
    byte ELS5B       :1;                                       /* Edge/Level Select Bit B */
    byte MS5A        :1;                                       /* Mode Select A for FTM2 Channel 5 */
    byte MS5B        :1;                                       /* Mode Select B for FTM2 Channel 5 */
    byte CH5IE       :1;                                       /* Channel 5 Interrupt Enable */
    byte CH5F        :1;                                       /* Channel 5 Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELS5x :2;
    byte grpMS5x :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} FTM2C5SCSTR;
extern volatile FTM2C5SCSTR _FTM2C5SC @0x00001894;
#define FTM2C5SC                        _FTM2C5SC.Byte
#define FTM2C5SC_ELS5A                  _FTM2C5SC.Bits.ELS5A
#define FTM2C5SC_ELS5B                  _FTM2C5SC.Bits.ELS5B
#define FTM2C5SC_MS5A                   _FTM2C5SC.Bits.MS5A
#define FTM2C5SC_MS5B                   _FTM2C5SC.Bits.MS5B
#define FTM2C5SC_CH5IE                  _FTM2C5SC.Bits.CH5IE
#define FTM2C5SC_CH5F                   _FTM2C5SC.Bits.CH5F
#define FTM2C5SC_ELS5x                  _FTM2C5SC.MergedBits.grpELS5x
#define FTM2C5SC_MS5x                   _FTM2C5SC.MergedBits.grpMS5x

#define FTM2C5SC_ELS5A_MASK             4U
#define FTM2C5SC_ELS5B_MASK             8U
#define FTM2C5SC_MS5A_MASK              16U
#define FTM2C5SC_MS5B_MASK              32U
#define FTM2C5SC_CH5IE_MASK             64U
#define FTM2C5SC_CH5F_MASK              128U
#define FTM2C5SC_ELS5x_MASK             12U
#define FTM2C5SC_ELS5x_BITNUM           2U
#define FTM2C5SC_MS5x_MASK              48U
#define FTM2C5SC_MS5x_BITNUM            4U


/*** FTM2C5V - FTM2 Timer Channel 5 Value Register; 0x00001895 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** FTM2C5VH - FTM2 Timer Channel 5 Value Register High; 0x00001895 ***/
    union {
      byte Byte;
    } FTM2C5VHSTR;
    #define FTM2C5VH                    _FTM2C5V.Overlap_STR.FTM2C5VHSTR.Byte
    

    /*** FTM2C5VL - FTM2 Timer Channel 5 Value Register Low; 0x00001896 ***/
    union {
      byte Byte;
    } FTM2C5VLSTR;
    #define FTM2C5VL                    _FTM2C5V.Overlap_STR.FTM2C5VLSTR.Byte
    
  } Overlap_STR;

} FTM2C5VSTR;
extern volatile FTM2C5VSTR _FTM2C5V @0x00001895;
#define FTM2C5V                         _FTM2C5V.Word


/*** FTM2CNTIN - FTM2 Counter Initial Value Registers; 0x000018A0 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** FTM2CNTINH - FTM2 Counter Initial Value Registers High; 0x000018A0 ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* FTM2 Counter Initial Value Bit 8 */
        byte BIT9        :1;                                       /* FTM2 Counter Initial Value Bit 9 */
        byte BIT10       :1;                                       /* FTM2 Counter Initial Value Bit 10 */
        byte BIT11       :1;                                       /* FTM2 Counter Initial Value Bit 11 */
        byte BIT12       :1;                                       /* FTM2 Counter Initial Value Bit 12 */
        byte BIT13       :1;                                       /* FTM2 Counter Initial Value Bit 13 */
        byte BIT14       :1;                                       /* FTM2 Counter Initial Value Bit 14 */
        byte BIT15       :1;                                       /* FTM2 Counter Initial Value Bit 15 */
      } Bits;
    } FTM2CNTINHSTR;
    #define FTM2CNTINH                  _FTM2CNTIN.Overlap_STR.FTM2CNTINHSTR.Byte
    #define FTM2CNTINH_BIT8             _FTM2CNTIN.Overlap_STR.FTM2CNTINHSTR.Bits.BIT8
    #define FTM2CNTINH_BIT9             _FTM2CNTIN.Overlap_STR.FTM2CNTINHSTR.Bits.BIT9
    #define FTM2CNTINH_BIT10            _FTM2CNTIN.Overlap_STR.FTM2CNTINHSTR.Bits.BIT10
    #define FTM2CNTINH_BIT11            _FTM2CNTIN.Overlap_STR.FTM2CNTINHSTR.Bits.BIT11
    #define FTM2CNTINH_BIT12            _FTM2CNTIN.Overlap_STR.FTM2CNTINHSTR.Bits.BIT12
    #define FTM2CNTINH_BIT13            _FTM2CNTIN.Overlap_STR.FTM2CNTINHSTR.Bits.BIT13
    #define FTM2CNTINH_BIT14            _FTM2CNTIN.Overlap_STR.FTM2CNTINHSTR.Bits.BIT14
    #define FTM2CNTINH_BIT15            _FTM2CNTIN.Overlap_STR.FTM2CNTINHSTR.Bits.BIT15
    
    #define FTM2CNTINH_BIT8_MASK        1U
    #define FTM2CNTINH_BIT9_MASK        2U
    #define FTM2CNTINH_BIT10_MASK       4U
    #define FTM2CNTINH_BIT11_MASK       8U
    #define FTM2CNTINH_BIT12_MASK       16U
    #define FTM2CNTINH_BIT13_MASK       32U
    #define FTM2CNTINH_BIT14_MASK       64U
    #define FTM2CNTINH_BIT15_MASK       128U
    

    /*** FTM2CNTINL - FTM2 Counter Initial Value Registers Low; 0x000018A1 ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* FTM2 Counter Initial Value Bit 0 */
        byte BIT1        :1;                                       /* FTM2 Counter Initial Value Bit 1 */
        byte BIT2        :1;                                       /* FTM2 Counter Initial Value Bit 2 */
        byte BIT3        :1;                                       /* FTM2 Counter Initial Value Bit 3 */
        byte BIT4        :1;                                       /* FTM2 Counter Initial Value Bit 4 */
        byte BIT5        :1;                                       /* FTM2 Counter Initial Value Bit 5 */
        byte BIT6        :1;                                       /* FTM2 Counter Initial Value Bit 6 */
        byte BIT7        :1;                                       /* FTM2 Counter Initial Value Bit 7 */
      } Bits;
    } FTM2CNTINLSTR;
    #define FTM2CNTINL                  _FTM2CNTIN.Overlap_STR.FTM2CNTINLSTR.Byte
    #define FTM2CNTINL_BIT0             _FTM2CNTIN.Overlap_STR.FTM2CNTINLSTR.Bits.BIT0
    #define FTM2CNTINL_BIT1             _FTM2CNTIN.Overlap_STR.FTM2CNTINLSTR.Bits.BIT1
    #define FTM2CNTINL_BIT2             _FTM2CNTIN.Overlap_STR.FTM2CNTINLSTR.Bits.BIT2
    #define FTM2CNTINL_BIT3             _FTM2CNTIN.Overlap_STR.FTM2CNTINLSTR.Bits.BIT3
    #define FTM2CNTINL_BIT4             _FTM2CNTIN.Overlap_STR.FTM2CNTINLSTR.Bits.BIT4
    #define FTM2CNTINL_BIT5             _FTM2CNTIN.Overlap_STR.FTM2CNTINLSTR.Bits.BIT5
    #define FTM2CNTINL_BIT6             _FTM2CNTIN.Overlap_STR.FTM2CNTINLSTR.Bits.BIT6
    #define FTM2CNTINL_BIT7             _FTM2CNTIN.Overlap_STR.FTM2CNTINLSTR.Bits.BIT7
    
    #define FTM2CNTINL_BIT0_MASK        1U
    #define FTM2CNTINL_BIT1_MASK        2U
    #define FTM2CNTINL_BIT2_MASK        4U
    #define FTM2CNTINL_BIT3_MASK        8U
    #define FTM2CNTINL_BIT4_MASK        16U
    #define FTM2CNTINL_BIT5_MASK        32U
    #define FTM2CNTINL_BIT6_MASK        64U
    #define FTM2CNTINL_BIT7_MASK        128U
    
  } Overlap_STR;

} FTM2CNTINSTR;
extern volatile FTM2CNTINSTR _FTM2CNTIN @0x000018A0;
#define FTM2CNTIN                       _FTM2CNTIN.Word


/*** FTM2STATUS - FTM2 Capture and Compare Status Register; 0x000018A2 ***/
typedef union {
  byte Byte;
  struct {
    byte CH0F        :1;                                       /* Channel 0 Flag */
    byte CH1F        :1;                                       /* Channel 1 Flag */
    byte CH2F        :1;                                       /* Channel 2 Flag */
    byte CH3F        :1;                                       /* Channel 3 Flag */
    byte CH4F        :1;                                       /* Channel 4 Flag */
    byte CH5F        :1;                                       /* Channel 5 Flag */
    byte             :1; 
    byte             :1; 
  } Bits;
} FTM2STATUSSTR;
extern volatile FTM2STATUSSTR _FTM2STATUS @0x000018A2;
#define FTM2STATUS                      _FTM2STATUS.Byte
#define FTM2STATUS_CH0F                 _FTM2STATUS.Bits.CH0F
#define FTM2STATUS_CH1F                 _FTM2STATUS.Bits.CH1F
#define FTM2STATUS_CH2F                 _FTM2STATUS.Bits.CH2F
#define FTM2STATUS_CH3F                 _FTM2STATUS.Bits.CH3F
#define FTM2STATUS_CH4F                 _FTM2STATUS.Bits.CH4F
#define FTM2STATUS_CH5F                 _FTM2STATUS.Bits.CH5F

#define FTM2STATUS_CH0F_MASK            1U
#define FTM2STATUS_CH1F_MASK            2U
#define FTM2STATUS_CH2F_MASK            4U
#define FTM2STATUS_CH3F_MASK            8U
#define FTM2STATUS_CH4F_MASK            16U
#define FTM2STATUS_CH5F_MASK            32U


/*** FTM2MODE - FTM2 Features Mode Selection Register; 0x000018A3 ***/
typedef union {
  byte Byte;
  struct {
    byte FTMEN       :1;                                       /* FTM2 Enable */
    byte INIT        :1;                                       /* Initialize the Channels Output */
    byte WPDIS       :1;                                       /* Write Protected Disable */
    byte PWMSYNC     :1;                                       /* PWM synchronization mode */
    byte CAPTTEST    :1;                                       /* Capture test mode enable */
    byte FAULTM0     :1;                                       /* Fault Control Mode Bits, bit 0 */
    byte FAULTM1     :1;                                       /* Fault Control Mode Bits, bit 1 */
    byte FAULTIE     :1;                                       /* Fault Interrupt Enable */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpFAULTM :2;
    byte         :1;
  } MergedBits;
} FTM2MODESTR;
extern volatile FTM2MODESTR _FTM2MODE @0x000018A3;
#define FTM2MODE                        _FTM2MODE.Byte
#define FTM2MODE_FTMEN                  _FTM2MODE.Bits.FTMEN
#define FTM2MODE_INIT                   _FTM2MODE.Bits.INIT
#define FTM2MODE_WPDIS                  _FTM2MODE.Bits.WPDIS
#define FTM2MODE_PWMSYNC                _FTM2MODE.Bits.PWMSYNC
#define FTM2MODE_CAPTTEST               _FTM2MODE.Bits.CAPTTEST
#define FTM2MODE_FAULTM0                _FTM2MODE.Bits.FAULTM0
#define FTM2MODE_FAULTM1                _FTM2MODE.Bits.FAULTM1
#define FTM2MODE_FAULTIE                _FTM2MODE.Bits.FAULTIE
#define FTM2MODE_FAULTM                 _FTM2MODE.MergedBits.grpFAULTM

#define FTM2MODE_FTMEN_MASK             1U
#define FTM2MODE_INIT_MASK              2U
#define FTM2MODE_WPDIS_MASK             4U
#define FTM2MODE_PWMSYNC_MASK           8U
#define FTM2MODE_CAPTTEST_MASK          16U
#define FTM2MODE_FAULTM0_MASK           32U
#define FTM2MODE_FAULTM1_MASK           64U
#define FTM2MODE_FAULTIE_MASK           128U
#define FTM2MODE_FAULTM_MASK            96U
#define FTM2MODE_FAULTM_BITNUM          5U


/*** FTM2SYNC - FTM2 Synchronization Register; 0x000018A4 ***/
typedef union {
  byte Byte;
  struct {
    byte CNTMIN      :1;                                       /* FTM2 Counter is Minimum */
    byte CNTMAX      :1;                                       /* FTM2 Counter is Maximum */
    byte REINIT      :1;                                       /* Reinitialization of FTM2 Counter by Synchronization */
    byte SYNCHOM     :1;                                       /* Output Mask by Synchronization */
    byte TRIG0       :1;                                       /* External Trigger Bit 0 for Synchronization */
    byte TRIG1       :1;                                       /* External Trigger Bit 1 for Synchronization */
    byte TRIG2       :1;                                       /* External Trigger Bit 2 for Synchronization */
    byte SWSYNC      :1;                                       /* Software Trigger for Synchronization */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpTRIG :3;
    byte         :1;
  } MergedBits;
} FTM2SYNCSTR;
extern volatile FTM2SYNCSTR _FTM2SYNC @0x000018A4;
#define FTM2SYNC                        _FTM2SYNC.Byte
#define FTM2SYNC_CNTMIN                 _FTM2SYNC.Bits.CNTMIN
#define FTM2SYNC_CNTMAX                 _FTM2SYNC.Bits.CNTMAX
#define FTM2SYNC_REINIT                 _FTM2SYNC.Bits.REINIT
#define FTM2SYNC_SYNCHOM                _FTM2SYNC.Bits.SYNCHOM
#define FTM2SYNC_TRIG0                  _FTM2SYNC.Bits.TRIG0
#define FTM2SYNC_TRIG1                  _FTM2SYNC.Bits.TRIG1
#define FTM2SYNC_TRIG2                  _FTM2SYNC.Bits.TRIG2
#define FTM2SYNC_SWSYNC                 _FTM2SYNC.Bits.SWSYNC
#define FTM2SYNC_TRIG                   _FTM2SYNC.MergedBits.grpTRIG

#define FTM2SYNC_CNTMIN_MASK            1U
#define FTM2SYNC_CNTMAX_MASK            2U
#define FTM2SYNC_REINIT_MASK            4U
#define FTM2SYNC_SYNCHOM_MASK           8U
#define FTM2SYNC_TRIG0_MASK             16U
#define FTM2SYNC_TRIG1_MASK             32U
#define FTM2SYNC_TRIG2_MASK             64U
#define FTM2SYNC_SWSYNC_MASK            128U
#define FTM2SYNC_TRIG_MASK              112U
#define FTM2SYNC_TRIG_BITNUM            4U


/*** FTM2OUTINIT - FTM2 Initial State for Channels Output Register; 0x000018A5 ***/
typedef union {
  byte Byte;
  struct {
    byte CH0OI       :1;                                       /* Initial State for Channel 0 Output */
    byte CH1OI       :1;                                       /* Initial State for Channel 1 Output */
    byte CH2OI       :1;                                       /* Initial State for Channel 2 Output */
    byte CH3OI       :1;                                       /* Initial State for Channel 3 Output */
    byte CH4OI       :1;                                       /* Initial State for Channel 4 Output */
    byte CH5OI       :1;                                       /* Initial State for Channel 5 Output */
    byte             :1; 
    byte             :1; 
  } Bits;
} FTM2OUTINITSTR;
extern volatile FTM2OUTINITSTR _FTM2OUTINIT @0x000018A5;
#define FTM2OUTINIT                     _FTM2OUTINIT.Byte
#define FTM2OUTINIT_CH0OI               _FTM2OUTINIT.Bits.CH0OI
#define FTM2OUTINIT_CH1OI               _FTM2OUTINIT.Bits.CH1OI
#define FTM2OUTINIT_CH2OI               _FTM2OUTINIT.Bits.CH2OI
#define FTM2OUTINIT_CH3OI               _FTM2OUTINIT.Bits.CH3OI
#define FTM2OUTINIT_CH4OI               _FTM2OUTINIT.Bits.CH4OI
#define FTM2OUTINIT_CH5OI               _FTM2OUTINIT.Bits.CH5OI

#define FTM2OUTINIT_CH0OI_MASK          1U
#define FTM2OUTINIT_CH1OI_MASK          2U
#define FTM2OUTINIT_CH2OI_MASK          4U
#define FTM2OUTINIT_CH3OI_MASK          8U
#define FTM2OUTINIT_CH4OI_MASK          16U
#define FTM2OUTINIT_CH5OI_MASK          32U


/*** FTM2OUTMASK - FTM2 Output Mask Register; 0x000018A6 ***/
typedef union {
  byte Byte;
  struct {
    byte CH0OM       :1;                                       /* Channel 0 Output Mask */
    byte CH1OM       :1;                                       /* Channel 1 Output Mask */
    byte CH2OM       :1;                                       /* Channel 2 Output Mask */
    byte CH3OM       :1;                                       /* Channel 3 Output Mask */
    byte CH4OM       :1;                                       /* Channel 4 Output Mask */
    byte CH5OM       :1;                                       /* Channel 5 Output Mask */
    byte             :1; 
    byte             :1; 
  } Bits;
} FTM2OUTMASKSTR;
extern volatile FTM2OUTMASKSTR _FTM2OUTMASK @0x000018A6;
#define FTM2OUTMASK                     _FTM2OUTMASK.Byte
#define FTM2OUTMASK_CH0OM               _FTM2OUTMASK.Bits.CH0OM
#define FTM2OUTMASK_CH1OM               _FTM2OUTMASK.Bits.CH1OM
#define FTM2OUTMASK_CH2OM               _FTM2OUTMASK.Bits.CH2OM
#define FTM2OUTMASK_CH3OM               _FTM2OUTMASK.Bits.CH3OM
#define FTM2OUTMASK_CH4OM               _FTM2OUTMASK.Bits.CH4OM
#define FTM2OUTMASK_CH5OM               _FTM2OUTMASK.Bits.CH5OM

#define FTM2OUTMASK_CH0OM_MASK          1U
#define FTM2OUTMASK_CH1OM_MASK          2U
#define FTM2OUTMASK_CH2OM_MASK          4U
#define FTM2OUTMASK_CH3OM_MASK          8U
#define FTM2OUTMASK_CH4OM_MASK          16U
#define FTM2OUTMASK_CH5OM_MASK          32U


/*** FTM2COMBINE0 - FTM2 Function For Linked Channel 0 Register; 0x000018A7 ***/
typedef union {
  byte Byte;
  struct {
    byte COMBINE     :1;                                       /* Enables the Combine of the Channels 0 and 1 */
    byte COMP        :1;                                       /* Complementary of Channel 0 */
    byte             :1; 
    byte             :1; 
    byte DTEN        :1;                                       /* Deadtime Enable */
    byte SYNCEN      :1;                                       /* Synchronization Enable */
    byte FAULTEN     :1;                                       /* Fault Control Enable */
    byte             :1; 
  } Bits;
} FTM2COMBINE0STR;
extern volatile FTM2COMBINE0STR _FTM2COMBINE0 @0x000018A7;
#define FTM2COMBINE0                    _FTM2COMBINE0.Byte
#define FTM2COMBINE0_COMBINE            _FTM2COMBINE0.Bits.COMBINE
#define FTM2COMBINE0_COMP               _FTM2COMBINE0.Bits.COMP
#define FTM2COMBINE0_DTEN               _FTM2COMBINE0.Bits.DTEN
#define FTM2COMBINE0_SYNCEN             _FTM2COMBINE0.Bits.SYNCEN
#define FTM2COMBINE0_FAULTEN            _FTM2COMBINE0.Bits.FAULTEN
/* FTM2COMBINE_ARR: Access 3 FTM2COMBINEx registers in an array */
#define FTM2COMBINE_ARR                 ((volatile byte * __far) &FTM2COMBINE0)

#define FTM2COMBINE0_COMBINE_MASK       1U
#define FTM2COMBINE0_COMP_MASK          2U
#define FTM2COMBINE0_DTEN_MASK          16U
#define FTM2COMBINE0_SYNCEN_MASK        32U
#define FTM2COMBINE0_FAULTEN_MASK       64U


/*** FTM2COMBINE1 - FTM2 Function For Linked Channel 1 Register; 0x000018A8 ***/
typedef union {
  byte Byte;
  struct {
    byte COMBINE     :1;                                       /* Enables the Combine of the Channels 2 and 3 */
    byte COMP        :1;                                       /* Complementary of Channel 2 */
    byte             :1; 
    byte             :1; 
    byte DTEN        :1;                                       /* Deadtime Enable */
    byte SYNCEN      :1;                                       /* Synchronization Enable */
    byte FAULTEN     :1;                                       /* Fault Control Enable */
    byte             :1; 
  } Bits;
} FTM2COMBINE1STR;
extern volatile FTM2COMBINE1STR _FTM2COMBINE1 @0x000018A8;
#define FTM2COMBINE1                    _FTM2COMBINE1.Byte
#define FTM2COMBINE1_COMBINE            _FTM2COMBINE1.Bits.COMBINE
#define FTM2COMBINE1_COMP               _FTM2COMBINE1.Bits.COMP
#define FTM2COMBINE1_DTEN               _FTM2COMBINE1.Bits.DTEN
#define FTM2COMBINE1_SYNCEN             _FTM2COMBINE1.Bits.SYNCEN
#define FTM2COMBINE1_FAULTEN            _FTM2COMBINE1.Bits.FAULTEN

#define FTM2COMBINE1_COMBINE_MASK       1U
#define FTM2COMBINE1_COMP_MASK          2U
#define FTM2COMBINE1_DTEN_MASK          16U
#define FTM2COMBINE1_SYNCEN_MASK        32U
#define FTM2COMBINE1_FAULTEN_MASK       64U


/*** FTM2COMBINE2 - FTM2 Function For Linked Channel 2 Register; 0x000018A9 ***/
typedef union {
  byte Byte;
  struct {
    byte COMBINE     :1;                                       /* Enables the Combine of the Channels 4 and 5 */
    byte COMP        :1;                                       /* Complementary of Channel 4 */
    byte             :1; 
    byte             :1; 
    byte DTEN        :1;                                       /* Deadtime Enable */
    byte SYNCEN      :1;                                       /* Synchronization Enable */
    byte FAULTEN     :1;                                       /* Fault Control Enable */
    byte             :1; 
  } Bits;
} FTM2COMBINE2STR;
extern volatile FTM2COMBINE2STR _FTM2COMBINE2 @0x000018A9;
#define FTM2COMBINE2                    _FTM2COMBINE2.Byte
#define FTM2COMBINE2_COMBINE            _FTM2COMBINE2.Bits.COMBINE
#define FTM2COMBINE2_COMP               _FTM2COMBINE2.Bits.COMP
#define FTM2COMBINE2_DTEN               _FTM2COMBINE2.Bits.DTEN
#define FTM2COMBINE2_SYNCEN             _FTM2COMBINE2.Bits.SYNCEN
#define FTM2COMBINE2_FAULTEN            _FTM2COMBINE2.Bits.FAULTEN

#define FTM2COMBINE2_COMBINE_MASK       1U
#define FTM2COMBINE2_COMP_MASK          2U
#define FTM2COMBINE2_DTEN_MASK          16U
#define FTM2COMBINE2_SYNCEN_MASK        32U
#define FTM2COMBINE2_FAULTEN_MASK       64U


/*** FTM2DEADTIME - FTM2 Deadtime Insertion Control Register; 0x000018AB ***/
typedef union {
  byte Byte;
  struct {
    byte DTVAL0      :1;                                       /* Deadtime Value Bits, bit 0 */
    byte DTVAL1      :1;                                       /* Deadtime Value Bits, bit 1 */
    byte DTVAL2      :1;                                       /* Deadtime Value Bits, bit 2 */
    byte DTVAL3      :1;                                       /* Deadtime Value Bits, bit 3 */
    byte DTVAL4      :1;                                       /* Deadtime Value Bits, bit 4 */
    byte DTVAL5      :1;                                       /* Deadtime Value Bits, bit 5 */
    byte DTPS0       :1;                                       /* Deadtime Prescaler Value Bits, bit 0 */
    byte DTPS1       :1;                                       /* Deadtime Prescaler Value Bits, bit 1 */
  } Bits;
  struct {
    byte grpDTVAL :6;
    byte grpDTPS :2;
  } MergedBits;
} FTM2DEADTIMESTR;
extern volatile FTM2DEADTIMESTR _FTM2DEADTIME @0x000018AB;
#define FTM2DEADTIME                    _FTM2DEADTIME.Byte
#define FTM2DEADTIME_DTVAL0             _FTM2DEADTIME.Bits.DTVAL0
#define FTM2DEADTIME_DTVAL1             _FTM2DEADTIME.Bits.DTVAL1
#define FTM2DEADTIME_DTVAL2             _FTM2DEADTIME.Bits.DTVAL2
#define FTM2DEADTIME_DTVAL3             _FTM2DEADTIME.Bits.DTVAL3
#define FTM2DEADTIME_DTVAL4             _FTM2DEADTIME.Bits.DTVAL4
#define FTM2DEADTIME_DTVAL5             _FTM2DEADTIME.Bits.DTVAL5
#define FTM2DEADTIME_DTPS0              _FTM2DEADTIME.Bits.DTPS0
#define FTM2DEADTIME_DTPS1              _FTM2DEADTIME.Bits.DTPS1
#define FTM2DEADTIME_DTVAL              _FTM2DEADTIME.MergedBits.grpDTVAL
#define FTM2DEADTIME_DTPS               _FTM2DEADTIME.MergedBits.grpDTPS

#define FTM2DEADTIME_DTVAL0_MASK        1U
#define FTM2DEADTIME_DTVAL1_MASK        2U
#define FTM2DEADTIME_DTVAL2_MASK        4U
#define FTM2DEADTIME_DTVAL3_MASK        8U
#define FTM2DEADTIME_DTVAL4_MASK        16U
#define FTM2DEADTIME_DTVAL5_MASK        32U
#define FTM2DEADTIME_DTPS0_MASK         64U
#define FTM2DEADTIME_DTPS1_MASK         128U
#define FTM2DEADTIME_DTVAL_MASK         63U
#define FTM2DEADTIME_DTVAL_BITNUM       0U
#define FTM2DEADTIME_DTPS_MASK          192U
#define FTM2DEADTIME_DTPS_BITNUM        6U


/*** FTM2EXTTRIG - FTM2 ExternalTrigger Register; 0x000018AC ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte INITTRIGEN  :1;                                       /* Enables the Generation of a Trigger Signal */
    byte             :1; 
  } Bits;
} FTM2EXTTRIGSTR;
extern volatile FTM2EXTTRIGSTR _FTM2EXTTRIG @0x000018AC;
#define FTM2EXTTRIG                     _FTM2EXTTRIG.Byte
#define FTM2EXTTRIG_INITTRIGEN          _FTM2EXTTRIG.Bits.INITTRIGEN

#define FTM2EXTTRIG_INITTRIGEN_MASK     64U


/*** FTM2POL - FTM2 Channels Polarity Register; 0x000018AD ***/
typedef union {
  byte Byte;
  struct {
    byte POL0        :1;                                       /* Channel 0 Polarity */
    byte POL1        :1;                                       /* Channel 1 Polarity */
    byte POL2        :1;                                       /* Channel 2 Polarity */
    byte POL3        :1;                                       /* Channel 3 Polarity */
    byte POL4        :1;                                       /* Channel 4 Polarity */
    byte POL5        :1;                                       /* Channel 5 Polarity */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPOL  :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} FTM2POLSTR;
extern volatile FTM2POLSTR _FTM2POL @0x000018AD;
#define FTM2POL                         _FTM2POL.Byte
#define FTM2POL_POL0                    _FTM2POL.Bits.POL0
#define FTM2POL_POL1                    _FTM2POL.Bits.POL1
#define FTM2POL_POL2                    _FTM2POL.Bits.POL2
#define FTM2POL_POL3                    _FTM2POL.Bits.POL3
#define FTM2POL_POL4                    _FTM2POL.Bits.POL4
#define FTM2POL_POL5                    _FTM2POL.Bits.POL5
#define FTM2POL_POL                     _FTM2POL.MergedBits.grpPOL

#define FTM2POL_POL0_MASK               1U
#define FTM2POL_POL1_MASK               2U
#define FTM2POL_POL2_MASK               4U
#define FTM2POL_POL3_MASK               8U
#define FTM2POL_POL4_MASK               16U
#define FTM2POL_POL5_MASK               32U
#define FTM2POL_POL_MASK                63U
#define FTM2POL_POL_BITNUM              0U


/*** FTM2FMS - FTM2 Fault Mode Status Register; 0x000018AE ***/
typedef union {
  byte Byte;
  struct {
    byte FAULTF0     :1;                                       /* Fault detection flag 0 */
    byte FAULTF1     :1;                                       /* Fault detection flag 1 */
    byte FAULTF2     :1;                                       /* Fault detection flag 2 */
    byte FAULTF3     :1;                                       /* Fault detection flag 3 */
    byte             :1; 
    byte FAULTIN     :1;                                       /* Fault Input */
    byte WPEN        :1;                                       /* Write Protected Enable */
    byte FAULTF      :1;                                       /* Fault Detection Flag */
  } Bits;
  struct {
    byte         :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} FTM2FMSSTR;
extern volatile FTM2FMSSTR _FTM2FMS @0x000018AE;
#define FTM2FMS                         _FTM2FMS.Byte
#define FTM2FMS_FAULTF0                 _FTM2FMS.Bits.FAULTF0
#define FTM2FMS_FAULTF1                 _FTM2FMS.Bits.FAULTF1
#define FTM2FMS_FAULTF2                 _FTM2FMS.Bits.FAULTF2
#define FTM2FMS_FAULTF3                 _FTM2FMS.Bits.FAULTF3
#define FTM2FMS_FAULTIN                 _FTM2FMS.Bits.FAULTIN
#define FTM2FMS_WPEN                    _FTM2FMS.Bits.WPEN
#define FTM2FMS_FAULTF                  _FTM2FMS.Bits.FAULTF

#define FTM2FMS_FAULTF0_MASK            1U
#define FTM2FMS_FAULTF1_MASK            2U
#define FTM2FMS_FAULTF2_MASK            4U
#define FTM2FMS_FAULTF3_MASK            8U
#define FTM2FMS_FAULTIN_MASK            32U
#define FTM2FMS_WPEN_MASK               64U
#define FTM2FMS_FAULTF_MASK             128U


/*** FTM2FILTER0 - FTM2 Input Capture Filter Control Register 0; 0x000018AF ***/
typedef union {
  byte Byte;
  struct {
    byte CH0FVAL0    :1;                                       /* Channel 0 Input Filter Bits, bit 0 */
    byte CH0FVAL1    :1;                                       /* Channel 0 Input Filter Bits, bit 1 */
    byte CH0FVAL2    :1;                                       /* Channel 0 Input Filter Bits, bit 2 */
    byte CH0FVAL3    :1;                                       /* Channel 0 Input Filter Bits, bit 3 */
    byte CH1FVAL0    :1;                                       /* Channel 1 Input Filter Bits, bit 0 */
    byte CH1FVAL1    :1;                                       /* Channel 1 Input Filter Bits, bit 1 */
    byte CH1FVAL2    :1;                                       /* Channel 1 Input Filter Bits, bit 2 */
    byte CH1FVAL3    :1;                                       /* Channel 1 Input Filter Bits, bit 3 */
  } Bits;
  struct {
    byte grpCH0FVAL :4;
    byte grpCH1FVAL :4;
  } MergedBits;
} FTM2FILTER0STR;
extern volatile FTM2FILTER0STR _FTM2FILTER0 @0x000018AF;
#define FTM2FILTER0                     _FTM2FILTER0.Byte
#define FTM2FILTER0_CH0FVAL0            _FTM2FILTER0.Bits.CH0FVAL0
#define FTM2FILTER0_CH0FVAL1            _FTM2FILTER0.Bits.CH0FVAL1
#define FTM2FILTER0_CH0FVAL2            _FTM2FILTER0.Bits.CH0FVAL2
#define FTM2FILTER0_CH0FVAL3            _FTM2FILTER0.Bits.CH0FVAL3
#define FTM2FILTER0_CH1FVAL0            _FTM2FILTER0.Bits.CH1FVAL0
#define FTM2FILTER0_CH1FVAL1            _FTM2FILTER0.Bits.CH1FVAL1
#define FTM2FILTER0_CH1FVAL2            _FTM2FILTER0.Bits.CH1FVAL2
#define FTM2FILTER0_CH1FVAL3            _FTM2FILTER0.Bits.CH1FVAL3
/* FTM2FILTER_ARR: Access 2 FTM2FILTERx registers in an array */
#define FTM2FILTER_ARR                  ((volatile byte * __far) &FTM2FILTER0)
#define FTM2FILTER0_CH0FVAL             _FTM2FILTER0.MergedBits.grpCH0FVAL
#define FTM2FILTER0_CH1FVAL             _FTM2FILTER0.MergedBits.grpCH1FVAL

#define FTM2FILTER0_CH0FVAL0_MASK       1U
#define FTM2FILTER0_CH0FVAL1_MASK       2U
#define FTM2FILTER0_CH0FVAL2_MASK       4U
#define FTM2FILTER0_CH0FVAL3_MASK       8U
#define FTM2FILTER0_CH1FVAL0_MASK       16U
#define FTM2FILTER0_CH1FVAL1_MASK       32U
#define FTM2FILTER0_CH1FVAL2_MASK       64U
#define FTM2FILTER0_CH1FVAL3_MASK       128U
#define FTM2FILTER0_CH0FVAL_MASK        15U
#define FTM2FILTER0_CH0FVAL_BITNUM      0U
#define FTM2FILTER0_CH1FVAL_MASK        240U
#define FTM2FILTER0_CH1FVAL_BITNUM      4U


/*** FTM2FILTER1 - FTM2 Input Capture Filter Control Register 1; 0x000018B0 ***/
typedef union {
  byte Byte;
  struct {
    byte CH2FVAL0    :1;                                       /* Channel 2 Input Filter Bits, bit 0 */
    byte CH2FVAL1    :1;                                       /* Channel 2 Input Filter Bits, bit 1 */
    byte CH2FVAL2    :1;                                       /* Channel 2 Input Filter Bits, bit 2 */
    byte CH2FVAL3    :1;                                       /* Channel 2 Input Filter Bits, bit 3 */
    byte CH3FVAL0    :1;                                       /* Channel 3 Input Filter Bits, bit 0 */
    byte CH3FVAL1    :1;                                       /* Channel 3 Input Filter Bits, bit 1 */
    byte CH3FVAL2    :1;                                       /* Channel 3 Input Filter Bits, bit 2 */
    byte CH3FVAL3    :1;                                       /* Channel 3 Input Filter Bits, bit 3 */
  } Bits;
  struct {
    byte grpCH2FVAL :4;
    byte grpCH3FVAL :4;
  } MergedBits;
} FTM2FILTER1STR;
extern volatile FTM2FILTER1STR _FTM2FILTER1 @0x000018B0;
#define FTM2FILTER1                     _FTM2FILTER1.Byte
#define FTM2FILTER1_CH2FVAL0            _FTM2FILTER1.Bits.CH2FVAL0
#define FTM2FILTER1_CH2FVAL1            _FTM2FILTER1.Bits.CH2FVAL1
#define FTM2FILTER1_CH2FVAL2            _FTM2FILTER1.Bits.CH2FVAL2
#define FTM2FILTER1_CH2FVAL3            _FTM2FILTER1.Bits.CH2FVAL3
#define FTM2FILTER1_CH3FVAL0            _FTM2FILTER1.Bits.CH3FVAL0
#define FTM2FILTER1_CH3FVAL1            _FTM2FILTER1.Bits.CH3FVAL1
#define FTM2FILTER1_CH3FVAL2            _FTM2FILTER1.Bits.CH3FVAL2
#define FTM2FILTER1_CH3FVAL3            _FTM2FILTER1.Bits.CH3FVAL3
#define FTM2FILTER1_CH2FVAL             _FTM2FILTER1.MergedBits.grpCH2FVAL
#define FTM2FILTER1_CH3FVAL             _FTM2FILTER1.MergedBits.grpCH3FVAL

#define FTM2FILTER1_CH2FVAL0_MASK       1U
#define FTM2FILTER1_CH2FVAL1_MASK       2U
#define FTM2FILTER1_CH2FVAL2_MASK       4U
#define FTM2FILTER1_CH2FVAL3_MASK       8U
#define FTM2FILTER1_CH3FVAL0_MASK       16U
#define FTM2FILTER1_CH3FVAL1_MASK       32U
#define FTM2FILTER1_CH3FVAL2_MASK       64U
#define FTM2FILTER1_CH3FVAL3_MASK       128U
#define FTM2FILTER1_CH2FVAL_MASK        15U
#define FTM2FILTER1_CH2FVAL_BITNUM      0U
#define FTM2FILTER1_CH3FVAL_MASK        240U
#define FTM2FILTER1_CH3FVAL_BITNUM      4U


/*** FTM2FLTFILTER - FTM2 Fault Input Filter Control Register; 0x000018B1 ***/
typedef union {
  byte Byte;
  struct {
    byte FFVAL0      :1;                                       /* Fault Input Filter Bits, bit 0 */
    byte FFVAL1      :1;                                       /* Fault Input Filter Bits, bit 1 */
    byte FFVAL2      :1;                                       /* Fault Input Filter Bits, bit 2 */
    byte FFVAL3      :1;                                       /* Fault Input Filter Bits, bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpFFVAL :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} FTM2FLTFILTERSTR;
extern volatile FTM2FLTFILTERSTR _FTM2FLTFILTER @0x000018B1;
#define FTM2FLTFILTER                   _FTM2FLTFILTER.Byte
#define FTM2FLTFILTER_FFVAL0            _FTM2FLTFILTER.Bits.FFVAL0
#define FTM2FLTFILTER_FFVAL1            _FTM2FLTFILTER.Bits.FFVAL1
#define FTM2FLTFILTER_FFVAL2            _FTM2FLTFILTER.Bits.FFVAL2
#define FTM2FLTFILTER_FFVAL3            _FTM2FLTFILTER.Bits.FFVAL3
#define FTM2FLTFILTER_FFVAL             _FTM2FLTFILTER.MergedBits.grpFFVAL

#define FTM2FLTFILTER_FFVAL0_MASK       1U
#define FTM2FLTFILTER_FFVAL1_MASK       2U
#define FTM2FLTFILTER_FFVAL2_MASK       4U
#define FTM2FLTFILTER_FFVAL3_MASK       8U
#define FTM2FLTFILTER_FFVAL_MASK        15U
#define FTM2FLTFILTER_FFVAL_BITNUM      0U


/*** FTM2FLTCTRL - FTM2 Fault Control Register; 0x000018B2 ***/
typedef union {
  byte Byte;
  struct {
    byte FAULT0EN    :1;                                       /* Fault input 0 enable */
    byte FAULT1EN    :1;                                       /* Fault input 1 enable */
    byte FAULT2EN    :1;                                       /* Fault input 2 enable */
    byte FAULT3EN    :1;                                       /* Fault input 3 enable */
    byte FFLTR0EN    :1;                                       /* Fault input 0 filter enable */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} FTM2FLTCTRLSTR;
extern volatile FTM2FLTCTRLSTR _FTM2FLTCTRL @0x000018B2;
#define FTM2FLTCTRL                     _FTM2FLTCTRL.Byte
#define FTM2FLTCTRL_FAULT0EN            _FTM2FLTCTRL.Bits.FAULT0EN
#define FTM2FLTCTRL_FAULT1EN            _FTM2FLTCTRL.Bits.FAULT1EN
#define FTM2FLTCTRL_FAULT2EN            _FTM2FLTCTRL.Bits.FAULT2EN
#define FTM2FLTCTRL_FAULT3EN            _FTM2FLTCTRL.Bits.FAULT3EN
#define FTM2FLTCTRL_FFLTR0EN            _FTM2FLTCTRL.Bits.FFLTR0EN

#define FTM2FLTCTRL_FAULT0EN_MASK       1U
#define FTM2FLTCTRL_FAULT1EN_MASK       2U
#define FTM2FLTCTRL_FAULT2EN_MASK       4U
#define FTM2FLTCTRL_FAULT3EN_MASK       8U
#define FTM2FLTCTRL_FFLTR0EN_MASK       16U


/*** NVFTRIM - Nonvolatile ICS Fine Trim; 0x0000FFAE ***/
typedef union {
  byte Byte;
  struct {
    byte FTRIM       :1;                                       /* ICS Fine Trim */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} NVFTRIMSTR;
/* Tip for register initialization in the user code:  const byte NVFTRIM_INIT @0x0000FFAE = <NVFTRIM_INITVAL>; */
#define _NVFTRIM (*(const NVFTRIMSTR * __far)0x0000FFAE)
#define NVFTRIM                         _NVFTRIM.Byte
#define NVFTRIM_FTRIM                   _NVFTRIM.Bits.FTRIM

#define NVFTRIM_FTRIM_MASK              1U


/*** NVICSTRM - Nonvolatile ICS Trim Register; 0x0000FFAF ***/
typedef union {
  byte Byte;
  struct {
    byte TRIM0       :1;                                       /* ICS Trim Setting, bit 0 */
    byte TRIM1       :1;                                       /* ICS Trim Setting, bit 1 */
    byte TRIM2       :1;                                       /* ICS Trim Setting, bit 2 */
    byte TRIM3       :1;                                       /* ICS Trim Setting, bit 3 */
    byte TRIM4       :1;                                       /* ICS Trim Setting, bit 4 */
    byte TRIM5       :1;                                       /* ICS Trim Setting, bit 5 */
    byte TRIM6       :1;                                       /* ICS Trim Setting, bit 6 */
    byte TRIM7       :1;                                       /* ICS Trim Setting, bit 7 */
  } Bits;
} NVICSTRMSTR;
/* Tip for register initialization in the user code:  const byte NVICSTRM_INIT @0x0000FFAF = <NVICSTRM_INITVAL>; */
#define _NVICSTRM (*(const NVICSTRMSTR * __far)0x0000FFAF)
#define NVICSTRM                        _NVICSTRM.Byte
#define NVICSTRM_TRIM0                  _NVICSTRM.Bits.TRIM0
#define NVICSTRM_TRIM1                  _NVICSTRM.Bits.TRIM1
#define NVICSTRM_TRIM2                  _NVICSTRM.Bits.TRIM2
#define NVICSTRM_TRIM3                  _NVICSTRM.Bits.TRIM3
#define NVICSTRM_TRIM4                  _NVICSTRM.Bits.TRIM4
#define NVICSTRM_TRIM5                  _NVICSTRM.Bits.TRIM5
#define NVICSTRM_TRIM6                  _NVICSTRM.Bits.TRIM6
#define NVICSTRM_TRIM7                  _NVICSTRM.Bits.TRIM7

#define NVICSTRM_TRIM0_MASK             1U
#define NVICSTRM_TRIM1_MASK             2U
#define NVICSTRM_TRIM2_MASK             4U
#define NVICSTRM_TRIM3_MASK             8U
#define NVICSTRM_TRIM4_MASK             16U
#define NVICSTRM_TRIM5_MASK             32U
#define NVICSTRM_TRIM6_MASK             64U
#define NVICSTRM_TRIM7_MASK             128U


/*** NVBACKKEY0 - Backdoor Comparison Key 0; 0x0000FFB0 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 7 */
  } Bits;
} NVBACKKEY0STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY0_INIT @0x0000FFB0 = <NVBACKKEY0_INITVAL>; */
#define _NVBACKKEY0 (*(const NVBACKKEY0STR * __far)0x0000FFB0)
#define NVBACKKEY0                      _NVBACKKEY0.Byte
#define NVBACKKEY0_KEY0                 _NVBACKKEY0.Bits.KEY0
#define NVBACKKEY0_KEY1                 _NVBACKKEY0.Bits.KEY1
#define NVBACKKEY0_KEY2                 _NVBACKKEY0.Bits.KEY2
#define NVBACKKEY0_KEY3                 _NVBACKKEY0.Bits.KEY3
#define NVBACKKEY0_KEY4                 _NVBACKKEY0.Bits.KEY4
#define NVBACKKEY0_KEY5                 _NVBACKKEY0.Bits.KEY5
#define NVBACKKEY0_KEY6                 _NVBACKKEY0.Bits.KEY6
#define NVBACKKEY0_KEY7                 _NVBACKKEY0.Bits.KEY7
/* NVBACKKEY_ARR: Access 8 NVBACKKEYx registers in an array */
#define NVBACKKEY_ARR                   ((volatile byte * __far) &NVBACKKEY0)

#define NVBACKKEY0_KEY0_MASK            1U
#define NVBACKKEY0_KEY1_MASK            2U
#define NVBACKKEY0_KEY2_MASK            4U
#define NVBACKKEY0_KEY3_MASK            8U
#define NVBACKKEY0_KEY4_MASK            16U
#define NVBACKKEY0_KEY5_MASK            32U
#define NVBACKKEY0_KEY6_MASK            64U
#define NVBACKKEY0_KEY7_MASK            128U


/*** NVBACKKEY1 - Backdoor Comparison Key 1; 0x0000FFB1 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 7 */
  } Bits;
} NVBACKKEY1STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY1_INIT @0x0000FFB1 = <NVBACKKEY1_INITVAL>; */
#define _NVBACKKEY1 (*(const NVBACKKEY1STR * __far)0x0000FFB1)
#define NVBACKKEY1                      _NVBACKKEY1.Byte
#define NVBACKKEY1_KEY0                 _NVBACKKEY1.Bits.KEY0
#define NVBACKKEY1_KEY1                 _NVBACKKEY1.Bits.KEY1
#define NVBACKKEY1_KEY2                 _NVBACKKEY1.Bits.KEY2
#define NVBACKKEY1_KEY3                 _NVBACKKEY1.Bits.KEY3
#define NVBACKKEY1_KEY4                 _NVBACKKEY1.Bits.KEY4
#define NVBACKKEY1_KEY5                 _NVBACKKEY1.Bits.KEY5
#define NVBACKKEY1_KEY6                 _NVBACKKEY1.Bits.KEY6
#define NVBACKKEY1_KEY7                 _NVBACKKEY1.Bits.KEY7

#define NVBACKKEY1_KEY0_MASK            1U
#define NVBACKKEY1_KEY1_MASK            2U
#define NVBACKKEY1_KEY2_MASK            4U
#define NVBACKKEY1_KEY3_MASK            8U
#define NVBACKKEY1_KEY4_MASK            16U
#define NVBACKKEY1_KEY5_MASK            32U
#define NVBACKKEY1_KEY6_MASK            64U
#define NVBACKKEY1_KEY7_MASK            128U


/*** NVBACKKEY2 - Backdoor Comparison Key 2; 0x0000FFB2 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 7 */
  } Bits;
} NVBACKKEY2STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY2_INIT @0x0000FFB2 = <NVBACKKEY2_INITVAL>; */
#define _NVBACKKEY2 (*(const NVBACKKEY2STR * __far)0x0000FFB2)
#define NVBACKKEY2                      _NVBACKKEY2.Byte
#define NVBACKKEY2_KEY0                 _NVBACKKEY2.Bits.KEY0
#define NVBACKKEY2_KEY1                 _NVBACKKEY2.Bits.KEY1
#define NVBACKKEY2_KEY2                 _NVBACKKEY2.Bits.KEY2
#define NVBACKKEY2_KEY3                 _NVBACKKEY2.Bits.KEY3
#define NVBACKKEY2_KEY4                 _NVBACKKEY2.Bits.KEY4
#define NVBACKKEY2_KEY5                 _NVBACKKEY2.Bits.KEY5
#define NVBACKKEY2_KEY6                 _NVBACKKEY2.Bits.KEY6
#define NVBACKKEY2_KEY7                 _NVBACKKEY2.Bits.KEY7

#define NVBACKKEY2_KEY0_MASK            1U
#define NVBACKKEY2_KEY1_MASK            2U
#define NVBACKKEY2_KEY2_MASK            4U
#define NVBACKKEY2_KEY3_MASK            8U
#define NVBACKKEY2_KEY4_MASK            16U
#define NVBACKKEY2_KEY5_MASK            32U
#define NVBACKKEY2_KEY6_MASK            64U
#define NVBACKKEY2_KEY7_MASK            128U


/*** NVBACKKEY3 - Backdoor Comparison Key 3; 0x0000FFB3 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 7 */
  } Bits;
} NVBACKKEY3STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY3_INIT @0x0000FFB3 = <NVBACKKEY3_INITVAL>; */
#define _NVBACKKEY3 (*(const NVBACKKEY3STR * __far)0x0000FFB3)
#define NVBACKKEY3                      _NVBACKKEY3.Byte
#define NVBACKKEY3_KEY0                 _NVBACKKEY3.Bits.KEY0
#define NVBACKKEY3_KEY1                 _NVBACKKEY3.Bits.KEY1
#define NVBACKKEY3_KEY2                 _NVBACKKEY3.Bits.KEY2
#define NVBACKKEY3_KEY3                 _NVBACKKEY3.Bits.KEY3
#define NVBACKKEY3_KEY4                 _NVBACKKEY3.Bits.KEY4
#define NVBACKKEY3_KEY5                 _NVBACKKEY3.Bits.KEY5
#define NVBACKKEY3_KEY6                 _NVBACKKEY3.Bits.KEY6
#define NVBACKKEY3_KEY7                 _NVBACKKEY3.Bits.KEY7

#define NVBACKKEY3_KEY0_MASK            1U
#define NVBACKKEY3_KEY1_MASK            2U
#define NVBACKKEY3_KEY2_MASK            4U
#define NVBACKKEY3_KEY3_MASK            8U
#define NVBACKKEY3_KEY4_MASK            16U
#define NVBACKKEY3_KEY5_MASK            32U
#define NVBACKKEY3_KEY6_MASK            64U
#define NVBACKKEY3_KEY7_MASK            128U


/*** NVBACKKEY4 - Backdoor Comparison Key 4; 0x0000FFB4 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 7 */
  } Bits;
} NVBACKKEY4STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY4_INIT @0x0000FFB4 = <NVBACKKEY4_INITVAL>; */
#define _NVBACKKEY4 (*(const NVBACKKEY4STR * __far)0x0000FFB4)
#define NVBACKKEY4                      _NVBACKKEY4.Byte
#define NVBACKKEY4_KEY0                 _NVBACKKEY4.Bits.KEY0
#define NVBACKKEY4_KEY1                 _NVBACKKEY4.Bits.KEY1
#define NVBACKKEY4_KEY2                 _NVBACKKEY4.Bits.KEY2
#define NVBACKKEY4_KEY3                 _NVBACKKEY4.Bits.KEY3
#define NVBACKKEY4_KEY4                 _NVBACKKEY4.Bits.KEY4
#define NVBACKKEY4_KEY5                 _NVBACKKEY4.Bits.KEY5
#define NVBACKKEY4_KEY6                 _NVBACKKEY4.Bits.KEY6
#define NVBACKKEY4_KEY7                 _NVBACKKEY4.Bits.KEY7

#define NVBACKKEY4_KEY0_MASK            1U
#define NVBACKKEY4_KEY1_MASK            2U
#define NVBACKKEY4_KEY2_MASK            4U
#define NVBACKKEY4_KEY3_MASK            8U
#define NVBACKKEY4_KEY4_MASK            16U
#define NVBACKKEY4_KEY5_MASK            32U
#define NVBACKKEY4_KEY6_MASK            64U
#define NVBACKKEY4_KEY7_MASK            128U


/*** NVBACKKEY5 - Backdoor Comparison Key 5; 0x0000FFB5 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 7 */
  } Bits;
} NVBACKKEY5STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY5_INIT @0x0000FFB5 = <NVBACKKEY5_INITVAL>; */
#define _NVBACKKEY5 (*(const NVBACKKEY5STR * __far)0x0000FFB5)
#define NVBACKKEY5                      _NVBACKKEY5.Byte
#define NVBACKKEY5_KEY0                 _NVBACKKEY5.Bits.KEY0
#define NVBACKKEY5_KEY1                 _NVBACKKEY5.Bits.KEY1
#define NVBACKKEY5_KEY2                 _NVBACKKEY5.Bits.KEY2
#define NVBACKKEY5_KEY3                 _NVBACKKEY5.Bits.KEY3
#define NVBACKKEY5_KEY4                 _NVBACKKEY5.Bits.KEY4
#define NVBACKKEY5_KEY5                 _NVBACKKEY5.Bits.KEY5
#define NVBACKKEY5_KEY6                 _NVBACKKEY5.Bits.KEY6
#define NVBACKKEY5_KEY7                 _NVBACKKEY5.Bits.KEY7

#define NVBACKKEY5_KEY0_MASK            1U
#define NVBACKKEY5_KEY1_MASK            2U
#define NVBACKKEY5_KEY2_MASK            4U
#define NVBACKKEY5_KEY3_MASK            8U
#define NVBACKKEY5_KEY4_MASK            16U
#define NVBACKKEY5_KEY5_MASK            32U
#define NVBACKKEY5_KEY6_MASK            64U
#define NVBACKKEY5_KEY7_MASK            128U


/*** NVBACKKEY6 - Backdoor Comparison Key 6; 0x0000FFB6 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 7 */
  } Bits;
} NVBACKKEY6STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY6_INIT @0x0000FFB6 = <NVBACKKEY6_INITVAL>; */
#define _NVBACKKEY6 (*(const NVBACKKEY6STR * __far)0x0000FFB6)
#define NVBACKKEY6                      _NVBACKKEY6.Byte
#define NVBACKKEY6_KEY0                 _NVBACKKEY6.Bits.KEY0
#define NVBACKKEY6_KEY1                 _NVBACKKEY6.Bits.KEY1
#define NVBACKKEY6_KEY2                 _NVBACKKEY6.Bits.KEY2
#define NVBACKKEY6_KEY3                 _NVBACKKEY6.Bits.KEY3
#define NVBACKKEY6_KEY4                 _NVBACKKEY6.Bits.KEY4
#define NVBACKKEY6_KEY5                 _NVBACKKEY6.Bits.KEY5
#define NVBACKKEY6_KEY6                 _NVBACKKEY6.Bits.KEY6
#define NVBACKKEY6_KEY7                 _NVBACKKEY6.Bits.KEY7

#define NVBACKKEY6_KEY0_MASK            1U
#define NVBACKKEY6_KEY1_MASK            2U
#define NVBACKKEY6_KEY2_MASK            4U
#define NVBACKKEY6_KEY3_MASK            8U
#define NVBACKKEY6_KEY4_MASK            16U
#define NVBACKKEY6_KEY5_MASK            32U
#define NVBACKKEY6_KEY6_MASK            64U
#define NVBACKKEY6_KEY7_MASK            128U


/*** NVBACKKEY7 - Backdoor Comparison Key 7; 0x0000FFB7 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 7 */
  } Bits;
} NVBACKKEY7STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY7_INIT @0x0000FFB7 = <NVBACKKEY7_INITVAL>; */
#define _NVBACKKEY7 (*(const NVBACKKEY7STR * __far)0x0000FFB7)
#define NVBACKKEY7                      _NVBACKKEY7.Byte
#define NVBACKKEY7_KEY0                 _NVBACKKEY7.Bits.KEY0
#define NVBACKKEY7_KEY1                 _NVBACKKEY7.Bits.KEY1
#define NVBACKKEY7_KEY2                 _NVBACKKEY7.Bits.KEY2
#define NVBACKKEY7_KEY3                 _NVBACKKEY7.Bits.KEY3
#define NVBACKKEY7_KEY4                 _NVBACKKEY7.Bits.KEY4
#define NVBACKKEY7_KEY5                 _NVBACKKEY7.Bits.KEY5
#define NVBACKKEY7_KEY6                 _NVBACKKEY7.Bits.KEY6
#define NVBACKKEY7_KEY7                 _NVBACKKEY7.Bits.KEY7

#define NVBACKKEY7_KEY0_MASK            1U
#define NVBACKKEY7_KEY1_MASK            2U
#define NVBACKKEY7_KEY2_MASK            4U
#define NVBACKKEY7_KEY3_MASK            8U
#define NVBACKKEY7_KEY4_MASK            16U
#define NVBACKKEY7_KEY5_MASK            32U
#define NVBACKKEY7_KEY6_MASK            64U
#define NVBACKKEY7_KEY7_MASK            128U


/*** NVPROT - Nonvolatile FLASH Protection Register; 0x0000FFBD ***/
typedef union {
  byte Byte;
  struct {
    byte FPDIS       :1;                                       /* FLASH Protection Disable */
    byte FPS1        :1;                                       /* FLASH Protect Select Bit 1 */
    byte FPS2        :1;                                       /* FLASH Protect Select Bit 2 */
    byte FPS3        :1;                                       /* FLASH Protect Select Bit 3 */
    byte FPS4        :1;                                       /* FLASH Protect Select Bit 4 */
    byte FPS5        :1;                                       /* FLASH Protect Select Bit 5 */
    byte FPS6        :1;                                       /* FLASH Protect Select Bit 6 */
    byte FPS7        :1;                                       /* FLASH Protect Select Bit 7 */
  } Bits;
  struct {
    byte         :1;
    byte grpFPS_1 :7;
  } MergedBits;
} NVPROTSTR;
/* Tip for register initialization in the user code:  const byte NVPROT_INIT @0x0000FFBD = <NVPROT_INITVAL>; */
#define _NVPROT (*(const NVPROTSTR * __far)0x0000FFBD)
#define NVPROT                          _NVPROT.Byte
#define NVPROT_FPDIS                    _NVPROT.Bits.FPDIS
#define NVPROT_FPS1                     _NVPROT.Bits.FPS1
#define NVPROT_FPS2                     _NVPROT.Bits.FPS2
#define NVPROT_FPS3                     _NVPROT.Bits.FPS3
#define NVPROT_FPS4                     _NVPROT.Bits.FPS4
#define NVPROT_FPS5                     _NVPROT.Bits.FPS5
#define NVPROT_FPS6                     _NVPROT.Bits.FPS6
#define NVPROT_FPS7                     _NVPROT.Bits.FPS7
#define NVPROT_FPS_1                    _NVPROT.MergedBits.grpFPS_1
#define NVPROT_FPS                      NVPROT_FPS_1

#define NVPROT_FPDIS_MASK               1U
#define NVPROT_FPS1_MASK                2U
#define NVPROT_FPS2_MASK                4U
#define NVPROT_FPS3_MASK                8U
#define NVPROT_FPS4_MASK                16U
#define NVPROT_FPS5_MASK                32U
#define NVPROT_FPS6_MASK                64U
#define NVPROT_FPS7_MASK                128U
#define NVPROT_FPS_1_MASK               254U
#define NVPROT_FPS_1_BITNUM             1U


/*** NVOPT - Nonvolatile Flash Options Register; 0x0000FFBF ***/
typedef union {
  byte Byte;
  struct {
    byte SEC00       :1;                                       /* Security State Code, bit 0 */
    byte SEC01       :1;                                       /* Security State Code, bit 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte FNORED      :1;                                       /* Vector Redirection Disable */
    byte KEYEN       :1;                                       /* Backdoor Key Mechanism Enable */
  } Bits;
  struct {
    byte grpSEC0 :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} NVOPTSTR;
/* Tip for register initialization in the user code:  const byte NVOPT_INIT @0x0000FFBF = <NVOPT_INITVAL>; */
#define _NVOPT (*(const NVOPTSTR * __far)0x0000FFBF)
#define NVOPT                           _NVOPT.Byte
#define NVOPT_SEC00                     _NVOPT.Bits.SEC00
#define NVOPT_SEC01                     _NVOPT.Bits.SEC01
#define NVOPT_FNORED                    _NVOPT.Bits.FNORED
#define NVOPT_KEYEN                     _NVOPT.Bits.KEYEN
#define NVOPT_SEC0                      _NVOPT.MergedBits.grpSEC0

#define NVOPT_SEC00_MASK                1U
#define NVOPT_SEC01_MASK                2U
#define NVOPT_FNORED_MASK               64U
#define NVOPT_KEYEN_MASK                128U
#define NVOPT_SEC0_MASK                 3U
#define NVOPT_SEC0_BITNUM               0U



/* Flash commands */
#define mBlank                          0x05
#define mBurstProg                      0x25
#define mByteProg                       0x20
#define mMassErase                      0x41
#define mPageErase                      0x40


/***********************************************/
/**   D E P R E C I A T E D   S Y M B O L S   **/
/***********************************************/
/* --------------------------------------------------------------------------- */
/* The following symbols were removed, because they were invalid or irrelevant */
/* --------------------------------------------------------------------------- */



/* **** 7.4.2009 10:12:07 */

#define IPMPS_IPM                        This_symb_has_been_depreciated
#define ILRS0_ILR                        This_symb_has_been_depreciated
#define ILRS1_ILR                        This_symb_has_been_depreciated
#define ILRS2_ILR1                       This_symb_has_been_depreciated
#define ILRS3_ILR1                       This_symb_has_been_depreciated
#define ILRS5_ILR2                       This_symb_has_been_depreciated
#define ILRS6_ILR2                       This_symb_has_been_depreciated
#define ILRS7_ILR3                       This_symb_has_been_depreciated
#endif
/*lint -restore  +esym(961,18.4) +esym(961,19.7) Enable MISRA rule (1.1,18.4,6.4,19.7) checking. */
