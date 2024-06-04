/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:55:16 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/06/04 15:41:22 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_var(t_game *game, char **av)
{
    // int i = 0;
	game->map = NULL;
	game->player = 0;
	game->exit = 0;
	game->collectible = 0;
	game->vide = 0;
	game->step = 0;
	game->filename = av[1];
    // while (i < 6)
    // {
    //     game->tab_png[i].texture = NULL;
    //     game->tab_png[i].img = NULL;
    //     i++;
    // }
}

int	main(int ac, char **av)
{
	t_game	game;

	if (basic_err(ac, av) != 1)
		return (0);
	init_var(&game, av);
	get_map(av[1], &game);
	if (all_checks(&game) != 1)
		return (0);
	add_data(&game);
	game.mlx = mlx_init((ft_strlen(game.map[0]) * 32), \
	(count_line(av[1]) * 32), "so_long", true);
	if (!game.mlx)
		return (0);
	loading_png(&game);
	resize(&game);
	mlx_key_hook(game.mlx, event_listener, &game);
	display(&game);
	mlx_loop(game.mlx);
    free(game.map2);
	return (1);
}