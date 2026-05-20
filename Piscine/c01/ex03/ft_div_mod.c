/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfurtado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 12:31:52 by lfurtado          #+#    #+#             */
/*   Updated: 2026/03/04 14:09:47 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod);

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*
int	main(void)
{
	int	number1;
	int	number2;
	int	div;
	int	mod;

	number1 = 10;
	number2 = 3;
	div = 0;
	mod = 0;
	ft_div_mod(number1, number2, &div, &mod);
	printf("div: %i mod: %i", div, mod);
}
*/
