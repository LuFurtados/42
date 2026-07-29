/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucsanto <lucsanto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 15:15:37 by lucsanto          #+#    #+#             */
/*   Updated: 2026/07/24 17:57:10 by lucsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_simple(t_data *data)
{
	if (!data || !data->a)
		return ;
	while (data->a->next)
	{
		move_min_to_top(data);
		pb(data);
	}
	while (data->b)
		pa(data);
}
