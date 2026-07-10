/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-mace <nde-mace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 19:50:00 by nde-mace          #+#    #+#             */
/*   Updated: 2026/07/04 18:09:00 by nde-mace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

#define STRATEGY_SIMPLE 1
#define STRATEGY_MEDIUM 2
#define STRATEGY_COMPLEX 3
#define STRATEGY_ADAPTIVE 4

int		validar_argumentos(char **args, int start);
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

void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);

void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

void	sort_two(t_stack **a);
void	sort_three(t_stack **a);
void	sort_small(t_stack **a, t_stack **b);
void	sort_five(t_stack **a, t_stack **b);
int 	get_max_bits(t_stack *a);
void 	push_min_to_b(t_stack **a, t_stack **b);
int		ft_find_min_pos(t_stack **a); 
void    ft_radix_sort(t_stack **a, t_stack **b);
void    orchestration_sorting(t_stack **a, t_stack **b, int len, int *numbers, int strategy);
double  ft_chaos(const int *numbers, int len);

void    simple_strategy(t_stack **a, t_stack **b);
void    medium_strategy(t_stack **a, t_stack **b);
void    complex_strategy(t_stack **a, t_stack **b);
void    adaptive_strategy(t_stack **a, t_stack **b, int len, int *numbers);


#endif