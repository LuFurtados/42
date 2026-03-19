/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfurtado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 18:14:38 by lfurtado          #+#    #+#             */
/*   Updated: 2026/03/17 15:36:05 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count(char *str)
{
	char	*s;
	int		len;

	s = str;
	len = 0;
	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	d_len;
	unsigned int	s_len;

	i = 0;
	d_len = ft_count(dest);
	if (d_len > size)
		d_len = size - 1;
	s_len = ft_count(src);
	if (d_len >= size)
		return (size + s_len);
	while (*src != '\0' && (d_len + i) < size)
	{
		dest[d_len + i] = src [i];
		i++;
	}
	if (d_len < size)
		dest[d_len + i] = '\0';
	return (d_len + s_len);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	go_to[30] = "Linguagem ";
	char	go_cmp[] = "C e incrivel!";
	int	n = 10;
	int	ret;

	ret = (ft_strlcat(go_to, go_cmp, n));
	printf("Z_Resultado go_to: %s\n", go_to);
	printf("Z_Retorno go_cmp: %s\n", go_cmp);
	printf("Z_Retorno: %d\n", ret);
	return (0);
}
*/
