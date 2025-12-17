# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pifourni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/17 11:01:47 by pifourni          #+#    #+#              #
#    Updated: 2025/12/17 13:40:09 by pifourni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


.PHONY: all clean fclean re

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LIB = 

SRC = ./Get_Next_Line/get_next_line.c \
	  ./Get_Next_Line/get_next_line_utils.c \
	  ./so_long.c \
	  ./src/parser/parser.c \
	  ./src/game/run.c 
