/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adejbakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 14:50:38 by adejbakh          #+#    #+#             */
/*   Updated: 2019/02/22 18:18:37 by adejbakh         ###   ########.fr       */
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

static void	ft_tab_option_filler(int tab[], char *str)
{
	tab[0] = (ft_strchr(str, 't') != 0) ? 1 : tab[0];
	tab[1] = (ft_strchr(str, 'a') != 0) ? 1 : tab[1];
	tab[2] = (ft_strchr(str, 'r') != 0) ? 1 : tab[2];
	tab[3] = (ft_strchr(str, 'l') != 0) ? 1 : tab[3];
	tab[4] = (ft_strchr(str, 'R') != 0) ? 1 : tab[4];
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
		if (argv[a][0] == '-' && argv[a][1] == '-' && argv[a][2] == '\0')
			break ;
		if (ft_str_contain_only((argv[a] + 1), "lratR") == 0)
		{
			ft_putstr("ls : illegal option -- ");
			ft_putchar(ft_dif(argv[a], "lratR"));
			ft_putendl("\nusage : ls [-lratR] [file ...]");
			return (1);
		}
		ft_tab_option_filler(tab, argv[a]);
		++a;
	}
	if (!(n_avg = argv_without_option(argc, argv)))
			return (-1);
	return (ft_start_option(n_avg, tab));
}
