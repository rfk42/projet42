# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 11:16:21 by rhamini           #+#    #+#              #
#    Updated: 2024/01/03 21:14:13 by rhamini          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

NAME = libftprintf.a

CFLAGS = -Werror -Wextra -Wall

LIBNAME = libft.a
LIBPATH = ./Libft

FILES = 	ft_printf.c \
			ft_prints.c \
			ft_printui.c \
			ft_printd.c \
			ft_printchar.c \
			ft_printptr.c \
			ft_printhex.c \

OBJS = ${FILES:.c=.o}

all: $(NAME)

makelibft:
	@make -C $(LIBPATH)
	@cp $(LIBPATH)/$(LIBNAME) ./
	@mv $(LIBNAME) $(NAME)

${NAME}: makelibft ${OBJS}
		ar rcs ${NAME} ${OBJS}

clean:
	@rm -f $(OBJS)
	@cd $(LIBPATH) && make clean
	
fclean: clean
	@rm -f $(NAME)
	@cd $(LIBPATH) && make fclean
	
re: fclean all
