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

static struct CPU global_cpu;


void Init_Cpu()
{
	memset(&global_cpu,0,sizeof(global_cpu));
}

