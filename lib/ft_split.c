/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxborde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:53:52 by maxborde          #+#    #+#             */
/*   Updated: 2023/10/19 15:54:12 by maxborde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	is_a_sep(char c, char sep)
{
	return (c == sep);
}

static size_t	count_words(char sep, char const *str)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		if ((is_a_sep(*(str - 1), sep) || *(str - 1) == 0) && !is_a_sep(*str,
				sep))
			count++;
		str++;
	}
	return (count);
}

static void	free_all(char **tab, size_t size)
{
	while (size)
	{
		free(tab[size]);
		size--;
	}
	free(tab);
	return ;
}

static char	*make_words(char sep, char const *str, size_t tsize, char **tab)
{
	char	*ns;
	size_t	size;
	size_t	i;

	size = 0;
	while (str[size] && !is_a_sep(str[size], sep))
		size++;
	ns = (char *)malloc(sizeof(char) * (size + 1));
	if (!ns)
	{
		free_all(tab, tsize);
		return (NULL);
	}
	i = 0;
	while (i < size)
	{
		ns[i] = str[i];
		i++;
	}
	ns[i] = 0;
	return (ns);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	char	**tab;
	size_t	tsize;

	tsize = count_words(c, s);
	tab = (char **)malloc(sizeof(char *) * (tsize + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (is_a_sep(c, *s) && *s)
			s++;
		if (*s)
		{
			tab[i] = make_words(c, s, tsize, tab);
			i++;
		}
		while (!is_a_sep(c, *s) && *s)
			s++;
	}
	tab[i] = 0;
	return (tab);
}
