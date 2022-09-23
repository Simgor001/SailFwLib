/****************************************************************
 * @file    sys.c
 * @author  Simgor001
 ****************************************************************/
#include "sys.h"
#ifdef __SL_STC8H__

//多少个周期为1ms
uint16_t _sys_cycle_ms_count = 0;
#ifdef SL_LOG
uint16_t _sys_baud = 0;
#endif
void sl_sys_init()
{
    P_SW2 |= 80; //使能访问XFR

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

    //打开总中断
    EA = 1;

    //魔法数据！（通过回归运算求出来的，不准确！）
    _sys_cycle_ms_count = FOSC / 12000 + (FOSC / 89565.6 + 80.7);

#ifdef SL_LOG
    //初始化SL_LOG
    sl_uart_init(UART_1, UART_Mode_VBR_8, UART_Multi_Disable);
    sl_uart_config(UART_1, TIM_1);
    sl_tim_init(TIM_1, GATE_Disable, CT_Timer, TIM_Mode_8_Auto, TIM_Isr_Disable);
    sl_tim_config(TIM_1, TIM_Speed_1T, TIM_Clk_Out_Disable);
    _sys_baud = FOSC / BAUD / 32;
    sl_tim_load_cycle(TIM_1, _sys_baud);
    sl_tim_enable(TIM_1);

    sl_delay(10);
#endif
}

void sl_delay(uint32_t ms)
{
    uint16_t i;
    while (ms--)
        for (i = 0; i < _sys_cycle_ms_count; i++)
            ;
}
#endif