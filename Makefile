# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/11 10:47:58 by cchen             #+#    #+#              #
#    Updated: 2022/01/11 12:01:04 by cchen            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fillit

CC := gcc
CFLAGS := -Wall -Werror -Wextra
INCLUDES := -I./libft/includes -I./libft/includes/libft -I./src

SRC_DIR := src
OBJ_DIR := obj
LIBFT := libft

SRC := $(SRC_DIR)/main.c

.PHONY: all clean fclean re

all:
	$(MAKE) -C $(LIBFT)
	$(MAKE) $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(INCLUDES) $(SRC) -L./libft -lft -o $(NAME)

clean:
	$(MAKE) -C $(LIBFT) clean

fclean:
	$(MAKE) -C $(LIBFT) fclean
	rm $(NAME)
