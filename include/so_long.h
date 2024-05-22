/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:05:11 by maxborde          #+#    #+#             */
/*   Updated: 2024/05/22 12:03:19 by hbenaddi         ###   ########.fr       */
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

typedef struct s_mlx_img
{
    mlx_image_t     *img;
    mlx_texture_t   *texture;
}            t_mlx_img;


typedef struct s_game
{
    mlx_t       *mlx;
    t_mlx_img   *tab_png;
    char    **map;
    int     fd;
    char    player;
    char    exit;
    char    collectible;
    int     vide;
    int     x;
    int     y;
} t_game;


int is_valid(char *str);
void get_map(char *file_name, t_game *game);
int count_line(char *file_name);
int verif_element(t_game *game);
int  is_rectang(char **map);
int	is_wall(char **map);
void loading_png(t_game *game);
void display(t_game *game);


#endif
