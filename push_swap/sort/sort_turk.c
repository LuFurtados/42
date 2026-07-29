
#include "push_swap.h"

static void	evacuate_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	pushed;

	size = stack_size(*stack_a);
	pushed = 0;
	while (size > 3 && pushed < size / 2)
	{
	// Optional: Add logic here to push cheaper nodes first based on index
		pb(stack_a, stack_b);
		pushed++;
	}
	while (size - pushed > 3)
	{
		pb(stack_a, stack_b);
	pushed++;
	}
}

void	turk_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest_node;

	evacuate_to_b(stack_a, stack_b);
	sort_three(stack_a);
	while (*stack_b)
	{
		update_metadata(*stack_a, *stack_b);
		cheapest_node = find_cheapest(*stack_b);
		move_cheapest(stack_a, stack_b, cheapest_node);
	}
	update_position(*stack_a);
	final_rotate(stack_a);
}
