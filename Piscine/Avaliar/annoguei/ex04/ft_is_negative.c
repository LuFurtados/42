/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annoguei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 14:35:15 by annoguei          #+#    #+#             */
/*   Updated: 2026/03/05 15:57:52 by annoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n)
{
	char	result;

	if (n < 0)
	{
		result = 'N';
	}
	else
	{
		result = 'P';
	}
	write(1, &result, 1);
}

/*int	main(void)
{
	ft_is_negative(-2);
	ft_is_negative(0);
	ft_is_negative(8);
	return (0);
}*/
