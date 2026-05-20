/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfurtado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 17:46:21 by lfurtado          #+#    #+#             */
/*   Updated: 2026/03/04 18:04:35 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b);

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	aux;

	aux = *a;
	*a = *a / *b;
	*b = aux % *b;
}
/*
int	main(void)
{
	int	div;
	int	mod;

	div = 10;
	mod = 3;
	ft_ultimate_div_mod(&div, &mod);
	printf("div: %i mod: %i", div, mod);
}
*/
