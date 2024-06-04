/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:23:05 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/06/04 15:48:02 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void    update_position(t_game *game, int old_y, int old_x, int new_y, int new_x)
{
    int pixel_old_y;
    int pixel_old_x;
    int pixel_new_x;
    int pixel_new_y;

    pixel_old_y = old_y * PIXEL;
    pixel_old_x = old_x * PIXEL;
    pixel_new_x = new_x * PIXEL;
    pixel_new_y = new_y * PIXEL;
    if (game->map[old_y][old_x] == 'E')
        mlx_image_to_window(game->mlx, game->tab_png[4].img, pixel_old_x, pixel_old_y);
    else
        mlx_image_to_window(game->mlx, game->tab_png[0].img, pixel_old_x, pixel_old_y);
    mlx_image_to_window(game->mlx, game->tab_png[3].img, pixel_new_x, pixel_new_y);
}
void    handle_capture(t_game *game, int new_x, int new_y)
{
    if (game->map[new_y][new_x] == 'T')
    {
        mlx_close_window(game->mlx);
        ft_printf("YOU GOT CAPTURED!!!!!!!!\n");
    }
}
void    handle_collectible(t_game *game, int new_x, int new_y)
{
     if (game->map[new_y][new_x] == 'C')
        grab_pokeball(game, new_x, new_y);
}
void    handle_exit(t_game *game, int new_x, int new_y)
{
     if (game->map[new_y][new_x] == 'E' && game->poke == 0)
    {
        mlx_close_window(game->mlx);
        ft_printf("You exited the map\n");
    }
}
void    update_game(t_game *game, int new_x, int new_y)
{
    game->x = new_x;
    game->y = new_y;
    game->step++;
    game->moove_count++;
    ft_printf("You mooved : %d Time\n", game->step);
    display_moove_count(game, 0);    
}
void	event_listener(mlx_key_data_t keydata, void* param)
{
    t_game *game;
    game = (t_game *)param;
    int y = game->y;
    int x = game->x;
    int new_y = y;
    int new_x = x;

    if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
    {
        mlx_close_window(game->mlx);
        return;
    }
    if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE && game->map[y - 1][x] != '1')
        new_y--;
    else if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE && game->map[y + 1][x] != '1')
        new_y++;
    else if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE && game->map[y][x - 1] != '1')
        new_x--;
    else if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE && game->map[y][x + 1] != '1')
        new_x++;
    if (new_x == x && new_y == y)
        return;
    update_position(game, y, x, new_x, new_y);
    handle_capture(game, new_x, new_y);
    handle_collectible(game, new_x, new_y);
    handle_exit(game, new_x, new_y);
    update_game(game, new_x, new_y);
}
