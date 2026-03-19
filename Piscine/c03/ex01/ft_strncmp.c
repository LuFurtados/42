/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfurtado <lfurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 16:04:51 by lfurtado          #+#    #+#             */
/*   Updated: 2026/03/17 18:30:03 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	while (n > 0 && *s1 == *s2 && *s1 != '\0')
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
/*
#include <stdio.h>

int	main(void)
{
	char	p1[] = "3215001";
	char	p2[] = "3215134";
	int	n = 4;
	int	resultado = ft_strncmp(p1, p2, n);

	printf("Resultado: %d\n", resultado);
	if (resultado == 0)
		printf("As '%i' primeiras posicoes sao Iguais!\n", n);
	else
		printf("Diferente nas '%i' primeira posicoes", n);
	return (0);
}
*/
