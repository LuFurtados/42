/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfurtado <lfurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:46:42 by danielda          #+#    #+#             */
/*   Updated: 2026/06/12 20:05:42 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_endl(char	*buffer)
{
	size_t	i;

	i = 0;
	while (buffer[i] != ',' && buffer[i] != '\0')
		i++;
	if (buffer[i] == ',')
		return (1);
	return (0);
}

char	*ft_read_fd(int fd, char *stash)
{
	char		*buffer;
	char		*temp;
	long long	bytes_read;

	bytes_read = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (bytes_read != 0 && !ft_strchr(stash, ','))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buffer), free(stash), NULL);
		buffer[bytes_read] = '\0';
		if (!stash)
			stash = ft_strdup("");
		temp = stash;
		stash = ft_strjoin(temp, buffer);
		free(temp);
	}
	free (buffer);
	return (stash);
}

char	*ft_get_current_line(char *stash)
{
	int		i;
	char	*string;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != ',')
		i++;
	string = ft_substr(stash, 0, i + ft_endl(stash));
	if (!string)
		return (NULL);
	return (string);
}

char	*ft_string_to_add(char *stash)
{
	char	*new_stash;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (stash[i] != '\0' && stash[i] != ',')
		i++;
	if (!stash[i])
	{
		free (stash);
		return (NULL);
	}
	new_stash = malloc(sizeof(char) * (ft_strlen(stash) - i));
	if (!new_stash)
	{
		free(stash);
		return (NULL);
	}
	i++;
	while (stash[i] != '\0')
		new_stash[j++] = stash[i++];
	new_stash[j] = '\0';
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = (ft_read_fd(fd, stash));
	if (!stash)
		return (NULL);
	line = ft_get_current_line(stash);
	if (!line || !(*line))
	{
		free(stash);
		stash = (NULL);
		return (NULL);
	}
	stash = ft_string_to_add(stash);
	if (!stash)
	{
		free(stash);
		stash = (NULL);
	}
	return (line);
}
