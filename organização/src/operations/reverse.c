/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 10:12:24 by marvin            #+#    #+#             */
/*   Updated: 2026/07/02 10:12:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rra(t_stack **a)
{
	t_stack	*primeiro;
	t_stack	*penultimo;
	t_stack	*ultimo;

	primeiro = *a;
	penultimo = NULL;
	ultimo = primeiro;
	while (ultimo->next != NULL)
	{
		penultimo = ultimo;
		ultimo = ultimo->next;
	}
	ultimo->prev = NULL;
	ultimo->next = primeiro;
	primeiro->prev = ultimo;
	penultimo->next = NULL;
}

void	rrb(t_stack **b)
{
	t_stack	*primeiro;
	t_stack	*penultimo;
	t_stack	*ultimo;

	primeiro = *b;
	penultimo = NULL;
	ultimo = primeiro;
	while (ultimo->next != NULL)
	{
		penultimo = ultimo;
		ultimo = ultimo->next;
	}
	ultimo->prev = NULL;
	ultimo->next = primeiro;
	primeiro->prev = ultimo;
	penultimo->next = NULL;
}
void    rrr(t_stack **a, t_stack **b)
{
    rra(a);
    rrb(b);
}
