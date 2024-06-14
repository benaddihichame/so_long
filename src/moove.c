/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:56:35 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/05/24 20:49:12 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	add_data(t_game *game)
{
	int	i;
	int	j;

	game->poke = 0;
	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				game->poke++;
			j++;
		}
		i++;
	}
}

void	grab_pokeball(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'C')
	{
		game->map[y][x] = '0';
		game->poke--;
		mlx_image_to_window(game->mlx, game->tab_png[0].img, \
		x * PIXEL, y * PIXEL);
	}
}

void	handle_escp(mlx_key_data_t keydata, t_game *game)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		close_and_free(game);
}

void	handle_movement_keys(t_game *game, mlx_key_data_t keydata, \
int *new_x, int *new_y)
{
	if (keydata.action == MLX_RELEASE)
	{
		if (keydata.key == MLX_KEY_W && game->map[game->y - 1][game->x] != '1')
			(*new_y)--;
		else if (keydata.key == MLX_KEY_S && \
		game->map[game->y + 1][game->x] != '1')
			(*new_y)++;
		else if (keydata.key == MLX_KEY_A && \
		game->map[game->y][game->x - 1] != '1')
			(*new_x)--;
		else if (keydata.key == MLX_KEY_D && \
		game->map[game->y][game->x + 1] != '1')
			(*new_x)++;
	}
}
