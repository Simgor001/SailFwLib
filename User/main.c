#include "sl_config.h"

sl_isr_state(Time0, IRQ_TIM0);

sl_isr_def(Time0, IRQ_TIM0)
{
    sl_gpio_toggle(GPIO_P1,GPIO_Pin_1);
}

void delay(uint16_t i)
{
    while (i--)
        ;
}
void main()
{
    gpio_config_t config;
    config.speed = GPIO_Speed_Fast;
    config.driver = GPIO_Driver_Plus;

    sl_sys_init();

    sl_gpio_init(GPIO_P1, GPIO_Pin_1, GPIO_Mode_Out_PP);

    sl_gpio_config(GPIO_P1,GPIO_Pin_2,config)

    sl_tim_init(TIM_0,GATE_Disable,CT_Timer,TIM_Mode_16_Auto);

    // sl_tim_load(TIM_0,10);
    TH0 = (65536 - 10) / 256;
    TL0 = (65536 - 10) % 256;
    // sl_tim_enable(TIM_0);
    TR0 = 1;

    EA  = 1;
    ET0 = 1;


        while (1)
    {
        /* code */
    }
}