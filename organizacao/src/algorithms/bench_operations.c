/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* bench_operations.c                                 :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: nde-mace <nde-mace@student.42.fr>          +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2026/07/11 11:30:19 by nde-mace          #+#    #+#             */
/* Updated: 2026/07/11 13:02:40 by nde-mace         ###   ########.fr       */
/* */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void    init_bench(t_bench *bench)
{
    bench->bench_mode = 0;
    bench->strategy = 0;
    bench->is_adaptive = 0;
    bench->total_ops = 0;
    bench->sa_count = 0;
    bench->sb_count = 0;
    bench->ss_count = 0;
    bench->pa_count = 0;
    bench->pb_count = 0;
    bench->ra_count = 0;
    bench->rb_count = 0;
    bench->rr_count = 0;
    bench->rra_count = 0;
    bench->rrb_count = 0;
    bench->rrr_count = 0;
}

void    increment_op(t_bench *bench, char *op)
{
    if (!bench || bench->bench_mode == 0)
        return ;
    bench->total_ops++;
    if (ft_strcmp(op, "sa") == 0)
        bench->sa_count++;
    else if (ft_strcmp(op, "sb") == 0)
        bench->sb_count++;
    else if (ft_strcmp(op, "ss") == 0)
        bench->ss_count++;
    else if (ft_strcmp(op, "pa") == 0)
        bench->pa_count++;
    else if (ft_strcmp(op, "pb") == 0)
        bench->pb_count++;
    else if (ft_strcmp(op, "ra") == 0)
        bench->ra_count++;
    else if (ft_strcmp(op, "rb") == 0)
        bench->rb_count++;
    else if (ft_strcmp(op, "rr") == 0)
        bench->rr_count++;
    else if (ft_strcmp(op, "rra") == 0)
        bench->rra_count++;
    else if (ft_strcmp(op, "rrb") == 0)
        bench->rrb_count++;
    else if (ft_strcmp(op, "rrr") == 0)
        bench->rrr_count++;
}

void	print_bench_report(t_bench *bench, double chaos)
{
	char	*strat;

	if (!bench || bench->bench_mode == 0)
		return ;
	ft_dprintf(2, "[bench] disorder: %.2f%%\n", chaos * 100.0);
	strat = "Simple / O(n^2)";
	if (bench->strategy == STRATEGY_MEDIUM)
		strat = "Medium / O(n*sqrt(n))";
	else if (bench->strategy == STRATEGY_COMPLEX)
		strat = "Complex / O(n log n)";
	if (bench->is_adaptive == 1 && bench->strategy == STRATEGY_SIMPLE)
		strat = "Adaptive / O(n^2)";
	if (bench->is_adaptive == 1 && bench->strategy == STRATEGY_MEDIUM)
		strat = "Adaptive / O(n*sqrt(n))";
	if (bench->is_adaptive == 1 && bench->strategy == STRATEGY_COMPLEX)
		strat = "Adaptive / O(n log n)";
	ft_dprintf(2, "[bench] strategy: %s\n", strat);
	ft_dprintf(2, "[bench] total_ops: %d\n", bench->total_ops);
	ft_dprintf(2, "[bench] sa: %d sb: %d ss: %d pa: %d pb: %d ",
		bench->sa_count, bench->sb_count, bench->ss_count,
		bench->pa_count, bench->pb_count);
	ft_dprintf(2, "ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
		bench->ra_count, bench->rb_count, bench->rr_count,
		bench->rra_count, bench->rrb_count, bench->rrr_count);
}
