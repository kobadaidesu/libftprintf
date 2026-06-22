/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kobadai <kobadai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 00:01:33 by kobadai           #+#    #+#             */
/*   Updated: 2026/05/03 00:01:33 by kobadai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(va_list *args)
{
	char	c;

	c = va_arg(*args, int);
	write(1, &c, 1);
	return (1);
}

int	ft_print_str(va_list *args)
{
	int		i;
	char	*str;

	str = va_arg(*args, char *);
	if (!str)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	i = 0;
	while (str[i])
	{
		if (write(1, &str[i], 1) == -1)
			return (-1);
		i++;
	}
	return (i);
}

static int	write_uint(unsigned int n)
{
	int	len;
	int	ret;

	len = 0;
	if (n >= 10)
	{
		ret = write_uint(n / 10);
		if (ret == -1)
			return (-1);
		len += ret;
	}
	if (write(1, &"0123456789"[n % 10], 1) == -1)
		return (-1);
	return (len + 1);
}

int	ft_print_int(va_list *args)
{
	int	n;

	n = va_arg(*args, int);
	if (n < 0)
	{
		write(1, "-", 1);
		return (1 + write_uint((unsigned int)(-(long)n)));
	}
	return (write_uint((unsigned int)n));
}

int	ft_print_uint(va_list *args)
{
	return (write_uint(va_arg(*args, unsigned int)));
}
