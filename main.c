/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:20:46 by acroisie          #+#    #+#             */
/*   Updated: 2021/11/30 13:55:51 by acroisie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
# include <stdio.h> //A supp

int	main(void)
{
	int		ret_ft_printf;
	int		ret_printf;
	char	one_letter;
	char	*word;
	int		test_int;

	one_letter = 't';
	word = "test";
	test_int = 56565;
	dprintf(1, "\033[1;36mft_printf :\033[0m\n");
	ret_ft_printf = ft_printf("%%%c --- %s --- %p --- %i", one_letter, word, word, test_int);
	dprintf(1, "\nret = %d\n", ret_ft_printf);
	dprintf(1, "\033[1;33mprintf :\033[0m\n");
	ret_printf = dprintf(1, "%%%c --- %s --- %p --- %i", one_letter, word, word, test_int);
	dprintf(1, "\nret = %d\n", ret_printf);
	return (0);
}
