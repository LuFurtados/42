/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucsanto <lucsanto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 15:15:19 by lucsanto          #+#    #+#             */
/*   Updated: 2026/07/24 18:47:26 by lucsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	integer_sqrt_ceil(int n)
{
	int	root;

	root = 1;
	while (root <= n / root && root * root < n)
		root++;
	return (root);
}

static void	push_low_bucket(t_data *data, int bucket, int base)
{
	int	size;
	int	i;

	size = stack_size(data->a);
	i = 0;
	while (i < size)
	{
		if (data->a->index % base == bucket)
			pb(data);
		else
			ra(data);
		i++;
	}
}

static void	push_high_bucket(t_data *data, int bucket, int base)
{
	int	size;
	int	i;

	size = stack_size(data->b);
	i = 0;
	while (i < size)
	{
		if (data->b->index / base == bucket)
			pa(data);
		else
			rb(data);
		i++;
	}
}

void	sort_medium(t_data *data)
{
	int	base;
	int	bucket;
	int	buckets;

	if (!data || !data->a)
		return ;
	base = integer_sqrt_ceil(stack_size(data->a));
	buckets = (stack_size(data->a) + base - 1) / base;
	bucket = 0;
	while (bucket < base)
		push_low_bucket(data, bucket++, base);
	bucket = buckets - 1;
	while (bucket >= 0)
	{
		push_high_bucket(data, bucket, base);
		bucket--;
	}
}
