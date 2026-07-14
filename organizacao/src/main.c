/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoreir <jumoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 13:46:57 by jumoreir          #+#    #+#             */
/*   Updated: 2026/07/13 22:11:40 by jumoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	*popular_numbers(char **args, int start, int len)
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
	t_bench	bench;
	char	**split_args;
	int		start;
	int		strategy;
	int		success;

	if (argc < 2)
		return (0);
	init_bench(&bench);
	start = parse_flags(argv, &strategy, &bench);
	bench.strategy = strategy;
	if (argv[start] && argv[start + 1] == NULL && argc == start + 1)
	{
		split_args = ft_split(argv[start], ' ');
		if (!split_args)
			return (1);
		success = process_arguments(split_args, 0, strategy, &bench);
		free_split(split_args);
		return (!success);
	}
	if (argc == start && bench.bench_mode == 1)
		return (0);
	success = process_arguments(argv, start, strategy, &bench);
	return (!success);
}
