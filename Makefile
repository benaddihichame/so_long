# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbenaddi <hbenaddi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/10 20:30:41 by hbenaddi          #+#    #+#              #
#    Updated: 2024/06/10 20:30:44 by hbenaddi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra -Iinclude -Imlx42/include/MLX42 -g3
LFLAGS = -Llib -lft -lmlx42 -ldl -lglfw
NAME = so_long
SRC_DIR = src
OBJ_DIR = obj

SRCS = $(SRC_DIR)/display_stuff.c $(SRC_DIR)/check_ext.c $(SRC_DIR)/check_map.c $(SRC_DIR)/err.c $(SRC_DIR)/get_map.c $(SRC_DIR)/main.c $(SRC_DIR)/moove.c $(SRC_DIR)/back_track.c $(SRC_DIR)/loading_texture.c $(SRC_DIR)/event.c $(SRC_DIR)/verif_map.c
OBJS = $(OBJ_DIR)/display_stuff.o $(OBJ_DIR)/check_ext.o $(OBJ_DIR)/check_map.o $(OBJ_DIR)/err.o $(OBJ_DIR)/get_map.o $(OBJ_DIR)/main.o $(OBJ_DIR)/moove.o $(OBJ_DIR)/back_track.o $(OBJ_DIR)/loading_texture.o $(OBJ_DIR)/event.o $(OBJ_DIR)/verif_map.o

LIBFT_DIR = lib
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
