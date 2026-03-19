/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguedes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 10:53:53 by eguedes-          #+#    #+#             */
/*   Updated: 2026/03/10 15:48:36 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putnbr_base(int nbr, char *base);

int		check_invalid(char *base);

int		write_result(int nbr, char *base, int size);

int	check_invalid(char *base)
{
	int	i;
	int	j;

	if (!base || !base[0] || !base[1])
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base [i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	write_result(int nbr, char *base, int size)
{
	int		i;
	long	n;
	char	result[35];

	i = 0;
	n = nbr;
	if (n < 0)
		n = -n;
	if (n == 0)
	{
		write(1, &base[0], 1);
		return (0);
	}
	while (n > 0)
	{
		result[i] = base[n % size];
		n = n / size;
		i++;
	}
	i--;
	while (i >= 0)
		write(1, &result[i--], 1);
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	size;

	if (nbr < 0)
		write(1, "-", 1);
	if (!check_invalid(base))
		return ;
	size = 0;
	while (base[size])
			size++;
	write_result(nbr, base, size);
}

int main(void)
{
    // Teste Decimal
    write(1, "Decimal -42: ", 12);
    ft_putnbr_base(-42, "0123456789");
    write(1, "\n", 1);

    // Teste Hexa
    write(1, "Hexa 255: ", 10);
    ft_putnbr_base(255, "0123456789ABCDEF");
    write(1, "\n", 1);

    // Teste octal
	write(1, "Octal 255: ", 11);
    ft_putnbr_base(255, "poneyvif");
	write(1, "\n", 1);  

    // Teste Binário
    write(1, "Binario 5: ", 11);
    ft_putnbr_base(5, "01");
    write(1, "\n", 1);

    // Teste Min Int (O terror da 42)
    write(1, "Min Int: ", 9);
    ft_putnbr_base(-2147483648, "0123456789");
    write(1, "\n", 1);

	// Teste com '0'
	write(1, "Teste com '0': ", 15);
	write(1, "\n", 1);

	// Teste base vazia
	write(1, "Base vazia: ", 12);
	ft_putnbr_base(42, "");
	write(1, "\n", 1);

	// Teste apenas 1 caractere
	write(1, "Apenas '1' caractere: ", 22);
	ft_putnbr_base(42, "1");
	write(1, "\n", 1);

	// Teste base contem duplicados
	write(1, "Base com duplicado: ", 20);
	ft_putnbr_base(42, "012012");
	write(1, "\n", 1);

	// Teste base contem + ou -
	write(1, "Base contem + ou -: ", 20);
	ft_putnbr_base(42, "0123-567+9");
	write(1, "\n", 1);

    return (0);
}
