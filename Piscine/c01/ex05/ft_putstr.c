/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfurtado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 18:05:35 by lfurtado          #+#    #+#             */
/*   Updated: 2026/03/04 19:12:16 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char	*str);

void	ft_putstr(char	*str)
{
	write(1, str, 20);
}
/*
int	main(void)
{
	char	str[20] = "California";

	ft_putstr(&str);
}
*/
