# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abhimi <abhimi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/14 13:57:02 by abhimi            #+#    #+#              #
#    Updated: 2025/01/14 17:36:02 by abhimi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
MAKE = make
CC = cc 
CFLAGS = -Wall -Wextra -Werror -Iincludes
RM =rm -rf 
SRC=$(wildcard src/*.c tools/*.c)
OBG=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBG)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(OBG) ./libft/libft.a -o $(NAME) -g

clean:
	$(MAKE) -C ./libft fclean
	$(RM) $(OBG)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: re fclean clean all

