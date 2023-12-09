/*****************************************************************************
* | File      	:   EPD_2in13b_V3_test.c
* | Author      :   Waveshare team
* | Function    :   2.13inch B V3 e-paper test demo
* | Info        :
*----------------
* |	This version:   V1.0
* | Date        :   2020-04-13
* | Info        :
* -----------------------------------------------------------------------------
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documnetation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to  whom the Software is
# furished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS OR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
#
******************************************************************************/
#include "EPD_Test.h"
#include "EPD_1in9.h"

unsigned char b[15];

void a(const unsigned char* image_buffer)
{
	for(char i = 0 ; i < 15 ; i++)
	{
		b[i] = image_buffer[i];
	}
}


int EPD_1in9_test(void)
{
	printf("EPD_1IN9_test Demo\r\n");
    if(DEV_Module_Init()!=0){
        return -1;
    }

    printf("e-Paper Init and Clear...\r\n");
	EPD_1in9_init();
	
	EPD_1in9_lut_5S();
	a(DSPNUM_1in9_off);
	EPD_1in9_Write_Screen(b);
	DEV_Delay_ms(500);
	
	EPD_1in9_lut_GC();
	
	a(DSPNUM_1in9_on);
	EPD_1in9_Write_Screen1(b);
	DEV_Delay_ms(500);
	
	a(DSPNUM_1in9_off);
	EPD_1in9_Write_Screen(b);
	DEV_Delay_ms(500);
	
	EPD_1in9_lut_DU_WB();
	a(DSPNUM_1in9_W0);
	EPD_1in9_Write_Screen(b);
	DEV_Delay_ms(500);
	a(DSPNUM_1in9_W1);
	EPD_1in9_Write_Screen(b);
	DEV_Delay_ms(500);
	a(DSPNUM_1in9_W2);
	EPD_1in9_Write_Screen(b);
	DEV_Delay_ms(500);
	a(DSPNUM_1in9_W3);
	EPD_1in9_Write_Screen(b);
	DEV_Delay_ms(500);
	a(DSPNUM_1in9_W4);
	EPD_1in9_Write_Screen(b);
	DEV_Delay_ms(500);
	a(DSPNUM_1in9_W5);
	EPD_1in9_Write_Screen(b);
	DEV_Delay_ms(500);
	a(DSPNUM_1in9_W6);
	EPD_1in9_Write_Screen(b);
	DEV_Delay_ms(500);
	a(DSPNUM_1in9_W7);
	EPD_1in9_Write_Screen(b);
	DEV_Delay_ms(500);
	a(DSPNUM_1in9_W8);
	EPD_1in9_Write_Screen(b);
	DEV_Delay_ms(500);
	a(DSPNUM_1in9_W9);
	EPD_1in9_Write_Screen(b);
	DEV_Delay_ms(500);
	a(DSPNUM_1in9_WB);
	EPD_1in9_Write_Screen(b);
	DEV_Delay_ms(500);

	// EPD_1in9_SendCommand(0xE1);
	// EPD_1in9_SendCommand(0xE5);
	// EPD_1in9_SendCommand(0x73);

	// char g= 0 ;
	// g = EPD_1in9_readCommand(0xE4);
	// printf("%d\r\n",g);

	
	EPD_1in9_sleep();
	
}







