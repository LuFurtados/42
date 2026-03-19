/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfurtado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 11:15:15 by lfurtado          #+#    #+#             */
/*   Updated: 2026/03/18 11:39:22 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	s_len;

	s_len = 0;
	while (*str)
	{
		s_len++;
		str++;
	}
	return (s_len);
}
/*
#include <stdio.h>

int	main(void)
{
	char	str[] = "casa alta";
	int	ret;

	ret = ft_strlen(str);
	printf("Lenth is:  %i", ret);
}
*/
