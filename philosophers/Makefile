
NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -O2 -g
SRC_DIR = ./src/
INC_DIR = ./includes/
SRC_FILES = main.c init.c init_2.c utils.c utils_2.c monitor.c routine.c routine_2.c threads.c

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
INC = -I$(INC_DIR)
OBJ = $(SRC:.c=.o)
RM = rm -rf

RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
CYAN = \033[36m
BOLD = \033[1m
ERASE = \033[2K\r
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(INC) -o $(NAME)
	@printf "$(ERASE)$(GREEN)Program $(CYAN)$(BOLD)$(NAME)$(RESET) $(GREEN)created!\n$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@
	@printf "$(ERASE)$(BLUE) > Compilation: $(RESET) $<\n"

clean:
	@printf "$(ERASE)$(GREEN)Cleaning up...$(RESET)\n"
	@$(RM) $(OBJ)
	@printf "$(ERASE)$(GREEN)Clean finished!$(RESET)\n"

fclean: clean
	@printf "$(ERASE)$(GREEN)Fcleaning up...$(RESET)\n"
	@$(RM) $(NAME)
	@printf "$(ERASE)$(GREEN)Fclean finished!$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re
.SILENT:
