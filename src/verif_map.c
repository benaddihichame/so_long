/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 23:16:48 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/06/08 23:17:31 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	valid_element(char c)
{
	return (c == 'C' || c == 'T' || c == '0' || \
	c == '1' || c == 'E' || c == 'P');
}

static void	count_elements(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'P')
	{
		game->x = j;
		game->y = i;
		game->player++;
	}
	else if (game->map[i][j] == 'E')
		game->exit++;
	else if (game->map[i][j] == 'C')
		game->collectible++;
}

static int	validate_counts(t_game *game)
{
	if (game->player != 1 || game->exit != 1 || game->collectible < 1)
		return (FALSE);
	return (TRUE);
}

int	verif_element(t_game *game)
{
	int	i;
	int	j;

	game->player = 0;
	game->exit = 0;
	game->collectible = 0;
	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j])
		{
			if (!valid_element(game->map[i][j]))
				return (FALSE);
			count_elements(game, i, j);
			j++;
		}
		i++;
	}
	return (validate_counts(game));
}
