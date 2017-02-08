# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbond <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/01 20:29:31 by nbond             #+#    #+#              #
#    Updated: 2017/01/28 19:07:53 by nbond            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

OBJ =	ft_atoi.o \
		ft_bzero.o \
		ft_isalnum.o \
		ft_isalpha.o \
		ft_isascii.o \
		ft_isdigit.o \
		ft_isprint.o \
		ft_iswhitespace.o \
		ft_itoa.o \
		ft_itoa_base.o \
		ft_lstadd.o \
		ft_lstdel.o \
		ft_lstdelone.o \
		ft_lstiter.o \
		ft_lstmap.o \
		ft_lstnew.o \
		ft_memalloc.o \
		ft_memccpy.o \
		ft_memchr.o \
		ft_memcmp.o \
		ft_memcpy.o \
		ft_memdel.o \
		ft_memmove.o \
		ft_memset.o \
		ft_putchar.o \
		ft_putchar_fd.o \
		ft_putendl.o \
		ft_putendl_fd.o \
		ft_putnbr.o \
		ft_putnbr_fd.o \
		ft_putstr.o \
		ft_putstr_fd.o \
		ft_strcat.o \
		ft_strchr.o \
		ft_strclr.o \
		ft_strcmp.o \
		ft_strcpy.o \
		ft_strdel.o \
		ft_strdup.o \
		ft_strequ.o \
		ft_striter.o \
		ft_striteri.o \
		ft_strjoin.o \
		ft_strlcat.o \
		ft_strlen.o \
		ft_strmap.o \
		ft_strmapi.o \
		ft_strncat.o \
		ft_strncmp.o \
		ft_strncpy.o \
		ft_strnequ.o \
		ft_strnew.o \
		ft_strnstr.o \
		ft_strrchr.o \
		ft_strsplit.o \
		ft_strstr.o \
		ft_strsub.o \
		ft_strtrim.o \
		ft_swap.o \
		ft_tolower.o \
		ft_toupper.o \
		ft_intlen.o \
		ft_baselen.o \
		ft_nth_root.o \
		ft_factorial.o \
		ft_lstlast.o \
		ft_putnstr.o \
		ft_lstadd_back.o \
		ft_printf/ft_printf.o \
		ft_printf/ft_printf_s.o \
		ft_printf/ft_printf_c.o \
		ft_printf/ft_printf_i.o \
		ft_printf/ft_printf_p.o \
		ft_printf/ft_printf_uni.o \
		ft_printf/helper_funcs.o \
		ft_printf/handler_funcs.o

all: $(NAME)

%.o: %.c
	gcc $(FLAGS) -c -o $@ $< -I ./ft_printf

$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
