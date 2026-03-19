/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguedes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 17:30:04 by eguedes-          #+#    #+#             */
/*   Updated: 2026/03/10 15:09:43 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putstr(char *str);

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

int	main(void)
{
	// Teste 1: String padrão
	write(1, "Teste 1: ", 9);
	ft_putstr("Ola 42!");
	write(1, "\n", 1);

	// Teste 2: String vazia (Não deve imprimir nada, nem quebrar)
	write(1, "Teste 2: ", 9);
	ft_putstr("");
	write(1, "(vazio)\n", 8);

	// Teste 3: String com espaços e tabs
	write(1, "Teste 3: ", 9);
	ft_putstr("Texto com\ttab e   espacos");
	write(1, "\n", 1);

	return (0);
}
