#ifndef __SL_TIM_H__
#define __SL_TIM_H__
#include "sl_type.h"
#include "sl_config.h"

#define TIM_0        0
#define TIM_1        1
#define TIM_2        2
#define TIM_3        3
#define TIM_4        4

#define GATE_Disable 0 //软开启
#define GATE_Enable  1 //由外部中断开启（仅TIM0、TIM1有效）
#define _TIM_0_GATE(x)   \
    {                    \
        TMOD &= (~0x08); \
        TMOD |= x << 3;  \
    }
#define _TIM_1_GATE(x)   \
    {                    \
        TMOD &= (~0x80); \
        TMOD |= x << 7;  \
    }
#define _TIM_2_GATE(x) sl_log_warn(x, "The TIM2 cannot set GATE flag! ")
#define _TIM_3_GATE(x) sl_log_warn(x, "The TIM3 cannot set GATE flag! ")
#define _TIM_4_GATE(x) sl_log_warn(x, "The TIM4 cannot set GATE flag! ")

#define CT_Timer       0 //定时器
#define CT_Count       1 //计数器
#define _TIM_0_CT(x)     \
    {                    \
        TMOD &= (~0x04); \
        TMOD |= x << 2;  \
    }
#define _TIM_1_CT(x)     \
    {                    \
        TMOD &= (~0x40); \
        TMOD |= x << 6;  \
    }
#define _TIM_2_CT(x)     \
    {                    \
        AUXR &= (~0x08); \
        AUXR |= x << 3;  \
    }
#define _TIM_3_CT(x)      \
    {                     \
        T4T3M &= (~0x04); \
        T4T3M |= x << 2;  \
    }
#define _TIM_4_CT(x)      \
    {                     \
        T4T3M &= (~0x40); \
        T4T3M |= x << 6;  \
    }

#define TIM_Mode_16_Auto      0 // 16位自动重载模式
#define TIM_Mode_16           1 // 16位不自动重载模式
#define TIM_Mode_8_Auto       2 // 8位自动重载模式
#define TIM_Mode_Stop         3 //停止工作
#define TIM_Mode_TIM0_16_Auto 3 // TIM0独有不可屏蔽中断的16位自动重载模式
#define _TIM_0_Mode(x)   \
    {                    \
        TMOD &= (~0x03); \
        TMOD |= x;       \
    }
#define _TIM_1_Mode(x)   \
    {                    \
        TMOD &= (~0x30); \
        TMOD |= x << 4;  \
    }
#define _TIM_2_Mode(x)  sl_log_warn(x, "The TIM2 cannot set Mode flag! ")
#define _TIM_3_Mode(x)  sl_log_warn(x, "The TIM3 cannot set Mode flag! ")
#define _TIM_4_Mode(x)  sl_log_warn(x, "The TIM4 cannot set Mode flag! ")

#define TIM_Isr_Disable 0 //禁用定时器中断
#define TIM_Isr_Enable  1 //启用定时器中断

#define _TIM_0_Isr(x)   ET0 = x
#define _TIM_1_Isr(x)   ET1 = x
#define _TIM_2_Isr(x)   \
    {                   \
        IE2 &= (~0x04); \
        IE2 |= x << 2;  \
    }
#define _TIM_3_Isr(x)   \
    {                   \
        IE2 &= (~0x20); \
        IE2 |= x << 5;  \
    }
#define _TIM_4_Isr(x)   \
    {                   \
        IE2 &= (~0x40); \
        IE2 |= x << 6;  \
    }

//初始化定时器
#define sl_tim_init(TIM_x, GATE_x, CT_x, TIM_Mode_x, TIM_Isr_x) \
    {                                                           \
        _##TIM_x##_GATE(GATE_x);                                \
        _##TIM_x##_CT(GATE_x);                                  \
        _##TIM_x##_Mode(TIM_Mode_x);                            \
        _##TIM_x##_Isr(TIM_Isr_x);                              \
    }
//配置定时器
//速率speed
#define TIM_Speed_12T 0 //系统时钟/12
#define TIM_Speed_1T  1 //不分频

#define _TIM_0_Speed(x)  \
    {                    \
        AUXR &= (~0x80); \
        AUXR |= x << 7;  \
    }
#define _TIM_1_Speed(x)  \
    {                    \
        AUXR &= (~0x40); \
        AUXR |= x << 6;  \
    }
#define _TIM_2_Speed(x)  \
    {                    \
        AUXR &= (~0x04); \
        AUXR |= x << 2;  \
    }
#define _TIM_3_Speed(x)   \
    {                     \
        T4T3M &= (~0x02); \
        AUXR |= x << 1;   \
    }
#define _TIM_4_Speed(x)   \
    {                     \
        T4T3M &= (~0x20); \
        AUXR |= x << 5;   \
    }

#define TIM_Clk_Out_Disable 0 //关闭时钟输出
#define TIM_Clk_Out_Enable  1 //开启时钟输出

#define _TIM_0_Out(x)       \
    {                       \
        INTCLKO &= (~0x01); \
        INTCLKO |= x;       \
    }
#define _TIM_1_Out(x)       \
    {                       \
        INTCLKO &= (~0x02); \
        INTCLKO |= x << 1;  \
    }
#define _TIM_2_Out(x)       \
    {                       \
        INTCLKO &= (~0x04); \
        INTCLKO |= x << 2;  \
    }
#define _TIM_3_Out(x)     \
    {                     \
        T4T3M &= (~0x01); \
        T4T3M |= x;       \
    }
#define _TIM_4_Out(x)     \
    {                     \
        T4T3M &= (~0x10); \
        T4T3M |= x << 4;  \
    }

//时钟信号输出
#define sl_tim_config(TIM_x, TIM_Speed_x, TIM_Clk_Out_x) \
    {                                                    \
        _##TIM_x##_Speed(TIM_Speed_x);                   \
        _##TIM_x##_Out(TIM_Clk_Out_x);                   \
    }

//详见数据手册
#define TIM_GPIO_0 0
#define TIM_GPIO_1 1

//定时器相关引脚（T3T4特供）
#define sl_tim_gpio(TIM_GPIO_x) \
    {                           \
        T3T4PIN &= (~0x01);     \
        T4T3M |= TIM_GPIO_x;    \
    }

#define _TIM_0_H         TH0
#define _TIM_0_L         TL0

#define _TIM_1_H         TH1
#define _TIM_1_L         TL1

#define _TIM_2_H         T2H
#define _TIM_2_L         T2L

#define _TIM_3_H         T3H
#define _TIM_3_L         T3L

#define _TIM_4_H         T4H
#define _TIM_4_L         T4L

#define _TIM_0_Mode_Flag (TMOD & 0x03) == 1
#define _TIM_1_Mode_Flag (TMOD & 0x30) == 1
#define _TIM_2_Mode_Flag 0
#define _TIM_3_Mode_Flag 0
#define _TIM_4_Mode_Flag 0

//按周期装载
#define sl_tim_load_cycle(TIM_x, cycle)            \
    {                                              \
        if (_##TIM_x##_Mode_Flag)                  \
        {                                          \
            _##TIM_x##_H = 256 - cycle;            \
            _##TIM_x##_L = 256 - cycle;            \
        }                                          \
        else                                       \
        {                                          \
            _##TIM_x##_H = (65536 - cycle) >> 8;   \
            _##TIM_x##_L = (65536 - cycle) & 0xFF; \
        }                                          \
    }

#define _TIM_0_Speed_Flag (AUXR & 0x80) == 1
#define _TIM_1_Speed_Flag (AUXR & 0x40) == 1
#define _TIM_2_Speed_Flag (AUXR & 0x04) == 1
#define _TIM_3_Speed_Flag (T4T3M & 0x02) == 1
#define _TIM_4_Speed_Flag (T4T3M & 0x20) == 1

static uint16_t _TIM_load_count = 0;
//按微秒装载
#define sl_tim_load(TIM_x, us)                           \
    {                                                    \
        if (_##TIM_x##_Speed_Flag)                       \
            _TIM_load_count = us * (FOSC / 12000000L);   \
        else                                             \
            _TIM_load_count = us * (FOSC / 1000000L);    \
        _##TIM_x##_H = (65536 - _TIM_load_count) >> 8;   \
        _##TIM_x##_L = (65536 - _TIM_load_count) & 0xFF; \
    }

#define _TIM_0_EN  TR0 = 1;
#define _TIM_1_EN  TR1 = 1;
#define _TIM_2_EN  AUXR |= (0x10);
#define _TIM_3_EN  T4T3M |= (0x08);
#define _TIM_4_EN  T4T3M |= (0x80);

#define _TIM_0_DIS TR0 = 0;
#define _TIM_1_DIS TR1 = 0;
#define _TIM_2_DIS AUXR &= (~0x10);
#define _TIM_3_DIS T4T3M &= (~0x08);
#define _TIM_4_DIS T4T3M &= (~0x80);

//启用
#define sl_tim_enable(TIM_x) _##TIM_x##_EN
//禁用
#define sl_tim_disable(TIM_x) _##TIM_x##_DIS

#define _TIM_0_Flag           TF0
#define _TIM_1_Flag           TF1
#define _TIM_2_Flag           (sl_log(LOG_WARN, "The TIM2 cannot check ISR flag! "), 0)
#define _TIM_3_Flag           (sl_log(LOG_WARN, "The TIM3 cannot check ISR flag! "), 0)
#define _TIM_4_Flag           (sl_log(LOG_WARN, "The TIM4 cannot check ISR flag! "), 0)

#define _TIM_0_Reset_Flag     TF0 = 0;
#define _TIM_1_Reset_Flag     TF1 = 0;
#define _TIM_2_Reset_Flag     sl_log(LOG_WARN, "The TIM2 cannot reset ISR flag! ");
#define _TIM_3_Reset_Flag     sl_log(LOG_WARN, "The TIM3 cannot reset ISR flag! ");
#define _TIM_4_Reset_Flag     sl_log(LOG_WARN, "The TIM4 cannot reset ISR flag! ");

//检查溢出中断标志位
#define sl_tim_flag(TIM_x) _##TIM_x##_Flag
//复位溢出中断标志位
#define sl_tim_reset_flag(TIM_x) _##TIM_x##_Reset_Flag
#endif