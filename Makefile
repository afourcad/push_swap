# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afourcad <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 20:03:40 by afourcad          #+#    #+#              #
#    Updated: 2017/06/16 16:13:48 by afourcad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= checker
NAME2	= push_swap

SRCDIR	= srcs
OBJDIR	= objs
INCDIR	= includes

SRCNAM	= ft_operations.c ft_set_stack.c ft_is_sort.c ft_visual.c\
		  ft_error_free.c ft_algo1.c ft_algo2.c ft_check_stack.c\
		  ft_set_tab.c ft_algo3.c ft_algo3_b.c\

SRC		= $(SRCNAM:%=$(SRCDIR)/%)
OBJ		= $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -I$(INCDIR) -I$(LIBINCDIR)
LDFLAGS	= -L $(LIBFTDIR) -lft

LIBFTNAM	= libft.a
LIBFTDIR	= ./libft/
LIBINCDIR	= ./libft/includes/
LIBFT		= $(LIBFTNAM:%=$(LIBFTDIR)/%)

INCNAM = checker.h push_swap.h
INC = $(INCNAM:%=$(INCDIR)/%)

GIT	= README.md

all: $(NAME) $(NAME2)

$(NAME): $(OBJ)
	$(CC) -o objs/checker.o -c srcs/checker.c $(CFLAGS)
	$(CC) -o $@ objs/checker.o $^ $(LDFLAGS)

$(NAME2): $(OBJ)
	$(CC) -o objs/push_swap.o -c srcs/push_swap.c $(CFLAGS)
	$(CC) -o $@ objs/push_swap.o $^ $(LDFLAGS)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INC) $(LIBFT)
	mkdir -p $(OBJDIR)
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: all git no printf check clean fclean re $(LIBFT)

git:
	git add $(SRC) $(INC) $(GIT)

no:
	@echo "Passage de la norminette :"
	@norminette $(SRC) $(INC)

printf:
	@echo "Detection des printf :\033[1;31m"
	@grep printf -r $(SRCDIR) $(INCDIR) | cat
	@printf "\033[0m"

check: no printf

clean:
	rm -rf $(OBJDIR)
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	rm -rf $(NAME) $(NAME2)
	$(MAKE) -C $(LIBFTDIR) fclean

# $(MAKE) needed so that the cleaning is done before starting to create again \
	# 	# cf make -j 
re: fclean
	$(MAKE) all
