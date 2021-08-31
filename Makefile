# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/18 20:22:39 by ocarlos-          #+#    #+#              #
#    Updated: 2021/05/26 11:52:22 by ocarlos-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRC = helper.c push_swap.c side1.c side2.c test.c flow1.c
OBJ = $(SRC:.s=.o)
FLAG = -Wall -Wextra -Werror
DEBUG = -g -fsanitize=address
ARGS = 8 3
#ARGS = 2 8 5
#ARGS = 43 2 9 4 5
#ARGS = 8 9 11 17

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