/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_by_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvixen <cvixen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:15:08 by cvixen            #+#    #+#             */
/*   Updated: 2022/01/12 23:35:13 by cvixen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	case_2(t_list **a)
{
	sa(a);
	rra(a);
}

static void	case_3(t_list **a)
{
	ra(a);
}

static void	case_4(t_list **a)
{
	sa(a);
	ra(a);
}

static void	case_5(t_list **a)
{
	rra(a);
}

void	sort_by_three(t_list **a)
{
	int	first_number;
	int	second_number;
	int	third_number;

	first_number = (*a)->number;
	second_number = (*a)->next->number;
	third_number = (*a)->next->next->number;
	if (first_number > second_number && first_number < third_number)
		sa(a);
	if (first_number > second_number && second_number > third_number)
		case_2(a);
	if (first_number > third_number && second_number < third_number)
		case_3(a);
	if (first_number < third_number && second_number > third_number)
		case_4(a);
	if (first_number < second_number && first_number > third_number)
		case_5(a);
	else
		return ;
}
