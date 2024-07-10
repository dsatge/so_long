/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsatge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:47:08 by dsatge            #+#    #+#             */
/*   Updated: 2023/12/08 15:15:26 by dsatge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*desti;
	char	*srci;
	size_t	i;

	desti = (char *)dest;
	srci = (char *)src;
	i = 0;
	if (n >= 0 && !src && !dest)
		return (dest);
	if (dest < src)
	{
		ft_memcpy(dest, src, n);
	}
	else
	{
		while (n--)
			desti[n] = srci[n];
	}
	return (dest);
}

// int	main(void)
// {
// 	char	dest[19] = "Hello Billy";
// 	char	src[3] = "you";
//     char    destee[19] = "Hello Billy";
// 	char    srcee[3] = "you";    
// 	memmove(dest + 6, src, 12);
// 	printf("memmove %s\n", dest);
// 	ft_memmove(destee + 6, srcee, 12);
// 	printf("ft_memmove %s\n", destee);
// }
