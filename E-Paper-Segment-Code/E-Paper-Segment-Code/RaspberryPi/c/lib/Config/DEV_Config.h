#ifndef _DEV_CONFIG_H_
#define _DEV_CONFIG_H_
/***********************************************************************************************************************
			------------------------------------------------------------------------
			|\\\																///|
			|\\\					Hardware interface							///|
			------------------------------------------------------------------------
***********************************************************************************************************************/
#ifdef USE_BCM2835_LIB
    #include <bcm2835.h>
#elif USE_WIRINGPI_LIB
    #include <wiringPi.h>
    #include <wiringPiI2C.h>
#elif USE_DEV_LIB
    #include "sysfs_gpio.h"
    #include "dev_hardware_i2c.h"
    
#endif

#include <stdint.h>
#include "Debug.h"

#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define DEV_SPI 0
#define DEV_I2C 1

/**
 * data
**/
#define UBYTE   uint8_t
#define UWORD   uint16_t
#define UDOUBLE uint32_t


/**
 * GPIOI config
**/
extern int EPD_RST_PIN;
// extern int EPD_DC_PIN;
// extern int EPD_CS_PIN;
extern int EPD_BUSY_PIN;



/*------------------------------------------------------------------------------------------------------*/
uint8_t DEV_ModuleInit(void);
void    DEV_ModuleExit(void);

void DEV_I2C_Init(uint8_t Add);
void I2C_Write_Byte(uint8_t value);
void I2C_Write_OnlyByte(uint8_t value);

int I2C_Read_Byte(uint8_t Cmd);
int I2C_Read_Word(uint8_t Cmd);
char I2C_Read_OnlyByte(void);

void I2C_SET_Addr(uint8_t Addr);

void DEV_GPIO_Mode(UWORD Pin, UWORD Mode);
void DEV_Digital_Write(UWORD Pin, UBYTE Value);
UBYTE DEV_Digital_Read(UWORD Pin);

void DEV_Delay_ms(UDOUBLE xms);

void DEV_SPI_WriteByte(UBYTE Value);
void DEV_SPI_Write_nByte(uint8_t *pData, uint32_t Len);


UBYTE DEV_Module_Init(void);
void DEV_Module_Exit(void);



#endif
