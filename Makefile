# ==============================================================================
#                                  VARIABLES
# ==============================================================================

NAME          = push_swap

CC            = cc
CFLAGS        = -Wall -Wextra -Werror

BASE_DIR      = organizacao/
SRC_DIR       = $(BASE_DIR)src/
INC_DIR       = $(BASE_DIR)includes/
OBJ_DIR       = obj/

ALGO_DIR      = $(SRC_DIR)algorithms/
OP_DIR        = $(SRC_DIR)operations/
PARSE_DIR     = $(SRC_DIR)parsing/
STACK_DIR     = $(SRC_DIR)stack/

SRC_FILES     = $(SRC_DIR)main.c \
                $(SRC_DIR)main.utils.c \
                $(ALGO_DIR)algorithm_selector.c \
                $(ALGO_DIR)utils_algorithm_selector.c \
                $(ALGO_DIR)sort_small.c \
                $(ALGO_DIR)sort_small_utils.c \
                $(ALGO_DIR)sort_large.c \
                $(ALGO_DIR)bench_operations.c \
                $(ALGO_DIR)bench_utils.c \
                $(OP_DIR)push.c \
                $(OP_DIR)reverse.c \
                $(OP_DIR)rotate.c \
                $(OP_DIR)swap.c \
                $(PARSE_DIR)parsing.c \
                $(PARSE_DIR)split_parsing.c \
                $(PARSE_DIR)utils_parsing.c \
                $(STACK_DIR)stack_lifecycle.c \
                $(STACK_DIR)utils_stack.c


OBJ_FILES     = $(patsubst $(BASE_DIR)%.c, $(OBJ_DIR)%.o, $(SRC_FILES))

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME)

$(OBJ_DIR)%.o: $(BASE_DIR)%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re