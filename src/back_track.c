/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_track.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 22:52:23 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/06/08 22:53:13 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	back_tracking(t_game *game, int x, int y)
{
	if (game->map2[y][x] == 'C' || game->map2[y][x] == 'E' || \
	game->map2[y][x] == '0' || game->map2[y][x] == 'P')
	{
		game->map2[y][x] = '9';
		back_tracking(game, x + 1, y);
		back_tracking(game, x - 1, y);
		back_tracking(game, x, y + 1);
		back_tracking(game, x, y - 1);
	}
}

int	back_tracking2(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map2[i] != NULL)
	{
		j = 0;
		while (game->map2[i][j])
		{
			if (game->map2[i][j] == 'C' || game->map2[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
