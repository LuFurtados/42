/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_overflow.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfurtado <lfurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 16:12:05 by lfurtado          #+#    #+#             */
/*   Updated: 2026/07/27 16:13:10 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_overflow(char *str)
{
	long	limit;
	long	number;
	int		i;

	limit = 2147483647;
	i = 0;
	number = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			limit = 2147483648;
		i++;
	}
	while (str[i] != '\0')
	{
		number = (number * 10) + (str[i] - '0');
		if (number > limit)
			return (0);
		i++;
	}
	return (1);
}
