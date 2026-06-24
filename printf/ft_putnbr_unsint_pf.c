

#include "ft_printf.h"

int ft_putnbr_unsint(unsigned int n)
{
	int     i;

	if (n == 0)
		return (ft_putchar_pf(0));
    i = 0;
	if (n >= 10)
	    ft_putnbr_pf(n / 10);
	i = i + (ft_putchar_pf((n % 10) + '0'));
    return (i);
}
