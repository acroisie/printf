/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:23:44 by acroisie          #+#    #+#             */
/*   Updated: 2021/11/29 18:35:39 by acroisie         ###   ########lyon.fr   */
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
		return (0);
	if (format_id == 'c')
		ft_putchar(va_arg(argptr, int), count);
	if (format_id == 's')
		ft_putstr(va_arg(argptr, char *), count);
	if (format_id == 'p')
		ft_putstr(va_arg(argptr, char *), count);
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
	return (count);
}
