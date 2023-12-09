这个文件是帮助您使用本例程。
在这里简略的描述本工程的使用：

1.基本信息：
本例程使用相对应的模块搭配Pico进行了验证，你可以在工程的examples\中查看对应的测试例程;

2.管脚连接：
管脚连接你可以在\User\Config目录下查看DEV_Config.c/h中查看，这里也再重述一次：
EPD    =>   XNUCLEO-F103RB
VCC    ->    3.3V
GND    ->    GND
SDA     ->    PB9/D14
SCL     ->	   PB8/D15
RST     ->     PA9/D8
BUSY   ->    PA8/D7

3.目录结构（选读）：
如果你经常使用我们的产品，对我们的程序目录结构会十分熟悉，关于具体的函数的我们有一份
函数的API手册，你可以在我们的WIKI上下载或像售后客服索取，这里简单介绍一次：
\User\Config\:此目录为硬件接口层文件，在DEV_Config.c(.h)可以看到很多定义，包括：
    数据类型;
    GPIO;
    读写GPIO;
    延时：注意：此延时函数并未使用示波器测量具体数值,因此会不准;
    模块初始化与退出的处理：
        void DEV_Module_Init(void);
        void DEV_Module_Exit(void);
        注意：这里是处理使用墨水屏前与使用完之后一些GPIO的处理。

\lib\e-paper\:此目录下为墨水屏驱动函数;
examples\:此目录下为墨水屏的测试程序，你可在其中看到具体的使用方法;