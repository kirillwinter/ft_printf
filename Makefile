# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wballaba <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/15 17:32:16 by wballaba          #+#    #+#              #
#    Updated: 2018/12/25 22:55:14 by jwillem-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a

SRCS =	srcs/main.c \
		srcs/ft_printf.c \
		srcs/create_struct.c \
		srcs/get_value.c \
		srcs/find_specifier.c \
		srcs/type_di.c \
		srcs/type_c.c \
		srcs/type_s.c \
		srcs/type_p.c \
		srcs/type_ouxX.c \
        srcs/ft_uitoa_base.c \

OBJ = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

LIBFT = ./libft/libftprintf.a
INC = -I ./includes
LIBLINK = -L ./libft -lftprintf
LIBINC = -I ./libft/includes

all: $(NAME) 

%.o:%.c
	@$(CC) $(CFLAGS) $(LIBINC) $(INC) -o $@ -c $<

libft: $(LIBFT)

$(LIBFT):
	@echo "Compiling libft..."
	@make -C ./libft
	@echo "OK!"

$(NAME): libft $(OBJ)
	@echo "Compiling ft_printf..."
	@$(CC) $(LIBLINK) -o $(NAME) $(OBJ)
	@echo "OK!"

rmlib:
	@echo "Deleting libft object files and libft.a..."
	@make fclean -C ./libft
	@echo "OK!"

clean: rmlib
	@echo "Deleting ft_printf object files..."
	@rm -rf $(OBJ)
	@echo "OK!"

fclean: clean
	@echo "Deleting ft_printf..."
	@rm -rf $(NAME)
	@echo "OK!"

re: fclean all
