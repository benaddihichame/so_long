/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxborde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:41:18 by maxborde          #+#    #+#             */
/*   Updated: 2023/10/31 17:41:21 by maxborde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_find_format(const char c, va_list ap)
{
	int	printlen;

	printlen = 0;
	if (c == 'd' || c == 'i')
		printlen += ft_putnbr(va_arg(ap, int));
	else if (c == 's')
		printlen += ft_printstr(va_arg(ap, char *));
	else if (c == 'c')
		printlen += ft_putchar(va_arg(ap, int));
	else if (c == 'p')
		printlen += ft_print_ptr(va_arg(ap, unsigned long long));
	else if (c == 'u')
		printlen += ft_putunbr(va_arg(ap, unsigned int));
	else if (c == 'x' || c == 'X')
		printlen += ft_printhex(va_arg(ap, unsigned int), c);
	else if (c == '%')
	{
		printlen++;
		ft_putchar('%');
	}
	return (printlen);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		printlen;

	va_start(ap, str);
	printlen = 0;
	while (*str)
	{
		if (*str == '%')
		{
			printlen += ft_find_format(*(str + 1), ap);
			str++;
		}
		else
			printlen += ft_putchar(*str);
		str++;
	}
	va_end(ap);
	return (printlen);
}
