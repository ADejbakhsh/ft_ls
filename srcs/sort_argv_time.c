/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_argv_time.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adejbakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 16:38:07 by adejbakh          #+#    #+#             */
/*   Updated: 2019/03/05 13:44:26 by adejbakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static	void	ft_free_if_argv(t_info *p, t_info *q)
{
	if (p)
		ft_free_struc(p);
	if (q)
		ft_free_struc(q);
}

int				ft_argv_time(char **argv)
{
	t_info	*p;
	t_info	*q;
	char	*tmp;
	int		i;

	i = 0;
	while (argv[i] && argv[i + 1])
	{
		p = ft_inspect_file(argv[i]);
		q = ft_inspect_file(argv[i + 1]);
		if (p && q)
		{
			if (p->nano < q->nano)
			{
				tmp = argv[i];
				argv[i] = argv[i + 1];
				argv[i + 1] = tmp;
				i = -1;
			}
		}
		ft_free_if_argv(p, q);
		i++;
	}
	return (0);
}

int				ft_argv_time_reverse(char **argv)
{
	t_info	*p;
	t_info	*q;
	char	*tmp;
	int		i;

	i = 0;
	while (argv[i] && argv[i + 1])
	{
		p = ft_inspect_file(argv[i]);
		q = ft_inspect_file(argv[i + 1]);
		if (p && q)
		{
			if (p->nano > q->nano)
			{
				tmp = argv[i];
				argv[i] = argv[i + 1];
				argv[i + 1] = tmp;
				i = -1;
			}
		}
		ft_free_if_argv(p, q);
		i++;
	}
	return (0);
}
