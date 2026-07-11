/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 10:06:44 by marvin            #+#    #+#             */
/*   Updated: 2026/07/02 10:06:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int ft_stack_size(t_stack *a)
{
    t_stack *current;
    int     i;

    current = a;
    i = 0;
    if (!a)
        return (0);
    while (current != NULL)
    {
        i++;
        current = current->next;
    }
    return (i);
}

int ft_is_sorted(t_stack *a)
{
    t_stack *current;

    current = a;
    if (!current || current->next == NULL)
        return (1);
    while(current-> next != NULL)
    {
        if(current->value > current->next->value)
            return(0);
        current = current->next;
    }
    return (1);
}

void	ft_index_stack(t_stack **a)
{	
	t_stack *current_node;
	t_stack	*second;
	int		counting;
	
	current_node = *a;
	while(current_node != NULL)
	{
		counting = 0;
		second = *a;
		while(second != NULL)
		{
			if(second->value < current_node->value)
				counting++;
			second = second->next;
			
		}
		current_node->index = counting;
		current_node = current_node->next;
	}
}

double  ft_chaos(const int *numbers, int len)
{
    int j;
    int k;
    int mistakes;
    int total_pairs;

    k = 0;
    mistakes = 0;
    total_pairs = 0;
    if (!numbers || len <= 1)
        return (0.0);
    while (k < len)
    {
        j = k + 1;
        while (j < len)
        {
            total_pairs++;
            if (numbers[k] > numbers[j])
                mistakes++;
            j++; 
        }
        k++;
    }
    return ((double)mistakes / total_pairs);
}
