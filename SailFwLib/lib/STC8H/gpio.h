#ifndef __SL_GPIO_H__
#define __SL_GPIO_H__
#include "type.h"
#include "sl_config.h"

#define GPIO_P0              P0 /* P0端口*/
#define GPIO_P1              P1 /* P1端口*/
#define GPIO_P2              P2 /* P2端口*/
#define GPIO_P3              P3 /* P3端口*/
#define GPIO_P4              P4 /* P4端口*/
#define GPIO_P5              P5 /* P5端口*/
#define GPIO_P6              P6 /* P6端口*/
#define GPIO_P7              P7 /* P7端口*/

#define GPIO_Pin_0           0 /*引脚 0*/
#define GPIO_Pin_1           1 /*引脚 1*/
#define GPIO_Pin_2           2 /*引脚 2*/
#define GPIO_Pin_3           3 /*引脚 3*/
#define GPIO_Pin_4           4 /*引脚 4*/
#define GPIO_Pin_5           5 /*引脚 5*/
#define GPIO_Pin_6           6 /*引脚 6*/
#define GPIO_Pin_7           7 /*引脚 7*/
#define GPIO_Pin_All         8 /*所有引脚*/

#define _GPIO_Pin_0_Mask     0x01 /*引脚 0掩码*/
#define _GPIO_Pin_1_Mask     0x02 /*引脚 1掩码*/
#define _GPIO_Pin_2_Mask     0x04 /*引脚 2掩码*/
#define _GPIO_Pin_3_Mask     0x08 /*引脚 3掩码*/
#define _GPIO_Pin_4_Mask     0x10 /*引脚 4掩码*/
#define _GPIO_Pin_5_Mask     0x20 /*引脚 5掩码*/
#define _GPIO_Pin_6_Mask     0x40 /*引脚 6掩码*/
#define _GPIO_Pin_7_Mask     0x80 /*引脚 7掩码*/
#define _GPIO_Pin_All_Mask   0xFF /*所有引脚掩码*/

#define _GPIO_P0_GPIO_Pin_0  P00 /* P0.0引脚位号*/
#define _GPIO_P0_GPIO_Pin_1  P01 /* P0.1引脚位号*/
#define _GPIO_P0_GPIO_Pin_2  P02 /* P0.2引脚位号*/
#define _GPIO_P0_GPIO_Pin_3  P03 /* P0.3引脚位号*/
#define _GPIO_P0_GPIO_Pin_4  P04 /* P0.4引脚位号*/
#define _GPIO_P0_GPIO_Pin_5  P05 /* P0.5引脚位号*/
#define _GPIO_P0_GPIO_Pin_6  P06 /* P0.6引脚位号*/
#define _GPIO_P0_GPIO_Pin_7  P07 /* P0.7引脚位号*/

#define _GPIO_P1_GPIO_Pin_0  P10 /* P1.0引脚位号*/
#define _GPIO_P1_GPIO_Pin_1  P11 /* P1.1引脚位号*/
#define _GPIO_P1_GPIO_Pin_2  P12 /* P1.2引脚位号*/
#define _GPIO_P1_GPIO_Pin_3  P13 /* P1.3引脚位号*/
#define _GPIO_P1_GPIO_Pin_4  P14 /* P1.4引脚位号*/
#define _GPIO_P1_GPIO_Pin_5  P15 /* P1.5引脚位号*/
#define _GPIO_P1_GPIO_Pin_6  P16 /* P1.6引脚位号*/
#define _GPIO_P1_GPIO_Pin_7  P17 /* P1.7引脚位号*/

#define _GPIO_P2_GPIO_Pin_0  P20 /* P2.0引脚位号*/
#define _GPIO_P2_GPIO_Pin_1  P21 /* P2.1引脚位号*/
#define _GPIO_P2_GPIO_Pin_2  P22 /* P2.2引脚位号*/
#define _GPIO_P2_GPIO_Pin_3  P23 /* P2.3引脚位号*/
#define _GPIO_P2_GPIO_Pin_4  P24 /* P2.4引脚位号*/
#define _GPIO_P2_GPIO_Pin_5  P25 /* P2.5引脚位号*/
#define _GPIO_P2_GPIO_Pin_6  P26 /* P2.6引脚位号*/
#define _GPIO_P2_GPIO_Pin_7  P27 /* P2.7引脚位号*/

#define _GPIO_P3_GPIO_Pin_0  P30 /* P3.0引脚位号*/
#define _GPIO_P3_GPIO_Pin_1  P31 /* P3.1引脚位号*/
#define _GPIO_P3_GPIO_Pin_2  P32 /* P3.2引脚位号*/
#define _GPIO_P3_GPIO_Pin_3  P33 /* P3.3引脚位号*/
#define _GPIO_P3_GPIO_Pin_4  P34 /* P3.4引脚位号*/
#define _GPIO_P3_GPIO_Pin_5  P35 /* P3.5引脚位号*/
#define _GPIO_P3_GPIO_Pin_6  P36 /* P3.6引脚位号*/
#define _GPIO_P3_GPIO_Pin_7  P37 /* P3.7引脚位号*/

#define _GPIO_P4_GPIO_Pin_0  P40 /* P4.0引脚位号*/
#define _GPIO_P4_GPIO_Pin_1  P41 /* P4.1引脚位号*/
#define _GPIO_P4_GPIO_Pin_2  P42 /* P4.2引脚位号*/
#define _GPIO_P4_GPIO_Pin_3  P43 /* P4.3引脚位号*/
#define _GPIO_P4_GPIO_Pin_4  P44 /* P4.4引脚位号*/
#define _GPIO_P4_GPIO_Pin_5  P45 /* P4.5引脚位号*/
#define _GPIO_P4_GPIO_Pin_6  P46 /* P4.6引脚位号*/
#define _GPIO_P4_GPIO_Pin_7  P47 /* P4.7引脚位号*/

#define _GPIO_P5_GPIO_Pin_0  P50 /* P5.0引脚位号*/
#define _GPIO_P5_GPIO_Pin_1  P51 /* P5.1引脚位号*/
#define _GPIO_P5_GPIO_Pin_2  P52 /* P5.2引脚位号*/
#define _GPIO_P5_GPIO_Pin_3  P53 /* P5.3引脚位号*/
#define _GPIO_P5_GPIO_Pin_4  P54 /* P5.4引脚位号*/
#define _GPIO_P5_GPIO_Pin_5  P55 /* P5.5引脚位号*/
#define _GPIO_P5_GPIO_Pin_6  P56 /* P5.6引脚位号*/
#define _GPIO_P5_GPIO_Pin_7  P57 /* P5.7引脚位号*/

#define _GPIO_P6_GPIO_Pin_0  P60 /* P6.0引脚位号*/
#define _GPIO_P6_GPIO_Pin_1  P61 /* P6.1引脚位号*/
#define _GPIO_P6_GPIO_Pin_2  P62 /* P6.2引脚位号*/
#define _GPIO_P6_GPIO_Pin_3  P63 /* P6.3引脚位号*/
#define _GPIO_P6_GPIO_Pin_4  P64 /* P6.4引脚位号*/
#define _GPIO_P6_GPIO_Pin_5  P65 /* P6.5引脚位号*/
#define _GPIO_P6_GPIO_Pin_6  P66 /* P6.6引脚位号*/
#define _GPIO_P6_GPIO_Pin_7  P67 /* P6.7引脚位号*/

#define _GPIO_P7_GPIO_Pin_0  P70 /* P7.0引脚位号*/
#define _GPIO_P7_GPIO_Pin_1  P71 /* P7.1引脚位号*/
#define _GPIO_P7_GPIO_Pin_2  P72 /* P7.2引脚位号*/
#define _GPIO_P7_GPIO_Pin_3  P73 /* P7.3引脚位号*/
#define _GPIO_P7_GPIO_Pin_4  P74 /* P7.4引脚位号*/
#define _GPIO_P7_GPIO_Pin_5  P75 /* P7.5引脚位号*/
#define _GPIO_P7_GPIO_Pin_6  P76 /* P7.6引脚位号*/
#define _GPIO_P7_GPIO_Pin_7  P77 /* P7.7引脚位号*/

#define GPIO_P0M0            P0M0 /* P0端口模式寄存器0*/
#define GPIO_P1M0            P1M0 /* P1端口模式寄存器0*/
#define GPIO_P2M0            P2M0 /* P2端口模式寄存器0*/
#define GPIO_P3M0            P3M0 /* P3端口模式寄存器0*/
#define GPIO_P4M0            P4M0 /* P4端口模式寄存器0*/
#define GPIO_P5M0            P5M0 /* P5端口模式寄存器0*/
#define GPIO_P6M0            P6M0 /* P6端口模式寄存器0*/
#define GPIO_P7M0            P7M0 /* P7端口模式寄存器0*/

#define GPIO_P0M1            P0M1 /* P0端口模式寄存器1*/
#define GPIO_P1M1            P1M1 /* P1端口模式寄存器1*/
#define GPIO_P2M1            P2M1 /* P2端口模式寄存器1*/
#define GPIO_P3M1            P3M1 /* P3端口模式寄存器1*/
#define GPIO_P4M1            P4M1 /* P4端口模式寄存器1*/
#define GPIO_P5M1            P5M1 /* P5端口模式寄存器1*/
#define GPIO_P6M1            P6M1 /* P6端口模式寄存器1*/
#define GPIO_P7M1            P7M1 /* P7端口模式寄存器1*/

#define GPIO_P0PU            P0PU /* P0端口上拉电阻控制寄存器*/
#define GPIO_P1PU            P1PU /* P1端口上拉电阻控制寄存器*/
#define GPIO_P2PU            P2PU /* P2端口上拉电阻控制寄存器*/
#define GPIO_P3PU            P3PU /* P3端口上拉电阻控制寄存器*/
#define GPIO_P4PU            P4PU /* P4端口上拉电阻控制寄存器*/
#define GPIO_P5PU            P5PU /* P5端口上拉电阻控制寄存器*/
#define GPIO_P6PU            P6PU /* P6端口上拉电阻控制寄存器*/
#define GPIO_P7PU            P7PU /* P7端口上拉电阻控制寄存器*/

#define GPIO_P0NCS           P0NCS /* P0端口施密特触发控制寄存器*/
#define GPIO_P1NCS           P1NCS /* P1端口施密特触发控制寄存器*/
#define GPIO_P2NCS           P2NCS /* P2端口施密特触发控制寄存器*/
#define GPIO_P3NCS           P3NCS /* P3端口施密特触发控制寄存器*/
#define GPIO_P4NCS           P4NCS /* P4端口施密特触发控制寄存器*/
#define GPIO_P5NCS           P5NCS /* P5端口施密特触发控制寄存器*/
#define GPIO_P6NCS           P6NCS /* P6端口施密特触发控制寄存器*/
#define GPIO_P7NCS           P7NCS /* P7端口施密特触发控制寄存器*/

#define GPIO_P0SR            P0SR /* P0端口电平转换速度控制寄存器*/
#define GPIO_P1SR            P1SR /* P1端口电平转换速度控制寄存器*/
#define GPIO_P2SR            P2SR /* P2端口电平转换速度控制寄存器*/
#define GPIO_P3SR            P3SR /* P3端口电平转换速度控制寄存器*/
#define GPIO_P4SR            P4SR /* P4端口电平转换速度控制寄存器*/
#define GPIO_P5SR            P5SR /* P5端口电平转换速度控制寄存器*/
#define GPIO_P6SR            P6SR /* P6端口电平转换速度控制寄存器*/
#define GPIO_P7SR            P7SR /* P7端口电平转换速度控制寄存器*/

#define GPIO_P0DR            P0DR /* P0端口驱动电流控制寄存器*/
#define GPIO_P1DR            P1DR /* P1端口驱动电流控制寄存器*/
#define GPIO_P2DR            P2DR /* P2端口驱动电流控制寄存器*/
#define GPIO_P3DR            P3DR /* P3端口驱动电流控制寄存器*/
#define GPIO_P4DR            P4DR /* P4端口驱动电流控制寄存器*/
#define GPIO_P5DR            P5DR /* P5端口驱动电流控制寄存器*/
#define GPIO_P6DR            P6DR /* P6端口驱动电流控制寄存器*/
#define GPIO_P7DR            P7DR /* P7端口驱动电流控制寄存器*/

#define GPIO_P0IE            P0IE /* P0端口数字信号输入使能寄存器*/
#define GPIO_P1IE            P1IE /* P1端口数字信号输入使能寄存器*/
#define GPIO_P2IE            P2IE /* P2端口数字信号输入使能寄存器*/
#define GPIO_P3IE            P3IE /* P3端口数字信号输入使能寄存器*/
#define GPIO_P4IE            P4IE /* P4端口数字信号输入使能寄存器*/
#define GPIO_P5IE            P5IE /* P5端口数字信号输入使能寄存器*/
#define GPIO_P6IE            P6IE /* P6端口数字信号输入使能寄存器*/
#define GPIO_P7IE            P7IE /* P7端口数字信号输入使能寄存器*/

#define GPIO_Mode_Pull_up    0x00 /*准双向口*/
#define GPIO_Mode_Out_PP     0x01 /*推挽输出*/
#define GPIO_Mode_In         0x02 /*高阻输入*/
#define GPIO_Mode_Out_OD     0x03 /*开漏输出*/

#define GPIO_Pull_up_Disable 0 /* GPIO禁用4.1k上拉电阻*/
#define GPIO_Pull_up_Enable  1 /* GPIO启用4.1k上拉电阻*/

#define GPIO_Smit_Disable    0 /* GPIO禁用施密特触发功能*/
#define GPIO_Smit_Enable     1 /* GPIO启用施密特触发功能*/

#define GPIO_Speed_Fast      0 /* GPIO电平快速转换*/
#define GPIO_Speed_Slow      1 /* GPIO电平慢速转换*/

#define GPIO_Driver_Plus     0 /* GPIO增强驱动能力*/
#define GPIO_Driver_Normal   1 /* GPIO一般驱动能力*/

#define GPIO_Digit_Disable   0 /* GPIO禁用数字型号输入功能*/
#define GPIO_Digit_Enable    1 /* GPIO启用数字型号输入功能*/
typedef struct _gpio_config_s
{
    uint8_t pull_up; //上拉
    uint8_t smit;    //施密特触发器
    uint8_t speed;   //速度
    uint8_t driver;  //驱动能力
    uint8_t digit;   //数字信号输入使能
} gpio_config_t;

/**
 * @brief 初始化GPIO
 *
 * @param GPIO_Px 端口x：0~7
 * @param GPIO_Pin_x 引脚号x：0~7
 * @param gpio_config 配置结构
 */
#define sl_gpio_init(GPIO_Px, GPIO_Pin_x, GPIO_Mode_x)     \
    {                                                      \
        GPIO_Px##M0 &= ~_##GPIO_Pin_x##_Mask;              \
        GPIO_Px##M1 &= ~_##GPIO_Pin_x##_Mask;              \
                                                           \
        GPIO_Px##M0 |= (GPIO_Mode_x & 0x01) << GPIO_Pin_x; \
        GPIO_Px##M1 |= (GPIO_Mode_x & 0x02) << GPIO_Pin_x; \
    }
/**
 * @brief 配置GPIO
 *
 * @param GPIO_Px 端口x：0~7
 * @param GPIO_Pin_x 引脚号x：0~7
 * @param gpio_config 配置结构
 */
#define sl_gpio_config(GPIO_Px, GPIO_Pin_x, gpio_config)  \
    {                                                     \
        GPIO_Px##PU &= ~_##GPIO_Pin_x##_Mask;             \
        GPIO_Px##NCS &= ~_##GPIO_Pin_x##_Mask;            \
        GPIO_Px##SR &= ~_##GPIO_Pin_x##_Mask;             \
        GPIO_Px##DR &= ~_##GPIO_Pin_x##_Mask;             \
        GPIO_Px##IE &= ~_##GPIO_Pin_x##_Mask;             \
                                                          \
        GPIO_Px##PU |= gpio_config.pull_up << GPIO_Pin_x; \
        GPIO_Px##NCS |= gpio_config.smit << GPIO_Pin_x;   \
        GPIO_Px##SR |= gpio_config.speed << GPIO_Pin_x;   \
        GPIO_Px##DR |= gpio_config.driver << GPIO_Pin_x;  \
        GPIO_Px##IE |= gpio_config.digit << GPIO_Pin_x;   \
    }

/**
 * @brief GPIO输出电平
 *
 * @param GPIO_Px 端口x：0~7
 * @param GPIO_Pin_x 引脚号x：0~7
 * @param lever 电平，HIGH：高电平，LOW：低电平
 */
#define sl_gpio_write(GPIO_Px, GPIO_Pin_x, lever) (_##GPIO_Px##_##GPIO_Pin_x = lever)

/**
 * @brief GPIO翻转电平
 *
 * @param GPIO_Px 端口x：0~7
 * @param GPIO_Pin_x 引脚号x：0~7
 */
#define sl_gpio_toggle(GPIO_Px, GPIO_Pin_x) (_##GPIO_Px##_##GPIO_Pin_x = !_##GPIO_Px##_##GPIO_Pin_x)

/**
 * @brief GPIO读取电平
 *
 * @param GPIO_Px 端口x：0~7
 * @param GPIO_Pin_x 引脚号x：0~7
 */
#define sl_gpio_read(GPIO_Px, GPIO_Pin_x) (_##GPIO_Px##_##GPIO_Pin_x)

#endif // !__SL_GPIO_H__