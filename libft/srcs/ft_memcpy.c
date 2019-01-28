/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adejbakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 12:25:31 by adejbakh          #+#    #+#             */
/*   Updated: 2018/11/17 13:31:05 by adejbakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*src2;
	char		*dest2;
	size_t		a;

	a = 0;
	src2 = (char*)src;
	dest2 = (char*)dest;
	while (n > 0)
	{
		dest2[a] = src2[a];
		a++;
		n--;
	}
	dest = dest2;
	return (dest);
}
