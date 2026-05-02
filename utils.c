#include "ft_printf.h"
#include "libft.h"

int ft_print_char(va_list *args)
{
    int c;

    c = va_arg(*args, int);
    write(1, &c, 1);
    return 1;
}

int ft_print_str(va_list *args)
{
    int i; 
    char *str;

    str = va_arg(*args, char *);
    i = 0;
    while(str[i])
    {
        write(1, &str[i], 1);
        i++ ;
    }
    return ft_strlen(str);
}

int print_hex(unsigned long long n, int cnt)
{
    int len;

    if(cnt == 16 || n == 0)
        return (0);
    len = print_hex(n >> 4, cnt + 1);
    write(1, &"0123456789abcdef"[0xf & n], 1);
    return (len + 1);
}

int ft_print_ptr(va_list *args)
{
    void               *str;
    unsigned long long  n;

    str = va_arg(*args, void *);
    n = (unsigned long long)str;
    if (n == 0)
    {
        write(1, "(nil)", 5);
        return (5);
    }
    write(1, "0x", 2);
    return (2 + print_hex(n, 0));
}
