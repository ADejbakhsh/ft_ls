/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adejbakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 18:13:57 by adejbakh          #+#    #+#             */
/*   Updated: 2018/11/15 17:48:13 by adejbakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	a;

	a = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (a < n && (s1[a] || s2[a]))
	{
		if (s1[a] != s2[a])
			return (0);
		a++;
	}
	return (1);
}
