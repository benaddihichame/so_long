/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:55:16 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/05/20 05:43:54 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_var(t_game *game)
{
    //int i = 0;
	game->map = NULL;
	game->player = 0;
	game->exit = 0;
	game->collectible = 0;
	game->vide = 0;
    // while (i < 6)
    // {
    //     game->tab_png[i].texture = NULL;
    //     game->tab_png[i].img = NULL;
    //     i++;
    // }
}
void    resiwe(t_game *game)
{
    mlx_resize_image(game->tab_png[0].img, 32, 32);
    mlx_resize_image(game->tab_png[1].img, 32, 32);
    mlx_resize_image(game->tab_png[2].img, 32, 32);
    mlx_resize_image(game->tab_png[3].img, 32, 32);
    mlx_resize_image(game->tab_png[4].img, 32, 32);
}

int main(int ac, char **av)
{
    (void)av;
    t_game game;

    if (ac != 2)
    {
        printf("Error Need 2 argument\n");
        return (1);
    }
    init_var(&game);
    get_map(av[1], &game);
    if (is_valid(av[1]) == FALSE)
        return (0);
    if (is_wall(&game) == FALSE)
        return (0);
    if (verif_element(&game) == FALSE)
    {
        printf("les elements ne respect pas le bon nombre👿\n");
        return (0);
    }
    if(is_rectang(game.map) == FALSE)
        return (0);
    game.mlx = mlx_init((ft_strlen(game.map[0]) * 32),(count_line(av[1]) * 32), "so_long", false);
    if (!game.mlx)
        return(0);
    loading_png(&game);
    resiwe(&game);
    // mlx_image_to_window(game.mlx, game.tab_png[0].img , 0 , 0);
    display(&game);
    mlx_loop(game.mlx);
    return(1);
}

