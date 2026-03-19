/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raarza-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 17:44:41 by raarza-s          #+#    #+#             */
/*   Updated: 2026/03/19 15:42:42 by raarza-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!((str[i] >= 'a' && str[i] <= 'z')
			|| (str[i] >= 'A' && str[i] <= 'Z')))
			return (0);
		i++;
	}
	return (1);
}
//
//# include <stdio.h>
//
//int	main(void)
//{
//	printf("%d\n", ft_str_is_alpha("Hello"));
//	printf("%d\n", ft_str_is_alpha("Hello123"));
//	printf("%d\n", ft_str_is_alpha(""));
//	return 0;
//}
