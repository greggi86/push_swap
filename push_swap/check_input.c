/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grbuchne <grbuchne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:15:45 by gregor.buch       #+#    #+#             */
/*   Updated: 2024/02/16 17:33:00 by grbuchne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_check(t_stack *a, t_stack *b)
{
	int	len;

	len = ft_lstsize(a) + 1;
	if (len == 2)
		sort2(a);
	else if (len == 3)
		sort3(a);
	else if (len == 4)
	{
		sort4(a, b);
	}
	else if (len == 5)
	{
		sort5(a, b);
	}
	else
	{
		radix_sort(a, b);
	}
}

void	error_check_ac_two(char **args, int i, t_stack *a, t_stack *b)
{
	long	tmp;

	tmp = ft_atoi(args[i]);
	if (!ft_isnum(args[i]))
	{
		ft_free(args);
		error_out(a, b);
	}
	if (ft_contains(tmp, args, i))
	{
		ft_free(args);
		error_out(a, b);
	}
	if (tmp <= -2147483648 || tmp >= 2147483647)
	{
		ft_free(args);
		error_out(a, b);
	}
}

void	error_check_ac_more(char **args, int i, t_stack *a, t_stack *b)
{
	long	tmp;

	tmp = ft_atoi(args[i]);
	if (!ft_isnum(args[i]))
	{
		error_out(a, b);
	}
	if (ft_contains(tmp, args, i))
	{
		error_out(a, b);
	}
	if (tmp <= -2147483648 || tmp >= 2147483647)
	{
		error_out(a, b);
	}
}

void	check_input(int argc, char **argv, t_stack *a, t_stack *b)
{
	int		i;
	char	**args;	

	i = 0;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		while (args[i])
		{
			error_check_ac_two(args, i, a, b);
			i++;
		}
	}
	else
	{
		i = 0;
		args = argv;
		while (args[++i])
			error_check_ac_more(args, i, a, b);
	}
	if (argc == 2)
		ft_free(args);
}

int	ft_contains(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}
