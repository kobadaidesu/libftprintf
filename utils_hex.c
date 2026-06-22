/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakobaya <dakobaya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 21:04:39 by dakobaya          #+#    #+#             */
/*   Updated: 2026/06/22 21:04:46 by dakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	write_hex(unsigned long long n, const char *base)
{
	int	len;
	int	ret;

	len = 0;
	if (n >= 16)
	{
		ret = write_hex(n >> 4, base);
		if (ret == -1)
			return (-1);
		len += ret;
	}
	if (write(1, &base[n & 0xf], 1) == -1)
		return (-1);
	return (len + 1);
}

int	ft_print_hex_lower(va_list *args)
{
	return (write_hex(va_arg(*args, unsigned int), "0123456789abcdef"));
}

int	ft_print_hex_upper(va_list *args)
{
	return (write_hex(va_arg(*args, unsigned int), "0123456789ABCDEF"));
}

int	ft_print_ptr(va_list *args)
{
	void				*ptr;
	unsigned long long	n;
	int					ret;

	ptr = va_arg(*args, void *);
	n = (unsigned long long)ptr;
	if (n == 0)
	{
		if (write(1, "(nil)", 5) == -1)
			return (-1);
		return (5);
	}
	if (write(1, "0x", 2) == -1)
		return (-1);
	ret = write_hex(n, "0123456789abcdef");
	if (ret == -1)
		return (-1);
	return (2 + ret);
}
