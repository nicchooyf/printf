# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/08 12:38:03 by nchoo             #+#    #+#              #
#    Updated: 2022/07/08 16:13:36 by nchoo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a
CC			=	gcc
CLAGS		=	-Wall -Wextra -Werror
SRC_DIR		=	src/
SRC			=	
OBJ_DIR		=	obj/
OBJ			=	$(addprefix $(OBJ_DIR), $(addprefix $(SRC_DIR), SRC:.c=.o))
AR			=	ar rcs
RM			=	rm -f

all		:		$(NAME)

$(NAME)	:		$(OBJ)
				@make -C ./libft
				@cp libft/libft.a .
				@mv libft.a $(NAME)
				@$(AR) $(NAME) $(OBJ)

clean	:		$(RM) $(OBJS)

fclean	:		clean 
				$(RM) $(NAME)

re	:			fclean all

.PHONY	:		all clean fclean re
