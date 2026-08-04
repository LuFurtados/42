/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlandi <dlandi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 14:57:46 by dlandi            #+#    #+#             */
/*   Updated: 2026/08/01 16:38:35 by dlandi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	evacuate_to_b(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	int	size;
	int	pushed;

	size = stack_size(*stack_a);
	pushed = 0;
	while (size > 3 && pushed < size / 2)
	{
		pb(stack_a, stack_b, bench);
		pushed++;
	}
	while (size - pushed > 3)
	{
		pb(stack_a, stack_b, bench);
		pushed++;
	}
}

void	turk_sort(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	t_stack	*cheapest_node;

	evacuate_to_b(stack_a, stack_b, bench);
	sort_three(stack_a, bench);
	while (*stack_b)
	{
		update_metadata(*stack_a, *stack_b);
		cheapest_node = find_cheapest(*stack_b);
		move_cheapest(stack_a, stack_b, cheapest_node, bench);
	}
	update_position(*stack_a);
	final_rotate(stack_a, bench);
}
