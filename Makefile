# Variables
CC = gcc
CFLAGS = -Wall -Werror -Wextra -Iinclude -Imlx42/include/MLX42 -g3
LFLAGS = -Llib -lft -lmlx42 -ldl -lglfw
NAME = so_long
SRC_DIR = src
OBJ_DIR = obj

# Fichiers sources et objets
SRCS = $(SRC_DIR)/affichage.c $(SRC_DIR)/check_ext.c $(SRC_DIR)/check_map.c $(SRC_DIR)/err.c $(SRC_DIR)/get_map.c $(SRC_DIR)/main.c $(SRC_DIR)/moove.c # Ajoutez tous vos fichiers source ici
OBJS = $(OBJ_DIR)/affichage.o $(OBJ_DIR)/check_ext.o $(OBJ_DIR)/check_map.o $(OBJ_DIR)/err.o $(OBJ_DIR)/get_map.o $(OBJ_DIR)/main.o $(OBJ_DIR)/moove.o  # Correspondance des fichiers objets

LIBFT_DIR = lib
LIBFT = $(LIBFT_DIR)/libft.a

# Règles
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Règle pour construire libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Nettoyage des fichiers objets
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

# Nettoyage complet
fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

# Reconstruire entièrement
re: fclean all

.PHONY: all clean fclean re
