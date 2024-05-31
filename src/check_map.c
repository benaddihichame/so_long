/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:14:48 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/05/31 21:55:01 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <string.h>


// cette fonction permet de verifier si la map est un rectangle
int  is_rectang(char **map)
{
    int		i;

    i = 0;
    if(!map)
        return (FALSE);
    while (map[i])
    {
        if (map[i + 1] != NULL  && strlen(map[i]) != strlen(map[i + 1]))
        {
            printf("Error: la map n'est pas un rectangle\n");
            return (FALSE);
        }
        i++;
    }
    return (TRUE);
}

// cette fonction permet de verifier si la map est valide
int verif_element(t_game *game)
{
    int i;
    int j;

    game->player = 0;
    game->exit = 0;
    game->collectible = 0;
    i = 0;
    while (game->map[i] != NULL)
    {
        j = 0;
        while (game->map[i][j])
        {
            if (game->map[i][j] == 'P')
            {
                game->x = j;
                game->y = i;
                game->player++;
            }
            else if (game->map[i][j] == 'E')
                game->exit++;
            else if (game->map[i][j] == 'C')
                game->collectible++;
            j++;
        }
        i++;
    }
    if (game->player != 1 || game->exit != 1 || game->collectible < 1)
        return (FALSE);
    return (TRUE);
}

int	is_wall(char **map)
{
	int	i;
	int	j;
    
    j = 0;
	i = 0;
	while (map[0][i])
	{
		if (map[0][i] != '1')
                return (FALSE);
        i++;
	}
	i = 0;
	while (map[i] != NULL)
	{
		if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
			return (FALSE);
        i++;
    }
	i--;
	while (map[i][j] != '\0')
	{
		if (map[i][j] != '1')
			return (FALSE);
        j++;
	}
	return (TRUE);
}

int ftstrleun(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}
void    back_tracking(t_game *game, int x, int y)
{
    // if (x < 0 || y < 0 || game->map2[y][x] == '1' || game->map2[y][x] == '9')
    //     return ;
    if (game->map2[y][x] == 'C' || game->map2[y][x] == 'E' || game->map2[y][x] == '0' || game->map2[y][x] == 'P')
    {
        game->map2[y][x] = '9';
        back_tracking(game, x + 1, y);
        back_tracking(game, x - 1, y);
        back_tracking(game, x, y + 1);
        back_tracking(game, x, y - 1);
    }
}
int back_tracking2(t_game *game)
{
    int i;
    int j;

    i = 0;
    while (game->map2[i] != NULL)
    {
        j = 0;
        while (game->map2[i][j])
        {
            if (game->map2[i][j] == 'C' || game->map2[i][j] == 'E'\
             || game->map2[i][j] == 'P' || game->map2[i][j] == '0')
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}
