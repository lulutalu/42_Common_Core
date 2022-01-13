# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/22 12:50:51 by lduboulo          #+#    #+#              #
#    Updated: 2022/01/13 22:46:47 by lduboulo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c \
	  ft_bzero.c \
	  ft_isalnum.c \
	  ft_isalpha.c \
	  ft_isascii.c \
	  ft_isdigit.c \
	  ft_isprint.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_memcpy.c \
	  ft_memmove.c \
	  ft_memset.c \
	  ft_strchr.c \
	  ft_strlcat.c \
	  ft_strlcpy.c \
	  ft_strlen.c \
	  ft_strncmp.c \
	  ft_strnstr.c \
	  ft_strrchr.c \
	  ft_tolower.c \
	  ft_toupper.c \
	  ft_calloc.c \
	  ft_strdup.c \
	  ft_substr.c \
	  ft_dyn_substr.c \
	  ft_strjoin.c \
	  ft_strtrim.c \
	  ft_split.c \
	  ft_itoa.c \
	  ft_strmapi.c \
	  ft_striteri.c \
	  ft_putchar_fd.c \
	  ft_putstr_fd.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c \
	  ft_itoa_base.c \
	  ft_putchar_fd_count.c \
	  ft_putstr_fd_count.c \
	  ft_putnbr_fd_count.c

SRCBONUS = ft_lstnew.c \
		   ft_lstadd_front.c \
		   ft_lstsize.c \
		   ft_lstlast.c \
		   ft_lstadd_back.c \
		   ft_lstdelone.c \
		   ft_lstclear.c \
		   ft_lstiter.c \
		   ft_lstmap.c

BONUSOBJ = $(SRCBONUS:.c=.o)

OBJECTS = $(SRC:.c=.o)

COMP = gcc -Wextra -Wall -Werror -c

LIB = ar rcs

all : $(NAME)

$(NAME) : $(OBJECTS)
	@$(COMP) $(SRC) && $(LIB) $(NAME) $(OBJECTS)

bonus :
	@$(COMP) $(SRC) $(SRCBONUS) && $(LIB) $(NAME) $(OBJECTS) $(BONUSOBJ)

.PHONY : clean
clean :
	@rm -f $(OBJECTS) $(BONUSOBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all
