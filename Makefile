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
MLX_CFLAGS = -w
MLX = minilibx-linux/libmlx_Linux.a
LIBFT = libft/libft.a
PRINTF = printf/libftprintf.a

SRC = ./gnl/get_next_line.c ./gnl/get_next_line_utils.c \
	  ./so_long.c \
	  ./src/parser/parser.c ./src/parser/utils.c \
	  ./src/game/run.c ./src/game/draw.c ./src/game/init.c \
	  ./src/game/event/key.c ./src/game/event/key_utils.c \
	  ./src/game/end.c \
	  ./src/game/error.c

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

$(PRINTF):
	@echo -e '\033[34m Compiling Ft_printf ... \033[0m'
	$(MAKE) -C ./printf
	@echo -e '\033[32m Ft_printf Compiled ! \033[0m'

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
