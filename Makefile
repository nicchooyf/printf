# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/08 12:38:03 by nchoo             #+#    #+#              #
#    Updated: 2022/07/14 22:22:53 by nchoo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
SRC			=	ft_printstr.c ft_printf.c ft_putchar.c ft_check_flags.c
OBJ			=	$(SRC:.c=.o)
AR			=	ar rcs
RM			=	rm -f
LIBFT		=	libft

all	:		$(NAME)

.c.o :
				@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME)	:		$(OBJ)
				@make -C ./libft
				@cp libft/libft.a .
				@mv libft.a $(NAME)
				@$(AR) $(NAME) $(OBJ)

clean	:		
				@$(RM) test.c				
				@$(RM) $(OBJ)
				@make clean -C libft
				
fclean	:		clean
				@$(RM) -f $(NAME)
				@$(RM) -f libft/libft.a

re	:			fclean all

test	:		
				@gcc -Wall -Werror -Wextra -Ilifbt ft_printf.c ft_check_flags.c ft_putchar.c ft_printstr.c -o test && ./test
				@$(RM) -f test

.PHONY	:		all clean fclean re
