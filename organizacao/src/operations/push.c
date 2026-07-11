/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 10:09:26 by marvin            #+#    #+#             */
/*   Updated: 2026/07/02 10:09:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void    pa(t_stack **a, t_stack **b, t_bench *bench)
{
    t_stack *first_b;
    t_stack *first_a;
    t_stack *second_b;

    first_b = *b;
    if (!first_b)
        return;
    second_b = first_b->next;
    first_a = *a;
    *b = second_b;
    if (second_b != NULL)
        second_b->prev = NULL;
    if(first_a != NULL)
        first_a->prev = first_b;

    first_b->next = first_a;
    first_b->prev = NULL;
    *a = first_b;
    write(1, "pa\n", 3);
    increment_op(bench, "pa");
}

void    pb(t_stack **a, t_stack **b, t_bench *bench)
{
    t_stack *first_a;
    t_stack *first_b;
    t_stack *second_a;

    first_a = *a;
    if (!first_a)
        return;
    second_a = first_a->next;
    first_b = *b;
    *a = second_a;
    if (second_a != NULL)
        second_a->prev = NULL;
    if(first_b != NULL)
        first_b->prev = first_a;

    first_a->next = first_b;
    first_a->prev = NULL;
    *b = first_a;
    write(1, "pb\n", 3);
    increment_op(bench, "pb");
}
