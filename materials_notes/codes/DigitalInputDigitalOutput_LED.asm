.include "m328pdef.inc"
.org 0
		cbi ddrb, 3
		sbi ddrc, 4
again:	nop
wait:	sbis pinb, 3
		rjmp wait

		sbi portc,4
		call qdelay
		cbi portc,4
		call qdelay

		rjmp again

QDELAY:
	LDI R20, 5
D1:	LDI R21, 250
D2:	LDI R22, 250
D3: NOP
	NOP
	DEC R22
	BRNE D3
	DEC R21
	BRNE D2
	DEC R20
	BRNE D1
	RET