/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annoguei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 13:10:16 by annoguei          #+#    #+#             */
/*   Updated: 2026/03/05 16:22:40 by annoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	char	numbers;

	numbers = '0';
	while (numbers <= '9')
	{
		write(1, &numbers, 1);
		numbers++;
	}
}
/*int	main(void)
	{
	ft_print_numbers();
	return (0);
	}*/
