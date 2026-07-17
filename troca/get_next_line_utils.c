

## encontra o demilitador de linha
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

## set memoria com 0

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = s;
	i = 0;
	while (i < n)
	{
		ptr[i] = c;
		i++;
	}
	return (s);
}

## Reserva memoria

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			nbytes;
	unsigned char	*ptr;

	if (nmemb == 0 || size == 0)
		nbytes = 1;
	else
	{
		nbytes = nmemb * size;
		if (nbytes / nmemb != size)
			return (NULL);
	}
	ptr = (unsigned char *)malloc(nbytes);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, nbytes);
	return (ptr);
}

# Conta o tamanho da string 

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;
	size_t	i;
	char	*sub_str;

	i = 0;
	len_s = ft_strlen(s);
	if (start > len_s)
		return (ft_calloc(1, sizeof(char)));
	if (len > (len_s - start))
		len = (len_s - start);
	sub_str = ft_calloc(len + 1, sizeof(char));
	if (!sub_str)
		return (NULL);
	while (i < len)
	{
		sub_str[i] = s[start];
		i++;
		start++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}

# Junta as strings
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	total_len;
	char	*new_str;

	if (!s1 || !s2)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	new_str = ft_calloc(total_len, sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		new_str[i] = s2[j];
		i++;
		j++;
	}
	return (new_str);
}
