/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 10:10:33 by marvin            #+#    #+#             */
/*   Updated: 2026/07/02 10:10:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	swap_nodes(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	third = second->next;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	first->next = third;
	if (third)
		third->prev = first;
	*stack = second;
}

void    sa(t_stack **a, t_bench *bench)
{
    swap_nodes(a);
    write(1, "sa\n", 3);
    increment_op(bench, "sa");
}

void    sb(t_stack **b, t_bench *bench)
{
    swap_nodes(b);
    write(1, "sb\n", 3);
    increment_op(bench, "sb");
}

void    ss(t_stack **a, t_stack **b, t_bench *bench)
{
    swap_nodes(a);
    swap_nodes(b);
    write(1, "ss\n", 3);
    increment_op(bench, "ss");
}
