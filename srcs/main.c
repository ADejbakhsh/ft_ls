/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adejbakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 16:32:06 by adejbakh          #+#    #+#             */
/*   Updated: 2019/03/05 11:59:22 by adejbakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_secu_all_argv(char **argv, int i)
{
	while (argv[i])
	{
		if (ft_is_not_a_dir(argv[i]) == 0)
			if (ft_print_error(argv[i]) != 0)
				return ;
		++i;
	}
}

int			ft_print_base(t_info *p, int a)
{
	t_info	*s;

	s = p;
	while (p)
	{
		while (p && p->name[0] == '.' && a == 0)
			p = p->next;
		if (!p)
			break ;
		ft_putendl(p->name);
		p = p->next;
	}
	ft_free_struc(s);
	return (0);
}

static int	ft_security_second_part(char **argv, int i)
{
	int a;

	a = i;
	while (argv[i])
	{
		if (ft_strlen(argv[i]) == 0)
		{
			ft_print_error(NULL);
			exit(0);
		}
		i++;
	}
	ft_secu_all_argv(argv, a);
	return (0);
}

int			ft_security_input(int argc, char **argv, int tab[])
{
	int	i;

	i = 1;
	if (argc == 1)
		return (0);
	while (argv[i] && argv[i][0] == '-' && ft_strlen(argv[i]) > 1)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-' && argv[i][2] == '\0')
		{
			i++;
			break ;
		}
		ft_flag(argv[i], tab);
		i++;
	}
	if (!argv[i])
		return (0);
	ft_sort_argv(argv + i);
	return (ft_security_second_part(argv, i));
}

int			main(int argc, char **argv)
{
	char	**n_avg;
	int		tab[5];

	ft_int_tab(tab, 5);
	if (argc == 1)
		return (ft_print_base(ft_sort_struc_ascii(ft_opendir(".")), 0));
	ft_security_input(argc, argv, tab);
	if (!(n_avg = argv_without_option(argc, argv)))
		return (-1);
	ft_sort_argv(n_avg);
	if (!ft_print_all(n_avg, tab))
		return (-1);
	return (0);
}
