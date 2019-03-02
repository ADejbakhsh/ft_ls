/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adejbakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 16:12:25 by adejbakh          #+#    #+#             */
/*   Updated: 2019/03/02 23:05:38 by adejbakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

struct s_info	*ft_sort_struc_ascii(t_info *p)
{
	t_info	*s;
	int		b;

	b = 1;
	while (b)
	{
		s = p;
		s = s->next;
		b = 0;
		while (s && s->next)
		{
			if (ft_strcmp(s->name, s->next->name) > 0)
			{
				ft_swap(&p, s);
				b = 1;
			}
			s = s->next;
		}
	}
	return (p);
}

struct s_info	*ft_sort_struc_time(t_info *head)
{
	t_info	*s;
	int		b;

	b = 1;
	while (b)
	{
		s = head;
		b = 0;
		while (s && s->next)
		{
			if (s->nano < s->next->nano)
			{
				ft_swap(&head, s);
				b = 1;
			}
			if (s && s->next && (s->nano == s->next->nano))
				if (ft_strcmp(s->name, s->next->name) > 0)
					ft_swap(&head, s);
			s = s->next;
		}
	}
	return (head);
}

t_info			*ft_rev_struct(t_info *p)
{
	t_info	*s;
	t_info	*r;

	s = NULL;
	r = p;
	p = p->next;
	r->next = NULL;
	while (p)
	{
		s = p;
		p = p->next;
		s->next = r;
		r = s;
	}
	return (s);
}

struct s_info	*ft_sort_hub(t_info *p, int tab[])
{
	if (tab[2] == 1 && tab[0] == 1)
		return (ft_rev_struct(ft_sort_struc_time(p)));
	if (tab[0] == 1)
		return (ft_sort_struc_time(p));
	ft_sort_struc_ascii(p);
	if (tab[2] == 1)
		return (ft_rev_struct(p));
	return (p);
}
