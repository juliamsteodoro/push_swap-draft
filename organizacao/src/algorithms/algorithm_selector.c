/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_selector.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-mace <nde-mace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 13:02:40 by nde-mace          #+#    #+#             */
/*   Updated: 2026/07/04 18:08:47 by nde-mace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void push_min_to_b(t_stack **a, t_stack **b)
{
    int min_pos;
    int size;
    int moves;

    min_pos = ft_find_min_pos(a);
    size = ft_stack_size(*a);
    if (min_pos <= size / 2)
    {
        while (min_pos-- > 0)
            ra(a);
    }
    else
    {
        moves = size - min_pos;
        while (moves-- > 0)
            rra(a);
    }
    pb(a, b);
}

void    simple_strategy(t_stack **a, t_stack **b)
{
    if (!a || !*a)
        return ;
    sort_small(a, b);
}

void    medium_strategy(t_stack **a, t_stack **b)
{
    if (!a || !*a)
        return ;
    if (ft_stack_size(*a) <= 3)
    {
        sort_small(a, b);
        return ;
    }
    while (ft_stack_size(*a) > 3)
        push_min_to_b(a, b);
    sort_three(a);
    while (*b)
        pa(a, b);
}

void    complex_strategy(t_stack **a, t_stack **b)
{
    ft_radix_sort(a, b);
}

void    adaptive_strategy(t_stack **a, t_stack **b, int len, int *numbers)
{
    double  taxa_chaos;

    if (ft_is_sorted(*a))
        return ;
    taxa_chaos = ft_chaos(numbers, len);
    if (taxa_chaos < 0.2)
        simple_strategy(a, b);
    else if (taxa_chaos < 0.5)
        medium_strategy(a, b);
    else
        complex_strategy(a, b);
}

void    orchestration_sorting(t_stack **a, t_stack **b, int len, int *numbers, int strategy)
{
    if (ft_is_sorted(*a))
        return ;
    if (strategy == 1)
        simple_strategy(a, b);
    else if (strategy == 2)
        medium_strategy(a, b);
    else if (strategy == 3)
        complex_strategy(a, b);
    else
        adaptive_strategy(a, b, len, numbers);
}
