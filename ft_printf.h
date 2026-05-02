#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int	ft_printf(const char *format, ...);
int	ft_print_char(va_list *args);
int	ft_print_str(va_list *args);
int	ft_print_ptr(va_list *args);

#endif
