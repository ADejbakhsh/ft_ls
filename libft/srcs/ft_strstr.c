/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adejbakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:10:30 by adejbakh          #+#    #+#             */
/*   Updated: 2018/11/09 10:33:57 by adejbakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int a;
	int b;
	int	c;

	a = 0;
	if (needle[0] == '\0')
		return ((char*)haystack);
	while (haystack[a] != '\0')
	{
		b = 0;
		c = a;
		while (haystack[a] == needle[b] && haystack[a] != '\0'
				&& haystack[b] != '\0')
		{
			a++;
			b++;
		}
		if (b > 0)
			a = a - b;
		if (needle[b] == '\0' || (needle[b - 1] == '\0' && haystack[a] == '\0'))
			return ((char*)&haystack[c]);
		a++;
	}
	return (NULL);
}
