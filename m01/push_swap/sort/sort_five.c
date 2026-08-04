/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlandi <dlandi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 14:57:19 by dlandi            #+#    #+#             */
/*   Updated: 2026/08/01 16:47:57 by dlandi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_smallest_to_b(t_stack **stack_a, t_stack **stack_b,
								t_bench *bench)
{
	int	min_pos;
	int	size;

	update_position(*stack_a);
	min_pos = find_min_position(*stack_a);
	size = stack_size(*stack_a);
	if (min_pos > size / 2)
	{
		while (min_pos < size)
		{
			rra(stack_a, bench);
			min_pos++;
		}
	}
	else
	{
		while (min_pos > 0)
		{
			ra(stack_a, bench);
			min_pos--;
		}
	}
	pb(stack_a, stack_b, bench);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	int	size;

	size = stack_size(*stack_a);
	while (size > 3)
	{
		push_smallest_to_b(stack_a, stack_b, bench);
		size--;
	}
	sort_three(stack_a, bench);
	while (*stack_b)
		pa(stack_a, stack_b, bench);
}
