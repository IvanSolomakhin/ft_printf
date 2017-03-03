# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isolomak <isolomak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/02 18:05:10 by isolomak          #+#    #+#              #
#    Updated: 2017/03/03 16:56:02 by isolomak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FILES = ft_atoi.c \
		ft_bzero.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_freejoin.c \
		ft_lstadd.c \
		ft_lstdel.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstnew.c \
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
		ft_putendl.c \
		ft_putendl_fd.c \
		ft_putnbr.c \
		ft_putnbr_fd.c \
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
		ft_strnequ.c \
		ft_strnew.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strsplit.c \
		ft_strstr.c \
		ft_strsub.c \
		ft_strtrim.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_strrev.c \
		ft_swap.c \
		ft_strtoupper.c \
		ft_strtolower.c \
		ft_sort_int.c \
		ft_itoa_base.c \
		get_next_line.c

FLAGS = -Wall -Wextra -Werror

OBJECTS = $(FILES:.c=.o)

CC = gcc

IN = ./

FLAGS = -Wall -Wextra -Werror

all:$(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -I $(IN) -c $< -o $@
	@echo "Compile $<" '\r\c'

$(NAME): $(OBJECTS)
	@echo "                                        "'\r\c' 
	@echo "Compiled"
	@$(AR) -rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@echo "Libft Created"

clean:
	@rm -rf $(OBJECTS)
	@echo "All .o deleted"

fclean: clean
	@rm -rf $(NAME)
	@echo "Libft clean as ass that you don't have to wipe"

re: clean all