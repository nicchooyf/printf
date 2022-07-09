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
CFLAGS		=	-Wall -Wextra -Werror
SRC_DIR		=	src/
SRC			=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
SRC_FILES	=	ft_printchar
OBJ_DIR		=	obj/
OBJ			=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
AR			=	ar rcs
RM			=	rm

OBJF		=	.cache_exists

$(OBJF)	:
				mkdir -p $(OBJ_DIR)

all		:		$(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJF)
				$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

$(NAME)	:		$(OBJ)
				make -C ./libft
				cp libft/libft.a .
				mv libft.a $(NAME)
				$(AR) $(NAME) $(OBJ)

clean	:
				$(RM) -rf $(OBJ_DIR)
				make clean -C libft

fclean	:		clean 
				$(RM) -f $(NAME)
				$(RM) -f libft/libft.a

re	:			fclean all

.PHONY	:		all clean fclean re
