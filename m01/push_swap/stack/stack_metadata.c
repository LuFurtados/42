/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_metadata.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfurtado <lfurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 16:17:37 by lfurtado          #+#    #+#             */
/*   Updated: 2026/07/28 16:30:27 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_position(t_stack *stack)
{
	int	position;

	position = 0;
	while (stack)
	{
		stack->position = position;
		position++;
		stack = stack->next;
	}
}

void	update_index(t_stack *stack)
{
	t_stack	*current;
	t_stack	*runner;
	int		index;

	current = stack;
	while (current)
	{
		index = 0;
		runner = stack;
		while (runner)
		{
			if (runner->value < current->value)
				index++;
			runner = runner->next;
		}
		current->index = index;
		current = current->next;
	}
}

int	find_min_position(t_stack *stack)
{
	int		min_value;
	int		min_pos;
	int		current_pos;
	t_stack	*current;

	if (stack == NULL)
		return (0);
	min_value = 2147483647;
	min_pos = 0;
	current_pos = 0;
	current = stack;
	while (current != NULL)
	{
		if (current->value < min_value)
		{
			min_value = current->value;
			min_pos = current_pos;
		}
		current_pos++;
		current = current->next;
	}
	return (min_pos);
}

static int	get_target(t_stack *stack_a, int b_value)
{
	t_stack	*cur_a;
	int		target_pos;
	long	match_value;

	cur_a = stack_a;
	target_pos = 0;
	match_value = 2147483648;
	while (cur_a)
	{
		if (cur_a->value > b_value && cur_a->value < match_value)
		{
			match_value = cur_a->value;
			target_pos = cur_a->position;
		}
		cur_a = cur_a->next;
	}
	if (match_value == 2147483648)
		return (find_min_position(stack_a));
	return (target_pos);
}

void	update_target_position(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*cur_b;

	cur_b = stack_b;
	while (cur_b)
	{
		cur_b->target_position = get_target(stack_a, cur_b->value);
		cur_b = cur_b->next;
	}
}
