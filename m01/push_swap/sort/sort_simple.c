
#include "push_swap.h"

static void	push_smallest(t_stack **a, t_stack **b)
{
	int	min_pos;
	int	size;

	update_position(*a);
	min_pos = find_min_position(*a);
	size = stack_size(*a);
	if (min_pos <= size / 2)
	{
		while (min_pos-- > 0)
			ra(a);
	}
	else
	{
		while (min_pos++ < size)
			rra(a);
	}
	pb(a, b);
}

void	sort_simple(t_stack **a, t_stack **b)
{
	while (stack_size(*a) > 3)
		push_smallest(a, b);
	sort_three(a);
	while (*b)
		pa(a, b);
}
