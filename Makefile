NAME = push_swap

LIB_DIR = ./libft
LIB = $(LIB_DIR)/libft.a
INC_PSW = ./includes

HEADER_PSW = $(INC_PSW)/push_swap.h

# dirs
DIR_S = source
DIR_O = objects

# files
C_FILES = ft_atol.c\
		  operations.c\
		  rotate_operations.c\
		  push_and_swap_operations.c\
		  sync_rotate_operatoins.c\
		  push_swap.c\
		  t_base_utils.c\
		  sorting.c\
		  optimal_rotations.c\
		  rotations_optimizators.c\
		  shortest_operatoin_list.c\
		  utils.c\
		  t_element_utils_part_one.c\
		  t_element_utils_part_two.c\
		  t_element_utils_part_three.c\
		  validate_args.c\
		  validate_values.c\

SRCS = $(addprefix $(DIR_S)/,$(C_FILES))
OBJS = $(addprefix $(DIR_O)/,$(C_FILES:.c=.o))

# flags
CC = gcc
FLAGS = -Wall -Werror -Wextra -g
INC_LIBS = -L $(LIB_DIR) -lft
INC_HEADERS = -I $(INC_PSW) -I $(LIB_DIR)

.PHONY: all clean fclean re lib

all: $(NAME)

$(NAME): $(DIR_O) $(LIB) $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(INC_HEADERS) $(INC_LIBS) -o $@

$(DIR_O):
	mkdir -p $(DIR_O)

$(LIB):
	make -C ./libft

$(DIR_O)/%.o: $(DIR_S)/%.c $(HEADER_PSW)
	$(CC) $(FLAGS) -I $(INC_PSW) -I $(LIB_DIR) -c ./$< -o $@

clean:
	rm -rf $(DIR_O)
	make -C ./libft fclean

fclean: clean
	rm -f $(NAME)

re: fclean all