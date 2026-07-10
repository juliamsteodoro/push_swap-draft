# ==============================================================================
#                                  VARIABLES
# ==============================================================================

NAME          = push_swap

CC            = cc
CFLAGS        = -Wall -Wextra -Werror

# Diretórios base
BASE_DIR      = organizacao/
SRC_DIR       = $(BASE_DIR)src/
INC_DIR       = $(BASE_DIR)includes/
OBJ_DIR       = obj/

# Subdiretórios
ALGO_DIR      = $(SRC_DIR)algorithms/
OP_DIR        = $(SRC_DIR)operations/
PARSE_DIR     = $(SRC_DIR)parsing/
STACK_DIR     = $(SRC_DIR)stack/

# Arquivos fonte (CAMINHOS CORRETOS)
SRC_FILES     = $(SRC_DIR)main.c \
                $(ALGO_DIR)algorithm_selector.c \
                $(ALGO_DIR)sort_small.c \
                $(ALGO_DIR)sort_large.c \
                $(OP_DIR)push.c \
                $(OP_DIR)reverse.c \
                $(OP_DIR)rotate.c \
                $(OP_DIR)swap.c \
                $(PARSE_DIR)parsing.c \
                $(PARSE_DIR)utils_parsing.c \
                $(STACK_DIR)stack_lifecycle.c \
                $(STACK_DIR)utils_stack.c

# Objetos espelhando a estrutura dentro de obj/
OBJ_FILES     = $(patsubst $(BASE_DIR)%.c, $(OBJ_DIR)%.o, $(SRC_FILES))

# ==============================================================================
#                                    RULES
# ==============================================================================

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME)

# Regra genérica de compilação
$(OBJ_DIR)%.o: $(BASE_DIR)%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re