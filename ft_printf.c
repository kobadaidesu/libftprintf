#include "ft_printf.h"

int ft_printf(const char *fmt, ...)
{
    va_list ap;
    int     cnt;

    cnt = 0;
    va_start(ap, fmt);
    while (*fmt)
    {
        if (*fmt == '%')
        {
            fmt++ ;
           cnt += handle_fmt(ap, fmt);
        }
        else
        {
            write(1, fmt, 1);
            cnt++ ;
        }
        fmt++;
    }
    va_end(ap);
    return (cnt);
}