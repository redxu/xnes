#include <stdio.h>
#include "rom.h"
#include "memory.h"


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

	/*
	unsigned char Mapper1 = rom->header.Control1 >> 4;
	unsigned char Mapper2 = rom->header.Control2 >> 4;
	global_memory->Mapper = Mapper1 | (Mapper2 << 4);

	unsigned char Mirror1 = rom->header.Control1 & 1;
	unsigned char Mirror2 = (rom->header.Control1 >> 3) & 1;
	global_memory->Mirror = Mirror1 | (Mirror2 << 1);

	global_memory->Battery = (rom->header.Control1 >> 1) & 1;

	global_memory->PRGBank = rom->header.PRGBank;
	global_memory->CHRBank = rom->header.CHRBank;
	global_memory->RamBank = rom->header.RamBank;
	if(global_memory->CHRBank == 0)
	{
		global_memory->CHRBank = 1;
	}
	global_memory->PRG = (unsigned char *)malloc(global_memory->PRGBank*0x4000);
	global_memory->CHR = (unsigned char *)malloc(global_memory->CHRBank*0x2000);
	global_memory->SRAM = (unsigned char *)malloc(0x2000);

	Debug_GlobalMemory();
	*/
}