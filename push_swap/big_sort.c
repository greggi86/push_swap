/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grbuchne <grbuchne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 00:03:06 by gregor.buch       #+#    #+#             */
/*   Updated: 2024/08/21 15:49:57 by grbuchne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_bits(t_stack *stack)
{
	t_node	*head;
	int		max;
	int		max_bits;

	head = stack->top;
	if (head == NULL)
		return (0);
	max = head->index;
	max_bits = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
	{
		++max_bits;
	}
	return (max_bits);
}

void	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	size;
	int	max_bits;
	int	i;
	int	j;

	i = 0;
	size = ft_lstsize(stack_a) + 1;
	max_bits = get_max_bits(stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			if ((stack_a->top->index >> i) & 1)
				ra(stack_a);
			else
				pb(stack_b, stack_a);
		}
		while (stack_b->top != NULL)
			pa(stack_b, stack_a);
		i++;
	}
}

t_node	*get_next_min(t_stack *stack)
{
	t_node	*head;
	t_node	*min;
	int		has_min;

	min = NULL;
	has_min = 0;
	head = stack->top;
	if (head)
	{
		while (head != NULL)
		{
			if ((head->index == -1) && (!has_min || head->data < min->data))
			{
				min = head;
				has_min = 1;
			}
			head = head->next;
		}
	}
	return (min);
}

void	indexer(t_stack *stack)
{
	t_node	*head;
	int		index;

	index = 0;
	head = get_next_min(stack);
	while (head)
	{
		head->index = ++index;
		head = get_next_min(stack);
	}
}
