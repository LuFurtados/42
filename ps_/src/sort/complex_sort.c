/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfurtado <lfurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 15:14:52 by lucsanto          #+#    #+#             */
/*   Updated: 2026/07/29 18:21:27 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	partition_a(t_data *data, int size, int pivot)
{
	int	rotations;

	rotations = 0;
	while (size-- > 0)
	{
		if (data->a->index < pivot)
			pb(data);
		else
		{
			ra(data);
			rotations++;
		}
	}
	return (rotations);
}

static void	restore_a(t_data *data, int rotations, int upper)
{
	while (stack_size(data->a) > upper && rotations-- > 0)
		rra(data);
}

void	quick_sort_a(t_data *data, int size, int min)
{
	int	pivot;
	int	lower;
	int	rotations;

	if (size <= 1)
		return ;
	if (size <= 5)
	{
		complex_small_a(data, size, min);
		return ;
	}
	lower = size / 2;
	pivot = min + lower;
	rotations = partition_a(data, size, pivot);
	restore_a(data, rotations, size - lower);
	quick_sort_a(data, size - lower, pivot);
	quick_sort_b(data, lower, min);
}

void	sort_complex(t_data *data)
{
	if (!data || !data->a)
		return ;
	quick_sort_a(data, stack_size(data->a), 0);
}
