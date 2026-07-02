/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 10:11:36 by marvin            #+#    #+#             */
/*   Updated: 2026/07/02 10:11:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ra(t_stack **a)
{
	t_stack	*primeiro;
	t_stack	*segundo;
	t_stack	*ultimo;

	primeiro = *a;
	segundo = primeiro->next;
	ultimo = primeiro;
	while (ultimo->next != NULL)
		ultimo = ultimo->next;
	*a = segundo;
	segundo->prev = NULL;
	ultimo->next = primeiro;
	primeiro->prev = ultimo;
	primeiro->next = NULL;
}

void	rb(t_stack **b)
{
	t_stack	*primeiro;
	t_stack	*segundo;
	t_stack	*ultimo;

	primeiro = *b;
	segundo = primeiro->next;
	ultimo = primeiro;
	while (ultimo->next != NULL)
		ultimo = ultimo->next;
	*b = segundo;
	segundo->prev = NULL;
	ultimo->next = primeiro;
	primeiro->prev = ultimo;
	primeiro->next = NULL;
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}
