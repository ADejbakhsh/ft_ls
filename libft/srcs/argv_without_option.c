/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_without_option.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adejbakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 17:42:40 by adejbakh          #+#    #+#             */
/*   Updated: 2019/02/09 17:57:40 by adejbakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**argv_without_option(int argc, char **argv)
{
	int	i;

	i = 1;
	while (argv[i] && argv[i][0] == '-')
		i++;
	if (!(argv[i]))
		return (NULL);
	return (argv_to_tab(argc, argv, i));
}
