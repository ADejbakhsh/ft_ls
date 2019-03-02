/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_link.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adejbakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 16:10:55 by adejbakh          #+#    #+#             */
/*   Updated: 2019/03/02 16:44:52 by adejbakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_swap(t_info **head, t_info *curr)
{
	t_info	*tmp_head;
	t_info	*tmp;

	tmp_head = *head;
	if (*head == curr)
	{
		tmp = curr->next;
		curr->next = curr->next->next;
		tmp->next = curr;
		*head = tmp;
	}
	else if (curr->next && curr->next->next == NULL)
	{
		while (tmp_head->next != curr)
			tmp_head = tmp_head->next;
		tmp_head->next = curr->next;
		curr->next->next = curr;
		curr->next = NULL;
	}
	else
	{
		while (tmp_head->next != curr)
			tmp_head = tmp_head->next;
		tmp_head->next = curr->next;
		curr->next = curr->next->next;
		tmp_head->next->next = curr;
	}
}
