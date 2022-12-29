# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajoliet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/29 14:57:08 by ajoliet           #+#    #+#              #
#    Updated: 2022/12/29 15:39:15 by ajoliet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PHI = philosophers
PHI_SRCS = main.c \
		   parsing.c
PHI_OBJS = $(PHI_SRCS:.c=.o)
RM = rm
CLGF = clang -g3 -Wall -Wextra -Werror -pthread

all: $(PHI)

$(PHI): $(PHI_OBJS)
	$(CLGF) -o $(PHI) $(PHI_SRCS)

clean:
	$(RM) $(PHI_OBJS)

fclean: clean

re: fclean $(PHI)

.PHONY: all fclean clean re
