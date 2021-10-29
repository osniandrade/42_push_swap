# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ocarlos- <ocarlos-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/18 20:22:39 by ocarlos-          #+#    #+#              #
#    Updated: 2021/10/29 18:59:28 by ocarlos-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRC = helper1.c helper2.c push_swap.c side1.c side2.c side3.c \
	  side4.c flow.c cases.c validate.c move.c helperlist.c
OBJ = $(SRC:.c=.o)
FLAG = -Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJ)
			@gcc $(FLAG) $(SRC) -o push_swap

clean:
			@/bin/rm -f $(OBJ)

fclean:		clean
			@/bin/rm -f $(NAME)

re:			fclean all