.INCLUDE "m328pdef.inc"
.ORG 0x0000

; Initialize Stack Pointer
LDI R16, HIGH(RAMEND)
OUT SPH, R16
LDI R16, LOW(RAMEND)
OUT SPL, R16

; Make PORTD output
LDI R19, 0xFF ; load imigiate  (alternate of mov ,.... 1111 1111 )
OUT DDRD, R19  ; mov R19 in DDRD 

START:
  LDI R20, 0x55 ;01010101
  OUT PORTD, R20 ;WRITE IN PORTD
  RCALL DELAY
  LDI R21, 0xAA ;reverse pattern ;10101010
  OUT PORTD, R21 
  RCALL DELAY
  JMP START

DELAY:
  LDI  R18, 0xFF   ; Outer loop counter
AGAIN1:
  LDI  R17, 255   ; Middle loop counter
AGAIN2:
  LDI  R16, 10   ; Inner loop counter
AGAIN3:
  DEC  R16
  BRNE AGAIN3      ; Repeat until R16 = 0

  DEC  R17
  BRNE AGAIN2      ; Repeat until R17 = 0

  DEC  R18
  BRNE AGAIN1      ; Repeat until R18 = 0

  RET



