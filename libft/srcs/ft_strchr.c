/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adejbakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 09:36:37 by adejbakh          #+#    #+#             */
/*   Updated: 2019/02/21 12:51:20 by adejbakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	a;

	a = c;
	c = 0;
	while (s[c])
	{
		if (s[c] == a)
			return ((char*)&s[c]);
		c++;
	}
	if (s[c] == a)
		return ((char*)&s[c]);
	return (0);
}
