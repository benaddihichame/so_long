/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxborde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 23:46:49 by maxborde          #+#    #+#             */
/*   Updated: 2023/11/10 17:52:01 by maxborde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_dirty_line(int fd, char *buffer)
{
	char	*dirtyline;
	int		charsread;

	charsread = 1;
	dirtyline = NULL;
	dirtyline = ft_strjoingnl(dirtyline, buffer);
	while (!ft_strchrgnl(dirtyline, '\n') && charsread != 0)
	{
		charsread = read(fd, buffer, BUFFER_SIZE);
		if (charsread == -1)
		{
			buffer[0] = 0;
			free(dirtyline);
			return (NULL);
		}
		buffer[charsread] = 0;
		dirtyline = ft_strjoingnl(dirtyline, buffer);
	}
	if (!ft_strlen(dirtyline) && charsread == 0)
	{
		free(dirtyline);
		return (NULL);
	}
	return (dirtyline);
}

char	*get_clean_line(char *remainder)
{
	char	*str;
	int		i;
	int		y;	

	i = 0;
	y = -1;
	while (remainder[i] && remainder[i] != '\n')
		i++;
	if (remainder[i] == '\n')
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	while (++y < i)
		str[y] = remainder[y];
	str[y] = 0;
	free(remainder);
	return (str);
}

static void	clean_up_buffer(char *buffer)
{
	int	k;
	int	i;

	i = 0;
	k = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (buffer[i] == '\n')
		i++;
	while (buffer[i])
		buffer[k++] = buffer[i++];
	buffer[k] = 0;
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1] = {0};
	char		*dirtyline;
	char		*cleanline;

	dirtyline = get_dirty_line(fd, buffer);
	if (!dirtyline)
		return (NULL);
	cleanline = get_clean_line(dirtyline);
	if (!cleanline)
	{
		free(dirtyline);
		return (NULL);
	}
	clean_up_buffer(buffer);
	return (cleanline);
}

/*int	main(void)
{
	int fd;
	int i;

	fd = open("read_error.txt", O_RDONLY);
	i = 1;
	printf("String %d: |%s|\n", i, get_next_line(fd));
	close(fd);
	printf("String %d: |%s|\n", i, get_next_line(fd));
	fd = open("read_error.txt", O_RDONLY);
	printf("String %d: |%s|\n", i, get_next_line(fd));
}*/
