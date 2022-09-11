# SailFwLib
一套51内核单片机的固件库，在尽可能不改动代码的情况下，兼容更多不同公司的MCU，同时支持SDCC或者Keil两种工具链。

 |                事项 | 信息                                                       |
 | -------------------:|:---------------------------------------------------------- |
 |     :warning:  警告 | 这个库还处于开发阶段，可以下载体验，但不要用于生产环境     |
 | :exclamation:  注意 | 因为使用这个库产生的问题，本人不承担任何责任，请酌情使用！ | 

# 代码风格
参考了STM32的HAL库、以及ESP32的固件库。

为了提高运行效率，绝大部分函数都由宏函数实现。

函数名以“sl_”开头，参数枚举前缀同参数名。
# API
采用模块化设计，为了兼容低端型号，配置函数分为init函数以及config函数。

init函数是基本的配置函数，主要确保低端型号的芯片能正常使用。

高端型号可能需要配置的寄存器更加多，这些配置使用config函数来完成，低端型号的芯片能自动屏蔽掉该函数，从而尽可能做到不改动代码，能在多款MCU上运行。如果不调用config函数，则使用上电默认值。
## GPIO

| 函数名         | 描述             |
| -------------- | ---------------- |
| sl_gpio_config | 配置GPIO引脚模式 |
| sl_gpio_write  | GPIO输出电平     |
| sl_gpio_read   | GPIO读入电平     |
| sl_gpio_toggle | GPIO翻转电平     |

# 正在适配的MCU
| 制造商 | 系列  | 型号      |
| ------ | ----- | --------- |
| STC    | STC8H | STC8H1K01 | 
