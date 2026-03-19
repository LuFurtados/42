/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucoelho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 08:28:07 by gucoelho          #+#    #+#             */
/*   Updated: 2026/03/08 11:36:37 by gucoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str);
void	init_table(int table[4][4]);
void	print_table(int table[4][4]);

// put string to stdout
void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	write(1, str, i);
}

void	init_table(int table[4][4])
{
	int	line;
	int	col;

	line = 0;
	while (line < 4)
	{
		col = 0;
		while (col < 4)
		{
			table[line][col] = 0;
			col++;
		}
		line++;
	}
}

void	print_table(int table[4][4])
{
	int		line;
	int		col;
	char	value;

	line = 0;
	while (line < 4)
	{
		col = 0;
		while (col < 4)
		{
			value = table[line][col] + '0';
			write(1, &value, 1);
			if (col < 3)
				write(1, " ", 1);
			col++;
		}
		write(1, "\n", 1);
		line++;
	}
}
