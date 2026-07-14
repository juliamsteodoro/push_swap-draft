/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 14:08:12 by marvin            #+#    #+#             */
/*   Updated: 2026/07/02 14:08:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_radix_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	int	max;
	int	i;
	int	size;

	max = get_max_bits(*a);
	i = 0;
	while (i < max)
	{
		if (ft_is_sorted(*a) && !*b)
			break ;
		size = ft_stack_size(*a);
		while (size--)
		{
			if (((*a)->index >> i) & 1)
				ra(a, bench);
			else
				pb(a, b, bench);
		}
		while (*b)
			pa(a, b, bench);
		i++;
	}
}

int	get_max_bits(t_stack *a)
{
	t_stack	*temp;
	int		max_index;
	int		max_bits;

	temp = a;
	max_index = 0;
	while (temp != NULL)
	{
		if (temp->index > max_index)
			max_index = temp->index;
		temp = temp->next;
	}
	max_bits = 0;
	while (max_index > 0)
	{
		max_index >>= 1;
		max_bits++;
	}
	return (max_bits);
}
