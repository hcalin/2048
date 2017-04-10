# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chrihorc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/18 20:00:01 by chrihorc          #+#    #+#              #
#    Updated: 2017/03/19 22:36:32 by chrihorc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = game_2048

CC=gcc

CFLAGS=

RM=rm -f

SRC=main_menu.c game_start.c eval_map.c matrix_calculus.c

OBJ=$(SRC:.c=.o)

$(NAME): 
	$(CC) $(CFLAGS) -c $(SRC)
	$(CC) $(OBJ)  -lncurses -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean
