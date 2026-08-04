/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlandi <dlandi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 14:22:12 by lfurtado          #+#    #+#             */
/*   Updated: 2026/08/01 16:19:04 by dlandi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stacks(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	int	size;

	size = stack_size(*stack_a);
	if (size == 2)
		sort_two(stack_a, bench);
	else if (size == 3)
		sort_three(stack_a, bench);
	else if (size <= 5)
		sort_five(stack_a, stack_b, bench);
	else
		turk_sort(stack_a, stack_b, bench);
}
