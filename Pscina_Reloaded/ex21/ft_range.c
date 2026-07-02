/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfurtado <lfurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 13:40:11 by lfurtado          #+#    #+#             */
/*   Updated: 2026/05/22 14:06:33 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	size;
	int	*array;

	if (min >= max)
		return (NULL);
	i = 0;
	size = max - min;
	array = malloc(size * (sizeof(int) + 1));
	while (min < max)
	{
		array[i] = min;
		min++;
		i++;
	}
	array[i] = '\0';
	return (array);
}
/*
#include <stdio.h>

int	main(void)
{
	int	min;
	int	max;
	int	*ret;
	int	i;

	min = 5;
	max = 10;
	i = 0;
	ret = ft_range(min, max);
	while (ret[i])
	{
		printf(" %d", ret[i]);
		i++;
	}
	free(ret);
	return (0);
}
*/