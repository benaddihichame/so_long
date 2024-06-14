/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:55:16 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/06/10 11:55:40 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_var(t_game *game, char **av)
{
	int	i;

	i = 0;
	game->map = NULL;
	game->map2 = NULL;
	game->player = 0;
	game->exit = 0;
	game->collectible = 0;
	game->vide = 0;
	game->step = 0;
	game->moove_count = 0;
	game->filename = av[1];
	game->tab_png->steps_count = 0;
	while (i < 6)
	{
		game->tab_png[i].texture = NULL;
		game->tab_png[i].img = NULL;
		i++;
	}
}

void	close_callback(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (game->map)
		free_map(game->map);
	if (game->map2)
		free_map(game->map2);
	if (game->mlx)
		mlx_terminate(game->mlx);
	exit(0);
}

void	cleanmap(t_game *game)
{
	free_map(game->map);
	free_map(game->map2);
}

int	setup(t_game *game, char **av)
{
	get_map(av[1], game);
	if (all_checks(game) != 1)
	{
		cleanmap(game);
		return (0);
	}
	game->mlx = mlx_init((ft_strlen(game->map[0]) * 32), \
	(count_line(av[1]) * 32), "so_long", true);
	if (!game->mlx)
	{
		cleanmap(game);
		return (0);
	}
	add_data(game);
	loading_png(game);
	resize(game);
	return (1);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (basic_err(ac, av) != 1)
		return (0);
	init_var(&game, av);
	if (!setup(&game, av))
		return (0);
	mlx_key_hook(game.mlx, event_listener, &game);
	mlx_close_hook(game.mlx, close_callback, &game);
	display(&game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	return (1);
}
