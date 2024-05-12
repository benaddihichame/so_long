/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxborde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:32:41 by maxborde          #+#    #+#             */
/*   Updated: 2023/10/27 17:57:24 by maxborde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	nbrlen(int n)
{
	long	nb;
	size_t	size;

	nb = n;
	size = 0;
	if (nb == 0)
		size++;
	if (nb < 0)
	{
		size++;
		nb *= -1;
	}
	while (nb)
	{
		nb /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*ns;
	size_t	len;
	int		limit;
	long	nb;

	len = nbrlen(n);
	nb = n;
	ns = malloc(sizeof(char) * (len + 1));
	if (!ns)
		return (NULL);
	ns[len--] = 0;
	limit = 0;
	if (nb < 0)
	{
		ns[0] = '-';
		nb *= -1;
		limit = 1;
	}
	while ((int)len >= limit)
	{
		ns[len--] = nb % 10 + 48;
		nb /= 10;
	}
	return (ns);
}
