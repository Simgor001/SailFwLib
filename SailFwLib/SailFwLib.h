/****************************************************************
 * @file    SailFwLib.h
 * @author  Simgor001
 * --------------------------------------------------------------
 * The MIT License (MIT)
 *
 * Copyright © 2022 Simgor001
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 ****************************************************************/

#ifndef __SAILFWLIB_H__
#define __SAILFWLIB_H__

//芯片支持

#if defined(__SL_STC8H__)        // STC8H系列
#elif defined(__SL_STC89C5xRC__) // STC89C52RC
#elif defined(__SL_CH552__)      // CH552
#else
//未包含MCU头文件，或不支持该MCU型号
#error MCU information is not configured correctly!
#endif

#include "type.h"
#include "sys.h"
#include "gpio.h"
#include "isr.h"
#include "tim.h"
#endif
