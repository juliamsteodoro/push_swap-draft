/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algorithm_selector.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 11:55:26 by nde-mace          #+#    #+#             */
/*   Updated: 2026/07/16 22:43:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_min_to_b(t_stack **a, t_stack **b, t_bench *bench)
{
	int	min_pos;
	int	size;
	int	moves;

	min_pos = ft_find_min_pos(a);
	size = ft_stack_size(*a);
	if (min_pos <= size / 2)
	{
		while (min_pos-- > 0)
			ra(a, bench);
	}
	else
	{
		moves = size - min_pos;
		while (moves-- > 0)
			rra(a, bench);
	}
	pb(a, b, bench);
}
