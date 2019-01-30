/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adejbakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 11:06:24 by adejbakh          #+#    #+#             */
/*   Updated: 2019/01/30 17:02:57 by adejbakh         ###   ########.fr       */
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

int			ft_start_option(int argc, char **argv, int tab[])
{
	int		a;
	int		b;
	int		c;

	b = 0;
	a = 1;
	argv = ft_sort_argv(argv);
	c = ft_nb_argv_is_two(argc, argv);
	while (--argc > 0)
	{
		if (argv[a][0] != 0)
		{
			if (c == 1)
				ft_putin(2, argv[a], ":\n");
				ft_open_default(argv[a], tab);
				if (argc > 1)
					write(1, "\n", 1);
			b = 1;
		}
		a++;
	}
	if (b == 0)
		ft_open_default(".", tab);
	return (0);
}

int		ft_print_hub(t_info *p, int a, int l)
{
	if (p == NULL)
		return (0);
	if (l == 1)
		return (ft_print_l(p, a));
	if (a == 0 && p->name[0] == '.')
	{
		ft_print_hub(p->next, a, l);
		return (0);
	}
	ft_putin(2, p->name, "\n");
	return (ft_print_hub(p->next, a, l));
}

int			ft_option(t_info *p, char *str, int tab[])
{
	t_info	*s;

	s = p;
	ft_print_hub(s, tab[1], tab[3]);
	write(1, "\n", 1);
	if (tab[4] == 1)
		ft_recursive(p, str, tab);
	ft_free_struc(s);
	return (0);
}
