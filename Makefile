# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/30 17:25:14 by bschneid          #+#    #+#              #
#    Updated: 2024/06/24 09:48:18 by bschneid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BON_NAME = checker
HEADER = push_swap.h
MAIN = src/main.c
BONUS = bonus/checker.c
SRC_DIR = src
OBJ_DIR = obj
SOURCES = control.c fill_init.c operations.c push.c reverse_rotate.c\
	  rotate.c small_sort_left.c small_sort_right.c swap.c\
	  thirds_left.c thirds_right.c utils.c
LIBFT = Libft_extended/libft.a
OBJECTS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SOURCES))
FLAGS = -Wall -Werror -Wextra -g

all:	$(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	cc $(FLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(OBJECTS) $(MAIN)
	cc $(FLAGS) $(MAIN) $(OBJECTS) -o $@ -L./Libft_extended -lft

$(LIBFT):
	$(MAKE) -C Libft_extended -f Makefile all
	$(MAKE) -C Libft_extended -f Makefile clean

bonus:	$(LIBFT) $(OBJECTS) $(BONUS)
	cc $(FLAGS) $(BONUS) $(OBJECTS) -o $(BON_NAME) -L./Libft_extended -lft

clean:
	rm -rf $(OBJ_DIR)

fclean:	clean
	rm -f $(NAME)
	rm -f $(BON_NAME)
	rm -f Libft_extended/libft.a

re:	fclean all

.PHONY:	all bonus clean fclean re
