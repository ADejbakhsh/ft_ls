/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut_before_last_cara.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adejbakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:52:13 by adejbakh          #+#    #+#             */
/*   Updated: 2019/01/24 12:29:44 by adejbakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_cut_before_last_cara(char *str, char cara)
{
	char	*nstr;
	int		i;
	int		a;

	if (str == NULL || cara < 0)
		return ("ft_cut_before_last_cara: envoi invalide \n");
	i = ft_strlen(str);
	while (i > 0 && str[i] != cara)
		i--;
	if (str[i] == '\0')
		return ("ft_cut_before_last_cara: pas le cara dans la string");
	a = ft_strlen(str + i++);
	if (!(nstr = (char*)malloc(sizeof(*nstr) * a + 1)))
		return ("ft_cut_before_last_cara: malloc error");
	a = 0;
	while (str[i])
		nstr[a++] = str[i++];
	nstr[a] = str[i];
	return (nstr);
}
