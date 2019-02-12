/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adejbakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 11:06:24 by adejbakh          #+#    #+#             */
/*   Updated: 2019/02/12 23:47:08 by adejbakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_open_default(char *str, int tab[])
{
	t_info *p;

	p = ft_opendir(str);
	if (p == NULL)
		return ;
	p = ft_sort_hub(p, tab);
	ft_option(p, str, tab);
}

int			ft_start_option(char **argv, int tab[])
{
	int		a;
	int		c;

	a = -1;
	if (!argv)
	{
		ft_open_default(".", tab);
		return (1);
	}
	ft_sort_argv(argv);
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
		return (ft_print_l(p, a, r));
	if (a == 0 && p->name[0] == '.')
	{
		ft_print_hub(p->next, a, l, r);
		return (0);
	}
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
