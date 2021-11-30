/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:18:59 by acroisie          #+#    #+#             */
/*   Updated: 2021/11/30 16:48:12 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

void	ft_putstr(char *str, int *count)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		ft_putstr("(null)", count);
		return ;
	}
	while (str[i])
	{
		ft_putchar(str[i], count);
		i++;
	}
}

void	ft_putnbr_base(int n, char *base, int *count)
{
	int			len;
	long int	nbr;

	nbr = n;
	len = ft_strlen(base);
	if (nbr < 0)
	{
		ft_putchar('-', count);
		nbr = nbr * -1;
	}
	if (nbr < len)
		ft_putchar(base[nbr], count);
	if (nbr >= len)
	{
		ft_putnbr_base((nbr / len), base, count);
		ft_putnbr_base((nbr % len), base, count);
	}
}

void	ft_putnbr_base_ul(unsigned long int nbr, char *base, int *count)
{
	unsigned int	len;

	len = ft_strlen(base);
	if (nbr < len)
		ft_putchar(base[nbr], count);
	if (nbr >= len)
	{
		ft_putnbr_base_ul((nbr / len), base, count);
		ft_putnbr_base_ul((nbr % len), base, count);
	}
}
