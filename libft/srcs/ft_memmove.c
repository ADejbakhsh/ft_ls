/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adejbakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:47:42 by adejbakh          #+#    #+#             */
/*   Updated: 2018/11/13 15:09:28 by adejbakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	*ft_imemcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*src2;
	unsigned char		*dest2;
	int					a;

	a = 0;
	src2 = (unsigned char*)src;
	dest2 = (unsigned char*)dest;
	while (n > 0)
	{
		dest2[a] = src2[a];
		a++;
		n--;
	}
	dest = dest2;
	return (dest);
}

void			*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*src2;
	unsigned char		*dest2;

	src2 = (unsigned char*)src;
	dest2 = (unsigned char*)dest;
	if (src > dest)
		return (ft_imemcpy(dest, src, n));
	else
	{
		while (n > 0)
		{
			dest2[n - 1] = src2[n - 1];
			n--;
		}
	}
	dest = dest2;
	return (dest);
}
