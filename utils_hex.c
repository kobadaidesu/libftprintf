/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kobadai <kobadai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 00:01:33 by kobadai           #+#    #+#             */
/*   Updated: 2026/05/03 00:01:33 by kobadai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	write_hex(unsigned long long n, const char *base)
{
	int	len;

	len = 0;
	if (n >= 16)
		len += write_hex(n >> 4, base);
	write(1, &base[n & 0xf], 1);
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

	ptr = va_arg(*args, void *);
	n = (unsigned long long)ptr;
	if (n == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	return (2 + write_hex(n, "0123456789abcdef"));
}
