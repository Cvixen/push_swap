/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvixen <cvixen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:47:51 by cvixen            #+#    #+#             */
/*   Updated: 2022/01/16 15:49:56 by cvixen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/checker.h"

char	*ft_strjoin_new(char *s1, char c)
{
	char	*output;
	int		i;
	int		j;

	if (!s1)
		s1 = ft_strdup("");
	output = (char *) malloc((ft_strlen(s1) + 2) * sizeof(char));
	if (!output)
		return (0);
	i = 0;
	j = 0;
	while (s1[j])
		output[i++] = s1[j++];
	output[i++] = c;
	output[i] = 0;
	free(s1);
	s1 = NULL;
	return (output);
}

static int	read_type_sort_2(char *remainder, t_list **a, t_list **b)
{
	if (!ft_strncmp(remainder, "pa", 4))
		pa(a, b);
	else if (!ft_strncmp(remainder, "pb", 4))
		pb(a, b);
	else if (!ft_strncmp(remainder, "rra", 4))
		rra(a);
	else if (!ft_strncmp(remainder, "rrb", 4))
		rrb(b);
	else if (!ft_strncmp(remainder, "rrr", 4))
		rrr(a, b);
	else
		return (0);
	return (1);
}

static void	read_type_sort(char *remainder, t_list **a, t_list **b)
{
	if (!remainder)
		return ;
	else if (!ft_strncmp(remainder, "sa", 4))
		sa(a);
	else if (!ft_strncmp(remainder, "sb", 4))
		sb(b);
	else if (!ft_strncmp(remainder, "ss", 4))
		ss(a, b);
	else if (!ft_strncmp(remainder, "ra", 4))
		ra(a);
	else if (!ft_strncmp(remainder, "rb", 4))
		rb(b);
	else if (!ft_strncmp(remainder, "rr", 4))
		rr(a, b);
	else if (!read_type_sort_2(remainder, a, b))
	{
		write(1, "Error\n", 6);
		exit(-1);
	}
}

void	read_sort(t_list **a, t_list **b)
{
	char	*remainder;
	char	c;

	remainder = NULL;
	while (read(0, &c, 1))
	{
		if (c == '\n')
		{
			read_type_sort(remainder, a, b);
			free(remainder);
			remainder = ft_strdup("");
		}
		else
			remainder = ft_strjoin_new(remainder, c);
	}
	free(remainder);
}
