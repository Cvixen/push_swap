/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvixen <cvixen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 23:36:26 by cvixen            #+#    #+#             */
/*   Updated: 2022/01/13 20:56:42 by cvixen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../../libft/libft.h"

typedef struct s_list
{
	int				number;
	struct s_list	*next;
	int				index;
}	t_list;

t_list	*ft_lstnew(int number);
int		count_list(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		check_line(char **argv);
int		ordered_argv(char **argv);
void	create_list(t_list **head, char **argv);
void	free_list(t_list **head);
void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
char	*ft_strjoin_new(char *s1, char c);
void	checker(int argc, char **argv);
void	read_sort(t_list **a, t_list **b);

#endif