/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzampier <jzampier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 19:26:55 by jzampier          #+#    #+#             */
/*   Updated: 2026/03/17 19:26:55 by jzampier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	size;
	int	*array;

	if (min >= max)
		return (NULL);
	i = 0;
	size = max - min;
	array = malloc(size * sizeof(int));
	while (min < max)
	{
		array[i] = min;
		min++;
		i++;
	}
	return (array);
}

/*
#include <stdio.h>
int main(int argc, char **argv)
{
	int *res;
	int min;
	int max;
	int size;
	int i;

	// Verifica se o usuário passou os 2 argumentos necessários (min e max)
	if (argc != 3)
	{
		printf("Uso: %s <min> <max>\n", argv[0]);
		return (1);
	}

	// Converte os argumentos da linha de comando para inteiros
	min = atoi(argv[1]);
	max = atoi(argv[2]);
	size = max - min;

	printf("Testando ft_range(%d, %d):\n", min, max);

	// Chama a sua função
	res = ft_range(min, max);

	// Verifica se o retorno foi NULL
	if (res == NULL)
	{
		printf("Retorno: NULL\n");
	}
	else
	{
		printf("Retorno (array): ");
		i = 0;
		while (i < size)
		{
			printf("%d ", res[i]);
			i++;
		}
		printf("\n");
		
		// Libera a memória alocada pela sua função
		free(res);
	}

	return (0);
}
*/