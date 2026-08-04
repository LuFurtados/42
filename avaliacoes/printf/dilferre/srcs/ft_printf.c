/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilferre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 12:27:04 by dilferre          #+#    #+#             */
/*   Updated: 2026/06/08 16:03:42 by dilferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(char specifier, va_list args)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count = count + ft_putchar_pf(va_arg(args, int));
	else if (specifier == 's')
		count = count + ft_putstr_pf(va_arg(args, char *));
	else if (specifier == 'p')
		count = count + ft_putptr(va_arg(args, unsigned long));
	else if (specifier == 'd' || specifier == 'i')
		count = count + ft_putnbr(va_arg(args, int));
	else if (specifier == 'u')
		count = count + ft_putunsigned(va_arg(args, unsigned int));
	else if (specifier == 'x' || specifier == 'X')
		count += ft_puthex(va_arg(args, unsigned int), specifier);
	else if (specifier == '%')
		count = count + ft_putchar_pf('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		total_length;

	if (!format)
		return (-1);
	i = 0;
	total_length = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			total_length += ft_check(format[i + 1], args);
			i++;
		}
		else if (format[i] != '%')
		{
			total_length += write(1, &format[i], 1);
		}
		i++;
	}
	va_end(args);
	return (total_length);
}
