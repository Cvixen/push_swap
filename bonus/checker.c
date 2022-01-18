/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvixen <cvixen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:56:09 by cvixen            #+#    #+#             */
/*   Updated: 2022/01/18 14:29:26 by cvixen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/checker.h"

static void	ok_or_ko(t_list **a, t_list **b)
{
	t_list	*tmp_head;

	tmp_head = *a;
	while (tmp_head->next)
	{
		if (tmp_head->number > tmp_head->next->number)
		{
			ft_putstr_fd("KO\n", 1);
			break ;
		}
		tmp_head = tmp_head->next;
	}
	if (tmp_head->next == NULL && *b == NULL)
		ft_putstr_fd("OK\n", 1);
	else if (*b != NULL && tmp_head->next == NULL)
		ft_putstr_fd("KO\n", 1);
	tmp_head = (*b);
}

void	checker(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	b = NULL;
	if (argc == 1)
		exit(0);
	if (check_line(argv))
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	if (argc == 1)
		exit(0);
	create_list(&a, argv);
	read_sort(&a, &b);
	ok_or_ko(&a, &b);
	free_list(&a);
}

int	main(int argc, char **argv)
{
	int		one_line;
	char	*str;
	int		i;

	one_line = 0;
	if (argc == 2)
	{	
		i = -1;
		str = "a ";
		argv[1] = ft_strjoin(str, argv[1]);
		argv = ft_split(argv[1], ' ');
		argc = 0;
		while (argv[++i])
				argc++;
		one_line = 1;
	}
	checker(argc, argv);
	if (one_line)
		exit(0);
	return (0);
}
