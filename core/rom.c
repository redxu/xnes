#include <stdio.h>
#include "memory.h"
#include "rom.h"



static unsigned char ROMMAGIC[4] = {0x4e,0x45,0x53,0x1a};





int Init_NesRom(const char* filepath)
{
	long fsize;
	FILE* file = fopen(filepath,"rb");
	if(file == NULL)
	{
		printf("open failed!\n");
		return -1;
	}
	fseek(file,0,SEEK_END);
	fsize = ftell(file);
	fseek(file,0,SEEK_SET);

	struct ROM* rom = (struct ROM*)malloc(fsize);
	fread(rom,fsize,1,file);
	fclose(file);

	if(memcmp(rom->header.magic,ROMMAGIC,4) != 0)
	{
		printf("magic wrong!\n");
		return -1;
	}

	printf("PRGCount=%d\n",rom->header.PRGCount);
	printf("CHRCount=%d\n",rom->header.CHRCount);
	printf("Control1=%d\n",rom->header.Control1);
	printf("Control2=%d\n",rom->header.Control2);
	printf("RamCount=%d\n",rom->header.RamCount);

	Init_Memory(rom);

	return 0;
}

