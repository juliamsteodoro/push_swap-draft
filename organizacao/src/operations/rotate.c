/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 10:11:36 by marvin            #+#    #+#             */
/*   Updated: 2026/07/02 10:11:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	rotate_stack(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = first;
	while (last->next != NULL)
		last = last->next;
	*stack = first->next;
	(*stack)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	ra(t_stack **a, t_bench *bench)
{
	rotate_stack(a);
	write(1, "ra\n", 3);
	increment_op(bench, "ra");
}

void	rb(t_stack **b, t_bench *bench)
{
	rotate_stack(b);
	write(1, "rb\n", 3);
	increment_op(bench, "rb");
}

void	rr(t_stack **a, t_stack **b, t_bench *bench)
{
	rotate_stack(a);
	rotate_stack(b);
	write(1, "rr\n", 3);
	increment_op(bench, "rr");
}
