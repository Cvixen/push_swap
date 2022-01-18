/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvixen <cvixen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:56:09 by cvixen            #+#    #+#             */
/*   Updated: 2022/01/14 13:31:23 by cvixen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	type_sort(t_list **a, t_list **b, int argc)
{
	if (argc == 3)
		sa(a);
	if (argc == 4)
		sort_by_three(a);
	if (argc == 5 || argc == 6)
		sort_by_five(a, b, argc);
	if (argc > 6)
		sort_many_numbers(a, b);
}

void	free_argv(int argc, char **argv)
{
	while (argc != 0)
	{
		free(argv[argc - 1]);
		argc--;
	}
	free(argv);
}

void	push_swap(int argc, char **argv)
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
	if (ordered_argv(argv))
		exit(0);
	create_list(&a, argv);
	sort_array(argc, argv, &a);
	type_sort(&a, &b, argc);
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
	push_swap(argc, argv);
	if (one_line)
		free_argv(argc, argv);
	return (0);
}
