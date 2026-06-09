
ft_remove(char c, char *set)
{
    size_t  i;

    i = 0;
    while(set[i])
    {
        if(c == set[i])
            return (1);
        i++;
    }
    return (0);
}

char    *ft_strtrim(char const *s1, char const *set)
{
    size_t  i;
    size_t  i_beg;
    size_t  i_end;
    char    *new_str;

    if (!s1 || !set)
      return (NULL);
    i_beg = 0;
    while (s1[i_beg] != '\0' && (ft_remove(s1[i_beg], set)))
        i_beg++;
    if(s1[i_beg] == '\0')
        return(ft_calloc(1, 1));
    i_end = ft_strlen(s1) - 1;
    while (i_end > i_beg && (ft_remove(s1[i_end], set)))
        i_end--;
    new_str = ft_calloc(1,(i_end - i_beg) + 2);
    if (!new_str)
        return (NULL);
    i = 0;
    ##talvez usar a ft_substr aqui
    ## tem que arrumar a ft_substr, colocando a ft_calloc no lugar da malloc
    while (i_beg <= i_end)
    {
        new_str[i] = s1[i_beg];
        i_beg++;
        i++;
    }
    new_str[i] = '\0';
    return (new_str);
}
