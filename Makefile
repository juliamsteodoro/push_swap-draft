NAME          = push_swap

CC            = cc
CFLAGS        = -Wall -Wextra -Werror

INC_DIR       = includes/
OBJ_DIR       = obj/

SRC_FILES     = main.c \
                main.utils.c \
                algorithm_selector.c \
                utils_algorithm_selector.c \
                sort_small.c \
                sort_small_utils.c \
                sort_large.c \
                bench_operations.c \
                bench_utils.c \
                push.c \
                reverse.c \
                rotate.c \
                swap.c \
                parsing.c \
                split_parsing.c \
                utils_parsing.c \
                stack_lifecycle.c \
                utils_stack.c

OBJ_FILES     = $(SRC_FILES:%.c=$(OBJ_DIR)%.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME)

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re