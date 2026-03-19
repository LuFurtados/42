/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfurtado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 18:44:34 by lfurtado          #+#    #+#             */
/*   Updated: 2026/03/19 14:34:35 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long	nbl;

	nbl = nb;
	if (nbl < 0)
	{
		write(1, "-", 1);
		nbl = -nbl;
	}
	if (nbl > 9)
		ft_putnbr(nbl / 10);
	ft_putchar((nbl % 10) + '0');
}
/*
int	main(void)
{
	int	n;

	n = 42;
	ft_putnbr(n);
}
*/
