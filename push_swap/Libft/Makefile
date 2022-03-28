# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/27 18:29:51 by lduboulo          #+#    #+#              #
#    Updated: 2022/03/28 15:05:00 by lduboulo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS

GREEN	= \033[1;32m
RED 	= \033[1;31m
ORANGE	= \033[1;33m
GREY	= \033[1;90m
RESET	= \033[0m

# COLORS

SRCS_DIR	= ./src/
SRCS_FILES 	= core_process.c ft_atoi.c ft_atol.c ft_bzero.c ft_calloc.c \
			  ft_dyn_substr.c ft_isalnum.c ft_isascii.c ft_isdigit.c \
			  ft_isprint.c ft_itoa.c ft_itoa_base.c ft_lstadd_back.c \
			  ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
			  ft_lstmap.c ft_lstnew.c ft_mem_alloc_check.c \
			  ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
			  ft_putchar_fd.c ft_putchar_fd_count.c ft_putendl_fd.c ft_putnbr_fd.c \
			  ft_putnbr_fd_count.c ft_putstr_fd_count.c ft_split.c ft_strchr.c \
			  ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcpy.c ft_strlen.c \
			  ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_substr.c \
			  ft_tolower.c ft_toupper.c get_next_line.c get_next_line_utils.c \
			  if_forest.c pointer_address_process.c string_process.c \
			  struct_init.c variable_counter.c ft_isalpha.c ft_lstadd_front.c \
			  ft_lstsize.c ft_printf.c ft_putstr_fd.c ft_strlcat.c \
			  ft_strtrim.c hexa_process.c \

SRCS		:= ${patsubst %, ${SRCS_DIR}%, ${SRCS_FILES}}

O_DIR		= ./objs/

OBJS_FILES	:= ${SRCS_FILES:.c=.o}
OBJS		:= ${patsubst %, ${O_DIR}%, ${OBJS_FILES}}

NAME		= libft.a

CC			= gcc
AR			= ar -rcs
MKDIR		= mkdir
RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror -g3 -fsanitize=address


all :		${NAME}

${NAME} : 	${O_DIR} ${OBJS}
			@${AR} ${NAME} ${OBJS}
			@echo "$(GREY)====================$(GREEN) [Created] : $(RESET)libft.a $(GREY)===================================$(RESET)"

${O_DIR}:
			${MKDIR} ${O_DIR}

${O_DIR}%.o:${SRCS_DIR}%.c
			${CC} ${CFLAGS} -o $@ -c $<

clean :
	@rm -rf ${O_DIR}
	@echo "$(GREY)====================$(ORANGE) [Deleted] : $(RESET).o files $(GREY)================================$(RESET)"

fclean : clean
	@rm -rf $(NAME) $(NAME).dSYM
	@echo "$(GREY)====================$(RED) [Deleted] : $(RESET).o and .a files$(GREY)==========================$(RESET)"

re : fclean all

.PHONY : all clean fclean re
