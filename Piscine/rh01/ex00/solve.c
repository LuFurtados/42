/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucoelho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 11:28:46 by gucoelho          #+#    #+#             */
/*   Updated: 2026/03/08 14:51:39 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	solve(int table[4][4], int clues[4][4], int n);
int	count_visible(int *buildings);
int	check_col(int table[4][4], int clues[4][4], int col);
int	check_line(int table[4][4], int clues[4][4], int line);
int	in_col(int table[4][4], int col, int value);
int	in_line(int table[4][4], int line, int value);

// função recursiva que faz tentativa e erro para tentar encontrar uma solução 
//  n presenta o o campo da tabela que está sendo testado
//  assim que um a linha é preenchida (col == 3), a função check_line faz a 
//  validação da linha em relação às pistas daquela linha
//      se for uma linha válida, chama solve recursivamente
//      se inválida, aquele valor é descartado e o tenta-se o próximo 
int	solve(int table[4][4], int clues[4][4], int n)
{
	int	line;
	int	col;
	int	value;

	if (n == 16)
		return (1);
	line = n / 4;
	col = n % 4;
	value = 1;
	while (value <= 4)
	{
		if (!in_line(table, line, value) && !in_col(table, col, value))
		{
			table[line][col] = value;
			if ((col != 3 || check_line(table, clues, line)) \
			&& (line != 3 || check_col(table, clues, col)))
				if (solve(table, clues, n + 1))
					return (1);
			table[line][col] = 0;
		}
		value++;
	}
	return (0);
}

// verifica se a linha line é compatível com as pistas à
// esquerda e à direita
int	check_line(int table[4][4], int clues[4][4], int line)
{
	int	line_from_left[4];
	int	line_from_right[4];
	int	i;

	i = 0;
	while (i < 4)
	{
		line_from_left[i] = table[line][i];
		line_from_right[i] = table[line][3 - i];
		i++;
	}
	if (count_visible(line_from_left) != clues[2][line])
		return (0);
	if (count_visible(line_from_right) != clues[3][line])
		return (0);
	return (1);
}

// verifica se a coluna col é compatível com as pistas de
// cima e de baixo
int	check_col(int table[4][4], int clues[4][4], int col)
{
	int	col_from_top[4];
	int	col_from_bottom[4];
	int	i;

	i = 0;
	while (i < 4)
	{
		col_from_top[i] = table[i][col];
		col_from_bottom[i] = table[3 - i][col];
		i++;
	}
	if (count_visible(col_from_top) != clues[0][col])
		return (0);
	if (count_visible(col_from_bottom) != clues[1][col])
		return (0);
	return (1);
}

// conta quantos prédios são visíveis numa fileira
int	count_visible(int *buildings)
{
	int	max;
	int	count;
	int	i;

	max = 0;
	count = 0;
	i = 0;
	while (i < 4)
	{
		if (buildings[i] > max)
		{
			max = buildings[i];
			count++;
		}
		i++;
	}
	return (count);
}
