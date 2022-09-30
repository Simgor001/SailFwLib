#include "sl_config.h"
#include "DotArray.h"
#define RD  10  //预设红亮度
#define GD  0   //预设绿亮度
#define BD  127 //预设蓝亮度
#define LUM 128 //亮度
// #define IDX 0   //符号索引

#define _RD (RD | 0x80)
#define _GD (GD | 0x80)
#define _BD (BD | 0x80)
//初始化点阵
void dotArray_init();

void dotArray_init()
{
    sl_gpio_init(GPIO_P1, GPIO_Pin_All, GPIO_Mode_Out_PP);

    P1 = 0;

    // sl_gpio_init(GPIO_P2, GPIO_Pin_6, GPIO_Mode_Out_PP);
    sl_gpio_init(GPIO_P0, GPIO_Pin_2, GPIO_Mode_Out_PP);
    sl_gpio_init(GPIO_P0, GPIO_Pin_1, GPIO_Mode_Out_PP);
    sl_gpio_init(GPIO_P0, GPIO_Pin_0, GPIO_Mode_Out_PP);
    sl_gpio_init(GPIO_P2, GPIO_Pin_7, GPIO_Mode_Out_PP);
    sl_gpio_init(GPIO_P2, GPIO_Pin_6, GPIO_Mode_Out_PP);
    P02 = 0;
    P01 = 0;
    P00 = 0;
    P27 = 0;
    P26 = 0;

    sl_gpio_init(GPIO_P2, GPIO_Pin_5, GPIO_Mode_Out_PP);
    sl_gpio_init(GPIO_P2, GPIO_Pin_3, GPIO_Mode_Out_PP);
    sl_gpio_init(GPIO_P2, GPIO_Pin_1, GPIO_Mode_Out_PP);
    sl_gpio_init(GPIO_P3, GPIO_Pin_7, GPIO_Mode_Out_PP);
    sl_gpio_init(GPIO_P3, GPIO_Pin_5, GPIO_Mode_Out_PP);
    P25 = 0;
    P23 = 0;
    P21 = 0;
    P37 = 0;
    P35 = 0;

    sl_gpio_init(GPIO_P2, GPIO_Pin_4, GPIO_Mode_Out_PP);
    sl_gpio_init(GPIO_P2, GPIO_Pin_2, GPIO_Mode_Out_PP);
    sl_gpio_init(GPIO_P2, GPIO_Pin_0, GPIO_Mode_Out_PP);
    sl_gpio_init(GPIO_P3, GPIO_Pin_6, GPIO_Mode_Out_PP);
    sl_gpio_init(GPIO_P3, GPIO_Pin_4, GPIO_Mode_Out_PP);
    P24 = 0;
    P22 = 0;
    P20 = 0;
    P36 = 0;
    P34 = 0;
}

void main()
{
    uint8_t i;

    uint8_t buf_r = 0; //红通道缓存
    uint8_t buf_g = 0; //绿通道缓存
    uint8_t buf_b = 0; //蓝通道缓存

    uint8_t IDX    = 0;
    uint16_t count = 0;

    dotArray_init();

    for (;;)
    {
        count++;
        if (count > 500)
        {
            IDX++;
            IDX   = IDX % 10;
            count = 0;
        }
        /*
        -----------------------------------------------
            第 0 列
        -----------------------------------------------
        */
        //首先装载颜色
        buf_r = _RD;
        buf_g = _GD;
        buf_b = _BD;

        //第二步装载当前需要扫描的行(0)
        DOT = dot_code[IDX][0];
        for (i = 0; i < LUM; i++)
        {
            buf_r--;
            buf_g--;
            buf_b--;
            R0 = buf_r & 0x80;
            G0 = buf_g & 0x80;
            B0 = buf_b & 0x80;
        }
        DOT   = 0; //消影
        R0    = 0;
        G0    = 0;
        B0    = 0;
        /*
        -----------------------------------------------
           第 1 列
        -----------------------------------------------
         */
        //首先装载颜色
        buf_r = _RD;
        buf_g = _GD;
        buf_b = _BD;

        //第二步装载当前需要扫描的行(0)
        DOT = dot_code[IDX][1];
        for (i = 0; i < LUM; i++)
        {
            buf_r--;
            buf_g--;
            buf_b--;
            R1 = buf_r & 0x80;
            G1 = buf_g & 0x80;
            B1 = buf_b & 0x80;
        }
        DOT   = 0; //消影
        R1    = 0;
        G1    = 0;
        B1    = 0;
        /*
        -----------------------------------------------
           第 2 列
        -----------------------------------------------
       */
        //首先装载颜色
        buf_r = _RD;
        buf_g = _GD;
        buf_b = _BD;

        //第二步装载当前需要扫描的行(0)
        DOT = dot_code[IDX][2];
        for (i = 0; i < LUM; i++)
        {
            buf_r--;
            buf_g--;
            buf_b--;
            R2 = buf_r & 0x80;
            G2 = buf_g & 0x80;
            B2 = buf_b & 0x80;
        }
        DOT   = 0; //消影
        R2    = 0;
        G2    = 0;
        B2    = 0;
        /*
        -----------------------------------------------
           第 3 列
        -----------------------------------------------
       */
        //首先装载颜色
        buf_r = _RD;
        buf_g = _GD;
        buf_b = _BD;

        //第二步装载当前需要扫描的行(0)
        DOT = dot_code[IDX][3];
        for (i = 0; i < LUM; i++)
        {
            buf_r--;
            buf_g--;
            buf_b--;
            R3 = buf_r & 0x80;
            G3 = buf_g & 0x80;
            B3 = buf_b & 0x80;
        }
        DOT   = 0; //消影
        R3    = 0;
        G3    = 0;
        B3    = 0;
        /*
        -----------------------------------------------
           第 4 列
        -----------------------------------------------
       */
        //首先装载颜色
        buf_r = _RD;
        buf_g = _GD;
        buf_b = _BD;

        //第二步装载当前需要扫描的行(0)
        DOT = dot_code[IDX][4];
        for (i = 0; i < LUM; i++)
        {
            buf_r--;
            buf_g--;
            buf_b--;
            R4 = buf_r & 0x80;
            G4 = buf_g & 0x80;
            B4 = buf_b & 0x80;
        }
        DOT = 0; //消影
        R4  = 0;
        G4  = 0;
        B4  = 0;
    }
}
