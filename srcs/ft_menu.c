/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adejbakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 14:50:38 by adejbakh          #+#    #+#             */
/*   Updated: 2019/01/30 17:19:59 by adejbakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_default(int argc, char **argv)
{
	t_info	*p;
	int		i;

	i = 0;
	while (argv[++i])
	{
		if ((p = ft_opendir(argv[i])) != NULL)
		{
			if (argc > 2)
				ft_putin(2, argv[i], ":\n");
			ft_prints(ft_opendir(argv[i]), 1);
			if (i + 1 != argc)
				ft_putstr("\n");
			ft_free_struc(p);
		}
	}
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
	int	tab[5];
	int	a;

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
		ft_bzero(argv[a], ft_strlen(argv[a]));
		++a;
	}
	return (ft_start_option(argc, argv, tab));
}
