/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfurtado <lfurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 21:21:45 by lfurtado          #+#    #+#             */
/*   Updated: 2026/07/29 16:43:52 by lfurtado         ###   ########.fr       */
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

t_stack	*stack_new(int value);
t_stack	*stack_last(t_stack *node);
t_stack	*find_cheapest(t_stack *stack_b);
int		build_stack(int argc, char **argv, t_stack **stack_a);
int		validate_number(char *str);
int		check_overflow(char *str);
int		check_duplicate(t_stack *stack, int value);
int		stack_size(t_stack *stack);
int		stack_is_sorted(t_stack *stack);
void	stack_clear(t_stack **stack);
void	stack_add_back(t_stack **stack, t_stack *new_node);
void	stack_print(t_stack *stack);
void	update_position(t_stack *stack);
void	update_index(t_stack *stack);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
int		find_min_position(t_stack *stack);
void	update_target_position(t_stack *stack_a, t_stack *stack_b);
void	update_cost(t_stack *stack_a, t_stack *stack_b);
void	move_cheapest(t_stack **a, t_stack **b, t_stack *cheapest);
void	update_metadata(t_stack *stack_a, t_stack *stack_b);
void	sort_stacks(t_stack **stack_a, t_stack **stack_b);
void	sort_two(t_stack **stack_a);
void	sort_three(t_stack **stack_a);
void	sort_five(t_stack **stack_a, t_stack **stack_b);
void	turk_sort(t_stack **stack_a, t_stack **stack_b);
void	final_rotate(t_stack **stack_a);

#endif