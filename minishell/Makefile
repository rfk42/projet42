CC = gcc 
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -lreadline -I./includes
SHELL_NAME = shell
SHELL_SRCS = ./srcs/minishell.c ./srcs/utils.c ./srcs/utils2.c 
SHELL_OBJS = $(SHELL_SRCS:.c=.o)

all: $(SHELL_NAME)

$(SHELL_NAME): $(SHELL_OBJS)
	$(CC) -o $(SHELL_NAME) $(SHELL_SRCS) $(CFLAGS) 

clean:
	$(RM) $(SHELL_OBJS)

fclean: clean
	$(RM) $(SHELL_NAME)

re: fclean all

.PHONY: all clean fclean re