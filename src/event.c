/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 23:12:17 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/06/10 13:05:49 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	close_and_free(t_game *game)
{
	free_img(game);
	free_map(game->map);
	mlx_close_window(game->mlx);
}

static void	handle_movement(t_game *game, int new_x, int new_y)
{
	game->x = new_x;
	game->y = new_y;
	game->step++;
	game->moove_count++;
	ft_printf("You moved: %d Time\n", game->step);
	mlx_image_to_window(game->mlx, game->tab_png[3].img, \
	new_x * PIXEL, new_y * PIXEL);
	display_moove_count(game, 0);
}

static void	update_player_position(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'E')
		mlx_image_to_window(game->mlx, game->tab_png[4].img, \
		x * PIXEL, y * PIXEL);
	else
		mlx_image_to_window(game->mlx, game->tab_png[0].img, \
		x * PIXEL, y * PIXEL);
}

static int	check_new_position(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == 'T')
	{
		close_and_free(game);
		ft_printf("You GET CAPTURED!\n");
		return (FALSE);
	}
	if (game->map[new_y][new_x] == 'C')
		grab_pokeball(game, new_x, new_y);
	else if (game->map[new_y][new_x] == 'E' && game->poke == 0)
	{
		close_and_free(game);
		ft_printf("You exited the map!\n");
		return (FALSE);
	}
	return (TRUE);
}

void	event_listener(mlx_key_data_t keydata, void *param)
{
	t_game	*game;
	int		new_y;
	int		new_x;

	game = (t_game *)param;
	new_y = game->y;
	new_x = game->x;
	handle_escp(keydata, game);
	handle_movement_keys(game, keydata, &new_x, &new_y);
	if (new_x == game->x && new_y == game->y)
		return ;
	update_player_position(game, game->x, game->y);
	if (!check_new_position(game, new_x, new_y))
		return ;
	handle_movement(game, new_x, new_y);
}
