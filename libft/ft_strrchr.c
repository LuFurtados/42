/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfurtado <lfurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 16:09:56 by lfurtado          #+#    #+#             */
/*   Updated: 2026/06/02 16:24:53 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*ptr;
	int			i;

	ptr = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			ptr = &s[i];
		i++;
	}
	if (s[i] == (char)c)
		ptr = &s[i];
	return ((char *)ptr);
}
