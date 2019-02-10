/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_not_a_dir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adejbakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 11:19:20 by adejbakh          #+#    #+#             */
/*   Updated: 2019/02/09 21:09:09 by adejbakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_is_not_a_dir(char *str)
{
	t_info *p;

	p = ft_inspect_file(str);
	if (p == NULL)
		return (0);
	ft_free_struc(p);
	return (1);
}

char	**not_dir_option(char **argv, int tab[])
{
	int		i;
	t_info	*p;

	i = 0;
	while (argv[i])
}
