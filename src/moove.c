/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:56:35 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/05/24 20:24:24 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void add_data(t_game *game)
{
    int i;
    int j;

    game->poke = 0;
    i = 0;
    while (game->map[i] != NULL)
    {
        j = 0;
        while (game->map[i][j])
        {  
            if (game->map[i][j] == 'C')
                game->poke++;
            j++;
        }
        i++;
    }
}
void    grab_pokeball(t_game *game)
{
    int i;
    int j;

    i = 0;
    while (game->map[i])
    {
        j = 0;
        while (game->map[i][j] && game->poke > 0)
        {
            if (game->map[i][j] == 'C')
                game->map[i][j] = '0';
            game->poke--;
            j++;
        }
        i++;
    }
}