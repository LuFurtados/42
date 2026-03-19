/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguedes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 17:16:54 by eguedes-          #+#    #+#             */
/*   Updated: 2026/03/10 15:06:33 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

#include <stdio.h>
#include <string.h>

// Protótipo da sua função
int	ft_strlen(char *str);

int	main(void)
{
	char *test1 = "Ola";
	char *test2 = "";
	char *test3 = "Tudo bem com voce?";
	char *test4 = "Espacos   e\ttabs";
	char *test5 = "1234567890";

	printf("--- TESTE 1: String simples ---\n");
	printf("ft: %d | or: %lu\n\n", ft_strlen(test1), strlen(test1));

	printf("--- TESTE 2: String vazia ---\n");
	printf("ft: %d | or: %lu\n\n", ft_strlen(test2), strlen(test2));

	printf("--- TESTE 3: Frase longa ---\n");
	printf("ft: %d | or: %lu\n\n", ft_strlen(test3), strlen(test3));

	printf("--- TESTE 4: Caracteres especiais ---\n");
	printf("ft: %d | or: %lu\n\n", ft_strlen(test4), strlen(test4));

	printf("--- TESTE 5: Numeros ---\n");
	printf("ft: %d | or: %lu\n\n", ft_strlen(test5), strlen(test5));

	return (0);
}
