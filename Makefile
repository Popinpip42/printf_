# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsirpa-g <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/22 07:02:19 by lsirpa-g          #+#    #+#              #
#    Updated: 2023/09/22 21:25:52 by lsirpa-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC = ft_printf.c utils1.c utils2.c utils3.c

OBJ = $(SRC:.c=.o)

CC = gcc
FLAGS = -Wall -Werror -Wextra
RM = rm -rf
AR = ar cr

all: ${NAME}

${NAME}: $(OBJ)
	$(AR) $(NAME) $(OBJ)
%.o: %.c
	$(CC) $(FLAGS) -c $^ -o $@
clean:
	$(RM) $(OBJ)
fclean:	clean
	$(RM) $(NAME)
re:	fclean all

.PHONY:	all, clean, fclean, re
