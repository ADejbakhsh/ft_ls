/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adejbakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:03:09 by adejbakh          #+#    #+#             */
/*   Updated: 2018/11/13 14:23:54 by adejbakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	int	a;

	a = 0;
	while (src[a] && n > 0)
	{
		dest[a] = src[a];
		a++;
		n--;
	}
	while (n > 0)
	{
		dest[a] = 0;
		n--;
		a++;
	}
	return (dest);
}
