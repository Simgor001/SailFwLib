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

## SL_LOG：日志
日志分为5个等级：
| 标识      | 符号 | 描述     |
| --------- | ---- | -------- |
| LOG_TRACE | T    | 跟踪数据 |
| LOG_DEBUG | D    | 调试信息 |
| LOG_INFO  | I    | 运行消息 |
| LOG_WARN  | W    | 警告     |
| LOG_ERROR | E    | 错误     |

如果想启用日志功能，请在`sl_config.h`文件头部，添加宏`#define SL_LOG`。
:warning: 注意：该功能会占用串口1！

| 函数名      | 描述     |
| ----------- | -------- |
| sl_log      | 发送日志 |
| sl_log_warn | 发送警告 |
| sl_log_info | 发送消息 | 

## GPIO：输入输出引脚

| 函数名         | 描述             |
| -------------- | ---------------- |
| sl_gpio_init   | 初始化GPIO       | 
| sl_gpio_config | 配置GPIO高级功能 |
| sl_gpio_write  | GPIO输出电平     |
| sl_gpio_read   | GPIO读入电平     |
| sl_gpio_toggle | GPIO翻转电平     |

## ISR：中断
使用方式有别于Keil和SDCC，建议中断函数声明使用单独的头文件存储，中断函数定义用单独的C文件存储。

| 函数名           | 描述       |
| ---------------- | ---------- |
| sl_isr_enable    | 打开总中断 |
| sl_isr_disable   | 关闭总中断 |

### 中断函数
`sl_isr_state(name, IRQ_x)`
用于声明中断函数，name为中断函数名，IRQ_x是中断类型。
`sl_isr_def(name, IRQ_x)`
用于定义明中断函数，需要和声明保持一致，后面接大括号。
### 外部中断

| 函数名              | 描述           |
| ------------------- | -------------- |
| sl_isr_exti_init    | 初始化外部中断 |
| sl_isr_exti_enable  | 开启外部中断   |
| sl_isr_exti_disable | 关闭外部中断   | 

## TIM：定时器/计数器

| 函数名            | 描述                           |
| ----------------- | ------------------------------ |
| sl_tim_init       | 初始化定时器                   |
| sl_tim_config     | 配置定时器                     |
| sl_tim_gpio       | 设置定时器输出引脚（T3T4特供） |
| sl_tim_load_cycle | 按周期装载                     |
| sl_tim_load       | 按微秒装载                     |
| sl_tim_flag       | 检查溢出中断标志位             |
| sl_tim_reset_flag | 复位溢出中断标志位             |
| sl_tim_enable     | 开启定时器中断                 |
| sl_tim_disable    | 关闭定时器中断                 | 

## UART：串口
（未完善）

| 函数名              | 描述                 |
| ------------------- | -------------------- |
| sl_uart_init        | 初始化串口           |
| sl_uart_config      | 配置串口             |
| sl_uart_set_baud    | 设置串口波特率           |
| sl_uart_set_address | 设置多机通讯地址     |
| sl_uart_arrive      | 串口数据到达（阻塞） | 

# 正在适配的MCU
| 制造商 | 系列  | 型号      |
| ------ | ----- | --------- |
| STC    | STC8H | STC8H1K01 | 
