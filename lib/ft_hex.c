/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxborde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:38:34 by maxborde          #+#    #+#             */
/*   Updated: 2023/10/31 17:38:37 by maxborde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hexlen(unsigned int num)
{
	int	hexlen;

	hexlen = 0;
	while (num != 0)
	{
		hexlen++;
		num = num / 16;
	}
	return (hexlen);
}

void	ft_puthex(unsigned int num, char const format)
{
	if (num >= 16)
	{
		ft_puthex(num / 16, format);
		ft_puthex(num % 16, format);
	}
	else
	{
		if (num <= 9)
			ft_putchar(num + '0');
		else
		{
			if (format == 'x')
				ft_putchar(num - 10 + 'a');
			if (format == 'X')
				ft_putchar(num - 10 + 'A');
		}
	}
}

int	ft_printhex(unsigned int num, char const format)
{
	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	ft_puthex(num, format);
	return (ft_hexlen(num));
}
