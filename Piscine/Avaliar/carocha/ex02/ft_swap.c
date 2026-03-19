/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 00:19:49 by carocha-          #+#    #+#             */
/*   Updated: 2026/03/03 12:15:38 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>

void	ft_swap(int *a, int *b);

void	ft_swap(int *a, int *b)
{
	int	tmp;

	if (a && b)
	{
		tmp = *a;
		*a = *b;
		*b = tmp;
		printf("tmp: %i\n", tmp);
	}
}

int	main(void)
{
	int	a;
	int	b;

	a = 1;
	b = 2;
	ft_swap(&a, &b);
	printf("a: %i b: %i", a, b);
}
