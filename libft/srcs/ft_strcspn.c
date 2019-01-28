/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adejbakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 11:14:55 by adejbakh          #+#    #+#             */
/*   Updated: 2018/11/29 11:15:39 by adejbakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcspn(char const *s, char const *charset)
{
	unsigned int i;

	i = 0;
	if (s && charset)
		while (*charset)
		{
			i = 0;
			while (s[i])
				if (s[i++] == *charset)
					return (--i);
			charset++;
		}
	return (-1);
}
