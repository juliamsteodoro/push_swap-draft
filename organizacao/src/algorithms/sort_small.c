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

void    sort_two(t_stack **a)
{
    sa(a);
}

void	sort_small(t_stack **a, t_stack **b)
{
	if (!a || !*a)
		return ;
	if (ft_stack_size(*a) == 2)
		sort_two(a);
	else if (ft_stack_size(*a) == 3)
		sort_three(a);
	else
		sort_five(a, b);
}

static void sort_three_case(t_stack **a, int n1, int n2, int n3)
{
    if (n1 > n2 && n2 > n3)
    {
        sa(a);
        rra(a);
    }
    else if (n1 > n2 && n1 < n3 && n2 < n3)
        sa(a);
    else if (n1 < n2 && n1 < n3 && n2 > n3)
    {
        sa(a);
        ra(a);
    }
    else if (n1 > n2 && n3 > n1)
        sa(a);
    else if (n1 > n3 && n3 > n2)
        ra(a);
    else if (n1 < n2 && n2 > n3 && n1 > n3)
        rra(a);
}

void    sort_three(t_stack **a)
{
    int n1;
    int n2;
    int n3;

    if (!a || !*a || !(*a)->next || !(*a)->next->next)
        return ;
    n1 = (*a)->value;
    n2 = (*a)->next->value;
    n3 = (*a)->next->next->value;
    sort_three_case(a, n1, n2, n3);
}

void sort_five(t_stack **a, t_stack **b)
{
    if (ft_stack_size(*a) <= 3)
        return ;
    while (ft_stack_size(*a) > 3)
		push_min_to_b(a, b);
    sort_three(a);
    while (*b)
        pa(a, b);
}

void	ft_sort_small(t_stack **a, t_stack **b)
{
	sort_small(a, b);
}