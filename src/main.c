/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 21:49:57 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/05/13 20:23:23 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_var(t_game *game)
{
	game->map = NULL;
	game->player = 0;
	game->exit = 0;
	game->collectible = 0;
	game->vide = 0;
}
int main(int ac, char **av)
{
    (void)ac;
    t_game game;
    mlx_t *mlx;
    mlx_image_t *img;
    mlx_texture_t *texture;

    get_map(av[1], game.map);
    init_var(&game);
    mlx = mlx_init((ft_strlen(game.map[0]) * 32), (count_line(game.map[0]) * 32) , "so_long", false);
    if (!mlx)
        return(0);
    texture = mlx_load_png("./image/pokel.png");
    img = mlx_texture_to_image(mlx, texture);
    mlx_image_to_window(mlx, img, 0, 0);
    mlx_resize_image(img, 32, 32);
    mlx_loop(mlx);
    return(0);
}