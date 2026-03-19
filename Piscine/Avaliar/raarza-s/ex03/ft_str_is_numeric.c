/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raarza-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 18:20:46 by raarza-s          #+#    #+#             */
/*   Updated: 2026/03/19 13:23:46 by raarza-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
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
//	printf("%d\n", ft_str_is_numeric("12345"));
//	printf("%d\n", ft_str_is_numeric("12a45"));
//	printf("%d\n", ft_str_is_numeric(""));
//	return (0);
//}
