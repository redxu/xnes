#include <stdio.h>
#include "../core/rom.h"
#include "../core/cpu.h"




int main(int arc,char** argv)
{
	int rtv = Init_NesRom("test.nes");
	int i;
	for(i=0;i<0x20;i++)
	{
		Cpu_Step();
	}
	return 0;
}

