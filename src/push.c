/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvixen <cvixen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:05:16 by cvixen            #+#    #+#             */
/*   Updated: 2022/01/13 18:29:40 by cvixen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	px(t_list **first_list, t_list **second_list)
{
	t_list	*tmp;

	if (!(*first_list))
		exit(0);
	tmp = *first_list;
	*first_list = (*first_list)->next;
	tmp->next = *second_list;
	*second_list = tmp;
}

void	pa(t_list **a, t_list **b)
{
	px(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_list **a, t_list **b)
{	
	px(a, b);
	write(1, "pb\n", 3);
}
