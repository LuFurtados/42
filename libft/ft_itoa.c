/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfurtado <lfurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 15:39:41 by lfurtado          #+#    #+#             */
/*   Updated: 2026/06/09 20:38:37 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*ft_is_zero(long n)
{
	char	*str;

	str = ft_calloc(1, 2);
	if (!str)
		return (NULL);
	str[n] = '0';
	str[1] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	int		i;
	long	n_new;
	char	*str;

	n_new = n;
	if (n_new == 0)
		return (ft_is_zero(n_new));
	i = ft_count(n_new);
	str = ft_calloc(1, i + 1);
	if (!str)
		return (NULL);
	if (n_new < 0)
	{
		str[0] = '-';
		n_new = n_new * -1;
	}
	str[i] = '\0';
	i--;
	while (n_new > 0)
	{
		str[i] = (n_new % 10) + '0';
		n_new = n_new / 10;
		i--;
	}
	return (str);
}
