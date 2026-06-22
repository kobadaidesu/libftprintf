/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakobaya <dakobaya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 00:01:33 by kobadai           #+#    #+#             */
/*   Updated: 2026/06/22 22:37:51 by dakobaya         ###   ########.fr       */
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
		if (write(1, "%", 1) == -1)
			return (-1);
		return (1);
	}
	return (0);
}

static int	print_next(const char **fmt, va_list *args)
{
	int	ret;

	if (**fmt == '%')
	{
		(*fmt)++;
		ret = handle_fmt(args, **fmt);
		if (ret == -1)
			return (-1);
		return (ret);
	}
	if (write(1, *fmt, 1) == -1)
		return (-1);
	return (1);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		cnt;
	int		ret;

	cnt = 0;
	va_start(args, fmt);
	while (*fmt)
	{
		ret = print_next(&fmt, &args);
		if (ret == -1)
		{
			va_end(args);
			return (-1);
		}
		cnt += ret;
		fmt++;
	}
	va_end(args);
	return (cnt);
}

#include <stdio.h>

int	main(void)
{
	ft_printf("%s", NULL);
}
