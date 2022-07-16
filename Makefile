# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nchoo <nchoo@student.42kl.edu.my>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/08 12:38:03 by nchoo             #+#    #+#              #
#    Updated: 2022/07/16 18:29:15 by nchoo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libftprintf.a
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
SRC_FILES		=	ft_printstr.c ft_printf.c ft_printchar.c ft_check_flags.c ft_printptr.c ft_putnbr_base.c ft_putnbr.c ft_printint.c ft_printuint.c ft_printhex.c ft_width.c
SRC_DIR			=	src
SRC				=	$(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ_FILES		=	$(SRC_FILES:%.c=%.o)
OBJ_DIR			=	obj
OBJ				=	$(addprefix $(OBJ_DIR)/, $(OBJ_FILES))
AR				=	ar rcs
RM				=	rm -f
LIBFT			=	libft

all	:		$(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
				@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(BONUS_DIR)/&.c
				@$(CC) $(CFLAGS) -c $< -o $@
				
$(OBJ_DIR)	:
				@mkdir -p $(OBJ_DIR)

$(NAME)	:		$(OBJ)
				@make -C ./libft
				@cp libft/libft.a .
				@mv libft.a $(NAME)
				@$(AR) $(NAME) $(OBJ)

bonus	:		$(NAME)
				
clean	:		
				@$(RM) test.c				
				@$(RM) -rf $(OBJ_DIR)
				@make clean -C libft
				
fclean	:		clean
				@$(RM) -f $(NAME)
				@$(RM) -f libft/libft.a

re	:			fclean all

test	:		
				@gcc -Wall -Werror -Wextra -Ilifbt ft_printf.c ft_check_flags.c ft_printchar.c ft_printstr.c ft_printint.c ft_printptr.c -o test && ./test
				@$(RM) -f test

.PHONY	:		all clean fclean re
