/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 06:05:38 by carocha-          #+#    #+#             */
/*   Updated: 2026/03/03 12:33:31 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

void	ft_rev_int_tab(int *tab, int size);

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	aux;

	i = size - 1;
	j = 0;
	while (i >= size / 2)
	{
		aux = tab[j];
		tab[j] = tab[i];
		tab[i] = aux;
		i--;
		j++;
	}
}

int	main(void)
{
	int	tab[] = {3, 5, 6, 9, 7, 6, 8};

	ft_rev_int_tab(tab, 7);
	for (int i = 0; i < 7; i++)
		printf("%i", tab[i]);
}
