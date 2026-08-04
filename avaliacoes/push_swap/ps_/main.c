/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfurtado <lfurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 15:25:20 by lucsanto          #+#    #+#             */
/*   Updated: 2026/07/29 18:31:40 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	prepare_data(t_data *data, int argc, char **argv, int *start)
{
	if (!parse_options(data, argc, argv, start))
		return (0);
	if (*start >= argc)
		return (2);
	if (!parse_numbers(&data->a, argc, argv, *start))
		return (0);
	assign_indexes(data->a);
	data->disorder = compute_disorder(data->a);
	resolve_strategy(data);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		start;
	int		status;

	init_data(&data);
	if (argc < 2)
		return (0);
	status = prepare_data(&data, argc, argv, &start);
	if (status == 0)
		return (exit_error(&data));
	if (status == 2)
	{
		free_data(&data);
		return (0);
	}
	sort_stack(&data);
	flush_operations(&data);
	if (data.count_line)
		ft_putnbr_fd(data.ops.total, 1);
	print_benchmark(&data);
	free_data(&data);
	return (0);
}
