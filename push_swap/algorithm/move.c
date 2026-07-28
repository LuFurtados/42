/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfurtado <lfurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 18:11:50 by lfurtado          #+#    #+#             */
/*   Updated: 2026/07/28 18:28:35 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "push_swap.h"

static void	rotate_both(t_stack **a, t_stack **b, t_stack *node)
{
	while (node->cost_a > 0 && node->cost_b > 0)
	{
		rr(a, b);
		node->cost_a--;
		node->cost_b--;
	}
}

static void	reverse_rotate_both(t_stack **a, t_stack **b, t_stack *node)
{
	while (node->cost_a < 0 && node->cost_b < 0)
	{
		rrr(a, b);
		node->cost_a++;
		node->cost_b++;
	}
}

static void	rotate_a(t_stack **a, t_stack *node)
{
	while (node->cost_a > 0)
	{
		ra(a);
		node->cost_a--;
	}
	while (node->cost_a < 0)
	{
		rra(a);
		node->cost_a++;
	}
}

static void	rotate_b(t_stack **b, t_stack *node)
{
	while (node->cost_b > 0)
	{
		rb(b);
		node->cost_b--;
	}
	while (node->cost_b < 0)
	{
		rrb(b);
		node->cost_b++;
	}
}

void	move_cheapest(t_stack **a, t_stack **b, t_stack *cheapest)
{
	if (!cheapest)
		return ;
	rotate_both(a, b, cheapest);
	reverse_rotate_both(a, b, cheapest);
	rotate_a(a, cheapest);
	rotate_b(b, cheapest);
	pa(a, b);
}
