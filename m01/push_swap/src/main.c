/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 16:14:30 by lfurtado          #+#    #+#             */
/*   Updated: 2026/07/30 17:37:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_matrix(char **matrix)
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

static char	**get_args(int argc, char **argv, int first_arg, int *ac)
{
	char	**args;

	if (argc - first_arg == 1)
		args = ft_split(argv[first_arg], ' ');
	else
		args = argv + first_arg;
	*ac = 0;
	while (args[*ac])
		(*ac)++;
	return (args);
}

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_options	opt;
	char		**args;
	int			ac;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (0);
	if (!parse_flags(argc, argv, &opt))
		return (1);
	args = get_args(argc, argv, opt.first_arg, &ac);
	if (ac <= 0)
		return (error());
	if (!build_stack(ac, args, &stack_a))
		return (1);
	if (argc == 2 || argc - opt.first_arg == 1)
		free_matrix(args);
	update_index(stack_a);
	if (!stack_is_sorted(stack_a))
		run_strategy(&stack_a, &stack_b, &opt);
	stack_clear(&stack_a);
	stack_clear(&stack_b);
	return (0);
}
