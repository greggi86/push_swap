/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_ops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grbuchne <grbuchne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:51:23 by gregor.buch       #+#    #+#             */
/*   Updated: 2024/02/16 12:03:47 by grbuchne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	list_add_front(t_node *new_start, t_stack *stack)
{
	new_start->next = stack->top;
	stack->top = new_start;
}

void	pa(t_stack *src, t_stack *dest)
{
	t_node	*temp;

	temp = src->top->next;
	list_add_front(src->top, dest);
	src->top = temp;
	write(1, "pa\n", 3);
}

void	pb(t_stack *dest, t_stack *src)
{
	t_node	*temp;

	temp = src->top->next;
	list_add_front(src->top, dest);
	src->top = temp;
	write(1, "pb\n", 3);
}
