/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfurtado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 14:08:52 by lfurtado          #+#    #+#             */
/*   Updated: 2026/03/18 18:48:26 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	now;
	int	signal;
	int	nbr_int;

	now = 0;
	signal = 1;
	nbr_int = 0;
	while ((str[now] >= 9 && str[now] <= 13) || (str[now] == 32))
		now++;
	while (str[now] == '-' || str[now] == '+')
	{
		if (str[now] == '-')
			signal = -signal;
		now++;
	}
	while (str[now] >= '0' && str[now] <= '9')
	{
		nbr_int = (nbr_int * 10) + (str[now] - '0' );
		now++;
	}
	return (nbr_int * signal);
}
/*
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int		ret;
	char	*str;

	ret = argc;
	str = argv[1];
	ret = ft_atoi(str);
	printf("Apos atoi: %i", ret);
	return (0);
}
*/
