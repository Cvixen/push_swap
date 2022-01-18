/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvixen <cvixen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:07:29 by cvixen            #+#    #+#             */
/*   Updated: 2022/01/13 20:01:11 by cvixen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/checker.h"

static void	rrx(t_list **head)
{
	t_list	*tmp;
	t_list	*penultimate_list;

	if (!(*head))
		exit(0);
	tmp = (*head);
	while ((*head)->next->next)
		(*head) = (*head)->next;
	penultimate_list = (*head);
	(*head) = (*head)->next;
	penultimate_list->next = NULL;
	(*head)->next = tmp;
}

void	rra(t_list **a)
{
	rrx(a);
}

void	rrb(t_list **b)
{
	rrx(b);
}

void	rrr(t_list **a, t_list **b)
{
	rrx(a);
	rrx(b);
}
