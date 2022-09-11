#include "sl_config.h"

sl_isr_state(Time0, Vector_TIM0);

sl_isr_def(Time0, Vector_TIM0)
{
    sl_gpio_toggle(GPIO_P1, GPIO_Pin_1);
}

void delay(uint16_t i)
{

    while (i--)
        ;
}
void main()
{
    gpio_config_t config;
    sl_sys_init();
    
    config.mode    = GPIO_Mode_Out_PP,
    config.pull_up = GPIO_Pull_up_Disable,
    config.smit    = GPIO_Smit_Disable,
    config.speed   = GPIO_Speed_Fast,
    config.driver  = GPIO_Driver_Plus,
    config.digit   = GPIO_Digit_Disable;

    sl_gpio_config(GPIO_P1, GPIO_Pin_1, config);

    TH0 = (65536 - 1000) / 256;
    TL0 = (65536 - 1000) % 256;

    TMOD = 0X01;
    TR0  = 1;

    EA  = 1;
    ET0 = 1;

    IT1 = 1;
    EX1 = 1;

    // while (1)
    // {
    //     sl_gpio_toggle(GPIO_P1, GPIO_Pin_1);
    //     delay(10);
    // }
    while (1)
    {
        /* code */
    }
}