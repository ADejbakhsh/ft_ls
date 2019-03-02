/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_a_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adejbakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 17:13:32 by adejbakh          #+#    #+#             */
/*   Updated: 2019/03/03 00:15:50 by adejbakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_is_not_a_dir(char *str)
{
	t_info *p;

	if (!(p = ft_inspect_file(str)))
		return (0);
	ft_free_struc(p);
	return (1);
}

void	ft_open_not_dir_if_not_dir(char **argv, int i, int tab[], t_info *p)
{
	if((p->mode[0] == 'd' || p->mode[0] == 'l') && tab[3] == 0)
	{
		ft_print_base(ft_sort_hub(p, tab), tab[1]);
		return ;
	}
	argv[i][0] = 4;
	if (tab[3] == 1)
		ft_print_l(p, -1, 0);
	else
	{
		ft_putendl(p->name);
		ft_free_struc(p);
	}
}

char	**ft_open_not_dir(char **argv, int tab[])
{
	t_info	*p;
	int		i;

	i = 0;
	while (argv[i])
	{
		p = ft_inspect_file(argv[i]);
		if (p && tab[3] == 1 && (p->mode[0] == 'd' || (p->mode[0] == 'l'
			&& (argv[i][ft_strlen(argv[i])] == '/'))))
			ft_free_struc(p);
		else if (p)
			ft_open_not_dir_if_not_dir(argv, i, tab, p);
		else
			argv[i][0] = 4;
		i++;
	}
	return (argv);
}

void	ft_free_tab(char **argv)
{
	int	a;

	if (!argv)
		return ;
	a = 0;
	while (argv[a])
		free(argv[a++]);
	free(argv);
	argv = NULL;
}
