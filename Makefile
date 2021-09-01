# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/18 20:22:39 by ocarlos-          #+#    #+#              #
#    Updated: 2021/09/01 23:19:51 by ocarlos-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRC = helper.c push_swap.c side1.c side2.c test.c flow1.c cases1.c
OBJ = $(SRC:.s=.o)
FLAG = -Wall -Wextra -Werror
DEBUG = -g -fsanitize=address
#ARGS = 8 3
ARGS = 2 8 5
#ARGS = 11 222 100 -44 0
#ARGS = 17 7 11 8

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