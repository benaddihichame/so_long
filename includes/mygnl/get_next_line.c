/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:40:03 by hbenaddi          #+#    #+#             */
/*   Updated: 2023/12/19 15:59:58 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *line)
{
	free(line);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1] = {};
	char		*line;
	int			res_read;

	line = NULL;
	if (BUFFER_SIZE < 0 || fd < 0)
		return (NULL);
	if (strchr_newline(buffer))
	{
		ft_cut_buffer(buffer);
		line = ft_mod_join(line, buffer);
	}
	res_read = 1;
	while (res_read > 0 && !strchr_newline(buffer))
	{
		res_read = read(fd, buffer, BUFFER_SIZE);
		if (res_read == -1)
			return (ft_free(line));
		if (res_read == 0)
			return (line);
		buffer[res_read] = '\0';
		line = ft_mod_join(line, buffer);
	}
	return (line);
}
