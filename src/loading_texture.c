/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 22:50:21 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/06/08 22:51:50 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	check_textures(t_game *game)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (!game->tab_png[i].texture)
			return (0);
		i++;
	}
	return (1);
}

static void	load_and_check_images(t_game *game)
{
	int	i;

	i = 0;
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

void	loading_png(t_game *game)
{
	game->tab_png[0].texture = mlx_load_png("./image/grass.png");
	game->tab_png[1].texture = mlx_load_png("./image/pokeball.png");
	game->tab_png[2].texture = mlx_load_png("./image/arbre.png");
	game->tab_png[3].texture = mlx_load_png("./image/ecto.png");
	game->tab_png[4].texture = mlx_load_png("./image/door.png");
	game->tab_png[5].texture = mlx_load_png("./image/enemie.png");
	game->tab_png[6].texture = NULL;
	if (!check_textures(game))
	{
		ft_printf("Error: loading texture\n");
		return ;
	}
	load_and_check_images(game);
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
