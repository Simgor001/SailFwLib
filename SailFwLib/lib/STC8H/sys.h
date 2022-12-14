/****************************************************************
 * @file    sys.h
 * @author  Simgor001
 ****************************************************************/
#ifndef __SL_SYS_H__
#define __SL_SYS_H__
#include "sl_type.h"
#include "sl_config.h"


/**
 * @brief 初始化系统
 */
void sl_sys_init();

void sl_delay(uint32_t ms);
void sl_delay_us(uint16_t us);

//进入掉电模式
#define sl_power_down() PCON |= 0x02
//进入睡眠（空闲）模式
#define sl_power_sleep() PCON |= 0x01
#endif