/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfurtado <lfurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 15:56:28 by lfurtado          #+#    #+#             */
/*   Updated: 2026/07/01 15:57:21 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_pf(unsigned int n, char t)
{
	int		count_recursion;
	int		count_current;
	char	*str_hex;

	if (t == 'x')
		str_hex = "0123456789abcdef";
	else
		str_hex = "0123456789ABCDEF";
	count_recursion = 0;
	if (n >= 16)
		count_recursion = (ft_puthex_pf(n / 16, t));
	count_current = (ft_putchar_pf(str_hex[n % 16]));
	return (count_recursion + count_current);
}
