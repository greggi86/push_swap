/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smaLL-sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gregor.buchner <gregor.buchner@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:17:56 by gregor.buch       #+#    #+#             */
/*   Updated: 2024/02/02 00:08:10 by gregor.buch      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort2(t_stack *stack_a)
{
	if (stack_a->top->data > stack_a->top->next->data)
		sa(stack_a);
}

void	sort3(t_stack *stack_a)
{
	int		max;

	max = is_max(stack_a);
	if (max == stack_a->top->data)
		ra(stack_a);
	if (stack_a->top->next->data == max)
		rra(stack_a);
	if (stack_a->top->data > stack_a->top->next->data)
		sa(stack_a);
}

void	sort4(t_stack *stack_a, t_stack *stack_b)
{
	int	distance;

	if (is_sorted(stack_a))
		return ;
	distance = get_distance(stack_a, get_min(stack_a));
	if (distance == 1)
		ra(stack_a);
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distance == 3)
		rra(stack_a);
	if (is_sorted(stack_a))
		return ;
	pb(stack_b, stack_a);
	sort3(stack_a);
	pa(stack_b, stack_a);
}

void	sort5(t_stack *stack_a, t_stack *stack_b)
{
	int	distance;

	distance = get_distance(stack_a, get_min(stack_a));
	if (distance == 1)
		ra(stack_a);
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distance == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (distance == 4)
		rra(stack_a);
	if (is_sorted(stack_a))
		return ;
	pb(stack_b, stack_a);
	sort4(stack_a, stack_b);
	pa(stack_b, stack_a);
}
