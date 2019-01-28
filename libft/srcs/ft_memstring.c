/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memstring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adejbakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 09:44:45 by adejbakh          #+#    #+#             */
/*   Updated: 2018/11/27 10:15:18 by adejbakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned char	*ft_memstring(const void *s, char *char_set, size_t n, size_t c)
{
	unsigned char	*s2;
	unsigned char	*c2;
	size_t			a;
	size_t			b;

	c2 = (unsigned char*)char_set;
	a = 0;
	s2 = (unsigned char*)s;
	while (n > a)
	{
		b = 0;
		while (b <= c)
		{
			if (s2[a] == c2[b])
				return ((unsigned char*)&s[a]);
			b++;
		}
		a++;
	}
	return (NULL);
}
