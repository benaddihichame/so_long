/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:52:32 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/05/31 04:49:37 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/so_long.h"

// cette fonction permet de compter le nombre de ligne dans le fichier

int count_line(char *file_name)
{
    int fd;
    int i;
    char *line;
    char   **input;
    i = 0;
    fd = open(file_name, O_RDONLY);
    if (fd == -1)
    {
        perror("Error fd");
        return (1);
    }
    input = malloc(sizeof(char *) * 100);
    while ((line = get_next_line(fd)) != NULL)
    {
        input[i] = strdup(line);
        i++;
        free(line);
    }
      input[i] = NULL;
    close(fd);
    return (i);
}
//cette fonction permet de recuperer la map dans un tableau de chaine de caractere
void get_map(char *file_name, t_game *game)
{
    int fd;
    int i;
    char *line;

    i = 0;
    game->map = malloc((count_line(file_name) + 1) * sizeof(char *));
    if (game->map == NULL)
    {
        ft_printf("Error malloc");
        return;
    }
    fd = open(file_name, O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        line[ft_strlen(line) -1] = 0;
        //printf("line ==%s==\n", line);
        game->map[i] = line;
        i++;
    }
    close(fd);
    game->map[i] = NULL;
}

void    copy_map(t_game *game)
{
    int i;

    i = 0;
    game->map2 = malloc(sizeof(char *) * (count_line(game->map) + 1));
    while (game->map[i])
    {
        game->map2[i] = strdup(game->map[i]);
        i++;
    }
    game->map2[i] = NULL;
}