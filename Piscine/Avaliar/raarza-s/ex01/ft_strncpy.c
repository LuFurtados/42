/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfurtado <lfurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 18:13:40 by raarza-s          #+#    #+#             */
/*   Updated: 2026/03/19 17:57:22 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i != n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

#include <unistd.h>

int	main(void)
{
	char	origem[] = "Ola";
	char	destino[10];

	ft_strncpy(destino, origem, 5);

	printf("Resultado: %s\n", destino);
	return (0);
}
