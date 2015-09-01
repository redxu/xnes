#include <stdio.h>
#include "rom.h"
#include "memory.h"


struct Memory{
	unsigned char Mapper;
	unsigned char Mirror;
	unsigned char Battery;
	unsigned char PRGCount;
	unsigned char CHRCount;
	unsigned char RamCount;
	unsigned char* PRG;
	unsigned char* CHR;
	unsigned char* SRAM;
};


static struct Memory* global_memory = NULL;

static void Destroy_GlobalMemory(void)
{
	if(global_memory)
	{
		if(global_memory->PRG)
		{
			free(global_memory->PRG);
			global_memory->PRG = NULL;
		}
		if(global_memory->CHR)
		{
			free(global_memory->CHR);
			global_memory->CHR = NULL;
		}
		if(global_memory->SRAM)
		{
			free(global_memory->SRAM);
			global_memory->SRAM = NULL;
		}
		free(global_memory);
		global_memory = NULL;
	}
}

static struct Memory* Create_GlobalMemory(void)
{
	struct Memory* mem = (struct Memory *)malloc(sizeof(struct Memory));
	memset(mem,0,sizeof(struct Memory));
	return mem;
}


static void Debug_GlobalMemory(void)
{
	printf("**************************Debug_GlobalMemory**************************\n");
	printf("Mapper=%d\n",global_memory->Mapper);
	printf("Mirror=%d\n",global_memory->Mirror);
	printf("Battery=%d\n",global_memory->Battery);
	printf("PRGCount=%d\n",global_memory->PRGCount);
	printf("CHRCount=%d\n",global_memory->CHRCount);
	printf("RamCount=%d\n",global_memory->RamCount);
	printf("PRG=0x%p\n",global_memory->PRG);
	printf("CHR=0x%p\n",global_memory->CHR);
	printf("SRAM=0x%p\n",global_memory->SRAM);
	printf("***********************************************************************\n");
}

void Init_Memory(struct ROM* rom)
{
	Destroy_GlobalMemory();
	global_memory = Create_GlobalMemory();

	unsigned char Mapper1 = rom->header.Control1 >> 4;
	unsigned char Mapper2 = rom->header.Control2 >> 4;
	global_memory->Mapper = Mapper1 | (Mapper2 << 4);

	unsigned char Mirror1 = rom->header.Control1 & 1;
	unsigned char Mirror2 = (rom->header.Control1 >> 3) & 1;
	global_memory->Mirror = Mirror1 | (Mirror2 << 1);

	global_memory->Battery = (rom->header.Control1 >> 1) & 1;

	global_memory->PRGCount = rom->header.PRGCount;
	global_memory->CHRCount = rom->header.CHRCount;
	global_memory->RamCount = rom->header.RamCount;
	if(global_memory->CHRCount == 0)
	{
		global_memory->CHRCount = 1;
	}
	global_memory->PRG = (unsigned char *)malloc(global_memory->PRGCount*0x4000);
	global_memory->CHR = (unsigned char *)malloc(global_memory->CHRCount*0x2000);
	global_memory->SRAM = (unsigned char *)malloc(0x2000);

	Debug_GlobalMemory();
}