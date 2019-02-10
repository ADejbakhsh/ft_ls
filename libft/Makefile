# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccommiss <ccommiss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/15 12:10:02 by adejbakh          #+#    #+#              #
#    Updated: 2019/02/09 17:46:27 by adejbakh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FUNC =  ft_atoi.c\
  ft_bzero.c\
  ft_isalnum.c\
  ft_isalpha.c\
  ft_isascii.c\
  ft_isdigit.c\
  ft_isprint.c\
  ft_memccpy.c\
  ft_memchr.c\
  ft_memcmp.c\
  ft_memcpy.c\
  ft_memmove.c\
  ft_memset.c\
  ft_strcat.c\
  ft_strchr.c\
  ft_strcmp.c\
  ft_strcpy.c\
  ft_strdup.c\
  ft_strlcat.c\
  ft_strlen.c\
  ft_strncat.c\
  ft_strncmp.c\
  ft_strncpy.c\
  ft_strnstr.c\
  ft_strrchr.c\
  ft_strstr.c\
  ft_tolower.c\
  ft_toupper.c\
  ft_memalloc.c\
  ft_memdel.c\
  ft_strnew.c\
  ft_strdel.c\
  ft_strclr.c\
  ft_striter.c\
  ft_striteri.c\
  ft_strmap.c\
  ft_strmapi.c\
  ft_strequ.c\
  ft_strnequ.c\
  ft_strsub.c\
  ft_strjoin.c\
  ft_strtrim.c\
  ft_strsplit.c\
  ft_itoa.c\
  ft_putchar.c\
  ft_putstr.c\
  ft_putendl.c\
  ft_putnbr.c\
  ft_putchar_fd.c\
  ft_putstr_fd.c\
  ft_putendl_fd.c\
  ft_putnbr_fd.c\
  ft_lstnew.c\
  ft_lstdelone.c\
  ft_lstdel.c\
  ft_lstadd.c\
  ft_lstiter.c\
  ft_lstmap.c\
  ft_realloc.c\
  ft_free_and_res.c\
  ft_memstring.c\
  ft_strcspn.c\
  ft_str_contain_only.c\
  ft_putin.c\
  ft_cut_before_last_cara.c\
  ft_int_tab.c\
  ft_sort_argv.c\
  argv_to_tab.c\
  argv_without_option.c\

SRC_DIR = srcs/

SRC = $(addprefix $(SRC_DIR), $(FUNC))

OBJS = $(FUNC:.c=.o)

NAME = libft.a

FLAG = -Wall -Wextra -Werror

CC = gcc

HEADERS = includes/

$(NAME) : $(SRC) Makefile $(HEADERS)libft.h
	@$(CC) $(CFLAG) -I$(HEADERS) -c $(SRC)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "$(NAME) have been made"

all: $(NAME)

clean : 
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re:  fclean all
