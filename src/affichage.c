/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:47:18 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/06/08 23:01:42 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	display_background(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j] != '\0')
			mlx_image_to_window(game->mlx, game->tab_png[0].img, \
				j * PIXEL, i * PIXEL);
	}
}

void	display_image(t_game *game, int i, int j)
{
	char	c;

	c = game->map[i][j];
	if (game->x == j && game->y == i)
		mlx_image_to_window(game->mlx, game->tab_png[3].img, \
		j * PIXEL, i * PIXEL);
	else if (c == 'C')
		mlx_image_to_window(game->mlx, game->tab_png[1].img, \
		j * PIXEL, i * PIXEL);
	else if (c == '1')
		mlx_image_to_window(game->mlx, game->tab_png[2].img, \
		j * PIXEL, i * PIXEL);
	else if (c == 'E')
		mlx_image_to_window(game->mlx, game->tab_png[4].img, \
		j * PIXEL, i * PIXEL);
	else if (c == 'T')
		mlx_image_to_window(game->mlx, game->tab_png[5].img, \
		j * PIXEL, i * PIXEL);
}

void	display_line(t_game *game, int i)
{
	int	j;

	j = 0;
	while (game->map[i][j] != '\0')
	{
		display_image(game, i, j);
		j++;
	}
}

void	display(t_game *game)
{
	int	i;

	i = 0;
	display_background(game);
	while (game->map[i])
	{
		display_line(game, i);
		i++;
	}
}

void	display_moove_count(t_game *game, int start)
{
	char	*move_str;

	move_str = ft_itoa(game->step);
	if (!start)
	{
		mlx_delete_image(game->mlx, game->tab_png->steps_count);
		game->tab_png->steps_count = mlx_put_string(game->mlx, \
		move_str, 30, 10);
		free(move_str);
	}
}
