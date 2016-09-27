
	XDEF _Startup

ZERO: EQU $0000

	org $C000
	DC.B $76, $CE, $00, $00, $00, $00, $00, $00
	DC.B $1B, $6D, $00, $96, $46, $00, $00, $02
	DC.B $00, $00, $00, $00, $05, $00, $05, $CC
	DC.B $07, $00, $07, $66, $07, $CC, $19, $00
	DC.B $1C, $00, $1F, $00, $25, $00, $28, $00
	DC.B $00, $00, $05, $00, $05, $CC, $07, $00
	DC.B $07, $66, $07, $CC, $19, $00, $1C, $00
	DC.B $1F, $00, $25, $00, $28, $00, $00, $00
	DC.B $05, $00, $05, $CC, $07, $00, $07, $66
	DC.B $07, $CC, $19, $00, $1C, $00, $1F, $00
	DC.B $25, $00, $28, $00, $00, $00, $05, $00
	DC.B $05, $CC, $07, $00, $07, $66, $07, $CC
	DC.B $19, $00, $1C, $00, $1F, $00, $25, $00
	DC.B $28, $00, $00, $FF, $05, $00, $05, $CC
	DC.B $07, $00, $07, $66, $07, $CC, $19, $00
	DC.B $1C, $00, $1F, $00, $25, $00, $28, $00


	org $C400 
	PSHH   
	BGND   
	PULH   
	RTI    
	PSHH   
	PSHA   
	TPA    
	SEI    
	STA    $90
	PULA   
	LDA    #$1E
	TSX    
	STA    ,X
	BRA    *+46       ;abs = $C43D
	TSX    
	LDX    ,X
	LDA    #$03
	MUL    
	CLRH   
	TAX    
	LDA    #$CC
	STA    1075,X
	LDA    1,SP
	LSLA   
	PSHA   
	CLRA   
	ROLA   
	PSHA   
	PULH   
	PSHX   
	LDX    2,SP
	LDHX   63424,X
	PSHH   
	PULA   
	STA    2,SP
	CLRH   
	TXA    
	PULX   
	STA    1077,X
	PULA   
	STA    1076,X
	TSX    
	LDA    ,X
	TAX    
	DECA   
	STA    1,SP
	TSTX   
	BNE    *-52       ;abs = $C411
	PSHA   
	LDA    $90
	TAP    
	PULA   
	PULH   
	RTS    
	BSR    *-74       ;abs = $C404
	LDA    #$1F
	STA    $1802
	LDA    #$08
	STA    $1803
	LDA    #$1C
	STA    $1809
	CLRA   
	STA    $180A
	LDA    $FFAF
	CBEQA  #$FF,*+15       ;abs = $C475
	LDA    $FFAF
	STA    $3E
	LDA    $FFAE
	AND    #$01
	STA    $3F
	MOV    #$06,$3C
	CLR    $3D
	BRCLR  4,$3F,*+0       ;abs = $C47A
	LDA    $3F
	AND    #$9F
	ORA    #$80
	STA    $3F
	LDA    $3F
	AND    #$C0
	CMP    #$80
	BNE    *-6       ;abs = $C485
	JMP    $C5D5
	LDA    #$FF
	STA    $180E
	STA    $180F
	CLR    $4F
	LDA    $00
	AND    #$7B
	STA    $00
	LDHX   #$1840
	LDA    ,X
	AND    #$FB
	STA    ,X
	LDA    $01
	AND    #$DF
	ORA    #$D4
	STA    $01
	LDA    $08
	AND    #$F8
	STA    $08
	LDHX   #$1850
	LDA    ,X
	AND    #$F8
	STA    ,X
	LDA    $09
	AND    #$F8
	STA    $09
	LDA    $17
	ORA    #$4B
	STA    $17
	CLRA   
	STA    $1841
	STA    $1845
	STA    $1849
	STA    $184D
	LDHX   #$1851
	LDA    ,X
	AND    #$80
	STA    ,X
	LDHX   #$1855
	LDA    ,X
	AND    #$F8
	STA    ,X
	LDA    #$FF
	STA    $1842
	STA    $1846
	LDA    #$C0
	STA    $184A
	LDA    #$FF
	STA    $184E
	LSRA   
	STA    $1852
	LDA    #$07
	STA    $1856
	CLR    $67
	MOV    #$01,$66
	CLR    $65
	MOV    #$A0,$64
	MOV    #$30,$63
	CLR    $62
	MOV    #$28,$61
	CLR    $60
	MOV    #$80,$5E
	JSR    $E6D1
	JSR    $E6E5
	JSR    $E7A7
	JSR    $E7CC
	JSR    $D885
	JSR    $D86F
	JSR    $C6C9
	LDA    $91
	AND    #$F8
	STA    $91
	JSR    $C6DC
	JSR    $E6F9	; configFTM2
	JSR    $E83B
	JSR    $E89E
	JSR    $C7E6
	LDA    $30
	AND    #$EF
	ORA    #$08
	STA    $30
	RTS    
	BRSET  0,$03,*-56       ;abs = $C510
	MOV    $F7,$54
	BRSET  0,$90,*+3       ;abs = $C551
	DEC    1,X
	BRSET  0,$00,*-29       ;abs = $C536
	BRCLR  0,$E0,*+3       ;abs = $C559
	ROL    ,X
	PSHH   
	PSHX   
	LDHX   5,SP
	LDA    ,X
	AIX    #1
	STHX   5,SP
	PULX   
	PULH   
	RTS    
	AIS    #-4
	LDA    $C549
	INCA   
	TSX    
	STA    1,X
	LDA    $C548
	INCA   
	STA    ,X
	LDHX   $C54A
	BRA    *+33       ;abs = $C59A
	PSHX   
	PSHH   
	LDA    ,X
	PSHA   
	LDA    2,X
	INCA   
	STA    6,SP
	LDA    3,X
	LDX    1,X
	PULH   
	INCA   
	BRA    *+5       ;abs = $C590
	CLR    ,X
	AIX    #1
	DBNZA  *-3       ;abs = $C58D
	DBNZ   5,SP,*-5       ;abs = $C58D
	PULH   
	PULX   
	AIX    #4
	DBNZ   2,SP,*-31       ;abs = $C57B
	DBNZ   1,SP,*-35       ;abs = $C57B
	LDHX   $C54C
	PSHX   
	PSHH   
	BSR    *-77       ;abs = $C55A
	TAX    
	INCA   
	STA    3,SP
	BSR    *-84       ;abs = $C55A
	INCA   
	STA    4,SP
	DECA   
	BNE    *+5       ;abs = $C5BA
	CBEQX  #$00,*+27       ;abs = $C5D2
	BSR    *-96       ;abs = $C55A
	PSHA   
	PULH   
	BSR    *-100       ;abs = $C55A
	TAX    
	BRA    *+7       ;abs = $C5C8
	BSR    *-105       ;abs = $C55A
	STA    ,X
	AIX    #1
	DBNZ   4,SP,*-5       ;abs = $C5C3
	DBNZ   3,SP,*-9       ;abs = $C5C3
	BRA    *-41       ;abs = $C5A7
	AIS    #6
	RTS    
	LDHX   #$0433
	TXS    
	BSR    *-113       ;abs = $C568
	JMP    $D7AC
	SEI    
	STA    $1826
	LDA    #$80
	STA    $1825
	NOP    
	NOP    
	NOP    
	NOP    
	LDA    $1825
	BIT    #$30
	BNE    *+9       ;abs = $C5F9
	LDA    $1825
	BIT    #$40
	BEQ    *-5       ;abs = $C5F2
	CLI    
	RTS    
	PSHX   
	PSHH   
	PSHA   
	AIS    #-42
	TSX    
	PSHX   
	PSHH   
	LDHX   #$C5DE
	LDA    #$2A
	JSR    $EF50
	CLRA   
	LDHX   #$1825
	STA    ,X
	LDA    ,X
	BIT    #$30
	BEQ    *+7       ;abs = $C61A
	LDA    #$30
	STA    $1825
	LDHX   44,SP
	LDA    43,SP
	STA    ,X
	TSX    
	LDA    47,X
	JSR    ,X
	LDA    $1825
	BIT    #$30
	BEQ    *+16       ;abs = $C63A
	LDA    $1825
	BIT    #$20
	BEQ    *+6       ;abs = $C637
	LDA    #$16
	BRA    *+6       ;abs = $C63B
	LDA    #$09
	DC.B   $21		 ;SKIP   
	CLRA   
	AIS    #45
	RTS    
	PSHX   
	PSHH   
	AIS    #-42
	TSX    
	PSHX   
	PSHH   
	LDHX   #$C5DE
	LDA    #$2A
	JSR    $EF50
	LDA    $1825
	BIT    #$40
	BNE    *+6       ;abs = $C658
	LDA    #$08
	BRA    *+91       ;abs = $C6B1
	CLRA   
	LDHX   #$1825
	STA    ,X
	LDA    ,X
	BIT    #$30
	BEQ    *+42       ;abs = $C68A
	LDA    #$30
	STA    $1825
	BRA    *+35       ;abs = $C68A
	LDHX   47,SP
	LDA    ,X
	LDHX   49,SP
	CMP    ,X
	BEQ    *+12       ;abs = $C67D
	COMA   
	ORA    ,X
	LDHX   47,SP
	STA    ,X
	LDA    #$25
	TSX    
	JSR    ,X
	TSX    
	INC    47,X
	BNE    *+4       ;abs = $C684
	INC    46,X
	INC    49,X
	BNE    *+4       ;abs = $C68A
	INC    48,X
	LDHX   43,SP
	PSHX   
	PSHH   
	AIX    #-1
	STHX   45,SP
	PULH   
	PULX   
	CPHX   #$0000
	BNE    *-48       ;abs = $C669
	LDA    $1825
	BIT    #$30
	BEQ    *+16       ;abs = $C6B0
	LDA    $1825
	BIT    #$20
	BEQ    *+6       ;abs = $C6AD
	LDA    #$16
	BRA    *+6       ;abs = $C6B1
	LDA    #$09
	DC.B   $21		 ;SKIP   
	CLRA   
	AIS    #44
	RTS    
	CPHX   #$C000
	BCC    *+5       ;abs = $C6BC
	LDA    #$02
	RTS    
	LDA    #$40
	PSHA   
	CLRA   
	JSR    $C5FB
	PULH   
	TSTA   
	BNE    *+3       ;abs = $C6C8
	CLRA   
	RTS    
	LDHX   #$FFFF
	STHX   $92
	LDA    #$30
	STA    $1825
	LDA    #$50
	STA    $1820
	RTS    
	BSET   0,$81
	RTS    
	BCLR   6,$8A
	LDA    $80
	AND    #$FE
	ORA    #$80
	STA    $80
	MOV    #$FC,$81
	LDX    #$28
	CLRH   
	STHX   $82
	LDX    #$90
	STHX   $84
	LDHX   #$0312
	STHX   $86
	MOV    #$EA,$8A
	BSET   0,$80
	RTS    
	PSHH   
	PULA   
	LSRA   
	RORX   
	PSHA   
	LDA    #$48
	PSHX   
	TSX    
	SUB    ,X
	STA    ,X
	LDA    #$6F
	SBC    1,X
	PSHA   
	PULH   
	PULX   
	PULA   
	RTS    
	PSHH   
	AIS    #-2
	LDA    $12
	TSX    
	STA    ,X
	LDA    $13
	STA    1,X
	LDX    $9D
	CPX    #$03
	BHI    *+12       ;abs = $C72C
	CLRA   
	JSR    $EFD6
	BRSET  2,$04,*+10       ;abs = $C730
	BSET   3,$25
	STHX   $3F
	NOP    
	BRA    *+120       ;abs = $C7A6
	LDHX   $94
	TXA    
	PSHH   
	BSR    *+120       ;abs = $C7AC
	STHX   $94
	MOV    #$41,$10
	MOV    #$01,$9D
	BRA    *+32       ;abs = $C75E
	LDHX   $96
	TXA    
	PSHH   
	BSR    *+104       ;abs = $C7AC
	STHX   $96
	MOV    #$43,$10
	MOV    #$02,$9D
	BRA    *+16       ;abs = $C75E
	LDHX   $98
	TXA    
	PSHH   
	BSR    *+88       ;abs = $C7AC
	STHX   $98
	MOV    #$46,$10
	MOV    #$03,$9D
	PULH   
	BRA    *+71       ;abs = $C7A6
	LDHX   $9A
	TXA    
	PSHH   
	BSR    *+71       ;abs = $C7AC
	STHX   $9A
	MOV    #$40,$10
	CLR    $9D
	INC    $9F
	LDA    $9F
	CMP    #$10
	PULH   
	BNE    *+49       ;abs = $C7A6
	MOV    #$01,$9C
	LDHX   $94
	JSR    $C6FD
	STHX   $010E
	LDHX   $96
	JSR    $C6FD
	STHX   $0110
	LDHX   $98
	JSR    $C6FD
	STHX   $0112
	LDHX   $9A
	JSR    $C6FD
	STHX   $0114
	CLRX   
	CLRH   
	STHX   $94
	STHX   $96
	STHX   $98
	STHX   $9A
	CLR    $9F
	BSET   3,$5E
	AIS    #2
	PULH   
	RTI    
	TSX    
	ADD    4,X
	PSHA   
	LDA    2,X
	ADC    3,X
	PSHA   
	PULH   
	PULX   
	RTS    
	CLRX   
	CLRH   
	STHX   $94
	STHX   $96
	STHX   $98
	STHX   $9A
	RTS    
	TST    $9E
	BEQ    *+18       ;abs = $C7D7
	CLR    $9F
	CLR    $9C
	CLR    $9D
	BSR    *-21       ;abs = $C7B8
	LDX    $9D
	CLRH   
	LDA    63074,X
	STA    $10
	RTS    
	TST    $9E
	BEQ    *+5       ;abs = $C7DF
	LDA    #$08
	RTS    
	MOV    #$02,$9E
	BSR    *-31       ;abs = $C7C3
	CLRA   
	RTS    
	MOV    #$1F,$10
	CLR    $11
	CLR    $9C
	CLR    $9E
	MOV    #$D7,$16
	RTS    


	org $C800
	DCB.B $400, $FF

	org $CC00
	AIS    #-2
	LDHX   $011E
	STHX   1,SP
	INC    $A8
	BNE    *+4       ;abs = $CC0E
	INC    $A7
	LDHX   $A3
	CPHX   1,SP
	BCC    *+21       ;abs = $CC28
	TXA    
	ADD    #$60
	STA    $A4
	PSHH   
	PULA   
	ADC    #$EA
	STA    $A3
	LDA    $00
	EOR    #$08
	STA    $00
	BSET   3,$01
	LDA    $A4
	TSX    
	SUB    1,X
	STA    $A4
	LDA    $A3
	SBC    ,X
	STA    $A3
	BRCLR  0,$A2,*+16       ;abs = $CC44
	JSR    $DDCA
	BCLR   0,$A2
	INC    $A6
	BNE    *+76       ;abs = $CC8A
	INC    $A5
	BRA    *+72       ;abs = $CC8A
	BRCLR  1,$A2,*+10       ;abs = $CC4E
	JSR    $DF15
	BCLR   1,$A2
	BRA    *+62       ;abs = $CC8A
	BRCLR  2,$A2,*+10       ;abs = $CC58
	JSR    $DF16
	BCLR   2,$A2
	BRA    *+52       ;abs = $CC8A
	BRCLR  3,$A2,*+10       ;abs = $CC62
	JSR    $DF96
	BCLR   3,$A2
	BRA    *+42       ;abs = $CC8A
	BRCLR  4,$A2,*+10       ;abs = $CC6C
	JSR    $E08F
	BCLR   4,$A2
	BRA    *+32       ;abs = $CC8A
	BRCLR  5,$A2,*+10       ;abs = $CC76
	JSR    $E239
	BCLR   5,$A2
	BRA    *+22       ;abs = $CC8A
	BRCLR  6,$A2,*+10       ;abs = $CC80
	JSR    $E42E
	BCLR   6,$A2
	BRA    *+12       ;abs = $CC8A
	BRCLR  7,$A2,*+10       ;abs = $CC8A
	JSR    $E4B1
	BCLR   7,$A2
	BSET   3,$F4
	INC    $A0
	LDA    $A0
	CMP    #$08
	BNE    *+20       ;abs = $CCA4
	CLR    $A0
	LDA    $A1
	INC    $A1
	PSHA   
	LDA    $A1
	TSX    
	EOR    ,X
	STA    ,X
	LDA    $A2
	ORA    ,X
	STA    $A2
	PULH   
	AIS    #2
	RTS    
	
	org $CCA7
	PSHH   
	LDX    $C1
	LSLX   
	STX    1,SP
	CLRH   
	INC    195,X
	BNE    *+4       ;abs = $CCB5
	INC    194,X
	LDHX   194,X
	CPHX   #$0002
	BNE    *+19       ;abs = $CCCE
	TSX    
	LDX    ,X
	LDA    $A8
	CLRH   
	STA    205,X
	LDA    $A7
	STA    204,X
	LDA    $A8
	BRA    *+12       ;abs = $CCD8
	CPHX   #$0002
	BLS    *+15       ;abs = $CCE0
	TSX    
	LDX    ,X
	LDA    $A8
	CLRH   
	STA    215,X
	LDA    $A7
	STA    214,X
	PULH   
	RTS    
	
	org $CCE2
	AIS    #-2
	JSR    $E8B7
	BRSET  1,$0E,*+11       ;abs = $CCF2
	LDHX   $A5
	STHX   $A9
	BSET   1,$0E
	BRA    *+114       ;abs = $CD62
	LDA    $A6
	SUB    $AA
	PSHA   
	LDA    $A5
	SBC    $A9
	PSHA   
	PULH   
	PULX   
	STHX   1,SP
	AIX    #-13
	CPHX   #$0263
	BHI    *+71       ;abs = $CD4D
	LDA    $0105
	BIT    #$40
	BEQ    *+21       ;abs = $CD22
	LDA    $0105
	BIT    #$80
	BEQ    *+74       ;abs = $CD5E
	LDHX   $0104
	TXA    
	AND    #$BF
	TAX    
	STHX   $0104
	BRA    *+62       ;abs = $CD5E
	LDX    $F5
	CPX    #$03
	BHI    *+35       ;abs = $CD49
	CLRA   
	JSR    $EFD6
	BRSET  2,$1B,*+6       ;abs = $CD32
	BRSET  1,$08,*+17       ;abs = $CD40
	MOV    #$02,$F5
	LDX    #$06
	BRA    *+14       ;abs = $CD45
	MOV    #$03,$F5
	LDX    #$07
	BRA    *+7       ;abs = $CD45
	MOV    #$01,$F5
	LDX    #$04
	CLRH   
	STHX   $0108
	BSET   1,$F4
	BRA    *+19       ;abs = $CD5E
	LDHX   1,SP
	CPHX   #$0271
	BCS    *+11       ;abs = $CD5E
	LDA    #$01
	JSR    $EAEE
	BSET   1,$F4
	BSET   4,$F4
	BCLR   1,$0E
	BSET   2,$0C
	AIS    #2
	RTS    
	
	org $CD65
	LSLA   
	PSHA   
	BSR    *+9       ;abs = $CD70
	LSLA   
	TSX    
	STA    ,X
	BSR    *+4       ;abs = $CD70
	PULH   
	RTS    
	JSR    $E8B7
	TSX    
	ORA    2,X
	LSLA   
	STA    2,X
	JSR    $E8B7
	TSX    
	ORA    2,X
	RTS    
	AIS    #-20
	TSX    
	CLR    19,X
	CLR    2,X
	CLR    1,X
	CLR    4,X
	CLR    3,X
	CLR    6,X
	CLR    5,X
	CLR    11,X
	CLR    10,X
	JSR    $CFCF
	BCS    *+5       ;abs = $CD9D
	CLRA   
	BRA    *+5       ;abs = $CDA0
	NSA    
	AND    #$F0
	ADD    #$20
	LSLA   
	CLRH   
	TAX    
	LDX    257,X
	STX    15,SP
	PSHA   
	TPA    
	SEI    
	STA    $90
	PULA   
	TSX    
	CLR    7,X
	LDA    $BF
	LSLA   
	LSLA   
	LSLA   
	PSHA   
	ADD    7,X
	PSHA   
	CLRA   
	ADC    #$00
	PSHA   
	PULH   
	PULX   
	LDA    510,X
	TSX    
	ADD    3,X
	STA    3,X
	CLRA   
	ADC    2,X
	STA    2,X
	PULA   
	ADD    8,X
	PSHA   
	CLRA   
	ADC    #$00
	PSHA   
	PULH   
	PULX   
	LDA    550,X
	TSX    
	ADD    4,X
	STA    4,X
	CLRA   
	ADC    3,X
	STA    3,X
	INC    7,X
	LDA    7,X
	CMP    #$08
	BCS    *-57       ;abs = $CDB4
	PSHA   
	LDA    $90
	TAP    
	PULA   
	LDHX   4,SP
	BEQ    *+7       ;abs = $CDFE
	LDHX   2,SP
	BNE    *+9       ;abs = $CE05
	TSX    
	CLR    6,X
	CLR    5,X
	BRA    *+103       ;abs = $CE6A
	PSHX   
	TSX    
	LDA    5,X
	LDX    4,X
	PSHA   
	PSHX   
	CLRA   
	PSHA   
	PSHA   
	TSX    
	JSR    $F5CA
	TSX    
	JSR    $F58D
	RORA   
	ORA    96,X
	BRSET  0,$EE,*+11       ;abs = $CE26
	PSHX   
	TSX    
	LDA    15,X
	STA    13,X
	PSHA   
	CLRA   
	PSHA   
	PSHA   
	TSX    
	JSR    $F5CA
	AIX    #4
	PSHX   
	PSHH   
	AIX    #-8
	JSR    $F594
	AIX    #36
	JSR    $EF80
	TSX    
	AIX    #36
	JSR    $F5A6
	ASRA   
	CLR    ,X
	STX    ,X
	BRSET  0,$A7,*+24       ;abs = $CE5B
	BLS    *+10       ;abs = $CE50
	LDHX   #$FFFF
	STHX   6,SP
	BRA    *+28       ;abs = $CE6A
	TSX    
	AIX    #15
	JSR    $F57F
	CLR    $00
	BRSET  0,$00,*-104       ;abs = $CDF0
	JSR    $F59B
	TSX    
	LDA    2,X
	PSHA   
	LDX    3,X
	PULH   
	STHX   14,SP
	AIS    #8
	JSR    $CFCF
	BCS    *+3       ;abs = $CE70
	CLRA   
	ADD    #$10
	LSLA   
	CLRH   
	TAX    
	LDHX   256,X
	CPHX   6,SP
	BCC    *+7       ;abs = $CE83
	LDA    #$01
	TSX    
	STA    11,X
	PSHA   
	TPA    
	SEI    
	STA    $90
	PULA   
	JSR    $CFCF
	BCS    *+3       ;abs = $CE8F
	CLRA   
	ADD    #$0B
	LSLA   
	CLRH   
	TAX    
	LDHX   256,X
	PSHX   
	LDA    8,SP
	SUB    1,SP
	PSHA   
	PSHH   
	PULA   
	TSX    
	STA    1,X
	LDA    7,X
	SBC    1,X
	PSHA   
	PULH   
	PULX   
	STHX   10,SP
	TSX    
	TST    9,X
	PULH   
	BGE    *+11       ;abs = $CEBE
	TSX    
	COM    8,X
	NEG    9,X
	BNE    *+4       ;abs = $CEBE
	INC    8,X
	LDHX   9,SP
	CPHX   #$0096
	BLE    *+7       ;abs = $CECB
	LDA    #$01
	TSX    
	STA    10,X
	JSR    $CFCF
	BCS    *+3       ;abs = $CED1
	CLRA   
	ADD    #$0B
	LSLA   
	PSHA   
	TSX    
	LDA    6,X
	CLRH   
	PULX   
	STA    256,X
	LDA    7,SP
	STA    257,X
	LDHX   6,SP
	CPHX   #$FFFF
	BNE    *+5       ;abs = $CEEE
	JMP    $CFB5
	TSX    
	TST    10,X
	BEQ    *+5       ;abs = $CEF6
	JMP    $CFB3
	TST    11,X
	BNE    *+5       ;abs = $CEFD
	JMP    $CFB3
	JSR    $CFCF
	CLRA   
	BCC    *+7       ;abs = $CF08
	LDA    $BF
	NSA    
	AND    #$F0
	ADD    #$21
	LSLA   
	CLRH   
	TAX    
	LDHX   256,X
	CPHX   #$00FF
	BEQ    *+5       ;abs = $CF19
	JMP    $CFB3
	JSR    $CFCF
	CLRA   
	BCC    *+4       ;abs = $CF21
	LDA    $BF
	ADD    #$10
	LSLA   
	CLRH   
	TAX    
	PSHH   
	PULA   
	STA    1,SP
	LDHX   256,X
	TXA    
	PSHH   
	TSX    
	ADD    7,X
	JSR    $CFD4
	JSR    $CFD4
	PSHA   
	TSX    
	LDA    1,X
	ADC    7,X
	PSHA   
	PULH   
	PULX   
	STHX   14,SP
	JSR    $CFCF
	PULH   
	BCC    *+4       ;abs = $CF4E
	TSX    
	STA    ,X
	TSX    
	LDA    ,X
	ADD    #$10
	LSLA   
	PSHA   
	LDA    13,X
	AND    #$03
	CLRX   
	LSRX   
	RORA   
	PSHX   
	LDHX   15,SP
	PSHA   
	PSHH   
	PULA   
	LSRA   
	RORX   
	LSRA   
	RORX   
	PSHA   
	TXA    
	TSX    
	ADD    1,X
	STA    1,X
	PULA   
	ADC    2,X
	CLRH   
	LDX    3,SP
	STA    256,X
	PULA   
	STA    257,X
	BSR    *+84       ;abs = $CFCF
	CLRA   
	AIS    #2
	BCC    *+4       ;abs = $CF84
	LDA    $BF
	ADD    #$10
	LSLA   
	TAX    
	LDHX   256,X
	CPHX   6,SP
	BCC    *+53       ;abs = $CFC4
	BSR    *+62       ;abs = $CFCF
	CLRA   
	BCC    *+4       ;abs = $CF98
	LDA    $BF
	ADD    #$10
	LSLA   
	CLRH   
	TAX    
	LDHX   256,X
	AIX    #1
	PSHH   
	CLRH   
	PSHX   
	TAX    
	LDA    2,SP
	STA    256,X
	PULA   
	STA    257,X
	AIS    #1
	BRA    *+17       ;abs = $CFC4
	TSX    
	LDA    14,X
	BPL    *+12       ;abs = $CFC4
	LDHX   $0104
	TXA    
	ORA    #$20
	TAX    
	STHX   $0104
	PSHA   
	LDA    $90
	TAP    
	PULA   
	TSX    
	LDA    10,X
	AIS    #20
	RTS    
	LDA    $BF
	CMP    #$05
	RTS    
	PSHA   
	TSX    
	LDA    3,X
	ADC    9,X
	STA    3,X
	PULA   
	ADD    10,X
	RTS    
	PSHA   
	AIS    #-7
	CLRH   
	TAX    
	LDA    171,X
	CMP    #$06
	BHI    *+25       ;abs = $D002
	SUB    #$01
	TAX    
	CLRA   
	JSR    $EFA7
	BRSET  0,$06,*-45       ;abs = $CFC5
	BRSET  1,$D0,*-83       ;abs = $CFA2
	CMP    37840,X
	BRSET  1,$D2,*-48       ;abs = $CFCB
	SBC    59859,X
	DECX   
	JSR    $D3F5
	BCS    *+3       ;abs = $D008
	CLRA   
	TSX    
	STA    3,X
	JSR    $D421
	JSR    $D3E6
	LDHX   256,X
	CPHX   #$0096
	BGT    *+5       ;abs = $D01D
	JMP    $D0A7
	JSR    $D3F5
	BCC    *+5       ;abs = $D025
	JSR    $D3EE
	JSR    $D3FB
	CLRH   
	TAX    
	LDA    257,X
	LDX    8,SP
	STA    176,X
	JSR    $D402
	BCC    *+5       ;abs = $D03A
	JSR    $D40C
	LDA    4,SP
	ADD    #$21
	LSLA   
	TAX    
	LDA    257,X
	LDX    8,SP
	STA    181,X
	CPX    #$05
	JSR    $D3E6
	BCC    *+5       ;abs = $D053
	STX    5,SP
	JSR    $D427
	TAX    
	CLRA   
	STA    256,X
	STA    257,X
	LDX    8,SP
	JSR    $D402
	BCC    *+5       ;abs = $D069
	JSR    $D40C
	LDA    4,SP
	ADD    #$20
	LSLA   
	TAX    
	CLRA   
	STA    256,X
	LDA    #$03
	STA    257,X
	JSR    $D3F5
	JSR    $D3E6
	BCC    *+5       ;abs = $D084
	JSR    $D3EE
	LDA    5,SP
	ADD    #$21
	LSLA   
	TAX    
	CLRA   
	STA    256,X
	LDA    #$FF
	STA    257,X
	LDX    8,SP
	LDA    #$06
	STA    186,X
	LDA    #$01
	STA    171,X
	LSLX   
	CLRA   
	STA    481,X
	STA    480,X
	JMP    $D190
	TSX    
	LDX    7,X
	CLRH   
	DEC    186,X
	BEQ    *+5       ;abs = $D0B5
	JMP    $D190
	PSHH   
	PULA   
	TSX    
	STA    4,X
	LDX    #$66
	CLRH   
	STHX   6,SP
	JSR    $D3F5
	BCC    *+5       ;abs = $D0C8
	JSR    $D3EE
	JSR    $D3FB
	TAX    
	CLRA   
	STA    256,X
	LDA    #$03
	STA    257,X
	JSR    $D3F5
	PSHA   
	PSHH   
	PULA   
	STA    5,SP
	PULA   
	BCC    *+8       ;abs = $D0E7
	NSA    
	AND    #$F0
	STA    4,SP
	LDA    4,SP
	ADD    #$21
	LSLA   
	TAX    
	CLRA   
	STA    256,X
	LDA    #$33
	STA    257,X
	LDX    8,SP
	LDA    #$10
	STA    186,X
	LDA    #$02
	STA    171,X
	CPX    #$05
	JSR    $D3E6
	BCC    *+5       ;abs = $D10C
	STX    5,SP
	JSR    $D427
	LSLX   
	PSHX   
	TAX    
	JSR    $D3E6
	LDHX   256,X
	PSHH   
	CLRH   
	TXA    
	LDX    2,SP
	STA    481,X
	PULA   
	STA    480,X
	LDA    9,SP
	CMP    #$05
	PULX   
	BCC    *+5       ;abs = $D131
	STA    4,SP
	LDA    4,SP
	ADD    #$10
	LSLA   
	TAX    
	JSR    $D3E6
	LDHX   256,X
	CPHX   #$03E8
	BLE    *+78       ;abs = $D190
	JSR    $D3F5
	BCC    *+5       ;abs = $D14C
	TSX    
	STA    4,X
	JSR    $D427
	CLRH   
	TAX    
	LDHX   256,X
	PSHX   
	PSHH   
	LDX    #$B0
	CLRH   
	JSR    $EF07
	AIS    #2
	PSHX   
	LDA    8,SP
	SUB    1,SP
	STA    8,SP
	LDA    7,SP
	PSHA   
	PSHH   
	PULA   
	TSX    
	STA    1,X
	PULA   
	SBC    1,X
	STA    7,X
	LDHX   7,SP
	CPHX   #$0011
	PULH   
	BGE    *+8       ;abs = $D186
	LDX    #$11
	CLRH   
	STHX   6,SP
	TSX    
	LDX    7,X
	CLRH   
	LDA    7,SP
	STA    229,X
	JMP    $D278
	JSR    $D3F5
	BCS    *+3       ;abs = $D199
	CLRA   
	TSX    
	STA    4,X
	ADD    #$0B
	LSLA   
	LDX    7,X
	STA    3,SP
	CLRA   
	CPX    #$05
	BCS    *+9       ;abs = $D1B0
	TSX    
	STA    1,X
	STA    3,X
	BRA    *+8       ;abs = $D1B6
	STX    4,SP
	TSX    
	STA    1,X
	LDA    3,X
	ADD    #$10
	LSLA   
	CLRH   
	TAX    
	PSHH   
	PULA   
	STA    5,SP
	LDHX   256,X
	PSHX   
	PSHH   
	LDX    #$03
	CLRH   
	JSR    $EEE0
	AIS    #2
	PSHX   
	PSHH   
	LDX    #$04
	CLRH   
	JSR    $EF07
	AIS    #2
	PSHH   
	PULA   
	STA    1,SP
	CLRH   
	TXA    
	LDX    3,SP
	LDHX   256,X
	PSHX   
	PSHH   
	TSX    
	LDX    2,X
	JSR    $EF3A
	BLE    *+49       ;abs = $D221
	JSR    $D3F5
	BCC    *+5       ;abs = $D1FA
	JSR    $D3EE
	JSR    $D3FB
	TSX    
	LDX    7,X
	CLRH   
	PSHA   
	LDA    176,X
	ORA    #$01
	LDX    1,SP
	PSHA   
	CLRA   
	STA    256,X
	LDX    2,SP
	PULA   
	STA    257,X
	JSR    $D414
	PULX   
	BCC    *+5       ;abs = $D21E
	JSR    $D3EE
	JMP    $D2AB
	JSR    $D3F5
	BCC    *+5       ;abs = $D229
	TSX    
	STA    4,X
	TSX    
	LDA    4,X
	ADD    #$0B
	LSLA   
	LDX    7,X
	LSLX   
	CLRH   
	STX    1,SP
	TAX    
	PSHH   
	PULA   
	STA    4,SP
	LDHX   256,X
	PSHX   
	PSHH   
	TSX    
	LDX    2,X
	CLRH   
	LDHX   480,X
	TXA    
	PSHH   
	PULX   
	JSR    $EF3A
	BLS    *+42       ;abs = $D27A
	JSR    $D3F5
	BCC    *+5       ;abs = $D25A
	TSX    
	STA    3,X
	TSX    
	LDA    3,X
	ADD    #$0B
	LSLA   
	LDX    7,X
	LSLX   
	CLRH   
	PSHX   
	TAX    
	LDHX   256,X
	PSHH   
	CLRH   
	TXA    
	LDX    2,SP
	STA    481,X
	PULA   
	STA    480,X
	PULH   
	BRA    *+82       ;abs = $D2CA
	TSX    
	LDX    7,X
	CLRH   
	DBNZ   186,X,*+76       ;abs = $D2CA
	CPX    #$05
	BCC    *+5       ;abs = $D288
	JSR    $D40C
	LDA    4,SP
	ADD    #$20
	LSLA   
	PSHA   
	LDA    176,X
	AND    #$FE
	LDX    1,SP
	PSHA   
	CLRA   
	STA    256,X
	LDX    2,SP
	PULA   
	STA    257,X
	JSR    $D414
	PULX   
	BCC    *+5       ;abs = $D2AB
	JSR    $D3EE
	LDA    5,SP
	ADD    #$21
	LSLA   
	LDX    8,SP
	PSHA   
	LDA    181,X
	PULX   
	PSHA   
	CLRA   
	STA    256,X
	PULA   
	STA    257,X
	LDX    8,SP
	LDA    #$04
	STA    171,X
	BSET   1,$F4
	JMP    $D34E
	JSR    $D3F5
	BCS    *+3       ;abs = $D2D3
	CLRA   
	TSX    
	STA    4,X
	JSR    $D421
	LDHX   256,X
	CPHX   #$0096
	BGE    *+110       ;abs = $D34E
	TSX    
	LDX    7,X
	LDA    #$05
	BRA    *+110       ;abs = $D355
	JSR    $D3F5
	BCS    *+3       ;abs = $D2EF
	CLRA   
	TSX    
	STA    3,X
	JSR    $D421
	JSR    $D3E6
	LDHX   256,X
	CPHX   #$0096
	BGE    *+81       ;abs = $D350
	JSR    $D3F5
	BCC    *+5       ;abs = $D309
	JSR    $D3EE
	JSR    $D3FB
	CLRH   
	TAX    
	LDA    257,X
	LDX    8,SP
	STA    176,X
	JSR    $D402
	BCC    *+5       ;abs = $D31E
	JSR    $D40C
	LDA    4,SP
	ADD    #$20
	LSLA   
	TAX    
	CLRA   
	STA    256,X
	LDA    #$03
	STA    257,X
	JSR    $D3F5
	JSR    $D3E6
	BCC    *+5       ;abs = $D339
	JSR    $D3EE
	LDA    5,SP
	ADD    #$21
	LSLA   
	TAX    
	CLRA   
	STA    256,X
	LDA    #$FF
	STA    257,X
	LDX    8,SP
	CLR    171,X
	BRA    *+68       ;abs = $D392
	TSX    
	LDX    7,X
	LDA    #$04
	CLRH   
	STA    171,X
	BRA    *+58       ;abs = $D392
	JSR    $D3F5
	BCS    *+3       ;abs = $D360
	CLRA   
	TSX    
	STA    3,X
	JSR    $D421
	BSR    *+128       ;abs = $D3E6
	LDHX   256,X
	CPHX   #$0096
	BLE    *+35       ;abs = $D392
	TSX    
	LDX    7,X
	LDA    #$01
	CLRH   
	STA    171,X
	CPX    #$05
	BCC    *+5       ;abs = $D380
	STX    5,SP
	JSR    $D427
	TAX    
	CLRA   
	STA    256,X
	STA    257,X
	LDX    8,SP
	LDA    #$04
	STA    186,X
	TSX    
	LDX    7,X
	CLRH   
	LDA    171,X
	CMP    #$04
	BNE    *+42       ;abs = $D3C4
	CPX    #$05
	BSR    *+72       ;abs = $D3E6
	BCC    *+5       ;abs = $D3A5
	TXA    
	BSR    *+75       ;abs = $D3EE
	BSR    *+86       ;abs = $D3FB
	TAX    
	LDHX   256,X
	PSHA   
	TXA    
	ORA    #$80
	PSHH   
	CLRH   
	LDX    2,SP
	PSHA   
	LDA    2,SP
	STA    256,X
	PULA   
	STA    257,X
	AIS    #2
	BRA    *+33       ;abs = $D3E3
	CPX    #$05
	BSR    *+32       ;abs = $D3E6
	BCC    *+5       ;abs = $D3CD
	TXA    
	BSR    *+35       ;abs = $D3EE
	BSR    *+46       ;abs = $D3FB
	TAX    
	LDHX   256,X
	PSHA   
	TXA    
	AND    #$7F
	CLRH   
	PULX   
	PSHA   
	CLRA   
	STA    256,X
	PULA   
	STA    257,X
	AIS    #8
	RTS    
	
	org $D3E6
	PSHA   
	PSHH   
	PULA   
	STA    8,SP
	PULA   
	RTS    
	NSA    
	AND    #$F0
	STA    7,SP
	RTS    
	LDA    10,SP
	CMP    #$05
	RTS    
	LDA    7,SP
	ADD    #$20
	LSLA   
	RTS    
	CPX    #$05
	PSHA   
	PSHH   
	PULA   
	STA    7,SP
	PULA   
	RTS    
	TXA    
	NSA    
	AND    #$F0
	STA    6,SP
	RTS    
	LDA    11,SP
	CMP    #$05
	PSHA   
	PSHH   
	PULA   
	STA    9,SP
	PULA   
	RTS    
	ADD    #$0B
	LSLA   
	CLRH   
	TAX    
	RTS    
	LDA    7,SP
	ADD    #$10
	LSLA   
	RTS    
	PSHA   
	PSHX   
	PSHH   
	AIS    #-18
	LSLA   
	PSHA   
	CLRA   
	ROLA   
	LDHX   20,SP
	PSHA   
	TXA    
	PSHH   
	TSX    
	ADD    2,X
	STA    2,X
	PULA   
	ADC    1,X
	PSHA   
	LDX    2,X
	PULH   
	LDHX   10,X
	STHX   9,SP
	JSR    $D546
	LDHX   ,X
	STHX   3,SP
	JSR    $D546
	LDA    13,X
	SUB    10,SP
	STA    1,SP
	LDA    12,X
	TSX    
	SBC    8,X
	TAX    
	JSR    $EF9A
	TSX    
	JSR    $F5AC
	AIX    #7
	JSR    $EF80
	LDA    $BF
	CMP    #$05
	CLRA   
	AIS    #5
	BCC    *+4       ;abs = $D47F
	LDA    $BF
	ADD    #$1A
	LSLA   
	CLRH   
	TAX    
	LDHX   256,X
	TXA    
	PSHH   
	TSX    
	SUB    8,X
	PSHA   
	LDA    ,X
	SBC    7,X
	TAX    
	JSR    $EF9A
	TSX    
	JSR    $F5AC
	AIX    #19
	JSR    $EF80
	TSX    
	LDA    25,X
	LSLA   
	CLRX   
	ROLX   
	STX    5,SP
	LDHX   24,SP
	ADD    25,SP
	PSHA   
	PSHH   
	PULA   
	TSX    
	ADC    5,X
	PSHA   
	PULH   
	PULX   
	LDA    3,X
	SUB    7,SP
	STA    5,SP
	LDA    2,X
	TSX    
	SBC    5,X
	TAX    
	LDA    5,SP
	PSHA   
	JSR    $EF9A
	TSX    
	JSR    $F5AC
	AIX    #19
	JSR    $EF80
	TSX    
	AIX    #11
	LDA    3,X
	ORA    2,X
	ORA    1,X
	ORA    ,X
	AIS    #9
	BEQ    *+99       ;abs = $D543
	LDA    11,X
	ORA    10,X
	ORA    9,X
	ORA    8,X
	BEQ    *+89       ;abs = $D543
	LDA    15,X
	ORA    14,X
	ORA    13,X
	ORA    12,X
	BEQ    *+79       ;abs = $D543
	AIX    #8
	PSHX   
	PSHH   
	AIX    #4
	JSR    $F586
	TSX    
	PSHX   
	PSHH   
	AIX    #6
	JSR    $F594
	TSX    
	JSR    $F57F
	TST    $4C
	JMP    $CD95
	JSR    $F59B
	TSX    
	LDA    3,X
	ADD    17,X
	PSHA   
	LDA    2,X
	ADC    16,X
	PSHA   
	PULH   
	PULX   
	STHX   25,SP
	LDA    $BF
	CMP    #$05
	CLRA   
	AIS    #16
	BCC    *+7       ;abs = $D531
	LDA    $BF
	NSA    
	AND    #$F0
	ADD    #$22
	LSLA   
	PSHA   
	TSX    
	LDA    9,X
	CLRH   
	PULX   
	STA    256,X
	LDA    10,SP
	STA    257,X
	AIS    #21
	RTS    
	TSX    
	LDA    24,X
	LSLA   
	CLRX   
	ROLX   
	ADD    24,SP
	STA    4,SP
	TXA    
	TSX    
	ADC    22,X
	PSHA   
	LDX    3,X
	PULH   
	RTS    
	AIS    #-10
	CLR    $C0
	MOV    #$04,$BF
	JSR    $D78D
	BCS    *+5       ;abs = $D56A
	CLRA   
	BRA    *+5       ;abs = $D56D
	NSA    
	AND    #$F0
	TSX    
	STA    2,X
	ADD    #$20
	LSLA   
	CLRH   
	TAX    
	CLRA   
	STA    256,X
	LDA    #$83
	STA    257,X
	JSR    $D783
	BCC    *+5       ;abs = $D586
	JSR    $D797
	LDA    4,SP
	ADD    #$21
	LSLA   
	TAX    
	CLRA   
	STA    256,X
	LDA    #$FF
	STA    257,X
	LDHX   $0100
	CPHX   #$003A
	BEQ    *+5       ;abs = $D5A1
	LDA    #$02
	CPHX   #$A604
	TSX    
	STA    3,X
	LDX    3,X
	STX    10,SP
	CLR    $BF
	JMP    $D76B
	JSR    $D78D
	BCS    *+5       ;abs = $D5B8
	CLRA   
	BRA    *+5       ;abs = $D5BB
	NSA    
	AND    #$F0
	TSX    
	STA    2,X
	ADD    #$20
	LSLA   
	CLRH   
	TAX    
	LDA    257,X
	BIT    #$0E
	BNE    *+57       ;abs = $D601
	JSR    $D783
	BCC    *+5       ;abs = $D5D2
	JSR    $D797
	LDA    4,SP
	ADD    #$20
	LSLA   
	TAX    
	CLRA   
	STA    256,X
	LDA    #$02
	STA    257,X
	JSR    $D783
	BCC    *+5       ;abs = $D5EA
	JSR    $D797
	LDA    4,SP
	ADD    #$21
	LSLA   
	TAX    
	CLRA   
	STA    256,X
	LDA    #$FF
	STA    257,X
	LDX    $BF
	CLR    171,X
	JMP    $D6EF
	JSR    $D783
	BCC    *+5       ;abs = $D609
	JSR    $D797
	LDA    4,SP
	ADD    #$20
	LSLA   
	TAX    
	LDA    257,X
	TSX    
	STA    6,X
	BMI    *+5       ;abs = $D61B
	JMP    $D6EF
	LDX    $F5
	CPX    #$03
	BHI    *+42       ;abs = $D649
	CLRA   
	JSR    $EFD6
	BRSET  2,$22,*+6       ;abs = $D62B
	BRCLR  5,$11,*+26       ;abs = $D642
	TSX    
	LDA    6,X
	AND    #$0E
	STA    6,X
	BRA    *+23       ;abs = $D649
	LDA    #$08
	TSX    
	STA    6,X
	BRA    *+26       ;abs = $D653
	LDA    #$0A
	TSX    
	STA    6,X
	BRA    *+19       ;abs = $D653
	LDA    #$0C
	TSX    
	STA    6,X
	BRA    *+12       ;abs = $D653
	TSX    
	LDA    6,X
	CMP    #$08
	BCC    *+5       ;abs = $D653
	JMP    $D6EF
	JSR    $D7A7
	BCS    *+3       ;abs = $D659
	CLRA   
	TSX    
	STA    3,X
	ADD    #$1A
	LSLA   
	CLRH   
	TAX    
	LDHX   256,X
	STHX   8,SP
	TSX    
	LDX    6,X
	CPX    #$0E
	BHI    *+71       ;abs = $D6B4
	CLRA   
	JSR    $F01B
	BRSET  7,$3F,*+11       ;abs = $D67E
	BRSET  3,$0A,*+12       ;abs = $D682
	BRSET  6,$0C,*+17       ;abs = $D68A
	BRCLR  7,$32,*-6       ;abs = $D676
	BHI    *+34       ;abs = $D6A1
	BIH    *+52       ;abs = $D6B5
	STA    ,X
	BCC    *+34       ;abs = $D6A6
	BPL    *+52       ;abs = $D6BA
	STA    ,X
	BNE    *+34       ;abs = $D6AB
	BCS    *-49       ;abs = $D65A
	STA    42789,X
	BRSET  2,$4F,*+98       ;abs = $D6F2
	BRA    *+5       ;abs = $D698
	LDX    #$10
	MUL    
	STA    4,SP
	STX    3,SP
	TSX    
	LDA    3,X
	ADD    #$23
	LSLA   
	LDHX   #$0100
	ADD    #$00
	PSHA   
	PSHH   
	PULA   
	ADC    #$00
	PSHA   
	PULH   
	PULX   
	STHX   5,SP
	LDHX   5,SP
	STHX   1,SP
	LDHX   10,X
	CPHX   8,SP
	BLE    *+29       ;abs = $D6DD
	JSR    $D7A7
	BCS    *+5       ;abs = $D6CA
	CLRA   
	BRA    *+5       ;abs = $D6CD
	NSA    
	AND    #$F0
	TSX    
	STA    3,X
	ADD    #$22
	LSLA   
	LDHX   5,SP
	PSHA   
	LDA    ,X
	PSHA   
	LDA    1,X
	BRA    *+109       ;abs = $D748
	LDHX   5,SP
	LDHX   12,X
	CPHX   8,SP
	BLE    *+11       ;abs = $D6F1
	JSR    $D79E
	CLRA   
	JSR    $D42E
	BRA    *+106       ;abs = $D759
	LDHX   5,SP
	LDHX   14,X
	CPHX   8,SP
	BLE    *+12       ;abs = $D706
	JSR    $D79E
	LDA    #$01
	JSR    $D42E
	BRA    *+85       ;abs = $D759
	LDHX   5,SP
	LDHX   16,X
	CPHX   8,SP
	BLE    *+12       ;abs = $D71B
	JSR    $D79E
	LDA    #$02
	JSR    $D42E
	BRA    *+64       ;abs = $D759
	LDHX   5,SP
	LDHX   18,X
	CPHX   8,SP
	BLE    *+11       ;abs = $D72F
	BSR    *+120       ;abs = $D79E
	LDA    #$03
	JSR    $D42E
	BRA    *+44       ;abs = $D759
	BSR    *+120       ;abs = $D7A7
	BCS    *+5       ;abs = $D736
	CLRA   
	BRA    *+5       ;abs = $D739
	NSA    
	AND    #$F0
	TSX    
	STA    3,X
	ADD    #$22
	LSLA   
	LDHX   5,SP
	PSHA   
	LDA    8,X
	PSHA   
	LDA    9,X
	CLRH   
	LDX    2,SP
	PSHA   
	LDA    2,SP
	STA    256,X
	PULA   
	STA    257,X
	AIS    #2
	PSHA   
	TPA    
	SEI    
	STA    $90
	PULA   
	LDA    $BF
	JSR    $CFE0
	PSHA   
	LDA    $90
	TAP    
	PULA   
	INC    $BF
	LDA    $BF
	TSX    
	CMP    9,X
	BCC    *+5       ;abs = $D775
	JMP    $D5B0
	BCLR   3,$F4
	TST    $C0
	BNE    *+5       ;abs = $D77E
	BCLR   0,$F4
	CPHX   #$10F4
	AIS    #10
	RTS    
	BSR    *+36       ;abs = $D7A7
	PSHA   
	PSHH   
	PULA   
	STA    7,SP
	PULA   
	RTS    
	JSR    $CD80
	ORA    $C0
	STA    $C0
	BSR    *+19       ;abs = $D7A7
	RTS    
	NSA    
	AND    #$F0
	STA    6,SP
	RTS    
	TSX    
	LDX    3,X
	LDA    3,SP
	PSHA   
	PULH   
	RTS    
	LDA    $BF
	CMP    #$05
	RTS    
	
	org $D7AC
	AIS    #-2
	JSR    $C490
	JSR    $C7D8
	MOV    #$FF,$04
	LDA    #$40
	STA    $18AC
	TSX    
	CLR    1,X
	JSR    $E8C7
	LDHX   #$E8AD
	STHX   $043D
	CLRA   
	TSX    
	STA    ,X
	JSR    $CD65
	TSX    
	STA    1,X
	JSR    $CD65
	TSX    
	STA    1,X
	BNE    *+5       ;abs = $D7DC
	LDA    #$01
	STA    ,X
	LDA    ,X
	JSR    $EAEE
	TSX    
	TST    1,X
	BNE    *+28       ;abs = $D7FF
	LDHX   $0104
	TXA    
	ORA    #$40
	TAX    
	STHX   $0104
	BRA    *+9       ;abs = $D7F8
	WAIT   
	BRCLR  3,$F4,*+6       ;abs = $D7F8
	JSR    $D55B
	LDA    $0105
	BIT    #$40
	BNE    *-12       ;abs = $D7F1
	LDX    $F5
	CPX    #$03
	BHI    *+106       ;abs = $D86D
	CLRA   
	JSR    $EFD6
	BRSET  2,$62,*+6       ;abs = $D80F
	BRSET  3,$09,*+14       ;abs = $D81A
	LDX    #$08
	BRA    *+11       ;abs = $D81C
	LDX    #$04
	BRA    *+7       ;abs = $D81C
	LDX    #$06
	CPHX   #$AE07
	CLRH   
	STHX   $0108
	BRA    *+77       ;abs = $D86D
	WAIT   
	BRCLR  2,$F4,*+14       ;abs = $D831
	JSR    $EC97
	BCLR   2,$F4
	BRCLR  4,$F4,*+60       ;abs = $D867
	
	DC.B   $8D				;**** Illegal OpCode
	
	BRA    *+56       ;abs = $D867
	LDHX   $013E
	CPHX   #$5A5A
	BNE    *+42       ;abs = $D861
	LDHX   $015E
	CPHX   #$A5A5
	BNE    *+34       ;abs = $D861
	LDHX   $017E
	CPHX   #$5A5A
	BNE    *+26       ;abs = $D861
	LDHX   $019E
	CPHX   #$A5A5
	BNE    *+18       ;abs = $D861
	LDHX   $01BE
	CPHX   #$5A5A
	BNE    *+10       ;abs = $D861
	LDHX   $01DE
	CPHX   #$A5A5
	BEQ    *+8       ;abs = $D867
	LDA    #$01
	JSR    $EAEE
	
	DC.B   $8D				;**** Illegal OpCode
	
	BRCLR  3,$F4,*-69       ;abs = $D822
	JSR    $D55B
	BRA    *-75       ;abs = $D822
	CLR    $8C
	MOV    #$0F,$8E
	MOV    $8E,$8E
	MOV    #$D8,$8C
	RTS    
	PSHH   
	BSET   7,$8C
	JSR    $CC00
	BSET   3,$5E
	PULH   
	RTI    
	CLR    $2A
	CLR    $25
	MOV    #$0A,$20
	MOV    #$25,$21
	MOV    #$C2,$27
	MOV    #$08,$26
	CLR    $26
	LDHX   #$35C2
	STHX   $28
	MOV    #$92,$23
	BSET   7,$22
	MOV    #$C0,$22
	RTS    
	PSHA   
	TSX    
	TST    ,X
	BEQ    *+6       ;abs = $D8AE
	BSET   2,$00
	PULH   
	RTS    
	BCLR   2,$00
	PULH   
	RTS    
	PSHA   
	AIS    #-4
	CLRH   
	TAX    
	LDX    590,X
	STX    1,SP
	LDA    5,SP
	LSLA   
	TAX    
	LDHX   194,X
	CPHX   #$0100
	BCC    *+11       ;abs = $D8D3
	CLRH   
	TAX    
	LDX    195,X
	STX    4,SP
	BRA    *+7       ;abs = $D8D8
	LDA    #$FF
	TSX    
	STA    3,X
	TSX    
	LDX    4,X
	LSLX   
	CLRH   
	LDA    215,X
	SUB    205,X
	PSHA   
	LDA    214,X
	SBC    204,X
	PSHA   
	PULH   
	PULX   
	STHX   2,SP
	BGT    *+9       ;abs = $D8F5
	TSX    
	CLR    2,X
	CLR    1,X
	BRA    *+13       ;abs = $D900
	TSX    
	TST    1,X
	BLE    *+8       ;abs = $D900
	LDX    #$FF
	CLRH   
	STHX   2,SP
	LDHX   2,SP
	BLE    *+51       ;abs = $D936
	TSX    
	LDA    3,X
	CMP    #$01
	BLS    *+44       ;abs = $D936
	LDA    4,X
	LSLA   
	LSLA   
	LSLA   
	PSHA   
	ADD    ,X
	PSHA   
	CLRA   
	ADC    #$00
	PSHA   
	LDA    2,X
	PULH   
	PULX   
	STA    510,X
	PULA   
	TSX    
	ADD    ,X
	PSHA   
	CLRA   
	ADC    #$00
	LDX    4,X
	LSLX   
	CLRH   
	PSHA   
	LDA    195,X
	SUB    #$02
	PULH   
	PULX   
	STA    550,X
	BRA    *+35       ;abs = $D957
	TSX    
	LDA    4,X
	LSLA   
	LSLA   
	LSLA   
	PSHA   
	ADD    ,X
	PSHA   
	CLRA   
	ADC    #$00
	PSHA   
	PULH   
	CLRA   
	PULX   
	STA    550,X
	PULA   
	TSX    
	ADD    ,X
	PSHA   
	CLRA   
	ADC    #$00
	PSHA   
	PULH   
	PULX   
	CLRA   
	STA    510,X
	TSX    
	LDX    4,X
	LSLX   
	CLRH   
	CLR    195,X
	CLR    194,X
	LDA    1,SP
	CMP    #$07
	BCC    *+7       ;abs = $D96C
	INC    1,SP
	BRA    *+5       ;abs = $D96F
	CLR    1,SP
	LDX    5,SP
	LDA    1,SP
	STA    590,X
	AIS    #5
	RTS    
	PSHA   
	AIS    #-3
	CMP    #$05
	BCS    *+3       ;abs = $D983
	CLRA   
	TSX    
	STA    1,X
	ADD    #$15
	LSLA   
	CLRH   
	TAX    
	PSHA   
	PSHH   
	PULA   
	STA    2,SP
	PULA   
	LDHX   256,X
	CPHX   #$00FF
	BLT    *+9       ;abs = $D9A2
	LDA    #$CC
	TSX    
	STA    2,X
	BRA    *+62       ;abs = $D9DE
	TSX    
	LDA    3,X
	CMP    #$05
	BCC    *+6       ;abs = $D9AD
	NSA    
	AND    #$F0
	STA    ,X
	LDA    ,X
	ADD    #$21
	LSLA   
	CLRH   
	TAX    
	LDX    257,X
	STX    3,SP
	LDA    4,SP
	CMP    #$05
	PSHA   
	PSHH   
	PULA   
	STA    3,SP
	PULA   
	BCC    *+8       ;abs = $D9CD
	NSA    
	AND    #$F0
	STA    2,SP
	LDA    2,SP
	ADD    #$20
	LSLA   
	TAX    
	LDA    257,X
	BIT    #$01
	BEQ    *+5       ;abs = $D9DE
	TSX    
	COM    2,X
	LDHX   $0100
	CPHX   #$003A
	BNE    *+39       ;abs = $DA0B
	TSX    
	LDX    3,X
	CPX    #$03
	BHI    *+59       ;abs = $DA26
	CLRA   
	JSR    $EFD6
	BRSET  2,$33,*+6       ;abs = $D9F7
	BRSET  6,$1E,*+42       ;abs = $DA1E
	TSX    
	LDA    2,X
	CLRH   
	TAX    
	STHX   $1892
	BRA    *+39       ;abs = $DA26
	TSX    
	LDA    2,X
	CLRH   
	TAX    
	STHX   $188F
	BRA    *+29       ;abs = $DA26
	TSX    
	LDA    3,X
	BEQ    *+6       ;abs = $DA14
	DBNZA  *+22       ;abs = $DA26
	BRA    *+12       ;abs = $DA1E
	TSX    
	LDA    2,X
	CLRH   
	TAX    
	STHX   $1889
	BRA    *+10       ;abs = $DA26
	TSX    
	LDA    2,X
	CLRH   
	TAX    
	STHX   $1886
	AIS    #4
	RTS    
	PSHA   
	PSHH   
	CMP    #$05
	BCS    *+5       ;abs = $DA32
	CLRA   
	BRA    *+5       ;abs = $DA35
	NSA    
	AND    #$F0
	TSX    
	STA    ,X
	ADD    #$20
	LSLA   
	CLRH   
	TAX    
	LDA    257,X
	BIT    #$01
	BEQ    *+97       ;abs = $DAA2
	LDHX   $0100
	CPHX   #$003A
	BNE    *+49       ;abs = $DA7A
	TSX    
	LDX    1,X
	CPX    #$03
	BHI    *+65       ;abs = $DA91
	CLRA   
	JSR    $EFD6
	BRSET  2,$9E,*+6       ;abs = $DA5C
	BCLR   0,$29
	ASR    $1F
	BRSET  2,$1E,*+8       ;abs = $DA65
	LDHX   #$1891
	LDA    ,X
	AND    #$F3
	ORA    #$04
	STA    ,X
	BRA    *+40       ;abs = $DA91
	BCLR   6,$04
	BSET   6,$05
	LDHX   #$188E
	LDA    ,X
	AND    #$F3
	ORA    #$04
	STA    ,X
	BRA    *+25       ;abs = $DA91
	TSX    
	LDA    1,X
	BEQ    *+7       ;abs = $DA84
	CBEQA  #$01,*+20       ;abs = $DA93
	BRA    *+116       ;abs = $DAF6
	BCLR   6,$06
	BSET   6,$07
	LDHX   #$1888
	LDA    ,X
	AND    #$F3
	ORA    #$04
	STA    ,X
	BRA    *+101       ;abs = $DAF6
	BCLR   7,$06
	BSET   7,$07
	LDHX   #$1885
	LDA    ,X
	AND    #$F3
	ORA    #$04
	STA    ,X
	BRA    *+86       ;abs = $DAF6
	LDHX   $0100
	CPHX   #$003A
	BNE    *+45       ;abs = $DAD5
	TSX    
	LDX    1,X
	CPX    #$03
	BHI    *+71       ;abs = $DAF6
	CLRA   
	JSR    $EFD6
	BRSET  2,$3F,*+6       ;abs = $DABB
	BRCLR  7,$24,*+51       ;abs = $DAEB
	LDHX   #$1891
	LDA    ,X
	AND    #$F3
	STA    ,X
	BSET   3,$04
	BSET   3,$05
	BRA    *+48       ;abs = $DAF6
	LDHX   #$188E
	LDA    ,X
	AND    #$F3
	STA    ,X
	BSET   2,$04
	BSET   2,$05
	BRA    *+35       ;abs = $DAF6
	TSX    
	LDA    1,X
	BEQ    *+6       ;abs = $DADE
	DBNZA  *+28       ;abs = $DAF6
	BRA    *+15       ;abs = $DAEB
	LDHX   #$1888
	LDA    ,X
	AND    #$F3
	STA    ,X
	BSET   1,$04
	BSET   1,$05
	BRA    *+13       ;abs = $DAF6
	LDHX   #$1885
	LDA    ,X
	AND    #$F3
	STA    ,X
	BSET   0,$04
	BSET   0,$05
	AIS    #2
	RTS    
	LDA    $C1
	JSR    $D8B2
	LDA    $C1
	CMP    #$04
	BCC    *+22       ;abs = $DB18
	CMP    #$01
	BNE    *+15       ;abs = $DB15
	LDHX   $0100
	CPHX   #$0037
	BNE    *+7       ;abs = $DB15
	MOV    #$04,$C1
	BRA    *+7       ;abs = $DB1A
	INC    $C1
	CPHX   #$3FC1
	LDA    $C1
	CMP    #$02
	BCC    *+24       ;abs = $DB36
	LDHX   $0100
	CPHX   #$0037
	BNE    *+16       ;abs = $DB36
	ADD    #$02
	LDX    #$05
	MUL    
	CLRH   
	TAX    
	LDHX   63275,X
	CLR    ,X
	BRA    *+17       ;abs = $DB45
	LDX    #$05
	MUL    
	CLRH   
	TAX    
	LDHX   63275,X
	CLR    ,X
	LDA    $C1
	LDX    #$05
	MUL    
	CLRH   
	TAX    
	LDA    63272,X
	LDHX   63273,X
	JMP    ,X
	PSHX   
	PSHH   
	PSHA   
	AIS    #-10
	CMP    #$05
	BCS    *+3       ;abs = $DB59
	CLRA   
	TSX    
	STA    2,X
	ADD    #$15
	LSLA   
	CLRH   
	TAX    
	PSHA   
	PSHH   
	PULA   
	STA    3,SP
	PULA   
	LDHX   256,X
	CPHX   #$00FF
	BNE    *+5       ;abs = $DB74
	JMP    $DDB2
	JSR    $DDBD
	BCC    *+8       ;abs = $DB7F
	NSA    
	AND    #$F0
	TSX    
	STA    1,X
	TSX    
	LDA    1,X
	ADD    #$20
	LSLA   
	CLRH   
	TAX    
	LDX    257,X
	STX    8,SP
	JSR    $DDBD
	JSR    $DDB5
	BCC    *+5       ;abs = $DB98
	JSR    $DDC3
	LDA    3,SP
	ADD    #$21
	LSLA   
	TAX    
	LDHX   256,X
	STHX   4,SP
	LDX    $F5
	CPX    #$03
	BHI    *+46       ;abs = $DBD8
	CLRA   
	JSR    $EFD6
	BRSET  2,$26,*+6       ;abs = $DBB6
	BRCLR  4,$11,*+28       ;abs = $DBCF
	TSX    
	LDA    7,X
	AND    #$8E
	BRA    *+27       ;abs = $DBD6
	TSX    
	LDA    7,X
	AND    #$F1
	ORA    #$08
	BRA    *+18       ;abs = $DBD6
	TSX    
	LDA    7,X
	AND    #$F1
	ORA    #$0A
	BRA    *+9       ;abs = $DBD6
	TSX    
	LDA    7,X
	AND    #$F1
	ORA    #$0C
	STA    7,X
	TSX    
	LDX    7,X
	CPX    #$84
	BHI    *+35       ;abs = $DC00
	CLRA   
	JSR    $EFFA
	TAP    
	JMP    0,X
	ADD    63490,X
	JSR    12804,X
	JSR    23168,X
	ADD    63618,X
	JSR    12932,X
	JMP    7573,X
	CLR    4,X
	CLR    3,X
	JMP    $DD5A
	JSR    $DDBD
	BCS    *+5       ;abs = $DC08
	CLRA   
	BRA    *+5       ;abs = $DC0B
	NSA    
	AND    #$F0
	TSX    
	STA    2,X
	ADD    #$20
	LSLA   
	CLRH   
	TAX    
	LDA    257,X
	BIT    #$80
	BNE    *+5       ;abs = $DC1D
	JMP    $DD54
	TSX    
	LDX    10,X
	LSLX   
	CLRH   
	PSHH   
	PULA   
	STA    3,SP
	LDHX   500,X
	STHX   6,SP
	TSX    
	LDX    10,X
	CLRH   
	LDA    234,X
	TAX    
	STHX   4,SP
	JSR    $DDBD
	BCC    *+5       ;abs = $DC40
	JSR    $DDC3
	LDA    3,SP
	ADD    #$22
	LSLA   
	LDX    11,SP
	CPX    #$05
	BCS    *+19       ;abs = $DC5E
	PSHA   
	PSHH   
	PULA   
	PSHH   
	STA    3,SP
	PULA   
	STA    4,SP
	PULA   
	STA    2,SP
	BRA    *+15       ;abs = $DC6B
	STX    3,SP
	STA    2,SP
	PSHA   
	PSHH   
	PULA   
	STA    2,SP
	PULA   
	LDA    3,SP
	ADD    #$0B
	LSLA   
	TAX    
	LDHX   256,X
	PSHH   
	CLRH   
	TXA    
	LDX    3,SP
	LDHX   256,X
	PSHX   
	SUB    1,SP
	PSHA   
	PSHH   
	PULA   
	TSX    
	STA    1,X
	LDA    2,X
	SBC    1,X
	PSHA   
	PULH   
	PULX   
	STHX   11,SP
	AIS    #2
	BLE    *+21       ;abs = $DCAB
	LDHX   12,SP
	CPHX   9,SP
	BGE    *+13       ;abs = $DCAB
	TSX    
	TST    6,X
	BNE    *+4       ;abs = $DCA7
	DEC    5,X
	DEC    6,X
	BRA    *+25       ;abs = $DCC2
	CLRA   
	TSX    
	SUB    9,X
	PSHA   
	CLRA   
	SBC    8,X
	PSHA   
	PULH   
	PULX   
	CPHX   12,SP
	BLE    *+9       ;abs = $DCC2
	TSX    
	INC    6,X
	BNE    *+4       ;abs = $DCC2
	INC    5,X
	LDHX   6,SP
	CPHX   #$0258
	BLE    *+7       ;abs = $DCCF
	LDHX   #$0258
	BRA    *+57       ;abs = $DD06
	CPHX   #$FDA8
	BGE    *+55       ;abs = $DD09
	TSX    
	LDX    10,X
	CLRH   
	LDA    229,X
	CMP    #$11
	BLS    *+39       ;abs = $DD03
	CPX    #$05
	JSR    $DDB5
	BCC    *+5       ;abs = $DCE8
	STX    3,SP
	LDA    3,SP
	ADD    #$0B
	LSLA   
	TAX    
	LDHX   256,X
	CPHX   #$0320
	BLE    *+13       ;abs = $DD03
	TSX    
	LDX    10,X
	CLRH   
	DEC    229,X
	LDHX   #$FDAE
	BRA    *+5       ;abs = $DD06
	LDHX   #$FDA8
	STHX   6,SP
	LDHX   6,SP
	PSHX   
	PSHH   
	LDX    #$06
	CLRH   
	JSR    $EF07
	AIS    #2
	TXA    
	PSHH   
	TSX    
	ADD    5,X
	STA    5,X
	PULA   
	ADC    4,X
	STA    4,X
	LDX    11,X
	LSLX   
	LDA    7,SP
	CLRH   
	STA    501,X
	LDA    6,SP
	STA    500,X
	TSX    
	LDX    10,X
	CLRH   
	LDX    229,X
	CPHX   4,SP
	BLE    *+20       ;abs = $DD4F
	TXA    
	LDHX   4,SP
	CPHX   #$0011
	BGE    *+7       ;abs = $DD4B
	LDX    #$11
	CLRH   
	BRA    *+14       ;abs = $DD57
	CLRH   
	TAX    
	BRA    *+10       ;abs = $DD57
	TSX    
	TST    3,X
	BLE    *+8       ;abs = $DD5A
	LDX    #$FF
	CLRH   
	STHX   4,SP
	BSR    *+99       ;abs = $DDBD
	BCS    *+5       ;abs = $DD61
	CLRA   
	BRA    *+5       ;abs = $DD64
	NSA    
	AND    #$F0
	TSX    
	STA    1,X
	ADD    #$21
	LSLA   
	CLRH   
	TAX    
	BSR    *+73       ;abs = $DDB5
	LDX    256,X
	PSHX   
	PULH   
	CLRX   
	CPHX   #$1A00
	BNE    *+21       ;abs = $DD8C
	BSR    *+68       ;abs = $DDBD
	BCC    *+4       ;abs = $DD7F
	BSR    *+70       ;abs = $DDC3
	TSX    
	LDA    2,X
	ADD    #$21
	LSLA   
	PSHA   
	LDA    3,X
	ORA    #$1A
	BRA    *+17       ;abs = $DD9B
	BSR    *+49       ;abs = $DDBD
	BCC    *+4       ;abs = $DD92
	BSR    *+51       ;abs = $DDC3
	TSX    
	LDA    2,X
	ADD    #$21
	LSLA   
	PSHA   
	LDA    3,X
	CLRH   
	PULX   
	STA    256,X
	LDA    5,SP
	STA    257,X
	TSX    
	LDA    10,X
	JSR    $DA29
	TSX    
	LDA    10,X
	JSR    $D97B
	AIS    #13
	RTS    
	
	org $DDB5
	PSHA   
	PSHH   
	PULA   
	STA    6,SP
	PULA   
	RTS    
	LDA    13,SP
	CMP    #$05
	RTS    
	NSA    
	AND    #$F0
	STA    5,SP
	RTS    
	AIS    #-6
	LDA    $F4
	AND    #$01
	JSR    $D8A5
	BCLR   0,$F4
	TSX    
	CLR    2,X
	LDA    2,X
	CMP    #$05
	BCS    *+5       ;abs = $DDE1
	CLRA   
	BRA    *+5       ;abs = $DDE4
	NSA    
	AND    #$F0
	STA    1,X
	ADD    #$20
	LSLA   
	CLRH   
	TAX    
	LDA    257,X
	BIT    #$01
	BEQ    *+15       ;abs = $DDFF
	LDA    $C1
	TSX    
	CMP    2,X
	BNE    *+5       ;abs = $DDFC
	JSR    $C6D9
	JMP    $DF06
	LDX    3,SP
	LDA    224,X
	TAX    
	STHX   4,SP
	LDA    3,SP
	CMP    #$05
	PSHA   
	PSHH   
	PULA   
	STA    2,SP
	PULA   
	BCC    *+8       ;abs = $DE1C
	NSA    
	AND    #$F0
	STA    1,SP
	LDA    1,SP
	ADD    #$21
	LSLA   
	TAX    
	LDX    257,X
	STX    6,SP
	LDA    3,SP
	CMP    #$05
	PSHA   
	PSHH   
	PULA   
	STA    3,SP
	PULA   
	BCC    *+5       ;abs = $DE3A
	STA    2,SP
	LDA    2,SP
	ADD    #$15
	LSLA   
	TAX    
	LDHX   256,X
	CPHX   #$00FF
	BLT    *+7       ;abs = $DE4F
	LDA    #$CC
	TSX    
	STA    5,X
	TSX    
	LDX    2,X
	CLRH   
	LDA    6,SP
	CMP    229,X
	BCC    *+7       ;abs = $DE5F
	LDA    229,X
	TSX    
	STA    5,X
	TSX    
	LDA    5,X
	ADD    4,X
	STA    4,X
	CLRA   
	ADC    3,X
	STA    3,X
	LDHX   4,SP
	CPHX   #$00FF
	BCC    *+61       ;abs = $DEAE
	LDHX   $0100
	CPHX   #$003A
	BNE    *+31       ;abs = $DE98
	TSX    
	LDX    2,X
	CPX    #$03
	BHI    *+125       ;abs = $DEFD
	CLRA   
	JSR    $EFD6
	BRSET  2,$75,*+6       ;abs = $DE8C
	BRSET  4,$17,*+31       ;abs = $DEA8
	BSET   7,$04
	BSET   7,$05
	BRA    *+109       ;abs = $DEFD
	BSET   6,$04
	BSET   6,$05
	BRA    *+103       ;abs = $DEFD
	TSX    
	LDA    2,X
	BEQ    *+7       ;abs = $DEA2
	CBEQA  #$01,*+11       ;abs = $DEA8
	BRA    *+93       ;abs = $DEFD
	BSET   6,$06
	BSET   6,$07
	BRA    *+87       ;abs = $DEFD
	BSET   7,$06
	BSET   7,$07
	BRA    *+81       ;abs = $DEFD
	LDHX   $0100
	CPHX   #$003A
	BNE    *+31       ;abs = $DED3
	TSX    
	LDX    2,X
	CPX    #$03
	BHI    *+43       ;abs = $DEE6
	CLRA   
	JSR    $EFD6
	BRSET  2,$23,*+6       ;abs = $DEC7
	BRSET  4,$16,*+30       ;abs = $DEE2
	BCLR   7,$04
	BSET   7,$05
	BRA    *+27       ;abs = $DEE6
	BCLR   6,$04
	BSET   6,$05
	BRA    *+21       ;abs = $DEE6
	TSX    
	LDA    2,X
	BEQ    *+6       ;abs = $DEDC
	DBNZA  *+14       ;abs = $DEE6
	BRA    *+8       ;abs = $DEE2
	BCLR   6,$06
	BSET   6,$07
	BRA    *+6       ;abs = $DEE6
	BCLR   7,$06
	BSET   7,$07
	LDA    $C1
	TSX    
	CMP    2,X
	BNE    *+5       ;abs = $DEF0
	JSR    $C6D9
	TSX    
	LDA    5,X
	CMP    #$80
	BLS    *+8       ;abs = $DEFD
	INC    4,X
	BNE    *+4       ;abs = $DEFD
	INC    3,X
	TSX    
	LDX    2,X
	
	org $DF00
	CLRH   
	LDA    5,SP
	STA    224,X
	TSX    
	INC    2,X
	LDA    2,X
	CMP    #$05
	BCC    *+5       ;abs = $DF12
	JMP    $DDD8
	AIS    #6
	RTS    
	RTS    
	AIS    #-2
	LDA    $EF
	CMP    #$05
	BCS    *+5       ;abs = $DF21
	CLRA   
	BRA    *+5       ;abs = $DF24
	NSA    
	AND    #$F0
	ADD    #$20
	LSLA   
	CLRH   
	TAX    
	LDA    257,X
	BIT    #$80
	BEQ    *+90       ;abs = $DF88
	LDA    $EF
	CMP    #$05
	CLRA   
	BCC    *+7       ;abs = $DF3C
	LDA    $EF
	NSA    
	AND    #$F0
	ADD    #$20
	LSLA   
	TAX    
	LDA    257,X
	AND    #$0E
	CMP    #$06
	BCS    *+65       ;abs = $DF88
	LDA    $EF
	CMP    #$05
	CLRA   
	BCC    *+7       ;abs = $DF55
	LDA    $EF
	NSA    
	AND    #$F0
	ADD    #$20
	LSLA   
	TAX    
	LDA    257,X
	AND    #$70
	CMP    #$70
	BNE    *+40       ;abs = $DF88
	LDA    $EF
	CMP    #$05
	BCS    *+3       ;abs = $DF69
	CLRA   
	ADD    #$15
	LSLA   
	LDHX   #$0100
	ADD    #$00
	PSHA   
	PSHH   
	PULA   
	ADC    #$00
	PSHA   
	PULH   
	PULX   
	STHX   1,SP
	LDHX   ,X
	CPHX   #$00FF
	BGE    *+7       ;abs = $DF88
	LDHX   1,SP
	LDHX   ,X
	LDA    $EF
	CMP    #$04
	BCC    *+5       ;abs = $DF91
	INC    $EF
	CPHX   #$3FEF
	AIS    #2
	RTS    
	PSHH   
	LDA    $0109
	TSX    
	STA    ,X
	BIT    #$01
	BNE    *+5       ;abs = $DFA3
	BCLR   0,$06
	CPHX   #$1006
	BSET   0,$07
	BIT    #$02
	BNE    *+5       ;abs = $DFAE
	BCLR   1,$06
	CPHX   #$1206
	BSET   1,$07
	BIT    #$04
	BNE    *+5       ;abs = $DFB9
	BCLR   2,$06
	CPHX   #$1406
	BSET   2,$07
	BIT    #$08
	BNE    *+5       ;abs = $DFC4
	BCLR   3,$06
	CPHX   #$1606
	BSET   3,$07
	LDA    $F0
	CMP    #$05
	BCS    *+5       ;abs = $DFD1
	CLRA   
	BRA    *+5       ;abs = $DFD4
	NSA    
	AND    #$F0
	ADD    #$20
	LSLA   
	CLRH   
	TAX    
	LDA    257,X
	BIT    #$01
	BEQ    *+7       ;abs = $DFE5
	LDX    #$DC
	CLRH   
	BRA    *+5       ;abs = $DFE8
	LDHX   #$014A
	LDA    $F0
	JSR    $DB4F
	TST    $F0
	BNE    *+10       ;abs = $DFF9
	LDA    $0143
	STA    $F6
	JMP    $E081
	LDA    $F0
	CMP    #$05
	BCS    *+5       ;abs = $E002
	CLRA   
	BRA    *+5       ;abs = $E005
	NSA    
	AND    #$F0
	ADD    #$20
	LSLA   
	CLRH   
	TAX    
	LDA    257,X
	BIT    #$0E
	BEQ    *+114       ;abs = $E081
	LDA    $F0
	CMP    #$05
	CLRA   
	BCC    *+7       ;abs = $E01D
	LDA    $F0
	NSA    
	AND    #$F0
	ADD    #$20
	LSLA   
	TAX    
	LDA    257,X
	BIT    #$01
	BNE    *+91       ;abs = $E081
	LDA    $F0
	CMP    #$05
	CLRA   
	BCC    *+7       ;abs = $E034
	LDA    $F0
	NSA    
	AND    #$F0
	ADD    #$21
	LSLA   
	TAX    
	LDHX   256,X
	PSHX   
	PSHH   
	LDA    $F6
	CLRX   
	JSR    $EF3A
	BLE    *+24       ;abs = $E05C
	LDA    $F0
	CMP    #$05
	CLRA   
	BCC    *+7       ;abs = $E052
	LDA    $F0
	NSA    
	AND    #$F0
	ADD    #$21
	LSLA   
	CLRH   
	TAX    
	LDX    257,X
	STX    $F6
	LDA    $F0
	CMP    #$04
	BNE    *+33       ;abs = $E081
	LDA    $F6
	SUB    #$0A
	STA    $F6
	CMP    #$33
	BCC    *+7       ;abs = $E071
	MOV    #$33,$F6
	BRA    *+9       ;abs = $E078
	CMP    #$E0
	BLS    *+5       ;abs = $E078
	MOV    #$E1,$F6
	BSET   7,$80
	LDX    $F6
	CLRH   
	STHX   $84
	BSET   0,$80
	LDA    $F0
	CMP    #$04
	BCC    *+6       ;abs = $E08B
	INC    $F0
	PULH   
	RTS    
	CLR    $F0
	PULH   
	RTS    
	AIS    #-7
	LDA    $F7
	CMP    #$05
	BCS    *+3       ;abs = $E098
	CLRA   
	ADD    #$15
	LSLA   
	CLRH   
	TAX    
	LDHX   256,X
	CPHX   #$00FF
	BNE    *+5       ;abs = $E0A9
	JMP    $E212
	JSR    $E22D
	BCC    *+5       ;abs = $E0B1
	JSR    $E233
	ADD    #$20
	LSLA   
	CLRH   
	TAX    
	LDA    257,X
	BMI    *+5       ;abs = $E0BE
	JMP    $E20A
	AND    #$0E
	CMP    #$06
	BEQ    *+5       ;abs = $E0C7
	JMP    $E20A
	JSR    $E22D
	BCC    *+5       ;abs = $E0CF
	JSR    $E233
	ADD    #$22
	LSLA   
	LDX    $F7
	CPX    #$05
	BCS    *+11       ;abs = $E0E1
	PSHA   
	PSHH   
	PULA   
	STA    4,SP
	PULA   
	BRA    *+5       ;abs = $E0E4
	STX    3,SP
	TAX    
	LDA    3,SP
	ADD    #$1A
	LSLA   
	PSHX   
	TAX    
	LDHX   256,X
	PSHH   
	CLRH   
	TXA    
	LDX    2,SP
	LDHX   256,X
	STX    2,SP
	SUB    2,SP
	PSHA   
	PSHH   
	PULA   
	TSX    
	STA    2,X
	LDA    1,X
	SBC    2,X
	PSHA   
	PULH   
	PULX   
	STHX   8,SP
	JSR    $E22D
	AIS    #2
	BCC    *+5       ;abs = $E11B
	JSR    $E233
	ADD    #$21
	LSLA   
	CLRH   
	TAX    
	LDX    257,X
	STHX   4,SP
	LDHX   6,SP
	BLE    *+34       ;abs = $E14B
	LDX    $F7
	LSLX   
	LDA    7,SP
	CLRH   
	ADD    491,X
	PSHA   
	LDA    7,SP
	ADC    490,X
	JSR    $E218
	ADD    6,SP
	STA    6,SP
	TXA    
	ADC    5,SP
	BRA    *+52       ;abs = $E17D
	TSX    
	COM    5,X
	NEG    6,X
	BNE    *+4       ;abs = $E154
	INC    5,X
	LDX    $F7
	LSLX   
	LDA    7,SP
	CLRH   
	ADD    491,X
	PSHA   
	LDA    7,SP
	ADC    490,X
	JSR    $E218
	STA    1,SP
	LDA    6,SP
	SUB    1,SP
	STA    6,SP
	LDA    5,SP
	STX    1,SP
	SBC    1,SP
	STA    5,SP
	LDX    3,SP
	LDA    491,X
	STA    1,SP
	LDA    490,X
	AND    #$0F
	PSHA   
	LDA    8,SP
	AND    #$0F
	PSHA   
	LDA    10,SP
	ADD    3,SP
	STA    491,X
	PULA   
	ADC    1,SP
	STA    490,X
	AIS    #2
	LDHX   4,SP
	CPHX   #$0066
	BGE    *+8       ;abs = $E1B5
	LDX    #$66
	CLRH   
	STHX   4,SP
	TSX    
	TST    3,X
	BLE    *+8       ;abs = $E1C0
	LDX    #$FF
	CLRH   
	STHX   4,SP
	LDA    $F7
	CMP    #$05
	BCS    *+5       ;abs = $E1C9
	CLRA   
	BRA    *+5       ;abs = $E1CC
	NSA    
	AND    #$F0
	ADD    #$21
	LSLA   
	CLRH   
	TAX    
	LDX    256,X
	PSHX   
	PULH   
	CLRX   
	CPHX   #$1A00
	BNE    *+19       ;abs = $E1ED
	BSR    *+81       ;abs = $E22D
	BCC    *+4       ;abs = $E1E2
	BSR    *+83       ;abs = $E233
	ADD    #$21
	LSLA   
	PSHA   
	TSX    
	LDA    4,X
	ORA    #$1A
	BRA    *+15       ;abs = $E1FA
	BSR    *+64       ;abs = $E22D
	BCC    *+4       ;abs = $E1F3
	BSR    *+66       ;abs = $E233
	ADD    #$21
	LSLA   
	PSHA   
	TSX    
	LDA    4,X
	CLRH   
	PULX   
	STA    256,X
	LDA    5,SP
	STA    257,X
	LDA    $F7
	JSR    $D97B
	LDA    $F7
	CMP    #$04
	BCC    *+5       ;abs = $E213
	INC    $F7
	CPHX   #$3FF7
	AIS    #7
	RTS    
	STA    4,SP
	LDA    #$0C
	PSHA   
	LDA    4,SP
	STX    6,SP
	LDX    5,SP
	JSR    $EF22
	AIS    #1
	RTS    
	LDA    $F7
	CMP    #$05
	CLRA   
	RTS    
	LDA    $F7
	NSA    
	AND    #$F0
	RTS    
	AIS    #-10
	JSR    $E429
	BCS    *+5       ;abs = $E243
	CLRA   
	BRA    *+5       ;abs = $E246
	NSA    
	AND    #$F0
	ADD    #$20
	LSLA   
	CLRH   
	TAX    
	LDA    257,X
	AND    #$0E
	CMP    #$04
	BCC    *+5       ;abs = $E257
	JMP    $E314
	JSR    $E429
	PSHA   
	PSHH   
	PULA   
	STA    3,SP
	PULA   
	BCC    *+8       ;abs = $E269
	NSA    
	AND    #$F0
	STA    2,SP
	LDA    2,SP
	ADD    #$22
	LSLA   
	TAX    
	LDHX   256,X
	TXA    
	PSHH   
	PULX   
	PSHA   
	JSR    $EF9A
	TSX    
	JSR    $F5AC
	TSX    
	JSR    $F58D
	COMA   
	RTI    
	BRSET  0,$00,*-48       ;abs = $E255
	AND    41,X
	TSX    
	LDX    3,X
	LDA    3,SP
	STA    17,SP
	LDA    2,SP
	STA    16,SP
	LDA    1,SP
	STA    15,SP
	CLRA   
	AIS    #12
	BCC    *+4       ;abs = $E2A6
	LDA    $F1
	ADD    #$10
	LSLA   
	CLRH   
	PSHX   
	TAX    
	LDHX   256,X
	TXA    
	PSHH   
	PULX   
	PSHA   
	JSR    $EF9A
	TSX    
	JSR    $F5AC
	LDA    4,X
	PSHA   
	LDX    9,X
	PSHX   
	TSX    
	LDA    14,X
	PSHA   
	LDA    13,X
	PSHA   
	TSX    
	PSHX   
	PSHH   
	AIX    #4
	JSR    $F594
	AIX    #14
	JSR    $EF80
	TSX    
	AIX    #18
	JSR    $F5A6
	CBEQA  #$88,*+3       ;abs = $E2DE
	BRSET  0,$A7,*+16       ;abs = $E2EE
	BCC    *+12       ;abs = $E2ED
	CLRX   
	CLRH   
	STHX   8,SP
	LDHX   #$4188
	BRA    *+22       ;abs = $E301
	TSX    
	AIX    #5
	JSR    $F5A6
	COMA   
	CLR    ,X
	BRSET  0,$00,*+38       ;abs = $E31B
	BRCLR  5,$5F,*-113       ;abs = $E287
	STHX   8,SP
	LDHX   #$437F
	STHX   6,SP
	TSX    
	AIX    #5
	JSR    $F59B
	LDX    $F1
	CLRH   
	LDA    4,SP
	STA    234,X
	AIS    #4
	TST    $F5
	BEQ    *+37       ;abs = $E33B
	JSR    $E429
	BCS    *+3       ;abs = $E31E
	CLRA   
	ADD    #$1A
	LSLA   
	LDX    $010E
	PSHA   
	LDA    $010F
	PSHX   
	LDX    2,SP
	PSHA   
	LDA    2,SP
	STA    256,X
	PULA   
	STA    257,X
	AIS    #2
	BRA    *+115       ;abs = $E3AC
	JSR    $E429
	BCS    *+5       ;abs = $E343
	CLRA   
	BRA    *+5       ;abs = $E346
	NSA    
	AND    #$F0
	ADD    #$20
	LSLA   
	TAX    
	LDA    257,X
	AND    #$70
	CMP    #$70
	BCC    *+91       ;abs = $E3AC
	JSR    $E429
	PSHA   
	PSHH   
	PULA   
	STA    6,SP
	PULA   
	BCC    *+8       ;abs = $E365
	NSA    
	AND    #$F0
	STA    5,SP
	LDA    5,SP
	ADD    #$20
	LSLA   
	TAX    
	LDA    257,X
	AND    #$70
	CLRX   
	LSRX   
	RORA   
	LSRX   
	RORA   
	LSRX   
	RORA   
	LSRX   
	RORA   
	STA    10,SP
	CMP    #$04
	CLRA   
	BCC    *+5       ;abs = $E385
	LDA    10,SP
	ADD    #$07
	LSLA   
	STA    1,SP
	CLRA   
	LDX    $F1
	CPX    #$05
	BCC    *+3       ;abs = $E393
	TXA    
	LDX    1,SP
	ADD    #$1A
	LSLA   
	LDHX   256,X
	PSHH   
	CLRH   
	PSHX   
	TAX    
	LDA    2,SP
	STA    256,X
	PULA   
	STA    257,X
	PULA   
	BSR    *+125       ;abs = $E429
	BCS    *+5       ;abs = $E3B3
	CLRA   
	BRA    *+5       ;abs = $E3B6
	NSA    
	AND    #$F0
	ADD    #$20
	LSLA   
	TAX    
	LDA    257,X
	BIT    #$01
	BEQ    *+5       ;abs = $E3C4
	LDX    #$3C
	CPHX   #$AE5A
	CLRH   
	LDA    $F1
	JSR    $DB4F
	JSR    $DAF9
	LDHX   $010A
	CPHX   $010E
	BLT    *+18       ;abs = $E3E7
	LDHX   $010E
	CPHX   #$3700
	BGT    *+10       ;abs = $E3E7
	LDHX   $010E
	CPHX   #$F600
	BGE    *+10       ;abs = $E3EF
	LDHX   $0104
	TXA    
	ORA    #$08
	BRA    *+8       ;abs = $E3F5
	LDHX   $0104
	TXA    
	AND    #$F7
	TAX    
	STHX   $0104
	LDHX   $011E
	CPHX   #$0ED8
	BLE    *+10       ;abs = $E409
	LDHX   $011E
	CPHX   #$1A90
	BLT    *+10       ;abs = $E411
	LDHX   $0104
	TXA    
	ORA    #$10
	BRA    *+8       ;abs = $E417
	LDHX   $0104
	TXA    
	AND    #$EF
	TAX    
	STHX   $0104
	LDA    $F1
	CMP    #$04
	BCC    *+5       ;abs = $E424
	INC    $F1
	CPHX   #$3FF1
	AIS    #10
	RTS    
	LDA    $F1
	CMP    #$05
	RTS    
	PSHH   
	LDA    $0105
	BIT    #$40
	BEQ    *+123       ;abs = $E4AF
	LDA    $0109
	TSX    
	STA    ,X
	INC    $F2
	LDA    $01C1
	BIT    #$80
	BEQ    *+9       ;abs = $E44B
	LDA    $0105
	BIT    #$10
	BEQ    *+8       ;abs = $E451
	LDA    $F2
	CMP    #$60
	BLS    *+12       ;abs = $E45B
	LDHX   $0104
	TXA    
	ORA    #$80
	TAX    
	STHX   $0104
	LDA    $0105
	BIT    #$80
	BEQ    *+60       ;abs = $E49C
	LDA    $0105
	BIT    #$08
	BNE    *+9       ;abs = $E470
	LDA    $0105
	BIT    #$10
	BEQ    *+39       ;abs = $E495
	LDA    $0105
	BIT    #$08
	BEQ    *+8       ;abs = $E47D
	TSX    
	LDA    ,X
	ORA    #$01
	BRA    *+6       ;abs = $E481
	TSX    
	LDA    ,X
	AND    #$FE
	STA    ,X
	LDA    $0105
	BIT    #$10
	BEQ    *+7       ;abs = $E48E
	LDA    ,X
	ORA    #$02
	BRA    *+5       ;abs = $E491
	LDA    ,X
	AND    #$FD
	STA    ,X
	EOR    #$08
	CPHX   #$A6FF
	TSX    
	STA    ,X
	CLRH   
	BRA    *+17       ;abs = $E4AB
	LDA    $F2
	AND    #$03
	PSHA   
	LDX    #$01
	TXA    
	CLRX   
	JSR    $EF2E
	PULH   
	PSHX   
	PULH   
	TAX    
	STHX   $0108
	PULH   
	RTS    
	LDA    $F3
	CMP    #$05
	BCS    *+5       ;abs = $E4BA
	CLRA   
	BRA    *+5       ;abs = $E4BD
	NSA    
	AND    #$F0
	ADD    #$20
	LSLA   
	CLRH   
	TAX    
	LDA    257,X
	BIT    #$01
	BEQ    *+5       ;abs = $E4CC
	LDX    #$14
	CPHX   #$AE1E
	CLRH   
	LDA    $F3
	JSR    $DB4F
	LDA    $F3
	CMP    #$04
	BCC    *+5       ;abs = $E4DD
	INC    $F3
	CPHX   #$3FF3
	LDX    $01C2
	PSHX   
	PULH   
	CLRX   
	CPHX   #$1A00
	BNE    *+8       ;abs = $E4F0
	BSET   6,$09
	BSET   6,$08
	BRA    *+6       ;abs = $E4F4
	BSET   6,$09
	BCLR   6,$08
	BRCLR  1,$F4,*+7       ;abs = $E4FB
	BSET   2,$F4
	BCLR   1,$F4
	RTS    
	LDHX   #$0256
	LDA    1,X
	STA    $24
	LDA    ,X
	STA    1,X
	CLRA   
	STA    ,X
	LDHX   #$0258
	DEC    ,X
	LDA    $0258
	BNE    *+29       ;abs = $E52C
	LDA    $F8
	CMP    #$6F
	BCC    *+5       ;abs = $E51A
	INC    $F8
	CPHX   #$3FF8
	LDX    $F8
	LSLX   
	CLRH   
	LDHX   256,X
	STHX   $0256
	LDA    #$02
	STA    $0258
	RTS    
	AIS    #-4
	LDA    $24
	TSX    
	STA    2,X
	LDA    #$01
	STA    1,X
	LDX    $F9
	DBNZX  *+35       ;abs = $E55D
	TSX    
	LDX    2,X
	STX    $F8
	CLR    $F9
	CLRX   
	CLRH   
	STHX   $0253
	NEGA   
	STA    $0255
	LDX    $F8
	LSLX   
	LDHX   256,X
	STHX   $0256
	LDA    #$02
	STA    $0258
	BRA    *+30       ;abs = $E579
	LDA    $0255
	INCA   
	BNE    *+27       ;abs = $E57C
	TSX    
	LDA    2,X
	CLRH   
	TAX    
	STHX   $0253
	LDA    $F8
	STA    $0255
	CMP    #$6F
	BCC    *+5       ;abs = $E577
	INC    $F8
	CPHX   #$3FF8
	JMP    $E69A
	TSX    
	LDA    2,X
	PSHA   
	CLRA   
	LDHX   #$0253
	ORA    1,X
	STA    1,X
	PULA   
	ORA    ,X
	STA    ,X
	TSX    
	CLR    1,X
	LDA    $0255
	CMP    #$02
	BNE    *+40       ;abs = $E5BB
	LDHX   $0253
	CPHX   #$00C3
	BNE    *+12       ;abs = $E5A7
	LDHX   #$F600
	JSR    $C6B4
	SEI    
	
	DC.B   $8D        ;**** Illegal OpCode
	
	BRA    *+19       ;abs = $E5B8
	CPHX   #$00A5
	BNE    *+12       ;abs = $E5B6
	LDA    #$01
	JSR    $EAEE
	BSET   1,$F4
	BSET   4,$F4
	CPHX   #$3FF8
	JMP    $E652
	SUB    #$1A
	CMP    #$04
	BHI    *+32       ;abs = $E5DF
	LDX    $0255
	LSLX   
	CLRH   
	CLRA   
	STA    246,X
	STA    247,X
	LDA    $0253
	STA    256,X
	LDA    $0254
	STA    257,X
	TSX    
	CLR    1,X
	JMP    $E690
	LDA    $0255
	SUB    #$20
	CMP    #$4C
	BHI    *+106       ;abs = $E650
	LDA    $0255
	AND    #$0F
	STA    ,X
	LDA    $0255
	AND    #$F0
	STA    3,X
	TST    ,X
	BNE    *+35       ;abs = $E619
	CLR    $F5
	LDX    #$08
	CLRH   
	STHX   $0108
	LDX    $0255
	LSLX   
	LDA    257,X
	AND    #$81
	PSHA   
	LDA    $0254
	AND    #$7E
	ORA    1,SP
	TAX    
	STHX   $0253
	PULA   
	BRA    *+43       ;abs = $E642
	LDA    ,X
	DBNZA  *+14       ;abs = $E628
	LDX    3,X
	LSLX   
	CLRH   
	LDA    257,X
	AND    #$0E
	CBEQA  #$02,*+29       ;abs = $E642
	TSX    
	LDA    ,X
	CMP    #$02
	BNE    *+14       ;abs = $E63A
	LDX    3,X
	LSLX   
	CLRH   
	LDA    257,X
	AND    #$0E
	CBEQA  #$04,*+11       ;abs = $E642
	TSX    
	LDA    ,X
	SUB    #$03
	CMP    #$09
	BHI    *+7       ;abs = $E647
	LDA    #$01
	TSX    
	STA    1,X
	LDA    ,X
	CMP    #$03
	BCS    *+6       ;abs = $E650
	CMP    #$0C
	BCS    *+4       ;abs = $E652
	CLR    $F8
	TSX    
	TST    1,X
	BEQ    *+59       ;abs = $E690
	LDX    $0255
	LSLX   
	PSHX   
	CLRH   
	PULX   
	LDHX   256,X
	CPHX   $0253
	JSR    $F040
	CLRX   
	JSR    $F04F
	BEQ    *+3       ;abs = $E66F
	INCX   
	LDA    $F4
	AND    #$02
	LSRA   
	PSHX   
	TSX    
	ORA    ,X
	PULH   
	BNE    *+5       ;abs = $E67D
	BCLR   1,$F4
	CPHX   #$12F4
	LDX    $0255
	LSLX   
	LDA    $0253
	CLRH   
	STA    256,X
	LDA    $0254
	STA    257,X
	CLRX   
	CLRH   
	STHX   $0253
	LDA    #$FF
	STA    $0255
	AIS    #4
	RTS    
	PSHH   
	PSHH   
	LDA    $23
	TSX    
	STA    ,X
	MOV    #$0A,$23
	BIT    #$40
	BEQ    *+18       ;abs = $E6BA
	BIT    #$04
	BEQ    *+9       ;abs = $E6B5
	BSET   4,$22
	JSR    $E4FC
	BRA    *+27       ;abs = $E6CE
	MOV    #$01,$F9
	BRA    *+13       ;abs = $E6C5
	BIT    #$10
	BNE    *+18       ;abs = $E6CE
	BRCLR  4,$22,*+13       ;abs = $E6CB
	BIT    #$01
	BEQ    *-19       ;abs = $E6B0
	BCLR   4,$22
	LDA    $24
	BRA    *+5       ;abs = $E6CE
	JSR    $E52D
	PULH   
	PULH   
	RTI    
	LDA    $06
	AND    #$1F
	STA    $06
	LDHX   #$184C
	LDA    ,X
	AND    #$1F
	STA    ,X
	LDA    $07
	ORA    #$E0
	STA    $07
	RTS    
	LDA    $04
	AND    #$3F
	STA    $04
	LDHX   #$1848
	LDA    ,X
	AND    #$7F
	STA    ,X
	LDA    $05
	ORA    #$C0
	STA    $05
	RTS    
	
	org $E6F9
configFTM2:
	LDHX   #$1880	; clear FTM2SC
	LDA    ,X
	CLRA   
	STA    ,X
	LDHX   #$1885	; FTM2C0SC
	LDA    ,X
	LDA    $1888	; FTM2C1SC
	LDA    $188B	; FTM2C2SC
	LDA    $188E	; FTM2C3SC
	LDA    $18A3	; FTM2MODE
	ORA    #$04		; 	set WPDIS
	STA    $18A3
	LDA    $18A3
	AND    #$FE		; 	clear FTMEN
	STA    $18A3
	LDA    $18A7	; FTM2COMBINE0
	AND    #$FE		;	clear COMBINE
	STA    $18A7
	LDA    $18A8	; FTM2COMBINE1
	AND    #$FE		; 	clear COMBINE
	STA    $18A8
	LDA    ,X		; FTM2C0SC
	AND    #$37		; 	= 0b00xx 0xxx
	ORA    #$24		;	= 0b001x 01xx
	STA    ,X		; 	= MSnB, ELSnA = edge aligned PWM, reset on overflow, set on compare match
	LDHX   #$1888
	LDA    ,X
	AND    #$37
	ORA    #$24
	STA    ,X
	LDHX   #$188B
	LDA    ,X
	AND    #$37
	ORA    #$24
	STA    ,X
	LDHX   #$188E
	LDA    ,X
	AND    #$37
	ORA    #$24
	STA    ,X
	LDHX   #$1891
	LDA    ,X
	AND    #$37
	ORA    #$24
	STA    ,X
	LDHX   #$1894
	LDA    ,X
	AND    #$03
	STA    ,X
	LDX    #$FF
	CLRH   
	STHX   $1886	; FTM2C0VH:L = $00FF
	STHX   $1889	; FTM2C1VH:L = $00FF
	STHX   $188C	; FTM2C2VH:L = $00FF
	STHX   $188F	; FTM2C3VH:L = $00FF
	STHX   $1892	; FTM2C4VH:L = $00FF
	CLRA   
	STA    $18AF
	STA    $18B0
	LDA    $18B1
	AND    #$0F
	STA    $18B1
	LDA    $18B2
	AND    #$F0
	STA    $18B2
	LDA    $18AC
	AND    #$40
	STA    $18AC
	STHX   $1883
	CLRX   
	STHX   $18A0
	STX    $1882
	LDHX   #$18A3
	LDA    ,X
	AND    #$6C
	ORA    #$04
	STA    ,X
	LDA    #$0A
	STA    $1880
	RTS    
	MOV    #$04,$43
	CLR    $30
	CLRX   
	CLRH   
	STHX   $33
	CLR    $31
	STHX   $36
	LDA    $30
	AND    #$FE
	ORA    #$06
	STA    $30
	MOV    #$4C,$35
	RTS    
	PSHH   
	LDA    $35
	BCLR   7,$35
	JSR    $CCA7
	BSET   3,$5E
	PULH   
	RTI    
	MOV    #$04,$43
	CLRX   
	CLRH   
	STHX   $39
	MOV    #$4C,$38
	RTS    
	PSHH   
	LDA    $38
	BCLR   7,$38
	JSR    $CCA7
	BSET   3,$5E
	PULH   
	RTI    
	PSHA   
	CMP    #$01
	BLS    *+6       ;abs = $E7EC
	LDA    #$02
	PULH   
	RTS    
	LDHX   #$1869
	LDA    ,X
	AND    #$FE
	STA    ,X
	LDA    #$40
	STA    ,X
	TSX    
	LDX    ,X
	CLRH   
	LDA    63299,X
	ORA    #$08
	STA    $186C
	LDA    63297,X
	ORA    #$73
	STA    $1868
	LDHX   #$1869
	LDA    ,X
	ORA    #$01
	STA    ,X
	JSR    $F74F
	LDHX   #$186B
	LDA    ,X
	ORA    #$06
	STA    ,X
	LDA    $1868
	BIT    #$0C
	BEQ    *+9       ;abs = $E828
	LDA    $1868
	BIT    #$03
	BNE    *+3       ;abs = $E829
	BGND   
	LDA    $186C
	BIT    #$10
	BNE    *+9       ;abs = $E837
	LDA    $186C
	BIT    #$01
	BEQ    *+3       ;abs = $E838
	BGND   
	CLRA   
	PULH   
	RTS    
	MOV    #$0F,$1A
	BSET   7,$1A
	LDA    #$FF
	STA    $186A
	RTS    
	PSHA   
	CMP    #$02
	BLS    *+6       ;abs = $E84F
	LDA    #$02
	PULH   
	RTS    
	LDHX   #$1861
	LDA    ,X
	AND    #$FE
	STA    ,X
	LDA    #$40
	STA    ,X
	TSX    
	LDX    ,X
	CLRH   
	LDA    63304,X
	ORA    #$08
	STA    $1864
	LDA    63301,X
	ORA    #$73
	STA    $1860
	LDHX   #$1861
	LDA    ,X
	ORA    #$01
	STA    ,X
	JSR    $F74F
	LDHX   #$1863
	LDA    ,X
	ORA    #$06
	STA    ,X
	LDA    $1860
	BIT    #$0C
	BEQ    *+9       ;abs = $E88B
	LDA    $1860
	BIT    #$03
	BNE    *+3       ;abs = $E88C
	BGND   
	LDA    $1864
	BIT    #$10
	BNE    *+9       ;abs = $E89A
	LDA    $1864
	BIT    #$01
	BEQ    *+3       ;abs = $E89B
	BGND   
	CLRA   
	PULH   
	RTS    
	MOV    #$0F,$19
	BSET   7,$19
	LDA    #$08
	STA    $1862
	CLRA   
	STA    $1863
	RTS    
	PSHH   
	BSET   2,$0C
	JSR    $CCE2
	BSET   3,$5E
	PULH   
	RTI    
	LDA    $02
	AND    #$08
	LSRA   
	LSRA   
	LSRA   
	PSHA   
	LDA    $02
	AND    #$02
	TSX    
	ORA    ,X
	PULH   
	RTS    
	LDA    $17
	AND    #$F5
	STA    $17
	LDHX   #$1844
	LDA    ,X
	AND    #$F5
	STA    ,X
	LDA    $03
	AND    #$F5
	STA    $03
	BSET   1,$67
	CLR    $0E
	CLR    $0C
	BSET   1,$0D
	BSET   2,$0C
	BSET   1,$0C
	RTS    
	PSHX   
	PSHH   
	PSHA   
	AIS    #-4
	PSHX   
	PSHH   
	LDHX   ,X
	STHX   5,SP
	PULH   
	PULX   
	AIX    #2
	STHX   6,SP
	TSX    
	LDA    4,X
	SUB    #$02
	STA    4,X
	MOV    #$FF,$7C
	MOV    #$FF,$7D
	BRA    *+17       ;abs = $E918
	NOP    
	LDHX   6,SP
	LDA    ,X
	STA    $7D
	AIX    #1
	STHX   6,SP
	TSX    
	DEC    4,X
	TST    4,X
	BNE    *-17       ;abs = $E909
	LDA    $7D
	STA    1,X
	LDA    $7C
	STA    ,X
	LDHX   1,SP
	CPHX   3,SP
	BEQ    *+4       ;abs = $E92D
	CLRA   
	CPHX   #$A601
	AIS    #7
	RTS    
	PSHX   
	PSHH   
	PSHA   
	AIS    #-2
	AIX    #2
	STHX   1,SP
	SUB    #$02
	TSX    
	STA    2,X
	MOV    #$FF,$7C
	MOV    #$FF,$7D
	BRA    *+17       ;abs = $E958
	NOP    
	LDHX   1,SP
	LDA    ,X
	STA    $7D
	AIX    #1
	STHX   1,SP
	TSX    
	DEC    2,X
	TST    2,X
	BNE    *-17       ;abs = $E949
	LDHX   4,SP
	LDA    $7D
	STA    1,X
	MOV    $7C,X+
	AIS    #5
	RTS    
	PSHX   
	PSHH   
	AIS    #-8
	LDHX   13,SP
	CPHX   #$0000
	BNE    *+5       ;abs = $E977
	LDA    #$FF
	DC.B   $21		 ;SKIP   
	CLRA   
	TSX    
	STA    5,X
	CLR    3,X
	CLR    2,X
	CLR    4,X
	BRA    *+85       ;abs = $E9D6
	LDHX   9,SP
	LDA    3,X
	PSHA   
	PSHX   
	LDA    7,SP
	LDX    2,SP
	MUL    
	PSHX   
	LDX    2,SP
	ADD    1,X
	STA    4,SP
	PULA   
	ADC    ,X
	TSX    
	LDX    2,X
	PSHA   
	STA    5,SP
	LDA    3,SP
	PULH   
	JSR    $E8E7
	TSTA   
	AIS    #2
	BEQ    *+38       ;abs = $E9D3
	TSX    
	LDA    1,X
	PSHA   
	LDX    ,X
	PULH   
	LDHX   2,X
	STHX   7,SP
	CPHX   3,SP
	BCC    *+10       ;abs = $E9C8
	LDHX   7,SP
	CPHX   3,SP
	BLE    *+13       ;abs = $E9D3
	TSX    
	LDA    4,X
	STA    5,X
	LDHX   7,SP
	STHX   3,SP
	TSX    
	INC    4,X
	LDHX   9,SP
	LDA    2,X
	TSX    
	CMP    4,X
	BHI    *-91       ;abs = $E983
	LDHX   13,SP
	BEQ    *+11       ;abs = $E9EE
	LDA    3,SP
	STA    ,X
	LDA    4,SP
	STA    1,X
	TSX    
	LDA    5,X
	AIS    #10
	RTS    
	PSHX   
	PSHH   
	AIS    #-2
	CLRX   
	PSHX   
	PSHX   
	LDHX   5,SP
	STX    3,SP
	JSR    $E968
	AIS    #2
	TSX    
	STA    1,X
	LDHX   3,SP
	LDA    2,X
	CMP    2,SP
	BLS    *+24       ;abs = $EA29
	LDA    3,X
	LDX    2,SP
	MUL    
	PSHX   
	LDX    2,SP
	ADD    1,X
	PSHA   
	LDA    2,SP
	ADC    ,X
	PSHA   
	PULH   
	PULX   
	PULA   
	CPHX   #$5F8C
	AIS    #4
	RTS    
	PSHX   
	PSHH   
	AIS    #-8
	TSX    
	CLR    3,X
	CLR    2,X
	AIX    #2
	PSHX   
	PSHH   
	LDHX   15,SP
	JSR    $E968
	AIS    #2
	TSX    
	STA    7,X
	TSX    
	INC    7,X
	LDHX   13,SP
	LDA    2,X
	CMP    8,SP
	BHI    *+5       ;abs = $EA56
	CLR    8,SP
	LDA    3,X
	PSHA   
	PSHX   
	LDA    10,SP
	LDX    2,SP
	MUL    
	STX    2,SP
	PULX   
	ADD    1,X
	PSHA   
	LDA    2,SP
	ADC    ,X
	PSHA   
	PULH   
	PULX   
	STHX   7,SP
	TSX    
	INC    4,X
	BNE    *+4       ;abs = $EA79
	INC    3,X
	LDHX   10,SP
	LDA    4,SP
	STA    2,X
	LDA    5,SP
	STA    3,X
	STHX   2,SP
	LDHX   14,SP
	LDA    3,X
	LDHX   2,SP
	JSR    $E932
	TSX    
	LDX    7,X
	LDA    7,SP
	AND    #$01
	PSHA   
	PULH   
	CPHX   #$0000
	PULH   
	BNE    *+13       ;abs = $EAAF
	LDHX   6,SP
	JSR    $C6B4
	TSX    
	STA    4,X
	BNE    *+26       ;abs = $EAC7
	LDHX   9,SP
	PSHX   
	PSHH   
	LDHX   8,SP
	PSHX   
	PSHH   
	LDHX   17,SP
	LDX    3,X
	CLRH   
	JSR    $C63E
	AIS    #4
	TSX    
	STA    4,X
	TST    4,X
	BNE    *+26       ;abs = $EAE3
	LDHX   9,SP
	PSHX   
	PSHH   
	LDHX   8,SP
	PSHX   
	PSHH   
	LDHX   17,SP
	LDX    3,X
	CLRH   
	JSR    $F5D5
	AIS    #4
	STX    5,SP
	TSX    
	TST    4,X
	BEQ    *+5       ;abs = $EAEB
	JMP    $EA46
	AIS    #10
	RTS    
	PSHA   
	AIS    #-127
	AIS    #-9
	TSX    
	TST    136,X
	BNE    *+11       ;abs = $EB01
	LDHX   #$F74B
	JSR    $E9F4
	STHX   7,SP
	TSX    
	TST    136,X
	BNE    *+7       ;abs = $EB0B
	LDHX   7,SP
	BNE    *+8       ;abs = $EB11
	LDHX   #$F666
	STHX   7,SP
	TSX    
	AIX    #8
	PSHX   
	PSHH   
	LDHX   9,SP
	LDA    #$80
	JSR    $EF50
	PSHA   
	TPA    
	SEI    
	STA    $90
	PULA   
	LDHX   #$0100
	LDA    #$E0
	JSR    $F64F
	BCLR   0,$09
	LDHX   #$1850
	LDA    ,X
	ORA    #$01
	STA    ,X
	BCLR   1,$09
	BCLR   2,$09
	BRSET  0,$08,*+6       ;abs = $EB3F
	LDX    #$37
	CPHX   #$AE3A
	CLRH   
	STHX   $0100
	LDHX   #$1208
	STHX   $0102
	LDHX   19,SP
	STHX   $010C
	LDHX   21,SP
	STHX   $010A
	TSX    
	LDA    23,X
	STA    $F5
	CLR    3,X
	LDA    3,X
	LDX    #$10
	MUL    
	ADD    #$20
	LSLA   
	LDHX   #$0100
	ADD    #$00
	PSHA   
	PSHH   
	PULA   
	ADC    #$00
	PSHA   
	TSX    
	LDX    1,X
	PULH   
	STHX   6,SP
	LDA    15,SP
	AND    #$01
	STA    4,SP
	LDA    15,SP
	AND    #$02
	LDX    #$40
	MUL    
	ORA    4,SP
	STA    4,SP
	LDA    17,SP
	AND    #$07
	NSA    
	AND    #$F0
	ORA    4,SP
	STA    4,SP
	LDA    19,SP
	AND    #$07
	LSLA   
	ORA    4,SP
	STA    4,SP
	PULX   
	CLR    ,X
	STA    1,X
	AND    #$0E
	CMP    #$02
	BNE    *+30       ;abs = $EBCE
	TSX    
	LDA    3,X
	LDX    #$16
	MUL    
	PSHX   
	TSX    
	JSR    $EC86
	LDHX   ,X
	PSHH   
	STX    2,SP
	LDHX   7,SP
	PULA   
	STA    2,X
	PULA   
	STA    3,X
	BRA    *+45       ;abs = $EBF9
	LDHX   5,SP
	CLR    2,X
	LDA    #$FF
	STA    3,X
	TSX    
	LDA    2,X
	AND    #$0E
	CMP    #$06
	BHI    *+27       ;abs = $EBF9
	LDA    3,X
	LDX    #$16
	MUL    
	PSHX   
	TSX    
	JSR    $EC86
	LDHX   ,X
	PSHH   
	STX    2,SP
	LDHX   7,SP
	PULA   
	STA    4,X
	PULA   
	STA    5,X
	LDHX   5,SP
	AIX    #6
	PSHX   
	PSHH   
	TSX    
	LDA    5,X
	LDX    #$16
	MUL    
	STX    3,SP
	TSX    
	AIX    #28
	STA    4,SP
	TXA    
	PSHH   
	TSX    
	ADD    4,X
	STA    4,X
	PULA   
	ADC    3,X
	PSHA   
	LDX    4,X
	PULH   
	AIX    #2
	LDA    #$14
	JSR    $F62B
	AIS    #2
	TSX    
	ASR    12,X
	ROR    13,X
	ASR    12,X
	ROR    13,X
	ASR    12,X
	ROR    13,X
	ASR    14,X
	ROR    15,X
	ASR    14,X
	ROR    15,X
	ASR    14,X
	ROR    15,X
	ASR    16,X
	ROR    17,X
	ASR    16,X
	ROR    17,X
	ASR    16,X
	ROR    17,X
	INC    3,X
	LDA    3,X
	CMP    #$05
	BCC    *+5       ;abs = $EC56
	JMP    $EB5E
	LDHX   #$5A5A
	STHX   $013E
	LDHX   #$A5A5
	STHX   $015E
	LDHX   #$5A5A
	STHX   $017E
	LDHX   #$A5A5
	STHX   $019E
	LDHX   #$5A5A
	STHX   $01BE
	LDHX   #$A5A5
	STHX   $01DE
	PSHA   
	LDA    $90
	TAP    
	PULA   
	AIS    #2
	AIS    #127
	AIS    #8
	RTS    
	AIX    #27
	PSHA   
	TXA    
	PSHH   
	TSX    
	ADD    1,X
	STA    1,X
	PULA   
	ADC    4,X
	PSHA   
	PULH   
	PULX   
	RTS    
	AIS    #-127
	AIS    #-7
	PSHA   
	TPA    
	SEI    
	STA    $90
	PULA   
	TSX    
	AIX    #4
	LDA    #$80
	JSR    $F64F
	LDA    $F5
	CLRH   
	TAX    
	STHX   19,SP
	LDHX   $010C
	STHX   15,SP
	LDHX   $010A
	STHX   17,SP
	TSX    
	CLR    2,X
	LDA    2,X
	LDX    #$10
	MUL    
	ADD    #$20
	LSLA   
	LDHX   #$0100
	ADD    #$00
	PSHA   
	PSHH   
	PULA   
	ADC    #$00
	PSHA   
	PULH   
	PULX   
	STHX   133,SP
	LDA    1,X
	TSX    
	STA    3,X
	LSL    9,X
	ROL    8,X
	LSL    9,X
	ROL    8,X
	LSL    9,X
	ROL    8,X
	LSL    11,X
	ROL    10,X
	LSL    11,X
	ROL    10,X
	LSL    11,X
	ROL    10,X
	LSL    13,X
	ROL    12,X
	LSL    13,X
	ROL    12,X
	LSL    13,X
	ROL    12,X
	AND    #$80
	ROLA   
	ROLA   
	ROLA   
	AND    #$03
	PSHA   
	LDA    3,X
	AND    #$01
	TSX    
	ORA    ,X
	ORA    10,X
	STA    10,X
	LDA    9,X
	STA    9,X
	LDA    4,X
	AND    #$70
	NSA    
	AND    #$0F
	ORA    12,X
	STA    12,X
	LDA    11,X
	STA    11,X
	LDA    4,X
	AND    #$0E
	TAX    
	LSRA   
	ORA    15,SP
	STA    15,SP
	LDA    14,SP
	STA    14,SP
	CPX    #$02
	PULH   
	BNE    *+20       ;abs = $ED4E
	LDA    #$16
	TSX    
	LDX    2,X
	MUL    
	PSHX   
	TSX    
	AIX    #23
	PSHA   
	BSR    *+123       ;abs = $EDC2
	LDHX   2,X
	BRA    *+18       ;abs = $ED5E
	LDA    #$16
	TSX    
	LDX    2,X
	MUL    
	PSHX   
	TSX    
	AIX    #23
	PSHA   
	BSR    *+105       ;abs = $EDC2
	LDHX   4,X
	PSHA   
	PSHH   
	PULA   
	STA    3,SP
	PULH   
	PSHX   
	LDX    2,SP
	PULA   
	STA    1,X
	LDA    2,SP
	STA    ,X
	AIS    #2
	TSX    
	LDA    2,X
	LDX    #$16
	MUL    
	STX    1,SP
	TSX    
	AIX    #22
	STA    2,SP
	TXA    
	PSHH   
	TSX    
	ADD    2,X
	STA    2,X
	PULA   
	ADC    1,X
	PSHA   
	LDX    2,X
	PULH   
	AIX    #2
	PSHX   
	PSHH   
	LDHX   135,SP
	AIX    #6
	LDA    #$14
	JSR    $F62B
	AIS    #2
	TSX    
	INC    2,X
	LDA    2,X
	CMP    #$05
	BCC    *+5       ;abs = $EDAB
	JMP    $ECBF
	PSHA   
	LDA    $90
	TAP    
	PULA   
	LDHX   #$F74B
	PSHX   
	PSHH   
	TSX    
	AIX    #6
	JSR    $EA2E
	AIS    #4
	AIS    #127
	AIS    #5
	RTS    
	TXA    
	PSHH   
	TSX    
	ADD    3,X
	STA    3,X
	PULA   
	ADC    4,X
	LDHX   137,SP
	RTS    
	LDA    3,X
	PSHA   
	LDA    2,X
	PSHA   
	LDHX   ,X
	PSHX   
	PSHH   
	LDHX   7,SP
	LDA    3,X
	STA    17,SP
	LDA    2,X
	STA    16,SP
	LDHX   ,X
	STHX   14,SP
	LDHX   5,SP
	JMP    ,X
	AIS    #-2
	PSHA   
	PSHX   
	PSHH   
	LDA    7,SP
	PSHA   
	LDA    7,SP
	PSHA   
	LDA    10,SP
	STA    6,SP
	LDA    11,SP
	STA    7,SP
	LDA    3,X
	STA    11,SP
	LDA    2,X
	STA    10,SP
	LDHX   ,X
	STHX   8,SP
	RTS    
	PSHA   
	PSHX   
	PSHH   
	PSHX   
	PSHH   
	LDHX   6,SP
	PSHX   
	PSHH   
	LDHX   10,SP
	STHX   8,SP
	LDHX   12,SP
	JMP    $EDD0
	AIS    #-2
	PSHA   
	PSHX   
	PSHH   
	PSHX   
	PSHH   
	LDHX   8,SP
	PSHX   
	PSHH   
	LDHX   12,SP
	AIX    #4
	STHX   8,SP
	AIX    #-4
	JMP    $EDD0
	TST    4,SP
	BNE    *+28       ;abs = $EE67
	TSX    
	LDA    7,X
	LDX    4,X
	CLRH   
	DIV    
	STA    4,SP
	LDA    9,SP
	DIV    
	STA    5,SP
	CLR    8,SP
	PSHH   
	PULA   
	STA    9,SP
	RTS    
	CLRA   
	PSHA   
	LDX    #$08
	CLC    
	ROL    10,SP
	ROL    9,SP
	ROL    1,SP
	LDA    5,SP
	CMP    1,SP
	BHI    *+31       ;abs = $EE9A
	BNE    *+10       ;abs = $EE87
	LDA    6,SP
	CMP    9,SP
	BHI    *+21       ;abs = $EE9A
	LDA    9,SP
	SUB    6,SP
	STA    9,SP
	LDA    1,SP
	SBC    5,SP
	STA    1,SP
	SEC    
	DBNZX  *-46       ;abs = $EE6C
	LDA    10,SP
	ROLA   
	STA    6,SP
	LDA    9,SP
	STA    10,SP
	PULA   
	STA    8,SP
	CLR    4,SP
	RTS    
	TSX    
	TST    7,X
	BPL    *+10       ;abs = $EEBE
	COM    7,X
	NEG    8,X
	BNE    *+4       ;abs = $EEBE
	INC    7,X
	TST    3,X
	BPL    *+10       ;abs = $EECA
	COM    3,X
	NEG    4,X
	BNE    *+4       ;abs = $EECA
	INC    3,X
	JMP    $EE48
	COM    ,X
	COM    1,X
	COM    2,X
	NEG    3,X
	BNE    *+11       ;abs = $EEDF
	INC    2,X
	BNE    *+7       ;abs = $EEDF
	INC    1,X
	BNE    *+3       ;abs = $EEDF
	INC    ,X
	RTS    
	AIS    #-2
	STHX   1,SP
	TSX    
	LDA    5,X
	LDX    1,X
	MUL    
	PSHA   
	PSHX   
	TSX    
	LDA    7,X
	LDX    2,X
	MUL    
	TSX    
	ADD    ,X
	PSHA   
	LDA    6,X
	LDX    3,X
	MUL    
	TSX    
	ADD    ,X
	STA    3,X
	AIS    #2
	PULA   
	STA    4,X
	PULH   
	PULX   
	RTS    
	AIS    #-2
	STHX   1,SP
	TSX    
	LDA    4,X
	EOR    ,X
	PSHA   
	JSR    $EEB1
	PULA   
	TSTA   
	BPL    *+9       ;abs = $EF1F
	TSX    
	COM    ,X
	NEG    1,X
	BNE    *+3       ;abs = $EF1F
	INC    ,X
	PULH   
	PULX   
	RTS    
	TST    3,SP
	BEQ    *+8       ;abs = $EF2D
	LSRX   
	RORA   
	DBNZ   3,SP,*-2       ;abs = $EF27
	RTS    
	TST    3,SP
	BEQ    *+8       ;abs = $EF39
	LSLA   
	ROLX   
	DBNZ   3,SP,*-2       ;abs = $EF33
	RTS    
	CPX    3,SP
	BNE    *+14       ;abs = $EF4B
	TSX    
	CMP    3,X
	BEQ    *+9       ;abs = $EF4B
	CLRA   
	BCS    *+4       ;abs = $EF49
	LDA    #$02
	CMP    #$01
	PULH   
	PULX   
	AIS    #2
	JMP    ,X
	PSHA   
	LDA    #$81
	PSHA   
	LDA    #$F6
	PSHA   
	LDA    #$26
	PSHA   
	LDA    #$5D
	PSHA   
	LDA    9,SP
	PSHA   
	LDA    9,SP
	PSHA   
	LDA    #$D7
	PSHA   
	PSHX   
	PSHH   
	LDHX   #$5AD6
	PSHX   
	PSHH   
	LDHX   #$8C97
	PSHX   
	PSHH   
	TSX    
	LDA    13,X
	JSR    ,X
	AIS    #13
	PULA   
	PULH   
	PULX   
	AIS    #2
	JMP    ,X
	PSHA   
	LDA    4,SP
	STA    ,X
	LDA    5,SP
	STA    1,X
	LDA    6,SP
	STA    2,X
	LDA    7,SP
	STA    3,X
	PULA   
	PULH   
	PULX   
	AIS    #4
	JMP    ,X
	TXA    
	PULH   
	PULX   
	PSHA   
	CMP    #$80
	CLRA   
	BCS    *+3       ;abs = $EFA4
	COMA   
	PSHA   
	PSHA   
	JMP    ,X
	PULH   
	PSHX   
	PSHA   
	LDX    3,SP
	CMP    ,X
	BHI    *+31       ;abs = $EFCD
	BNE    *+9       ;abs = $EFB9
	LDA    1,X
	CMP    2,SP
	BLS    *+22       ;abs = $EFCD
	AIX    #2
	LSL    2,SP
	ROL    1,SP
	TXA    
	ADD    2,SP
	TAX    
	PSHH   
	PULA   
	ADC    1,SP
	PSHA   
	PULH   
	AIS    #3
	LDA    2,X
	LDX    3,X
	PSHA   
	PULH   
	JMP    ,X
	TSTA   
	TXA    
	PULH   
	PULX   
	BNE    *+20       ;abs = $EFEE
	CMP    ,X
	BCC    *+17       ;abs = $EFEE
	AIX    #1
	PSHX   
	ADD    1,SP
	PSHA   
	PSHH   
	PULA   
	ADC    #$00
	PSHA   
	PULH   
	PULX   
	PULA   
	TXA    
	ADD    1,X
	TAX    
	PSHH   
	PULA   
	ADC    #$00
	PSHA   
	PULH   
	JMP    2,X
	PULH   
	PSHH   
	PSHX   
	LDX    3,SP
	TSTA   
	PULA   
	BNE    *+16       ;abs = $F012
	CMP    ,X
	BHI    *+13       ;abs = $F012
	AIX    #3
	CMP    ,X
	BHI    *-3       ;abs = $F007
	BEQ    *+6       ;abs = $F012
	PULH   
	PULX   
	BRA    *+4       ;abs = $F014
	AIS    #2
	LDA    1,X
	LDX    2,X
	PSHA   
	PULH   
	JMP    ,X
	PULH   
	PSHH   
	PSHX   
	LDX    3,SP
	TSTA   
	PULA   
	BNE    *+15       ;abs = $F032
	CMP    ,X
	BHI    *+12       ;abs = $F032
	AIX    #2
	CMP    ,X
	BHI    *-3       ;abs = $F028
	BEQ    *+5       ;abs = $F032
	PULH   
	PULX   
	CPHX   #$A702
	TXA    
	ADD    1,X
	TAX    
	PSHH   
	PULA   
	ADC    #$00
	PSHA   
	PULH   
	JMP    2,X
	PSHA   
	TPA    
	PSHA   
	LDA    4,SP
	PSHA   
	LDA    4,SP
	PSHA   
	LDA    4,SP
	RTS    
	STA    4,SP
	PULA   
	STA    4,SP
	PULA   
	STA    4,SP
	PULA   
	TAP    
	PULA   
	RTS    
	LDA    #$02
	TSX    
	STA    9,X
	RTS    
	LDA    #$02
	TSX    
	STA    3,X
	RTS    
	LDA    #$FF
	TSX    
	STA    9,X
	RTS    
	LDA    #$FE
	TSX    
	STA    9,X
	RTS    
	TSX    
	LDA    17,X
	STA    30,X
	LDA    14,X
	STA    11,X
	BNE    *+20       ;abs = $F093
	LDHX   16,SP
	STHX   13,SP
	LDHX   18,SP
	STHX   31,SP
	LDHX   20,SP
	STHX   33,SP
	RTS    
	TSX    
	LDA    11,X
	LDX    14,X
	STX    12,SP
	TSX    
	STA    14,X
	LDA    12,X
	LDX    15,X
	STX    13,SP
	TSX    
	STA    15,X
	LDA    13,X
	LDX    16,X
	STX    14,SP
	TSX    
	STA    16,X
	LDA    30,X
	LDX    17,X
	STX    31,SP
	TSX    
	STA    17,X
	LDA    31,X
	LDX    18,X
	STX    32,SP
	TSX    
	STA    18,X
	LDA    32,X
	LDX    19,X
	STX    33,SP
	TSX    
	STA    19,X
	LDA    33,X
	LDX    20,X
	STX    34,SP
	TSX    
	STA    20,X
	RTS    
	TSX    
	CLR    9,X
	LDA    28,X
	LSLA   
	CMP    #$FE
	BNE    *+20       ;abs = $F0F8
	LDA    29,X
	BPL    *+30       ;abs = $F106
	DEC    9,X
	LDA    29,X
	LSLA   
	ORA    30,X
	ORA    31,X
	BNE    *+4       ;abs = $F0F7
	DEC    9,X
	RTS    
	TSX    
	ORA    29,X
	ORA    30,X
	ORA    31,X
	BNE    *+7       ;abs = $F106
	LDA    #$02
	STA    9,X
	RTS    
	TSX    
	LDA    28,X
	CLR    28,X
	LDX    29,X
	LSLX   
	ROLA   
	BCC    *+6       ;abs = $F115
	COM    29,SP
	TSTA   
	BEQ    *+3       ;abs = $F118
	SEC    
	RORX   
	STX    30,SP
	TSX    
	CLR    10,X
	STA    11,X
	BNE    *+18       ;abs = $F133
	DEC    11,X
	LSL    31,X
	ROL    30,X
	ROL    29,X
	BPL    *-8       ;abs = $F123
	INC    11,X
	BEQ    *+4       ;abs = $F133
	COM    10,X
	RTS    
	TSX    
	CLR    3,X
	LDA    11,X
	LSLA   
	CMP    #$FE
	BNE    *+20       ;abs = $F150
	LDA    12,X
	BPL    *+30       ;abs = $F15E
	DEC    3,X
	LDA    12,X
	LSLA   
	ORA    13,X
	ORA    14,X
	BNE    *+4       ;abs = $F14F
	DEC    3,X
	RTS    
	TSX    
	ORA    12,X
	ORA    13,X
	ORA    14,X
	BNE    *+7       ;abs = $F15E
	LDA    #$02
	STA    3,X
	RTS    
	TSX    
	LDA    11,X
	CLR    11,X
	LDX    12,X
	LSLX   
	ROLA   
	BCC    *+6       ;abs = $F16D
	COM    12,SP
	TSTA   
	BEQ    *+3       ;abs = $F170
	SEC    
	RORX   
	STX    13,SP
	TSX    
	CLR    4,X
	STA    5,X
	BNE    *+18       ;abs = $F18B
	DEC    5,X
	LSL    14,X
	ROL    13,X
	ROL    12,X
	BPL    *-8       ;abs = $F17B
	INC    5,X
	BEQ    *+4       ;abs = $F18B
	COM    4,X
	RTS    
	TSX    
	CLR    12,X
	LDA    15,X
	LSLA   
	CMP    #$FE
	BNE    *+20       ;abs = $F1A8
	LDA    16,X
	BPL    *+30       ;abs = $F1B6
	DEC    12,X
	LDA    16,X
	LSLA   
	ORA    17,X
	ORA    18,X
	BNE    *+4       ;abs = $F1A7
	DEC    12,X
	RTS    
	TSX    
	ORA    16,X
	ORA    17,X
	ORA    18,X
	BNE    *+7       ;abs = $F1B6
	LDA    #$02
	STA    12,X
	RTS    
	TSX    
	LDA    15,X
	CLR    15,X
	LDX    16,X
	LSLX   
	ROLA   
	BCC    *+6       ;abs = $F1C5
	COM    16,SP
	TSTA   
	BEQ    *+3       ;abs = $F1C8
	SEC    
	RORX   
	STX    17,SP
	TSX    
	CLR    13,X
	STA    14,X
	BNE    *+18       ;abs = $F1E3
	DEC    14,X
	LSL    18,X
	ROL    17,X
	ROL    16,X
	BPL    *-8       ;abs = $F1D3
	INC    14,X
	BEQ    *+4       ;abs = $F1E3
	COM    13,X
	RTS    
	TSX    
	LDA    9,X
	BEQ    *+43       ;abs = $F212
	BMI    *+8       ;abs = $F1F1
	CLR    28,X
	CLR    29,X
	BRA    *+15       ;abs = $F1FE
	CMP    #$FF
	BEQ    *+17       ;abs = $F204
	LDA    #$80
	STA    29,X
	COMA   
	ORA    28,X
	STA    28,X
	CLR    30,X
	CLR    31,X
	BRA    *+43       ;abs = $F22D
	LDA    #$7F
	STA    28,X
	LDA    #$FF
	STA    29,X
	STA    30,X
	STA    31,X
	BRA    *+29       ;abs = $F22D
	LDA    11,X
	BNE    *+16       ;abs = $F224
	LSR    29,X
	ROR    30,X
	ROR    31,X
	LSR    28,X
	CLR    28,X
	ROR    28,X
	BRA    *+11       ;abs = $F22D
	LSL    29,X
	LSL    28,X
	RORA   
	STA    28,X
	ROR    29,X
	AIS    #23
	PULH   
	PULX   
	PULA   
	RTS    
	TSX    
	LDA    3,X
	BEQ    *+43       ;abs = $F261
	BMI    *+8       ;abs = $F240
	CLR    11,X
	CLR    12,X
	BRA    *+15       ;abs = $F24D
	CMP    #$FF
	BEQ    *+17       ;abs = $F253
	LDA    #$80
	STA    12,X
	COMA   
	ORA    11,X
	STA    11,X
	CLR    13,X
	CLR    14,X
	BRA    *+43       ;abs = $F27C
	LDA    #$7F
	STA    11,X
	LDA    #$FF
	STA    12,X
	STA    13,X
	STA    14,X
	BRA    *+29       ;abs = $F27C
	LDA    5,X
	BNE    *+16       ;abs = $F273
	LSR    12,X
	ROR    13,X
	ROR    14,X
	LSR    11,X
	CLR    11,X
	ROR    11,X
	BRA    *+11       ;abs = $F27C
	LSL    12,X
	LSL    11,X
	RORA   
	STA    11,X
	ROR    12,X
	AIS    #6
	PULH   
	PULX   
	PULA   
	RTS    
	TSX    
	TST    9,X
	BEQ    *+3       ;abs = $F288
	RTS    
	TSX    
	LDA    29,X
	ORA    30,X
	ORA    31,X
	BNE    *+5       ;abs = $F294
	JMP    $F05E
	TSX    
	TST    10,X
	BMI    *+29       ;abs = $F2B4
	BEQ    *+5       ;abs = $F29E
	JMP    $F070
	TSX    
	TST    29,X
	BMI    *+18       ;abs = $F2B3
	LDA    11,X
	TSTA   
	BEQ    *+26       ;abs = $F2C0
	DECA   
	LSL    31,X
	ROL    30,X
	ROL    29,X
	BPL    *-10       ;abs = $F2A5
	STA    11,X
	RTS    
	TSX    
	LDA    11,X
	NEGA   
	LSR    29,X
	ROR    30,X
	ROR    31,X
	DBNZA  *-6       ;abs = $F2B8
	CLR    11,X
	CLR    10,X
	RTS    
	TSX    
	LDA    9,X
	ORA    12,X
	BEQ    *+36       ;abs = $F2EE
	BPL    *+18       ;abs = $F2DE
	INCA   
	BEQ    *+28       ;abs = $F2EB
	LDA    12,X
	EOR    9,X
	BPL    *+15       ;abs = $F2E4
	LDA    9,X
	CMP    #$FE
	BNE    *+42       ;abs = $F305
	RTS    
	TSX    
	LDA    9,X
	BGT    *+36       ;abs = $F305
	RTS    
	TSX    
	LDA    28,X
	EOR    15,X
	BPL    *+27       ;abs = $F304
	JMP    $F06A
	TSX    
	LDA    11,X
	SUB    14,X
	TAX    
	LDA    11,SP
	SBC    14,SP
	BCS    *+15       ;abs = $F309
	TXA    
	BEQ    *+28       ;abs = $F319
	TST    11,SP
	BLT    *+7       ;abs = $F309
	RTS    
	JSR    $F076
	RTS    
	COMA   
	TXA    
	BNE    *-6       ;abs = $F305
	NEGA   
	BEQ    *-9       ;abs = $F305
	TSX    
	STA    3,X
	JSR    $F094
	TSX    
	LDA    3,X
	CMP    #$18
	BCC    *-23       ;abs = $F304
	TSTA   
	BEQ    *+11       ;abs = $F329
	TSX    
	LSR    16,X
	ROR    17,X
	ROR    18,X
	DBNZA  *-7       ;abs = $F320
	TSX    
	LDA    28,X
	CMP    15,X
	BEQ    *+39       ;abs = $F355
	LDA    31,X
	SUB    18,X
	STA    31,X
	LDA    30,X
	SBC    17,X
	STA    30,X
	LDA    29,X
	SBC    16,X
	STA    29,X
	BCC    *+18       ;abs = $F354
	COM    28,X
	COM    29,X
	COM    30,X
	NEG    31,X
	BNE    *+8       ;abs = $F354
	INC    30,X
	BNE    *+4       ;abs = $F354
	INC    29,X
	RTS    
	TSX    
	LDA    31,X
	ADD    18,X
	STA    31,X
	LDA    30,X
	ADC    17,X
	STA    30,X
	LDA    29,X
	ADC    16,X
	STA    29,X
	BCC    *+14       ;abs = $F376
	ROR    29,X
	ROR    30,X
	ROR    31,X
	INC    11,X
	BNE    *+4       ;abs = $F376
	INC    10,X
	RTS    
	TSX    
	LDA    9,X
	ORA    12,X
	BEQ    *+41       ;abs = $F3A5
	INCA   
	BEQ    *+17       ;abs = $F390
	BMI    *+5       ;abs = $F386
	JMP    $F05E
	TSX    
	LDA    9,X
	EOR    12,X
	CBEQA  #$FC,*+5       ;abs = $F390
	BRA    *+13       ;abs = $F39B
	JMP    $F06A
	TSTA   
	BEQ    *+7       ;abs = $F39B
	TSX    
	LDA    9,X
	BGT    *-9       ;abs = $F390
	TSX    
	LDA    15,X
	EOR    28,X
	STA    28,X
	JMP    $F070
	TSX    
	LDA    15,X
	EOR    28,X
	STA    15,X
	LDA    14,X
	ADD    11,X
	STA    14,X
	LDA    13,X
	ADC    10,X
	PSHA   
	LDA    14,X
	SUB    #$7E
	STA    14,X
	PULA   
	SBC    #$00
	STA    13,X
	CLR    3,X
	CLR    4,X
	CLR    5,X
	LDA    29,X
	STA    6,X
	LDA    30,X
	STA    7,X
	LDA    31,X
	STA    8,X
	CLR    19,X
	CLR    20,X
	CLR    21,X
	LDA    #$18
	STA    22,X
	TSX    
	AIX    #22
	LDA    #$06
	CLC    
	AIX    #-1
	ROL    ,X
	DBNZA  *-3       ;abs = $F3E4
	BCC    *+22       ;abs = $F3FF
	TSX    
	AIX    #22
	LDA    #$06
	STA    3,SP
	CLC    
	AIX    #-1
	LDA    ,X
	ADC    65523,X
	STA    ,X
	DBNZ   3,SP,*-7       ;abs = $F3F4
	TSX    
	DBNZ   22,X,*-34       ;abs = $F3DE
	JSR    $F076
	RTS    
	TSX    
	LDA    9,X
	ORA    12,X
	BEQ    *+39       ;abs = $F433
	INCA   
	BEQ    *+20       ;abs = $F423
	LDA    9,X
	BGT    *+16       ;abs = $F423
	LDA    12,X
	BGT    *+25       ;abs = $F430
	CMP    #$FE
	BNE    *+21       ;abs = $F430
	LDA    9,X
	CMP    #$FE
	BNE    *+5       ;abs = $F426
	JMP    $F06A
	TSX    
	LDA    15,X
	EOR    28,X
	STA    28,X
	JMP    $F070
	JMP    $F05E
	TSX    
	LDA    15,X
	EOR    28,X
	STA    28,X
	LDA    14,X
	SUB    11,X
	STA    11,X
	LDA    13,X
	SBC    10,X
	PSHA   
	LDA    11,X
	ADD    #$7F
	STA    11,X
	PULA   
	ADC    #$00
	STA    10,X
	CLR    3,X
	CLR    4,X
	CLR    5,X
	LDA    #$18
	STA    22,X
	CLC    
	BCS    *+20       ;abs = $F46F
	LDA    29,X
	CMP    16,X
	BNE    *+12       ;abs = $F46D
	LDA    30,X
	CMP    17,X
	BNE    *+6       ;abs = $F46D
	LDA    31,X
	CMP    18,X
	BHI    *+21       ;abs = $F482
	LDA    18,X
	SUB    31,X
	STA    18,X
	LDA    17,X
	SBC    30,X
	STA    17,X
	LDA    16,X
	SBC    29,X
	STA    16,X
	SEC    
	ROL    5,X
	ROL    4,X
	ROL    3,X
	LSL    18,X
	ROL    17,X
	ROL    16,X
	DBNZ   22,X,*-51       ;abs = $F45B
	LDA    3,X
	STA    29,X
	LDA    4,X
	STA    30,X
	LDA    5,X
	STA    31,X
	RTS    
	TSX    
	LDA    3,X
	BEQ    *+23       ;abs = $F4B8
	CMP    #$02
	BNE    *+13       ;abs = $F4B2
	CLR    11,X
	TSX    
	CLR    12,X
	CLR    13,X
	CLR    14,X
	BRA    *+66       ;abs = $F4F2
	LDA    #$80
	STA    11,X
	BRA    *-13       ;abs = $F4A9
	LDA    11,X
	CLR    11,X
	STA    2,X
	LDA    5,X
	SUB    #$7E
	PSHA   
	LDA    4,X
	SBC    #$00
	PULA   
	BCS    *-33       ;abs = $F4A7
	CMP    #$20
	BHI    *-37       ;abs = $F4A7
	SUB    #$18
	BPL    *+13       ;abs = $F4DD
	NEGA   
	LSR    12,X
	ROR    13,X
	ROR    14,X
	DBNZA  *-6       ;abs = $F4D3
	BRA    *+14       ;abs = $F4E9
	BEQ    *+12       ;abs = $F4E9
	LSL    14,X
	ROL    13,X
	ROL    12,X
	ROL    11,X
	DBNZA  *-8       ;abs = $F4DF
	TST    2,X
	BPL    *+7       ;abs = $F4F2
	AIX    #11
	JSR    $EECD
	AIS    #6
	PULH   
	PULX   
	PULA   
	RTS    
	LDA    #$18
	TSX    
	TST    11,X
	BEQ    *+25       ;abs = $F516
	LSR    11,X
	ROR    12,X
	ROR    13,X
	ROR    14,X
	INCA   
	TST    11,X
	BNE    *-11       ;abs = $F4FF
	ADD    #$7E
	TSX    
	STA    5,X
	CLR    4,X
	CLR    3,X
	RTS    
	TSX    
	TST    12,X
	BMI    *-13       ;abs = $F50C
	LSL    14,X
	ROL    13,X
	ROL    12,X
	DBNZA  *-11       ;abs = $F516
	JMP    $F064
	TSX    
	AIX    #2
	LDA    #$04
	STA    4,X
	LDA    13,X
	ORA    ,X
	BPL    *+15       ;abs = $F53F
	LDA    ,X
	CMP    13,X
	BNE    *+21       ;abs = $F54A
	AIX    #1
	DBNZ   7,SP,*-7       ;abs = $F532
	BRA    *+13       ;abs = $F54A
	LDA    13,X
	CMP    ,X
	BNE    *+8       ;abs = $F54A
	AIX    #1
	DBNZ   7,SP,*-7       ;abs = $F53F
	AIS    #12
	PULA   
	PULH   
	PULX   
	AIS    #4
	JMP    ,X
	JSR    $F0DC
	JSR    $F18C
	JSR    $F2C5
	JSR    $F282
	JSR    $F1E4
	JSR    $F0DC
	JSR    $F18C
	JSR    $F377
	JSR    $F282
	JSR    $F1E4
	JSR    $F0DC
	JSR    $F18C
	JSR    $F407
	JSR    $F282
	JSR    $F1E4
	JSR    $EE2F
	AIS    #-13
	BRA    *-50       ;abs = $F552
	JSR    $EE19
	AIS    #-13
	BRA    *-42       ;abs = $F561
	JSR    $EE2F
	AIS    #-13
	BRA    *-49       ;abs = $F561
	JSR    $EE19
	AIS    #-13
	BRA    *-41       ;abs = $F570
	JSR    $EDF0
	AIS    #-4
	JSR    $F134
	JSR    $F49E
	JSR    $EE2F
	JSR    $F526
	JSR    $EDF0
	AIS    #-4
	TST    10,SP
	BMI    *+7       ;abs = $F5BB
	JSR    $F4F8
	BRA    *+14       ;abs = $F5C7
	TSX    
	AIX    #9
	JSR    $EECD
	JSR    $F4F8
	COM    10,SP
	JSR    $F233
	JSR    $EDF0
	AIS    #-4
	JSR    $F4F8
	JSR    $F233
	PSHX   
	PSHH   
	AIS    #-4
	LDHX   11,SP
	STHX   1,SP
	LDHX   9,SP
	STHX   3,SP
	LDHX   5,SP
	BNE    *+28       ;abs = $F604
	CLRH   
	CLRX   
	BRA    *+60       ;abs = $F628
	LDHX   3,SP
	LDA    ,X
	LDHX   1,SP
	CMP    ,X
	BNE    *+28       ;abs = $F612
	TSX    
	INC    1,X
	BNE    *+3       ;abs = $F5FE
	INC    ,X
	INC    3,X
	BNE    *+4       ;abs = $F604
	INC    2,X
	TSX    
	TST    5,X
	BNE    *+4       ;abs = $F60B
	DEC    4,X
	DEC    5,X
	LDHX   5,SP
	BNE    *-34       ;abs = $F5EE
	LDHX   1,SP
	LDA    ,X
	LDHX   3,SP
	PSHA   
	LDA    ,X
	PSHA   
	TSX    
	LDA    1,X
	SUB    ,X
	STA    ,X
	CLRA   
	SBC    #$00
	PSHA   
	PULH   
	PULX   
	PULA   
	AIS    #6
	RTS    
	PSHX   
	PSHH   
	PSHA   
	BRA    *+26       ;abs = $F648
	DEC    ,X
	LDA    ,X
	ADD    6,X
	PSHA   
	CLRA   
	ADC    5,X
	PSHA   
	LDA    ,X
	ADD    2,X
	PSHA   
	CLRA   
	ADC    1,X
	PSHA   
	PULH   
	PULX   
	LDX    ,X
	PULH   
	TXA    
	PULX   
	STA    ,X
	TSX    
	TST    ,X
	BNE    *-26       ;abs = $F630
	AIS    #3
	RTS    
	PSHX   
	PSHH   
	PSHA   
	LDHX   2,SP
	CLR    ,X
	TSX    
	INC    2,X
	BNE    *+4       ;abs = $F65D
	INC    1,X
	DBNZ   ,X,*-11       ;abs = $F652
	AIS    #3
	RTS    
	NEGA   
	CBEQA  #$43,*+73       ;abs = $F6AC
	BRSET  0,$00,*+3       ;abs = $F669
	BRSET  0,$00,*+3       ;abs = $F66C
	BRSET  0,$00,*+30       ;abs = $F68A
	TST    0,X
	STHX   $4600
	BRSET  0,$02,*+3       ;abs = $F677
	BRSET  0,$00,*+3       ;abs = $F67A
	BRCLR  2,$00,*+8       ;abs = $F682
	JMP    $0700
	BRCLR  3,$66,*+10       ;abs = $F68A
	JMP    $1900
	BSET   6,$00
	BCLR   7,$00
	BCS    *+2       ;abs = $F68C
	BHCC   *+2       ;abs = $F68E
	BRSET  0,$00,*+8       ;abs = $F696
	BRSET  0,$05,*-49       ;abs = $F660
	BRCLR  3,$00,*+10       ;abs = $F69E
	ROR    7,X
	JMP    $1900
	BSET   6,$00
	BCLR   7,$00
	BCS    *+2       ;abs = $F6A2
	BHCC   *+2       ;abs = $F6A4
	BRSET  0,$00,*+8       ;abs = $F6AC
	BRSET  0,$05,*-49       ;abs = $F676
	BRCLR  3,$00,*+10       ;abs = $F6B4
	ROR    7,X
	JMP    $1900
	BSET   6,$00
	BCLR   7,$00
	BCS    *+2       ;abs = $F6B8
	BHCC   *+2       ;abs = $F6BA
	BRSET  0,$00,*+8       ;abs = $F6C2
	BRSET  0,$05,*-49       ;abs = $F68C
	BRCLR  3,$00,*+10       ;abs = $F6CA
	ROR    7,X
	JMP    $1900
	BSET   6,$00
	BCLR   7,$00
	BCS    *+2       ;abs = $F6CE
	BHCC   *+2       ;abs = $F6D0
	BRSET  0,$FF,*+8       ;abs = $F6D8
	BRSET  0,$05,*-49       ;abs = $F6A2
	BRCLR  3,$00,*+10       ;abs = $F6E0
	ROR    7,X
	JMP    $1900
	BSET   6,$00
	BCLR   7,$00
	BCS    *+2       ;abs = $F6E4
	BHCC   *+2       ;abs = $F6E6
	BRCLR  1,$80,*+6       ;abs = $F6EC
	LDA    4,X
	COM    $04
	SEC    
	BRCLR  2,$00,*+31       ;abs = $F70D
	BRSET  0,$1F,*+3       ;abs = $F6F4
	BHI    *+2       ;abs = $F6F6
	BCS    *+2       ;abs = $F6F8
	BHCC   *+2       ;abs = $F6FA
	BRCLR  2,$00,*+8       ;abs = $F702
	JMP    $0700
	BRCLR  3,$66,*+10       ;abs = $F70A
	JMP    $1900
	BSET   6,$00
	BCLR   7,$00
	BCS    *+2       ;abs = $F70C
	BHCC   *+2       ;abs = $F70E
	BRSET  3,$33,*+9       ;abs = $F717
	SEC    
	BRSET  4,$80,*+12       ;abs = $F71E
	INCA   
	BRSET  5,$80,*+28       ;abs = $F732
	BRSET  0,$1C,*+3       ;abs = $F71C
	BCLR   7,$00
	BHI    *+2       ;abs = $F720
	BHCC   *+2       ;abs = $F722
	LDA    ,X
	LDA    246,X
	ORA    ,X
	STA    ,X
	BRSET  7,$01,*-22       ;abs = $F711
	CPX    24,X
	CBEQ   0,X+,*-22       ;abs = $F716
	CPX    24,X
	CBEQ   1,X+,*-21       ;abs = $F71C
	RORA   
	BSET   4,$69
	BRSET  0,$E8,*+73       ;abs = $F780
	BSET   4,$69
	BRSET  1,$E8,*+73       ;abs = $F785
	BSET   4,$69
	BRSET  4,$0C,*+67       ;abs = $F784
	RTI    
	BRSET  4,$0C,*+7       ;abs = $F74C
	NEGA   
	RTI    
	BRA    *-62       ;abs = $F70C
	BRSET  0,$08,*-125       ;abs = $F6CF
	LDX    #$9A
	DBNZX  *+0       ;abs = $F751
	RTS    
	BRSET  0,$02,*+3       ;abs = $F757
	CPX    #$EA
	NEG    0,X
	BRSET  5,$00,*-24       ;abs = $F743
	ROR    102,X
	ROR    102,X
	ROR    255,X
	STX    ,X
	STX    ,X
	STX    ,X
	STX    ,X
	BRSET  0,$00,*+3       ;abs = $F76B
	
	org $F7C0
	DC.W $C400, $C400, $C400, $C400
	DC.W $C400, $C400, $C400, $D87B
	DC.W $E69D, $C400, $C400, $C400
	DC.W $C400, $C711, $C400, $C400
	DC.W $C400, $C400, $C400, $C400
	DC.W $C400, $C400, $C400, $C400
	DC.W $C400, $E7D7, $E7C0, $C400
	DC.W $C400, $C400, $C400, $C44E
	
	org $F800
BootDefaultHandler:
	PSHH
	BGND
	PULH   
	RTI    
	
	org $F804
BootISRInit:
	PSHH   
	PSHA   
	TPA    
	SEI    
	STA    $90
	PULA   
	TSX    
	CLR    ,X
	LDX    ,X
	LDA    #$03
	MUL    
	CLRH   
	TAX    
	LDA    #$CC		; JMP opcode for vector table
	STA    $0433,X	; store JMP opcode into RAM address of vector table
	LDA    1,SP
	LSLA   
	PSHA   
	CLRA   
	ROLA   
	PSHA   
	PULH   
	PSHX   
	LDX    2,SP
	LDHX   $FF70,X	; source for ISR addresses
	PSHH   
	PULA   
	STA    2,SP
	CLRH   
	TXA    
	PULX   
	STA    $0435,X	; destination for ISR addresses
	PULA   
	STA    $0434,X	; destination for ISR addresses
	TSX    
	INC    ,X
	LDA    ,X
	CMP    #$1F
	BCS    *-48       ;abs = $F80D
	PSHA   
	LDA    $90
	TAP    
	PULA   
	PULH   
	RTS

; reset handler
	org $F846
_Startup:
	BSR    BootISRInit       ;abs = $F804
	LDA    #$03
	STA    $1802
	LDA    #$08
	STA    $1803
	LDA    #$1C
	STA    $1809
	CLRA   
	STA    $180A
	LDA    $FFAF
	CBEQA  #$FF,*+15       ;abs = $F86D
	LDA    $FFAF
	STA    $3E
	LDA    $FFAE
	AND    #$01
	STA    $3F
	MOV    #$06,$3C
	CLR    $3D
	BRCLR  4,$3F,*+0       ;abs = $F872
	LDA    $3F
	AND    #$9F
	ORA    #$80
	STA    $3F
	LDA    $3F
	AND    #$C0
	CMP    #$80
	BNE    *-6       ;abs = $F87D
	JMP    $FCB5	; startup02
	
	org $F888
startup04:
	LDA    #$FF
	STA    $180E
	STA    $180F
	BCLR   2,$00
	LDHX   #$1840
	LDA    ,X
	AND    #$FB
	STA    ,X
	BSET   2,$01
	CLRA   
	STA    $1841
	STA    $1845
	STA    $1849
	STA    $184D
	LDHX   #$1851
	LDA    ,X
	AND    #$80
	STA    ,X
	LDHX   #$1855
	LDA    ,X
	AND    #$F8
	STA    ,X
	LDA    #$FF
	STA    $1842
	STA    $1846
	STA    $184A
	STA    $184E
	LSRA   
	STA    $1852
	LDA    #$07
	STA    $1856
	CLR    $67
	CLR    $66
	CLR    $65
	CLR    $64
	MOV    #$80,$63
	CLR    $62
	CLR    $61
	CLR    $60
	MOV    #$80,$5E
	JSR    $FA5E	; startup05
	JSR    $FC00	; startup06
	JSR    $FC1B	; startup07
	CLI    
	RTS    
	
	
	STA    $1826
	LDA    #$80
	STA    $1825
	NOP    
	NOP    
	NOP    
	NOP    
	LDA    $1825
	BIT    #$30
	BNE    *+9       ;abs = $F906
	LDA    $1825
	BIT    #$40
	BEQ    *-5       ;abs = $F8FF
	RTS    
	
	org $F907
startup10:
	PSHX   
	PSHH   
	PSHA   
	AIS    #-40
	TSX    
	PSHX   
	PSHH   
	LDHX   #$F8EC
	LDA    #$28
	JSR    $FC3C
	PSHA   
	TPA    
	SEI    
	STA    $90
	PULA   
	CLRA   
	LDHX   #$1825
	STA    ,X
	LDA    ,X
	BIT    #$30
	BEQ    *+7       ;abs = $F92C
	LDA    #$30
	STA    $1825
	LDHX   42,SP
	LDA    41,SP
	STA    ,X
	TSX    
	LDA    45,X
	JSR    ,X
	PSHA   
	LDA    $90
	TAP    
	PULA   
	LDA    $1825
	BIT    #$30
	BEQ    *+16       ;abs = $F951
	LDA    $1825
	BIT    #$20
	BEQ    *+6       ;abs = $F94E
	LDA    #$16
	BRA    *+6       ;abs = $F952
	LDA    #$09
	DC.B   $21		 ;SKIP   
	CLRA   
	AIS    #43
	RTS    
	PSHX   
	PSHH   
	AIS    #-47
	TSX    
	AIX    #7
	PSHX   
	PSHH   
	LDHX   #$F8EC
	LDA    #$28
	JSR    $FC3C
	LDHX   52,SP
	CPHX   #$C000
	BCS    *+29       ;abs = $F989
	LDHX   48,SP
	CPHX   #$4000
	BHI    *+21       ;abs = $F989
	TXA    
	TSX    
	ADD    52,X
	PSHA   
	LDA    51,X
	ADC    47,X
	PSHA   
	PULH   
	PULX   
	AIX    #-1
	CPHX   #$C000
	BCC    *+6       ;abs = $F98D
	LDA    #$02
	BRA    *+128       ;abs = $FA0B
	LDA    $1825
	BIT    #$40
	BNE    *+6       ;abs = $F998
	LDA    #$08
	BRA    *+117       ;abs = $FA0B
	PSHA   
	TPA    
	SEI    
	STA    $90
	PULA   
	CLRA   
	LDHX   #$1825
	STA    ,X
	LDA    ,X
	BIT    #$30
	BEQ    *+7       ;abs = $F9AD
	LDA    #$30
	STA    $1825
	LDHX   48,SP
	STHX   6,SP
	LDHX   52,SP
	STHX   2,SP
	LDHX   54,SP
	STHX   4,SP
	BRA    *+38       ;abs = $F9E5
	LDHX   2,SP
	LDA    ,X
	TSX    
	STA    ,X
	LDHX   4,SP
	CMP    ,X
	BEQ    *+13       ;abs = $F9D8
	COMA   
	ORA    ,X
	LDHX   2,SP
	STA    ,X
	LDA    #$25
	TSX    
	JSR    7,X
	TSX    
	INC    2,X
	BNE    *+4       ;abs = $F9DF
	INC    1,X
	INC    4,X
	BNE    *+4       ;abs = $F9E5
	INC    3,X
	LDHX   6,SP
	PSHX   
	PSHH   
	AIX    #-1
	STHX   8,SP
	PULH   
	PULX   
	CPHX   #$0000
	BNE    *-51       ;abs = $F9C1
	PSHA   
	LDA    $90
	TAP    
	PULA   
	LDA    $1825
	BIT    #$30
	BEQ    *+61       ;abs = $FA3D
	LDA    $1825
	BIT    #$20
	BEQ    *+6       ;abs = $FA0D
	LDA    #$16
	BRA    *+53       ;abs = $FA40
	LDA    #$09
	BRA    *+49       ;abs = $FA40
	LDHX   52,SP
	LDA    ,X
	LDHX   54,SP
	CMP    ,X
	BEQ    *+6       ;abs = $FA1F
	LDA    #$03
	BRA    *+35       ;abs = $FA40
	TSX    
	TST    48,X
	BNE    *+4       ;abs = $FA26
	DEC    47,X
	DEC    48,X
	LDHX   48,SP
	CPHX   #$0000
	BEQ    *+17       ;abs = $FA3F
	TSX    
	INC    54,X
	BNE    *+4       ;abs = $FA37
	INC    53,X
	INC    52,X
	BNE    *-40       ;abs = $FA11
	INC    51,X
	BRA    *-44       ;abs = $FA11
	CLRA   
	AIS    #49
	RTS   
	
	org $FA43
startup09: 
	CPHX   #$C000
	BCC    *+5       ;abs = $FA4B
	LDA    #$02
	RTS    
	LDA    $1825
	BIT    #$40
	BNE    *+5       ;abs = $FA55
	LDA    #$08
	RTS    
	LDA    #$40
	PSHA   
	CLRA   
	JSR    $F907	; startup10
	PULH   
	RTS    
	
	org $FA5E
startup05:
	LDA    #$30
	STA    $1825
	LDA    #$50
	STA    $1820
	RTS    
	CMP    #$57
	BHI    *+75       ;abs = $FAB6
	TAX    
	CLRA   
	JSR    $FC90
	ASRX   
	MUL    
	LDHX   #$3149
	BRSET  3,$51,*+44       ;abs = $FAA3
	DIV    
	BSET   2,$57
	NEG    $3F
	TXA    
	CLR    $9E
	LDHX   #$C000
	STHX   $95
	LDHX   #$FCBC
	STHX   $9A
	MOV    #$18,$9C
	RTS    
	MOV    $95,$A6
	MOV    $96,$A7
	LDA    $91
	STA    $A8
	LDX    #$A6
	CLRH   
	STHX   $9A
	MOV    #$03,$9C
	RTS    
	MOV    #$01,$98
	RTS    
	LDX    #$01
	CLRH   
	STHX   $A2
	BRA    *+8       ;abs = $FAB4
	LDX    #$02
	CLRH   
	STHX   $A2
	LSLX   
	STHX   $A4
	RTS    
	PSHH   
	LDHX   $A4
	AIX    #-1
	PSHH   
	STA    2,SP
	PULA   
	JSR    $FC6C
	BRSET  2,$3E,*+6       ;abs = $FACA
	BRCLR  6,$3B,*+29       ;abs = $FAE4
	TSX    
	LDA    ,X
	STA    $95
	LDX    #$02
	CLRH   
	STHX   $A4
	PULH   
	RTS    
	TSX    
	LDA    ,X
	STA    $96
	CLRX   
	CLRH   
	STHX   $A4
	STHX   $A2
	MOV    #$01,$97
	PULH   
	RTS    
	LDA    $94
	CMP    #$FF
	BCC    *+19       ;abs = $FAFB
	INC    $94
	LDA    $92
	TAX    
	INCA   
	STA    $92
	CLRH   
	LDA    1,SP
	STA    256,X
	BRA    *+5       ;abs = $FAFE
	MOV    #$0D,$91
	INC    $A1
	BNE    *+4       ;abs = $FB04
	INC    $A0
	PULH   
	RTS    
	TST    $99
	BNE    *+5       ;abs = $FB0D
	MOV    #$01,$98
	RTS    
	PSHH   
	PSHH   
	LDA    $23
	MOV    #$0A,$23
	BIT    #$40
	BEQ    *+19       ;abs = $FB2A
	BIT    #$04
	BEQ    *+10       ;abs = $FB25
	BSET   4,$22
	TST    $9C
	BNE    *+30       ;abs = $FB3F
	BRA    *+42       ;abs = $FB4D
	MOV    #$01,$9D
	BRA    *+13       ;abs = $FB35
	BIT    #$10
	BNE    *+57       ;abs = $FB65
	BRCLR  4,$22,*+35       ;abs = $FB51
	BIT    #$01
	BEQ    *+8       ;abs = $FB3B
	BCLR   4,$22
	LDA    $24
	BRA    *+44       ;abs = $FB65
	TST    $9C
	BEQ    *+16       ;abs = $FB4D
	DEC    $9C
	LDHX   $9A
	MOV    X+,$24
	INC    $9B
	BNE    *+30       ;abs = $FB65
	INC    $9A
	BRA    *+26       ;abs = $FB65
	CLR    $24
	BRA    *+22       ;abs = $FB65
	LDA    $24
	TSX    
	STA    ,X
	LDA    $9D
	DBNZA  *+10       ;abs = $FB61
	LDA    ,X
	JSR    $FA69
	CLR    $9D
	BRA    *+6       ;abs = $FB65
	LDA    ,X
	JSR    $FAB7
	PULH   
	PULH   
	RTI    
	
	org $FB68
startup03:
	PSHH   
	LDA    #$6F
	LDHX   #$0091
	MOV    #$00,$90
	MOV    $90,X+
	DBNZA  *-2       ;abs = $FB71
	JSR    $F888	; startup04
	LDA    $F7FE
	SUB    #$C0
	CMP    #$37
	BHI    *+94       ;abs = $FBDD
	JSR    $FBE9	; startup08
	BRA    *+89       ;abs = $FBDD
	TST    $97
	BNE    *+9       ;abs = $FB91
	LDA    $94
	CMP    #$3F
	BHI    *+3       ;abs = $FB91
	WAIT   
	TST    $97
	BEQ    *+9       ;abs = $FB9C
	LDHX   $95
	JSR    $FA43	;startup09
	CLR    $97
	LDA    $94
	CMP    #$3F
	BLS    *+61       ;abs = $FBDD
	TSX    
	CLR    ,X
	TST    $94
	BNE    *+5       ;abs = $FBAB
	CLRA   
	BRA    *+14       ;abs = $FBB7
	DEC    $94
	LDA    $93
	TAX    
	INCA   
	STA    $93
	CLRH   
	LDA    256,X
	TSX    
	LDX    ,X
	CLRH   
	STA    512,X
	TSX    
	INC    ,X
	LDA    ,X
	CMP    #$40
	BCS    *-30       ;abs = $FBA4
	LDHX   #$0200
	PSHX   
	PSHH   
	LDHX   $95
	PSHX   
	PSHH   
	LDX    #$40
	CLRH   
	JSR    $F955	;
	AIS    #4
	STA    $91
	LDHX   $95
	AIX    #64
	STHX   $95
	TST    $98
	BEQ    *-89       ;abs = $FB86
	JSR    $FBF5
	SEI    
	LDHX   $F7FE
	JMP    ,X
	
	org $FBE9
startup08:
	TST    $A9
	BNE    *+8       ;abs = $FBF3
	MOV    #$01,$A9
	MOV    #$60,$54
	CLRA   
	RTS    
	
	org $FBF5
	TST    $A9
	BEQ    *+7       ;abs = $FBFE
	CLR    $A9
	MOV    #$10,$54
	CLRA   
	RTS    
	
	org $FC00
startup06:
	MOV    #$10,$54
	CLR    $A9
	MOV    #$BF,$57
	MOV    #$18,$55
	BSET   5,$54
	MOV    #$10,$54
	RTS    
	
	org $FC11
bootModuloTimerOverflowHandler:
	PSHH   
	BCLR   7,$54
	JSR    $FB06
	BSET   3,$5E
	PULH   
	RTI    
	
	org $FC1B
startup07:
	CLR    $2A
	CLR    $25
	CLR    $25
	MOV    #$0A,$20
	MOV    #$23,$21
	MOV    #$C2,$27
	MOV    #$08,$26
	CLR    $26
	CLRX   
	CLRH   
	STHX   $28
	MOV    #$92,$23
	BSET   7,$22
	MOV    #$C0,$22
	RTS    
	
	org $FC3C
	PSHA   
	LDA    #$81
	PSHA   
	LDA    #$F6
	PSHA   
	LDA    #$26
	PSHA   
	LDA    #$5D
	PSHA   
	LDA    9,SP
	PSHA   
	LDA    9,SP
	PSHA   
	LDA    #$D7
	PSHA   
	PSHX   
	PSHH   
	LDHX   #$5AD6
	PSHX   
	PSHH   
	LDHX   #$8C97
	PSHX   
	PSHH   
	TSX    
	LDA    13,X
	JSR    ,X
	AIS    #13
	PULA   
	PULH   
	PULX   
	AIS    #2
	JMP    ,X
	TSTA   
	TXA    
	PULH   
	PULX   
	BNE    *+20       ;abs = $FC84
	CMP    ,X
	BCC    *+17       ;abs = $FC84
	AIX    #1
	PSHX   
	ADD    1,SP
	PSHA   
	PSHH   
	PULA   
	ADC    #$00
	PSHA   
	PULH   
	PULX   
	PULA   
	TXA    
	ADD    1,X
	TAX    
	PSHH   
	PULA   
	ADC    #$00
	PSHA   
	PULH   
	JMP    2,X
	PULH   
	PSHH   
	PSHX   
	LDX    3,SP
	TSTA   
	PULA   
	BNE    *+15       ;abs = $FCA7
	CMP    ,X
	BHI    *+12       ;abs = $FCA7
	AIX    #2
	CMP    ,X
	BHI    *-3       ;abs = $FC9D
	BEQ    *+5       ;abs = $FCA7
	PULH   
	PULX   
	CPHX   #$A702
	TXA    
	ADD    1,X
	TAX    
	PSHH   
	PULA   
	ADC    #$00
	PSHA   
	PULH   
	JMP    2,X
	
	org $FCB5
startup02:
	LDHX   #$0433
	TXS    
	JMP    $FB68	; startup03
	
	org $FCBC
	DC.B	$82   
	DC.B	$01
	DC.B	$27
	DC.B	$00
	DC.B	$00
	DC.B	$C0
	DC.B	$00
	DC.B	$F8
	DC.B	$C0
	DC.B	$F7
	DC.B	$C0
	DC.B	$FF
	DC.B	$00
	DC.B	$02
	DC.B	$40
	DC.B	$00

	org $FCCC
	DC.B	"Corsair"
	DC.B	$00

	org $FF70	; bootloader vector table
	DC.W $F800		; reserved
	DC.W $F800		; Vkeyboard3	- keyboard
	DC.W $F800		; Vkeyboard2
	DC.W $F800		; Vkeyboard1
	DC.W $F800		; Vhscmp3		- analog comparator
	DC.W $F800		; Vhscmp2
	DC.W $F800		; Vhscmp1
	DC.W $F800		; Vrtc			- real-time counter
	DC.W $FB0E		; Viic			- I2C
	DC.W $F800		; Vscitx		- SCI
	DC.W $F800		; Vscirx
	DC.W $F800		; Vscierr
	DC.W $F800		; Vspi			- SPI
	DC.W $F800		; Vadc			- ADC
	DC.W $F800		; Vpdb2			- programmable delay block
	DC.W $F800		; Vpdb1
	DC.W $FC11		; Vmtim			- MTIM overflow
	DC.W $F800		; Vftm2ovf
	DC.W $F800		; Vftm2ch5
	DC.W $F800		; Vftm2ch4
	DC.W $F800		; Vftm2ch3
	DC.W $F800		; Vftm2ch2
	DC.W $F800		; Vftm2ch1
	DC.W $F800		; Vftm2ch0
	DC.W $F800		; Vftm1ovf
	DC.W $F800		; Vftm1ch1
	DC.W $F800		; Vftm1ch0
	DC.W $F800		; Vftm2fault
	DC.W $F800		; Vftm1fault
	DC.W $F800		; Vlvw			- low-voltage warning
	DC.W $F800		; Vswi			- software interrupt
	
	org $FFBD
	DC.B $F6

	org $FFBF
	DC.B $7E

	; interrupt vector table (at top of RAM region ending at 0x048F)
	org $FFC0
	DC.W $0433		; reserved
	DC.W $0436		; Vkeyboard3	- keyboard
	DC.W $0439		; Vkeyboard2
	DC.W $043C		; Vkeyboard1
	DC.W $043F		; Vhscmp3		- analog comparator
	DC.W $0442		; Vhscmp2
	DC.W $0445		; Vhscmp1
	DC.W $0448		; Vrtc			- real-time counter
	DC.W $044B		; Viic			- I2C
	DC.W $044E		; Vscitx		- SCI
	DC.W $0451		; Vscirx
	DC.W $0454		; Vscierr
	DC.W $0457		; Vspi			- SPI
	DC.W $045A		; Vadc			- ADC
	DC.W $045D		; Vpdb2			- programmable delay block
	DC.W $0460		; Vpdb1
	DC.W $0463		; Vmtim			- MTIM overflow
	DC.W $0466		; Vftm2ovf
	DC.W $0469		; Vftm2ch5
	DC.W $046C		; Vftm2ch4
	DC.W $046F		; Vftm2ch3
	DC.W $0472		; Vftm2ch2
	DC.W $0475		; Vftm2ch1
	DC.W $0478		; Vftm2ch0
	DC.W $047B		; Vftm1ovf
	DC.W $047E		; Vftm1ch1
	DC.W $0481		; Vftm1ch0
	DC.W $0484		; Vftm2fault
	DC.W $0487		; Vftm1fault
	DC.W $048A		; Vlvw			- low-voltage warning
	DC.W $048D		; Vswi			- software interrupt
;	DC.W $F846	; reset vector
