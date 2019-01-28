/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adejbakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:05:28 by adejbakh          #+#    #+#             */
/*   Updated: 2018/11/12 16:19:19 by adejbakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	const char		*src2;
	unsigned char	*dest2;
	size_t			a;

	a = 0;
	src2 = (char*)src;
	dest2 = (unsigned char*)dest;
	while (n > a)
	{
		dest2[a] = src2[a];
		if (dest2[a] == (unsigned char)c)
			return ((unsigned char*)&dest[a + 1]);
		a++;
	}
	return (NULL);
}
