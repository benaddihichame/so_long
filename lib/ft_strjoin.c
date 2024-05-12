/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxborde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:38:32 by maxborde          #+#    #+#             */
/*   Updated: 2023/10/18 14:22:45 by maxborde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ns;
	size_t	i;
	size_t	size;
	size_t	size2;

	size = ft_strlen(s1);
	size2 = ft_strlen(s2);
	i = 0;
	ns = (char *)malloc(sizeof(char) * (size + size2 + 1));
	if (!ns)
		return (NULL);
	while (i < size)
	{
		ns[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < size2)
	{
		ns[i + size] = s2[i];
		i++;
	}
	ns[i + size] = 0;
	return (ns);
}
