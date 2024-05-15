/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:14:48 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/05/15 20:16:13 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <string.h>
// cette fonction permet de verifier si la map est un rectangle
int  is_rectang(t_game *game)
{
    int i;

    i = 0;
    if(game->map == NULL)
        return (0);
    while (game->map[i])
    {
        if (strlen(game->map[i]) != strlen(game->map[i]))
        {
            printf("Error: la map n'est pas un rectangle\n");
            return (0);
        }
        i++;
    }
    return (1);
}
/*
// cette fonction permet de verifier si la map est entouré de mur
int is_wall(t_game *game)
{
    int i;
    int j;
    int len;

    i = 0;
    j = 0;

    // len of the first line
    while (game->map[0][i])
        i++;
    
    // check the first and last line 
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
*/

// cette fonction permet de verifier si la map est valide
int verif_element(t_game *game)
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
int is_wall(t_game *game)
{
    int i;
    int j;
    int len;

    // Len of the first line
    len = strlen(game->map[0]);

    // Check the first and last line
    for (j = 0; j < len; j++)
    {
        if (game->map[0][j] != '1' || game->map[game->y - 1][j] != '1')
            return 0;
    }

    // Check the first and last column of each line
    for (i = 1; i < game->y - 1; i++)
    {
        if (game->map[i][0] != '1' || game->map[i][len - 1] != '1')
            return 0;
    }
    
    return 1;
}
