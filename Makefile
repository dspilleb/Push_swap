NAME = push_swap

SRC_C = main.c parsing.c
SRC_DIR = 
SRC = $(addprefix $(SRC_DIR), $(SRC_C))


LIBFT_A = libft.a
LIBFT_DIR = ./My_Libft/
LIBFT = $(addprefix $(LIBFT_DIR), $(LIBFT_A))

FLAGS = #-Wall -Wextra -Werror
INCLUDE = #-fsanitize=address -g

OBJ = *.o

GREEN='\033[32m'
LIGHT_BLUE='\033[1;36m'
NONE='\033[0m'
BLUE='\033[0;34m'

all: $(NAME)

$(NAME): $(OBJ)
	@echo $(LIGHT_BLUE)"- Compiling LIBFT -"$(NONE)
	@make -C $(LIBFT_DIR)
	@gcc $(FLAGS) $(OBJ) $(LIBFT) $(INCLUDE) -o $(NAME)
	@echo $(GREEN)"- Compiled -"$(NONE)

$(OBJ): $(SRC)
	@gcc $(FLAGS) -c $(SRC)

push_clean:
	@echo $(BLUE)"- cleaning Push_Swap -"$(NONE)
	@rm -rf $(OBJ)

clean:
	@echo $(BLUE)"- cleaning Push_Swap -"$(NONE)
	@rm -rf $(OBJ)
	@echo $(LIGHT_BLUE)"cleaning LIBFT -"$(NONE)
	@make -C $(LIBFT_DIR) clean

fclean: push_clean
	@rm -rf $(NAME)
	@echo $(LIGHT_BLUE)"- cleaning LIBFT -"$(NONE)
	@make -C $(LIBFT_DIR) fclean

re: fclean all