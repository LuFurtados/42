/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaique- <acaique-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 18:43:58 by acaique-          #+#    #+#             */
/*   Updated: 2026/03/17 18:59:35 by acaique-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	char	*argv_str;
	int		count_argc;

	count_argc = argc;
	argv_str = argv[0];
	while (*argv_str)
	{
		write(1, argv_str, 1);
		argv_str++;
	}
	write(1, "\n", 1);
}
