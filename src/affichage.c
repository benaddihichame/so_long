/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:47:18 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/05/15 17:06:58 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void loading_png(t_game *game)
{   
    int i;

    i = 0;
    game->grass = mlx_load_png("./image/grass.png");
    game->collectible = mlx_load_png("./image/pokeball.png");
    game->arbre = mlx_load_png("./image/arbre.png");
    game->ecto = mlx_load_png("./image/ecto.png");
    game->door = mlx_load_png("./image/door.png");
}
void loading_texture(t_game *game)
{
    
}