/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfurtado <lfurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 15:12:43 by lucsanto          #+#    #+#             */
/*   Updated: 2026/07/29 18:31:03 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_operation(t_data *data, t_op op)
{
	char	*name;

	if (!data || op == OP_NONE)
		return ;
	count_operation(data, op);
	if (data->count_line)
		return ;
	name = operation_name(op);
	write(1, name, ft_strlen(name));
	write(1, "\n", 1);
}

void	flush_operations(t_data *data)
{
	if (!data || data->pending_op == OP_NONE)
		return ;
	print_operation(data, data->pending_op);
	data->pending_op = OP_NONE;
}

void	queue_operation(t_data *data, t_op op)
{
	t_op	combined;

	if (!data || op == OP_NONE)
		return ;
	combined = combined_operation(data->pending_op, op);
	if (combined != OP_NONE)
	{
		data->pending_op = OP_NONE;
		print_operation(data, combined);
		return ;
	}
	flush_operations(data);
	data->pending_op = op;
}
