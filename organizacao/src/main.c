/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* main.c                                             :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: nde-mace <nde-mace@student.42.fr>          +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2026/07/11 12:06:57 by nde-mace          #+#    #+#             */
/* Updated: 2026/07/11 12:42:00 by nde-mace         ###   ########.fr       */
/* */
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

static void	run_sorting(t_stack **a, t_stack **b, int strategy, t_bench *bench)
{
	double	chaos_inicial;

	chaos_inicial = ft_chaos(*a);
	ft_index_stack(a);
	orch_sorting(a, b, strategy, bench);
	if (bench->bench_mode == 1)
		print_bench_report(bench, chaos_inicial);
}

static int	parse_flags(char **argv, int *strategy, t_bench *bench)
{
	int	i;

	i = 1;
	*strategy = STRATEGY_ADAPTIVE;
	bench->is_adaptive = 1;
	while (argv[i] && argv[i][0] == '-')
	{
		if (ft_strcmp(argv[i], "--bench") == 0)
			bench->bench_mode = 1;
		else if (ft_strcmp(argv[i], "--simple") == 0)
			(*strategy = STRATEGY_SIMPLE, bench->is_adaptive = 0);
		else if (ft_strcmp(argv[i], "--medium") == 0)
			(*strategy = STRATEGY_MEDIUM, bench->is_adaptive = 0);
		else if (ft_strcmp(argv[i], "--complex") == 0)
			(*strategy = STRATEGY_COMPLEX, bench->is_adaptive = 0);
		else if (ft_strcmp(argv[i], "--adaptive") == 0)
			(*strategy = STRATEGY_ADAPTIVE, bench->is_adaptive = 1);
		else
			return (i);
		i++;
	}
	return (i);
}
static int	process_arguments(char **args, int start, int strat, t_bench *bench)
{
	t_stack	*a;
	t_stack	*b;
	int		*numbers;
	int		len;

	int i = 0;
	while (args[i])
		i++;
	len = i - start;
	if (len <= 0 || !validate_arg(args, start))
		return (ft_error(), 0);
	numbers = popular_numbers(args, start, len);
	a = NULL;
	b = NULL;
	if (!numbers || !ft_init_stack(&a, numbers, len))
		return (free(numbers), 0);
	run_sorting(&a, &b, strat, bench);
	return (free(numbers), ft_free_stack(&a), ft_free_stack(&b), 1);
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
