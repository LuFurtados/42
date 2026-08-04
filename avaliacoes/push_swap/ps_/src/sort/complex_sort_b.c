/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucsanto <lucsanto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 15:21:49 by lucsanto          #+#    #+#             */
/*   Updated: 2026/07/24 20:46:02 by lucsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	partition_b(t_data *data, int size, int pivot)
{
	int	rotations;

	rotations = 0;
	while (size-- > 0)
	{
		if (data->b->index >= pivot)
			pa(data);
		else
		{
			rb(data);
			rotations++;
		}
	}
	return (rotations);
}

static void	restore_b(t_data *data, int rotations, int lower)
{
	while (stack_size(data->b) > lower && rotations-- > 0)
		rrb(data);
}

void	quick_sort_b(t_data *data, int size, int min)
{
	int	pivot;
	int	lower;
	int	rotations;

	if (size <= 0)
		return ;
	if (size <= 5)
	{
		complex_small_b(data, size, min);
		return ;
	}
	lower = size / 2;
	pivot = min + lower;
	rotations = partition_b(data, size, pivot);
	restore_b(data, rotations, lower);
	quick_sort_a(data, size - lower, pivot);
	quick_sort_b(data, lower, min);
}
