/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsatge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:01:37 by dsatge            #+#    #+#             */
/*   Updated: 2023/12/06 17:39:42 by dsatge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*mem;
	int		i;

	i = 0;
	mem = malloc(ft_strlen(s) + 1);
	if (!mem)
		return (NULL);
	while (s[i])
	{
		mem[i] = s[i];
		i++;
	}
	mem[i] = '\0';
	return (mem);
}
/*
int	main(void)
{
	printf("ft_strdup returns %s", ft_strdup("hello how are you?"));
}*/
