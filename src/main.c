/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:55:16 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/05/24 20:19:06 by hbenaddi         ###   ########.fr       */
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
void    event_listener(mlx_key_data_t keydata, void* param)
{
    t_game *game;
    game = (t_game *)param;
    int y = game->y;
    int x = game->x;
    if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
        mlx_close_window(game->mlx);
    if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE && game->map[y - 1][x] != '1')
    {
        if (game->map[y - 1][x] == 'C')
            grab_pokeball(game);
        game->y--;
    }
    else if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE && game->map[y + 1][x] != '1')
    {
        if (game->map[y + 1][x] == 'C')
            grab_pokeball(game);
        game->y++;
    }
    else if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE && game->map[y][x - 1] != '1')
    {
        if (game->map[y][x - 1] == 'C')
            grab_pokeball(game);
        game->x--;
    }
    else if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE && game->map[y][x + 1] != '1')
    {
        if(game->map[y][x + 1] == 'C')
            grab_pokeball(game);
        game->x++;
    }
    if (game->x != x || game->y != y)
    {
            game->step++;
            ft_printf("You mooved : %d Time\n", game->step);
            game->tab_png[3].img->instances[0].x = game->x * PIXEL;
            game->tab_png[3].img->instances[0].y = game->y * PIXEL;
    }
}
int   basic_err(int ac , char **av)
{
    if (ac != 2)
    {
        ft_printf("\033[31;5mError : You must have 2 arguments\033[0m\n");
        return (0);
    }
    if(is_valid(av[1]) == FALSE)
    {
        ft_printf("\033[31;5mError : Invalid extension\033[0m\n");
        return (0);
    }
    return (1);
}

// int map_err(t_game *game)
// {
//     t_game map;
//     if (verif_element(&game) == FALSE)
//     {
//         ft_printf("\033[31;5mError : Not Good Amount of Element\033[0m\n");
//         return (0);
//     }
//     if (is_wall(map.map) == FALSE)
//     {
//         ft_printf("\033[31;5mError : The Map is not Surrounded by Wall\033[0m\n");
//         return (0);
//     }
//     if (is_rectang(map.map) == FALSE)
//     {
//         ft_printf("\033[31;5mError : The Map is not Rectangle\033[0m\n");
//         return (0);
//     }
//     return (1);
// }
int main(int ac, char **av)
{
    t_game game;

    if (basic_err(ac, av) != 1)
        return (0);
    init_var(&game);
    get_map(av[1], &game);
        if (verif_element(&game) == FALSE)
    {
        ft_printf("\033[31;5mError : Not Good Amount of Element\033[0m\n");
        return (0);
    }
    if (is_wall(game.map) == FALSE)
    {
        ft_printf("\033[31;5mError : The Map is not Surrounded by Wall\033[0m\n");
        return (0);
    }
    if (is_rectang(game.map) == FALSE)
    {
        ft_printf("\033[31;5mError : The Map is not Rectangle\033[0m\n");
        return (0);
    }
    
    add_data(&game);
    game.mlx = mlx_init((ft_strlen(game.map[0]) * 32),(count_line(av[1]) * 32), "so_long", false);
    if (!game.mlx)
        return(0);
    loading_png(&game);
    resize(&game);
    mlx_key_hook(game.mlx, event_listener, &game);
    display(&game);
    mlx_loop(game.mlx);
    return(1);
}

