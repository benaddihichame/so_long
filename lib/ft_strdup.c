/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxborde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:10:28 by maxborde          #+#    #+#             */
/*   Updated: 2023/10/19 19:32:13 by maxborde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ns;
	size_t	size;
	size_t	i;

	size = ft_strlen(s) + 1;
	ns = (char *)malloc(sizeof(char) * size);
	if (!ns)
		return (NULL);
	i = 0;
	while (i < size)
	{
		ns[i] = s[i];
		i++;
	}
	ns[i] = 0;
	return (ns);
}
