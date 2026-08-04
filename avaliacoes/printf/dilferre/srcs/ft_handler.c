/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilferre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 14:52:27 by dilferre          #+#    #+#             */
/*   Updated: 2026/06/08 16:46:23 by dilferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_pf(char c)
{
	return (write(1, &c, 1));
}

int	ft_putptr(unsigned long ptr)
{
	int	count;

	count = 0;
	if (ptr == 0)
	{
		count = count + ft_putstr_pf("(nil)");
		return (count);
	}
	count = count + write(1, "0x", 2);
	count = count + ft_puthex_long(ptr);
	return (count);
}

int	ft_putstr_pf(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putunsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count = count + ft_putunsigned(n / 10);
	count = count + ft_putchar_pf((n % 10) + '0');
	return (count);
}
