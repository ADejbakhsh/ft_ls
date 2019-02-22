/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_a_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adejbakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 17:13:32 by adejbakh          #+#    #+#             */
/*   Updated: 2019/02/19 15:56:13 by adejbakh         ###   ########.fr       */
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

char	**ft_open_not_dir(char **argv, int tab[])
{
	t_info	*p;
	int		i;

	i = 0;
	while (argv[i])
	{
		p = ft_inspect_file(argv[i]);
		if (p && (p->mode[0] == 'd' || (p->mode[0] == 'l'
			&& (argv[i][ft_strlen(argv[i])] == '/'))))
			ft_free_struc(p);
		else
		{
			argv[i][0] = 4;
			ft_print_hub(p, -1, tab[3], tab[4]);
			ft_free_struc(p);
		}
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
