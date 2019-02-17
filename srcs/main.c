/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adejbakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 16:32:06 by adejbakh          #+#    #+#             */
/*   Updated: 2019/02/17 10:26:32 by adejbakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_prints(t_info *p, int a)
{
	t_info	*s;

	p = ft_sort_struc_ascii(p);
	s = p;
	while (p)
	{
		if (p->name[0] != '.' && a == 1)
			ft_putendl(p->name);
		if (a != 1)
			ft_putendl(p->name);
		p = p->next;
	}
	ft_free_struc(s);
	return (1);
}

void	ft_secu_all_argv(char **argv, int i)
{
	while (argv[i])
	{
		if (ft_is_not_a_dir(argv[i]) == 0)
			if (ft_print_error(argv[i]) != 0)
				return ;
		++i;
	}
}

int		ft_security_input(int argc, char **argv)
{
	int	a;
	int	i;

	a = 1;
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
		i++;
	}
	if (!argv[i])
		return (-1);
	while (argv[a])
		if (ft_strlen(argv[a++]) == 0)
			return (ft_print_error(argv[a]));
	ft_sort_argv(argv + i);
	ft_secu_all_argv(argv, i);
	return (0);
}

void	ft_default(int argc, char **argv)
{
	t_info	*p;
	t_info	*s;
	int		i;

	i = 0;
	while (argv[++i])
	{
		if ((p = ft_inspect_file(argv[i])))
		{
			if ((s = ft_opendir(argv[i])))
			{
				if (argc > 2)
					ft_putin(2, argv[i], ":\n");
				ft_prints(s, 1);
				if (i + 1 != argc)
					ft_putstr("\n");
			}
			else
				ft_putendl(argv[i]);
			ft_free_struc(p);
		}
	}
}

int		main(int argc, char **argv)
{
	ft_security_input(argc, argv);
	if (argc == 1)
		return (ft_prints(ft_opendir("."), 1));
	if (argv[1][0] == '-' && ft_strlen(argv[1]) > 1)
		return (ft_menu(argc, argv));
	ft_default(argc, argv);
	return (0);
}
