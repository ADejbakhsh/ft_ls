/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adejbakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 17:46:14 by adejbakh          #+#    #+#             */
/*   Updated: 2018/11/15 12:40:38 by adejbakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_sstrlen(const char *s)
{
	size_t a;

	a = 0;
	while (s[a])
		a++;
	return (a);
}

char			*ft_strmap(char const *s, char (*f)(char))
{
	size_t	a;
	char	*str;

	a = 0;
	if (s == NULL)
		return (NULL);
	if (!(str = (char*)malloc(sizeof(*s) * ft_sstrlen(s) + 1)))
		return (NULL);
	while (s[a])
	{
		str[a] = f(s[a]);
		a++;
	}
	str[a] = '\0';
	return (str);
}
