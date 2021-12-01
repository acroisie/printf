/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:23:44 by acroisie          #+#    #+#             */
/*   Updated: 2021/12/01 10:59:43 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	char_is_format_id(char c)
{
	if (c == '%')
		return (1);
	return (0);
}

static int	ft_print_format(va_list argptr, char format_id, int *count)
{
	if (format_id == '%')
		ft_putchar('%', count);
	else if (format_id == 'c')
		ft_putchar(va_arg(argptr, int), count);
	else if (format_id == 's')
		ft_putstr(va_arg(argptr, char *), count);
	else if (format_id == 'p')
	{
		ft_putstr("0x", count);
		ft_putnbr_base_ul(va_arg(argptr, unsigned long int),
			"0123456789abcdef", count);
	}
	else if (format_id == 'd' || format_id == 'i')
		ft_putnbr_base(va_arg(argptr, int),
			"0123456789", count);
	else if (format_id == 'u')
		ft_putnbr_base_ul(va_arg(argptr, unsigned int),
			"0123456789", count);
	else if (format_id == 'x')
		ft_putnbr_base_ul(va_arg(argptr, unsigned int),
			"0123456789abcdef", count);
	else if (format_id == 'X')
		ft_putnbr_base_ul(va_arg(argptr, unsigned int),
			"0123456789ABCDEF", count);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	int		i;
	va_list	argptr;

	va_start(argptr, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (char_is_format_id(format[i]))
		{
			i++;
			ft_print_format(argptr, format[i++], &count);
		}
		else
			ft_putchar(format[i++], &count);
	}
	va_end(argptr);
	return (count);
}
