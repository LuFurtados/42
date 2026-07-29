/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfurtado <lfurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 15:12:02 by mariafer          #+#    #+#             */
/*   Updated: 2026/07/29 18:29:45 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_data(t_data *data)
{
	if (!data)
		return ;
	data->a = NULL;
	data->b = NULL;
	data->bench_enabled = 0;
	data->count_line = 0;
	data->strategy = S_ADAPTATIVE;
	data->used_strategy = S_ADAPTATIVE;
	data->disorder = 0.0;
	data->pending_op = OP_NONE;
	ft_bzero(&data->ops, sizeof(t_ops));
}

void	free_data(t_data *data)
{
	if (!data)
		return ;
	free_stack(&data->a);
	free_stack(&data->b);
}
