/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfurtado <lfurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 15:59:27 by lfurtado          #+#    #+#             */
/*   Updated: 2026/07/01 20:14:24 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_pf(int n)
{
	long	number;
	int		count_recursion;
	int		count_current;

	number = n;
	if (number == 0)
		return (ft_putchar_pf('0'));
	count_recursion = 0;
	if (number < 0)
	{
		ft_putchar_pf('-');
		number = -number;
		count_recursion++;
	}
	if (number >= 10)
		count_recursion += ft_putnbr_pf(number / 10);
	count_current = ft_putchar_pf((number % 10) + '0');
	return (count_recursion + count_current);
}
