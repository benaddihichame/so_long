/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxborde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 21:01:54 by maxborde          #+#    #+#             */
/*   Updated: 2023/10/19 15:57:13 by maxborde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*c1 = s1;
	const unsigned char	*c2 = s2;

	c1 = s1;
	c2 = s2;
	i = 0;
	while (i < n)
	{
		if (c1[i] > c2[i])
			return (1);
		else if (c1[i] < c2[i])
			return (-1);
		i++;
	}
	return (0);
}
