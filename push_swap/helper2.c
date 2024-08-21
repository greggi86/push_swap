/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grbuchne <grbuchne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 23:54:49 by gregor.buch       #+#    #+#             */
/*   Updated: 2024/02/16 13:07:04 by grbuchne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack_a)
{
	t_node	*head;

	if (!stack_a)
		return (1);
	head = stack_a->top;
	if (head == NULL)
		return (0);
	while (head->next != NULL)
	{
		if (head->data > head->next->data)
			return (0);
		head = head->next;
	}
	return (1);
}

int	get_min(t_stack *stack)
{
	t_node	*head;
	t_node	*min;

	head = stack->top;
	min = head;
	while (head->next)
	{
		head = head->next;
		if ((head->data < min->data))
			min = head;
	}
	return (min->index);
}

int	is_max(t_stack *stack_a)
{
	t_node	*head;
	int		max;

	head = stack_a->top;
	max = head->data;
	while (head->next)
	{
		head = head->next;
		if (head->data > max)
			max = head->data;
	}
	return (max);
}

int	get_distance(t_stack *stack, int index)
{
	t_node	*head;
	int		distance;

	distance = 0;
	head = stack->top;
	while (head)
	{
		if (head->index == index)
			break ;
		distance++;
		head = head->next;
	}
	return (distance);
}

void	error_out(t_stack *a, t_stack *b)
{
	write(1, "Error", 5);
	free(a);
	free(b);
	exit(1);
}
