# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/27 18:29:51 by lduboulo          #+#    #+#              #
#    Updated: 2022/03/07 17:18:18 by lduboulo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS

GREEN	= \033[1;32m
RED 	= \033[1;31m
ORANGE	= \033[1;33m
GREY	= \033[1;90m
RESET	= \033[0m

# COLORS

.SILENT : $(NAME)

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g3

SRC = src/core_process.c src/ft_atoi.c src/ft_bzero.c src/ft_calloc.c src/ft_dyn_substr.c \
	  src/ft_isalnum.c src/ft_isascii.c src/ft_isdigit.c src/ft_isprint.c src/ft_itoa.c \
	  src/ft_itoa_base.c src/ft_lstadd_back.c src/ft_lstclear.c src/ft_lstdelone.c \
	  src/ft_lstiter.c src/ft_lstlast.c src/ft_lstmap.c src/ft_lstnew.c src/ft_mem_alloc_check.c \
	  src/ft_memchr.c src/ft_memcmp.c src/ft_memcpy.c src/ft_memmove.c src/ft_memset.c \
	  src/ft_putchar_fd.c src/ft_putchar_fd_count.c src/ft_putendl_fd.c src/ft_putnbr_fd.c \
	  src/ft_putnbr_fd_count.c src/ft_putstr_fd_count.c src/ft_split.c src/ft_strchr.c \
	  src/ft_strdup.c src/ft_striteri.c src/ft_strjoin.c src/ft_strlcpy.c src/ft_strlen.c \
	  src/ft_strmapi.c src/ft_strncmp.c src/ft_strnstr.c src/ft_strrchr.c src/ft_substr.c \
	  src/ft_tolower.c src/ft_toupper.c src/get_next_line.c src/get_next_line_utils.c \
	  src/if_forest.c src/pointer_address_process.c src/string_process.c \
	  src/struct_init.c src/variable_counter.c src/ft_isalpha.c src/ft_lstadd_front.c \
	  src/ft_lstsize.c src/ft_printf.c src/ft_putstr_fd.c src/ft_strlcat.c \
	  src/ft_strtrim.c src/hexa_process.c \

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "$(GREY)====================$(GREEN) [Created] : $(RESET)libft.a $(GREY)===================================$(RESET)"

clean :
	@rm -f $(OBJ)
	@echo "$(GREY)====================$(ORANGE) [Deleted] : $(RESET).o files $(GREY)================================$(RESET)"

fclean : clean
	@rm -rf $(NAME) $(NAME).dSYM
	@echo "$(GREY)====================$(RED) [Deleted] : $(RESET).o and .a files$(GREY)==========================$(RESET)"

re : fclean all

.PHONY : all clean fclean re
