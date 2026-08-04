/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobezerr <jobezerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 10:48:59 by victor            #+#    #+#             */
/*   Updated: 2026/07/14 11:51:02 by jobezerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnx(unsigned int x, char *base, int size_base)
{
	unsigned int	count;
	int				aux;
	int				total;

	count = x;
	aux = 0;
	total = 0;
	if (count >= (unsigned int)size_base)
	{
		aux = ft_putnx(count / size_base, base, size_base);
		if (aux == -1)
			return (aux);
		total += aux;
	}
	aux = ft_putchar(base[count % size_base]);
	if (aux == -1)
		return (aux);
	total += aux;
	return (total);
}

int	ft_putnbr(int numb, char *base, int size_base)
{
	long	j;
	int		total;
	int		aux;

	total = 0;
	aux = 0;
	j = numb;
	if (numb < 0)
	{
		aux = ft_putchar('-');
		if (aux == -1)
			return (aux);
		total += aux;
		j *= -1;
	}
	aux = ft_putnx(j, base, size_base);
	if (aux == -1)
		return (aux);
	total += aux;
	return (total);
}

int	ft_putvoid(void *ptr)
{
	unsigned long	conv;
	int				aux;
	int				total;

	if (ptr == NULL)
		return (write(1, "(nil)", 5));
	aux = 0;
	total = 0;
	conv = (unsigned long)ptr;
	aux = write(1, "0x", 2);
	if (aux == -1)
		return (aux);
	total += aux;
	aux = ft_put_ptr(conv, "0123456789abcdef", 16);
	if (aux == -1)
		return (aux);
	total += aux;
	return (total);
}

int	ft_put_ptr(unsigned long numb, char *base, int size_base)
{
	unsigned long	count;
	int				aux;
	int				total;

	aux = 0;
	total = 0;
	count = numb;
	if (count >= (unsigned long)size_base)
	{
		aux = ft_put_ptr(count / size_base, base, size_base);
		if (aux == -1)
			return (aux);
		total += aux;
	}
	aux = ft_putchar(base[count % size_base]);
	if (aux == -1)
		return (aux);
	total += aux;
	return (total);
}
