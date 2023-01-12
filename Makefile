# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajoliet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 13:38:48 by ajoliet           #+#    #+#              #
#    Updated: 2023/01/11 14:28:57 by ajoliet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=philo
CC=gcc
CFLAGS=-Wall -Wextra -Werror -g3 -pthread
SRC_C=	ft_utils.c \
		parsing.c \
		finish.c \
		init.c \
		routine.c \
		ft_say.c \
		ft_gettimestamp.c \
		checker.c \
		routine_utils.c \
		main.c
OBJ_C= $(SRC_C:%.c=%.o)

$(NAME):	$(OBJ_C)
	$(CC) $(CFLAGS) $(OBJ_C) -o $(NAME)

all:	$(NAME)

%.o		: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm $(OBJ_C)

fclean: clean
	rm $(NAME)

exec: re
	./philosophers 4 420 100 100

execl: re
	./philosophers 4 420 100 100 3

execd: re
	./philosophers 4 150 100 100 3

re: fclean $(NAME)
