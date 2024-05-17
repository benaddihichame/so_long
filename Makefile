OBJECTS = \
	src/main.o \
	src/get_map.o \
	src/check_ext.o \
	src/check_map.o \
	src/affichage.o

LIBFT = lib/libft.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra -Iinclude -Imlx42/include/MLX42 -g
LFLAGS = -Llib -lft -lmlx42 -ldl -lglfw

NAME = so_long

all: $(NAME)

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
