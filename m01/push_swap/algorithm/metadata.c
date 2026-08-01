/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfurtado <lfurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 18:42:10 by lfurtado          #+#    #+#             */
/*   Updated: 2026/07/28 18:43:51 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_metadata(t_stack *stack_a, t_stack *stack_b)
{
	update_position(stack_a);
	update_position(stack_b);
	update_target_position(stack_a, stack_b);
	update_cost(stack_a, stack_b);
}
