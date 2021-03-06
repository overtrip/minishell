# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/25 15:08:49 by jealonso          #+#    #+#              #
#    Updated: 2015/12/14 17:58:20 by jealonso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SUFFIXES:

.PHONY: all re clean fclean cleanlib cleanall fleme

#BINARIES:
CC			= /usr/bin/clang
RM			= /bin/rm
GIT			= /usr/bin/git
MAKE		= /usr/bin/make
MKDIR		= /bin/mkdir

#FILES:
INCPATH		= includes
LFTPATH		= libft
SRCSPATH	= srcs
OBJSPATH	= objs

#FIND:

#LIB:
LIBFT		= $(LFTPATH)/libft.a

#FLAGS:
LDFLAGS		= -L $(LFTPATH) -lft
CFLAGS		= -Wall -Wextra -Werror -O3
PATHLIB		= -I $(INCPATH) -I $(LFTPATH)/$(INCPATH)

#EXECUTALE:
NAME 		= ft_minishell

#SRCRS:
SRCS 		= \
			ft_builtins.c \
			ft_change_env.c \
			ft_fork.c \
			ft_sig.c \
			ft_tools.c \
			main.c \

#OBJ:
OBJS = $(patsubst %.c, $(OBJSPATH)/%.o, $(SRCS))

#HEAD:
HFILES	= sh_1.h
HEAD	= $(patsubst %.h, $(INCPATH)/%.h, $(HFILES))

all: $(LIBFT) $(OBJSPATH) $(NAME)

$(NAME): $(OBJS)
	@$(CC) -g3 $(CFLAGS) $(LDFLAGS) -o $@ $^

$(OBJSPATH)/%.o: $(SRCSPATH)/%.c $(HEAD)
	@$(CC) -c $(CFLAGS) $(PATHLIB) -o $@ $<

clean:
	@$(MAKE) -C $(LFTPATH) clean
	@$(RM) -rf $(OBJSPATH)
	@echo "Delete current objs files"

fclean: clean
	@$(MAKE) -C $(LFTPATH) fclean
	@$(RM) -rf $(NAME)
	@echo "Delete current objs files and current executable"

cleanlib:
	$(MAKE) clean -C $(LFTPATH)

cleanall: clean cleanlib

re: fclean all

$(OBJSPATH):
	@$(MKDIR) $@

$(LIBFT):
	@$(MAKE) -C $(LFTPATH)

fleme:
	@$(MAKE) re > /dev/null
	@$(MAKE) cleanall > /dev/null
	@echo "YOUPI"

sup:
	@$(MKDIR) -p ~/Library/Caches/Homebrew
	@$(BREW) rm -rf cmake
