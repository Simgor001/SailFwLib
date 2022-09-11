#ifndef __SL_ISR_H__
#define __SL_ISR_H__
#include "type.h"
#include "sl_config.h"

/*
    中断向量表
*/
#define IRQ_INT0     INT0_VECTOR     /*序号0，中断向量：0003H*/
#define IRQ_TIM0     TMR0_VECTOR     /*序号1，中断向量：000BH*/
#define IRQ_INT1     INT1_VECTOR     /*序号2，中断向量：0013H*/
#define IRQ_TIM1     TMR1_VECTOR     /*序号3，中断向量：001BH*/
#define IRQ_UART1    UART1_VECTOR    /*序号4，中断向量：0023H*/
#define IRQ_ADC      ADC_VECTOR      /*序号5，中断向量：002BH*/
#define IRQ_LVD      LVD_VECTOR      /*序号6，中断向量：0033H*/
#define IRQ_UART2    UART2_VECTOR    /*序号7，中断向量：0043H*/
#define IRQ_SPI      SPI_VECTOR      /*序号8，中断向量：004BH*/
#define IRQ_INT2     INT2_VECTOR     /*序号9，中断向量：0053H*/
#define IRQ_INT3     INT3_VECTOR     /*序号10，中断向量：005BH*/
#define IRQ_TIM2     TMR2_VECTOR     /*序号11，中断向量：0063H*/
#define IRQ_USER     USER_VECTOR     /*序号12，中断向量：006BH*/
#define IRQ_INT4     INT4_VECTOR     /*序号13，中断向量：0083H*/
#define IRQ_UART3    UART3_VECTOR    /*序号14，中断向量：008BH*/
#define IRQ_UART4    UART4_VECTOR    /*序号15，中断向量：0093H*/
#define IRQ_TIM3     TMR3_VECTOR     /*序号16，中断向量：009BH*/
#define IRQ_TIM4     TMR4_VECTOR     /*序号17，中断向量：00A3H*/
#define IRQ_CMP      CMP_VECTOR      /*序号18，中断向量：00ABH*/
#define IRQ_I2C      I2C_VECTOR      /*序号19，中断向量：00C3H*/
#define IRQ_USB      USB_VECTOR      /*序号20，中断向量：00CBH*/
#define IRQ_PWMA     PWMA_VECTOR     /*序号21，中断向量：00D3H*/
#define IRQ_PWMB     PWMB_VECTOR     /*序号22，中断向量：00DBH*/
#define IRQ_TKSU     TKSU_VECTOR     /*序号23，中断向量：011BH*/
#define IRQ_RTC      RTC_VECTOR      /*序号24，中断向量：0123H*/
#define IRQ_P0INT    P0INT_VECTOR    /*序号25，中断向量：012BH*/
#define IRQ_P1INT    P1INT_VECTOR    /*序号26，中断向量：0133H*/
#define IRQ_P2INT    P2INT_VECTOR    /*序号27，中断向量：013BH*/
#define IRQ_P3INT    P3INT_VECTOR    /*序号28，中断向量：0143H*/
#define IRQ_P4INT    P4INT_VECTOR    /*序号29，中断向量：014BH*/
#define IRQ_P5INT    P5INT_VECTOR    /*序号30，中断向量：0153H*/
#define IRQ_P6INT    P6INT_VECTOR    /*序号31，中断向量：015BH*/
#define IRQ_P7INT    P7INT_VECTOR    /*序号32，中断向量：0163H*/
#define IRQ_DMA_M2M  DMA_M2M_VECTOR  /*序号33，中断向量：017BH*/
#define IRQ_DMA_ADC  DMA_ADC_VECTOR  /*序号34，中断向量：0183H*/
#define IRQ_DMA_SPI  DMA_SPI_VECTOR  /*序号35，中断向量：018BH*/
#define IRQ_DMA_UR1T DMA_UR1T_VECTOR /*序号36，中断向量：0193H*/
#define IRQ_DMA_UR1R DMA_UR1R_VECTOR /*序号37，中断向量：019BH*/
#define IRQ_DMA_UR2T DMA_UR2T_VECTOR /*序号38，中断向量：01A3H*/
#define IRQ_DMA_UR2R DMA_UR2R_VECTOR /*序号39，中断向量：01ABH*/
#define IRQ_DMA_UR3T DMA_UR3T_VECTOR /*序号40，中断向量：01B3H*/
#define IRQ_DMA_UR3R DMA_UR3R_VECTOR /*序号41，中断向量：01BBH*/
#define IRQ_DMA_UR4T DMA_UR4T_VECTOR /*序号42，中断向量：01C3H*/
#define IRQ_DMA_UR4R DMA_UR4R_VECTOR /*序号43，中断向量：01CBH*/
#define IRQ_DMA_LCM  DMA_LCM_VECTOR  /*序号44，中断向量：01D3H*/
#define IRQ_LCM      LCM_VECTOR      /*序号45，中断向量：01DBH*/

//判断是否为SDCC编译器
#ifdef __SDCC
#define sl_isr_state(name, IRQ_x) void name(void) __interrupt(IRQ_x)
#define sl_isr_def(name, IRQ_x)   void name(void) __interrupt(IRQ_x)
#else
#define sl_isr_state(name, IRQ_x) void name(void)
#define sl_isr_def(name, IRQ_x)   void name(void) interrupt IRQ_x
#endif

#define INT_0        0
#define INT_1        1
#define INT_2        2
#define INT_3        3
#define INT_4        4

#define _INT_0_IT(x) (IT0 = x)
#define _INT_1_IT(x) (IT1 = x）
#define _INT_2_IT(x) ;
#define _INT_3_IT(x) ;
#define _INT_4_IT(x) ;

#define _INT_0_EN    (EX0 = 1)
#define _INT_1_EN    (EX1 = 1)
#define _INT_2_EN    (INTCLKO |= 0x10)
#define _INT_3_EN    (INTCLKO |= 0x20)
#define _INT_4_EN    (INTCLKO |= 0x40)

#define _INT_0_DIS   (EX0 = 0)
#define _INT_1_DIS   (EX1 = 0)
#define _INT_2_DIS   (INTCLKO &= ~0x10)
#define _INT_3_DIS   (INTCLKO &= ~0x20)
#define _INT_4_DIS   (INTCLKO &= ~0x40)

#ifdef __SL_STC8H__
#define Trig_Edge 0 /*上升沿或下降沿触发*/
#else
#define Trig_LOW 0 /*低电平触发*/
#endif
#define Trig_Fall 1 /*下降沿触发*/

/**
 * @brief 配置外部中断
 * @param INT_x 外部中断号
 * @param Trig_x 外部中断类型
 */
#define sl_isr_exti_config(INT_x, Trig_x) _##INT_x##_IT(Trig_x);

/**
 * @brief 开启外部中断
 * @param INT_x 外部中断号
 */
#define sl_isr_exti_enable(INT_x) \
    {                             \
        EA = 1;                   \
        _##INT_x##_EN;            \
    }

#define sl_isr_exti_disable(INT_x) _##INT_x##_DIS;

#endif // !__SL_ISR_H__