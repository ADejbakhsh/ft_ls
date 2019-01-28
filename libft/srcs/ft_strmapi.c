/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adejbakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 17:58:33 by adejbakh          #+#    #+#             */
/*   Updated: 2018/11/15 11:29:55 by adejbakh         ###   ########.fr       */
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

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
		str[a] = f(a, s[a]);
		a++;
	}
	str[a] = '\0';
	return (str);
}
