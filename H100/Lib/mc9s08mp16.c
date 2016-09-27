/* Based on CPU DB MC9S08MP16_48, version 3.00.021 (RegistersPrg V2.32) */
/* DataSheet : MC9S08MP16 Rev. 1 09/2009 */

#include <mc9s08mp16.h>

/*lint -save -esym(765, *) */


/* * * * *  8-BIT REGISTERS  * * * * * * * * * * * * * * * */
volatile PTADSTR _PTAD;                                    /* Port A Data Register; 0x00000000 */
volatile PTADDSTR _PTADD;                                  /* Port A Data Direction Register; 0x00000001 */
volatile PTBDSTR _PTBD;                                    /* Port B Data Register; 0x00000002 */
volatile PTBDDSTR _PTBDD;                                  /* Port B Data Direction Register; 0x00000003 */
volatile PTCDSTR _PTCD;                                    /* Port C Data Register; 0x00000004 */
volatile PTCDDSTR _PTCDD;                                  /* Port C Data Direction Register; 0x00000005 */
volatile PTDDSTR _PTDD;                                    /* Port D Data Register; 0x00000006 */
volatile PTDDDSTR _PTDDD;                                  /* Port D Data Direction Register; 0x00000007 */
volatile PTEDSTR _PTED;                                    /* Port E Data Register; 0x00000008 */
volatile PTEDDSTR _PTEDD;                                  /* Port E Data Direction Register; 0x00000009 */
volatile PTFDSTR _PTFD;                                    /* Port F Data Register; 0x0000000A */
volatile PTFDDSTR _PTFDD;                                  /* Port F Data Direction Register; 0x0000000B */
volatile KBI1SCSTR _KBI1SC;                                /* KBI1 Status and Control Register; 0x0000000C */
volatile KBI1PESTR _KBI1PE;                                /* KBI1 Pin Enable Register; 0x0000000D */
volatile KBI1ESSTR _KBI1ES;                                /* KBI1 Edge Select Register; 0x0000000E */
volatile ADCSC1STR _ADCSC1;                                /* Status and Control Register 1; 0x00000010 */
volatile ADCSC2STR _ADCSC2;                                /* Status and Control Register 2; 0x00000011 */
volatile ADCCFGSTR _ADCCFG;                                /* Configuration Register; 0x00000016 */
volatile APCTL1STR _APCTL1;                                /* Pin Control 1 Register; 0x00000017 */
volatile APCTL2STR _APCTL2;                                /* Pin Control 2 Register; 0x00000018 */
volatile DAC1CTRLSTR _DAC1CTRL;                            /* DAC Control Register; 0x00000019 */
volatile DAC2CTRLSTR _DAC2CTRL;                            /* DAC Control Register; 0x0000001A */
volatile DAC3CTRLSTR _DAC3CTRL;                            /* DAC Control Register; 0x0000001B */
volatile KBI2SCSTR _KBI2SC;                                /* KBI2 Status and Control Register; 0x0000001C */
volatile KBI2PESTR _KBI2PE;                                /* KBI2 Pin Enable Register; 0x0000001D */
volatile KBI2ESSTR _KBI2ES;                                /* KBI2 Edge Select Register; 0x0000001E */
volatile IICA1STR _IICA1;                                  /* IIC Address Register; 0x00000020 */
volatile IICFSTR _IICF;                                    /* IIC Frequency Divider Register; 0x00000021 */
volatile IICC1STR _IICC1;                                  /* IIC Control Register 1; 0x00000022 */
volatile IICSSTR _IICS;                                    /* IIC Status Register; 0x00000023 */
volatile IICDSTR _IICD;                                    /* IIC Data I/O Register; 0x00000024 */
volatile IICC2STR _IICC2;                                  /* IIC Control Register 2; 0x00000025 */
volatile IICSMBSTR _IICSMB;                                /* SMBus Control and Status Register; 0x00000026 */
volatile IICA2STR _IICA2;                                  /* IIC Address Register 2; 0x00000027 */
volatile IICFLTSTR _IICFLT;                                /* IIC Filter register; 0x0000002A */
volatile KBI3SCSTR _KBI3SC;                                /* KBI3 Status and Control Register; 0x0000002C */
volatile KBI3PESTR _KBI3PE;                                /* KBI3 Pin Enable Register; 0x0000002D */
volatile KBI3ESSTR _KBI3ES;                                /* KBI3 Edge Select Register; 0x0000002E */
volatile FTM1SCSTR _FTM1SC;                                /* FTM1 Status and Control Register; 0x00000030 */
volatile FTM1C0SCSTR _FTM1C0SC;                            /* FTM1 Timer Channel 0 Status and Control Register; 0x00000035 */
volatile FTM1C1SCSTR _FTM1C1SC;                            /* FTM1 Timer Channel 1 Status and Control Register; 0x00000038 */
volatile ICSC1STR _ICSC1;                                  /* ICS Control Register 1; 0x0000003C */
volatile ICSC2STR _ICSC2;                                  /* ICS Control Register 2; 0x0000003D */
volatile ICSTRMSTR _ICSTRM;                                /* ICS Trim Register; 0x0000003E */
volatile ICSSCSTR _ICSSC;                                  /* ICS Status and Control Register; 0x0000003F */
volatile FTM1STATUSSTR _FTM1STATUS;                        /* FTM1 Capture and Compare Status Register; 0x00000042 */
volatile FTM1MODESTR _FTM1MODE;                            /* FTM1 Features Mode Selection Register; 0x00000043 */
volatile FTM1SYNCSTR _FTM1SYNC;                            /* FTM1 Synchronization Register; 0x00000044 */
volatile FTM1OUTINITSTR _FTM1OUTINIT;                      /* FTM1 Initial State for Channels Output Register; 0x00000045 */
volatile FTM1OUTMASKSTR _FTM1OUTMASK;                      /* FTM1 Output Mask Register; 0x00000046 */
volatile FTM1COMBINE0STR _FTM1COMBINE0;                    /* FTM1 Function For Linked Channel 0 Register; 0x00000047 */
volatile FTM1DEADTIMESTR _FTM1DEADTIME;                    /* FTM1 Deadtime Insertion Control Register; 0x0000004B */
volatile FTM1EXTTRIGSTR _FTM1EXTTRIG;                      /* FTM1 ExternalTrigger Register; 0x0000004C */
volatile FTM1POLSTR _FTM1POL;                              /* FTM1 Channels Polarity Register; 0x0000004D */
volatile FTM1FMSSTR _FTM1FMS;                              /* FTM1 Fault Mode Status Register; 0x0000004E */
volatile FTM1FILTER0STR _FTM1FILTER0;                      /* FTM1 Input Capture Filter Control Register 0; 0x0000004F */
volatile FTM1FLTFILTERSTR _FTM1FLTFILTER;                  /* FTM1 Fault Input Filter Control Register; 0x00000051 */
volatile FTM1FLTCTRLSTR _FTM1FLTCTRL;                      /* FTM1 Fault Control Register; 0x00000052 */
volatile MTIMSCSTR _MTIMSC;                                /* MTIM Clock Configuration Register; 0x00000054 */
volatile MTIMCLKSTR _MTIMCLK;                              /* MTIM Clock Configuration Register; 0x00000055 */
volatile MTIMCNTSTR _MTIMCNT;                              /* MTIM Counter Register; 0x00000056 */
volatile MTIMMODSTR _MTIMMOD;                              /* MTIM Modulo Register; 0x00000057 */
volatile SPIC1STR _SPIC1;                                  /* SPI Control Register 1; 0x00000058 */
volatile SPIC2STR _SPIC2;                                  /* SPI Control Register 2; 0x00000059 */
volatile SPIBRSTR _SPIBR;                                  /* SPI Baud Rate Register; 0x0000005A */
volatile SPISSTR _SPIS;                                    /* SPI Status Register; 0x0000005B */
volatile SPIDSTR _SPID;                                    /* SPI Data Register; 0x0000005D */
volatile IPCSCSTR _IPCSC;                                  /* IPC Status and Control Register; 0x0000005E */
volatile IPMPSSTR _IPMPS;                                  /* Interrupt Priority Mask Pseudo Stack Register; 0x0000005F */
volatile ILRS0STR _ILRS0;                                  /* Interrupt Level Setting Register; 0x00000060 */
volatile ILRS1STR _ILRS1;                                  /* Interrupt Level Setting Register; 0x00000061 */
volatile ILRS2STR _ILRS2;                                  /* Interrupt Level Setting Register; 0x00000062 */
volatile ILRS3STR _ILRS3;                                  /* Interrupt Level Setting Register; 0x00000063 */
volatile ILRS4STR _ILRS4;                                  /* Interrupt Level Setting Register; 0x00000064 */
volatile ILRS5STR _ILRS5;                                  /* Interrupt Level Setting Register; 0x00000065 */
volatile ILRS6STR _ILRS6;                                  /* Interrupt Level Setting Register; 0x00000066 */
volatile ILRS7STR _ILRS7;                                  /* Interrupt Level Setting Register; 0x00000067 */
volatile SCIC1STR _SCIC1;                                  /* SCI Control Register 1; 0x0000006A */
volatile SCIC2STR _SCIC2;                                  /* SCI Control Register 2; 0x0000006B */
volatile SCIS1STR _SCIS1;                                  /* SCI Status Register 1; 0x0000006C */
volatile SCIS2STR _SCIS2;                                  /* SCI Status Register 2; 0x0000006D */
volatile SCIC3STR _SCIC3;                                  /* SCI Control Register 3; 0x0000006E */
volatile SCIDSTR _SCID;                                    /* SCI Data Register; 0x0000006F */
volatile PDB1CTRL1STR _PDB1CTRL1;                          /* PDB1 Control 1 Register; 0x00000070 */
volatile PDB1CTRL2STR _PDB1CTRL2;                          /* PDB1 Control 2 Register; 0x00000071 */
volatile PDB1SCRSTR _PDB1SCR;                              /* PDB1 Status Register; 0x0000007A */
volatile CRCHSTR _CRCH;                                    /* CRC High Register; 0x0000007C */
volatile CRCLSTR _CRCL;                                    /* CRC Low Register; 0x0000007D */
volatile TRANSPOSESTR _TRANSPOSE;                          /* CRC Transpose Register; 0x0000007E */
volatile PDB2CTRL1STR _PDB2CTRL1;                          /* PDB2 Control 1 Register; 0x00000080 */
volatile PDB2CTRL2STR _PDB2CTRL2;                          /* PDB2 Control 2 Register; 0x00000081 */
volatile PDB2SCRSTR _PDB2SCR;                              /* PDB2 Status Register; 0x0000008A */
volatile RTCSCSTR _RTCSC;                                  /* RTC Status and Control Register; 0x0000008C */
volatile RTCCNTSTR _RTCCNT;                                /* RTC Counter Register; 0x0000008D */
volatile RTCMODSTR _RTCMOD;                                /* RTC Modulo Register; 0x0000008E */
volatile SRSSTR _SRS;                                      /* System Reset Status Register; 0x00001800 */
volatile SBDFRSTR _SBDFR;                                  /* System Background Debug Force Reset Register; 0x00001801 */
volatile SOPT1STR _SOPT1;                                  /* System Options Register 1; 0x00001802 */
volatile SOPT2STR _SOPT2;                                  /* System Options Register 2; 0x00001803 */
volatile SPMSC1STR _SPMSC1;                                /* System Power Management Status and Control 1 Register; 0x00001809 */
volatile SPMSC2STR _SPMSC2;                                /* System Power Management Status and Control 2 Register; 0x0000180A */
volatile SOPT3STR _SOPT3;                                  /* System Options Register 3; 0x0000180B */
volatile SCGC1STR _SCGC1;                                  /* System Clock Gating Control 1 Register; 0x0000180E */
volatile SCGC2STR _SCGC2;                                  /* System Clock Gating Control 2 Register; 0x0000180F */
volatile DBGCAXSTR _DBGCAX;                                /* Debug Comparator A Extension Register; 0x00001818 */
volatile DBGCBXSTR _DBGCBX;                                /* Debug Comparator B Extension Register; 0x00001819 */
volatile DBGCCXSTR _DBGCCX;                                /* Debug Comparator C Extension Register; 0x0000181A */
volatile DBGCSTR _DBGC;                                    /* Debug Control Register; 0x0000181C */
volatile DBGTSTR _DBGT;                                    /* Debug Trigger Register; 0x0000181D */
volatile DBGSSTR _DBGS;                                    /* Debug Status Register; 0x0000181E */
volatile DBGCNTSTR _DBGCNT;                                /* Debug Count Status Register; 0x0000181F */
volatile FCDIVSTR _FCDIV;                                  /* FLASH Clock Divider Register; 0x00001820 */
volatile FOPTSTR _FOPT;                                    /* FLASH Options Register; 0x00001821 */
volatile FCNFGSTR _FCNFG;                                  /* FLASH Configuration Register; 0x00001823 */
volatile FPROTSTR _FPROT;                                  /* FLASH Protection Register; 0x00001824 */
volatile FSTATSTR _FSTAT;                                  /* Flash Status Register; 0x00001825 */
volatile FCMDSTR _FCMD;                                    /* FLASH Command Register; 0x00001826 */
volatile PTAPESTR _PTAPE;                                  /* Port A Pull Enable Register; 0x00001840 */
volatile PTASESTR _PTASE;                                  /* Port A Slew Rate Enable Register; 0x00001841 */
volatile PTADSSTR _PTADS;                                  /* Port A Drive Strength Selection Register; 0x00001842 */
volatile PTBPESTR _PTBPE;                                  /* Port B Pull Enable Register; 0x00001844 */
volatile PTBSESTR _PTBSE;                                  /* Port B Slew Rate Enable Register; 0x00001845 */
volatile PTBDSSTR _PTBDS;                                  /* Port B Drive Strength Selection Register; 0x00001846 */
volatile PTCPESTR _PTCPE;                                  /* Port C Pull Enable Register; 0x00001848 */
volatile PTCSESTR _PTCSE;                                  /* Port C Slew Rate Enable Register; 0x00001849 */
volatile PTCDSSTR _PTCDS;                                  /* Port C Drive Strength Selection Register; 0x0000184A */
volatile PTDPESTR _PTDPE;                                  /* Port D Pull Enable Register; 0x0000184C */
volatile PTDSESTR _PTDSE;                                  /* Port D Slew Rate Enable Register; 0x0000184D */
volatile PTDDSSTR _PTDDS;                                  /* Port D Drive Strength Selection Register; 0x0000184E */
volatile PTEPESTR _PTEPE;                                  /* Port E Pull Enable Register; 0x00001850 */
volatile PTESESTR _PTESE;                                  /* Port E Slew Rate Enable Register; 0x00001851 */
volatile PTEDSSTR _PTEDS;                                  /* Port E Drive Strength Selection Register; 0x00001852 */
volatile PTFPESTR _PTFPE;                                  /* Port F Pull Enable Register; 0x00001854 */
volatile PTFSESTR _PTFSE;                                  /* Port F Slew Rate Enable Register; 0x00001855 */
volatile PTFDSSTR _PTFDS;                                  /* Port F Drive Strength Selection Register; 0x00001856 */
volatile HSCMP1CR0STR _HSCMP1CR0;                          /* HSCMP1 Control Register 0; 0x00001860 */
volatile HSCMP1CR1STR _HSCMP1CR1;                          /* HSCMP1 Control Register 1; 0x00001861 */
volatile HSCMP1FPRSTR _HSCMP1FPR;                          /* HSCMP1 Filter Period Register; 0x00001862 */
volatile HSCMP1SCRSTR _HSCMP1SCR;                          /* HSCMP1 Status & Control Register; 0x00001863 */
volatile HSCMP1PCRSTR _HSCMP1PCR;                          /* Pin Control Register; 0x00001864 */
volatile HSCMP2CR0STR _HSCMP2CR0;                          /* HSCMP2 Control Register 0; 0x00001868 */
volatile HSCMP2CR1STR _HSCMP2CR1;                          /* HSCMP2 Control Register 1; 0x00001869 */
volatile HSCMP2FPRSTR _HSCMP2FPR;                          /* HSCMP2 Filter Period Register; 0x0000186A */
volatile HSCMP2SCRSTR _HSCMP2SCR;                          /* HSCMP2 Status & Control Register; 0x0000186B */
volatile HSCMP2PCRSTR _HSCMP2PCR;                          /* Pin Control Register; 0x0000186C */
volatile HSCMP3CR0STR _HSCMP3CR0;                          /* HSCMP3 Control Register 0; 0x00001870 */
volatile HSCMP3CR1STR _HSCMP3CR1;                          /* HSCMP3 Control Register 1; 0x00001871 */
volatile HSCMP3FPRSTR _HSCMP3FPR;                          /* HSCMP3 Filter Period Register; 0x00001872 */
volatile HSCMP3SCRSTR _HSCMP3SCR;                          /* HSCMP3 Status & Control Register; 0x00001873 */
volatile HSCMP3PCRSTR _HSCMP3PCR;                          /* Pin Control Register; 0x00001874 */
volatile PGACNTL0STR _PGACNTL0;                            /* PGA Control Register 0; 0x00001878 */
volatile PGACNTL1STR _PGACNTL1;                            /* PGA Control Register 1; 0x00001879 */
volatile PGACNTL2STR _PGACNTL2;                            /* PGA Control Register 2; 0x0000187A */
volatile PGASTSSTR _PGASTS;                                /* PGA Status Register; 0x0000187B */
volatile FTM2SCSTR _FTM2SC;                                /* FTM2 Status and Control Register; 0x00001880 */
volatile FTM2C0SCSTR _FTM2C0SC;                            /* FTM2 Timer Channel 0 Status and Control Register; 0x00001885 */
volatile FTM2C1SCSTR _FTM2C1SC;                            /* FTM2 Timer Channel 1 Status and Control Register; 0x00001888 */
volatile FTM2C2SCSTR _FTM2C2SC;                            /* FTM2 Timer Channel 2 Status and Control Register; 0x0000188B */
volatile FTM2C3SCSTR _FTM2C3SC;                            /* FTM2 Timer Channel 3 Status and Control Register; 0x0000188E */
volatile FTM2C4SCSTR _FTM2C4SC;                            /* FTM2 Timer Channel 4 Status and Control Register; 0x00001891 */
volatile FTM2C5SCSTR _FTM2C5SC;                            /* FTM2 Timer Channel 5 Status and Control Register; 0x00001894 */
volatile FTM2STATUSSTR _FTM2STATUS;                        /* FTM2 Capture and Compare Status Register; 0x000018A2 */
volatile FTM2MODESTR _FTM2MODE;                            /* FTM2 Features Mode Selection Register; 0x000018A3 */
volatile FTM2SYNCSTR _FTM2SYNC;                            /* FTM2 Synchronization Register; 0x000018A4 */
volatile FTM2OUTINITSTR _FTM2OUTINIT;                      /* FTM2 Initial State for Channels Output Register; 0x000018A5 */
volatile FTM2OUTMASKSTR _FTM2OUTMASK;                      /* FTM2 Output Mask Register; 0x000018A6 */
volatile FTM2COMBINE0STR _FTM2COMBINE0;                    /* FTM2 Function For Linked Channel 0 Register; 0x000018A7 */
volatile FTM2COMBINE1STR _FTM2COMBINE1;                    /* FTM2 Function For Linked Channel 1 Register; 0x000018A8 */
volatile FTM2COMBINE2STR _FTM2COMBINE2;                    /* FTM2 Function For Linked Channel 2 Register; 0x000018A9 */
volatile FTM2DEADTIMESTR _FTM2DEADTIME;                    /* FTM2 Deadtime Insertion Control Register; 0x000018AB */
volatile FTM2EXTTRIGSTR _FTM2EXTTRIG;                      /* FTM2 ExternalTrigger Register; 0x000018AC */
volatile FTM2POLSTR _FTM2POL;                              /* FTM2 Channels Polarity Register; 0x000018AD */
volatile FTM2FMSSTR _FTM2FMS;                              /* FTM2 Fault Mode Status Register; 0x000018AE */
volatile FTM2FILTER0STR _FTM2FILTER0;                      /* FTM2 Input Capture Filter Control Register 0; 0x000018AF */
volatile FTM2FILTER1STR _FTM2FILTER1;                      /* FTM2 Input Capture Filter Control Register 1; 0x000018B0 */
volatile FTM2FLTFILTERSTR _FTM2FLTFILTER;                  /* FTM2 Fault Input Filter Control Register; 0x000018B1 */
volatile FTM2FLTCTRLSTR _FTM2FLTCTRL;                      /* FTM2 Fault Control Register; 0x000018B2 */
/* NVFTRIM - macro for reading non volatile register       Nonvolatile ICS Fine Trim; 0x0000FFAE */
/* Tip for register initialization in the user code:  const byte NVFTRIM_INIT @0x0000FFAE = <NVFTRIM_INITVAL>; */
/* NVICSTRM - macro for reading non volatile register      Nonvolatile ICS Trim Register; 0x0000FFAF */
/* Tip for register initialization in the user code:  const byte NVICSTRM_INIT @0x0000FFAF = <NVICSTRM_INITVAL>; */
/* NVBACKKEY0 - macro for reading non volatile register    Backdoor Comparison Key 0; 0x0000FFB0 */
/* Tip for register initialization in the user code:  const byte NVBACKKEY0_INIT @0x0000FFB0 = <NVBACKKEY0_INITVAL>; */
/* NVBACKKEY1 - macro for reading non volatile register    Backdoor Comparison Key 1; 0x0000FFB1 */
/* Tip for register initialization in the user code:  const byte NVBACKKEY1_INIT @0x0000FFB1 = <NVBACKKEY1_INITVAL>; */
/* NVBACKKEY2 - macro for reading non volatile register    Backdoor Comparison Key 2; 0x0000FFB2 */
/* Tip for register initialization in the user code:  const byte NVBACKKEY2_INIT @0x0000FFB2 = <NVBACKKEY2_INITVAL>; */
/* NVBACKKEY3 - macro for reading non volatile register    Backdoor Comparison Key 3; 0x0000FFB3 */
/* Tip for register initialization in the user code:  const byte NVBACKKEY3_INIT @0x0000FFB3 = <NVBACKKEY3_INITVAL>; */
/* NVBACKKEY4 - macro for reading non volatile register    Backdoor Comparison Key 4; 0x0000FFB4 */
/* Tip for register initialization in the user code:  const byte NVBACKKEY4_INIT @0x0000FFB4 = <NVBACKKEY4_INITVAL>; */
/* NVBACKKEY5 - macro for reading non volatile register    Backdoor Comparison Key 5; 0x0000FFB5 */
/* Tip for register initialization in the user code:  const byte NVBACKKEY5_INIT @0x0000FFB5 = <NVBACKKEY5_INITVAL>; */
/* NVBACKKEY6 - macro for reading non volatile register    Backdoor Comparison Key 6; 0x0000FFB6 */
/* Tip for register initialization in the user code:  const byte NVBACKKEY6_INIT @0x0000FFB6 = <NVBACKKEY6_INITVAL>; */
/* NVBACKKEY7 - macro for reading non volatile register    Backdoor Comparison Key 7; 0x0000FFB7 */
/* Tip for register initialization in the user code:  const byte NVBACKKEY7_INIT @0x0000FFB7 = <NVBACKKEY7_INITVAL>; */
/* NVPROT - macro for reading non volatile register        Nonvolatile FLASH Protection Register; 0x0000FFBD */
/* Tip for register initialization in the user code:  const byte NVPROT_INIT @0x0000FFBD = <NVPROT_INITVAL>; */
/* NVOPT - macro for reading non volatile register         Nonvolatile Flash Options Register; 0x0000FFBF */
/* Tip for register initialization in the user code:  const byte NVOPT_INIT @0x0000FFBF = <NVOPT_INITVAL>; */


/* * * * *  16-BIT REGISTERS  * * * * * * * * * * * * * * * */
volatile ADCRSTR _ADCR;                                    /* Data Result Register; 0x00000012 */
volatile ADCCVSTR _ADCCV;                                  /* Compare Value Register; 0x00000014 */
volatile IICSLTSTR _IICSLT;                                /* IIC SCL Low Time Out register; 0x00000028 */
volatile FTM1CNTSTR _FTM1CNT;                              /* FTM1 Timer Counter Register; 0x00000031 */
volatile FTM1MODSTR _FTM1MOD;                              /* FTM1 Timer Counter Modulo Register; 0x00000033 */
volatile FTM1C0VSTR _FTM1C0V;                              /* FTM1 Timer Channel 0 Value Register; 0x00000036 */
volatile FTM1C1VSTR _FTM1C1V;                              /* FTM1 Timer Channel 1 Value Register; 0x00000039 */
volatile FTM1CNTINSTR _FTM1CNTIN;                          /* FTM1 Counter Initial Value Registers; 0x00000040 */
volatile SCIBDSTR _SCIBD;                                  /* SCI Baud Rate Register; 0x00000068 */
volatile PDB1DLYASTR _PDB1DLYA;                            /* PDB1 Delay A Register; 0x00000072 */
volatile PDB1DLYBSTR _PDB1DLYB;                            /* PDB1 Delay B Register; 0x00000074 */
volatile PDB1MODSTR _PDB1MOD;                              /* PDB1 Counter Modulus Register; 0x00000076 */
volatile PDB1CNTSTR _PDB1CNT;                              /* PDB1 Counter Value Register; 0x00000078 */
volatile PDB2DLYASTR _PDB2DLYA;                            /* PDB2 Delay A Register; 0x00000082 */
volatile PDB2DLYBSTR _PDB2DLYB;                            /* PDB2 Delay B Register; 0x00000084 */
volatile PDB2MODSTR _PDB2MOD;                              /* PDB2 Counter Modulus Register; 0x00000086 */
volatile PDB2CNTSTR _PDB2CNT;                              /* PDB2 Counter Value Register; 0x00000088 */
volatile SDIDSTR _SDID;                                    /* System Device Identification Register; 0x00001806 */
volatile DBGCASTR _DBGCA;                                  /* Debug Comparator A Register; 0x00001810 */
volatile DBGCBSTR _DBGCB;                                  /* Debug Comparator B Register; 0x00001812 */
volatile DBGCCSTR _DBGCC;                                  /* Debug Comparator C Register; 0x00001814 */
volatile DBGFSTR _DBGF;                                    /* Debug FIFO Register; 0x00001816 */
volatile FTM2CNTSTR _FTM2CNT;                              /* FTM2 Timer Counter Register; 0x00001881 */
volatile FTM2MODSTR _FTM2MOD;                              /* FTM2 Timer Counter Modulo Register; 0x00001883 */
volatile FTM2C0VSTR _FTM2C0V;                              /* FTM2 Timer Channel 0 Value Register; 0x00001886 */
volatile FTM2C1VSTR _FTM2C1V;                              /* FTM2 Timer Channel 1 Value Register; 0x00001889 */
volatile FTM2C2VSTR _FTM2C2V;                              /* FTM2 Timer Channel 2 Value Register; 0x0000188C */
volatile FTM2C3VSTR _FTM2C3V;                              /* FTM2 Timer Channel 3 Value Register; 0x0000188F */
volatile FTM2C4VSTR _FTM2C4V;                              /* FTM2 Timer Channel 4 Value Register; 0x00001892 */
volatile FTM2C5VSTR _FTM2C5V;                              /* FTM2 Timer Channel 5 Value Register; 0x00001895 */
volatile FTM2CNTINSTR _FTM2CNTIN;                          /* FTM2 Counter Initial Value Registers; 0x000018A0 */

/*lint -restore */

/* EOF */
