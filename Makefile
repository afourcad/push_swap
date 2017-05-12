# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afourcad <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 20:03:40 by afourcad          #+#    #+#              #
#    Updated: 2017/04/21 19:15:20 by afourcad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= checker
NAME2	= push_swap

SRCDIR	= srcs
OBJDIR	= objs
INCDIR	= includes

SRCNAM	= ft_operations.c ft_set_stack.c ft_is_sort.c \
		  ft_error_free.c ft_find_operations.c ft_algo2.c\

SRC		= $(SRCNAM:%=$(SRCDIR)/%)
OBJ		= $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

CC		= clang
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
	rm -rf $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

# $(MAKE) needed so that the cleaning is done before starting to create again \
	# 	# cf make -j 
re: fclean
	$(MAKE) all
