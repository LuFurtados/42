/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfurtado <lfurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 21:21:45 by lfurtado          #+#    #+#             */
/*   Updated: 2026/08/03 17:06:28 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				position;
	int				target_position;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

typedef enum e_strategy
{
	DEFAULT,
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}	t_strategy;

typedef struct s_options
{
	t_strategy	strategy;
	int			bench;
	int			first_arg;
}	t_options;

typedef struct s_bench
{
	int		active;
	float	disorder;
	char	*strategy_str;
	int		total_ops;
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
}	t_bench;

t_stack	*stack_new(int value);
t_stack	*stack_last(t_stack *node);
t_stack	*find_cheapest(t_stack *stack_b);
int		build_stack(int argc, char **argv, t_stack **stack_a);
int		validate_number(char *str);
int		check_overflow(char *str);
int		check_duplicate(t_stack *stack, int value);
int		stack_size(t_stack *stack);
int		stack_is_sorted(t_stack *stack);
int		find_min_position(t_stack *stack);
int		error(void);
int		parse_flags(int argc, char **argv, t_options *opt);
int		find_max_position(t_stack *stack);
void	stack_clear(t_stack **stack);
void	stack_add_back(t_stack **stack, t_stack *new_node);
void	stack_print(t_stack *stack);
void	update_position(t_stack *stack);
void	update_index(t_stack *stack);
void	sa(t_stack **a, t_bench *bench);
void	sb(t_stack **b, t_bench *bench);
void	ss(t_stack **a, t_stack **b, t_bench *bench);
void	pa(t_stack **a, t_stack **b, t_bench *bench);
void	pb(t_stack **a, t_stack **b, t_bench *bench);
void	ra(t_stack **a, t_bench *bench);
void	rb(t_stack **b, t_bench *bench);
void	rr(t_stack **a, t_stack **b, t_bench *bench);
void	rra(t_stack **a, t_bench *bench);
void	rrb(t_stack **b, t_bench *bench);
void	rrr(t_stack **a, t_stack **b, t_bench *bench);
void	update_target_position(t_stack *stack_a, t_stack *stack_b);
void	update_cost(t_stack *stack_a, t_stack *stack_b);
void	move_cheapest(t_stack **a, t_stack **b, t_stack *cheap, t_bench *bench);
void	update_metadata(t_stack *stack_a, t_stack *stack_b);
void	sort_stacks(t_stack **stack_a, t_stack **stack_b, t_bench *bench);
void	sort_two(t_stack **stack_a, t_bench *bench);
void	sort_three(t_stack **stack_a, t_bench *bench);
void	sort_five(t_stack **stack_a, t_stack **stack_b, t_bench *bench);
void	turk_sort(t_stack **stack_a, t_stack **stack_b, t_bench *bench);
void	final_rotate(t_stack **stack_a, t_bench *bench);
void	run_strategy(t_stack **a, t_stack **b, t_options *opt, t_bench *bench);
void	sort_simple(t_stack **a, t_stack **b, t_bench *bench);
void	sort_medium(t_stack **a, t_stack **b, t_bench *bench);
void	rotate_to_top_b(t_stack **b, int pos, t_bench *bench);
float	calculate_disorder(t_stack *stack);
void	sort_complex(t_stack **a, t_stack **b, t_bench *bench);
void	sort_adaptive(t_stack **a, t_stack **b, t_bench *bench);
void	print_benchmark(t_bench *bench);
void	free_matrix(char **matrix);
int		is_only_spaces(char *str);
int		count_split_words(char **argv, int start);
char	**get_flattened_args(int argc, char **argv, int first_arg, int *ac);

#endif