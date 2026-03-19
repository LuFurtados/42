/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raarza-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 20:16:24 by raarza-s          #+#    #+#             */
/*   Updated: 2026/03/17 22:10:33 by raarza-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 32 && str[i] <= 126))
			return (0);
		i++;
	}
	return (1);
}
//
//#include <stdio.h>
//
//int	main(void)
//{
//	printf("Teste com \"Hello\" -> %d\n", ft_str_is_printable("Hello"));
//	printf("Teste com \"Oi\\n\" -> %d\n", ft_str_is_printable("Oi\n"));
//	printf("Teste com string vazia \"\" -> %d\n", ft_str_is_printable(""));
//	printf("Teste com \"123!\" -> %d\n", ft_str_is_printable("123!"));
//	return (0);
//}
