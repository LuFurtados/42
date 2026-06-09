
void	ft_free(char **str_free, size_t n_block)
{
	size_t	i;

	i = 0;
	while (i < n_block)
	{
		free(str_free[i]);
		i++;
	}
	free(str_free);
}

int ft_count_blocks(char const *str, char c)
{
    size_t  i;
    size_t  i_words;
    size_t  is_word;

    i = 0;
    is_word = 0;
    i_words = 0;
    while (str[i] != '\0')
    {
        if (str[i] != c && is_word == 0)
        {
            i_words++;
            is_word = 1;
        }
        if (str[i] == c)
            is_word = 0;
        i++;
    }
    return (i_words);
}


char **ft_split(char const *s, char c)
{
    size_t  i;
    size_t  j;
    size_t  start;
    size_t  n_words;
    char    **str_split;

    if (!s)
        return (NULL);
    n_words = ft_count_blocks(s, c);
    str_split = ft_calloc(n_words + 1, sizeof(char *));
    if(!str_split)
        return (NULL);
    i = 0;
    j = 0;
    while (j < n_words)
    {
        while (s[i] == c)
            i++;
        start = i;
        while (s[i] != '\0' && s[i] != c)
            i++;
        str_split[j] = ft_substr(s,start, i - start);
        if (!str_split[j])
        {
            ft_free(str_split, j);
            return (NULL);
        }
        j++;
    }
    return (str_split);
}