/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 10:10:33 by marvin            #+#    #+#             */
/*   Updated: 2026/07/02 10:10:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	sa(t_stack **a)
{
	t_stack	*primeiro;
	t_stack	*segundo;

	if (!a || !*a || !(*a)->next)
		return ;
	primeiro = *a;
	segundo = primeiro->next;
	primeiro->next = segundo->next;
	if (segundo->next)
		segundo->next->prev = primeiro;
	segundo->prev = primeiro->prev;
	segundo->next = primeiro;
	primeiro->prev = segundo;
	*a = segundo;
}

void	sb(t_stack **b)
{
	t_stack	*primeiro;
	t_stack	*segundo;

	if (!b || !*b || !(*b)->next)
		return ;
	primeiro = *b;
	segundo = primeiro->next;
	primeiro->next = segundo->next;
	if (segundo->next)
		segundo->next->prev = primeiro;
	segundo->prev = primeiro->prev;
	segundo->next = primeiro;
	primeiro->prev = segundo;
	*b = segundo;
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
}
