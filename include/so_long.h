/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:05:11 by maxborde          #+#    #+#             */
/*   Updated: 2024/05/13 11:15:09 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42.h"
# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 32
# define HEIGHT 32

typedef struct s_texture
{
    struct mlx_texture *sol;
    void *pokeball;
    void *porte;
    void *arbre;
    void *grass;
}   t_texture;

typedef struct s_mlxd
{
    void    *mlx;
    void    *window;
}   t_mlx;

typedef struct s_game
{
    char    **map;
    char    player;
    char    exit;
    char    collectible;
    int     vide;
} t_game;

typedef struct s_player
{
    int x;
    int y;
}   t_player;

int is_valid(char *str);
void get_map(char *file_name, t_game *game);
size_t	my_strlen(char *s);
int ultimate_check(char **argv, t_game *game);

#endif