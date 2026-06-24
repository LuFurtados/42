

#include "ft_printf.h"

int ft_putptr_pf(void *ptr)
{
    int i;
    uintptr_t n;

    n = (uintptr_t)ptr;
    i = 0;
    i = ft_putstr_pf("0x");
    i = i + ft_puthex_ptr_pf(n);
    return (i);
}

verificar o qu isso imprime e fazer igual na função:
printf("%p\n", NULL);
