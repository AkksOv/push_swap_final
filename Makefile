# Nom de l'exécutable final
NAME = push_swap
BONUS_NAME = checker

# Répertoires contenant les bibliothèques et les sources
PRINTF_DIR = printf
UTILS_DIR = utils
CHECKER_DIR = checker_bonus
GNL_DIR = $(CHECKER_DIR)/GetNextLine

# Bibliothèques compilées
PRINTF_LIB = $(PRINTF_DIR)/printf.a
UTILS_LIB = $(UTILS_DIR)/utils.a
GNL_LIB = $(GNL_DIR)/get_next_line.a

# Fichiers source et objets du programme principal
SRCS = main.c
BONUS_SRCS = $(CHECKER_DIR)/checker.c
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

# Inclusion des headers
INCLUDES = -I $(PRINTF_DIR) -I $(UTILS_DIR) -I $(GNL_DIR)

# Compiler et options
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Règle principale pour construire l'exécutable
all:  $(PRINTF_LIB) $(UTILS_LIB) $(NAME)

# Construction de l'exécutable final (push_swap)
$(NAME): $(OBJS) $(PRINTF_LIB) $(UTILS_LIB)
	$(CC) $(CFLAGS) $(OBJS) -L$(UTILS_DIR) $(UTILS_LIB) -L$(PRINTF_DIR) $(PRINTF_LIB) -o $(NAME)
	@echo "Exécutable $(NAME) créé avec succès !"

# Construction de l'exécutable bonus (Checker)
bonus: $(BONUS_OBJS) $(PRINTF_LIB) $(UTILS_LIB) $(GNL_LIB)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -L$(UTILS_DIR) $(UTILS_LIB) -L$(PRINTF_DIR) $(PRINTF_LIB) -L$(GNL_DIR) $(GNL_LIB) -o $(BONUS_NAME)
	@echo "Exécutable $(BONUS_NAME) créé avec succès !"

# Compilation des fichiers objets du programme principal
$(UTILS_DIR)/%.o: $(UTILS_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(PRINTF_DIR)/%.o: $(PRINTF_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Compilation des fichiers objets pour le bonus
$(CHECKER_DIR)/%.o: $(CHECKER_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Construction des bibliothèques
$(UTILS_LIB):
	@make -C $(UTILS_DIR)

$(PRINTF_LIB):
	@make -C $(PRINTF_DIR)

$(GNL_LIB):
	@make -C $(GNL_DIR)

# Nettoyage des fichiers objets et des bibliothèques
clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	@make -C $(UTILS_DIR) clean
	@make -C $(PRINTF_DIR) clean
	@make -C $(GNL_DIR) clean
	@echo "Fichiers objets et fichiers temporaires supprimés."

# Nettoyage complet (objets + exécutable + bibliothèques)
fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	@make -C $(UTILS_DIR) fclean
	@make -C $(PRINTF_DIR) fclean
	@make -C $(GNL_DIR) fclean
	@echo "Exécutable et bibliothèques supprimés."

# Recompilation complète
re: fclean all

# Règles d'usage
.PHONY: all bonus clean fclean re
