/*******************************************************
*	NES Console 
*******************************************************/

#include <stdio.h>
#include "rom.h"
#include "console.h"

struct Console{
	unsigned char Mapper;
	unsigned char Mirror;
	unsigned char Battery;
};

static struct Console global_console;


void Init_Console(struct ROM* rom)
{
	unsigned char Mapper1 = rom->header.Control1 >> 4;
	unsigned char Mapper2 = rom->header.Control2 >> 4;
	global_console.Mapper = Mapper1 | (Mapper2 << 4);
	unsigned char Mirror1 = rom->header.Control1 & 1;
	unsigned char Mirror2 = (rom->header.Control1 >> 3) & 1;
	global_console.Mirror = Mirror1 | (Mirror2 << 1);
	global_console.Battery = (rom->header.Control1 >> 1) & 1;
}

