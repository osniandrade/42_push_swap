# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/18 20:22:39 by ocarlos-          #+#    #+#              #
#    Updated: 2021/05/23 11:34:41 by ocarlos-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRC = helper.c push_swap.c side1.c side2.c test.c
OBJ = $(SRC:.s=.o)
FLAG = -Wall -Wextra -Werror
DEBUG = -g -fsanitize=address
ARGS = 1 3 4 8 6 9

all:		$(NAME)

$(NAME):	$(OBJ)
			@gcc $(FLAG) $(SRC) -o push_swap

test:
			@gcc $(DEBUG) $(SRC) -o push_swap
			@./push_swap $(ARGS)

clean:
			@/bin/rm -f $(OBJ)

fclean:		clean
			@/bin/rm -f $(NAME)

re:			fclean all