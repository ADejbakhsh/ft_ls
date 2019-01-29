/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adejbakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 16:12:25 by adejbakh          #+#    #+#             */
/*   Updated: 2019/01/26 16:45:57 by adejbakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

struct s_info	*ft_sort_struc_rev(t_info *p)
{
	t_info	*s;
	int		b;

	b = 1;
	while (b)
	{
		s = p;
		b = 0;
		while (s->next)
		{
			if (ft_strcmp(s->name, s->next->name) < 0)
			{
				ft_swap(s, s->next);
				b = 1;
			}
			s = s->next;
		}
	}
	return (p);
}

struct s_info	*ft_sort_struc_ascii(t_info *p)
{
	t_info	*s;
	int		b;

	b = 1;
	while (b)
	{
		s = p;
		b = 0;
		while (s->next)
		{
			if (ft_strcmp(s->name, s->next->name) > 0)
			{
				ft_swap(s, s->next);
				b = 1;
			}
			s = s->next;
		}
	}
	return (p);
}

struct s_info	*ft_sort_struc_time(t_info *p)
{
	t_info	*s;
	int		b;

	b = 1;
	while (b)
	{
		s = p;
		b = 0;
		while (s->next)
		{
			if (s->nano < s->next->nano)
			{
				ft_swap(s, s->next);
				b = 1;
			}
			s = s->next;
		}
	}
	return (p);
}

struct s_info	*ft_sort_struc_time_rev(t_info *p)
{
	t_info	*s;
	int		b;

	b = 1;
	while (b)
	{
		s = p;
		b = 0;
		while (s->next)
		{
			if (s->nano > s->next->nano)
			{
				ft_swap(s, s->next);
				b = 1;
			}
			s = s->next;
		}
	}
	return (p);
}

struct s_info	*ft_sort_hub(t_info *p, int tab[])
{
	if (tab[2] == 1 && tab[0] == 1)
		return (ft_sort_struc_time_rev(p));
	if (tab[0] == 1)
		return (ft_sort_struc_time(p));
	if (tab[2] == 1)
		return (ft_sort_struc_rev(p));
	return (ft_sort_struc_ascii(p));
}