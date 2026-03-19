/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguedes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 15:49:40 by eguedes-          #+#    #+#             */
/*   Updated: 2026/03/10 15:56:44 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi_base(char *str, char *base);

int	ft_atoi(char *str);

int	special_char(char *str, int *i);

int	check_invalid(char *base);

int	conversion_result(char *str, int *i, char *base);

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

int	base_calc(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	special_char(char *str, int *i)
{
	int	count_neg;

	count_neg = 0;
	while ((str[*i] >= 9 && str[*i] <= 13) || str[*i] == 32)
		(*i)++;
	while (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			count_neg++;
		(*i)++;
	}
	if (count_neg % 2 != 0)
		return (-1);
	else
		return (1);
}

int	conversion_result(char *str, int *i, char *base)
{
	int	res;
	int	size;
	int	value;

	res = 0;
	size = 0;
	while (base[size])
		size++;
	value = base_calc(str[*i], base);
	while (str[*i] != '\0' && value != -1)
	{
		res = (res * size) + value;
		(*i)++;
		value = base_calc(str[*i], base);
	}
	return (res);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	signal;
	int	nbr;

	i = 0;
	if (!check_invalid(base))
		return (0);
	signal = special_char(str, &i);
	nbr = conversion_result(str, &i, base);
	return (nbr * signal);
}

#include <stdio.h>

int	main(void)
{
	printf("--- TESTES BÁSICOS ---\n");
	printf("Decimal (42): %d\n", ft_atoi_base("42", "0123456789"));
	printf("Negativo (-42): %d\n", ft_atoi_base("-42", "0123456789"));
	printf("Binário (101010 = 42): %d\n", ft_atoi_base("101010", "01"));
	printf("Hexa (2a = 42): %d\n", ft_atoi_base("2a", "0123456789abcdef"));

	printf("\n--- TESTES DE SINAIS E ESPAÇOS ---\n");
	// Devem pular espaços e tratar a quantidade de sinais '-'
	printf("Espaço e 1menos (-42): %d\n", ft_atoi_base("  -42", "0123456789"));
	printf("Múltiplosinal (-+-42): %d\n", ft_atoi_base(" -+-42", "0123456789"));

	printf("\n--- TESTES DE INTERRUPÇÃO ---\n");
	// Deve parar no primeiro caractere que não pertence à base
	printf("Parar no 'a' (42abc5): %d\n", ft_atoi_base("42abc5", "0123456789"));
	printf("Base Poneyvif (pon): %d\n", ft_atoi_base("pon", "poneyvif"));

	printf("\n--- TESTES DE BASES INVÁLIDAS (Deve retornar 0) ---\n");
	printf("Base com sinal (+): %d\n", ft_atoi_base("10", "0123+45"));
	printf("Base com repetidos (11): %d\n", ft_atoi_base("10", "0123445"));
	printf("Base vazia: %d\n", ft_atoi_base("10", ""));
	printf("Base de 1 char: %d\n", ft_atoi_base("10", "0"));

	printf("\n--- TESTES DE LIMITES ---\n");
	printf("Max Int: %d\n", ft_atoi_base("2147483647", "0123456789"));
	printf("Min Int: %d\n", ft_atoi_base("-2147483648", "0123456789"));

	return (0);
}
