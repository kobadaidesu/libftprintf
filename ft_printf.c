#include "ft_printf.h"

int handle_fmt(va_list *args, char fmt)
{
    switch(fmt)
    {
        case 'c': return (ft_print_char(args));
        case 's': return (ft_print_str(args));
        case 'p': return (ft_print_ptr(args));
        default: return (0);
    }
}

int ft_printf(const char *fmt, ...)
{
    va_list args;
    int     cnt;

    cnt = 0;
    va_start(args, fmt);
    while (*fmt)
    {
        if (*fmt == '%')
        {
            fmt++ ;
            cnt += handle_fmt(&args, *fmt);
        }
        else
        {
            write(1, fmt, 1);
            cnt++ ;
        }
        fmt++;
    }
    va_end(args);
    return (cnt);
}

int main(void)
{
    int a;
    int b;

    a = printf("%p", 0);
    b = ft_printf("%p", 0);
    printf("%d\n", a);
    printf("%d\n", b);
}