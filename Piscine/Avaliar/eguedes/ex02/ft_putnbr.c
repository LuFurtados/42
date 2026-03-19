/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguedes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 17:39:39 by eguedes-          #+#    #+#             */
/*   Updated: 2026/03/10 15:18:28 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putnbr(int nb);

void	ft_rev_char_tab(char *tab, int size);

void	ft_num(int *i, long temp, char *number);

void	ft_numb(int *i, long temp, char *number)
{
	while (temp > 0)
	{
		number[*i] = (temp % 10) + '0';
		temp = temp / 10;
		(*i)++;
	}
	ft_rev_char_tab(number, *i);
}

void	ft_rev_char_tab(char *tab, int size)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	j = size -1;
	while (i < j)
	{
		temp = tab[i];
		tab[i] = tab[j];
		tab[j] = temp;
		i++;
		j--;
	}
}

void	ft_putnbr(int nb)
{
	int		i;
	char	number[20];
	long	temp;
	int		if_neg;

	i = 0;
	temp = nb;
	if_neg = 0;
	if (temp == 0)
	{
		i = 1;
		number[0] = '0';
	}
	else if (temp < 0)
	{
		temp = -temp;
		if_neg = 1;
	}
	ft_numb(&i, temp, number);
	if (if_neg == 1)
		write(1, "-", 1);
	write(1, number, i);
}

// Auxiliar para pular linha nos testes
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(void)
{
	write(1, "Teste 1 (Positivo): ", 20);
	ft_putnbr(42);
	ft_putchar('\n');

	write(1, "Teste 2 (Zero): ", 16);
	ft_putnbr(0);
	ft_putchar('\n');

	write(1, "Teste 3 (Negativo): ", 20);
	ft_putnbr(-2147);
	ft_putchar('\n');

	write(1, "Teste 4 (Max Int): ", 19);
	ft_putnbr(2147483647);
	ft_putchar('\n');

	write(1, "Teste 5 (Min Int - O Chefe): ", 29);
	ft_putnbr(-2147483648);
	ft_putchar('\n');

	return (0);
}
