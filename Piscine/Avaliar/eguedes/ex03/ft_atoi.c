/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguedes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 07:38:25 by eguedes-          #+#    #+#             */
/*   Updated: 2026/03/10 15:35:36 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_atoi(char *str);

int	special_char(char *str, int *i);

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

int	ft_atoi(char *str)
{
	int	i;
	int	signal;
	int	result;

	i = 0;
	result = 0;
	signal = special_char(str, &i);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i = i + 1;
	}
	return (result * signal);
}

#include <stdio.h>
#include <stdlib.h>

void	run_test(char *str)
{
	int res_ft = ft_atoi(str);
	int res_orig = atoi(str);

	printf("Input: [%s]\n", str);
	printf("ft_atoi: %d | atoi: %d\n", res_ft, res_orig);
	if (res_ft == res_orig)
		printf("✅ OK\n");
	else
		printf("❌ FAIL\n");
	printf("----------------------------\n");
}

int	main(void)
{
	// 1. Número simples
	run_test("42");

	// 2. Espaços e White-spaces (deve pular)
	run_test("   \t\n\v\f\r  123");

	// 3. Sinais (na 42, muitas vezes pede-se tratar vários sinais,
	// mas a atoi original só trata UM sinal. Verifique seu PDF!)
	run_test("-456");
	run_test("+789");

	// 4. Número com lixo depois
	run_test("1234abc56");

	// 5. Nada além de espaços ou sinais
	run_test("   +");
	run_test("   --");

	// 6. Max e Min Int
	run_test("2147483647");
	run_test("-2147483648");

	// 7. Começando com letras (deve retornar 0)
	run_test("hello 42");

	return (0);
}
