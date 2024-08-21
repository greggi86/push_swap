/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grbuchne <grbuchne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 22:01:26 by grbuchne          #+#    #+#             */
/*   Updated: 2024/02/16 12:26:30 by grbuchne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_stack *stack, t_node *new)
{
	t_node	*n;

	if (stack == NULL)
	{
		stack = malloc(sizeof(t_stack));
		stack->top = new;
		stack->top->next = NULL;
		return ;
	}
	n = ft_lstlast(stack);
	if (n == NULL)
	{
		(stack)->top = new;
	}
	else
	{
		n->next = new;
	}
	new->next = NULL;
}

int	ft_lstsize(t_stack *lst)
{
	t_node	*cur;
	int		i;

	i = 0;
	cur = lst->top;
	if (lst == NULL || cur == NULL)
		return (-1);
	while (cur->next != NULL)
	{
		cur = cur->next;
		i++;
	}
	return (i);
}

t_node	*ft_lstnew(int data)
{
	t_node	*new;

	new = (t_node *) malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->data = data;
	new->index = -1;
	new->next = NULL;
	return (new);
}

t_node	*ft_lstlast(t_stack *lst)
{
	t_node	*cur;

	if (lst == NULL || lst->top == NULL)
	{
		return (NULL);
	}
	cur = lst->top;
	while (cur->next)
	{
		cur = cur->next;
	}
	return (cur);
}
