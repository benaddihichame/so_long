/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxborde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:05:11 by maxborde          #+#    #+#             */
/*   Updated: 2023/12/18 14:05:13 by maxborde         ###   ########.fr       */
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
    void *sol;
    void *pokeball;
    void *porte;
    void *arbre;
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
    int     map_colone;
    int     map_exit;
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

#endif
