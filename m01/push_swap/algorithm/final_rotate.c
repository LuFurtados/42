/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlandi <dlandi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 16:39:44 by lfurtado          #+#    #+#             */
/*   Updated: 2026/08/01 16:36:42 by dlandi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_rotate(t_stack **stack_a, t_bench *bench)
{
	int	min_pos;
	int	size;

	if (!stack_a || !*stack_a)
		return ;
	update_position(*stack_a);
	min_pos = find_min_position(*stack_a);
	size = stack_size(*stack_a);
	if (min_pos <= size / 2)
	{
		while (min_pos > 0)
		{
			ra(stack_a, bench);
			min_pos--;
		}
	}
	else
	{
		while (min_pos < size)
		{
			rra(stack_a, bench);
			min_pos++;
		}
	}
}
