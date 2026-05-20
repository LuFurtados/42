/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfurtado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 20:38:10 by lfurtado          #+#    #+#             */
/*   Updated: 2026/03/11 15:15:24 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char	*dest, char *src)
{
	int	count;

	count = 0;
	while (src[count] != '\0')
	{
		dest[count] = src[count];
		count++;
	}
	dest[count] = '\0';
	return (dest);
}
/*
#include <stdio.h>

int	main(void)
{
	char	dest[10];
	char	src[] = "Hello";

	ft_strcpy(dest, src);
	printf("%s", dest);
	return (0);
}
*/
