

#include "ft_printf.h"

int ft_putnbr(int n)
{
	long	number;
    int     i;

	number = n;
	if (number == 0)
		return (ft_putchar_pf('0'));
    i = 0;
	if (number < 0)
	{
		ft_putchar_pf('-');
		number = -number;
        i++;
	}
	if (number >= 10)
		ft_putnbr_pf(number / 10);
	i = i + (ft_putchar_pf((number % 10) + '0'));
    return (i);
}
