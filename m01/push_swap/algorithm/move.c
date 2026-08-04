/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfurtado <lfurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 18:11:50 by lfurtado          #+#    #+#             */
/*   Updated: 2026/08/03 17:07:20 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both(t_stack **a, t_stack **b, t_stack *n, t_bench *bench)
{
	while (n->cost_a > 0 && n->cost_b > 0)
	{
		rr(a, b, bench);
		n->cost_a--;
		n->cost_b--;
	}
}

static void	rev_rotate_both(t_stack **a, t_stack **b,
						t_stack *n, t_bench *bench)
{
	while (n->cost_a < 0 && n->cost_b < 0)
	{
		rrr(a, b, bench);
		n->cost_a++;
		n->cost_b++;
	}
}

static void	rotate_a(t_stack **a, t_stack *node, t_bench *bench)
{
	while (node->cost_a > 0)
	{
		ra(a, bench);
		node->cost_a--;
	}
	while (node->cost_a < 0)
	{
		rra(a, bench);
		node->cost_a++;
	}
}

static void	rotate_b(t_stack **b, t_stack *node, t_bench *bench)
{
	while (node->cost_b > 0)
	{
		rb(b, bench);
		node->cost_b--;
	}
	while (node->cost_b < 0)
	{
		rrb(b, bench);
		node->cost_b++;
	}
}

void	move_cheapest(t_stack **a, t_stack **b, t_stack *cheap, t_bench *bench)
{
	if (!cheap)
		return ;
	rotate_both(a, b, cheap, bench);
	rev_rotate_both(a, b, cheap, bench);
	rotate_a(a, cheap, bench);
	rotate_b(b, cheap, bench);
	pa(a, b, bench);
}
