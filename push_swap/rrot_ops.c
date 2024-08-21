/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrot_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grbuchne <grbuchne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:31:05 by gregor.buch       #+#    #+#             */
/*   Updated: 2024/02/16 12:04:15 by grbuchne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*lst2nd2none(t_stack *lst)
{
	t_node	*cur;

	cur = lst->top;
	while (cur->next->next != NULL)
	{
		cur = cur->next;
	}
	return (cur);
}

void	rr_op(t_stack *stack)
{
	t_node	*last;
	t_node	*temp;

	if (stack->top != NULL && stack->top->next != NULL)
	{
		temp = lst2nd2none(stack);
		last = temp->next;
		temp->next = NULL;
		last->next = stack->top;
		stack->top = last;
	}
}

void	rra(t_stack *a)
{
	rr_op(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	rr_op(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	rr_op(a);
	rr_op(b);
	write(1, "rrr\n", 4);
}
