/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adejbakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 10:59:03 by adejbakh          #+#    #+#             */
/*   Updated: 2018/11/15 12:41:03 by adejbakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen_end(const char *s)
{
	size_t b;

	b = 0;
	while (s[b])
		b++;
	b--;
	while (b > 0 && (s[b] == ' ' || s[b] == '\n' || s[b] == '\t'))
		b--;
	return (++b);
}

static size_t	ft_strlen_start(const char *s)
{
	size_t a;

	a = 0;
	while ((s[a] == ' ' || s[a] == '\n' || s[a] == '\t') && s[a])
		a++;
	return (a);
}

char			*ft_strtrim(char const *s)
{
	char	*str;
	size_t	a;
	size_t	b;
	size_t	c;

	if (s == NULL)
		return (NULL);
	a = ft_strlen_start(s);
	b = ft_strlen_end(s);
	c = 0;
	if (b <= a)
		b = a;
	if (!(str = (char*)malloc(sizeof(*str) * (b - a) + 1)))
		return (NULL);
	while (a < b)
		str[c++] = s[a++];
	str[c] = '\0';
	return (str);
}
