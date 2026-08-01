/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsint_pf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfurtado <lfurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 16:01:45 by lfurtado          #+#    #+#             */
/*   Updated: 2026/07/01 20:20:33 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsint_pf(unsigned int n)
{
	int	count_recursion;
	int	count_current;

	if (n == 0)
		return (ft_putchar_pf('0'));
	count_recursion = 0;
	if (n >= 10)
		count_recursion = ft_putnbr_pf(n / 10);
	count_current = (ft_putchar_pf((n % 10) + '0'));
	return (count_recursion + count_current);
}
