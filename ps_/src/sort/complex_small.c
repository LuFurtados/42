/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucsanto <lucsanto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 16:40:00 by lucsanto          #+#    #+#             */
/*   Updated: 2026/07/24 20:50:37 by lucsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_index_pos(t_stack *stack, int target, int limit)
{
	int	position;

	position = 0;
	while (stack && position < limit)
	{
		if (stack->index == target)
			return (position);
		stack = stack->next;
		position++;
	}
	return (0);
}

static void	move_a_target(t_data *data, int position)
{
	int	rotations;

	rotations = position;
	while (position-- > 0)
		ra(data);
	pb(data);
	while (rotations-- > 0)
		rra(data);
}

static void	move_b_target(t_data *data, int position)
{
	int	rotations;

	rotations = position;
	while (position-- > 0)
		rb(data);
	pa(data);
	while (rotations-- > 0)
		rrb(data);
}

void	complex_small_a(t_data *data, int size, int min)
{
	int	total;

	total = size;
	while (size > 0)
	{
		move_a_target(data, find_index_pos(data->a, min, size));
		min++;
		size--;
	}
	while (total-- > 0)
		pa(data);
}

void	complex_small_b(t_data *data, int size, int min)
{
	int	target;

	target = min + size - 1;
	while (size > 0)
	{
		move_b_target(data, find_index_pos(data->b, target, size));
		target--;
		size--;
	}
}
