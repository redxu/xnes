#ifndef __DEF__H__
#define __DEF__H__


#define UNUSED(x) do { x = x; } while (0)


/***************
VIDEO MODES
****************/
#define VIDEO_PAL	0
#define VIDEO_NTSC	1
#define VIDEO_MODE	VIDEO_NTSC

#define HTOTAL_PAL			
#define VTOTAL_PAL			312
#define HTOTAL_NTSC			341
#define VTOTAL_NTSC			262		//scanline

#define SCREEN_WIDTH_PAL	256
#define SCREEN_HEIGHT_PAL	240
#define SCREEN_WIDTH_NTSC	256
#define SCREEN_HEIGHT_NTSC	224

/***************
OPCODE NAMES
***************/
#define OP_BRK	"BRK"
#define OP_ORA	"ORA"
#define OP_FUT	"FUT"
#define OP_ASL	"ASL"
#define OP_PHP	"PHP"
#define OP_BPL	"BPL"
#define OP_CLC	"CLC"
#define OP_CLV	"CLV"
#define OP_CLD	"CLD"
#define OP_JSR	"JSR"
#define OP_AND	"AND"
#define OP_BIT	"BIT"
#define OP_ROL	"ROL"
#define OP_PLA	"PLA"
#define OP_PLP	"PLP"
#define OP_BMI	"BMI"
#define OP_SEC	"SEC"
#define OP_SED	"SED"
#define OP_RTI	"RTI"
#define OP_EOR	"EOR"
#define OP_LSR	"LSR"
#define OP_PHA	"PHA"
#define OP_JMP	"JMP"
#define OP_BVC	"BVC"
#define OP_BVS	"BVS"
#define OP_CLI	"CLI"
#define OP_RTS	"RTS"
#define OP_ADC	"ADC"
#define OP_ROR	"ROR"
#define OP_SEI	"SEI"
#define OP_STA	"STA"
#define OP_STX	"STX"
#define OP_STY	"STY"
#define OP_DEY	"DEY"
#define OP_TXA	"TXA"
#define OP_TYA	"TYA"
#define OP_BCC	"BCC"
#define OP_BCS	"BCS"
#define OP_TXS	"TXS"
#define OP_LDY	"LDY"
#define OP_LDA	"LDA"
#define OP_LDX	"LDX"
#define OP_TAY	"TAY"
#define OP_TAX	"TAX"
#define OP_TSX	"TSX"
#define OP_CPX	"CPX"
#define OP_CPY	"CPY"
#define OP_CMP	"CMP"
#define OP_DEC	"DEC"
#define OP_DEX	"DEX"
#define OP_INC	"INC"
#define OP_INX	"INX"
#define OP_INY	"INY"
#define OP_BNE	"BNE"
#define OP_BEQ	"BEQ"
#define OP_SBC	"SBC"
#define OP_NOP	"NOP"



#endif

