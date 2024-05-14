/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:52:32 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/05/14 14:22:52 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/so_long.h"
#include <string.h>

// cette fonction permet de compter le nombre de ligne dans le fichier

int count_line(char *file_name)
{
    int fd;
    int i;
    char *line;
    char   **input;
    i = 0;
    // printf("file: %s\n", file_name);
    fd = open(file_name, O_RDONLY);
    if (fd == -1)
    {
        perror("je suis la");
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
    // i = 0;  
    // while (input[i])
    // {
    //     printf("%s\n", input[i]);
    //     i++;
    // }
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
        ft_printf("erroree");
        return;
    }
    fd = open(file_name, O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        game->map[i] = line;
        i++;
    }
    close(fd);
    game->map[i] = NULL;
}
