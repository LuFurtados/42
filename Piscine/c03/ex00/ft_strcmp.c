/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfurtado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 16:04:51 by lfurtado          #+#    #+#             */
/*   Updated: 2026/03/11 16:53:01 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 != '\0')
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
/*
#include <stdio.h>

int	main(void)
{
	char	p1[] = "Abacate";
	char	p2[] = "Abacate";
	int	resultado = ft_strcmp(p1, p2);

	printf("Resultado: %d\n", resultado);
	if (resultado == 0)
		printf("Iguais!\n");
	else if (resultado < 0)
		printf("'%s' vem antes de '%s'\n", p1, p2);
	else
		printf("'%s' vem depois de '%s'\n", p1, p2);
	return (0);
}
*/
