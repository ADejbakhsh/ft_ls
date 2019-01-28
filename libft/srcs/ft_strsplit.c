/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adejbakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 13:09:21 by adejbakh          #+#    #+#             */
/*   Updated: 2018/11/18 12:57:33 by adejbakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_sstrlen(const char *s, char c, int a)
{
	while (s[a] != c && s[a] != '\0')
		a++;
	return (a);
}

static	int	ft_skip(const char *s, char c, int a)
{
	while (s[a] == c && s[a] != '\0')
		a++;
	return (a);
}

static	int	ft_nb_argv(const char *s, char c)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (s[a] != '\0')
	{
		while (s[a] == c && s[a] != '\0')
			a++;
		if (s[a] != '\0')
			b++;
		while (s[a] != c && s[a])
			a++;
	}
	return (b);
}

char		**ft_strsplit(char const *s, char c)
{
	char**w;
	int	a;
	int	b;
	int	d;

	a = 0;
	b = 0;
	if (!(s))
		return (0);
	if (!(w = (char**)malloc(sizeof(*w) * ft_nb_argv(s, c) + 1)))
		return (NULL);
	while (s[a] != 0)
	{
		d = 0;
		a = ft_skip(s, c, a);
		if (s[a] != '\0')
		{
			w[b] = ft_strnew(ft_sstrlen(s, c, a));
			while (s[a] && s[a] != c)
				w[b][d++] = s[a++];
			w[b++][d] = '\0';
		}
	}
	w[b] = 0;
	return (w);
}
