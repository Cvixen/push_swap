/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvixen <cvixen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:08:53 by cvixen            #+#    #+#             */
/*   Updated: 2022/01/13 20:01:06 by cvixen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/checker.h"

static void	rx(t_list **head)
{
	t_list	*tmp_head;
	t_list	*last_list;

	if (!(*head))
		exit(0);
	tmp_head = (*head);
	(*head) = (*head)->next;
	last_list = ft_lstlast((*head));
	last_list->next = tmp_head;
	tmp_head->next = NULL;
}

void	ra(t_list **a)
{
	rx(a);
}

void	rb(t_list **b)
{
	rx(b);
}

void	rr(t_list **a, t_list **b)
{
	rx(a);
	rx(b);
}
