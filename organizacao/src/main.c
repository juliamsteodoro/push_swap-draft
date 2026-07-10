/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoreir <jumoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 19:51:18 by jumoreir          #+#    #+#             */
/*   Updated: 2026/07/10 19:51:52 by jumoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	*popular_numbers(char **args, int start, int len)
{
	int	*numbers;
	int	i;

	numbers = malloc(sizeof(int) * len);
	if (!numbers)
		return (NULL);
	i = 0;
	while (i < len)
	{
		numbers[i] = (int)ft_atol(args[start + i]);
		i++;
	}
	return (numbers);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		*numbers;
	int		len;

	if (argc < 2)
		return (0);
	if (!validate_arg(argv, 1))
		return (ft_error(), 1);
	len = argc - 1;
	numbers = popular_numbers(argv, 1, len);
	if (!numbers)
		return (1);
	a = NULL;
	b = NULL;
	if (!ft_init_stack(&a, numbers, len))
		return (free(numbers), 1);
	ft_index_stack(&a);
	orchestration_sorting(&a, &b, len, numbers, STRATEGY_ADAPTIVE);
	free(numbers);
	ft_free_stack(&a);
	ft_free_stack(&b);
	return (0);
}