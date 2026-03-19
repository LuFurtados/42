/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raarza-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 21:30:44 by raarza-s          #+#    #+#             */
/*   Updated: 2026/03/19 13:25:43 by raarza-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}
//
//#include <unistd.h>
//
//int	main(void)
//{
//	char str[] = "CHICUNGUNHA";
//
//	ft_strlowcase(str);
//	
//	write(1, str, 9);
//	write(1, "\n", 1);
//	return (0);
//}
