/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfurtado <lfurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 18:14:38 by lfurtado          #+#    #+#             */
/*   Updated: 2026/03/17 18:39:02 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	char	*ptr;

	ptr = dest;
	while (*ptr != '\0')
		ptr++;
	while (*src != '\0')
	{
		*ptr = *src;
		ptr++;
		src++;
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
	char	*ret;

	ret = ft_strcat(go_to, go_cmp);
	printf("Retorno: %s\n", ret);
	return (0);
}
*/
