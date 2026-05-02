/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kobadai <kobadai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 00:01:33 by kobadai           #+#    #+#             */
/*   Updated: 2026/05/03 00:04:50 by kobadai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_fmt(va_list *args, char fmt)
{
	if (fmt == 'c')
		return (ft_print_char(args));
	if (fmt == 's')
		return (ft_print_str(args));
	if (fmt == 'p')
		return (ft_print_ptr(args));
	if (fmt == 'd' || fmt == 'i')
		return (ft_print_int(args));
	if (fmt == 'u')
		return (ft_print_uint(args));
	if (fmt == 'x')
		return (ft_print_hex_lower(args));
	if (fmt == 'X')
		return (ft_print_hex_upper(args));
	if (fmt == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		cnt;

	cnt = 0;
	va_start(args, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			cnt += handle_fmt(&args, *fmt);
		}
		else
		{
			write(1, fmt, 1);
			cnt++;
		}
		fmt++;
	}
	va_end(args);
	return (cnt);
}

// int main(void)
// {
//     int a;
//     int b;

//     a = printf("%p", 0);
//     b = ft_printf("%p", 0);
//     printf("%d\n", a);
//     printf("%d\n", b);
// }