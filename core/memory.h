#ifndef __MEMORY__H__
#define __MEMORY__H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void Init_Memory(struct ROM* rom);

unsigned char Mem_ReadB(uint16_t address);

uint16_t Mem_ReadW(uint16_t address);

void Mem_WriteB(uint16_t address,unsigned char value);

void Mem_WriteW(uint16_t address,uint16_t value);

#ifdef __cplusplus
}
#endif

#endif

