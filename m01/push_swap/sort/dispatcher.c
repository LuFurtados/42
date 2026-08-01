
#include "push_swap.h"

void	run_strategy(t_stack **a, t_stack **b, t_options *opt)
{
	if (opt->strategy == DEFAULT)
		sort_stacks(a, b);
    else if (opt->strategy == SIMPLE)
		sort_simple(a, b);
	else if (opt->strategy == MEDIUM)
		sort_medium(a, b);
	/*
	else if (opt->strategy == COMPLEX)
		sort_complex(a, b);
	else if (opt->strategy == ADAPTIVE)
		sort_adaptive(a, b);
    */
}
