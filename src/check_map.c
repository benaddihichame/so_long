/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:14:48 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/05/20 05:43:06 by hbenaddi         ###   ########.fr       */
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

// cette fonction permet de verifier si la map est entouré de mur
int is_wall(t_game *game)
{
    int i;
    int j;
    int len;

    i = 0;
    j = 0;

    while (game->map[0][i])
        i++;
    while (game->map[0][j] && game->map[i - 1][j])
    {
        if (game->map[0][j - 1] != '1' || game->map[i - 1][j -  1] != '1')
            return (0);
        j++;
    }
    i = 1;
    len = strlen(game->map[i]);
    while (game->map[i])
    {
        if (game->map[i][0] != '1' || game->map[i][len - 1] != '1')
            return (0);
        i++;
    }
    return (1);
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
                game->player++;
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

int	is_wall(t_game *game)
{
	int	i;
	int	j;
	int	height;

	i = 0;
	while (game->map[0][i])
	{
		if (game->map[0][i++] != '1')
			return (FALSE);
	}
	i = 0;
	while (game->map[++i])
	{
		if (game->map[i][0] != '1' ||
			game->map[i][strlen(game->map[i]) - 1] != '1')
			return (FALSE);
	}
	height = i - 1;
	j = 0;
	while (game->map[height][j])
	{
		if (game->map[height][j++] != '1')
			return (FALSE);
	}
	return (TRUE);
}