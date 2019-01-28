/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adejbakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 20:28:17 by adejbakh          #+#    #+#             */
/*   Updated: 2019/01/24 18:06:41 by adejbakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	ft_month_to_nu(char *str)
{
	if (!(ft_strcmp(str, "Jan")))
		return (0);
	if (!(ft_strcmp(str, "Feb")))
		return (1);
	if (!(ft_strcmp(str, "Mar")))
		return (2);
	if (!(ft_strcmp(str, "Apr")))
		return (3);
	if (!(ft_strcmp(str, "May")))
		return (4);
	if (!(ft_strcmp(str, "Jun")))
		return (5);
	if (!(ft_strcmp(str, "Jul")))
		return (6);
	if (!(ft_strcmp(str, "Aug")))
		return (7);
	if (!(ft_strcmp(str, "Sep")))
		return (8);
	if (!(ft_strcmp(str, "Oct")))
		return (9);
	if (!(ft_strcmp(str, "Nov")))
		return (10);
	return (11);
}

int			ft_puttime(char *str, size_t b)
{
	size_t a;

	if (str == NULL)
		return (0);
	str[10] = '\0';
	a = ft_atoi(str + 8) * DAY;
	str[10] = ' ';
	str[13] = '\0';
	a += ft_atoi(str + 11) * HOUR;
	str[13] = ' ';
	str[16] = '\0';
	a += ft_atoi(str + 14) * MIN;
	str[16] = ' ';
	str[19] = '\0';
	a += ft_atoi(str + 17);
	str[19] = ' ';
	a += (ft_atoi(str + 20) - 1970) * YEAR;
	str[7] = '\0';
	a += ft_month_to_nu(str + 4) * MONTH;
	str[7] = ' ';
	free(str);
	if ((b - a) + DAY < (YEAR / 2))
		return (0);
	return (1);
}
