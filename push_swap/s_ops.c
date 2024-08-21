/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_ops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grbuchne <grbuchne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:52:17 by gregor.buch       #+#    #+#             */
/*   Updated: 2024/02/16 12:03:45 by grbuchne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swapr(t_stack *stack)
{
	t_node	*head;
	t_node	*next;
	int		tmp_val;
	int		tmp_index;

	if (ft_lstsize(stack) < 2)
		return (-1);
	head = stack->top;
	next = head->next;
	tmp_val = head->data;
	tmp_index = head->index;
	head->data = next->data;
	head->index = next->index;
	next->data = tmp_val;
	next->index = tmp_index;
	return (0);
}

void	sa(t_stack *a)
{
	swapr(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	swapr(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	swapr(a);
	swapr(b);
	write(1, "ss\n", 3);
}
