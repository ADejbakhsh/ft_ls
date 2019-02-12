/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adejbakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 14:50:38 by adejbakh          #+#    #+#             */
/*   Updated: 2019/02/12 23:37:49 by adejbakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ft_print_error(char *str)
{
	write(2, "ls: ", 4);
	if (!str)
	{
		write(2, "fts_open", 8);
		write(2, ": ", 2);
		ft_putstr_fd("No such file or directory\n", 2);
		return (1);
	}
	else
		ft_putstr_fd(str, 2);
	write(2, ": ", 2);
	ft_putstr_fd(strerror(errno), 2);
	write(2, "\n", 2);
	return (0);
}

static char	ft_dif(char *s1, char *s2)
{
	int	a;
	int	b;
	int	c;

	a = 1;
	while (s1[a])
	{
		b = 0;
		c = 0;
		while (s2[b])
		{
			if (s2[b] == s1[a])
				c = 1;
			b++;
		}
		if (c == 0)
			return (s1[a]);
		a++;
	}
	return (0);
}

int			ft_menu(int argc, char **argv)
{
	char	**n_avg;
	int		tab[5];
	int		a;

	ft_int_tab(tab, 5);
	a = 1;
	while (argv[a] && argv[a][0] == '-')
	{
		if (ft_str_contain_only((argv[a] + 1), "lratR") == 0)
		{
			ft_putstr("ls : illegal option -- ");
			ft_putchar(ft_dif(argv[a], "lratR"));
			write(1, "\n", 1);
			ft_putendl("usage : ls [-lratR] [file ...]");
			return (0);
		}
		tab[0] = (ft_strchr(argv[a], 't') != 0) ? 1 : tab[0];
		tab[1] = (ft_strchr(argv[a], 'a') != 0) ? 1 : tab[1];
		tab[2] = (ft_strchr(argv[a], 'r') != 0) ? 1 : tab[2];
		tab[3] = (ft_strchr(argv[a], 'l') != 0) ? 1 : tab[3];
		tab[4] = (ft_strchr(argv[a], 'R') != 0) ? 1 : tab[4];
		++a;
	}
	n_avg = argv_without_option(argc, argv);
	return (ft_start_option(n_avg, tab));
}
