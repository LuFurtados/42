/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danda-si <danda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 13:18:25 by danda-si          #+#    #+#             */
/*   Updated: 2026/06/10 13:27:18 by danda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char		*copy;
	int			i;
	int			dest;

	i = 0;
	dest = 0;
	while (s[dest] != '\0')
	{
		dest++;
	}
	copy = (char *)malloc((dest + 1) * sizeof(char));
	if (!copy)
	{
		return (NULL);
	}
	while (i < dest)
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while ((*s != '\0') && (*s != (char)c))
	{
		s++;
	}
	if (*s == (char)c)
	{
		return ((char *)s);
	}
	return ((char *) NULL);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str_return;
	int		length;
	int		i;
	int		j;

	length = ft_strlen(s1) + ft_strlen(s2) + 1;
	str_return = NULL;
	str_return = malloc(length * sizeof(char));
	if (!str_return)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str_return[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		str_return[i++] = s2[j++];
	str_return[i] = 0;
	return (str_return);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	new_str = malloc(len + 1);
	if (!new_str)
		return (NULL);
	if (!s)
		return (NULL);
	i = start;
	j = 0;
	while (i < ft_strlen(s) && j < len)
		new_str[j++] = s[i++];
	new_str[j] = '\0';
	return (new_str);
}
