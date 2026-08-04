/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_search.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlandi <dlandi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 14:23:37 by lfurtado          #+#    #+#             */
/*   Updated: 2026/08/01 16:35:52 by dlandi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_position(t_stack *stack)
{
	int		max;
	int		position;
	t_stack	*current;

	max = stack->value;
	position = stack->position;
	current = stack;
	while (current)
	{
		if (current->value > max)
		{
			max = current->value;
			position = current->position;
		}
		current = current->next;
	}
	return (position);
}

void	rotate_to_top_b(t_stack **b, int pos, t_bench *bench)
{
	int	size;

	size = stack_size(*b);
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			rb(b, bench);
			pos--;
		}
	}
	else
	{
		while (pos < size)
		{
			rrb(b, bench);
			pos++;
		}
	}
}
