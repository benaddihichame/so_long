/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:14:48 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/06/14 11:43:30 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	is_rectang(char **map)
{
	int		i;

	i = 0;
	if (!map)
		return (FALSE);
	while (map[i])
	{
		if (map[i + 1] != NULL && ft_strlen(map[i]) \
		!= ft_strlen(map[i + 1]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static int	is_wall_top_bottom(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static int	is_wall_sides(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	is_wall(char **map)
{
	int	last_index;

	if (!is_wall_top_bottom(map[0]))
		return (FALSE);
	if (!is_wall_sides(map))
		return (FALSE);
	last_index = 0;
	while (map[last_index] != NULL)
		last_index++;
	last_index--;
	if (!is_wall_top_bottom(map[last_index]))
		return (FALSE);
	return (TRUE);
}
