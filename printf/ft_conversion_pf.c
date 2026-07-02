/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_pf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfurtado <lfurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 15:52:37 by lfurtado          #+#    #+#             */
/*   Updated: 2026/07/01 15:53:29 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversion_pf(va_list args, char c)
{
	if (c == 'c')
		return (ft_putchar_pf(va_arg(args, int)));
	if (c == 's')
		return (ft_putstr_pf(va_arg(args, char *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr_pf(va_arg(args, int)));
	if (c == 'u')
		return (ft_putnbr_unsint_pf(va_arg(args, unsigned int)));
	if (c == 'x' || c == 'X')
		return (ft_puthex_pf(va_arg(args, unsigned int), c));
	if (c == 'p')
		return (ft_putptr_pf(va_arg(args, void *)));
	if (c == '%')
		return (ft_putchar_pf(c));
	return (0);
}
