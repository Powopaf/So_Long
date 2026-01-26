# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pifourni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/17 11:01:47 by pifourni          #+#    #+#              #
#    Updated: 2026/01/19 13:36:37 by pifourni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


.PHONY: all clean fclean re

NAME = so_long
CC = cc

CFLAGS = -Wall -Wextra -Werror
LIB = -lXext -lX11 
MLX = minilibx-linux/libmlx_Linux.a
LIBFT = libft/libft.a
PRINTF = printf/libftprintf.a

SRC = ./gnl/get_next_line.c ./gnl/get_next_line_utils.c \
	  ./so_long.c \
	  ./src/parser/parser.c ./src/parser/utils.c ./src/parser/is_play.c \
	  ./src/parser/is_play_utils.c \
	  ./src/game/run.c ./src/game/draw.c ./src/game/init.c \
	  ./src/game/event/key.c ./src/game/event/key_utils.c \
	  ./src/game/end.c \
	  ./src/game/error.c

OBJ = $(SRC:.c=.o)

all: $(MLX) $(LIBFT) $(PRINTF) $(NAME)

$(MLX):
	$(MAKE) -C ./minilibx-linux
$(LIBFT):
	$(MAKE) -C ./libft

$(PRINTF):
	$(MAKE) -C ./printf

$(NAME): $(OBJ) $(MLX) $(LIBFT) $(PRINTF)
	$(CC) -o $(NAME) $+ $(LIB) $(MLX) $(LIBFT) $(PRINTF)

%.o:%.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ)
	$(MAKE) -C ./minilibx-linux clean
	$(MAKE) -C ./libft clean
	$(MAKE) -C ./printf clean

fclean: clean
	rm -f $(NAME)
re: fclean all
