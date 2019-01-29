# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccommiss <ccommiss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/15 12:10:02 by adejbakh          #+#    #+#              #
#    Updated: 2019/01/29 17:17:05 by adejbakh         ###   ########.fr        #
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
 
SRC_DIR = ./srcs/

SRC = $(addprefix $(SRC_DIR), $(FUNC))

OBJS = ${FUNC:c=o}

NAME = ft_ls

INCLUDES = ./includes/

CFLAG = -Wall -Wextra -Werror

CC = gcc

LIB =  -L. ./libft/libft.a

.PHONY: clean all fclean re

$(NAME) : $(SRC) Makefile libft/srcs
	@$(CC) $(CFLAG) -I$(INCLUDES) -c $(SRC)
	@make -C ./libft/
	@$(CC) -o $(NAME) $(OBJS) $(LIB)
	@echo "$(NAME) has been made"

all: $(NAME)

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
