/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:28:50 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/03/11 16:52:01 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <stdio.h>


int main(int argc, char** argv)
{
    t_game game;
    int i = 0;

    get_map(argv[1], &game);
    while (game.map[i])
    {
        printf("%s", game.map[i]);
        i++;
    }
    return(0);
}