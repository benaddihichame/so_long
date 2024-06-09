/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ext.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:54:15 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/06/09 19:48:28 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(const unsigned char *)s1 - *(const unsigned char *)s2);
}

static char	*strchrmod(char *s, char *target)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_strcmp(s + i, target) == 0)
			return (s + i);
		i++;
	}
	return (NULL);
}

int	is_valid(char *str)
{
	if (strchrmod(str, ".ber"))
		return (TRUE);
	else
		return (FALSE);
}
