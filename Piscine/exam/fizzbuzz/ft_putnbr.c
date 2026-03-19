/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfurtado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 18:44:34 by lfurtado          #+#    #+#             */
/*   Updated: 2026/03/19 15:36:20 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	long	nbl;
	char	c;

	nbl = nb;
	if (nbl < 0)
	{
		write(1, "-", 1);
		nbl = -nbl;
	}
	if (nbl > 9)
		ft_putnbr(nbl / 10);
	c = (nbl % 10) + '0';
	write(1, &c, 1);
}

void	ft_fizzbuzz(int n)
{
	int	i;

	i = n;
	while (i <= 100)
	{
		if (i % 3 == 0)
			write(1, "FIZZ", 4);
		if (i % 5 == 0)
			write(1, "BUZZ", 4);
		if (i % 3 && i % 5)
			ft_putnbr(i);
		write(1, "\n", 1);
		i++;
	}
}

int	main(void)
{
	int	n;

	n = 1;
	ft_fizzbuzz(n);
}
