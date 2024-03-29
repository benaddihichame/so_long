/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:14:48 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/03/16 22:01:53 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


static int  is_rectang(char **map)
{
    int i;

    i = 0;
    if(!map)
        return (0);
    while (map[i] != '\0')
    {
        if (ft_strlen(map[i]) != ft_strlen(map[0]))
            return (0)
        i++;
    }
    return (1);
}

static int is_wall(char **map)
{
    int i;
    int j;
    int len;

    i = 0;
    j = 0;
    while (map[i] != '\0')
        i++;
    while (map[0][j] != '\0' && map[i - 1][j] != '\0')
    {
        if (map[0][j] != '1' || map[i - 1][j] != '1')
            return (0);
        j++;
    }
    i = 1;
    len = ft_strlen(map[i]);
    while (map[i] != '\0')
    {
        if (map[i][0] != '1' || map[i][len - 1] != '1')
            return (0);
        i++;
    }
    return (1);
}
static int is_mapvalid(char **map)
{
    int i;
    int j;

    i = 0;
    

}
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
    if (game->player != 1 || game->exit == 0 || game->collectible == 0)
        return (0);
    return (1);
}
int map_checker(t_game *game)
{
    if ()
        return (1);
    return (0);
}