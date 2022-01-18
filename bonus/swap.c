/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvixen <cvixen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:22:02 by cvixen            #+#    #+#             */
/*   Updated: 2022/01/13 20:00:57 by cvixen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/checker.h"

static void	sx(t_list **head)
{
	t_list	*tmp;

	if (!(*head) || !(*head)->next)
		exit(0);
	tmp = *head;
	*head = (*head)->next;
	tmp->next = (*head)->next;
	(*head)->next = tmp;
}

void	sa(t_list **a)
{
	sx(a);
}

void	sb(t_list **b)
{
	sx(b);
}

void	ss(t_list **a, t_list **b)
{
	sx(a);
	sx(b);
}
