/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlandi <dlandi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 19:03:06 by lfurtado          #+#    #+#             */
/*   Updated: 2026/08/01 15:22:04 by dlandi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **src, t_stack **dest)
{
	t_stack	*node;

	if (!src || !*src)
		return ;
	node = *src;
	*src = (*src)->next;
	node->next = (*dest);
	*dest = node;
}

void	pa(t_stack **a, t_stack **b, t_bench *bench)
{
	if (!b || !*b)
		return ;
	push(b, a);
	write(1, "pa\n", 3);
	if (bench && bench->active)
	{
		bench->pa++;
		bench->total_ops++;
	}
}

void	pb(t_stack **a, t_stack **b, t_bench *bench)
{
	if (!a || !*a)
		return ;
	push(a, b);
	write(1, "pb\n", 3);
	if (bench && bench->active)
	{
		bench->pb++;
		bench->total_ops++;
	}
}
