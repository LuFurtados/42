/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carocha- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 02:55:03 by carocha-          #+#    #+#             */
/*   Updated: 2026/03/01 06:10:31 by carocha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str);

int	ft_strlen(char *str)
{
	int	result;

	result = 0;
	if (str)
	{
		while (*str)
		{
			str++;
			result++;
		}
		return (result);
	}
	return (0);
}
