#ifndef _EPD_1in9_H_
#define _EPD_1in9_H_


#include "DEV_Config.h"
// address
#define adds_com  	0x3C
#define adds_data		0x3D

void EPD_1in9_Reset(void);
void EPD_1in9_SendCommand(UBYTE Reg);
void EPD_1in9_SendData(UBYTE Data);
UBYTE EPD_1in9_readCommand(UBYTE Reg);
UBYTE EPD_1in9_readData(UBYTE Data);
void EPD_1in9_ReadBusy(void);
void EPD_1in9_lut_DU_WB(void);
void EPD_1in9_lut_GC(void);
void EPD_1in9_lut_5S(void);
void EPD_1in9_Temperature(void);
void EPD_1in9_init(void);
void EPD_1in9_Write_Screen(unsigned char *image);
void EPD_1in9_Write_Screen1(unsigned char *image);
void EPD_1in9_sleep(void);

#endif
