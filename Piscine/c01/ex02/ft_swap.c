/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfurtado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 19:46:40 by lfurtado          #+#    #+#             */
/*   Updated: 2026/03/04 11:22:08 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int	*a, int	*b);

void	ft_swap(int *a, int *b)
{
	int	aux;

	aux = *a;
	*a = *b;
	*b = aux;
}
/*
int	main(void)
{
	int	number1;
	int	number2;

	number1 = 10;
	number2 = 20;
	ft_swap(&number1, &number2);
	printf("a: %i b: %i", number1, number2);
	return (0);
}
*/
