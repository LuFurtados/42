/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stcristi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 18:16:27 by stcristi          #+#    #+#             */
/*   Updated: 2026/03/10 14:36:06 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void);
void	exib_numer_ord(char n1, char n2, char n3);

void	exib_numer_ord(char n1, char n2, char n3)
{
	write (1, &n1, 1);
	write (1, &n2, 1);
	write (1, &n3, 1);
	if (!(n1 == '7' && n2 == '8' && n3 == '9'))
	{
		write (1, ", ", 2);
	}
}

void	ft_print_comb(void)
{
	char	digito_1;
	char	digito_2;
	char	digito_3;

	digito_1 = '0';
	while (digito_1 <= '7')
	{
		digito_2 = digito_1 + 1;
		while (digito_2 <= '8')
		{
			digito_3 = digito_2 + 1;
			while (digito_3 <= '9')
			{
				exib_numer_ord(digito_1, digito_2, digito_3);
				digito_3++;
			}
			digito_2++;
		}
		digito_1++;
	}
}

int	main(void)
{
	ft_print_comb();
	return (0);
}
