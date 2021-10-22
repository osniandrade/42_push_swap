# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/18 20:22:39 by ocarlos-          #+#    #+#              #
#    Updated: 2021/10/21 23:12:06 by ocarlos-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRC_FILES = main.c
SRC = $(addprefix ./src/, $(SRC_FILES))
OBJ = $(SRC:.c=.o)
FLAG = -Wall -Wextra -Werror
DEBUG = -g -fsanitize=address
LIBFT = -L ./libft -lft
ARGS = 8 11

all:		$(NAME)

$(NAME):	$(OBJ) c_libft
			@gcc $(FLAG) $(DEBUG) $(SRC) $(LIBFT) -o push_swap

test:		all
			@./push_swap $(ARGS)

c_libft:
			make bonus -C ./libft

clean:
			make clean -C ./libft
			@/bin/rm -f $(OBJ)

fclean:		clean
			make fclean -C ./libft
			@/bin/rm -f $(NAME)

re:			fclean all