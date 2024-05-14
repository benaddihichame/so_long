/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:14:48 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/05/14 17:59:40 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <string.h>
// cette fonction permet de verifier si la map est un rectangle
int  is_rectang(char **map)
{
    int i;

    i = 0;
    if(!map)
        return (0);
    while (map[i])
    {
        if (strlen(map[i]) != strlen(map[0]))
        {
            printf("Error: la map n'est pas un rectangle\n");
            return (0);
        }
        i++;
    }
    return (1);
}

// cette fonction permet de verifier si la map est entouré de mur
int is_wall(char **map)
{
    int i;
    int j;
    int len;

    i = 0;
    j = 0;
    while (map[0][i])
        i++;
    while (map[0][j] && map[i - 1][j])
    {
        if (map[0][j] != '1' || map[i - 1][j] != '1')
            return (0);
        j++;
    }
    i = 1;
    len = strlen(map[i]);
    while (map[i])
    {
        if (map[i][0] != '1' || map[i][len - 1] != '1')
            return (0);
        i++;
    }
    return (1);
}
/*
// cette fonction permet de verifier si la map est valide
static int verif_element(t_game *game)
{
    int i;
    int j;

    game->player = 0;
    game->exit = 0;
    game->collectible = 0;
    i = 0;
    while (game->map[i] != '\0')
    {
        while (game->map[i][j] != '\0')
        {
            j = 0;
            if (game->map[i][j] == 'P')
                game->player++;
            else if (game->map[i][j] == 'E')
                game->exit++;
            else if (game->map[i][j] == 'C')
                game->collectible++;
            j++;
        }
        i++;
    }
    if (game->player != 1 || game->exit == 0 || game->collectible == 0 || game->exit > 1)
        return (0);
    return (1);
}
*/