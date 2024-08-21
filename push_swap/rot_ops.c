/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grbuchne <grbuchne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:36:20 by gregor.buch       #+#    #+#             */
/*   Updated: 2024/02/16 12:03:48 by grbuchne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rot(t_stack *a)
{
	t_node	*first_node;
	t_node	*cur;

	if (a->top != NULL && a->top->next != NULL)
	{
		first_node = a->top;
		a->top = first_node->next;
		cur = a->top;
		while (cur->next != NULL)
			cur = cur->next;
		cur->next = first_node;
		first_node->next = NULL;
	}
}

void	ra(t_stack *a)
{
	rot(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	rot(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	rot(a);
	rot(b);
	write(1, "rr\n", 3);
}
