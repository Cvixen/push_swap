/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvixen <cvixen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:53:03 by cvixen            #+#    #+#             */
/*   Updated: 2022/01/13 16:42:42 by cvixen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/checker.h"

t_list	*ft_lstnew(int number)
{
	t_list	*f;

	f = malloc(sizeof(t_list));
	if (!f)
		return (NULL);
	f->number = number;
	f->next = NULL;
	return (f);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	count_list(t_list *lst)
{
	int	i;

	i = 1;
	while (lst->next)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (lst && *lst)
	{
		new->next = *lst;
		*lst = new;
	}
	else
	{
		new->next = NULL;
		*lst = new;
	}
}
