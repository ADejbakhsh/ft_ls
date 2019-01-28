/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adejbakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 17:53:55 by adejbakh          #+#    #+#             */
/*   Updated: 2018/11/18 14:11:59 by adejbakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*elem;
	t_list	*start;
	t_list	*tmp;

	if (!(elem = (t_list*)malloc(sizeof(*elem))))
		return (NULL);
	elem = f(lst);
	start = elem;
	tmp = lst->next;
	while (tmp != NULL)
	{
		elem->next = f(tmp);
		tmp = tmp->next;
		elem = elem->next;
	}
	return (start);
}
