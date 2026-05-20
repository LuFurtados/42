/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfurtado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 15:22:05 by lfurtado          #+#    #+#             */
/*   Updated: 2026/03/11 15:26:27 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	count1;

	count1 = 0;
	while (count1 < n && *src != '\0')
	{
		*dest++ = *src++;
		count1++;
	}
	while (count1 < n)
	{
		*dest++ = '\0';
		count1++;
	}
	return (dest);
}
/*
#include <stdio.h>

int	main(void)
{
	char	origem[8] = "Casebre";
	char	destino[10];

	ft_strncpy(destino, origem, 4);
	printf("Resultado: %s\n", destino);
	return (0);
}
*/
