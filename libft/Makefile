# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/09 16:51:42 by jealonso          #+#    #+#              #
#    Updated: 2015/12/13 16:58:29 by jealonso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SUFFIXES:

.PHONY: all re clean fclean casm ccf

NAME = libft.a

INCPATH = includes

OBJSPATH = objs

AR = ar

RANLIB = ranlib

SRCSPATH = srcs

OBJSPATH = objs

SRCS = \
	ft_atoi.c \
	ft_bzero.c \
	ft_create_elem.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_islower.c \
	ft_isprint.c \
	ft_isupper.c \
	ft_itoa.c \
	ft_lst_push_back.c \
	ft_lstadd.c \
	ft_memalloc.c \
	ft_memccpy.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memdel.c \
	ft_memmove.c \
	ft_memset.c \
	ft_putchar.c \
	ft_putchar_fd.c \
	ft_putchar_l.c \
	ft_putendl.c \
	ft_putendl_fd.c \
	ft_putlist.c \
	ft_putnbr.c \
	ft_putnbr_fd.c \
	ft_putnbr_long.c \
	ft_putstr.c \
	ft_putstr_fd.c \
	ft_strcat.c \
	ft_strchr.c \
	ft_strclr.c \
	ft_strcmp.c \
	ft_strcpy.c \
	ft_strdel.c \
	ft_strdup.c \
	ft_strequ.c \
	ft_striter.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlen.c \
	ft_strmap.c \
	ft_strmapi.c \
	ft_strncat.c \
	ft_strncmp.c \
	ft_strncpy.c \
	ft_strndup.c \
	ft_strnequ.c \
	ft_strnew.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strsplit.c \
	ft_strstr.c \
	ft_strsub.c \
	ft_strtrim.c \
	ft_swap.c \
	ft_swap_str.c \
	ft_tolower.c \
	ft_toupper.c \
	get_next_line.c

CFLAGS = -Wall -Werror -Wextra -I $(INCPATH)

COBJS =  $(patsubst %.c, $(OBJSPATH)/%.o, $(SRCS))

HEAD = $(patsubst %.h, $(INCPATH)/%.h, $(HFILES))

all: $(OBJSPATH) $(NAME)

$(NAME): ccf $(COBJS)
	@ $(AR) -rc $@ $(COBJS)
	@$(RANLIB) $@
	@echo "\033[1;32;41m\nAll is done!\033[0m"

ccf:
	@echo "\033[1;33;105mCompilation libft\033[0m"

$(OBJSPATH)/%.o: $(SRCSPATH)/%.c $(HEAD)
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@/bin/rm -rf $(OBJSPATH)
	@echo "Delete objs file"

fclean: clean
	@/bin/rm -rf $(NAME)
	@echo "Delete objs file and executable    "

re: fclean all

$(OBJSPATH) :
	@mkdir $@
