
char *ft_strrchr(const char *s, int c)
{
    const char *ptr;
    int i;

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