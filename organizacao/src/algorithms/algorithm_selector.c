/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_selector.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-mace <nde-mace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 13:02:40 by nde-mace          #+#    #+#             */
/*   Updated: 2026/07/11 13:17:16 by nde-mace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void    simple_strategy(t_stack **a, t_stack **b, t_bench *bench)
{
    if (!a || !*a)
        return ;
    bench->strategy = STRATEGY_SIMPLE;
    sort_small(a, b, bench);
}

void    medium_strategy(t_stack **a, t_stack **b, t_bench *bench)
{
    if (!a || !*a)
        return ;
    bench->strategy = STRATEGY_MEDIUM;
    if (ft_stack_size(*a) <= 3)
    {
        sort_small(a, b, bench);
        return ;
    }
    while (ft_stack_size(*a) > 3)
        push_min_to_b(a, b, bench);
    sort_three(a, bench);
    while (*b)
        pa(a, b, bench);
}

void    complex_strategy(t_stack **a, t_stack **b, t_bench *bench)
{
    bench->strategy = STRATEGY_COMPLEX;
    ft_radix_sort(a, b, bench);
}

void adaptive_strategy(t_stack **a, t_stack **b, int len,int *numbers, t_bench *bench)
{
    double taxa_chaos;

    if (ft_is_sorted(*a))
        return ;
    if (len <= 3)
    {
        sort_small(a, b, bench);
        return ;
    }
    taxa_chaos = ft_chaos(numbers, len);
    if (taxa_chaos < 0.2)
        simple_strategy(a, b, bench);
    else if (taxa_chaos < 0.5)
        medium_strategy(a, b, bench);
    else
        complex_strategy(a, b, bench);
}
void    orchestration_sorting(t_stack **a, t_stack **b, int len, int *numbers, int strategy, t_bench *bench)
{
    if (ft_is_sorted(*a))
        return ;
    if (strategy == 1)
        simple_strategy(a, b, bench);
    else if (strategy == 2)
        medium_strategy(a, b, bench);
    else if (strategy == 3)
        complex_strategy(a, b, bench);
    else
        adaptive_strategy(a, b, len, numbers, bench);
}
