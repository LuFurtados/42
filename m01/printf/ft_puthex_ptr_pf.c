/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_ptr_pf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfurtado <lfurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 15:58:10 by lfurtado          #+#    #+#             */
/*   Updated: 2026/07/01 20:34:29 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_ptr_pf(unsigned long n)
{
	int		count_recursion;
	int		count_current;
	char	*str_hex;

	str_hex = "0123456789abcdef";
	count_recursion = 0;
	if (n >= 16)
		count_recursion = (ft_puthex_ptr_pf(n / 16));
	count_current = (ft_putchar_pf(str_hex[n % 16]));
	return (count_recursion + count_current);
}
