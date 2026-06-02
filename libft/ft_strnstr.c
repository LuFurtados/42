
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
    size_t  h;
    size_t  n;

    n = 0;
    h = 0;
    if (needle[n] == '\0')
        return ((char *)haystack);
    while (h < len && haystack[h])
    {
        n = 0;
        while (haystack[h + n] == needle[n] && (h + n) < len)
        {
            if (needle[n + 1] == '\0')
                return ((char *)&haystack[h]);
            n++;                
        }
        h++;
    }
    return (NULL);
}