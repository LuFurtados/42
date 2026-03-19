/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkaue-fa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 17:09:06 by lkaue-fa          #+#    #+#             */
/*   Updated: 2026/03/17 18:20:01 by lkaue-fa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	aux;

	aux = *a / *b;
	*b = *a % *b;
	*a = aux;
}
/*
#include <unistd.h>

int	main(void)
{
	int	a;
	int	b;

	a = 5;
	b = 6;
	ft_ultimate_div_mod(&a, &b);
	write(1, &"0123456789"[a], 1);
	write(1, &"0123456789"[b], 1);
	return (0);
}*/
