/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:12:52 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/06/05 17:55:18 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// void	handle_key_escape(t_game *game)
// {
// 	mlx_close_window(game->mlx);
// }

// void	move_up(t_game *game)
// {
// 	game->y--;
// }

// void	move_down(t_game *game)
// {
// 	game->y++;
// }

// void	move_left(t_game *game)
// {
// 	game->x--;
// }

// void	move_right(t_game *game)
// {
// 	game->x++;
// }
// void	event_listener(mlx_key_data_t keydata, void* param)
// {
//     t_game *game;
//     game = (t_game *)param;
//     int y = game->y;
//     int x = game->x;
//     int new_y = y;
//     int new_x = x;

//     if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
//     {
//         mlx_close_window(game->mlx);
//         return;
//     }
//     if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE && game->map[y - 1][x] != '1')
//         new_y--;
//     else if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE && game->map[y + 1][x] != '1')
//         new_y++;
//     else if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE && game->map[y][x - 1] != '1')
//         new_x--;
//     else if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE && game->map[y][x + 1] != '1')
//         new_x++;
//     // Vérifiez si le joueur a réellement déplacé
//     if (new_x == x && new_y == y)
//         return;
//     // Mettre à jour l'affichage de l'ancienne position avec l'image de fond
//     if (game->map[y][x] == 'E')
//         mlx_image_to_window(game->mlx, game->tab_png[4].img, x * PIXEL, y * PIXEL);
//     else 
//         mlx_image_to_window(game->mlx, game->tab_png[0].img, x * PIXEL, y * PIXEL);
//     if (game->map[new_y][new_x] == 'T')
//     {
//         mlx_close_window(game->mlx);
//         ft_printf("You GET CAPTURED!\n");
//         return ;
//     }
//     // Si le joueur se déplace sur un collectible
//     if (game->map[new_y][new_x] == 'C')
//         grab_pokeball(game, new_x, new_y);
//     // Si le joueur se déplace sur la porte de sortie et tous les collectibles sont ramassés
//     else if (game->map[new_y][new_x] == 'E' && game->poke == 0)
//     {
//         mlx_close_window(game->mlx);
//         ft_printf("You exited the map!\n");
//     }
//     // Mettre à jour les coordonnées du joueur
//     game->x = new_x;
//     game->y = new_y;
//     game->step++;
//     game->moove_count++;
//     ft_printf("You moved: %d Time\n", game->step);
//     // Mettre à jour l'affichage de la nouvelle position avec l'image du personnage
// 	mlx_image_to_window(game->mlx, game->tab_png[3].img, new_x * PIXEL, new_y * PIXEL);
// 	display_moove_count(game, 0);
// }