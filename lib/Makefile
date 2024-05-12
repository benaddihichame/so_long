OBJECTS = \
	ft_isalpha.o \
	ft_isdigit.o \
	ft_isalnum.o \
	ft_isascii.o \
	ft_isprint.o \
	ft_strlen.o \
	ft_toupper.o \
	ft_strlcat.o \
	ft_tolower.o \
	ft_strlcpy.o \
	ft_memset.o \
	ft_bzero.o \
	ft_strncmp.o \
	ft_memmove.o \
	ft_memcpy.o \
	ft_memcmp.o \
	ft_strchr.o \
	ft_strrchr.o \
	ft_memchr.o \
	ft_atoi.o \
	ft_strnstr.o \
	ft_calloc.o \
	ft_strdup.o \
	ft_substr.o \
	ft_strmapi.o \
	ft_putchar_fd.o \
	ft_putstr_fd.o \
	ft_putendl_fd.o	\
	ft_putnbr_fd.o \
	ft_split.o \
	ft_itoa.o \
	ft_striteri.o \
	ft_strjoin.o \
	ft_strtrim.o \
	
BONUS_OBJECTS = \
	ft_lstnew_bonus.o \
	ft_lstadd_front_bonus.o \
	ft_lstsize_bonus.o \
	ft_lstlast_bonus.o \
	ft_lstadd_back_bonus.o \
	ft_lstdelone_bonus.o \
	ft_lstclear_bonus.o \
	ft_lstiter_bonus.o \
	ft_lstmap_bonus.o \

GNL_OBJECTS = \
	get_next_line.o \
	get_next_line_utils.o \

PRINTF_OBJECTS = \
	ft_hex.o \
	ft_letters.o \
	ft_numbers.o\
	ft_printf.o \
	ft_ptr.o

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.
AR = ar rcs

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJECTS) $(GNL_OBJECTS) $(PRINTF_OBJECTS)
	$(AR) $(NAME) $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	$(RM) $(OBJECTS) $(GNL_OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: $(OBJECTS) $(BONUS_OBJECTS) $(GNL_OBJECTS)
	$(AR) $(NAME) $^

.PHONY: all clean fclean re bonus
