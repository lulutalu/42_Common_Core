# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/27 18:29:51 by lduboulo          #+#    #+#              #
#    Updated: 2022/04/14 16:18:06 by lduboulo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS

GREEN	= \033[1;32m
RED 	= \033[1;31m
ORANGE	= \033[1;33m
BUILD	= \e[38;5;225m
SEP		= \e[38;5;120m
DUCK	= \e[38;5;227m
RESET	= \033[0m

# COLORS


SRCS_DIR		= ./src/
SRCS_FILES		= main.c error_and_mem.c child_process.c parsing.c \
				  fd_functions.c

SRCS			:= ${patsubst %, ${SRCS_DIR}%, ${SRCS_FILES}}


BONUS_SRCS_DIR	= ./bonus_src/
BONUS_FILES 	= main_bonus.c child_process_bonus.c error_and_mem_bonus.c \
				  fd_functions_bonus.c parsing_bonus.c main_operation.c


BONUS_SRCS		:= ${patsubst %, ${BONUS_SRCS_DIR}%, ${BONUS_FILES}}

O_DIR			= ./objs/
BONUS_DIR		= ./b_objs/

OBJS_FILES		:= ${SRCS_FILES:.c=.o}
BONUS_OBJS		:= ${BONUS_FILES:.c=.o}

OBJS			:= ${patsubst %, ${O_DIR}%, ${OBJS_FILES}}
B_OBJS			:= ${patsubst %, ${BONUS_DIR}%, ${BONUS_OBJS}}

HEADS_DIR		= ./includes/

NAME			= pipex


LIBUTILS		= ./utils/


MAKELIB			= ${MAKE} -C
CC				= gcc
AR				= ar rcs
MKDIR			= mkdir
RM				= rm -rf

CFLAGS			= -Wall -Wextra -Werror -g3 -fsanitize=address

TSEP			= ${SEP}=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=${RESET}



all:			${NAME}

${NAME}:		${O_DIR} ${OBJS}
				@printf "\n"
				@${MAKELIB} ${LIBUTILS}
				@printf "${TSEP}\n"
				@printf "\n${GREEN} 💻 Successfully compiled ${NAME} .o's${RESET} ✅\n"
				@${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBUTILS}/libutils.a
				@printf "${GREEN} 💻 Successfully created ${NAME} executable${RESET} ✅\n"
				@printf "\n${TSEP}\n"

${O_DIR}:
				@${MKDIR} ${O_DIR}
				@printf "${BUILD}${O_DIR} Directory Created 📎${RESET}\n\n"

${O_DIR}%.o:${SRCS_DIR}%.c
				@${CC} ${CFLAGS} -I${HEADS_DIR} -o $@ -c $<
				@printf "\e[1K\r${BUILD} 🚧 $@ from $<${RESET}"

bonus:			fclean ${BONUS_DIR} ${B_OBJS}
				@printf "\n"
				@${MAKELIB} ${LIBUTILS}
				@printf "${TSEP}\n"
				@printf "\n${GREEN} 💻 Successfully compiled ${NAME} bonus's .o's${RESET} ✅\n"
				@${CC} ${CFLAGS} -o ${NAME} ${B_OBJS} ${LIBUTILS}/libutils.a
				@printf "${GREEN} 💻 Successfully created ${NAME} executable${RESET} ✅\n"
				@printf "\n${TSEP}\n"

${BONUS_DIR}:
				@${MKDIR} ${BONUS_DIR}
				@printf "${BUILD}${BONUS_DIR} Directory Created 📎${RESET}\n\n"

${BONUS_DIR}%.o:${BONUS_SRCS_DIR}%.c
				@${CC} ${CFLAGS} -I${HEADS_DIR} -o $@ -c $<
				@printf "\e[1K\r${BUILD} 🚧 $@ from $<${RESET}"
			
clean :
				@${RM} ${O_DIR} ${BONUS_DIR}
				@printf "\n${RED} 🧹 Deleted ${NAME} .o's${RESET} ❌\n\n"

fclean : 		clean
				@${RM} ${NAME} ${NAME}.dSYM
				@${MAKELIB} ${LIBUTILS} fclean
				@printf "${RED} 💥 Deleted ${NAME} files${RESET} ❌\n\n"

re : 			fclean all

norm :
				@${MAKELIB} ${LIBUTILS} norm
				@printf "${DUCK} 🐥 Checking Norm for ${NAME}${RESET}\n"
				@norminette ${SRCS}
				@norminette ${BONUS_SRCS}
				@norminette ${HEADS_DIR}

help :
				@printf "\e[1m\nFor mandatory part, binary call: ./pipex infile cmd1 cmd2 outfile\n\n${RESET}"
				@printf "\e[1mFor bonus part, binary call: ./pipex infile cmd cmd2 ... cmdn outfile\n\n${RESET}"
				@printf "\e[1mFor here_doc, binary call: ./pipex here_doc limiter cmd1 cmd2 outfile\n\n${RESET}"

.PHONY : all clean fclean re norm bonus help
