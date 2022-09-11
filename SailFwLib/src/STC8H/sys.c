/****************************************************************
 * @file    sys.c
 * @author  Simgor001
 ****************************************************************/
#define __STC8H_SL__
#ifdef __STC8H_SL__
#include "sys.h"
void sl_sys_init()
{
    P_SW2 |= 80;    //使能访问XFR

    //配置系统时钟
#if defined(SYS_CLK_IRC) //内部IRC时钟
    CLKSEL = 0;
    HIRCCR |= 0x80;
    //等待振荡稳定
    while (!(HIRCCR & 0x01))
        ;
#elif defined(SYS_CLK_XTAL)    //外部晶振
    CLKSEL = 1;
    XOSCCR |= 0x80;
    //等待振荡稳定
    while (!(XOSCCR & 0x01))
        ;
    //选择时钟源
    XOSCCR |= SYS_CLK_XTAL << 6;
#elif defined(SYS_CLK_IRC_32)  //内部32k IRC时钟
    CLKSEL = 2;
    IRC32KCR |= 0x80;
    //等待振荡稳定
    while (!(IRC32KCR & 0x01))
        ;
#elif defined(SYS_CLK_XTAL_32) //外部32k 晶振
    CLKSEL = 3;
    X32KCR |= 0x80;
    //等待振荡稳定
    while (!(X32KCR & 0x01))
        ;
#endif
    //配置系统分频
    CLKDIV = SYS_CLK_DIV;

    //系统时钟输出分频
    MCLKOCR |= SYS_CLK_OUT_DIV;
    //系统时钟输出引脚
    MCLKOCR |= SYS_CLK_OUT_PIN << 7;
}
#endif