#ifndef __SL_TIM_H__
#define __SL_TIM_H__
#include "type.h"
#include "sl_config.h"

#define TIM_0        0
#define TIM_1        1
#define TIM_2        2
#define TIM_3        3
#define TIM_4        4

#define GATE_Disable 0
#define GATE_Enable  1
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
#define _TIM_2_GATE(x) ;
#define _TIM_3_GATE(x) ;
#define _TIM_4_GATE(x) ;

#define CT_Timer       0
#define CT_Count       1
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
#define TIM_Mode_TIM0_16_Auto 3 // TIM0独有的不可屏蔽中断的16位自动重载模式
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
#define _TIM_2_Mode(x) ;
#define _TIM_3_Mode(x) ;
#define _TIM_4_Mode(x) ;

//初始化定时器
#define sl_tim_init(TIM_x, GATE_x, CT_x, TIM_Mode_x) \
    {                                                \
        _##TIM_x##_GATE(GATE_x);                     \
        _##TIM_x##_CT(GATE_x);                       \
        _##TIM_x##_Mode(TIM_Mode_x);                 \
    }
//配置定时器
#define sl_tim_config(TIM_x)
//时钟输出
#define sl_tim_clk_out(TIM_x)
//装载
#define sl_tim_load(TIM_x, us)
//选择引脚
#define sl_tim_mux(TIM_x)
//启用
#define sl_tim_enable(TIM_x)
//禁用
#define sl_tim_disable(TIM_x)
//检查溢出中断标志位
#define sl_tim_flag(TIM_x)
//复位溢出中断标志位
#define sl_tim_reset_flag(TIM_x)
#endif