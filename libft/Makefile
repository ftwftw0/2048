# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchenut <lchenut@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/19 14:14:39 by lchenut           #+#    #+#              #
#    Updated: 2015/03/01 15:00:45 by lchenut          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME       = libft.a

ALL_CFLAGS = -Wall -Wextra -Werror -O3
CC         = gcc

INC_LIBFT  = libft

OBJS_DIR   = objs
SRCS = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
	   ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c \
	   ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c \
	   ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
	   ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	   ft_isprint.c ft_toupper.c ft_tolower.c ft_putchar.c ft_putstr.c \
	   ft_itoa.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c \
	   ft_putendl_fd.c ft_putnbr_fd.c ft_memalloc.c ft_memdel.c ft_strnew.c \
	   ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c \
	   ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c \
	   ft_strtrim.c ft_strsplit.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c \
	   ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_strndup.c get_next_line.c \
	   ft_strnew.c ft_btoa.c ft_otoa.c ft_ltoa.c ft_utoa.c ft_htoa.c \
	   ft_capitalize.c ft_minimalize.c ft_is_in.c ft_strfnew.c ft_deltabstr.c \
	   ft_puttabstr.c ft_strtabdup.c ft_swap_char.c ft_dbletoa.c ft_atol.c \
	   ft_depow2.c \
	   ft_intlen.c ft_quick_sort.c ft_isspace.c ft_pf_after_effect.c \
	   ft_pf_check_length.c ft_pf_check_modifier.c \
	   ft_pf_print_and_close.c ft_pf_split.c ft_pf_treat_bin.c \
	   ft_pf_treat_char.c ft_pf_treat_hex.c ft_pf_treat_int.c \
	   ft_pf_treat_null.c ft_pf_treat_oct.c ft_pf_treat_other.c \
	   ft_pf_treat_str.c ft_pf_treat_strange.c ft_pf_treat_uns.c \
	   ft_pf_treat_wchar.c ft_pf_treat_wstr.c ft_pf_useful_function.c \
	   ft_pf_useful_function_three.c ft_pf_useful_function_two.c ft_printf.c

S          = $(addprefix , $(SRCS:.c=.c~))

OBJS       = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\033[4;1;34m***   Création de la LIBFT   ***\033[0m"
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)
	@echo "\033[1;32m>>> libft ok <<<\033[0m"

$(OBJS_DIR)/%.o: %.c
	$(CC) $(ALL_CFLAGS) -I $(INC_LIBFT)/ -c $< -o $@

clean:
	$(RM) $(OBJS)	
	$(RM) $(S)
	$(RM) Makefile~
	@echo "\033[4;1;34mClean OBJS    >>\033[0m     \033[1;32mok.\033[0m"

fclean: clean
	$(RM) $(NAME)
	@echo "\033[4;1;34mClean libft   >>\033[0m     \033[1;32mok.\033[0m"

re: fclean all

$(OBJS): | $(OBJS_DIR)

$(OBJS_DIR):
	mkdir $(OBJS_DIR)
