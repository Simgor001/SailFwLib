#include "sl_config.h"
//声明中断服务
// sl_isr_state(Time0, IRQ_TIM0);

// //定义中断服务
// sl_isr_def(Time0, IRQ_TIM0)
// {
//     //翻转电平
//     sl_gpio_toggle(GPIO_P3, GPIO_Pin_2);
// }

void main()
{
    //初始化系统
    sl_sys_init();

    //初始化GPIO
    sl_gpio_init(GPIO_P3, GPIO_Pin_2, GPIO_Mode_Out_PP);

    sl_gpio_init(GPIO_P3, GPIO_Pin_5, GPIO_Mode_Out_PP);
    //初始化定时器
    sl_tim_init(TIM_3, GATE_Disable, CT_Timer, TIM_Mode_16_Auto, TIM_Isr_Enable);



    // sl_tim_config(TIM_0, TIM_Speed_1T, TIM_Clk_Out_Enable);

    // sl_tim_load(TIM_0, 1000);

    // sl_tim_enable(TIM_0);

    while (1)
    {
        sl_gpio_toggle(GPIO_P3, GPIO_Pin_5);
        sl_delay(100);
        printf("Hello\r\n");
        NOP();
    }
}
