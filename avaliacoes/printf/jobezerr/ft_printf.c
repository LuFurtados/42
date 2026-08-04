/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfurtado <lfurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 15:21:02 by jobezerr          #+#    #+#             */
/*   Updated: 2026/07/14 19:09:13 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_manager(char conversion, va_list args)
{
	if (conversion == 'i' || conversion == 'd')
		return (ft_putnbr(va_arg(args, int), "0123456789", 10));
	else if (conversion == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (conversion == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (conversion == 'u')
		return (ft_putnx(va_arg(args, unsigned int), "0123456789", 10));
	else if (conversion == 'x')
		return (ft_putnx(va_arg(args, unsigned int), "0123456789abcdef", 16));
	else if (conversion == 'X')
		return (ft_putnx(va_arg(args, unsigned int), "0123456789ABCDEF", 16));
	else if (conversion == 'p')
		return (ft_putvoid(va_arg(args, void *)));
	else
		return (0);
}

int	ft_aux_printf(const char *format, va_list args)
{
	int	total;
	int	i;
	int	aux;

	i = 0;
	total = 0;
	aux = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[++i] != '%')
				aux = ft_manager(format[i++], args);
			else
				aux = ft_putchar(format[i++]);
		}
		else
			aux = ft_putchar(format[i++]);
		if (aux == -1)
			return (-1);
		total += aux;
	}
	return (total);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		total;

	total = 0;
	va_start(args, format);
	total = ft_aux_printf(format, args);
	va_end(args);
	return (total);
}

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

