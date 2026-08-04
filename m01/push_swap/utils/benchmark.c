/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlandi <dlandi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 15:38:21 by dlandi            #+#    #+#             */
/*   Updated: 2026/08/01 16:35:57 by dlandi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_percent(float f)
{
	int	integer_part;
	int	decimal_part;

	f = f * 100.0;
	integer_part = (int)f;
	decimal_part = (int)((f - (float)integer_part) * 100.0 + 0.5);
	if (decimal_part >= 100)
	{
		integer_part++;
		decimal_part -= 100;
	}
	ft_putnbr_fd(integer_part, 2);
	ft_putchar_fd('.', 2);
	if (decimal_part < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(decimal_part, 2);
	ft_putstr_fd("%\n", 2);
}

static void	print_metric(char *label, int val, char *suffix)
{
	ft_putstr_fd(label, 2);
	ft_putnbr_fd(val, 2);
	if (suffix)
		ft_putstr_fd(suffix, 2);
}

void	print_benchmark(t_bench *bench)
{
	if (!bench || !bench->active)
		return ;
	ft_putstr_fd("[bench] disorder:  ", 2);
	print_percent(bench->disorder);
	ft_putstr_fd("[bench] strategy:  ", 2);
	if (bench->strategy_str)
		ft_putstr_fd(bench->strategy_str, 2);
	else
		ft_putstr_fd("Unknown", 2);
	ft_putstr_fd("\n", 2);
	print_metric("[bench] total_ops: ", bench->total_ops, "\n");
	ft_putstr_fd("[bench] ", 2);
	print_metric("sa:  ", bench->sa, "  ");
	print_metric("sb:  ", bench->sb, "  ");
	print_metric("ss:  ", bench->ss, "  ");
	print_metric("pa:  ", bench->pa, "  ");
	print_metric("pb:  ", bench->pb, "\n");
	ft_putstr_fd("[bench] ", 2);
	print_metric("ra:  ", bench->ra, "  ");
	print_metric("rb:  ", bench->rb, "  ");
	print_metric("rr:  ", bench->rr, "  ");
	print_metric("rra: ", bench->rra, "  ");
	print_metric("rrb: ", bench->rrb, "  ");
	print_metric("rrr: ", bench->rrr, "\n");
}
