/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:47:18 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/05/16 22:05:01 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void loading_png(t_game *game)
{
    int i;

    i = 0;  
    game->tab_png[0].texture = mlx_load_png("./image/grass.png");
    game->tab_png[1].texture = mlx_load_png("./image/pokeball.png");
    game->tab_png[2].texture = mlx_load_png("./image/arbre.png");
    game->tab_png[3].texture = mlx_load_png("./image/ecto.png");
    game->tab_png[4].texture = mlx_load_png("./image/door.png");

    while (i < 5)
    {
        game->tab_png[i].img = mlx_texture_to_image(game->mlx, game->tab_png[i].texture);
        if (!game->tab_png[i].img)
        {
            ft_printf("Error: loading texture\n");
            return ;
        }
        mlx_delete_texture(game->tab_png[i].texture);
        i++;
    }
}
void display(t_game *game)
{
    int i;
    int j;

    i = 0;
    j = 0;

    while (game->map[i])
    {
        if (game->map[i][j] == '0')
        {
            mlx_image_to_window(game->mlx, game->tab_png[0].img,game->x * PIXEL, game->y * PIXEL);
        }
        if (game->map[i][j] == 'C')
        {
            mlx_image_to_window(game->mlx, game->tab_png[1].img,game->x * PIXEL, game->y * PIXEL);
        }
        if (game->map[i][j] == '1')
        {
            mlx_image_to_window(game->mlx, game->tab_png[2].img,game->x * PIXEL, game->y * PIXEL);
        }
        if (game->map[i][j] == 'P')
        {
            mlx_image_to_window(game->mlx, game->tab_png[3].img,game->x * PIXEL, game->y * PIXEL);
        }
        if (game->map[i][j] == 'E')
        {
            mlx_image_to_window(game->mlx, game->tab_png[4].img,game->x * PIXEL, game->y * PIXEL);
        }
    }   
}