/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adejbakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 16:32:06 by adejbakh          #+#    #+#             */
/*   Updated: 2019/01/30 17:20:06 by adejbakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ft_prints(t_info *p, int a)
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

int	ft_security_input(int argc,char **argv)
{
	DIR	*dirp;
	int	i;
	int	c;

	if (argc == 1)
		return (0);
	i = 1;
	c = 0;
	while (argv[i] && argv[i][0] == '-')
		i++;
	while (argv[i])
	{
		dirp = opendir(argv[i]);
		if (dirp == NULL)
		{
			++c;
			write (2, "ls: ", 4);
			ft_putstr_fd(argv[i], 2);
			write (2, ": ", 2);
			ft_putstr_fd(strerror(errno), 2);
			ft_putchar('\n');
		}
		if (dirp)
			closedir(dirp);
		++i;
	}
	return (1);
}

int			main(int argc, char **argv)
{
	ft_security_input(argc, argv); /* pas de message si  */
	if (argc == 1)
		return (ft_prints(ft_opendir("."), 1));
	if (argv[1][0] == '-' && ft_strlen(argv[1]) != 1)
		return (ft_menu(argc, argv));
	argv = ft_sort_argv(argv);
	ft_default(argc, argv);
	return (0);
}
