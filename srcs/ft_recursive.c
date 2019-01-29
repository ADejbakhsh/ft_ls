/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adejbakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 11:02:35 by adejbakh          #+#    #+#             */
/*   Updated: 2019/01/29 11:02:40 by adejbakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	ft_nb_argv_is_two(int argc, char **argv)
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

int		ft_recursive(t_info *p, char *str, int tab[])
{
	char *t;

	while (p)
	{
		t = ft_naming(str, p->name);
		if (ft_nodouble(t, p->mode, tab[1]) != 0)
		{
			ft_putin(2, t, ":\n");
			ft_option(ft_sort_hub(ft_opendir(t), tab), t, tab);
		}
		ft_strdel(&t);
		p = p->next;
	}
	return (0);
}
