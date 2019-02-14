/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_argv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adejbakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 13:46:46 by adejbakh          #+#    #+#             */
/*   Updated: 2019/02/14 16:23:59 by adejbakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_sort_argv(char **argv)
{
	char	*tmp;
	int		a;

	a = 0;
	while (argv[a + 1])
	{
		if (ft_strcmp(argv[a], argv[a + 1]) > 0)
		{
			tmp = argv[a];
			argv[a] = argv[a + 1];
			argv[a + 1] = tmp;
			a = -1;
		}
		++a;
	}
	return (argv);
}

char	**ft_sort_rev_argv(char **argv)
{
	char	*tmp;
	int		a;

	a = 0;
	while (argv[a + 1])
	{
		if (ft_strcmp(argv[a], argv[a + 1]) < 0)
		{
			tmp = argv[a];
			argv[a] = argv[a + 1];
			argv[a + 1] = tmp;
			a = -1;
		}
		++a;
	}
	return (argv);
}
