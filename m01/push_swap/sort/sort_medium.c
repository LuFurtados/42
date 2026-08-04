/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfurtado <lfurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 14:21:48 by lfurtado          #+#    #+#             */
/*   Updated: 2026/08/03 16:31:02 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calculate_chunk_size(int size)
{
	int	chunk_size;

	if (size <= 100)
		return (size / 4);
	else if (size <= 500)
		return (size / 6);
	chunk_size = 1;
	while (chunk_size * chunk_size < size)
		chunk_size++;
	return (chunk_size * 2);
}

static void	push_chunks(t_stack **a, t_stack **b, int chunk_size,
						t_bench *bench)
{
	int	limit;
	int	b_size;

	limit = chunk_size;
	b_size = 0;
	while (*a)
	{
		if ((*a)->index < limit)
		{
			pb(a, b, bench);
			b_size++;
			if (*b && (*b)->index < limit - (chunk_size / 2))
				rb(b, bench);
			if (b_size == limit)
				limit += chunk_size;
		}
		else
			ra(a, bench);
	}
}

static void	push_back(t_stack **a, t_stack **b, t_bench *bench)
{
	int	pos;

	while (*b)
	{
		update_position(*b);
		pos = find_max_position(*b);
		rotate_to_top_b(b, pos, bench);
		pa(a, b, bench);
	}
}

void	sort_medium(t_stack **a, t_stack **b, t_bench *bench)
{
	int	size;
	int	chunk_size;

	size = stack_size(*a);
	update_index(*a);
	chunk_size = calculate_chunk_size(size);
	push_chunks(a, b, chunk_size, bench);
	push_back(a, b, bench);
}
