/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grbuchne <grbuchne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:19:01 by gregor.buch       #+#    #+#             */
/*   Updated: 2024/02/16 16:13:21 by grbuchne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "./libft/libft.h"

typedef struct t_node
{
	int				data;
	int				index;
	struct t_node	*next;
}	t_node;

typedef struct t_stack
{
	t_node	*top;
}	t_stack;

//main.c
int		main(int ac, char **av);

//list_ops.c
t_node	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack *stack, t_node *new);
int		ft_lstsize(t_stack *lst);
t_node	*ft_lstnew(int data);
//check_input.c
void	check_input(int argc, char **argv, t_stack *a, t_stack *b);
void	sort_check(t_stack *a, t_stack *b);
int		ft_contains(int num, char **argv, int i);
//small_sort.c
void	sort5(t_stack *stack_a, t_stack *stack_b);
void	sort4(t_stack *stack_a, t_stack *stack_b);
void	sort3(t_stack *stack_a);
void	sort2(t_stack *stack_a);

//big_sort.c
int		get_max_bits(t_stack *stack);
void	radix_sort(t_stack *stack_a, t_stack *stack_b);
t_node	*get_next_min(t_stack *stack);
//rrOps.c
void	rr_op(t_stack *stack);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
//s_ops
void	ss(t_stack *a, t_stack *b);
void	sb(t_stack *b);
void	sa(t_stack *a);
int		swapr(t_stack *stack);
//rot_ops.c
void	rr(t_stack *a, t_stack *b);
void	rb(t_stack *b);
void	ra(t_stack *a);
void	rot(t_stack *a);
//p_ops
void	pb(t_stack *dest, t_stack *src);
void	pa(t_stack *src, t_stack *dest);
void	push_op(t_stack *src, t_stack *dest);
t_node	*pop(t_stack *stack);
void	push(t_node *push, t_stack *stack);
//helper2
void	ft_free(char **str);
int		get_distance(t_stack *stack, int index);
int		is_max(t_stack *stack_a);
int		get_min(t_stack *stack);
int		is_sorted(t_stack *stack_a);
void	error_out(t_stack *a, t_stack *b);
//helper
int		word_length(char const *s, char c);
char	**f(char const *s, char c, char **result, int words_count);
void	initialize_stack(t_stack *stack, int argc, char **argv);
void	indexer(t_stack *stack);
int		ft_isnum(char *num);
void	ft_free(char **str);
#endif