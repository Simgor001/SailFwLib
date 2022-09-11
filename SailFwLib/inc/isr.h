#ifndef __SL_ISR_H__
#define __SL_ISR_H__
#include "type.h"
#include "sl_config.h"

/*
    中断向量表
*/
#define Vector_INT0     INT0_VECTOR  // 0003H
#define Vector_TIM0     TMR0_VECTOR  // 000BH
#define Vector_INT1     INT1_VECTOR  // 0013H
#define Vector_TIM1     TMR1_VECTOR  // 001BH
#define Vector_UART1    UART1_VECTOR // 0023H
#define Vector_ADC      ADC_VECTOR   // 002BH
#define Vector_LVD      LVD_VECTOR   // 0033H
#define Vector_UART2    UART2_VECTOR // 0043H
#define Vector_SPI      SPI_VECTOR   // 004BH
#define Vector_INT2     INT2_VECTOR  // 0053H
#define Vector_INT3     INT3_VECTOR  // 005BH
#define Vector_TIM2     TMR2_VECTOR  // 0063H
#define Vector_USER     USER_VECTOR  // 006BH
#define Vector_INT4     INT4_VECTOR  // 0083H
#define Vector_UART3    UART3_VECTOR // 008BH
#define Vector_UART4    UART4_VECTOR // 0093H
#define Vector_TIM3     TMR3_VECTOR  // 009BH
#define Vector_TIM4     TMR4_VECTOR  // 00A3H
#define Vector_CMP      CMP_VECTOR   // 00ABH
#define Vector_I2C      I2C_VECTOR   // 00C3H
#define Vector_USB      USB_VECTOR   // 00CBH
#define Vector_PWMA     PWMA_VECTOR  // 00D3H
#define Vector_PWMB     PWMB_VECTOR  // 00DBH

#define Vector_TKSU     TKSU_VECTOR     // 011BH
#define Vector_RTC      RTC_VECTOR      // 0123H
#define Vector_P0INT    P0INT_VECTOR    // 012BH
#define Vector_P1INT    P1INT_VECTOR    // 0133H
#define Vector_P2INT    P2INT_VECTOR    // 013BH
#define Vector_P3INT    P3INT_VECTOR    // 0143H
#define Vector_P4INT    P4INT_VECTOR    // 014BH
#define Vector_P5INT    P5INT_VECTOR    // 0153H
#define Vector_P6INT    P6INT_VECTOR    // 015BH
#define Vector_P7INT    P7INT_VECTOR    // 0163H
#define Vector_DMA_M2M  DMA_M2M_VECTOR  // 017BH
#define Vector_DMA_ADC  DMA_ADC_VECTOR  // 0183H
#define Vector_DMA_SPI  DMA_SPI_VECTOR  // 018BH
#define Vector_DMA_UR1T DMA_UR1T_VECTOR // 0193H
#define Vector_DMA_UR1R DMA_UR1R_VECTOR // 019BH
#define Vector_DMA_UR2T DMA_UR2T_VECTOR // 01A3H
#define Vector_DMA_UR2R DMA_UR2R_VECTOR // 01ABH
#define Vector_DMA_UR3T DMA_UR3T_VECTOR // 01B3H
#define Vector_DMA_UR3R DMA_UR3R_VECTOR // 01BBH
#define Vector_DMA_UR4T DMA_UR4T_VECTOR // 01C3H
#define Vector_DMA_UR4R DMA_UR4R_VECTOR // 01CBH
#define Vector_DMA_LCM  DMA_LCM_VECTOR  // 01D3H
#define Vector_LCM      LCM_VECTOR      // 01DBH

#ifdef __SDCC
#define sl_isr_state(name, Vector_x) void name(void) __interrupt(Vector_x)
#define sl_isr_def(name, Vector_x)   void name(void) __interrupt(Vector_x)
#else
#define sl_isr_state(name, Vector_x) void name(void)
#define sl_isr_def(name, Vector_x) void name(void) interrupt Vector_x
#endif

#endif // !__SL_ISR_H__