/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfurtado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 18:14:38 by lfurtado          #+#    #+#             */
/*   Updated: 2026/03/17 18:36:03 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*ptr;

	ptr = dest;
	while (*ptr != '\0')
		ptr++;
	while (nb > 0 && *src != '\0')
	{
		*ptr = *src;
		ptr++;
		src++;
		nb--;
	}
	*ptr = '\0';
	return (dest);
}
/*
#include <stdio.h>

int	main(void)
{
	char	go_to[50] = "Linguagem ";
	char	go_cmp[] = "C e incrivel!";
	int	n = 15;

	ft_strncat(go_to, go_cmp, n);
	printf("%s\n", go_to);
	return (0);
}
*/
