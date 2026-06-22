/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakobaya <dakobaya@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 21:04:48 by dakobaya          #+#    #+#             */
/*   Updated: 2026/06/22 21:04:53 by dakobaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_print_char(va_list *args);
int	ft_print_str(va_list *args);
int	ft_print_ptr(va_list *args);
int	ft_print_int(va_list *args);
int	ft_print_uint(va_list *args);
int	ft_print_hex_lower(va_list *args);
int	ft_print_hex_upper(va_list *args);

#endif
