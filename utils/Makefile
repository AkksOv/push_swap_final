# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -std=c99 -g3

# Name of the library (since no main, we'll create a library instead)
LIBRARY = utils.a

# Source files
SRC = operations.c utils.c utils2.c utils3.c check_errors.c sort.c algo.c split.c tools.c sort_three.c push_b_to_a.c free_func.c intmax.c

# Object files (generated from the source files)
OBJ = $(SRC:.c=.o)

# Default rule: Build the static library
all: $(LIBRARY)

# Rule to create the static library (liblist.a)
$(LIBRARY): $(OBJ)
	ar rcs $(LIBRARY) $(OBJ)

# Rule to compile each .c file to .o file
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up the generated object files and the library
clean:
	rm -f $(OBJ) $(LIBRARY)

# Clean and then rebuild everything
fclean: clean

# Rebuild everything (clean + build the library)
re: fclean all