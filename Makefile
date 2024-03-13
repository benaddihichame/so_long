NAME := so_long

SRC := fonction/main.c fonction/testmap.c fonction/get_map.c

LIBFT_DIR = includes/libft
FT_PRINTF_DIR = includes/ft_printf
GET_NEXT_LINE_DIR = includes/mygnl

OBJ := $(SRC:.c=.o)

CFLAGS := -g -Iincludes
LDFLAGS := -Llib -lmlx42 -lftprintf -ldl -lglfw -pthread -lm

.PHONY: all clean fclean re

%.o:		%.c
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJ)
			$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

all:		$(NAME)

clean:
			$(RM) -f $(OBJ)

fclean:		clean
			$(RM) -f $(NAME)

re:			fclean all

