CC = c++

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -std=c++98

PRGM_NAME = megaphone

SRC = megaphone.cpp

OBJ = $(SRC:.cpp=.o)

all: $(PRGM_NAME)

$(PRGM_NAME): $(OBJ)
	$(CC) -o $(PRGM_NAME) $(SRC) $(CFLAGS) 

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(PRGM_NAME)

re: fclean all

.PHONY: all clean fclean re