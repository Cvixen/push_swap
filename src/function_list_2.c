/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_list_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvixen <cvixen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:53:03 by cvixen            #+#    #+#             */
/*   Updated: 2022/01/12 23:39:49 by cvixen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	create_list(t_list **head, char **argv)
{
	int	i;

	i = 1;
	(*head) = ft_lstnew(ft_atoi(argv[1]));
	while (argv[++i])
	{
		ft_lstadd_back(head, ft_lstnew(ft_atoi(argv[i])));
	}
}

void	free_list(t_list **head)
{
	if ((*head)->next != NULL)
		free_list(&(*head)->next);
	free(*head);
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
