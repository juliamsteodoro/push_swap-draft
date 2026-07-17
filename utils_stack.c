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

#include "push_swap.h"

int	ft_stack_size(t_stack *a)
{
	t_stack	*current;
	int		i;

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

int	ft_is_sorted(t_stack *a)
{
	t_stack	*current;

	current = a;
	if (!current || current->next == NULL)
		return (1);
	while (current-> next != NULL)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

void	ft_index_stack(t_stack **a)
{
	t_stack	*current_node;
	t_stack	*second;
	int		counting;

	current_node = *a;
	while (current_node != NULL)
	{
		counting = 0;
		second = *a;
		while (second != NULL)
		{
			if (second->value < current_node->value)
				counting++;
			second = second->next;
		}
		current_node->index = counting;
		current_node = current_node->next;
	}
}

double	ft_chaos(t_stack *stack)
{
	t_stack	*i;
	t_stack	*j;
	int		mistakes;
	int		total_pairs;

	mistakes = 0;
	total_pairs = 0;
	i = stack;
	while (i)
	{
		j = i->next;
		while (j)
		{
			total_pairs++;
			if (i->value > j->value)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((double)mistakes / total_pairs);
}
