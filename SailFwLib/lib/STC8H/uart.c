#include "sys.h"
#include "uart.h"
#ifdef __SDCC
int getchar(void)
{
    return 0;
}
int putchar(int c)
{
    SBUF = c;
    while (!TI)
        ;
    TI = 0;
    return c;
}
#else
char getchar(void)
{
    return 0;
}
char putchar(char c)
{
    SBUF = c;
    while (!TI)
        ;
    TI = 0;
    return c;
}
#endif // __SDCC