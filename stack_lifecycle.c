/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_lifecycle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 10:05:01 by marvin            #+#    #+#             */
/*   Updated: 2026/07/02 10:05:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_newstack(long n)
{
	t_stack	*new_nbr;

	new_nbr = malloc(sizeof(t_stack));
	if (!new_nbr)
		return (NULL);
	new_nbr->value = n;
	new_nbr->index = 0;
	new_nbr->next = NULL;
	new_nbr->prev = NULL;
	return (new_nbr);
}

static void	append_node(t_stack **a, t_stack **temp, t_stack *new_node)
{
	if (*a == NULL)
	{
		*a = new_node;
		*temp = *a;
	}
	else
	{
		(*temp)->next = new_node;
		new_node->prev = *temp;
		*temp = new_node;
	}
}

t_stack	*ft_init_stack(t_stack **a, int *numbers, int len_numbers)
{
	int		i;
	t_stack	*new_node;
	t_stack	*temp;

	i = 0;
	while (i < len_numbers)
	{
		new_node = ft_newstack(numbers[i]);
		if (!new_node)
		{
			ft_free_stack(a);
			return (NULL);
		}
		append_node(a, &temp, new_node);
		i++;
	}
	return (*a);
}

void	ft_free_stack(t_stack **a)
{
	t_stack	*temp;
	t_stack	*current;

	temp = *a;
	while (temp != NULL)
	{
		current = temp;
		temp = temp->next;
		free(current);
	}
	*a = NULL;
}
