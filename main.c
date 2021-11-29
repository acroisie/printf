/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:20:46 by acroisie          #+#    #+#             */
/*   Updated: 2021/11/29 18:33:05 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...);

int	main(void)
{
	int		ret_ft_printf;
	int		ret_printf;
	char	one_letter;
	char	*word;

	one_letter = 't';
	word = "test";
	dprintf(1, "\033[1;36mft_printf :\033[0m\n");
	ret_ft_printf = ft_printf("%c --- %s --- %p", one_letter, word);
	dprintf(1, "\nret = %d\n", ret_ft_printf);
	dprintf(1, "\033[1;33mprintf :\033[0m\n");
	ret_printf = dprintf(1, "%c --- %s --- %p", one_letter, word, word);
	dprintf(1, "\nret = %d\n", ret_printf);
}
