/*******************************************************
*	6502 CPU 
*******************************************************/
#include <stdint.h>

struct CPU{
	uint16_t PC;	//Program Counter
	char SP;		//Stack Pointer
	char A;			//Accumulator
	char X;			//Index Register X
	char Y;			//Index Register Y
	char C;			//Carry Flag
	char Z;			//Zero Flag
	char I;			//Interrupt Disable Flag
	char D;			//Decimal Mode Flag
	char B;			//Break Command Flag
	char V;			//Overflow Flag Flag
	char N;			//Negative Flag
};