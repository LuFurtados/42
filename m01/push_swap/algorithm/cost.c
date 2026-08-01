/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfurtado <lfurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 16:54:52 by lfurtado          #+#    #+#             */
/*   Updated: 2026/07/28 17:24:51 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	calculate_cost(t_stack *node, int size_a, int size_b)
{
	if (node->position <= size_b / 2)
		node->cost_b = node->position;
	else
		node->cost_b = node->position - size_b;
	if (node->target_position <= size_a / 2)
		node->cost_a = node->target_position;
	else
		node->cost_a = node->target_position - size_a;
}

void	update_cost(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current;
	int		size_a;
	int		size_b;

	size_a = stack_size(stack_a);
	size_b = stack_size(stack_b);
	current = stack_b;
	while (current)
	{
		calculate_cost(current, size_a, size_b);
		current = current->next;
	}
}
