/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvixen <cvixen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:47:51 by cvixen            #+#    #+#             */
/*   Updated: 2022/01/13 16:42:32 by cvixen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/checker.h"

static int	only_number(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			if (argv[i][j] == '-')
				j++;
			if (!ft_isdigit(argv[i][j]))
				return (1);
		}
	}
	return (0);
}

static int	overflow(char **argv)
{
	int	i;

	i = 0;
	while (argv[++i])
	{
		if (ft_atoi(argv[i]) > INT_MAX || ft_atoi(argv[i]) < INT_MIN)
			return (1);
	}
	return (0);
}

static int	dublicate(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[(++i) + 1])
	{
		j = i;
		while (argv[++j])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
		}
	}
	return (0);
}

int	ordered_argv(char **argv)
{
	int	i;

	i = 1;
	while (argv[i + 1])
	{
		if (ft_atoi(argv[i]) > ft_atoi(argv[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

int	check_line(char **argv)
{
	if (only_number(argv) == 1 || overflow(argv) == 1 || dublicate(argv) == 1)
		return (1);
	return (0);
}
