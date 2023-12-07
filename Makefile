NAME := philo
NAME_BONUS := philo_bonus

CC := gcc
CFLAGS := -Wall -Werror -Wextra

SRC_DIR := src
SRC_BONUS_DIR := src_bonus
OBJ_DIR := obj
INC_DIR := include
INC_BONUS_DIR := include_bonus

SRCS := $(wildcard $(SRC_DIR)/*.c)
SRCS_BONUS := $(wildcard $(SRC_BONUS_DIR)/*.c)
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJS_BONUS := $(SRCS_BONUS:$(SRC_BONUS_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -I$(INC_DIR)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) -I$(INC_BONUS_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_BONUS_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_BONUS_DIR) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all bonus clean fclean re
