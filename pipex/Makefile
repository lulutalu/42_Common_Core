# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/27 18:29:51 by lduboulo          #+#    #+#              #
#    Updated: 2022/03/29 05:01:42 by lduboulo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS

GREEN	= \033[1;32m
RED 	= \033[1;31m
ORANGE	= \033[1;33m
GREY	= \033[1;90m
BUILD	= \e[38;5;225m
SEP		= \e[38;5;120m
RESET	= \033[0m

# COLORS


SRCS_DIR	= ./src/
SRCS_FILES	= main.c error.c

SRCS		:= ${patsubst %, ${SRCS_DIR}%, ${SRCS_FILES}}


O_DIR		= ./objs/

OBJS_FILES	:= ${SRCS_FILES:.c=.o}
OBJS		:= ${patsubst %, ${O_DIR}%, ${OBJS_FILES}}

HEADS_DIR	= ./includes/

NAME		= pipex


PRINTF		= ./ft_printf/


MAKELIB		= ${MAKE} -C
CC			= gcc
AR			= ar rcs
MKDIR		= mkdir
RM			= rm -rf

CFLAGS		= -Wall -Wextra -Werror -g3 -fsanitize=address

TSEP		= ${SEP}=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=${RESET}



all:		${NAME}

${NAME}:	${O_DIR} ${OBJS}
			@printf "\n"
			@${MAKELIB} ${PRINTF}
			@printf "${TSEP}\n"
			@printf "\n${GREEN}💻 Successfully compiled ${NAME} .o's${RESET} ✅\n"
			@${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${PRINTF}/libprintf.a
			@printf "${GREEN}💻 Successfully created ${NAME} executable${RESET} ✅\n"
			@printf "\n${TSEP}\n"

${O_DIR}:
			@${MKDIR} ${O_DIR}
			@printf "${BUILD}${O_DIR} Directory Created 📎${RESET}\n\n"

${O_DIR}%.o:${SRCS_DIR}%.c
			@${CC} ${CFLAGS} -I${HEADS_DIR} -o $@ -c $<
			@printf "\e[1K\r${BUILD}🚧 $@ from $<${RESET}"

clean :
			@${RM} ${O_DIR}
			@printf "\n${RED}🧹 Deleted ${NAME} .o's${RESET} ❌\n\n"

fclean : clean
			@${RM} ${NAME} ${NAME}.dSYM
			@${MAKELIB} ${PRINTF} fclean
			@printf "${RED}💥 Deleted ${NAME} files${RESET} ❌\n\n"

re : fclean all

.PHONY : all clean fclean re
