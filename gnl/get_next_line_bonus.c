/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfurtado <lfurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 19:17:45 by lfurtado          #+#    #+#             */
/*   Updated: 2026/07/23 19:46:40 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_line(int fd, char *leftover, int delimiter)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			free(leftover);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		leftover = ft_append_leftover(leftover, buffer);
		if (!leftover || ft_strchr(buffer, delimiter) || bytes_read == 0)
			break ;
	}
	free(buffer);
	return (leftover);
}

char	*ft_create_line(const char *s, const char *delimiter)
{
	size_t	line_len;

	if (!s || *s == '\0')
		return (NULL);
	if (!delimiter)
		return (ft_substr(s, 0, ft_strlen(s)));
	line_len = (delimiter - s) + 1;
	return (ft_substr(s, 0, line_len));
}

char	*ft_update_leftover(char *s, const char *delimiter)
{
	size_t	start;
	char	*new_leftover;

	if (!s)
		return (NULL);
	if (!delimiter || *(delimiter + 1) == '\0')
	{
		free(s);
		return (NULL);
	}
	start = (delimiter - s) + 1;
	new_leftover = ft_substr(s, start, ft_strlen(s) - start);
	free(s);
	return (new_leftover);
}

char	*ft_append_leftover(char *leftover, char *buffer)
{
	char	*new_leftover;

	new_leftover = ft_strjoin(leftover, buffer);
	free(leftover);
	return (new_leftover);
}

char	*get_next_line(int fd)
{
	static char	*leftover[1024];
	char		*delimiter;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (fd < 0 || fd >= 1024)
		return (NULL);
	delimiter = ft_strchr(leftover[fd], '\n');
	if (!delimiter)
	{
		leftover[fd] = ft_read_line(fd, leftover[fd], '\n');
		if (!leftover[fd])
			return (NULL);
		delimiter = ft_strchr(leftover[fd], '\n');
	}
	line = ft_create_line(leftover[fd], delimiter);
	leftover[fd] = ft_update_leftover(leftover[fd], delimiter);
	return (line);
}
