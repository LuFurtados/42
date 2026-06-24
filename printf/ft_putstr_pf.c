

#include "ft_printf.h"

int ft_putstr_pf(char *s)
{
	int	i;

	if (!s)
    {
        write(1, "(null)", 6);
        return (6);
    }
	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar_pf(s[i]);
		i++;
	}
    return (i);
}
