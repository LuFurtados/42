/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaomi-i <inaomi-i@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 19:04:59 by lfurtado          #+#    #+#             */
/*   Updated: 2026/03/01 21:11:35 by inaomi-i         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	line;
	int	col;

	if (x <= 0 || y <= 0)
		return ;
	col = 0;
	while (col++ < y)
	{
		line = 0;
		while (line++ < x)
		{
			if ((col == 1 && line == 1) || (col == 1 && line == x) || (col == y
					&& line == 1) || (col == y && line == x))
				ft_putchar('o');
			else if ((col > 1 && line == 1) || (line == x && col > 1))
				ft_putchar('|');
			else if ((line > 1 && col == 1) || (line > 1 && col == y))
				ft_putchar('-');
			else
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}
