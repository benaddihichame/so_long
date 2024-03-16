/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:22:06 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/03/15 17:20:41 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int count_line(char *file_name)
{
    int fd;
    int i;
    char *line;

    i = 0;
    fd = open(file_name, O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
        i++;
    close(fd);
    return (i);
}
void get_map(char *file_name, t_game *game)
{
    int fd;
    int i;
    char *line;

    i = 0;
    game->map = malloc((count_line(file_name) + 1) * sizeof(char *));
    fd = open(file_name, O_RDONLY);
    if (fd == -1)
        return;
    while ((line = get_next_line(fd)) != NULL)
    {
        game->map[i] = line;
        i++;
    }
    close(fd);
    game->map[i] = NULL;
}