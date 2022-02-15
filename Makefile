# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/21 15:17:38 by gozsertt          #+#    #+#              #
#    Updated: 2022/02/15 10:34:54 by gozsertt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	ft_containers

NAME_STD	=	std_containers

CC			=	clang++

SRC_DIR		=	$(shell find srcs -type d)
INC_DIR		=	$(shell find includes -type d)
OBJ_DIR		=	obj

vpath %.cpp $(foreach dir, $(SRC_DIR), $(dir):)

SRC			= 	$(foreach dir, $(SRC_DIR), $(foreach file, $(wildcard $(dir)/*.cpp), $(notdir $(file))))

OBJ			=	$(addprefix $(OBJ_DIR)/, $(SRC:%.cpp=%.o))

# Compilation flags

CFLAGS		=	-Wall -Wextra -Werror -std=c++98 #-g3 -fsanitize=address

D_NO_STD  	=	-DSTD=0

D_STD		=	-DSTD=1

IFLAGS		=	$(foreach dir, $(INC_DIR), -I $(dir))

# Colors

_GREY=	$' \033[30m
_RED=	$' \033[31m
_GREEN=	$' \033[32m
_YELLOW=$' \033[33m
_BLUE=	$' \033[34m
_PURPLE=$' \033[35m
_CYAN=	$' \033[36m
_WHITE=	$' \033[37m

# MAIN part --------------------------------------------------------

all:
	@echo "\n$(_BLUE)___$(NAME) Setting___\n$(_WHITE)"
	@make STD=$(D_NO_STD) $(NAME)

std:
	@echo "\n$(_BLUE)___$(NAME_STD) Setting___\n$(_WHITE)"
	@make STD=$(D_STD) $(NAME_STD)

show:
	@echo "$(_BLUE)SRC :\n$(_YELLOW)$(SRC)$(_WHITE)"
	@echo "$(_BLUE)OBJ :\n$(_YELLOW)$(OBJ)$(_WHITE)"
	@echo "$(_BLUE)CFLAGS :\n$(_YELLOW)$(CFLAGS)$(_WHITE)"
	@echo "$(_BLUE)IFLAGS :\n$(_YELLOW)$(IFLAGS)$(_WHITE)"
	@echo "\n-----\n"
	@echo "$(_BLUE)Compiling : \n$(_YELLOW)$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(_WHITE)"

$(NAME): $(OBJ)
	@echo "-----\nCreating Binary File $(_YELLOW)$@$(_WHITE) ... \c"
	@$(CC) $(CFLAGS) $(STD) $(OBJ) -o $(NAME)
	@echo "$(_GREEN)DONE$(_WHITE)\n-----"

$(NAME_STD): $(OBJ)
	@echo "-----\nCreating Binary File $(_YELLOW)$@$(_WHITE) ... \c"
	@$(CC) $(CFLAGS) $(STD) $(OBJ) -o $(NAME_STD)
	@echo "$(_GREEN)DONE$(_WHITE)\n-----"

$(OBJ_DIR)/%.o : %.cpp
	@echo "Compiling $(_YELLOW)$@$(_WHITE) ... \c"
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(STD) $(IFLAGS) -o $@ -c $<
	@echo "$(_GREEN)DONE$(_WHITE)"

re:	fclean all

clean:
	@echo "$(_WHITE)Deleting Objects Directory $(_YELLOW)$(OBJ_DIR)$(_WHITE) ... \c"
	@$(foreach file, $(OBJ), rm -rf $(file))
	@rm -rf ftVectorLog stdVectorLog ftStackLog stdStackLog ftMapLog stdMapLog ftSetLog stdSetLog
	@echo "$(_GREEN)DONE$(_WHITE)\n-----"

fclean:	clean
	@echo "Deleting Binary File $(_YELLOW)$(NAME)$(_WHITE) ... \c"
	@rm -f $(NAME)
	@echo "$(_GREEN)DONE$(_WHITE)\n-----"

fclean-std:	clean
	@echo "Deleting Binary File $(_YELLOW)$(NAME_STD)$(_WHITE) ... \c"
	@rm -f $(NAME_STD)
	@echo "$(_GREEN)DONE$(_WHITE)\n-----"

.PHONY: all std show re clean flcean fclean-std