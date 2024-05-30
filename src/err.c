/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 21:41:09 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/05/30 16:17:40 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
int all_checks(t_game *game)
{
    if (verif_element(game) == FALSE)
    {
        ft_printf("\033[31;5mError : Not Good Amount of Element\033[0m\n");
        return 0;
    }
    if (is_wall(game->map) == FALSE)
    {
        ft_printf("\033[31;5mError : The Map is not Surrounded by Wall\033[0m\n");
        return 0;
    }
    if (is_rectang(game->map) == FALSE)
    {
        ft_printf("\033[31;5mError : The Map is not Rectangle\033[0m\n");
        return 0;
    }
    back_tracking(game, game->x, game->y);
    if (back_tracking2(game) == 0)
        return (0);
    return 1;
}