/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_selector.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoreir <jumoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 13:02:40 by nde-mace          #+#    #+#             */
/*   Updated: 2026/07/13 23:11:13 by jumoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	simple_strategy(t_stack **a, t_stack **b, t_bench *bench)
{
	t_stack	*temp;
	int		min;

	if (!a || !*a)
		return ;
	bench->strategy = STRATEGY_SIMPLE;
	while (ft_stack_size(*a) > 0)
	{
		temp = *a;
		min = temp->index;
		while (temp)
		{
			if (temp->index < min)
				min = temp->index;
			temp = temp->next;
		}
		while ((*a)->index != min)
			ra(a, bench);
		pb(a, b, bench);
	}
	while (*b)
		pa(a, b, bench);
}

void	medium_strategy(t_stack **a, t_stack **b, t_bench *bench)
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

void	complex_strategy(t_stack **a, t_stack **b, t_bench *bench)
{
	bench->strategy = STRATEGY_COMPLEX;
	ft_radix_sort(a, b, bench);
}

void	adaptive_strategy(t_stack **a, t_stack **b, t_bench *bench)
{
	double	taxa_chaos;
	int		len;

	len = ft_stack_size(*a);
	if (ft_is_sorted(*a))
		return ;
	if (len <= 3)
	{
		sort_small(a, b, bench);
		return ;
	}
	taxa_chaos = ft_chaos(*a);
	if (taxa_chaos < 0.2)
		simple_strategy(a, b, bench);
	else if (taxa_chaos < 0.5)
		medium_strategy(a, b, bench);
	else
		complex_strategy(a, b, bench);
}

void	orch_sorting(t_stack **a, t_stack **b, int strategy, t_bench *bench)
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
		adaptive_strategy(a, b, bench);
}
