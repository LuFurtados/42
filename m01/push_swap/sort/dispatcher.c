/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfurtado <lfurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 14:21:29 by lfurtado          #+#    #+#             */
/*   Updated: 2026/08/03 18:30:27 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	run_strategy(t_stack **a, t_stack **b, t_options *opt, t_bench *bench)
{
	if (opt->strategy == DEFAULT || opt->strategy == ADAPTIVE)
	{
		if (bench && (opt->strategy == DEFAULT || opt->strategy == ADAPTIVE))
			bench->strategy_str = "Adaptive / Dynamic (Default)";
		sort_adaptive(a, b, bench);
	}
	else if (opt->strategy == SIMPLE)
	{
		if (bench)
			bench->strategy_str = "Simple / O(n^2)";
		sort_simple(a, b, bench);
	}
	else if (opt->strategy == MEDIUM)
	{
		if (bench)
			bench->strategy_str = "Medium / O(n√n)";
		sort_medium(a, b, bench);
	}
	else if (opt->strategy == COMPLEX)
	{
		if (bench)
			bench->strategy_str = "Complex / O(n log n)";
		sort_complex(a, b, bench);
	}
}
