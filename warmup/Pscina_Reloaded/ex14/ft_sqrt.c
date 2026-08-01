/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfurtado <lfurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 14:39:04 by lfurtado          #+#    #+#             */
/*   Updated: 2026/05/20 15:48:02 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	odd;
	int	count;

	odd = 1;
	count = 0;
	if (nb <= 0)
		return (0);
	while (nb >= odd)
	{
		nb = nb - odd;
		odd = odd + 2;
		count++;
	}
	if (nb == 0)
		return (count);
	else
		return (0);
}
/*
#include <stdio.h>
int main()
{
    int ret;

    ret = ft_sqrt(2.45);
    printf("A raiz quadrada: %d\n", ret);
    return 0;
}
*/