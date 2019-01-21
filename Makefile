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

NAME := libftprintf.a

PFDIR := ft_printf/
PF :=   create_struct	find_specifier		ft_printf	get_value	handling_specifier \
		type_a		type_c		type_di		type_e		type_f		type_g		type_oux \
		type_p		type_percent	type_s    \

LSTDIR := ft_lst/
LST :=	ft_lstadd	ft_lstdel	ft_lstdelone	ft_lstiter	ft_lstlen	ft_lstmap \
		ft_lstnew	ft_lstpush \

MEMDIR := ft_mem/
MEM :=	ft_bzero	ft_memalloc		ft_memcpy	ft_memccpy	ft_memchr	ft_memcmp	ft_memdel \
		ft_memmove	ft_memset \

STRDIR := ft_str/
STR :=	ft_atoi		ft_close_file	ft_intlen	ft_isalnum	ft_isalpha	ft_isascii	ft_isdigit	\
		ft_isprint	ft_itoa_base	ft_itoa		ft_power	ft_putchar_fd			ft_putchar	\
		ft_putendl	ft_putendl_fd	ft_putnbr	ft_putnbr_fd	ft_putstr_fd		ft_putstr	\
		ft_putstrc	ft_range	ft_read_file	ft_sqrt			ft_strcat			ft_strchr	\
		ft_strclr	ft_strcmp	ft_strcpy		ft_strdel		ft_strdup			ft_strequ	\
		ft_striter	ft_striteri	ft_strjoin_free	ft_strjoin		ft_strlcat			ft_strlen	\
		ft_strmap	ft_strmapi	ft_strncat		ft_strncmp		ft_strncpy			ft_strnequ	\
		ft_strnew	ft_strnstr	ft_strpbrk		ft_strrchr		ft_strsplit			ft_strstr	\
		ft_strsub	ft_strtoupper	ft_strtrim	ft_tolower		ft_toupper			ft_uitoa_base	\
		get_next_line \

COMPILE := gcc -Wall -Wextra -Werror
OBJDIR := obj/
SRCDIR := srcs/
INCDIR := includes/

FILES := $(addprefix $(PFDIR),$(PF))
FILES += $(addprefix $(LSTDIR),$(LST))
FILES += $(addprefix $(MEMDIR),$(MEM))
FILES += $(addprefix $(STRDIR),$(STR))

SRC := $(addprefix $(SRCDIR),$(addsuffix .c,$(FILES)))
OBJ := $(addprefix $(OBJDIR),$(addsuffix .o,$(FILES)))

OBJMKDIR := .cache_exists

all: $(NAME)

$(OBJMKDIR):
	@echo "Creating object files directories..."
	@mkdir $(OBJDIR)
	@mkdir $(OBJDIR)$(PFDIR)
	@mkdir $(OBJDIR)$(LSTDIR)
	@mkdir $(OBJDIR)$(MEMDIR)
	@mkdir $(OBJDIR)$(STRDIR)
	@touch $(OBJMKDIR)
	@echo "OK!"

$(OBJDIR)%.o: $(SRCDIR)%.c | $(OBJMKDIR)
	@$(COMPILE) -I $(INCDIR) -c $< -o $@

$(NAME): $(OBJ)
	@echo "Compiling library..."
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "OK!"

clean:
	@echo "Deleting object files..."
	@rm -rf $(OBJDIR)
	@rm -f $(OBJMKDIR)
	@echo "OK!"

fclean: clean
	@echo "Deleting library binary..." 
	@rm -f $(NAME)
	@echo "OK!"

re: fclean
	@$(MAKE) all

test: all
	@$(COMPILE) -g -w -I $(INCDIR) main.c $(SRC) -L -lftprintf -o test
	@#./test