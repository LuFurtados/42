/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilferre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 11:14:32 by dilferre          #+#    #+#             */
/*   Updated: 2026/06/08 16:11:57 by dilferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_check(char specifier, va_list args);
int	ft_putchar_pf(char c);
int	ft_putstr_pf(char *s);
int	ft_putptr(unsigned long ptr);
int	ft_putnbr(int n);
int	ft_putunsigned(unsigned int n);
int	ft_puthex(unsigned int n, char specifier);
int	ft_puthex_long(unsigned long n);

#endif
