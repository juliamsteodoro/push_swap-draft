/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-mace <nde-mace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 19:50:00 by nde-mace          #+#    #+#             */
/*   Updated: 2026/06/28 17:08:32 by nde-mace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include "libft/libft.h"
# include <stdio.h>

int		*ft_valid(int argc, char **argv);
double	ft_chaos(const int *numbers, int len);
typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;
int		ft_error(void);
int		ft_isnumber(char *str);
int		ft_stack_len(t_stack **a);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	ft_sort_three(t_stack **a);
double  ft_chaos(const int *numbers, int len);
void	orchestration_sorting(t_stack **a, t_stack **b, int len, int *numbers);
int		ft_find_min_pos(t_stack **a);
void	ft_sort_small(t_stack **a, t_stack **b);
int		ft_is_dup(int argc, char **argv);
void	ft_index_stack(t_stack **a);
long    ft_atol(const char *str);
t_stack *ft_newstack(long n);
void    ft_free_stack(t_stack **a);
t_stack *ft_init_stack(t_stack **a, int *numbers, int len_numbers);
int		ft_isdigit(int c);


#endif
