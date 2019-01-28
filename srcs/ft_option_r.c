/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adejbakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 13:12:12 by adejbakh          #+#    #+#             */
/*   Updated: 2019/01/28 10:17:52 by adejbakh         ###   ########.fr       */
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
	ft_option_r(p, str, tab);
}

static int	ft_nb_argv_is_two(int argc, char **argv)
{
	int	a;

	a = 0;
	while (--argc > 0)
		if (argv[argc][0] != '\0')
			a++;
	if (a == 1)
		return (0);
	return (1);
}

int			ft_start_option_r(int argc, char **argv, int tab[])
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
			b = 1;
		}
		a++;
	}
	if (b == 0)
		ft_open_default(".", tab);
	return (0);
}

static int	ft_nodouble(char *str, char *mode, int tab)
{
	int	a;

	if (mode[0] != 'd')
		return (0);
	if (mode[1] != 'r')
	{
		ft_putin(3, "ls: ", str, ": Permission denied\n");
		return (0);
	}
	a = ft_strlen(str);
	if (str[a - 1] == '.' && str[a - 2] == '/')
		return (0);
	if (str[a - 1] == '.' && str[a - 2] == '.' && str[a - 3] == '/')
		return (0);
	if (tab == 0)
	{
		while (str[a] != '/')
			--a;
		if (str[a + 1] == '.')
			return (0);
	}
	return (1);
}

int			ft_option_r(t_info *p, char *str, int tab[])
{
	t_info	*s;
	char	*t;

	if (!(p))
		return (0);
	s = p;
	ft_print_notl(s, tab[1]);
	write(1, "\n", 1);
	while (p)
	{
		t = ft_naming(str, p->name);
		if (ft_nodouble(t, p->mode, tab[1]) != 0)
		{
			ft_putin(2, t, ":\n");
			ft_option_r(ft_sort_hub(ft_opendir(t), tab), t, tab);
		}
		ft_strdel(&t);
		p = p->next;
	}
	ft_free_struc(s);
	return (0);
}
