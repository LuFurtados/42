/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 16:10:13 by lfurtado          #+#    #+#             */
/*   Updated: 2026/07/30 13:01:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	add_node(t_stack **stack, char *arg)
{
	t_stack	*node;
	int		value;

	if (!validate_number(arg) || !check_overflow(arg))
		return (error());
	value = ft_atoi(arg);
	if (check_duplicate(*stack, value))
		return (error());
	node = stack_new(value);
	if (!node)
		return (error());
	stack_add_back(stack, node);
	return (1);
}

int	build_stack(int argc, char **argv, t_stack **stack_a)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (!add_node(stack_a, argv[i]))
		{
			stack_clear(stack_a);
			return (0);
		}
		i++;
	}
	return (1);
}
