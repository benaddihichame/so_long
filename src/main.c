/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:55:16 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/05/15 20:16:39 by hbenaddi         ###   ########.fr       */
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

    if (ac != 2)
    {
        printf("Error Need 2 argument\n");
        return (1);
    }
    // loading_png(&game);
    init_var(&game);
    get_map(av[1], &game);
    if (is_valid(av[1]) == 0)
        return (0);
    if(is_rectang(game.map) == 0)
        return (0);
    mlx = mlx_init((ft_strlen(game.map[0]) * 32), (count_line(av[1]) * 32) , "so_long", false);
    if (!mlx)
        return(0);
    mlx_loop(mlx);
    return(1);
}

/*
int main(int ac, char **av)
{
    t_game game;
    mlx_t *mlx;

    if (ac != 2)
    {
        printf("Error: Need 2 arguments\n");
        return (1);
    }

    // Initialiser les variables
    init_var(&game);
    get_map(av[1], &game);

    // Définir map_data
    game.map_data.num_lines = count_line(av[1]);
    game.map_data.line_length = ft_strlen(game.map[0]);

    if (is_valid(av[1]) == 0)
        return (0);
    if (is_rectang(game.map) == 0)
        return (0);

    // Vérifiez si la carte est entourée de murs
    if (is_wall(&game) == 0)
    {
        printf("Error: Map is not enclosed by walls\n");
        return (0);
    }

    // Initialiser mlx
    mlx = mlx_init(game.map_data.line_length * 32, game.map_data.num_lines * 32, "so_long", false);
    if (!mlx)
        return (0);

    mlx_loop(mlx);
    return (1);
}
*/