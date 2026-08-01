/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfurtado <lfurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 17:31:06 by lfurtado          #+#    #+#             */
/*   Updated: 2026/07/28 18:06:58 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_total_cost(t_stack *node)
{
	int	cost_a;
	int	cost_b;

	cost_a = node->cost_a;
	if (cost_a < 0)
		cost_a = -cost_a;
	cost_b = node->cost_b;
	if (cost_b < 0)
		cost_b = -cost_b;
	if ((node->cost_a >= 0 && node->cost_b >= 0)
		|| (node->cost_a < 0 && node->cost_b < 0))
	{
		if (cost_a > cost_b)
			return (cost_a);
		return (cost_b);
	}
	return (cost_a + cost_b);
}

t_stack	*find_cheapest(t_stack *stack_b)
{
	t_stack	*cheapest;
	int		min_cost;
	int		current_cost;

	if (!stack_b)
		return (NULL);
	cheapest = stack_b;
	min_cost = get_total_cost(stack_b);
	stack_b = stack_b->next;
	while (stack_b)
	{
		current_cost = get_total_cost(stack_b);
		if (current_cost < min_cost)
		{
			min_cost = current_cost;
			cheapest = stack_b;
		}
		stack_b = stack_b->next;
	}
	return (cheapest);
}
