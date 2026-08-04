/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucsanto <lucsanto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 15:15:54 by lucsanto          #+#    #+#             */
/*   Updated: 2026/07/24 17:57:35 by lucsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_data *data)
{
	if (!data || !data->a)
		return ;
	if (stack_is_sorted(data->a))
		return ;
	if (data->used_strategy == S_SIMPLE)
		sort_simple(data);
	else if (data->used_strategy == S_MEDIUM)
		sort_medium(data);
	else if (data->used_strategy == S_COMPLEX)
		sort_complex(data);
}
