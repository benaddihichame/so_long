/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxborde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:57:43 by maxborde          #+#    #+#             */
/*   Updated: 2023/10/20 14:04:56 by maxborde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	is_a_sep(char const *set, char c)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	size;
	char	*ns;
	size_t	i;

	if (!s1)
		return (NULL);
	size = 0;
	while (is_a_sep(set, *s1))
		s1++;
	while (*s1++)
		size++;
	while (size > 0 && is_a_sep(set, *(s1 - 2)))
	{
		size--;
		s1--;
	}
	ns = (char *)malloc(sizeof(char) * (size + 1));
	if (!ns)
		return (NULL);
	i = 0;
	while (i < (size))
		ns[i++] = *(s1++ - (size + 1));
	ns[i] = 0;
	return (ns);
}
