/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raarza-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 18:37:29 by raarza-s          #+#    #+#             */
/*   Updated: 2026/03/19 13:21:33 by raarza-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 'a' && str[i] <= 'z'))
			return (0);
		i++;
	}
	return (1);
}
//#include <stdio.h>
//
//int	main(void)
//{
//	printf("%d\n", ft_str_is_lowercase("abc"));
//	printf("%d\n", ft_str_is_lowercase("Abc"));
//	printf("%d\n", ft_str_is_lowercase("abc123"));
//	printf("%d\n", ft_str_is_lowercase(""));
//	return 0;
//}	
