/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlandi <dlandi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 15:27:37 by dlandi            #+#    #+#             */
/*   Updated: 2026/08/01 16:48:04 by dlandi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_inversions(t_stack *stack)
{
	t_stack	*current;
	t_stack	*runner;
	int		inversions;

	inversions = 0;
	current = stack;
	while (current)
	{
		runner = current->next;
		while (runner)
		{
			if (current->value > runner->value)
				inversions++;
			runner = runner->next;
		}
		current = current->next;
	}
	return (inversions);
}

float	calculate_disorder(t_stack *stack)
{
	int		inversions;
	int		max_inv;
	int		n;

	if (!stack || !stack->next)
		return (0.0);
	n = stack_size(stack);
	max_inv = (n * (n - 1)) / 2;
	if (max_inv == 0)
		return (0.0);
	inversions = count_inversions(stack);
	return ((float)inversions / (float)max_inv);
}
