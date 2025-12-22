# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pifourni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/17 11:01:47 by pifourni          #+#    #+#              #
#    Updated: 2025/12/17 15:32:32 by pifourni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


.PHONY: all clean fclean re

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LIB = -lXext -lX11
MLX = minilibx-linux/libmlx_Linux.a

SRC = ./Get_Next_Line/get_next_line.c \
	  ./Get_Next_Line/get_next_line_utils.c \
	  ./so_long.c \
	  ./src/parser/parser.c \
	  ./src/game/run.c \
	  ./src/parser/map.c

OBJ = $(SRC:.c=.o)

all: $(MLX) $(NAME)
	@echo -e '\033[32m $(NAME) Compiled ! \033[0m'

$(MLX):
	@echo -e '\033[34m Compiling MiniLibX ... \033[0m'
	$(MAKE) -C ./minilibx-linux
	@echo -e '\033[32m MiniLibX Compiled ! \033[0m'

$(NAME): $(OBJ) $(MLX)
	$(CC) -o $(NAME) $+ $(LIB) $(MLX)

%.o:%.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ)
	$(MAKE) -C ./minilibx-linux clean

fclean: clean
	rm -f $(NAME)
	
re: fclean all
