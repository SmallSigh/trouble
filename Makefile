# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

# Directories
SRC_DIRS = inc/gnl inc/ft_printf inc/libft inc/src better worse ascii tools
INC_DIRS = $(addprefix -I, $(SRC_DIRS))
OBJ_DIR = o_files

# Source files
SRC_FILES = $(wildcard $(addsuffix /*.c, $(SRC_DIRS)))
OBJ_FILES = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

# Output executable
NAME = run

# Default target
all: $(NAME)

# Create object directory
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Link object files to create the executable
$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME)

# Compile source files into object files
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	mkdir -p $(dir $@)  # Ensure subdirectories exist
	$(CC) $(CFLAGS) $(INC_DIRS) -c $< -o $@

# Clean up build files
clean:
	rm -rf $(OBJ_DIR)

# Clean up everything
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re
