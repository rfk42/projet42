NAME = so_long

SRC =	main.c \
		parsing.c \
		parsing_utils.c \
		parsing_utils2.c \
		moves.c \
		moves2.c \
		init.c \
		free.c \
		exit.c \

CC = cc

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g3

RM = rm -f

all : $(NAME)

$(NAME) : $(OBJ)
	make  -C Libft
	make -C mlx
	$(CC) $(CFLAGS) $^  Libft/libft.a mlx/libmlx.a -lXext -lX11 -o  $@
	
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean :
	$(RM) $(OBJ)
fclean : clean
	$(RM) $(NAME)

re : fclean all
