OBJECTS = \
	src/main.c \
	src/get_map.c \
	src/check_ext.c

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
	make clean -C lib
	rm $(OBJECTS)

fclean: clean
	make fclean -C lib
	rm $(NAME)

re: fclean all
	make fclean -C lib

.PHONY: all clean fclean re

