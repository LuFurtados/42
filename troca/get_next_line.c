
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

	if (!s || !delimiter || *(delimiter + 1) == '\0')
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
	static char	*leftover;
	char		buffer[BUFFER_SIZE + 1];
	char		*delimiter;
	char		*line;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(leftover);
		return (leftover = NULL);
	}
	bytes_read = 1;
	while (!ft_strchr(leftover, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		buffer[bytes_read] = '\0';
		leftover = ft_append_leftover(leftover, buffer);
	}
	delimiter = ft_strchr(leftover, '\n');
	line = ft_create_line(leftover, delimiter);
	leftover = ft_update_leftover(leftover, delimiter);
	return (line);
}
