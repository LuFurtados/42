/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobezerr <jobezerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 22:30:15 by victor            #+#    #+#             */
/*   Updated: 2026/07/14 11:41:57 by jobezerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	if (write(1, &c, 1) == 1)
		return (1);
	return (-1);
}

int	ft_putstr(char *ptr)
{
	int	i;
	int	total;

	if (!ptr)
	{
		if (write(1, "(null)", 6) == 6)
			return (6);
		return (-1);
	}
	i = 0;
	total = 0;
	while (ptr[i])
	{
		if (ft_putchar(ptr[i]) == -1)
			return (-1);
		total ++;
		i++;
	}
	return (total);
}
