/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stcristi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 13:21:30 by stcristi          #+#    #+#             */
/*   Updated: 2026/03/10 14:40:11 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void)
{
	int	colum_1;
	int	colum_2;

	colum_1 = 0;
	while (colum_1 <= 98)
	{
		colum_2 = colum_1 + 1;
		while (colum_2 <= 99)
		{
			write (1, &(char){colum_1 / 10 + '0'}, 1);
			write (1, &(char){colum_1 % 10 + '0'}, 1);
			write (1, " ", 1);
			write (1, &(char){colum_2 / 10 + '0'}, 1);
			write (1, &(char){colum_2 % 10 + '0'}, 1);
			if (!(colum_1 == 98 && colum_2 == 99))
				write (1, ", ", 2);
			colum_2++;
		}
	colum_1++;
	}	
}

int	main(void)
{
	ft_print_comb2();
	return (0);
}
