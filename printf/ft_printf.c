
#include "ft_printf.h"

int ft_printf(const char *restrict format, ...)
{
    int i;
    int count_total;
    va_list args;

    va_start(args, format);
    i = 0;
    count_total = 0;
    while (format[i] != '\0')
    {   
        if(format[i] != '%')
        {
            count_total += ft_putchar_pf(format[i]);
            i++;
        }
        else
        {
            if (format[i+1] == '\0')
                break ();  
            count_total += ft_conversion_pf(args, format[i+1]);
            i = i + 2;
        }
    }
    va_end (args);
    return (count_total);
}
