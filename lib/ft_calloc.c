/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxborde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:59:17 by maxborde          #+#    #+#             */
/*   Updated: 2023/10/20 15:13:26 by maxborde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmenb, size_t size)
{
	size_t	tsize;
	void	*ptr;

	tsize = nmenb * size;
	ptr = (void *)malloc(tsize);
	if (ptr)
		ft_bzero(ptr, tsize);
	return (ptr);
}
