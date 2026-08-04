/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfurtado <lfurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 15:23:25 by dlandi            #+#    #+#             */
/*   Updated: 2026/08/03 16:31:26 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_only_spaces(char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (1);
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'
			&& str[i] != '\r' && str[i] != '\v' && str[i] != '\f')
			return (0);
		i++;
	}
	return (1);
}

int	count_split_words(char **argv, int start)
{
	int		count;
	int		i;
	char	**split;
	int		j;

	count = 0;
	i = start;
	while (argv[i])
	{
		if (is_only_spaces(argv[i]))
			return (-1);
		split = ft_split(argv[i], ' ');
		if (!split)
			return (-1);
		j = 0;
		while (split[j])
		{
			count++;
			j++;
		}
		free_matrix(split);
		i++;
	}
	return (count);
}

void	fill_flattened_args(int argc, char **argv, int first_arg, char **args)
{
	char	**split;
	int		i;
	int		j;
	int		k;

	i = first_arg;
	k = 0;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		j = 0;
		while (split && split[j])
		{
			args[k++] = ft_strdup(split[j]);
			j++;
		}
		free_matrix(split);
		i++;
	}
	args[k] = NULL;
}

char	**get_flattened_args(int argc, char **argv, int first_arg, int *ac)
{
	char	**args;
	int		total_args;
	int		i;

	i = first_arg;
	while (argv[i])
	{
		if (is_only_spaces(argv[i]))
			return (NULL);
		i++;
	}
	total_args = count_split_words(argv, first_arg);
	if (total_args <= 0)
		return (NULL);
	args = ft_calloc(total_args + 1, sizeof(char *));
	if (!args)
		return (NULL);
	fill_flattened_args(argc, argv, first_arg, args);
	*ac = total_args;
	return (args);
}
