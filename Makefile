# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acroisie <acroisie@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/30 13:54:09 by acroisie          #+#    #+#              #
#    Updated: 2021/12/01 11:31:42 by acroisie         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME 		= libftprintf.a
CC 			= gcc 
CC_FLAGS 	= -Wall -Wextra -Werror
SRCS 		= ft_printf.c \
				ft_printf_utils.c
OBJS 		= $(SRCS:.c=.o)
HEADER  	= ft_printf.h

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o : %.c $(HEADER)
	$(CC) $(CC_FLAGS) -c $< -o $@
	
clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all, clean, fclean