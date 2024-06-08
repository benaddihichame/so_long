/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:52:32 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/06/08 17:16:56 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	count_line(char *file_name)
{
	int		fd;
	int		i;
	char	*line;
	//char	**input;

	i = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		perror("Error fd");
		return (1);
	}
	//input = malloc(sizeof(char *) * 100);
	while ((line = get_next_line(fd)) != NULL)
	{
		//input[i] = strdup(line);
		i++;
		free(line);
	}
	//input[i] = NULL;
	close(fd);
	return (i);
}

void	get_map(char *file_name, t_game *game)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	game->map = malloc((count_line(file_name) + 1) * sizeof(char *));
	if (game->map == NULL)
	{
		ft_printf("Error malloc");
		free_map(game->map);
		return ;
	}
	fd = open(file_name, O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		line[ft_strlen(line) - 1] = 0;
		game->map[i] = line;
		i++;
	}
	if (line != NULL)
		free(line);
	close(fd);
	game->map[i] = NULL;
}

void get_map(char *file_name, t_game *game)
{
    int fd;
    int i;
    char *line;
    int line_count;

    i = 0;
    line_count = count_line(file_name);
    game->map = malloc((line_count + 1) * sizeof(char *));
    if (game->map == NULL)
    {
        ft_printf("Error malloc\n");
        return;
    }
    fd = open(file_name, O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        free(game->map);
        game->map = NULL; // Éviter une double libération
        return;
    }
    while ((line = get_next_line(fd)) != NULL)
    {
        line[ft_strlen(line) - 1] = 0;
        game->map[i] = strdup(line);
        if (game->map[i] == NULL)
        {
            ft_printf("Error strdup\n");
            free_map(game->map);
            close(fd);
            return;
        }
        i++;
    }
    if (line != NULL)
        free(line);
    game->map[i] = NULL;
    close(fd);
}

void	copy_map(t_game *game)
{
	int	i;

	i = 0;
	game->map2 = malloc(sizeof(char *) * (count_line(game->filename) + 1));
	if (game->map2 == NULL)
	{
		perror("Error malloc");
		return ;
	}
	while (game->map[i])
	{
		game->map2[i] = ft_strdup(game->map[i]);
		if (game->map2[i] == NULL)
		{
			perror("Error strdup");
			free_map(game->map2);
			return ;
		}
		i++;
	}
	game->map2[i] = NULL;
}
