/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:55:16 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/05/22 21:32:48 by hbenaddi         ###   ########.fr       */
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
int   error_msg(t_game game , char **av)
{
    (void)av;
    if (is_valid(av[1]) == FALSE)
    {
        printf("Error : La map n'est .ber\n");
        return (0);
    }
    if (verif_element(&game) == FALSE)
    {
        printf("Error : les elements ne respect pas le bon nombre\n");
        return (0);
    }
    if (is_wall(game.map) == FALSE)
    {
        printf("Error : La map n'est pas close\n");
        return (0);
    }
    if (is_rectang(game.map) == FALSE)
    {
        printf("Error : La map n'est pas un rectangle\n");
        return (0);
    }
    return (TRUE);
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
void    basic_err(int ac , char **av)
{
    if (ac != 2)
    {
        printf("\033[31;5mError : You must have 2 arguments\033[0m\n");
        return ;
    }
    else if(is_valid(av[1]) == FALSE)
    {
        printf("\033[31;5mError : Invalid extension\033[0m\n");
        return ;
    }
}
int main(int ac, char **av)
{
    t_game game;

    basic_err(ac, av);
    init_var(&game);
    get_map(av[1], &game);
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
    resize(&game);
    mlx_key_hook(game.mlx, event_listener, &game);
    display(&game);
    mlx_loop(game.mlx);
    return(1);
}

