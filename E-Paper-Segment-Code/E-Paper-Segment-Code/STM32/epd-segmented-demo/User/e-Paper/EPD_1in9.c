#include "EPD_1in9.h"
#include "Debug.h"

//////////////////////////////////////full screen update LUT////////////////////////////////////////////

const unsigned char DSPNUM_on[]   = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,       };  // all black
const unsigned char DSPNUM_off[]  = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,       };  // all white
const unsigned char DSPNUM_WB[]   = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,       };  // All black font
const unsigned char DSPNUM_W0[]   = {0x00, 0xbf, 0x1f, 0xbf, 0x1f, 0xbf, 0x1f, 0xbf, 0x1f, 0xbf, 0x1f, 0xbf, 0x1f, 0x00, 0x00,       };  // 0
const unsigned char DSPNUM_W1[]   = {0xff, 0x1f, 0x00, 0x1f, 0x00, 0x1f, 0x00, 0x1f, 0x00, 0x1f, 0x00, 0x1f, 0x00, 0x00, 0x00,       };  // 1
const unsigned char DSPNUM_W2[]   = {0x00, 0xfd, 0x17, 0xfd, 0x17, 0xfd, 0x17, 0xfd, 0x17, 0xfd, 0x17, 0xfd, 0x37, 0x00, 0x00,       };  // 2
const unsigned char DSPNUM_W3[]   = {0x00, 0xf5, 0x1f, 0xf5, 0x1f, 0xf5, 0x1f, 0xf5, 0x1f, 0xf5, 0x1f, 0xf5, 0x1f, 0x00, 0x00,       };  // 3
const unsigned char DSPNUM_W4[]   = {0x00, 0x47, 0x1f, 0x47, 0x1f, 0x47, 0x1f, 0x47, 0x1f, 0x47, 0x1f, 0x47, 0x3f, 0x00, 0x00,       };  // 4
const unsigned char DSPNUM_W5[]   = {0x00, 0xf7, 0x1d, 0xf7, 0x1d, 0xf7, 0x1d, 0xf7, 0x1d, 0xf7, 0x1d, 0xf7, 0x1d, 0x00, 0x00,       };  // 5
const unsigned char DSPNUM_W6[]   = {0x00, 0xff, 0x1d, 0xff, 0x1d, 0xff, 0x1d, 0xff, 0x1d, 0xff, 0x1d, 0xff, 0x3d, 0x00, 0x00,       };  // 6
const unsigned char DSPNUM_W7[]   = {0x00, 0x21, 0x1f, 0x21, 0x1f, 0x21, 0x1f, 0x21, 0x1f, 0x21, 0x1f, 0x21, 0x1f, 0x00, 0x00,       };  // 7
const unsigned char DSPNUM_W8[]   = {0x00, 0xff, 0x1f, 0xff, 0x1f, 0xff, 0x1f, 0xff, 0x1f, 0xff, 0x1f, 0xff, 0x3f, 0x00, 0x00,       };  // 8
const unsigned char DSPNUM_W9[]   = {0x00, 0xf7, 0x1f, 0xf7, 0x1f, 0xf7, 0x1f, 0xf7, 0x1f, 0xf7, 0x1f, 0xf7, 0x1f, 0x00, 0x00,       };  // 9

unsigned char VAR_Temperature=20; 

/******************************************************************************
function :	Software reset
parameter:
******************************************************************************/
void EPD_1in9_Reset(void)
{
    DEV_Digital_Write(EPD_RST_PIN, 1);
    DEV_Delay_ms(200);
    DEV_Digital_Write(EPD_RST_PIN, 0);
    DEV_Delay_ms(20);
    DEV_Digital_Write(EPD_RST_PIN, 1);
    DEV_Delay_ms(200);
}

/******************************************************************************
function :	send command
parameter:
     Reg : Command register
******************************************************************************/
void EPD_1in9_SendCommand(UBYTE Reg)
{
	DEV_I2C_WriteByte(adds_com, Reg);
}

/******************************************************************************
function :	send data
parameter:
    Data : Write data
******************************************************************************/
void EPD_1in9_SendData(UBYTE Data)
{
	DEV_I2C_WriteByte(adds_data, Data);
}

/******************************************************************************
function :	read command
parameter:
     Reg : Command register
******************************************************************************/
UBYTE EPD_1in9_readCommand(UBYTE Reg)
{
	DEV_I2C_WriteByte(adds_com, Reg);
	DEV_Delay_ms(10);
	return DEV_I2C_ReadByte(adds_com);
}

/******************************************************************************
function :	read data
parameter:
    Data : Write data
******************************************************************************/
UBYTE EPD_1in9_readData(UBYTE Data)
{
  DEV_I2C_WriteByte(adds_data, Data);
	DEV_Delay_ms(10);
	return DEV_I2C_ReadByte(Data);
}

/******************************************************************************
function :	Wait until the busy_pin goes LOW
parameter:
******************************************************************************/
void EPD_1in9_ReadBusy(void)
{
    Debug("e-Paper busy\r\n");
	while(1)
	{	 //=1 BUSY
		if(DEV_Digital_Read(EPD_BUSY_PIN)==1) 
			break;
		DEV_Delay_ms(1);
	}
	DEV_Delay_ms(10);
    Debug("e-Paper busy release\r\n");
}

/*
# DU waveform white extinction diagram + black out diagram
# Bureau of brush waveform
*/
void EPD_1in9_lut_DU_WB(void)
{
	EPD_1in9_SendCommand(0x82);
	EPD_1in9_SendCommand(0x80);
	EPD_1in9_SendCommand(0x00);
	EPD_1in9_SendCommand(0xC0);
	EPD_1in9_SendCommand(0x80);
	EPD_1in9_SendCommand(0x80);
	EPD_1in9_SendCommand(0x62);
}

/*   
# GC waveform
# The brush waveform
*/
void EPD_1in9_lut_GC(void)
{
	EPD_1in9_SendCommand(0x82);
	EPD_1in9_SendCommand(0x20);
	EPD_1in9_SendCommand(0x00);
	EPD_1in9_SendCommand(0xA0);
	EPD_1in9_SendCommand(0x80);
	EPD_1in9_SendCommand(0x40);
	EPD_1in9_SendCommand(0x63);
}

/* 
# 5 waveform  better ghosting
# Boot waveform
*/
void EPD_1in9_lut_5S(void)
{
	EPD_1in9_SendCommand(0x82);
	EPD_1in9_SendCommand(0x28);
	EPD_1in9_SendCommand(0x20);
	EPD_1in9_SendCommand(0xA8);
	EPD_1in9_SendCommand(0xA0);
	EPD_1in9_SendCommand(0x50);
	EPD_1in9_SendCommand(0x65);
}

/*
# temperature measurement
# You are advised to periodically measure the temperature and modify the driver parameters
# If an external temperature sensor is available, use an external temperature sensor
*/
void EPD_1in9_Temperature(void)
{
	if( VAR_Temperature < 10 )
	{
		EPD_1in9_SendCommand(0x7E);
		EPD_1in9_SendCommand(0x81);
		EPD_1in9_SendCommand(0xB4);
	}
	else
	{
		EPD_1in9_SendCommand(0x7E);
		EPD_1in9_SendCommand(0x81);
		EPD_1in9_SendCommand(0xB4);
	}
         
    DEV_Delay_ms(10);        
	EPD_1in9_SendCommand(0xe7);    // Set default frame time
        
	// Set default frame time
	if(VAR_Temperature<5)
		EPD_1in9_SendCommand(0x31); // 0x31  (49+1)*20ms=1000ms
	else if(VAR_Temperature<10)
		EPD_1in9_SendCommand(0x22); // 0x22  (34+1)*20ms=700ms
	else if(VAR_Temperature<15)
		EPD_1in9_SendCommand(0x18); // 0x18  (24+1)*20ms=500ms
	else if(VAR_Temperature<20)
		EPD_1in9_SendCommand(0x13); // 0x13  (19+1)*20ms=400ms
	else
		EPD_1in9_SendCommand(0x0e); // 0x0e  (14+1)*20ms=300ms
}

/*
# Note that the size and frame rate of V0 need to be set during initialization, 
# otherwise the local brush will not be displayed
*/
void EPD_1in9_init(void)
{
	EPD_1in9_Reset();
	DEV_Delay_ms(100);


	EPD_1in9_SendCommand(0x2B); // POWER_ON

	DEV_Delay_ms(10);
	EPD_1in9_SendCommand(0xA7); // boost
	EPD_1in9_SendCommand(0xE0); // TSON 
	DEV_Delay_ms(10);
	EPD_1in9_Temperature();
}

void EPD_1in9_Write_Screen( unsigned char *image)
{
	EPD_1in9_SendCommand(0xAC); // Close the sleep
	EPD_1in9_SendCommand(0x2B); // turn on the power
	EPD_1in9_SendCommand(0x40); // Write RAM address
	EPD_1in9_SendCommand(0xA9); // Turn on the first SRAM
	EPD_1in9_SendCommand(0xA8); // Shut down the first SRAM

	for(char j = 0 ; j<15 ; j++ )
		EPD_1in9_SendData(image[j]);

	EPD_1in9_SendData(0x00);
	EPD_1in9_SendCommand(0xAB); // Turn on the second SRAM
	EPD_1in9_SendCommand(0xAA); // Shut down the second SRAM
	EPD_1in9_SendCommand(0xAF); // display on
	EPD_1in9_ReadBusy();
	
	//DEV_Delay_ms(2000);
	EPD_1in9_SendCommand(0xAE); // display off
	EPD_1in9_SendCommand(0x28); // HV OFF
	EPD_1in9_SendCommand(0xAD); // sleep in	

}

void EPD_1in9_Write_Screen1( unsigned char *image)
{
	EPD_1in9_SendCommand(0xAC); // Close the sleep
	EPD_1in9_SendCommand(0x2B); // turn on the power
	EPD_1in9_SendCommand(0x40); // Write RAM address
	EPD_1in9_SendCommand(0xA9); // Turn on the first SRAM
	EPD_1in9_SendCommand(0xA8); // Shut down the first SRAM

	for(char j = 0 ; j<15 ; j++ )
		EPD_1in9_SendData(image[j]);

	EPD_1in9_SendData(0x03);
	EPD_1in9_SendCommand(0xAB); // Turn on the second SRAM
	EPD_1in9_SendCommand(0xAA); // Shut down the second SRAM
	EPD_1in9_SendCommand(0xAF); // display on
	EPD_1in9_ReadBusy();

	//DEV_Delay_ms(2000);
	EPD_1in9_SendCommand(0xAE); // display off
	EPD_1in9_SendCommand(0x28); // HV OFF
	EPD_1in9_SendCommand(0xAD); // sleep in	

}

void EPD_1in9_sleep(void)
{
	EPD_1in9_SendCommand(0x28); // POWER_OFF
	EPD_1in9_ReadBusy();
	EPD_1in9_SendCommand(0xAC); // DEEP_SLEEP

	DEV_Delay_ms(2000);
}











