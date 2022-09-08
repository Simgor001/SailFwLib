/****************************************************************
 * @file    sys.c
 * @author  Simgor001
 ****************************************************************/
#define __STC8H_SFL__
#ifdef __STC8H_SFL__
#include "sys.h"
void sfl_sys_init()
{
#if defined(SYS_CLK_IRC)
    CLKSEL = 0;
    HIRCCR |= 0x80;
#elif defined(SYS_CLK_XTAL)
    CLKSEL = 1;
    XOSCCR |= 0x80;
#elif defined(SYS_CLK_IRC_32)
    CLKSEL = 2;
    IRC32KCR |= 0x80;
#elif defined(SYS_CLK_XTAL_32)
    CLKSEL = 3;
    X32KCR |= 0x80;
#endif
    CLKDIV = SYS_CLK_DIV;
}
#endif