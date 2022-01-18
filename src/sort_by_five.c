/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_by_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvixen <cvixen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:13:09 by cvixen            #+#    #+#             */
/*   Updated: 2022/01/12 23:39:59 by cvixen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	find_min(t_list **a)
{
	t_list	*tmp;
	int		min;

	min = INT_MAX;
	tmp = (*a);
	while (tmp)
	{
		if (min > tmp->number)
			min = tmp->number;
		tmp = tmp->next;
	}
	return (min);
}

static void	ft_moves(t_list **a, t_list **b, int argc)
{
	int		small;
	t_list	*tmp;

	tmp = *a;
	small = find_min(a);
	if (tmp->next->number == small)
		sa(a);
	else if (tmp->next->next->number == small)
	{
		ra(a);
		ra(a);
	}
	else if (tmp->next->next->next->number == small && argc == 6)
	{
		rra(a);
		rra(a);
	}
	else if ((tmp->next->next->next->number == small && argc == 5) \
	|| (tmp->number != small && argc == 6))
		rra(a);
	pb(a, b);
}

void	sort_by_five(t_list **a, t_list **b, int argc)
{
	int	i;

	i = argc;
	while (i != 4)
		ft_moves(a, b, i--);
	sort_by_three(a);
	pa(a, b);
	if (argc == 6)
		pa(a, b);
}
