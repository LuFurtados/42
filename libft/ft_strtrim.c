/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfurtado <lfurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 14:39:05 by lfurtado          #+#    #+#             */
/*   Updated: 2026/06/10 18:52:44 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_remove(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i_beg;
	size_t	i_end;
	char	*new_str;

	if (!s1 || !set)
		return (NULL);
	i_beg = 0;
	while (s1[i_beg] != '\0' && (ft_remove(s1[i_beg], set)))
		i_beg++;
	if (s1[i_beg] == '\0')
		return (ft_calloc(1, sizeof(char)));
	i_end = ft_strlen(s1) - 1;
	while (i_end > i_beg && (ft_remove(s1[i_end], set)))
		i_end--;
	new_str = ft_substr(s1, i_beg, (i_end - i_beg) + 1);
	return (new_str);
}
