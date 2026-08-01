/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfurtado <lfurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 15:51:11 by lfurtado          #+#    #+#             */
/*   Updated: 2026/07/01 20:36:26 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_conversion_pf(va_list args, char c);
int	ft_putchar_pf(int c);
int	ft_puthex_pf(unsigned int n, char t);
int	ft_puthex_ptr_pf(unsigned long n);
int	ft_putnbr_pf(int n);
int	ft_putnbr_unsint_pf(unsigned int n);
int	ft_putptr_pf(void *ptr);
int	ft_putstr_pf(char *s);

#endif