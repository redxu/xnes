#include <stdio.h>
#include <string.h>
#include "rom.h"
#include "memory.h"

/********************************************************
					Memory Map
_____________	0x10000

PRG-ROM

_____________	0x8000
SRAM
_____________	0x6000
Expansion ROM
_____________	0x4020


IO Registers


_____________	0x2000

RAM
_____________	0x0000
*********************************************************/

static unsigned char global_memory[0x10000];


void Init_Memory(struct ROM* rom)
{
	memset(global_memory,0,sizeof(global_memory));

	//RPG ROM
	memcpy(&global_memory[0x8000],rom->data,rom->header.PRGBank*0x4000);
	if(rom->header.PRGBank == 1)
	{
		memcpy(&global_memory[0xc000],rom->data,rom->header.PRGBank*0x4000);
	}
}


unsigned char Mem_ReadB(uint16_t address)
{
	return global_memory[address];
}

uint16_t Mem_ReadW(uint16_t address)
{
	return Mem_ReadB(address) + (Mem_ReadB(address+1) << 8);
}

void Mem_WriteB(uint16_t address,unsigned char value)
{
	global_memory[address] = value;
}

void Mem_WriteW(uint16_t address,uint16_t value)
{
	unsigned char hi = value >> 8;
	unsigned char lo = value & 0xff;
	Mem_WriteB(address,hi);
	Mem_WriteB(address+1,lo);
}
