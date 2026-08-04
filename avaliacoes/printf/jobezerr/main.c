
#include "ft_printf.h"

int	main(void)
{
	int	n;

	n = 42;
	ft_printf("Valor: %d\n", 42);
	ft_printf("Valor: %c\n", 'A');
	ft_printf("Valor: %s\n", "42 Mundo");
	ft_printf("Valor: %p\n", n);
	ft_printf("Valor: %i\n", 42);
	ft_printf("Valor: %x\n", 42);
	ft_printf("Valor: %X\n", 42);
	ft_printf("Valor: %%\n", 42);
}
