/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:05:11 by maxborde          #+#    #+#             */
/*   Updated: 2024/05/15 21:24:41 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42.h"
# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define PIXEL 32
# define TRUE 1
# define FALSE 0

typedef struct s_game
{
    mlx_t   mlx;
    char    **map;
    int     fd;
    char    player;
    char    exit;
    char    collectible;
    int     vide;
    int     x;
    int     y;
    mlx_texture_t *ecto;
    mlx_texture_t *pokeball;
    mlx_texture_t *door;
    mlx_texture_t *arbre;
    mlx_texture_t *grass;
} t_game;


int is_valid(char *str);
void get_map(char *file_name, t_game *game);
int count_line(char *file_name);
int verif_element(t_game *game);
int  is_rectang(char **map);
int is_wall(t_game *game);

#endif
