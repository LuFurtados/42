/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucsanto <lucsanto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 15:14:06 by lucsanto          #+#    #+#             */
/*   Updated: 2026/07/24 16:56:11 by lucsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	add_token_to_stack(t_stack **stack, char *token)
{
	int		number;
	t_stack	*node;

	if (!is_valid_number(token))
		return (0);
	if (!convert_to_int(token, &number))
		return (0);
	if (has_duplicate(*stack, number))
		return (0);
	node = new_node(number);
	if (!node)
		return (0);
	add_node_back(stack, node);
	return (1);
}

static int	parse_argument(t_stack **a, char *arg)
{
	char	**numbers;
	int		i;

	numbers = ft_split(arg, ' ');
	if (!numbers || !numbers[0])
	{
		free_numbers(numbers);
		return (0);
	}
	i = 0;
	while (numbers[i])
	{
		if (!add_token_to_stack(a, numbers[i]))
		{
			free_numbers(numbers);
			return (0);
		}
		i++;
	}
	free_numbers(numbers);
	return (1);
}

int	parse_numbers(t_stack **a, int argc, char **argv, int start)
{
	int	i;

	i = start;
	while (i < argc)
	{
		if (!parse_argument(a, argv[i]))
			return (0);
		i++;
	}
	return (1);
}
