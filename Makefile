# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pifourni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/17 11:01:47 by pifourni          #+#    #+#              #
#    Updated: 2025/12/22 15:01:27 by pifourni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


.PHONY: all clean fclean re

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LIB = -lXext -lX11
MLX = minilibx-linux/libmlx_Linux.a
LIBFT = libft/libft.a

SRC = ./gnl/get_next_line.c ./gnl/get_next_line_utils.c \
	  ./so_long.c \
	  ./src/parser/parser.c ./src/parser/utils.c \
	  ./src/game/run.c

OBJ = $(SRC:.c=.o)

all: $(MLX) $(LIBFT) $(NAME)
	@echo -e '\033[32m $(NAME) Compiled ! \033[0m'

$(MLX):
	@echo -e '\033[34m Compiling MiniLibX ... \033[0m'
	$(MAKE) -C ./minilibx-linux
	@echo -e '\033[32m MiniLibX Compiled ! \033[0m'
$(LIBFT):
	@echo -e '\033[34m Compiling Libft ... \033[0m'
	$(MAKE) -C ./libft
	@echo -e '\033[32m Libft Compiled ! \033[0m'

$(NAME): $(OBJ) $(MLX)
	$(CC) -o $(NAME) $+ $(LIB) $(MLX)

%.o:%.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ)
	$(MAKE) -C ./minilibx-linux clean
	$(MAKE) -C ./libft clean

fclean: clean
	rm -f $(NAME)
	rm -f ./libft/libft.a
	
re: fclean all
