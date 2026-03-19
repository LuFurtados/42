/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raarza-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 16:23:32 by raarza-s          #+#    #+#             */
/*   Updated: 2026/03/19 13:22:10 by raarza-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
//#include <stdio.h>
//
//int	main(void)
//{
//	char src[] = "Olá, Mundo!";
//	char dest[50];
//
//	ft_strcpy(dest, src);
//	printf("src: %s\n", src);
//	printf("dest: %s\n", dest);
//	return (0);
//}
