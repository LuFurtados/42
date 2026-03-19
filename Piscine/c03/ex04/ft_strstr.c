/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfurtado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 19:43:10 by lfurtado          #+#    #+#             */
/*   Updated: 2026/03/18 17:06:09 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char	*s;
	char	*f;

	if (*to_find == '\0')
		return (str);
	while (*str != '\0')
	{
		if (*str == *to_find)
		{
			s = str;
			f = to_find;
			while (*s != '\0' && *f != '\0' && *s == *f)
			{
				s++;
				f++;
			}
			if (*f == '\0')
				return (str);
		}
		str++;
	}
	return (0);
}

#include <stdio.h>

int	main(void)
{
	char	texto[] = "+-1";
	char	busca[] = "+-1";
	char	*resultado = ft_strstr(texto, busca);

	printf("Palavra encontrada!\n");
	printf("A partir da busca, o texto e: [%s]\n", resultado);
}
