/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariafer <mariafer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 14:41:50 by mariafer          #+#    #+#             */
/*   Updated: 2026/07/26 14:41:51 by mariafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_two_digits(int n)
{
	if (n < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(n, 2);
}

void	print_percent(double value)
{
	int	percent;

	percent = (int)(value * 10000.0 + 0.5);
	ft_putnbr_fd(percent / 100, 2);
	ft_putchar_fd('.', 2);
	print_two_digits(percent % 100);
}

char	*strategy_name(t_strategy strategy)
{
	if (strategy == S_SIMPLE)
		return ("Simple");
	if (strategy == S_MEDIUM)
		return ("Medium");
	if (strategy == S_COMPLEX)
		return ("Complex");
	return ("Adaptive");
}

char	*strategy_complexity(t_strategy strategy)
{
	if (strategy == S_SIMPLE)
		return ("O(n^2)");
	if (strategy == S_MEDIUM)
		return ("O(n√n)");
	if (strategy == S_COMPLEX)
		return ("O(n log n)");
	return ("Adaptive");
}
