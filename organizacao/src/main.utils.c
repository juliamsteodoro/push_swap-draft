/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoreir <jumoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 14:00:12 by jumoreir          #+#    #+#             */
/*   Updated: 2026/07/13 14:11:32 by jumoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	run_sorting(t_stack **a, t_stack **b, int strategy, t_bench *bench)
{
	double	chaos_inicial;

	chaos_inicial = ft_chaos(*a);
	ft_index_stack(a);
	orch_sorting(a, b, strategy, bench);
	if (bench->bench_mode == 1)
		print_bench_report(bench, chaos_inicial);
}

static void	set_strategy(int *strategy, t_bench *bench, int type)
{
	*strategy = type;
	if (type == STRATEGY_ADAPTIVE)
		bench->is_adaptive = 1;
	else
		bench->is_adaptive = 0;
}

static int	parse_flags(char **argv, int *strategy, t_bench *bench)
{
	int	i;

	i = 1;
	set_strategy(strategy, bench, STRATEGY_ADAPTIVE);
	while (argv[i] && argv[i][0] == '-')
	{
		if (ft_strcmp(argv[i], "--bench") == 0)
			bench->bench_mode = 1;
		else if (ft_strcmp(argv[i], "--simple") == 0)
			set_strategy(strategy, bench, STRATEGY_SIMPLE);
		else if (ft_strcmp(argv[i], "--medium") == 0)
			set_strategy(strategy, bench, STRATEGY_MEDIUM);
		else if (ft_strcmp(argv[i], "--complex") == 0)
			set_strategy(strategy, bench, STRATEGY_COMPLEX);
		else if (ft_strcmp(argv[i], "--adaptive") == 0)
			set_strategy(strategy, bench, STRATEGY_ADAPTIVE);
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
	int		i;

	i = 0;
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
