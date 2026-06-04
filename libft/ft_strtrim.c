/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfurtado <lfurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 14:39:05 by lfurtado          #+#    #+#             */
/*   Updated: 2026/06/04 16:45:54 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_remove(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	h;

	i = 0;
	j = 0;
	h = 0;
	while (s1[h])
	{
		while (s1[h] == set[i])
			h++;
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i_beg;
	size_t	i_end;
	size_t	size;
	char	*new_str;

	i_beg = 0;
	while (s1[i_beg])
	{
		if (s1[i_beg] == set[i_beg])
			i_beg++;
	}
	i_end = ft_strlen(s1);
	while (s1[i_end])
	{
		if (s1[i_end] == set[i_end])
		i_end--;
	}
	size = i_end - i_beg;
	new_str = calloc(1, size);
	if (!new_str)
		return (NULL);
	return (new_str);
}

