/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfurtado <lfurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 11:57:53 by lfurtado          #+#    #+#             */
/*   Updated: 2026/05/22 19:17:15 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	nb_factorial;

	nb_factorial = 1;
	if (nb == 0)
		return (1);
	if (nb < 0 || nb > 12)
		return (0);
	while (nb > 1)
	{
		nb_factorial = nb_factorial * nb;
		nb--;
	}
	return (nb_factorial);
}
/*
#include <stdio.h>

int	main (void)
{
	int	ret;

	ret = ft_iterative_factorial(3);
	printf("Fatorial eh %d\n", ret);
	ret = ft_iterative_factorial(-3);
	printf("Fatorial eh %d\n", ret);
	ret = ft_iterative_factorial(0);
	printf("Fatorial eh %d\n", ret);
	ret = ft_iterative_factorial(8);
	printf("Fatorial eh %d\n", ret);
	return (0);
}
*/