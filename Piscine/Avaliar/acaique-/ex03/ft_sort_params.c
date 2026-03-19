/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaique- <acaique-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 18:52:12 by acaique-          #+#    #+#             */
/*   Updated: 2026/03/17 19:15:12 by acaique-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char *argv[])
{
	int	count_a;
	int	count_b;

	count_a = 1;
	while (argv[count_a] != 0)
	{
		count_b = 0;
		while (argv[count_a][count_b] != 0)
		{
			write (1, &argv[count_a][count_b], 1);
			count_b++;
		}
		write (1, "\n", 1);
		count_a++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	count;

	count = 0;
	if (s1[count] != '\0' && s2[count] != '\0')
	{
		while (s1[count] && s2[count])
		{
			if (s1[count] != s2[count])
				return (s1[count] - s2[count]);
			count++;
		}
	}
	return ((s1[count] - s2[count]));
}

void	ft_sort_params(int argc, char *argv[])
{
	int		count_a;
	int		count_b;
	char	*temp;

	count_a = 0;
	count_b = 1;
	while (count_a < argc - 1)
	{
		count_b = 1;
		while (count_b < argc - 1 - count_a)
		{		
			if (ft_strcmp(argv[count_b], argv[count_b + 1]) > 0)
			{
				temp = argv[count_b];
				argv[count_b] = argv[count_b + 1];
				argv[count_b + 1] = temp;
			}
			count_b++;
		}
		count_a++;
	}
}

int	main(int argc, char *argv[])
{
	ft_sort_params(argc, argv);
	ft_putchar(argv);
}
