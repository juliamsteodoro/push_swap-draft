/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-mace <nde-mace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 12:02:12 by nde-mace          #+#    #+#             */
/*   Updated: 2026/07/11 12:02:41 by nde-mace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_find_min_pos(t_stack **a)
{
	t_stack	*temp;
	int		min;
	int		pos_now;
	int		pos_minor;

	temp = *a;
	pos_now = 0;
	pos_minor = 0;
	min = (*a)->value;
	while (temp != NULL)
	{
		if ((temp)->value < min)
		{
			min = (temp)->value;
			pos_minor = pos_now;
		}
		temp = (temp)->next;
		pos_now++;
	}
	return (pos_minor);
}

void	sort_three_case(t_stack **a, int n1, int n2, int n3, t_bench *bench)
{
	if (n1 > n2 && n2 > n3)
	{
		sa(a, bench);
		rra(a, bench);
	}
	else if (n1 > n2 && n1 < n3 && n2 < n3)
		sa(a, bench);
	else if (n1 < n2 && n1 < n3 && n2 > n3)
	{
		sa(a, bench);
		ra(a, bench);
	}
	else if (n1 > n2 && n3 > n1)
		sa(a, bench);
	else if (n1 > n3 && n3 > n2)
		ra(a, bench);
	else if (n1 < n2 && n2 > n3 && n1 > n3)
		rra(a, bench);
}
