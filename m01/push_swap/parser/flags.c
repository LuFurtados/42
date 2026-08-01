
#include "push_swap.h"

static int	set_option(char *arg, t_options *opt)
{
	if (!ft_strncmp(arg, "--bench", 8))
	{
		if (opt->bench)
			return (error());
		opt->bench = 1;
	}
	else if (!ft_strncmp(arg, "--simple", 9))
	{
		if (opt->strategy != DEFAULT)
			return (error());
		opt->strategy = SIMPLE;
	}
	else if (!ft_strncmp(arg, "--medium", 9))
	{
		if (opt->strategy != DEFAULT)
			return (error());
		opt->strategy = MEDIUM;
	}
	else if (!ft_strncmp(arg, "--complex", 10))
	{
		if (opt->strategy != DEFAULT)
			return (error());
		opt->strategy = COMPLEX;
	}
	else if (!ft_strncmp(arg, "--adaptive", 11))
	{
		if (opt->strategy != DEFAULT)
			return (error());
		opt->strategy = ADAPTIVE;
	}
	else
		return (error());
	return (1);
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
