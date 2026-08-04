/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfurtado <lfurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 16:14:30 by lfurtado          #+#    #+#             */
/*   Updated: 2026/08/03 16:31:43 by lfurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix)
		return ;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

static int	init_app(int argc, char **argv, t_options *opt, t_stack **a)
{
	char	**args;
	int		ac;
	int		ret;

	args = get_flattened_args(argc, argv, opt->first_arg, &ac);
	if (ac <= 0 || !args)
	{
		if (args)
			free_matrix(args);
		error();
		return (1);
	}
	ret = 2;
	if (!build_stack(ac, args, a))
		ret = 1;
	free_matrix(args);
	return (ret);
}

static void	run_push_swap(t_stack **stack_a, t_options *opt, t_bench *bench)
{
	t_stack	*stack_b;

	stack_b = NULL;
	update_index(*stack_a);
	if (bench->active)
		bench->disorder = calculate_disorder(*stack_a);
	if (!stack_is_sorted(*stack_a))
		run_strategy(stack_a, &stack_b, opt, bench);
	print_benchmark(bench);
	stack_clear(stack_a);
	stack_clear(&stack_b);
}

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_options	opt;
	t_bench		bench;

	stack_a = NULL;
	ft_bzero(&bench, sizeof(t_bench));
	if (argc < 2)
		return (0);
	if (argc == 2 && is_only_spaces(argv[1]))
	{
		error();
		return (1);
	}
	if (!parse_flags(argc, argv, &opt))
		return (1);
	if (opt.bench)
		bench.active = 1;
	argc = init_app(argc, argv, &opt, &stack_a);
	if (argc != 2)
		return (argc);
	run_push_swap(&stack_a, &opt, &bench);
	return (0);
}
