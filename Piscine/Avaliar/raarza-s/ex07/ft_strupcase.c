/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfurtado <lfurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 21:22:03 by raarza-s          #+#    #+#             */
/*   Updated: 2026/03/19 18:02:44 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] += 32;
		i++;
	}
	return (str);
}
//
//#include <unist.h>
//
//int	main(void)
//{
//	char	str[] = "ola mundo";
//
//	ft_strupcase(str);
//	write(1, str, 9);
//	write(1, "\n", 1);
//
//	return (0);
//}
