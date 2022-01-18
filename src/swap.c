/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvixen <cvixen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:22:02 by cvixen            #+#    #+#             */
/*   Updated: 2022/01/13 19:59:07 by cvixen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	write(1, "sa\n", 3);
}

void	sb(t_list **b)
{
	sx(b);
	write(1, "sb\n", 3);
}

void	ss(t_list **a, t_list **b)
{
	sx(a);
	sx(b);
	write(1, "ss\n", 3);
}
