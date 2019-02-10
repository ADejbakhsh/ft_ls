/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_l.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adejbakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 11:07:23 by adejbakh          #+#    #+#             */
/*   Updated: 2019/02/09 22:24:39 by adejbakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_padding(t_info *p, int pad[], int a)
{
	t_info	*s;
	int		tmp;
	int		block;

	s = p;
	block = 0;
	ft_int_tab(pad, 6);
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
		if ((tmp = ft_strlen(s->group)) > pad[5])
			pad[5] = tmp;
		block += s->block;
		s = s->next;
	}
	if (a != -1)
	{
		ft_putstr("total ");
		ft_putnbr(block);
		write(1, "\n", 1);
	}
}

static void	ft_space(int a, int b)
{
	int	c;

	c = b - a;
	while (--c >= 0)
		write(1 , " ", 1);
}

static int	ft_device(t_info *p, int pad[])
{
	write(1, "  ", 2);
	if (pad[3] != 1 && pad[4] != 1)
	{
		ft_space(ft_strlen(p->major), pad[3]);
		if (p->mode[0] == 'c' || p->mode[0] == 'b')
		{
			ft_putin(2, p->major, ",  ");
			ft_space(ft_strlen(p->minor), pad[4]);
			ft_putin(2, p->minor, " ");
			return (1);
		}
		ft_space(ft_strlen(p->size), pad[4]);
		ft_putin(3, "    ", p->size, " ");
	return (0);
	}
	ft_space(ft_strlen(p->size), pad[2]);
	ft_putin(2, p->size, " ");
	return (0);
}

int			ft_print_l(t_info *p, int a)
{
	int	pad[6];

	ft_padding(p, pad, a);
	while (p)
	{
		while (p && a == 0 && p->name[0] == '.')
			p = p->next;
		if (!(p))
			break;
		ft_putin(2, p->mode, " ");
		ft_space(ft_strlen(p->nbl), pad[0]);
		ft_putin(2, p->nbl, " ");
		ft_putstr(p->owner);
		ft_space(ft_strlen(p->owner), pad[1]);
		ft_putin(2, "  ", p->group);
		ft_space(ft_strlen(p->group), pad[5]);
		ft_device(p, pad);
		ft_putin(3, p->time, " ", p->name);
		if (p->link[0] != '\0')
			ft_putin(2, " -> ", p->link);
		if (p->next)
			write(1, "\n", 1);
		p = p->next;
	}
	if (a == -1)
		write(1, "\n", 1);
	return (0);
}
