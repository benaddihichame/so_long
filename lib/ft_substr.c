/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxborde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:14:55 by maxborde          #+#    #+#             */
/*   Updated: 2023/10/20 13:50:44 by maxborde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ns;
	size_t	i;
	size_t	j;

	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	ns = (char *)malloc(sizeof(char) * (len + 1));
	if (!ns)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			ns[j] = s[i];
			j++;
		}
		i++;
	}
	ns[j] = 0;
	return (ns);
}

/*#include <stdio.h>

int	main(void)
{
	printf("%s\n", ft_substr("hello", 0, 5));
	printf("%s\n", ft_substr("hello", 0, 0));
	printf("%s---\n", ft_substr("hello", 8, 5));
	printf("%s\n", ft_substr("hello", 0, 3));
}*/
