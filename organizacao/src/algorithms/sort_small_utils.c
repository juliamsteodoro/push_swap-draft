/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoreir <jumoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 12:02:12 by nde-mace          #+#    #+#             */
/*   Updated: 2026/07/13 13:12:21 by jumoreir         ###   ########.fr       */
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

static void	get_three_values(t_stack **a, int *n1, int *n2, int *n3)
{
	*n1 = (*a)->value;
	*n2 = (*a)->next->value;
	*n3 = (*a)->next->next->value;
}

void	sort_three_case(t_stack **a, t_bench *bench)
{
	int	n1;
	int	n2;
	int	n3;

	get_three_values(a, &n1, &n2, &n3);
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
