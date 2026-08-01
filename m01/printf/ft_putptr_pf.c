/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfurtado <lfurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 16:03:15 by lfurtado          #+#    #+#             */
/*   Updated: 2026/07/01 20:34:11 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr_pf(void *ptr)
{
	int				i;
	unsigned long	n;

	n = (unsigned long)ptr;
	i = 0;
	if (n == 0)
	{
		i = i + ft_putstr_pf("(nil)");
		return (i);
	}
	i = ft_putstr_pf("0x");
	i = i + ft_puthex_ptr_pf(n);
	return (i);
}
