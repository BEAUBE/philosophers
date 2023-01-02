# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajoliet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/29 14:57:08 by ajoliet           #+#    #+#              #
#    Updated: 2023/01/02 20:42:36 by ajoliet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PHI = philosophers
PHI_SRCS = main.c \
		   parsing.c \
		   ft_utils.c
PHI_OBJS = $(PHI_SRCS:.c=.o)
RM = rm
CLGF = clang -g3 -Wall -Wextra -Werror -pthread

all: $(PHI)

$(PHI): $(PHI_OBJS)
	$(CLGF) -o $(PHI) $(PHI_SRCS)

clean:
	$(RM) $(PHI_OBJS)

fclean: clean
	$(RM) $(PHI)

exec: all
	./$(PHI) 4 420 100 100

execl: all
	./$(PHI) 4 420 100 100 3

re: fclean $(PHI)

.PHONY: all fclean clean re