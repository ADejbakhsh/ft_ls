/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adejbakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 18:28:50 by adejbakh          #+#    #+#             */
/*   Updated: 2018/11/22 15:35:35 by adejbakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strjoin(char const *s1, char const *s2)
{
	size_t	a;
	size_t	b;
	char	*str;

	b = 0;
	a = 0;
	if (s2 == NULL)
		return (NULL);
	if (s1 != NULL)
		a = ft_strlen(s1);
	a += ft_strlen(s2);
	if (!(str = (char*)malloc(sizeof(*str) * a + 1)))
		return (NULL);
	a = 0;
	if (s1 != NULL)
		while (s1[a])
			str[a++] = s1[b++];
	b = 0;
	while (s2[b])
		str[a++] = s2[b++];
	str[a] = '\0';
	return (str);
}
