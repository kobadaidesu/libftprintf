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
#include "libft.h"
#include <stdlib.h>

int	ft_print_char(va_list *args)
{
	int	c;

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
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (ft_strlen(str));
}

int	ft_print_int(va_list *args)
{
	int		n;
	char	*str;
	int		len;

	n = va_arg(*args, int);
	str = ft_itoa(n);
	len = ft_strlen(str);
	write(1, str, len);
	free(str);
	return (len);
}

static int	write_uint(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 10)
		len += write_uint(n / 10);
	write(1, &"0123456789"[n % 10], 1);
	return (len + 1);
}

int	ft_print_uint(va_list *args)
{
	return (write_uint(va_arg(*args, unsigned int)));
}
