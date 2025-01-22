# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abhimi <abhimi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/14 13:57:02 by abhimi            #+#    #+#              #
#    Updated: 2025/01/22 15:40:32 by abhimi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker
MAKE = make
CC = cc 
CFLAGS = -Wall -Wextra -Werror -Iincludes
RM =rm -rf 
SRC=$(wildcard src/*.c tools/*.c)
BSRC= $(wildcard bonus/*.c tools/*.c)
OBG=$(SRC:.c=.o)
BOBG=$(BSRC:.c=.o)

all: $(NAME)

$(NAME): $(OBG)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(OBG) ./libft/libft.a -o $(NAME)

$(BONUS): $(BOBG)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(BOBG)	./libft/libft.a -o $(BONUS)

bonus:$(BONUS)
clean:
	$(MAKE) -C ./libft fclean
	$(RM) $(OBG) $(BOBG)

fclean: clean
	$(RM) $(NAME) $(BONUS)

re: fclean all

.PHONY: re fclean clean all

