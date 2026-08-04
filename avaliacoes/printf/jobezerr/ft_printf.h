/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfurtado <lfurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 11:42:51 by jobezerr          #+#    #+#             */
/*   Updated: 2026/07/14 18:53:09 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINT_H

# include <stdarg.h>
# include <unistd.h>

int	ft_putchar(int c);
int	ft_putstr(char *ptr);
int	ft_putnx(unsigned int x, char *base, int size_base);
int	ft_putnbr(int numb, char *base, int size_base);
int	ft_putvoid(void *ptr);
int	ft_put_ptr(unsigned long numb, char *base, int size_base);
int	ft_manager(char conversion, va_list args);
int	ft_aux_printf(const char *format, va_list args);
int	ft_printf(const char *format, ...);

#endif