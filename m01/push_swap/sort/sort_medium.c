
#include "push_swap.h"

static int	calculate_chunk_size(int size)
{
	int	chunk_size;

	chunk_size = 1;
	while (chunk_size * chunk_size < size)
		chunk_size++;
	return (chunk_size);
}

static void	push_chunks(t_stack **a, t_stack **b, int chunk_size)
{
	int	limit;

	limit = chunk_size;
	while (*a)
	{
		if ((*a)->index < limit)
		{
			pb(a, b);
			if (*b && (*b)->index < limit - (chunk_size / 2))
				rb(b);
			if (stack_size(*b) == limit)
				limit += chunk_size;
		}
		else
			ra(a);
	}
}

static void	push_back(t_stack **a, t_stack **b)
{
	int	pos;

	while (*b)
	{
		update_position(*b);
		pos = find_max_position(*b);
		rotate_to_top_b(b, pos);
		pa(a, b);
	}
}

void	sort_medium(t_stack **a, t_stack **b)
{
	int	size;
	int	chunk_size;

	size = stack_size(*a);
	update_index(*a);
	chunk_size = calculate_chunk_size(size);
	push_chunks(a, b, chunk_size);
	push_back(a, b);
}
