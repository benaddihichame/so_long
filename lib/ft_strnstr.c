/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxborde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 21:13:21 by maxborde          #+#    #+#             */
/*   Updated: 2023/10/23 17:32:18 by maxborde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;

	if (*to_find == 0)
	{
		return ((char *)(str));
	}
	i = 0;
	j = 0;
	while (*str)
	{
		if (*str == *to_find)
		{
			while (str[i] == to_find[i] && i + j < n && str[i])
				i++;
			if (!to_find[i])
				return ((char *)(str));
		}
		j++;
		str++;
	}
	return (NULL);
}
