/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 10:12:24 by marvin            #+#    #+#             */
/*   Updated: 2026/07/02 10:12:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	reverse_rotate_stack(t_stack **stack)
{
	t_stack	*first;
	t_stack	*penultimate;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	penultimate = NULL;
	last = first;
	while (last->next != NULL)
	{
		penultimate = last;
		last = last->next;
	}
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	penultimate->next = NULL;
	*stack = last;
}

void    rra(t_stack **a, t_bench *bench)
{
    reverse_rotate_stack(a);
    write(1, "rra\n", 4);
    increment_op(bench, "rra");
}

void    rrb(t_stack **b, t_bench *bench)
{
    reverse_rotate_stack(b);
    write(1, "rrb\n", 4);
    increment_op(bench, "rrb");
}

void    rrr(t_stack **a, t_stack **b, t_bench *bench)
{
    reverse_rotate_stack(a);
    reverse_rotate_stack(b);
    write(1, "rrr\n", 4);
    increment_op(bench, "rrr");
}
