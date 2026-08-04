/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlandi <dlandi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 15:31:55 by dlandi            #+#    #+#             */
/*   Updated: 2026/08/01 19:07:58 by dlandi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_complex(t_stack **a, t_stack **b, t_bench *bench)
{
	turk_sort(a, b, bench);
}

void	sort_adaptive(t_stack **a, t_stack **b, t_bench *bench)
{
	int		size;
	float	disorder;

	size = stack_size(*a);
	if (size <= 3)
	{
		sort_three(a, bench);
		return ;
	}
	if (size <= 5)
	{
		sort_five(a, b, bench);
		return ;
	}
	disorder = calculate_disorder(*a);
	if (disorder < 0.2)
		sort_simple(a, b, bench);
	else if (disorder < 0.5)
		sort_medium(a, b, bench);
	else
		sort_complex(a, b, bench);
}
