This file is to help you use this routine.
Since our ink screens are getting more and more, it is not convenient for our maintenance, so all the ink screen programs are made into one project.
A brief description of the use of this project is here:

1. Basic information:
This routine is verified using the corresponding module with the PICO. 
You can see the corresponding test routine in the examples\ of the project.

2. Pin connection:
Pin connection You can look at dev_config.c/h in \lib\Config. Again, here:
EPD    =>   XNUCLEO-F103RB
VCC    ->    3.3V
GND    ->    GND
SDA     ->    PB9/D14
SCL     ->	   PB8/D15
RST     ->     PA9/D8
BUSY   ->    PA8/D7

3. Directory structure (selection):
If you use our products frequently, we will be very familiar with our program directory structure. We have a copy of the specific function.
The API manual for the function, you can download it on our WIKI or request it as an after-sales customer service. Here is a brief introduction:
Config\: This directory is a hardware interface layer file. You can see many definitions in DEV_Config.c(.h), including:
   type of data;
    GPIO;
    Read and write GPIO;
    Delay: Note: This delay function does not use an oscilloscope to measure specific values.
    Module Init and exit processing:
        void DEV_Module_Init(void);
        void DEV_Module_Exit(void);
        Note: Here is the processing of some GPIOs before and after using the ink screen.
        
\User\e-paper\: This screen is the ink screen driver function;
examples\: This is the test program for the ink screen. You can see the specific usage method in it.