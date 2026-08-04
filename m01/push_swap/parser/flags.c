/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlandi <dlandi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 14:24:44 by lfurtado          #+#    #+#             */
/*   Updated: 2026/08/01 16:42:34 by dlandi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	set_strategy(char *arg, t_options *opt)
{
	if (opt->strategy != DEFAULT)
		return (error());
	if (!ft_strncmp(arg, "--simple", 9))
		opt->strategy = SIMPLE;
	else if (!ft_strncmp(arg, "--medium", 9))
		opt->strategy = MEDIUM;
	else if (!ft_strncmp(arg, "--complex", 10))
		opt->strategy = COMPLEX;
	else if (!ft_strncmp(arg, "--adaptive", 11))
		opt->strategy = ADAPTIVE;
	else
		return (0);
	return (1);
}

static int	set_option(char *arg, t_options *opt)
{
	if (!ft_strncmp(arg, "--bench", 8))
	{
		if (opt->bench)
			return (error());
		opt->bench = 1;
		return (1);
	}
	if (set_strategy(arg, opt))
		return (1);
	return (error());
}

int	parse_flags(int argc, char **argv, t_options *opt)
{
	int	i;

	opt->strategy = DEFAULT;
	opt->bench = 0;
	i = 1;
	while (i < argc)
	{
		if (ft_strncmp(argv[i], "--", 2))
			break ;
		if (!set_option(argv[i], opt))
			return (0);
		i++;
	}
	opt->first_arg = i;
	return (1);
}
