/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:05:11 by maxborde          #+#    #+#             */
/*   Updated: 2024/05/14 12:17:31 by hbenaddi         ###   ########.fr       */
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
    mlx_texture_t *sol;
    mlx_texture_t *pokeball;
    mlx_texture_t *porte;
    mlx_texture_t *arbre;
    mlx_texture_t *grass;
} t_game;


int is_valid(char *str);
void get_map(char *file_name, t_game *game);
int ultimate_check(char **argv, t_game *game);
int count_line(char *file_name);


#endif
