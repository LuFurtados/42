
int ft_count(long n)
{
    int i;

    i = 0;
    if (n < 0)
    {
        n = n * - 1;
        i++;
    }
    while (n > 0)
    {
        n = n / 10;
        i++;
    }
    return (i);
}



char *ft_itoa(int n)
{
    int i;
    int is_neg;
    long n_new;
    char *str;

    i = 0;
    is_neg = 0;
    n_new = n;
    if (n == 0)
    {
        str = ft_calloc(1, 2);
        if (!str)
            return (NULL);
        str[i] = '0';
        str[1] = '\0';
        return (str);
    }
    else
    {
        i = ft_count(n_new);
        str = ft_calloc(1, i + 1);
        if (!str)
            return (NULL);
        if (n_new < 0)
        {
            n_new = n_new * - 1;
            is_neg = 1;
        }
        str[i] = '\0';
        i--;
        while (n_new > 0)
        {
            str[i] = (n_new % 10) + '0';
            n_new = n_new / 10;
            i--;
        }
        if (is_neg == 1)
            str[i] = '-';
    }
    return (str);
}
