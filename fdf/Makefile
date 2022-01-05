# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/16 14:19:45 by lduboulo          #+#    #+#              #
#    Updated: 2022/01/05 21:45:51 by lduboulo         ###   ########.fr        #
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

NAME = fdf

CC = gcc

CFLAGS = -Wall -Werror -Wextra -Imlx -D BUFFER_SIZE=1

MLXFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

LLDBFLAGS = -g -fsanitize=address,undefined

SRC = ./utils/main.c \
	  ./utils/get_next_line.c \
	  ./utils/get_next_line_utils.c \
	  ./utils/argument_check.c \
	  ./utils/file_desc_manipulation.c \
	  ./utils/map_process.c \

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@$(MAKE) -C $(LIBFTPATH) bonus
	@$(MAKE) -C $(MINILIBPATH)
	@$(CC) $(CFLAGS) $(MLXFLAGS) -o $(NAME) $(OBJ) $(LIBFTPATH)/$(LIBFT) 
	@echo "$(GREY)====================$(GREEN) [Created] : $(RESET)./fdf $(GREY)===================================$(RESET)"

clean :
	@$(MAKE) -C $(LIBFTPATH) clean
	@$(MAKE) -C $(MINILIBPATH) clean
	@rm -f $(OBJ)
	@echo "$(GREY)====================$(ORANGE) [Deleted] : $(RESET).o files $(GREY)================================$(RESET)"

fclean : clean
	@$(MAKE) -C $(LIBFTPATH) fclean
	@$(MAKE) -C $(MINILIBPATH) clean
	@rm -f $(NAME)
	@echo "$(GREY)====================$(RED) [Deleted] : $(RESET).o and .a files - ./fdf $(GREY)=================$(RESET)"

re : fclean all

debog : $(OBJ)
	@$(MAKE) -C $(LIBFTPATH) bonus
	@$(MAKE) -C $(MINILIBPATH)                                                                                              
	@$(CC) $(CFLAGS) $(MLXFLAGS) $(LLDBFLAGS) -o $(NAME) $(OBJ) $(LIBFTPATH)/$(LIBFT) 
	@echo "$(GREY)====================$(GREEN) [Created] : $(RESET)./fdf debog $(GREY)===================================$(RESET)"

.PHONY : all clean fclean re debog
