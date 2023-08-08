NAME = push_swap

SRC_C = main.c parsing.c utils.c stacks.c
SRC_DIR = 
SRC = $(addprefix $(SRC_DIR), $(SRC_C))

OPERATIONS_C = operation1.c operation2.c
OPERATIONS_DIR = ./operations/
OPERATIONS_SRC = $(addprefix $(OPERATIONS_DIR), $(OPERATIONS_C))

FLAGS = #-Wall -Wextra -Werror
INCLUDE = #-fsanitize=address -g

OBJ_DIR = ./objects/
OBJ = $(addprefix $(OBJ_DIR), $(SRC_C:.c=.o)) $(addprefix $(OBJ_DIR), $(OPERATIONS_C:.c=.o))

GREEN='\033[32m'
LIGHT_BLUE='\033[1;36m'
NONE='\033[0m'
BLUE='\033[0;34m'

all: $(NAME)

$(NAME): $(OBJ)
	@gcc $(FLAGS) $(OBJ) $(LIBFT) $(INCLUDE) -o $(NAME)
	@echo $(GREEN)"- Compiled -"$(NONE)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@gcc $(FLAGS) -c $< -o $@

$(OBJ_DIR)%.o: $(OPERATIONS_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@gcc $(FLAGS) -c $< -o $@

clean:
	@echo $(BLUE)"- Cleaning Push_Swap -"$(NONE)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all
