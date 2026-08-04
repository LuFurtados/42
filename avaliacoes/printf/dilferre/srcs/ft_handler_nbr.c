/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_nbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilferre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 15:50:44 by dilferre          #+#    #+#             */
/*   Updated: 2026/06/08 16:48:37 by dilferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_long(unsigned long n)
{
	int		count;
	char	*base;

	count = 0;
	base = "0123456789abcdef";
	if (n >= 16)
		count = count + ft_puthex_long(n / 16);
	write(1, &base[n % 16], 1);
	return (count + 1);
}

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		count = count + ft_putchar_pf('-');
		n = -n;
	}
	if (n >= 10)
		count = count + ft_putnbr(n / 10);
	count = count + ft_putchar_pf((n % 10) + '0');
	return (count);
}

int	ft_puthex(unsigned int n, char specifier)
{
	int		count;
	char	*base;

	count = 0;
	if (specifier == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n >= 16)
		count = count + ft_puthex(n / 16, specifier);
	write(1, &base[n % 16], 1);
	return (count + 1);
}
