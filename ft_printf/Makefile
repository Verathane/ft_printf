# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbond <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/08 15:23:12 by nbond             #+#    #+#              #
#    Updated: 2017/01/25 20:16:03 by nbond            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libftprintf.a

FLAGS =		-Wall -Wextra -Werror

LDIR =		./libft

LIB =		$(LDIR)/libft.a

OBJ =		ft_printf.o \
			ft_printf_s.o \
			ft_printf_c.o \
			ft_printf_i.o \
			ft_printf_p.o \
			ft_printf_uni.o \
			helper_funcs.o \
			handler_funcs.o

all: $(NAME)

%.o: %.c
	gcc $(FLAGS) -c -o $@ $^

$(NAME): $(OBJ)
#	make -C $(LDIR)
	ar -rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
#	make clean -C $(LDIR)

fclean: clean
	rm -f $(NAME)
#	make fclean -C $(LDIR)

re: fclean all
