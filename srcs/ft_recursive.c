/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adejbakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 11:02:35 by adejbakh          #+#    #+#             */
/*   Updated: 2019/02/12 23:47:36 by adejbakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ft_nb_argv_is_two(char **argv)
{
	int	a;

	a = 0;
	while (argv[a])
		a++;
	return (a);
}

static int	ft_nodouble(char *str, char *mode, int tab)
{
	int	a;

	if (mode[0] != 'd')
		return (0);
	if (mode[1] != 'r')
		return (ft_print_error(str));
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

int			ft_recursive(t_info *p, char *str, int tab[])
{
	t_info	*s;
	char	*t;

	while (p)
	{
		t = ft_naming(str, p->name);
		if (ft_nodouble(t, p->mode, tab[1]) != 0)
		{
			write(1, "\n", 1);
			ft_putin(2, t, ":\n");
			s = ft_opendir(t);
			if (!s)
				ft_print_error(p->name);
			else
			{
				ft_option(ft_sort_hub(s, tab), t, tab);
			}
		}
		ft_strdel(&t);
		p = p->next;
	}
	return (0);
}
