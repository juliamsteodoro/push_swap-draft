/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 10:09:26 by marvin            #+#    #+#             */
/*   Updated: 2026/07/02 10:09:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	pa(t_stack **a, t_stack **b)
{
	t_stack *primeiro_b;
	t_stack *primeiro_a;
	t_stack *segundo_b;

	primeiro_b = *b;
    if (!primeiro_b)
        return;
    segundo_b = primeiro_b->next;
    primeiro_a = *a;
    *b = segundo_b;
    if (segundo_b != NULL)
        segundo_b->prev = NULL;
    if(primeiro_a != NULL)
        primeiro_a->prev = primeiro_b;

    primeiro_b->next = primeiro_a;
    primeiro_b->prev = NULL;
    *a = primeiro_b;
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack *primeiro_a;
	t_stack *primeiro_b;
	t_stack *segundo_a;

	primeiro_a = *a;
    if (!primeiro_a)
        return;
    segundo_a = primeiro_a->next;
    primeiro_b = *b;
    *a = segundo_a;
    if (segundo_a != NULL)
        segundo_a->prev = NULL;
    if(primeiro_b != NULL)
        primeiro_b->prev = primeiro_a;

    primeiro_a->next = primeiro_b;
    primeiro_a->prev = NULL;
    *b = primeiro_a;

}
