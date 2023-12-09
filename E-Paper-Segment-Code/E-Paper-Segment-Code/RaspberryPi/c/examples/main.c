#include <stdlib.h>     //exit()
#include <signal.h>     //signal()
#include "EPD_Test.h"   //Examples

void  Handler(int signo)
{
    //System Exit
    printf("\r\nHandler:exit\r\n");
    DEV_Module_Exit();

    exit(0);
}

int main(void)
{
    // Exception handling:ctrl + c
    signal(SIGINT, Handler);
	
    EPD_1in9_test();




	// 	For Test
    // if(DEV_Module_Init()!=0){
        // return -1;
    // }

	// DEV_Module_Exit();
	// 
    return 0;
}
