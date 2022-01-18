/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_many_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvixen <cvixen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:18:14 by cvixen            #+#    #+#             */
/*   Updated: 2022/01/12 23:35:32 by cvixen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	find_max_index(t_list **b)
{
	t_list	*tmp;
	int		i;
	int		max;

	tmp = *b;
	max = INT_MIN;
	i = 0;
	while (i < count_list(*b))
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
		i++;
	}
	return (max);
}

static int	find_search_elems_place(t_list **b, int max)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *b;
	while (tmp->next)
	{
		if (tmp->index == max)
			break ;
		tmp = tmp->next;
		i++;
	}
	return (i);
}

static void	sort_b(t_list **a, t_list **b)
{
	int	i;
	int	max;
	int	arguments;

	while (*b)
	{
		arguments = (count_list(*b)) / 2;
		max = find_max_index(b);
		i = find_search_elems_place(b, max);
		if ((*b)->index == max)
			pa(a, b);
		else if (i <= arguments && (*b)->index != max)
			rb(b);
		else if (i > arguments && (*b)->index != max)
			rrb(b);
	}
}

void	sort_many_numbers(t_list **a, t_list **b)
{
	int		i;

	i = 0;
	while (*a)
	{
		if ((*a)->index <= i && i > 0)
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else if ((*a)->index <= (i + 23))
		{
			pb(a, b);
			i++;
		}
		else if ((*a)->index >= i)
			ra(a);
	}
	sort_b(a, b);
}
