/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adejbakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 11:06:24 by adejbakh          #+#    #+#             */
/*   Updated: 2019/02/24 18:04:33 by adejbakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	ft_sort_argv_with_option(char **argv, int tab[])
{
	if (tab[0] == 1 && tab[2] == 1)
		return (ft_argv_time_reverse(argv));
	if (tab[0] == 1)
		return (ft_argv_time(argv));
	if (tab[2] == 1)
		ft_sort_rev_argv(argv);
	if (tab[2] == 0)
		ft_sort_argv(argv);
	return (0);
}

int		ft_print_option(char *str, int tab[])
{
	t_info	*p;
	t_info	*s;

	if (!(p = ft_opendir(str)))
		return (0);
	p = ft_sort_hub(p, tab);
	s = p;
	if (str[0] == 4)
		return (0);/*
	if (tab[4])
		return (ft_recursive(p, str, tab));*/
	if (tab[3] == 1)
		return (ft_print_l(p, tab[1]));
	ft_print_base(p, tab[1]);
	return (1);
}

int		ft_print_all(char **n_avg, int tab[])
{
	int	i;

	i = 0;
	if (!n_avg)
		exit(-1);
	if (n_avg[0][0] == '\0')
		return (ft_print_option(".", tab));
	ft_sort_argv_with_option(n_avg, tab);
	ft_open_not_dir(n_avg, tab);
	while (n_avg[i])
	{
		ft_print_option(n_avg[i], tab);
		++i;
		if (n_avg[i] && n_avg[i][0] != 4)
			write(1, "\n", 1);
	}
	ft_free_tab(n_avg);
	return (0);
}
