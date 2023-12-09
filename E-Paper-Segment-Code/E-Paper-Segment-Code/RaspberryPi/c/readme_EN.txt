This file is to help you use this routine.
A brief description of the use of this project is here:

1. Basic information:
This routine has been verified using the e-paper Driver HAT module. 
You can view the corresponding test routines in the \lib\Examples\ 
of the project.

2. Pin connection:
Pin connection You can view it in DEV_Config.h in the \lib\Config\ directory, and repeat it here:
EPD    =>   RPI(BCM)
VCC    ->    3.3
GND    ->    GND
SDA    ->    2
SCL    ->    3
RST    ->    4
BUSY   ->    17

3. Basic use:
Since this project is a comprehensive project, you may need to read the following for use:
You can see the 19 functions that have been annotated in lines 19 through 43 of main.c.
Please note which ink screen you purchased.
	Uncomment the corresponding function

Then you need to execute: 
make
compile the program, will generate the executable file: main
Run: 
sudo ./main
If you modify the program, you need to execute: 
make clear
then:
make

4. Directory structure (selection):
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
   
\lib\E-paper\: This screen is the ink screen driver function;
Examples\: This is the test program for the ink screen. You can see the specific usage method in it.