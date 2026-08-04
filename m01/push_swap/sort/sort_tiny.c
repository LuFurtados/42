/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tiny.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlandi <dlandi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 14:57:39 by dlandi            #+#    #+#             */
/*   Updated: 2026/08/01 16:38:31 by dlandi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **stack_a, t_bench *bench)
{
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a, bench);
}

static t_stack	*find_max(t_stack *stack)
{
	t_stack	*max_node;
	int		max_val;

	max_node = stack;
	max_val = stack->value;
	while (stack)
	{
		if (stack->value > max_val)
		{
			max_val = stack->value;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

void	sort_three(t_stack **stack_a, t_bench *bench)
{
	t_stack	*max_node;

	max_node = find_max(*stack_a);
	if (*stack_a == max_node)
		ra(stack_a, bench);
	else if ((*stack_a)->next == max_node)
		rra(stack_a, bench);
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a, bench);
}
