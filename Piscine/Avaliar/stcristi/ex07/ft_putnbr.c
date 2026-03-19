/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stcristi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 14:12:49 by stcristi          #+#    #+#             */
/*   Updated: 2026/03/10 14:44:15 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long	a;
	char	c;

	a = nb;
	if (a < 0)
	{
		write (1, "-", 1);
		a = -a;
	}
	if (a >= 10)
	{
		ft_putnbr(a / 10);
	}
	c = (a % 10) + '0';
	write (1, &c, 1);
}

int	main(void)
{
	ft_putnbr(42);
	return (0);
}
