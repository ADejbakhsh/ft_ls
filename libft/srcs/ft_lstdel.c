/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adejbakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 16:46:44 by adejbakh          #+#    #+#             */
/*   Updated: 2018/11/18 11:18:14 by adejbakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;

	if (alst == NULL || del == NULL)
		return ;
	while ((*alst))
	{
		tmp = (*alst);
		del(tmp->content, tmp->content_size);
		free(tmp);
		*alst = (*alst)->next;
	}
}
