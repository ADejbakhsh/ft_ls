/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_link.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adejbakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 16:10:55 by adejbakh          #+#    #+#             */
/*   Updated: 2019/02/17 13:35:17 by adejbakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_swap_more(t_info *a, t_info *b)
{
	long	s;
	char	*tmp;
	int		i;

	tmp = a->link;
	a->link = b->link;
	b->link = tmp;
	tmp = a->major;
	a->major = b->major;
	b->major = tmp;
	tmp = a->minor;
	a->minor = b->minor;
	b->minor = tmp;
	i = a->block;
	a->block = b->block;
	b->block = i;
	s = a->nano;
	a->nano = b->nano;
	b->nano = s;
	tmp = a->usr_id;
	a->usr_id = b->usr_id;
	b->usr_id = tmp;
}

void			ft_swap(t_info *a, t_info *b)
{
	char	*tmp;

	tmp = a->name;
	a->name = b->name;
	b->name = tmp;
	tmp = a->mode;
	a->mode = b->mode;
	b->mode = tmp;
	tmp = a->time;
	a->time = b->time;
	b->time = tmp;
	tmp = a->size;
	a->size = b->size;
	b->size = tmp;
	tmp = a->owner;
	a->owner = b->owner;
	b->owner = tmp;
	tmp = a->group;
	a->group = b->group;
	b->group = tmp;
	tmp = a->nbl;
	a->nbl = b->nbl;
	b->nbl = tmp;
	ft_swap_more(a, b);
}
