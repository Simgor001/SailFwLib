/****************************************************************
 * @file    type.h
 * @author  Simgor001
 ****************************************************************/
#ifndef __SL_TYPE_H__
#define __SL_TYPE_H__

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned long uint32_t;

typedef char int8_t;
typedef short int16_t;
typedef long int32_t;

#ifdef __SDCC
#define bit __bit
#endif // __SDCC

#endif