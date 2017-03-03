# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isolomak <isolomak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/27 15:47:56 by isolomak          #+#    #+#              #
#    Updated: 2017/03/03 16:58:36 by isolomak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= libftprintf.a
CC		= gcc
FLAGS	= -Wall -Wextra -Werror
SRC		= 	args.c \
			checks.c \
			create_stuff.c \
			flags.c \
			ft_printf.c \
			hash_sign_space.c \
			length.c \
			manage_nbr.c \
			manage_ptr.c \
			manage_str.c \
			manage_type.c \
			precision.c \
			process.c \
			put_wchar.c \
			read_data.c \
			width.c

OBJ		= $(SRC:.c=.o)

IN = ./

all: $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -I $(IN) -c $< -o $@
	@echo "Compile $<                   \r\c"

$(NAME): $(OBJ)
	@make -C libft/
	@mv libft/libft.a ./$(NAME)
	@$(AR) -rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "Printf Created"

clean :
	@make clean -C libft/
	@rm -rf $(OBJ)

fclean : clean
	@make fclean -C libft/
	@rm -rf $(NAME)

re : clean all
