# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/08 12:38:03 by nchoo             #+#    #+#              #
#    Updated: 2022/07/09 16:56:11 by nchoo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
SRC			=	ft_printstr.c ft_printf.c
OBJ			=	$(SRC:.c=.o)
AR			=	ar rcs
RM			=	rm -f

all	:		$(NAME)

.c.o :
				@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME)	:		$(OBJ)
				@make -C ./libft
				@cp libft/libft.a .
				@mv libft.a $(NAME)
				@$(AR) $(NAME) $(OBJ)

clean	:		
				@$(RM) $(OBJ)
				@make clean -C libft
				
fclean	:		clean 
				@$(RM) -f $(NAME)
				@$(RM) -f libft/libft.a

re	:			fclean all

.PHONY	:		all clean fclean re
