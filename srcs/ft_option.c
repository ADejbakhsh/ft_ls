/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adejbakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 11:06:24 by adejbakh          #+#    #+#             */
/*   Updated: 2019/02/22 19:28:24 by adejbakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	ft_open_default(char *str, int tab[])
{
	t_info *p;

	p = ft_opendir(str);
	if (p == NULL)
		return (-1);
	p = ft_sort_hub(p, tab);
	ft_option(p, str, tab);
	if (tab[3] == 1 && tab[4] == 0)
		write(1, "\n", 1);
	return (1);
}

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

int			ft_start_option(char **argv, int tab[])
{
	int		a;
	int		c;

	a = -1;
	if (argv[0][0] == '\0')
		return (ft_open_default(".", tab));
	ft_sort_argv_with_option(argv, tab);
	ft_open_not_dir(argv, tab);
	c = ft_nb_argv_is_two(argv);
	while (argv[++a])
	{
		if (argv[a][0] != 0)
		{
			if (c > 1 && argv[a][0] != 4)
				ft_putin(2, argv[a], ":\n");
			ft_open_default(argv[a], tab);
			if (argv[a + 1] != 0 && argv[a + 1][0] != 4)
				write(1, "\n", 1);
		}
	}
	ft_free_tab(argv);
	return (0);
}

int			ft_print_hub(t_info *p, int a, int l, int r)
{
	if (p == NULL)
		return (0);
	if (l == 1)
		return (ft_print_l(p, a));
	if (a == 0 && p->name[0] == '.')
		return (ft_print_hub(p->next, a, l, r));
	ft_putin(2, p->name, "\n");
	return (ft_print_hub(p->next, a, l, r));
}

int			ft_option(t_info *p, char *str, int tab[])
{
	t_info	*s;

	s = p;
	ft_print_hub(s, tab[1], tab[3], tab[4]);
	if (tab[4] == 1)
		ft_recursive(p, str, tab);
	ft_free_struc(s);
	return (0);
}
