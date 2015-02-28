# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/19 14:14:39 by lchenut           #+#    #+#              #
#    Updated: 2015/02/28 11:56:01 by lchenut          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME       = game_2048

ALL_CFLAGS = -Wall -Wextra -Werror -O3
CC         = gcc

INC_LIBFT  = libft

OBJS_DIR   = objs

SRCS       = game.c

S          = $(addprefix , $(SRCS:.c=.c~))

OBJS       = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\033[4;1;34m*** Création de la LIBFT ***\033[0m"
	make -C libft
	@echo "\033[4;1;34m*** Compilation du 2048  ***\033[0m"
	$(CC) -o $(NAME) $(OBJS) -L $(INC_LIBFT) -lft -lncurses
	@echo "\033[1;32m>>> push_swap ok <<<\033[0m"

$(OBJS_DIR)/%.o: %.c
	$(CC) $(ALL_CFLAGS) -I $(INC_LIBFT)/ -c $< -o $@ -lncurses

clean:
	$(RM) $(OBJS)	
	$(RM) $(S)
	$(RM) Makefile~
	@echo "\033[4;1;34mClean OBJS    >>\033[0m     \033[1;32mok.\033[0m"

fclean: clean
	$(RM) $(NAME)
	@echo "\033[4;1;34mClean 2048    >>\033[0m     \033[1;32mok.\033[0m"

re: fclean all

$(OBJS): | $(OBJS_DIR)

$(OBJS_DIR):
	mkdir $(OBJS_DIR)
