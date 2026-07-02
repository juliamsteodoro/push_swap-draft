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

int	ft_find_min_pos(t_stack **a)
{
	t_stack	*temp;
	int		min;
	int		position_atual;
	int		position_menor;

	temp = *a;
	position_atual = 0;
	position_menor = 0;
	min = (*a)->value;
	while (temp != NULL)
	{
		if ((temp)->value < min)
		{
			min = (temp)->value;
			position_menor = position_atual;
		}
		temp = (temp)->next;
		position_atual++;
	}
	return (position_menor);
}

void    ft_sort_two(t_stack **a)
{
    sa(a);
}

void	ft_sort_three(t_stack **a)
{
	int	n1;
	int	n2;
	int	n3;

	if (!a || !*a)
		return ;
	n1 = (*a)->value;
	n2 = (*a)->next->value;
	n3 = (*a)->next->next->value;
	if (n1 < n2 && n1 < n3 && n2 > n3)
	{
		sa(a);
		ra(a);
	}
	else if (n1 > n2 && n2 > n3)
	{
		sa(a);
		rra(a);
	}
	else if (n1 > n2 && n3 > n1) 
		sa(a);
	else if (n1 > n3 && n3 > n2)
		ra(a);
	else if (n2 > n1 && n1 > n3)
		rra(a);
}

void sort_five(t_stack **a, t_stack **b)
{
    int min_pos;
    int size;

    while (ft_stack_size(a) > 3)
    {
        min_pos = ft_find_min_pos(a);
        size = ft_stack_size(a);

        if (min_pos <= size / 2)
        {
            while (min_pos--)
                ra(a);
        }
        else
        {
            while ((size - min_pos)--)
                rra(a);
        }
        pb(a, b);
    }
    sort_three(a);
    while (*b)
        pa(a, b);
}

