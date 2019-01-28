/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adejbakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:52:31 by adejbakh          #+#    #+#             */
/*   Updated: 2018/11/17 13:37:26 by adejbakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	a;
	char	*str;

	a = 0;
	if (!(str = (void*)malloc(sizeof(*str) * size)))
		return (NULL);
	while (a < size)
		str[a++] = 0;
	return ((void*)str);
}
