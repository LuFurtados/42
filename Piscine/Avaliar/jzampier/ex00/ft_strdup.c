/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzampier <jzampier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 19:26:48 by jzampier          #+#    #+#             */
/*   Updated: 2026/03/17 19:26:48 by jzampier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		size;
	char	*new_str;

	i = 0;
	size = ft_strlen(src);
	new_str = malloc(size + 1 * sizeof(char));
	while (i < size)
	{
		new_str[i] = src[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

#include <stdio.h>
int main(int argc, char **argv)
{
    char *copia;

    // Verifica se o usuário passou algum argumento
    if (argc < 2)
    {
        printf("Uso: %s <string_para_duplicar>\n", argv[0]);
        return (1);
    }

    printf("--- Testando com argv[1]: \"%s\" ---\n", argv[1]);

    // Testando a duplicação do primeiro argumento passado
    copia = ft_strdup(argv[1]);

    if (copia == NULL)
    {
        printf("Erro de alocacao de memoria!\n");
        return (1);
    }

    // Exibe resultados e endereços para provar que são áreas diferentes
    printf("Original (argv[1]): %s | Endereco: %p\n", argv[1], (void*)argv[1]);
    printf("Copia (ft_strdup):  %s | Endereco: %p\n", copia, (void*)copia);

    // Liberando a memória
    free(copia);

    return (0);
}