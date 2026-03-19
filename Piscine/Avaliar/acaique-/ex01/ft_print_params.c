/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaique- <acaique-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 18:52:12 by acaique-          #+#    #+#             */
/*   Updated: 2026/03/17 18:59:38 by acaique-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_str(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}

void	ft_print_params(int argc, char *argv[])
{
	int	count;

	count = 1;
	while (count < argc)
	{
		put_str(argv[count]);
		count++;
	}
}

int	main(int argc, char *argv[])
{
	ft_print_params(argc, argv);
}
