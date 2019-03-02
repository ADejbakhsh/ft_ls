/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adejbakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 11:02:35 by adejbakh          #+#    #+#             */
/*   Updated: 2019/03/02 23:29:02 by adejbakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		ft_print_r_base(t_info *p, int a)
{
	while (p)
	{
		while (p && p->name[0] == '.' && a == 0)
			p = p->next;
		if (!p)
			break ;
		ft_putendl(p->name);
		p = p->next;
	}
	return (0);
}

static int		ft_nodouble(char *str, char *mode, int tab)
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

static void		ft_recursive_sat(char *t, t_info *p, t_info *s, int tab[])
{
	if (ft_nodouble(t, p->mode, tab[1]) != 0)
	{
		write(1, "\n", 1);
		ft_putin(2, t, ":\n");
		s = ft_opendir(t);
		if (!s)
			ft_print_error(p->name);
		else
		{
			ft_free_struc(s);
			ft_print_option(t, tab);
		}
	}
}

int				ft_recursive(t_info *p, char *str, int tab[])
{
	t_info	*s;
	t_info	*sit;
	char	*t;

	s = p;
	sit = p;
	if (tab[3] == 0)
		ft_print_r_base(ft_sort_hub(s, tab), tab[1]);
	else
		ft_print_l(s, tab[1], tab[4]);
	while (p)
	{
		t = ft_naming(str, p->name);
		ft_recursive_sat(t, p, s, tab);
		ft_strdel(&t);
		p = p->next;
	}
	ft_free_struc(sit);
	return (0);
}
