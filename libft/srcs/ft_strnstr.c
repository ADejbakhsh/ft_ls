/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adejbakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:31:16 by adejbakh          #+#    #+#             */
/*   Updated: 2018/11/09 10:53:24 by adejbakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int a;
	int b;
	int	c;

	a = 0;
	if (needle[0] == '\0')
		return ((char*)haystack);
	while (haystack[a] != '\0' && len > 0)
	{
		b = 0;
		c = a;
		while (haystack[a] == needle[b] && haystack[a] != '\0'
				&& haystack[b] != '\0' && len-- > 0)
		{
			a++;
			b++;
		}
		a = a - b;
		len = len + b;
		if (needle[b] == '\0' || (needle[b - 1] == '\0' && haystack[a] == '\0'))
			return ((char*)&haystack[c]);
		a++;
		len--;
	}
	return (NULL);
}
