# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/16 14:19:45 by lduboulo          #+#    #+#              #
#    Updated: 2021/12/16 17:23:29 by lduboulo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS

GREEN	= \033[1;32m
RED 	= \033[1;31m
ORANGE	= \033[1;33m
GREY	= \033[1;90m
RESET	= \033[0m

# COLORS

LIBFTPATH = ./libft

LIBFT = libft.a

MINILIBPATH = ./mlx

NAME = so_long

CC = gcc

CFLAGS = -Wall -Werror -Wextra -Imlx

MLXFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

SRC = ./utils/main.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@$(MAKE) -C $(LIBFTPATH) bonus
	@$(MAKE) -C $(MINILIBPATH)
	@$(CC) $(CFLAGS) $(MLXFLAGS) -o $(NAME) $(OBJ) $(LIBFTPATH)/$(LIBFT) 
	@echo "$(GREY)====================$(GREEN) [Created] : $(RESET)./so_long $(GREY)===================================$(RESET)"

clean :
	@$(MAKE) -C $(LIBFTPATH) clean
	@$(MAKE) -C $(MINILIBPATH) clean
	@rm -f $(OBJ)
	@echo "$(GREY)====================$(ORANGE) [Deleted] : $(RESET).o files $(GREY)===================================$(RESET)"

fclean : clean
	@$(MAKE) -C $(LIBFTPATH) fclean
	@$(MAKE) -C $(MINILIBPATH) clean
	@rm -f $(NAME)
	@echo "$(GREY)====================$(RED) [Deleted] : $(RESET).o and .a files - ./so_long $(GREY)===================================$(RESET)"

re : fclean all

.PHONY : all clean fclean re
