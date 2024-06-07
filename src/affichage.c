/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:47:18 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/06/07 16:17:57 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	loading_png(t_game *game)
{
	int	i;

	i = 0;
	game->tab_png[0].texture = mlx_load_png("./image/grass.png");
	game->tab_png[1].texture = mlx_load_png("./image/pokeball.png");
	game->tab_png[2].texture = mlx_load_png("./image/arbre.png");
	game->tab_png[3].texture = mlx_load_png("./image/ecto.png");
	game->tab_png[4].texture = mlx_load_png("./image/door.png");
	game->tab_png[5].texture = mlx_load_png("./image/enemie.png");
	game->tab_png[6].texture = NULL;
	if (game->tab_png[0].texture == NULL || game->tab_png[1].texture == NULL \
	|| game->tab_png[2].texture == NULL || game->tab_png[3].texture == NULL \
	|| game->tab_png[4].texture == NULL || game->tab_png[5].texture == NULL)
	{
		ft_printf("Error: loading texture\n");
		return ;
	}
	while (i < 6)
	{
		game->tab_png[i].img = mlx_texture_to_image(game->mlx, \
				game->tab_png[i].texture);
		if (!game->tab_png[i].img)
		{
			ft_printf("Error: loading texture\n");
			return ;
		}
		mlx_delete_texture(game->tab_png[i].texture);
		i++;
	}
}

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

void	display(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	display_background(game);
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j] != '\0')
		{
			if (game->x == j && game->y == i)
				mlx_image_to_window(game->mlx, game->tab_png[3].img, \
				j * 32, i * 32);
			else if (game->map[i][j] == 'C')
				mlx_image_to_window(game->mlx, game->tab_png[1].img, \
				j * PIXEL, i * PIXEL);
			else if (game->map[i][j] == '1')
				mlx_image_to_window(game->mlx, game->tab_png[2].img, \
				j * PIXEL, i * PIXEL);
			else if (game->map[i][j] == 'E')
				mlx_image_to_window(game->mlx, game->tab_png[4].img, \
				j * PIXEL, i * PIXEL);
			else if (game->map[i][j] == 'T')
				mlx_image_to_window(game->mlx, game->tab_png[5].img, \
				j * PIXEL, i * PIXEL);
		}
	}
}

void	resize(t_game *game)
{
	mlx_resize_image(game->tab_png[0].img, 32, 32);
	mlx_resize_image(game->tab_png[1].img, 32, 32);
	mlx_resize_image(game->tab_png[2].img, 32, 32);
	mlx_resize_image(game->tab_png[3].img, 32, 32);
	mlx_resize_image(game->tab_png[4].img, 32, 32);
	mlx_resize_image(game->tab_png[5].img, 32, 32);
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
