OBJECTS = \
	src/main.o \
	src/get_map.o \
	src/check_ext.o \
	src/check_map.o \
	src/affichage.o

LIBFT = lib/libft.a

banner:
	@echo "\n"
	@echo "⏳ Files are being compiled. ⏳  \n"
	@echo "888      .d88888b.        d8888 8888888b. 8888888 888b    888  .d8888b."
	@echo "888     d88P   Y88b      d88888 888   Y88b  888   8888b   888 d88P  Y88b"
	@echo "888     888     888     d88P888 888    888  888   88888b  888 888    888"
	@echo "888     888     888    d88P 888 888    888  888   888Y88b 888 888"
	@echo "888     888     888   d88P  888 888    888  888   888 Y88b888 888  88888"
	@echo "888     888     888  d88P   888 888    888  888   888  Y88888 888    888"
	@echo "888     Y88b. .d88P d8888888888 888  .d88P  888   888   Y8888 Y88b  d88P"
	@echo "88888888  Y88888P  d88P     888 8888888P  8888888 888    Y888  Y8888P88"
	@echo "\n"
	@sleep 1

CC = gcc
CFLAGS = -Wall -Werror -Wextra -Iinclude -Imlx42/include/MLX42 -g
LFLAGS = -Llib -lft -lmlx42 -ldl -lglfw

NAME = so_long

all: banner $(NAME)

$(NAME): $(OBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME) $(LFLAGS) 

$(LIBFT):
	$(MAKE) -C lib

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C lib
	rm -f $(OBJECTS)

fclean: clean
	$(MAKE) fclean -C lib
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
