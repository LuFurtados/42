/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:01:55 by carocha-          #+#    #+#             */
/*   Updated: 2026/03/03 12:39:45 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

void	ft_sort_int_tab(int *tab, int size);

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	aux;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				aux = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = aux;
			}
			j++;
		}
		i++;
	}
}

int	main(void)
{
	int	tab[] = {4, 6, 1, 9, 3, 8};

	ft_sort_int_tab(tab, 6);
	for(int i = 0; i < 6; i++)
		printf("%i", tab[i]);
}
