NAME = philosophers
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src/
INC_DIR = include/
OBJ_DIR = obj/

SRCS = $(addprefix $(SRC_DIR), init.c my_time.c routines.c main.c print_status.c timings.c ft_atoi.c mrclean.c)
OBJS = $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I $(INC_DIR) $(OBJS) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
