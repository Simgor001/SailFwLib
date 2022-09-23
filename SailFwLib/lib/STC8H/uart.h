#ifndef _SL_UART_H_
#define _SL_UART_H_
#include "tim.h"

#define UART_1             SCON  //串口1
#define UART_2             S2CON //串口2
#define UART_3             S3CON //串口3
#define UART_4             S4CON //串口4

#define UART_Mode_Sync     0        //同步移位输出
#define UART_Mode_VBR_8    (1 << 6) //可变波特率8位数据
#define UART_Mode_CBR_9    (2 << 6) //固定波特率9位数据
#define UART_Mode_VBR_9    (3 << 6) //可变波特率9位数据

#define UART_Multi_Disable 0 //禁用多机通信
#define UART_Multi_Enable  1 //启用多机通信

#define sl_uart_init(UART_x, UART_Mode_x, UART_Multi_x) \
    {                                                   \
        UART_x = 0x08;                                  \
        UART_x |= UART_Mode_x;                          \
        UART_x |= (UART_Multi_x << 5);                  \
    }

#define _UART_1_TIM_0                                       \
    {                                                       \
        AUXR &= (~0x01);                                    \
        sl_log(LOG_WARN, "TIM0 cannot be used by UART1! "); \
    }
#define _UART_1_TIM_1 AUXR &= (~0x01);
#define _UART_1_TIM_2 AUXR |= 0x01;
#define _UART_1_TIM_3                                       \
    {                                                       \
        AUXR &= (~0x01);                                    \
        sl_log(LOG_WARN, "TIM3 cannot be used by UART1! "); \
    }
#define _UART_1_TIM_4                                       \
    {                                                       \
        AUXR &= (~0x01);                                    \
        sl_log(LOG_WARN, "TIM4 cannot be used by UART1! "); \
    }

#define _UART_2_TIM_0 sl_log(LOG_WARN, "TIM0 cannot be used by UART2! ");
#define _UART_2_TIM_1 sl_log(LOG_WARN, "TIM1 cannot be used by UART2! ");
#define _UART_2_TIM_2 sl_log(LOG_WARN, "TIM2 cannot be used by UART2! ");
#define _UART_2_TIM_3 sl_log(LOG_WARN, "TIM3 cannot be used by UART2! ");
#define _UART_2_TIM_4 sl_log(LOG_WARN, "TIM4 cannot be used by UART2! ");

#define _UART_3_TIM_0                                       \
    {                                                       \
        S3CON &= (~0x40);                                   \
        sl_log(LOG_WARN, "TIM0 cannot be used by UART3! "); \
    }
#define _UART_3_TIM_1                                       \
    {                                                       \
        S3CON &= (~0x40);                                   \
        sl_log(LOG_WARN, "TIM1 cannot be used by UART3! "); \
    }
#define _UART_3_TIM_2 S3CON &= (~0x40);
#define _UART_3_TIM_3 S3CON |= 0x40;
#define _UART_3_TIM_4                                       \
    {                                                       \
        S3CON &= (~0x40);                                   \
        sl_log(LOG_WARN, "TIM4 cannot be used by UART3! "); \
    }

#define _UART_4_TIM_0                                       \
    {                                                       \
        S4CON &= (~0x40);                                   \
        sl_log(LOG_WARN, "TIM0 cannot be used by UART3! "); \
    }
#define _UART_4_TIM_1                                       \
    {                                                       \
        S4CON &= (~0x40);                                   \
        sl_log(LOG_WARN, "TIM1 cannot be used by UART3! "); \
    }
#define _UART_4_TIM_2 S3CON &= (~0x40);
#define _UART_4_TIM_3                                       \
    {                                                       \
        S4CON &= (~0x40);                                   \
        sl_log(LOG_WARN, "TIM3 cannot be used by UART3! "); \
    }
#define _UART_4_TIM_4                 S4CON |= 0x40;

//配置串口
#define sl_uart_config(UART_x, TIM_x) _##UART_x##_##TIM_x;

//设置波特率
#define sl_uart_set_baud(UART_x,baud)

#endif // !_SL_UART_H_