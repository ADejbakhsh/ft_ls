/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adejbakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 12:23:13 by adejbakh          #+#    #+#             */
/*   Updated: 2019/01/24 12:58:12 by adejbakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_int_tab(int tab[], int size)
{
	if (size <= 0)
		return (write(1, "ft_int_tab : size must be stricly positive\n", 42));
	while (--size >= 0)
		tab[size] = 0;
	return (0);
}
