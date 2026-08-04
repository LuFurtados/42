/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlandi <dlandi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 18:36:28 by lfurtado          #+#    #+#             */
/*   Updated: 2026/08/01 15:23:25 by dlandi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_stack **a, t_bench *bench)
{
	if (!a || !*a || !(*a)->next)
		return ;
	swap(a);
	write(1, "sa\n", 3);
	if (bench && bench->active)
	{
		bench->sa++;
		bench->total_ops++;
	}
}

void	sb(t_stack **b, t_bench *bench)
{
	if (!b || !*b || !(*b)->next)
		return ;
	swap(b);
	write(1, "sb\n", 3);
	if (bench && bench->active)
	{
		bench->sb++;
		bench->total_ops++;
	}
}

void	ss(t_stack **a, t_stack **b, t_bench *bench)
{
	if (!a || !*a || !(*a)->next)
		return ;
	if (!b || !*b || !(*b)->next)
		return ;
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
	if (bench && bench->active)
	{
		bench->ss++;
		bench->total_ops++;
	}
}
