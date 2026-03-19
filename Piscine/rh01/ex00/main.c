/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucoelho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 18:02:45 by gucoelho          #+#    #+#             */
/*   Updated: 2026/03/08 17:02:28 by gucoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str);
int		populate_clues(char	*input, int clues[4][4]);
void	init_table(int table[4][4]);
int		solve(int table[4][4], int clues[4][4], int n);
void	print_table(int table[4][4]);

int	main(int argc, char *argv[])
{
	int	table[4][4];
	int	clues[4][4];

	if (argc != 2)
	{
		ft_putstr("Error\n");
		return (1);
	}
	if (populate_clues(argv[1], clues) != 16)
	{
		ft_putstr("Error\n");
		return (1);
	}
	init_table(table);
	if (solve(table, clues, 0))
		print_table(table);
	else
		ft_putstr("Error\n");
	return (0);
}

//	preenche a matrix clues com as pistas recebidas pela linha de comando
//		linha 0 de clues contem as pistas do topo
//		linha 1 de clues contem as pistas de baixo 
//		linha 2 de clues contem as pistas da esquerda 
//		linha 3 de clues contem as pistas da direita 
// retorna o número de pistas para validação do input:
// para um quebra-cabeça 4x4, deve retornar 16

int	populate_clues(char	*input, int clues[4][4])
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (*input)
	{
		if (*input >= '1' && *input <= '4')
		{
			clues[i / 4][i % 4] = *input - '0';
			i++;
		}
		else if (*input == ' ')
			count++;
		input++;
	}
	if (count == 15 && i == 16)
		return (i);
	else
		return (0);
}

// verifica se o valor value já está presente na linha line
int	in_line(int table[4][4], int line, int value)
{
	int	col;

	col = 0;
	while (col < 4)
	{
		if (table[line][col] == value)
			return (1);
		col++;
	}
	return (0);
}

// verifica se um certo valor value já está presente na coluna col 
int	in_col(int table[4][4], int col, int value)
{
	int	line;

	line = 0;
	while (line < 4)
	{
		if (table[line][col] == value)
			return (1);
		line++;
	}
	return (0);
}
