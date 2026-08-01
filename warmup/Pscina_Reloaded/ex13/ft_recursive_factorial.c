/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfurtado <lfurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 12:21:20 by lfurtado          #+#    #+#             */
/*   Updated: 2026/05/22 19:16:01 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb > 12)
		return (0);
	if (nb <= 1)
	{
		if (nb < 0)
			return (0);
		else
			return (1);
	}
	return (nb * ft_recursive_factorial(nb -1));
}
/*
#include <stdio.h>

int	main (void)
{
	int	ret;

	ret = ft_recursive_factorial(2);
	printf("O fatorial eh: %d\n", ret);
	return (0);
}
*/