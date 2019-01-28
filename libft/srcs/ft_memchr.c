/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adejbakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:39:16 by adejbakh          #+#    #+#             */
/*   Updated: 2018/11/13 14:21:55 by adejbakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s2;
	unsigned char	c2;
	size_t			a;

	c2 = c;
	a = 0;
	s2 = (unsigned char*)s;
	while (n > a)
	{
		if (s2[a] == c2)
			return ((unsigned char*)&s[a]);
		a++;
	}
	return (NULL);
}
