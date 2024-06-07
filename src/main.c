/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:55:16 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/06/07 18:55:11 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_var(t_game *game, char **av)
{
    int i = 0;
	game->map = NULL;
	game->player = 0;
	game->exit = 0;
	game->collectible = 0;
	game->vide = 0;
	game->step = 0;
	game->filename = av[1];
    while (i < 6)
    {
        game->tab_png[i].texture = NULL;
        game->tab_png[i].img = NULL;
        i++;
    }
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
        free_map(game->map);
        free_map(game->map2);
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
    // Vérifiez si le joueur a réellement déplacé
    if (new_x == x && new_y == y)
        return;
    // Mettre à jour l'affichage de l'ancienne position avec l'image de fond
    if (game->map[y][x] == 'E')
        mlx_image_to_window(game->mlx, game->tab_png[4].img, x * PIXEL, y * PIXEL);
    else 
        mlx_image_to_window(game->mlx, game->tab_png[0].img, x * PIXEL, y * PIXEL);
    if (game->map[new_y][new_x] == 'T')
    {
        mlx_close_window(game->mlx);
        free_map(game->map);
        free_map(game->map2);
        ft_printf("You GET CAPTURED!\n");
        return ;
    }
    // Si le joueur se déplace sur un collectible
    if (game->map[new_y][new_x] == 'C')
        grab_pokeball(game, new_x, new_y);
    // Si le joueur se déplace sur la porte de sortie et tous les collectibles sont ramassés
    else if (game->map[new_y][new_x] == 'E' && game->poke == 0)
    {
        free_map(game->map);
        free_map(game->map2);
        mlx_close_window(game->mlx);
        ft_printf("You exited the map!\n");
        return ;
    }
    // Mettre à jour les coordonnées du joueur
    game->x = new_x;
    game->y = new_y;
    game->step++;
    game->moove_count++;
    ft_printf("You moved: %d Time\n", game->step);
    // Mettre à jour l'affichage de la nouvelle position avec l'image du personnage
	mlx_image_to_window(game->mlx, game->tab_png[3].img, new_x * PIXEL, new_y * PIXEL);
	display_moove_count(game, 0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (basic_err(ac, av) != 1)
		return (0);
	init_var(&game, av);
	get_map(av[1], &game);
	if (all_checks(&game) != 1)
    {
        free_map(game.map);
        free_map(game.map2);
		return (0);
    }
    add_data(&game);
	game.mlx = mlx_init((ft_strlen(game.map[0]) * 32), \
	(count_line(av[1]) * 32), "so_long", true);
	if (!game.mlx)
    {
        free_map(game.map);
        free_map(game.map2);
		return (0);
    }
    loading_png(&game);
	resize(&game);
	mlx_key_hook(game.mlx, event_listener, &game);
	display(&game);
	mlx_loop(game.mlx);
    free_resources(&game);
    free_map(game.map);
    free_map(game.map2);
	return (1);
}