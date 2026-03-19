/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaue-fa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 16:45:58 by lkaue-fa          #+#    #+#             */
/*   Updated: 2026/03/17 18:47:48 by lkaue-fa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*
#include <unistd.h>

int	main(void)
{
	int	a;
	int	b;
	int	div;
	int	mod;

	a = 8;
	b = 7;
	ft_div_mod(a, b, &div, &mod);
	write(1, &"0123456789"[div], 1);
	write(1, &"0123456789"[mod], 1);
	write(1, "\n", 1);
	return (0);
}*/
