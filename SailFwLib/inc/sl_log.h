#ifndef _SL_LOG_H_
#define _SL_LOG_H_
#ifdef SL_LOG
#include "sl_stdio.h"
//五级日志

#define LOG_TRACE "T" //跟踪数据
#define LOG_DEBUG "D" //调试信息
#define LOG_INFO  "I" //运行消息
#define LOG_WARN  "W" //警告
#define LOG_ERROR "E" //错误

//日志计数
static unsigned int _sl_log_count = 0;

#define sl_log(LOG_x, msg) printf(LOG_x "(%d):" msg, _sl_log_count++)
#define sl_log_warn(x, msg) \
    if (x) printf("W(%d):" msg, _sl_log_count++)
#else
#define sl_log_warn(x, msg) ;
#define sl_log(LOG_x, msg)  ;
#endif // SL_LOG
#endif // !_SL_LOG_H_