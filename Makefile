# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/11 10:47:58 by cchen             #+#    #+#              #
#    Updated: 2022/01/25 17:10:29 by cchen            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fillit

CC := gcc
CFLAGS := -Wall -Werror -Wextra
INCLUDES := -I./libft  -I./src
L_FT := -L./libft -lft

SRC_DIR := src
OBJ_DIR := obj
LIBFT := libft

SRC := $(shell find $(SRC_DIR) -type f | grep -E "\.c$$")
HEADER := $(SRC_DIR)/$(NAME).h

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(SRC) $(HEADER)
	$(MAKE) -C $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) $(SRC) $(L_FT) -o $(NAME)

clean:
	$(MAKE) -C $(LIBFT) clean

fclean:
	$(MAKE) -C $(LIBFT) fclean
	@rm -f $(NAME)

re: fclean all
