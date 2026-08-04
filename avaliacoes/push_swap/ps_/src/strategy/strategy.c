/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariafer <mariafer@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 16:25:17 by mariafer          #+#    #+#             */
/*   Updated: 2026/07/24 18:24:02 by mariafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	resolve_strategy(t_data *data)
{
	if (!data)
		return ;
	if (data->strategy != S_ADAPTATIVE)
	{
		data->used_strategy = data->strategy;
		return ;
	}
	if (data->disorder < 0.2)
		data->used_strategy = S_SIMPLE;
	else if (data->disorder < 0.5)
		data->used_strategy = S_MEDIUM;
	else
		data->used_strategy = S_COMPLEX;
}
