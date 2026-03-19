/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfurtado <lfurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 14:32:40 by rde-melo          #+#    #+#             */
/*   Updated: 2026/03/16 14:29:48 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write (1, "-2147483648", 1);
		return ;
	}
	if (nb < 0)
	{
		write (1, "-", 1);
		nb = -nb;
	}
	if (nb / 10 == 0)
	{
		nb = nb + '0';
		write (1, &nb, 1);
		return ;
	}
	ft_putnbr (nb / 10);
	nb = (nb % 10) + '0';
	write (1, &nb, 1);
}

int	main (void)
{
	ft_putnbr(-2147483648);
	return (0);
}
