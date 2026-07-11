/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 10:15:08 by marvin            #+#    #+#             */
/*   Updated: 2026/07/02 10:15:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void    sort_two(t_stack **a, t_bench *bench)
{
    sa(a, bench);
}

void sort_five(t_stack **a, t_stack **b, t_bench *bench)
{
    if (ft_stack_size(*a) <= 3)
        return ;
    while (ft_stack_size(*a) > 3)
        push_min_to_b(a, b, bench);
    sort_three(a, bench);
    while (*b)
        pa(a, b, bench);
}

void    sort_small(t_stack **a, t_stack **b, t_bench *bench)
{
    if (!a || !*a)
        return ;
    if (ft_stack_size(*a) == 2)
        sort_two(a, bench);
    else if (ft_stack_size(*a) == 3)
        sort_three(a, bench);
    else
        sort_five(a, b, bench);
}

void    ft_sort_small(t_stack **a, t_stack **b, t_bench *bench)
{
    sort_small(a, b, bench);
}

void    sort_three(t_stack **a, t_bench *bench)
{
    if (!a || !*a || !(*a)->next || !(*a)->next->next)
        return ;
    sort_three_case(a, bench);
}
