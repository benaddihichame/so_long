/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:55:16 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/05/22 17:49:12 by hbenaddi         ###   ########.fr       */
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
    game->step = 0;
    // while (i < 6)
    // {
    //     game->tab_png[i].texture = NULL;
    //     game->tab_png[i].img = NULL;
    //     i++;
    // }
}
//typedef void (*mlx_keyfunc)(mlx_key_data_t keydata, void* param);
void    event_listener(mlx_key_data_t keydata, void* param)
{
    t_game *game;
    game = (t_game *)param;
    int y = game->y;
    int x = game->x;
    if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
        mlx_close_window(game->mlx);
    if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE && game->map[y - 1][x] != '1')
            game->y--;
    else if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE && game->map[y + 1][x] != '1')
            game->y++;
    else if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE && game->map[y][x - 1] != '1')
            game->x--;
    else if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE && game->map[y][x + 1] != '1')
            game->x++;
    if (game->x != x || game->y != y)
    {
            game->step++;
            ft_printf("You walk : %d Time\n", game->step);
            game->tab_png[3].img->instances[0].x = game->x * PIXEL;
            game->tab_png[3].img->instances[0].y = game->y * PIXEL;
    }
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
    printf("dddd");
    init_var(&game);
    get_map(av[1], &game);
    if (is_valid(av[1]) == FALSE)
        return (0);
    if (verif_element(&game) == FALSE)
    {
        printf("les elements ne respect pas le bon nombre👿\n");
        return (0);
    }
    if (is_wall(game.map) == FALSE)
        return (0);
    if (is_rectang(game.map) == FALSE)
        return (0);
    game.mlx = mlx_init((ft_strlen(game.map[0]) * 32),(count_line(av[1]) * 32), "so_long", false);
    if (!game.mlx)
        return(0);
    loading_png(&game);
    resiwe(&game);
    //game.tab_png[3].img->instances[0].z = 0;
    mlx_key_hook(game.mlx, event_listener, &game);
    display(&game);
    mlx_loop(game.mlx);
    return(1);
}

