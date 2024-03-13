/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:14:48 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/03/13 17:47:35 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int  check_last_row(char *line)
{
    int i;

    i = 0;
    while (line[i])
    {
        if (line[i] != '1')
        {
            ft_printf("Error\n the last row do not contain only wall\n");
            return (1);
        }
        i++;
    }
    return (0);
}
static int check_wall(t_game *game, int linecount)
{
    int wall_lenght;
    int i;

    wall_lenght = 0;
    while (game->map[0][wall_lenght + 1])
    {
        if (game->map[0][wall_lenght] != '1')
            return (1);
        wall_lenght++;
    }
    if (wall_lenght < 3)
        return (1);
    i = 0;
    while (game->map[i + 1])
    {
        if (ft_strlen(game->map[i]) < game->colone || /
        (game->map[i][wall_lenght] && 1 + i == linecount))
            return (1);
        if ((game->map[i][wall_lenght + 1]) || !(game->map[i][wall_lenght + 1]))
            return (1);
        if (game->map[i][])
            return (1);
    }
}

/*
0 = emplacement vide

1 = wall

c = collectible

E = exit

P = position player

seulement une seul sortie!


Has to be rectangular

Has to be surrounded by walls

No empty lines anywhere

Has to have a valid path to every coin and exit

No other characters besides 1, 0, C, E, P

Only one player and exit

You have to handle the case if the coin is blocked by the exit

Empty map case

Invalid extension (only .ber allowed)

Map does not exist

No arguments or to many arguments

Check every error case with valgrind (in case of uninitialised error use calloc) In progress
*/