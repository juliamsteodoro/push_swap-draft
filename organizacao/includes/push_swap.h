/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoreir <jumoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 19:50:00 by nde-mace          #+#    #+#             */
/*   Updated: 2026/07/11 18:13:18 by jumoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_bench
{
	int		bench_mode;
	int		strategy;
	int		is_adaptive;
	int		total_ops;
	int		sa_count;
	int		sb_count;
	int		ss_count;
	int		pa_count;
	int		pb_count;
	int		ra_count;
	int		rb_count;
	int		rr_count;
	int		rra_count;
	int		rrb_count;
	int		rrr_count;
}	t_bench;

#define STRATEGY_SIMPLE 1
#define STRATEGY_MEDIUM 2
#define STRATEGY_COMPLEX 3
#define STRATEGY_ADAPTIVE 4

int		validate_arg(char **args, int start);
int		is_valid_format(char **args, int start);
int		has_duplicates(char **args, int start);
long	ft_atol(const char *str);
void	ft_error(void);

char	**ft_split(char const *s, char c);
void	free_split(char **args);
int		ft_isdigit(int c);

t_stack	*ft_newstack(long n);
t_stack	*ft_init_stack(t_stack **a, int *numbers, int len_numbers);
void	ft_free_stack(t_stack **a);
int		ft_stack_size(t_stack *a);
int		ft_is_sorted(t_stack *a);
void	ft_index_stack(t_stack **a);

void	pa(t_stack **a, t_stack **b, t_bench *bench);
void	pb(t_stack **a, t_stack **b, t_bench *bench);

void	sa(t_stack **a, t_bench *bench);
void	sb(t_stack **b, t_bench *bench);
void	ss(t_stack **a, t_stack **b, t_bench *bench);

void	ra(t_stack **a, t_bench *bench);
void	rb(t_stack **b, t_bench *bench);
void	rr(t_stack **a, t_stack **b, t_bench *bench);

void	rra(t_stack **a, t_bench *bench);
void	rrb(t_stack **b, t_bench *bench);
void	rrr(t_stack **a, t_stack **b, t_bench *bench);

void	sort_two(t_stack **a, t_bench *bench);
void	sort_three_case(t_stack **a, t_bench *bench);
void	sort_three(t_stack **a, t_bench *bench);
void	sort_small(t_stack **a, t_stack **b, t_bench *bench);
void	sort_five(t_stack **a, t_stack **b, t_bench *bench);
int		get_max_bits(t_stack *a);
void	push_min_to_b(t_stack **a, t_stack **b, t_bench *bench);
int		ft_find_min_pos(t_stack **a);
void	ft_radix_sort(t_stack **a, t_stack **b, t_bench *bench);
void	orch_sorting(t_stack **a, t_stack **b, int strategy, t_bench *bench);
double	ft_chaos(t_stack *stack);

void	simple_strategy(t_stack **a, t_stack **b, t_bench *bench);
void	medium_strategy(t_stack **a, t_stack **b, t_bench *bench);
void	complex_strategy(t_stack **a, t_stack **b, t_bench *bench);
void	adaptive_strategy(t_stack **a, t_stack **b, t_bench *bench);
void	init_bench(t_bench *bench);
void	print_bench_report(t_bench *bench, double chaos);
void	ft_dprintf(int fd, const char *format, ...);
int		ft_strcmp(const char *s1, const char *s2);
void	increment_op(t_bench *bench, char *op);

#endif

//adaptive
//orchestration