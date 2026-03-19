/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raarza-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 20:03:08 by raarza-s          #+#    #+#             */
/*   Updated: 2026/03/17 22:06:39 by raarza-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 'A' && str[i] <= 'Z'))
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
//	printf("%d\n", ft_str_is_uppercase("ABC"));
//	printf("%d\n", ft_str_is_uppercase("AbC"));
//	printf("%d\n", ft_str_is_uppercase("123"));
//	printf("%d\n", ft_str_is_uppercase(""));
//	printf("%d\n", ft_str_is_uppercase("XYZ!"));
//	return (0);
//}
