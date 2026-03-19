/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzampier <jzampier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 19:25:09 by jzampier          #+#    #+#             */
/*   Updated: 2026/03/17 19:25:09 by jzampier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	size;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	i = 0;
	size = max - min;
	*range = malloc(size * sizeof(int));
	while (min < max)
	{
		(*range)[i] = min;
		min++;
		i++;
	}
	return (i);
}

/*
#include <stdio.h>
int main(int argc, char **argv)
{
	int *meu_array; // Ponteiro que receberá o endereço da alocação
	int retorno;
	int min;
	int max;
	int i;

	// Verifica se os argumentos min e max foram passados
	if (argc != 3)
	{
		printf("Uso: %s <min> <max>\n", argv[0]);
		return (1);
	}

	min = atoi(argv[1]);
	max = atoi(argv[2]);

	printf("Testando ft_ultimate_range(range, %d, %d):\n", min, max);

	// Inicializamos o ponteiro como NULL por segurança
	meu_array = NULL;

	// Passamos o endereço do ponteiro (&meu_array)
	retorno = ft_ultimate_range(&meu_array, min, max);

	printf("Retorno da funcao (tamanho): %d\n", retorno);

	// Se o retorno for 0 ou negativo, ou se o ponteiro continuar NULL
	if (retorno <= 0)
	{
		printf("retorno 0.\n");
		// Importante: Verifique se sua função lida com o ponteiro em caso de erro
	}


	if (meu_array == NULL)
	{
		printf ("meu array é NULL\n");
	}

	else
	{
		printf("Conteudo do array: ");
		i = 0;
		while (i < retorno)
		{
			printf("%d ", meu_array[i]);
			i++;
		}
		printf("\n");

		// Liberar a memória alocada
		free(meu_array);
	}

	return (0);
}
*/