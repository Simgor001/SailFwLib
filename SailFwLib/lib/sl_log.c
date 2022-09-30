#include "sl_config.h"
#ifndef __SDCC
#ifdef SL_LOG

int sl_log(const char *LOG_x, const char *msg, ...)
{
    va_list arg_ptr;
    va_start(arg_ptr, msg);
    printf("%s(%d):", LOG_x, _sl_log_count++);
    vprintf(msg, arg_ptr);
    va_end(arg_ptr);
    return 0;
}
int sl_log_warn(const char *msg, ...)
{
    va_list arg_ptr;
    va_start(arg_ptr, msg);
    printf("W(%d):", _sl_log_count++);
    vprintf(msg, arg_ptr);
    va_end(arg_ptr);
    return 0;
}
int sl_log_info(const char *msg, ...)
{
    va_list arg_ptr;
    va_start(arg_ptr, msg);
    printf("I(%d):", _sl_log_count++);
    vprintf(msg, arg_ptr);
    va_end(arg_ptr);
    return 0;
}
#else
int sl_log(const char *LOG_x, const char *msg, ...)
{
    va_list arg_ptr;
    va_start(arg_ptr, msg);
    va_end(arg_ptr);
    return 0;
}
int sl_log_warn(const char *msg, ...)
{
    va_list arg_ptr;
    va_start(arg_ptr, msg);
    va_end(arg_ptr);
    return 0;
}
int sl_log_info(const char *msg, ...)
{
    va_list arg_ptr;
    va_start(arg_ptr, msg);
    va_end(arg_ptr);
    return 0;
}
#endif // SL_LOG
#endif // !__SDCC