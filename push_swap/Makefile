# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhamini <rhamini@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/21 11:36:57 by rhamini           #+#    #+#              #
#    Updated: 2024/05/07 15:32:34 by rhamini          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap

SRC_DIR := src

OBJ_DIR := obj

SRCS := main.c \
    	operator.c \
    	operator_2.c \
    	utils.c \
		lst_utils.c \
		check.c \
		sort_utils.c \
		sort_utils_2.c \
		sort.c \
		lst_mediane.c \

SRCS := $(SRCS:%=$(SRC_DIR)/%)

OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC          := cc
CFLAGS      := -Wall -Wextra -Werror

RM          := rm -f
MAKEFLAGS   += --no-print-directory
DIR_DUP     = mkdir -p $(@D)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)
	$(info CREATED $(NAME))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) -c -o $@ $<
	$(info CREATED $@)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

