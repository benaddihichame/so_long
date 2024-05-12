/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxborde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:41:04 by maxborde          #+#    #+#             */
/*   Updated: 2023/10/31 17:41:07 by maxborde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	nbrlen(int n)
{
	int	size;

	size = 0;
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

int	unbrlen(unsigned int n)
{
	int	size;

	size = 0;
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_uitoa(unsigned int n)
{
	char	*ns;
	int		len;

	len = unbrlen(n);
	ns = malloc(sizeof(char) * (len + 1));
	if (!ns)
		return (NULL);
	ns[len--] = 0;
	while (len >= 0)
	{
		ns[len--] = n % 10 + 48;
		n /= 10;
	}
	return (ns);
}

int	ft_putnbr(int n)
{
	int		nlen;
	char	*number;

	number = ft_itoa(n);
	nlen = ft_printstr(number);
	free(number);
	return (nlen);
}

int	ft_putunbr(unsigned int n)
{
	int		nlen;
	char	*number;

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	number = ft_uitoa(n);
	nlen = ft_printstr(number);
	free(number);
	return (nlen);
}
