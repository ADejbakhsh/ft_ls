/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adejbakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:00:49 by adejbakh          #+#    #+#             */
/*   Updated: 2018/11/15 14:39:35 by adejbakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char a;

	a = c;
	c = 0;
	while (s[c])
		c++;
	while (c >= 0)
	{
		if (s[c] == a)
			return ((char*)&s[c]);
		c--;
	}
	return (0);
}
