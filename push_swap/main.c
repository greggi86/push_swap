/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grbuchne <grbuchne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:11:49 by gregor.buch       #+#    #+#             */
/*   Updated: 2024/02/16 11:35:48 by grbuchne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_stack *list)
{
	t_node	*temp;
	t_node	*temp2;

	temp = list->top;
	if (temp == NULL)
		return ;
	if (temp->next != NULL)
		temp2 = temp->next;
	while (temp->next != NULL)
	{
		temp2 = temp->next;
		free(temp);
		temp = temp2;
	}
	free(temp);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = malloc(sizeof(t_stack *));
	b = malloc(sizeof(t_stack *));
	a->top = NULL;
	b->top = NULL;
	check_input(ac, av, a, b);
	initialize_stack(a, ac, av);
	if (is_sorted(a))
		return (free_list(a), free(a), free(b), 0);
	sort_check(a, b);
	free_list(a);
	free(a);
	free(b);
	return (0);
}
