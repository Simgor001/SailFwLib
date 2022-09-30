#ifndef _SL_LOG_H_
#define _SL_LOG_H_
//五级日志
#define LOG_TRACE "T" //跟踪数据
#define LOG_DEBUG "D" //调试信息
#define LOG_INFO  "I" //运行消息
#define LOG_WARN  "W" //警告
#define LOG_ERROR "E" //错误

#ifdef SL_LOG
#include "sl_stdio.h"

//日志计数
static unsigned int _sl_log_count = 0;

#ifdef __SDCC
#define sl_log(LOG_x, msg, ...) printf(LOG_x "(%d):" msg "\r\n", _sl_log_count++, ##__VA_ARGS__)
#define sl_log_warn(msg, ...)   printf("W(%d):" msg "\r\n", _sl_log_count++, ##__VA_ARGS__)
#define sl_log_info(msg, ...)   printf("I(%d):" msg "\r\n", _sl_log_count++, ##__VA_ARGS__)
#else
#include <stdarg.h>
int sl_log(const char *LOG_x, const char *msg, ...);
int sl_log_warn(const char *msg, ...);
int sl_log_info(const char *msg, ...);
#endif

//关闭日志
#else
#ifdef __SDCC
#define sl_log_warn(x, msg, ...) 0
#define sl_log(msg, ...)         0
#define sl_log_info(msg, ...)
#else
int sl_log(const char *LOG_x, const char *msg, ...);
int sl_log_warn(const char *msg, ...);
int sl_log_info(const char *msg, ...);
#endif // __SDCC
#endif // SL_LOG
#endif // !_SL_LOG_H_