# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/23 13:38:21 by lduboulo          #+#    #+#              #
#    Updated: 2021/12/03 17:05:44 by lduboulo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS

GREEN	= \033[1;32m
RED 	= \033[1;31m
ORANGE	= \033[1;33m
GREY	= \033[1;90m
RESET	= \033[0m

# COLORS

LIBFTPATH = ./Libft

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

LIB = ar rcs

SRC = ft_printf.c \
	  ./utils/if_forest.c \
	  ./utils/struct_init.c \
	  ./utils/variable_counter.c \
	  ./utils/pointer_address_process.c \
	  ./utils/string_process.c \
	  ./utils/hexa_process.c \
	  ./utils/core_process.c \

OBJ = $(SRC:.c=.o)

all : $(NAME)

.PHONY : clean fclean re all test tclean

$(NAME) : $(OBJ)
	@$(MAKE) -C $(LIBFTPATH) bonus
	@cp $(LIBFTPATH)/libft.a $(NAME)
	@$(LIB) $(NAME) $(OBJ)
	@echo "$(GREY)====================$(GREEN) [Created] : $(RESET)$(NAME) Library $(GREY)===================================$(RESET)"

clean :
	@rm -f $(OBJ)
	@$(MAKE) -C $(LIBFTPATH) clean
	@echo "$(GREY)====================$(ORANGE) [Deleted] : $(RESET).o files $(GREY)====================================$(RESET)"

fclean : clean
	@rm -f $(NAME)
	@rm -f libft.a
	@$(MAKE) -C $(LIBFTPATH) fclean
	@echo "$(GREY)====================$(RED) [Deleted] : $(RESET).a files $(GREY)====================================$(RESET)"

re : fclean all

test: tclean all
	@$(CC) ft_printf.c -o test $(NAME)
	@echo "$(GREY)====================$(GREEN) [Created] : $(RESET)$(NAME) Test exe ./test to try it out $(GREY)===================================$(RESET)"

tclean: fclean
	@rm -f test
	@echo "$(GREY)====================$(RED) [Deleted] : $(RESET) Test exe $(GREY)====================================$(RESET)"

debog: dclean all
	@$(CC) -g -fsanitize=address ft_printf.c -o test $(NAME)
	@echo "$(GREY)====================$(GREEN) [Created] : $(RESET) Test debog file $(GREY)====================================$(RESET)"

dclean: fclean tclean
	@rm -rf test.dSYM
	@echo "$(GREY)====================$(RED) [Deleted] : $(RESET) Test debog file $(GREY)====================================$(RESET)"
