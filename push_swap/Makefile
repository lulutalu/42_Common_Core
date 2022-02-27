# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile_Bis                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lduboulo <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/27 18:29:51 by lduboulo          #+#    #+#              #
#    Updated: 2022/02/27 23:00:14 by lduboulo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS

GREEN	= \033[1;32m
RED 	= \033[1;31m
ORANGE	= \033[1;33m
GREY	= \033[1;90m
RESET	= \033[0m

# COLORS

#Compiler and Linker
CC          := gcc

#The Target Binary Program
TARGET      := push_swap

#The Directories, Source, Includes, Objects, Binary and Resources
SRCDIR      := src
BUILDDIR    := obj
LIBDIR		:= Libft
SRCEXT      := c
DEPEXT      := d
OBJEXT      := o

#Flags, Libraries and Includes
CFLAGS      := -Wall -Wextra -Werror
LLDBFLAGS	:= -g3 -fsanitize=address,undefined

#---------------------------------------------------------------------------------
#DO NOT EDIT BELOW THIS LINE
#---------------------------------------------------------------------------------
SOURCES     := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS     := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.$(OBJEXT)))

#Defauilt Make
all: directories $(TARGET)

#Remake
re: fclean all

#Make the Directories
directories:
	@mkdir -p $(BUILDDIR)

fclean: clean
	@$(MAKE) -C $(LIBDIR) fclean
	@$(RM) -rf $(TARGET)
	@echo "$(GREY)====================$(RED) [Deleted] : $(RESET)$(TARGET) executable $(GREY)======================================$(RESET)"

#Clean only Objecst
clean:
	@$(MAKE) -C $(LIBDIR) clean
	@$(RM) -rf $(BUILDDIR)
	@echo "$(GREY)====================$(RED) [Deleted] : $(RESET)$(TARGET) objects files $(GREY)===================================$(RESET)"

#Pull in dependency info for *existing* .o files
-include $(OBJECTS:.$(OBJEXT)=.$(DEPEXT))

#Link
$(TARGET): $(OBJECTS)
	@$(MAKE) -C $(LIBDIR)
	@$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS) $(LIBDIR)/libft.a
	@echo "$(GREY)====================$(GREEN) [Created] : $(RESET)$(TARGET) executable $(GREY)======================================$(RESET)"

#Compile
$(BUILDDIR)/%.$(OBJEXT): $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -c -o $@ $<
	@$(CC) $(CFLAGS) $(INCDEP) -MM $(SRCDIR)/$*.$(SRCEXT) > $(BUILDDIR)/$*.$(DEPEXT)
	@cp -f $(BUILDDIR)/$*.$(DEPEXT) $(BUILDDIR)/$*.$(DEPEXT).tmp
	@sed -e 's|.*:|$(BUILDDIR)/$*.$(OBJEXT):|' < $(BUILDDIR)/$*.$(DEPEXT).tmp > $(BUILDDIR)/$*.$(DEPEXT)
	@sed -e 's/.*://' -e 's/\\$$//' < $(BUILDDIR)/$*.$(DEPEXT).tmp | fmt -1 | sed -e 's/^ *//' -e 's/$$/:/' >> $(BUILDDIR)/$*.$(DEPEXT)
	@rm -f $(BUILDDIR)/$*.$(DEPEXT).tmp

#Non-File Targets
.PHONY: all re directories clean fclean

