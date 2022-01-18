/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvixen <cvixen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:10:15 by cvixen            #+#    #+#             */
/*   Updated: 2022/01/12 18:16:58 by cvixen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	define_index(t_list **a, int *arr)
{
	t_list	*tmp;
	int		i;
	int		size;

	size = count_list(*a);
	tmp = *a;
	while (tmp)
	{
		i = 0;
		while (i < size)
		{
			if (tmp->number == arr[i])
			{
				tmp->index = i;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
}

static void	ft_swap(int	*a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	sort_array(int argc, char **argv, t_list **a)
{
	int		*arr;
	int		i;
	int		j;

	i = 0;
	j = 1;
	arr = malloc(sizeof(int) * (argc - 1));
	while (j < argc)
		arr[i++] = ft_atoi(argv[j++]);
	i = 0;
	while (i != argc - 1)
	{
		j = 0;
		while (j != argc - 2)
		{
			if (arr[j] > arr[j + 1])
				ft_swap(&arr[j], &arr[j + 1]);
			j++;
		}
		i++;
	}
	define_index(a, arr);
	free(arr);
}
