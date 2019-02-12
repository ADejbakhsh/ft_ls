/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_l_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adejbakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 23:52:24 by adejbakh          #+#    #+#             */
/*   Updated: 2019/02/12 23:53:04 by adejbakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_paddind_total_print(int a, int block)
{
	if (a == -1)
		return ;
	ft_putstr("total ");
	ft_putnbr(block);
	write(1, "\n", 1);
}

void	ft_space(int a, int b)
{
	int	c;

	c = b - a;
	while (--c >= 0)
		write(1, " ", 1);
}
