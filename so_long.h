/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 13:06:49 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/03/12 14:24:29 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

///////////les lib//////////////////
# include "includes/printf/ft_printf.h"
# include "includes/mygnl/get_next_line.h"
# include "includes/libft/libft.h"
# include "includes/MLX42/include/MLX42/MLX42.h"
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define WIDTH 32
# define HEIGHT 32

typedef struct s_texture
{
    void *sol;
    void *pokeball;
    void *porte;
    void *arbre;
}   t_texture;

typedef struct mlxd
{
    void    *mlx;
    void    *window;
};

typedef struct s_game
{
    char **map;
    int map_colone;
    int map_exit;


} t_game;

typedef struct s_player
{
    int x;
    int y;
}   t_player;

int is_valid(char *str);
void get_map(char *file_name, t_game *game);
static int check_wall(t_game *game, int linecount);
static int  check_last_row(char *line);

#endif