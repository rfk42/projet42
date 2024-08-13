CC = gcc 
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -I./includes
SERVER_NAME = server
CLIENT_NAME = client 
SERVER_SRCS = ./src/server.c ./src/utils/utils.c ./src/utils/utils2.c
CLIENT_SRCS = ./src/client.c ./src/utils/utils.c ./src/utils/utils2.c
SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)


all: $(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_NAME): $(SERVER_OBJS)
	$(CC) -o $(SERVER_NAME) $(SERVER_SRCS) $(CFLAGS) 

$(CLIENT_NAME): $(CLIENT_OBJS) 
	$(CC) -o $(CLIENT_NAME) $(CLIENT_SRCS) $(CFLAGS)

clean:
	$(RM) $(SERVER_OBJS) $(CLIENT_OBJS)

fclean: clean
	$(RM) $(SERVER_NAME) $(CLIENT_NAME)

re: fclean all

.PHONY: all clean fclean re