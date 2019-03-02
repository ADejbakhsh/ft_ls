/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_l.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adejbakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 11:07:23 by adejbakh          #+#    #+#             */
/*   Updated: 2019/02/24 19:22:02 by adejbakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	padding_lenght(t_info *s, int pad[])
{
	int	tmp;

	if ((tmp = ft_strlen(s->nbl)) > pad[0])
		pad[0] = tmp;
	if (s->owner && ((tmp = ft_strlen(s->owner)) > pad[1]))
		pad[1] = tmp;
	if ((tmp = ft_strlen(s->size)) > pad[2])
		pad[2] = tmp;
	if ((tmp = ft_strlen(s->major)) > pad[3])
		pad[3] = tmp;
	if ((tmp = ft_strlen(s->minor)) > pad[4])
		pad[4] = tmp;
	if ((s->group && ((tmp = ft_strlen(s->group))) > pad[5]))
		pad[5] = tmp;
}

static void	ft_padding(t_info *p, int pad[], int a)
{
	t_info	*s;
	int		block;

	s = p;
	block = 0;
	ft_int_tab(pad, 6);
	while (s)
	{
		padding_lenght(s, pad);
		block += s->block;
		s = s->next;
	}
	ft_paddind_total_print(a, block);
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

static void	ft_print_basic(t_info *p, int pad[])
{
	ft_putin(2, p->mode, " ");
	ft_space(ft_strlen(p->nbl), pad[0]);
	ft_putin(2, p->nbl, " ");
	if (p->owner)
	{
		ft_putstr(p->owner);
		ft_space(ft_strlen(p->owner), pad[1]);
	}
	else
	{
		ft_putstr(p->usr_id);
		ft_space(ft_strlen(p->usr_id), pad[1]);
	}
	if (p->group)
	{
		ft_putin(2, "  ", p->group);
		ft_space(ft_strlen(p->group), pad[5]);
	}
}

int			ft_print_l(t_info *p, int a)
{
	t_info	*s;
	int	pad[6];

	s = p;
	ft_padding(p, pad, a);
	while (p)
	{
		while (p && a == 0 && p->name[0] == '.')
			p = p->next;
		if (!(p))
			break ;
		ft_print_basic(p, pad);
		ft_device(p, pad);
		ft_putin(3, p->time, " ", p->name);
		if (p->link[0] != '\0')
			ft_putin(2, " -> ", p->link);
		if (p->next && ((a == 1) || (p->next->name[0] != '.' && a == 0 )))
			write(1, "\n", 1);
		p = p->next;
	}
	write(1, "\n", 1);
	ft_free_struc(s);
	return (0);
}
