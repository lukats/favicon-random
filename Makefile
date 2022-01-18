# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/18 16:29:53 by lutsiara          #+#    #+#              #
#    Updated: 2022/01/18 18:05:38 by lutsiara         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := favicon-mod

SRCDIR := srcs/
SRC := main.c \
	   utils.c \
	   exit.c

SRC := $(addprefix $(SRCDIR), $(SRC))

INCDIR := includes/
INC := favicon-mod.h

INC := $(addprefix $(INCDIR), $(INC))
OBJ := $(SRC:.c=.o)
CFLAGS := -Wall -Wextra -Werror -I$(INCDIR)

$(NAME): $(OBJ) $(INC)
	cc $(OBJ) $(CFLAGS) -o $(NAME)

all: $(NAME)

%.o: %.c
	cc $(CFLAGS) -o $@ -c $<

$(INC):

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

.NOTPARALLEL: re
