/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzampier <jzampier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 18:08:32 by jzampier          #+#    #+#             */
/*   Updated: 2026/03/18 18:08:32 by jzampier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	count_strs_len(char **strs, int size)
{
	int	str;
	int	str_char;
	int	num;
	int	i;

	str = 0;
	str_char = 0;
	num = 0;
	i = 0;
	while (strs[str] && i < size)
	{
		str_char = 0;
		while (strs[str][str_char])
			str_char++;
		str++;
		i++;
		num += str_char;
	}
	return (num);
}

void	fill_str(char *new_str, char **strs, char *sep, int size)
{
	int	i;
	int	str_char;
	int	sep_i;

	i = 0;
	while (strs[i] && i < size)
	{
		str_char = 0;
		sep_i = 0;
		while (strs[i][str_char])
		{
			*new_str = strs[i][str_char];
			new_str++;
			str_char++;
		}
		while (sep[sep_i] != '\0' && i != size - 1)
		{
			*new_str = sep[sep_i];
			new_str++;
			sep_i++;
		}
		i++;
	}
	*new_str = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*new_str;
	int		size_strs;
	int		size_sep;

	size_strs = count_strs_len(strs, size);
	size_sep = ft_strlen(sep);
	if (size == 0)
	{
		new_str = malloc(1);
		new_str[0] = '\0';
		return (new_str);
	}
	new_str = malloc((size_strs + (size_sep * (size - 1))) * sizeof(char) + 1);
	fill_str(new_str, strs, sep, size);
	return (new_str);
}

/*
#include <stdio.h>
int	main(void)
{
	char *new_str;
	// char *strs[] = {"Eu", "juntei", "todas", "essas",
	// "strings", "com", "um", "separador", "no", "meio"};
	char sep[] = {""};
	char *strs[] = { "Hello", "world" };
	int size = 2;{""};
	char *strs[] = { "H

	new_str = ft_strjoin(size, strs, sep);
	printf("%s", new_str);
	free(new_str);
}
*/