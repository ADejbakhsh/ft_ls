# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adejbakh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/09 17:00:04 by adejbakh          #+#    #+#              #
#    Updated: 2019/02/21 11:36:37 by adejbakh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


FUNC = ft_menu.c \
    ft_option.c\
    ft_print_l.c\
    ft_recursive.c\
    ft_sort_algo.c\
    ft_strmode.c\
    ft_swap_link.c\
    ft_time.c\
    inspect_file.c\
    main.c\
    open_dir.c\
    not_a_dir.c\
    ft_print_l_tools.c\
    sort_argv_time.c\

SRC_DIR = ./srcs/

SRC = $(addprefix $(SRC_DIR), $(FUNC))

OBJS = ${FUNC:c=o}

NAME = ft_ls

INCLUDES = ./includes/

CFLAG = -Wall -Wextra -Werror

CC = gcc

LIB =  -L. ./libft/libft.a

.PHONY: clean all fclean re

all: $(NAME)

$(NAME) : $(SRC) Makefile libft/srcs
	@$(CC) $(CFLAG) -I$(INCLUDES) -c $(SRC)
	@make -C ./libft/
	@$(CC) -o $(NAME) $(OBJS) $(LIB)
	@echo "$(NAME) has been made"


clean :
	@rm -f $(OBJS)
	@make -C ./libft/ clean
	@echo "Objects deleted"

fclean: clean
	@rm -f $(NAME)
	@make -C ./libft/ fclean
	@echo "$(NAME) deleted"

re:  fclean all
	@echo "Remake done"
