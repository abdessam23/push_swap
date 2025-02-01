# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abhimi <abhimi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/14 13:57:02 by abhimi            #+#    #+#              #
#    Updated: 2025/02/01 15:57:06 by abhimi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker
MAKE = make
CC = cc 
CFLAGS = -Wall -Wextra -Werror -Iincludes
RM =rm -rf 
SRC= src/ft_push_to_a.c src/ft_push_to_b.c src/push_swap.c src/small_sort.c     \
	 tools/utils.c tools/utils1.c tools/isvalid_arg.c tools/instrection2.c 		\
	 tools/instrection1.c tools/ft_moves.c tools/fill_stack.c				


BSRC= bonus/checker.c bonus/ft_check_moves.c bonus/get_next_line_utils.c bonus/get_next_line.c \
	tools/utils.c tools/utils1.c tools/isvalid_arg.c tools/instrection2.c 		\
	 tools/instrection1.c tools/ft_moves.c tools/fill_stack.c	
OBG=$(SRC:.c=.o)
BOBG=$(BSRC:.c=.o)

all: $(NAME)

$(NAME): $(OBG)
	@$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(OBG) ./libft/libft.a -o $(NAME)

$(BONUS): $(BOBG)
	@$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(BOBG)	./libft/libft.a -o $(BONUS)

bonus:$(BONUS)
clean:
	@$(MAKE) -C ./libft fclean
	$(RM) $(OBG) $(BOBG)

fclean: clean
	$(RM) $(NAME) $(BONUS)

re: fclean all

.PHONY: re fclean clean all

