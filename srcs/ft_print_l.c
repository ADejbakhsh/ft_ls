/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_l.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adejbakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 11:07:23 by adejbakh          #+#    #+#             */
/*   Updated: 2019/01/29 17:16:57 by adejbakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


#include <stdio.h>
static void	ft_padding(t_info *p, int pad[])
{
	t_info	*s;
	int		tmp;
	int		block;

	s = p;
	block = 0;
	ft_int_tab(pad, 5);
	while (s)
	{
		if ((tmp = ft_strlen(s->nbl)) > pad[0])
			pad[0] = tmp;
		if ((tmp = ft_strlen(s->owner)) > pad[1])
			pad[1] = tmp;
		if ((tmp = ft_strlen(s->size)) > pad[2])
			pad[2] = tmp;
		if ((tmp = ft_strlen(s->major)) > pad[3])
			pad[3] = tmp;
		if ((tmp = ft_strlen(s->minor)) > pad[4])
			pad[4] = tmp;
		block += s->block;
		s = s->next;
	}
	ft_putstr("total ");
	ft_putnbr(block);
	write(1, "\n", 1);
}

static void	ft_space(int a, int b)
{
	int	c;

	c = b - a;
	while (--c >= 0)
		write(1 , " ", 1);
}

static int	ft_device(t_info *p, int tab[])
{
	write(1, "  ", 2);
	if (tab[3] > tab[2])
		ft_space(ft_strlen(p->major), tab[3]);
	if (tab[3] < tab[2])
		ft_space(ft_strlen(p->size), tab[2]);
	if (p->mode[0] == 'c')
	{
		ft_putin(2, p->major, ",");
		ft_space(ft_strlen(p->minor), tab[4]);
		ft_putin(2, p->minor, " ");
		return (1);
	}
	ft_putin(2, p->size, " ");
	return (0);
}

int			ft_print_l(t_info *p, int a)
{
	int	pad[5];

	ft_padding(p, pad);
	while (p)
	{
		while (p && a == 1 && p->name[0] == '.')
			p = p->next;
		if (!(p))
			break;
		ft_putin(2, p->mode, " ");
		ft_space(ft_strlen(p->nbl), pad[0]);
		ft_putin(2, p->nbl, " ");
		ft_putstr(p->owner);
		ft_space(ft_strlen(p->owner), pad[1]);
		write(1, "  ", 2); /* add padding here */
		ft_putstr(p->group);
		ft_device(p, pad);
		ft_putin(3, p->time, " ", p->name);
		if (p->link[0] != '\0')
			ft_putin(2, " -> ", p->link);
		write(1, "\n", 1);
		p = p->next;
	}
	return (0);
}
