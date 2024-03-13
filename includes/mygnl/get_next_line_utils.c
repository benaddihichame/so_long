/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:07:14 by hbenaddi          #+#    #+#             */
/*   Updated: 2023/12/19 16:13:52 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_cut_buffer(char *buffer)
{
	int		i;
	int		j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	j = 0;
	while (buffer[i])
		buffer[j++] = buffer[i++];
	buffer[j] = '\0';
}

char	*ft_mod_join(char *line, char *buffer)
{
	char	*tmp;
	int		i;
	int		j;

	if (!line)
	{
		line = malloc(sizeof(char));
		if (!line)
			return (NULL);
		line[0] = '\0';
	}
	tmp = malloc((strlen_gnl(line) + strlen_gnl(buffer) + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	i = -1;
	while (line[++i])
		tmp[i] = line[i];
	free(line);
	j = 0;
	while (buffer[j] && buffer[j] != '\n')
		tmp[i++] = buffer[j++];
	if (buffer[j] == '\n')
		tmp[i++] = '\n';
	tmp[i] = '\0';
	return (test_end(tmp));
}

int	strchr_newline(char *buffer)
{
	int	i;

	i = 0;
	if (buffer == NULL)
		return (0);
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	strlen_gnl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*test_end(char *dest)
{
	if (dest[0] == '\0')
	{
		free(dest);
		dest = NULL;
	}
	return (dest);
}

